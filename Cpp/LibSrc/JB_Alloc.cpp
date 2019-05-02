
// fireballs at da police's heads.
// Copyright, Theodore H. Smith 2019.
// Released under jeebox-licence http://jeebox.org/licence.txt



/*
    Idea for a new system...
    
    * First... simplify the spare-system. Just have prev/next, no SpareBlock.
        * There will be a "spareblock" but that will just be the last on the list.
        * The whole point of having a spareblock, before, was that we point to a block that's already freed.
        * BUT... why not just keep it on the actual sparelist... in the first place?
            * The problem comes that we try to get a block from the sparelist, and... it's already taken.
            * So just handle that case and return nil.
        * Maybe make the block allocator... try avoid "spareblocks".
            * if it finds a "spare" try search 1 or 2 further
        
    * Non-spare blocks can't point to normal blocks, so they just won't.
        * We'll need some flag to say if this block is in use or not.
            * OR the lack of ->Prev?

    * Anyhow... So! We can make one list... for both the spare-list AND the mainlist... of allocated blocks, within a MemoryLayer.
        * Right now... allocated blocks actually AREN'T on ANY list. I don't like this. They should be on the memory-layer's list.
        * But then we'd have two lists. A spare-list and a normal list.
        * So let's just put the sparelist on the end? Makes sense. Besides, spares are normal blocks... with objects in them...
            * Except the last one, if it's already freed.
        * This lets us list over all the blocks, and objects, in a MemoryLayer!! Via JB_ObjNext()
        * ALSO "non-default" MemoryLayers like for JB_Message... need to NOT hold onto the last spareblock
            * except "weakly". Or else it's refcount can never reach 0.
*/


#include "JB_Umbrella.h"
#include <malloc/malloc.h>
#include "JB_Log.h"

#define kBlockSize          12  // 4K


extern "C" {

struct FreeObject {
    int         RefCount; // avoid altering first 4 bytes. Downside: minimum obj-size becomes 8.
    FreeObject* Next;
};

struct LinkHelper {
    LinkHelper*     Unused[2];
    LinkHelper*     Next;
    LinkHelper*     Prev;
};

struct SuperBlock {
    MemoryWorld*            World;
    AllocationBlock*        FirstBlock;
    SuperBlock*             Next;
    SuperBlock*             Prev;
    u16                     ID;
    u16                     BlocksActive;
    AllocationBlock*        StartBlock;
    FreeObject*             StartObj;
    void*                   BlockEnd;
};


struct AllocationBlock {
    MemoryLayer*            Owner;      // these two...
    FreeObject*             FirstFree;  // have to be first...
    AllocationBlock*        Next;
    AllocationBlock*        Prev;
    JBObject_Behaviour*     FuncTable; // speed things up a bit.
    u16                     ObjCount;
    u16                     HiddenObjCount;

    u16                     ObjSize;
    u16                     Unused_;
    SuperBlock*             Super;
};


int JB_AllocationBlockSize() {
    return sizeof(AllocationBlock);
}
void JB_Mem_Destructor( MemoryLayer* self );


////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////

static bool IsDummy( const AllocationBlock* Block ) {
    AllocationBlock* OwnersDummy = (AllocationBlock*)(&Block->Owner->Dummy);
    return OwnersDummy == Block;
}

static inline AllocationBlock* OfficialStart_(SuperBlock* NewSuper, IntPtr BlockSize) {
    return (AllocationBlock*)(((IntPtr)NewSuper | (BlockSize-1)) &~ (sizeof(AllocationBlock)-1));
}
static inline AllocationBlock* StartBlock_(SuperBlock* Block) {
    return Block->StartBlock;
}
static inline AllocationBlock* EndBlock_(SuperBlock* Block) {return (AllocationBlock*)Block->BlockEnd;}
#ifdef DEBUG
    #define GoodBlock(x)
    // expect ( ((int)(x->FirstFree) != -1)  and  ((int)x->Destructor != -1)  and  ((int)x->Owner != -1)  and  ((int)x->Super != -1)  );
    
#else
    #define GoodBlock(x)
    #define Sanity(x)
#endif

////////////////////////////////////////////////////////////////////////////////////////////////////////////

MemoryWorld MemoryManager = {
    .Name           = (u8*)"JB Standard Memory",
    .SuperSize      = 20,
    .BlockSize      = 12,
    .Alignment      = 4,
    .SpareTrigger   = 0.75f,
};



fpDestructor GetDestructor_(AllocationBlock* B) {
    return (fpDestructor)(B->FuncTable->__destructor__);
}

JBObject_Behaviour DummyFuncTable = {0, 0};
#if DEBUG
static void Sanity(AllocationBlock* B);
int DB = 0;
JBObject_Behaviour SuperSanityTable = {(void*)Sanity, 0};

static bool FreeBlock_(AllocationBlock* B) {
    return (GetDestructor_(B) == (fpDestructor)Sanity);
}

static void LinkSane(AllocationBlock* B) {
    if (!B) {
        return;
    }
    if (IsDummy(B)) {
        return;
    }
    AllocationBlock* N = B->Next;
    AllocationBlock* P = B->Prev;
    if (N) {
        if (IsDummy(N)) {
            debugger;
        }
        if (FreeBlock_(N) != FreeBlock_(B)) {
            debugger;
        }
    }
    if (P) {
        if (IsDummy(P)) {
            debugger;
        }
        if (FreeBlock_(P) != FreeBlock_(B)) {
            debugger;
        }
    }
}


static bool IsBadFree_(AllocationBlock* Curr) {
    LinkSane(Curr);
    if (Curr->Prev) {
        debugger;
        return true;
    }
    AllocationBlock* N = Curr->Next;
    if (N == Curr) {
        debugger;
        return true;
    }
    fpDestructor D = GetDestructor_(Curr);
    if (D != (fpDestructor)Sanity) {
        debugger;
        return true;
    }
    return false;
}


static int CanFollow_( AllocationBlock* First, bool Forward ) { 
    // try to follow the links... until we find the end!
    int Count = 0; // max...
    AllocationBlock* Curr = First;
    do {
        fpDestructor D = GetDestructor_(Curr);
        if (D == (fpDestructor)Sanity) {
            debugger;
            return -1;
        }
        Count++;
        if (Forward) {
            Curr = Curr->Next;
        } else {
            Curr = Curr->Prev;
        }
        if (!Curr) {
            debugger;
            return -2;
        }
        if (Count > 100) {
            debugger;
            return -3;
        }
    } while (Curr != First);
    return Count;
}


static bool IsBadInUse_(AllocationBlock* Curr) {
    LinkSane(Curr);
    int A = CanFollow_(Curr, true);
    int B = CanFollow_(Curr, false);
    if (A != B) {
        debugger;
    }
    return false;
}


static void SanityOfInUse(SuperBlock* Sup, MemoryWorld* World) {
    AllocationBlock* Curr = StartBlock_(Sup);
    AllocationBlock* Finish = EndBlock_(Sup);
    while (Curr < Finish) {
        LinkSane(Curr);
        if (GetDestructor_(Curr) != (fpDestructor) Sanity) {
            IsBadInUse_(Curr);
        }
        Curr = JBShift( Curr, 1 << World->BlockSize );
    }
}


static void SanityOfFree(SuperBlock* Sup) {
    AllocationBlock* F = Sup->FirstBlock;
    AllocationBlock* Curr = F;
    while (Curr) {
        if (GetDestructor_(Curr) != (fpDestructor)Sanity) {
            debugger;
        }
        IsBadFree_(Curr);
        Curr = Curr->Next;
    }
}


static void Sanity(AllocationBlock* B) {
    return;
    if (B) {
        LinkSane(B);
    }

    SuperBlock* Sup0 = MemoryManager.CurrSuper;
    SuperBlock* Curr = Sup0;
    if (!Curr) {
        return;
    }

    do { //////////// .,,,<<<<>>>><<<<<>>>><<<>>>><<<<<<<<<
        SanityOfInUse(Curr, &MemoryManager);
        SanityOfFree(Curr);
        Curr = Curr->Next;
    } while (Curr and Curr != Sup0);

}
#endif


void JB_Class_Init(JB_Class* Cls, MemoryWorld* World, int Size) {
    memzero(Cls, sizeof(JB_Class)); // can't use JB_Zero.
    Cls->DefaultBlock = (AllocationBlock*)(&Cls->Memory.Dummy);
    Cls->Size = Size;
    Cls->Memory.RefCount = 1, // so it never goes away
    Cls->Memory.CurrBlock = (AllocationBlock*)(&Cls->Memory.Dummy);
    Cls->Memory.Dummy.Owner = &Cls->Memory;
    Cls->Memory.World = World;
    Cls->Memory.Class = Cls;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////




void JB_Mem_Constructor( MemoryLayer* self, JB_Class* Cls ) {
    JB_Zero(self);
    self->Class = Cls;
    self->CurrBlock = (AllocationBlock*)&(self->Dummy);
    self->Dummy.Owner = self;
    self->World = JB_MemStandardWorld();
//    self->HiddenRefCount = JB_HiddenRef(Cls->Size);
}



void JB_Mem_InitAndUse(MemoryLayer* Mem, JB_Class* Cls) {
    JB_Mem_Constructor(Mem, Cls);
    JB_Mem_Use(Mem);
}

MemoryLayer* JB_Mem_CreateLayer(JB_Class* Cls, JB_Object* Obj) {
    MemoryLayer* Mem = JB_New(MemoryLayer);
    JB_Mem_Constructor(Mem, Cls);
    JB_SetRef(Mem->Obj, Obj);
    return Mem;
}

MemoryLayer* JB_Mem_UseNewLayer(JB_Class* Cls, JB_Object* Obj) {
    MemoryLayer* Mem = JB_New(MemoryLayer);
    JB_Mem_InitAndUse(Mem, Cls); 
    JB_SetRef(Mem->Obj, Obj); 
    return Mem;
}

void JB_Mem_Use( MemoryLayer* self ) {
    // shouldn't we incr the layer? or not?
    if (self->IsActive) { // save time...
        return;
    }
    JB_Class* Cls = self->Class;
    AllocationBlock* ClsBlock = Cls->DefaultBlock;
    ClsBlock->Owner->IsActive = false;
    Cls->DefaultBlock = self->CurrBlock; // swap first...
    self->IsActive = true;
    /// what does this do even, or why? I forgot?
    /// we are putting into the class, but why compare something to self and why incr or decr?
    if (ClsBlock->Owner != self) {
        JB_Incr(self);
        JB_Decr(ClsBlock->Owner);
    }
}


void JB_Mem_Destructor( MemoryLayer* self ) {
    JB_Decr( self->Obj );
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////


inline AllocationBlock* ObjBlock_(void* Obj) {
    IntPtr Addr = (IntPtr)Obj | ((1<<kBlockSize)-1);
    Addr = Addr &~ (sizeof(AllocationBlock)-1);
    return (AllocationBlock*)Addr;
}

///   ///   ///   ///   ///   ///   ///   ///   ///   ///   ///   ///   ///   ///   ///   ///   ///   ///   ///   ///   



static void SelfLink_(LinkHelper* New) {
    New->Next = New;
    New->Prev = New;
}

static void AddLink_(LinkHelper* Old, LinkHelper* New) {
    if (Old) {
        LinkHelper* P = Old->Prev;
        P->Next = New;
        New->Prev = P;
        New->Next = Old;
        Old->Prev = New;
    } else {
        SelfLink_(New);
    }
}

static void Unlink_(LinkHelper* Curr) {
    LinkHelper* N = Curr->Next;
    LinkHelper* P = Curr->Prev;
    N->Prev = P;
    P->Next = N;
    Curr->Next = Curr;
    Curr->Prev = Curr;
}



  ///////////////////////////////////////////////////////////////////////////////////////////////
  ///////////////////////////////////////////////////////////////////////////////////////////////

MemoryLayer* JB_Class_CurrLayer( JB_Class* Cls ) {
    return Cls->DefaultBlock->Owner;
}

JB_Object* JB_Class_AllocZeroed( JB_Class* Cls ) {
    JB_Object* Result = JB_Alloc2(Cls->DefaultBlock);
    if (Result) {
        memzero(Result, Cls->Size);
    }
    return Result;
}

MemoryLayer* JB_Class_DefaultLayer( JB_Class* Cls ) {
    return &Cls->Memory;
}

MemoryLayer* JB_ObjLayer( JB_Object* Obj ) {
    AllocationBlock* Block = ObjBlock_(Obj);
    return Block->Owner;
}

int JB_ObjID( JB_Object* Obj ) {
    AllocationBlock* Block = ObjBlock_(Obj);
    require(((IntPtr)Block->Super) >= 4000);
    int SuperID = Block->Super->ID;
    IntPtr Offset = ((IntPtr)Obj) - ((IntPtr)(Block->Super));
    return (SuperID << 20) + (int)(Offset >> 3); // min objectsize = 8. So we can lose 3 bits
                                            // SuperID is also different. Need to increase it so it won't collide.
}


void JB_Mem_OwnedSet(MemoryLayer* Mem, bool b) {
    Mem->Owned = b;
}

/*
bool JB_ObjIsOwned(JB_Object* Obj) {
    return ObjBlock_(Obj)->Owned;
}
*/

JB_Class* JB_ObjClass(JB_Object* Obj) {
    return JB_ObjLayer(Obj)->Class;
}


int JB_ObjRefCount(JB_Object* Obj) {
    return Obj->RefCount;
}


u8* JB_ObjClassBehaviours(JB_Object* Obj) {
    // assume exists.
    return (u8*)(ObjBlock_(Obj)->FuncTable);
}


/*JB_Object* JB_ObjNext(JB_Object* Obj) {
    require(Obj);
    AllocationBlock* Block = ObjBlock_(Obj);
    int Size = Block->ObjSize;
    do {
        do {
            Obj = JBShift(Obj, Size);
            if ((void*)Obj >= (void*)Block) {
                break;
            }
            if (Obj->RefCount > 0) {
                return Obj;
            }
        } while(true);
        // OK... so we are at the end of one block. We need to visit the next!
        Block = Block->Next;
        // NOPE!! Can't do that! It's just the spare-list... Maybe in a future version we can use the prev-list somehow.
        // even then, how to remove a block? We need to know what block points TO IT.
        // unless we had TWO lists? A sparelist and a... normal list? Seems fair. But later.
        Obj = (JB_Object*)(((int)Block) &~ ((1<<kBlockSize)-1));
    } while (Block);
    return 0;
}*/

void JB_ObjDestroy( JB_Object* Obj ) {
    AllocationBlock* Block = ObjBlock_(Obj);
    fpDestructor Destructor = GetDestructor_(Block);
    if (Destructor) {
        (Destructor)(Obj);
    }
    // in theory... I could call the default constructor after? In fact it may be faster than calling memset!
    JB_Class* Cls = Block->Owner->Class;
    memzero(Obj+1, Cls->Size - sizeof(Obj));
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////

static void SetCurrBlock_( MemoryLayer* Mem, AllocationBlock* NewBlock ) {
Sanity(NewBlock);
    JB_Class* Cls = Mem->Class;
    if (Cls and (Cls->DefaultBlock == Mem->CurrBlock)) {
        // class is using this MemoryLayer...
        Cls->DefaultBlock = NewBlock;
    }
    
    Mem->CurrBlock = NewBlock;
}

static FreeObject* LinkIn_(MemoryLayer* Mem, AllocationBlock* NewBlock) {
Sanity(NewBlock);
// Call this when returning the first item from a newly allocated block.
    SetCurrBlock_( Mem, NewBlock );
    Mem->RefCount++;
    FreeObject* First = NewBlock->FirstFree;
    NewBlock->FirstFree = First->Next;
    NewBlock->ObjCount++;
Sanity(NewBlock);
    return First;
}

static AllocationBlock* LinkInSuper_(MemoryWorld* World, SuperBlock* Super) {
    if (Super->World!=World) {
        Super->World = World;
        Super->BlocksActive++;
        World->CurrSuper = Super; // issue?
        World->RefCount++;
    }
    AllocationBlock* First = Super->FirstBlock;
Sanity(First);
Sanity(First->Next);
    Super->FirstBlock = First->Next;
    First->Next = 0;
    return First;
}



// write the AllocationBlocks... at the end.
static inline void SetupSuper_(SuperBlock* Super, MemoryWorld* W) {
    AllocationBlock* Curr = StartBlock_( Super );
    AllocationBlock* End =  EndBlock_( Super ); // end is too far, somehow. it's 4100K but we only allocated 4096K?
    int Size = 1 << W->BlockSize;

    Super->FirstBlock = Curr;

    while (Curr < End) {
        AllocationBlock* Next = JBShift(Curr, Size);
        Curr->Super = Super;
        #ifdef DEBUG
        Curr->FuncTable = &SuperSanityTable;
        Curr->Unused_ = DB++;
        #endif
        Curr->Next = Next;
        Curr = Next;
    }
    Curr = JBShift(Curr, -Size);
    Curr->Next = 0;
}



#ifdef DEBUG
MiniStr BlockShadowRange (AllocationBlock* B) {
    MemoryWorld* W = B->Super->World;
    MiniStr Result = {};
    if (W) {
        // int Size = B->ObjSize;
        FreeObject* End =  (FreeObject*)B;
//        End = JBShift(End, -(Size-1)); // There for alignment... Only changes things for unaligned-sizes... (32bytes?)
        int Shadow = (1 << W->ShadowSize) &~ 0x0F;
        End = JBShift(End, -Shadow);
        Result.Addr = (u8*)End;
        Result.Length = Shadow;
    }
    return Result;
}
#endif


static void InitObjectsInBlock_(AllocationBlock* NewBlock, MemoryWorld* W, int Size) {
    // I'm pretty sure this loop is perfect. So if we get any errors... it can't be from here.
    NewBlock->ObjSize = Size;
    int BS = W->BlockSize;
    int BlockBits = (1 << BS) - 1;
    FreeObject* Curr = (FreeObject*)(((IntPtr)NewBlock) &~ BlockBits);
    FreeObject* TrueFirst = NewBlock->Super->StartObj;
    if (Curr < TrueFirst) {
        Curr = TrueFirst;
    }
    FreeObject* End =  (FreeObject*)NewBlock;
    dbgexpect(Curr < End);
    End = JBShift(End, -(Size-1));
    dbgexpect(Curr < End);
    int Shadow = (1 << W->ShadowSize) &~ 0x0F;
    End = JBShift(End, -Shadow);
    dbgexpect(Curr < End);
    NewBlock->FirstFree = Curr; // for LinkIn_

    while (true) {
        FreeObject* Next = JBShift(Curr, Size);
        Curr->RefCount = 0;
        Curr->Next = Next;
        if (Next >= End) {
            break;
        }
        Curr = Next;
    }

    Curr->Next = 0;
}



static AllocationBlock* SuperBlockSetup_( SuperBlock* Super, MemoryWorld* World ) {
    AddLink_((LinkHelper*)(World->CurrSuper), (LinkHelper*)Super);
    SetupSuper_( Super, World );
    return LinkInSuper_(World, Super);
}


JBObject_Behaviour* NeedRealTable_(JBObject_Behaviour* T) {
    if (T) {
        return T;
    }
    return &DummyFuncTable;
}


static FreeObject* BlockSetup_ ( MemoryLayer* Mem, AllocationBlock* NewBlock, MemoryWorld* World ) {
    if (!NewBlock) {
        return 0;
    }
    Sanity(NewBlock);
    JB_Class* Class = Mem->Class;
    NewBlock->FuncTable = NeedRealTable_(Class->FuncTable); // helps avoid touching uncached RAM.
    int Size = Class->Size;
    NewBlock->Owner = Mem;
//    NewBlock->Owned = Mem->Owned;

    if (NewBlock->ObjSize != Size) {
        InitObjectsInBlock_( NewBlock, World, Size );
    }

    SelfLink_((LinkHelper*)NewBlock);

    return LinkIn_(Mem, NewBlock);
}




// SuperBlocks
// MemoryLayer
// AllocationBlocks
// Objects


static bool OutOfMemoryHappenedAlready;
void JB_OutOfMemory(int N) {
    if (!OutOfMemoryHappenedAlready) {
        OutOfMemoryHappenedAlready = true;
        printf("Failed to allocate RAM (%i bytes) : (JB_Utils.cpp)\n", N);
    }
}

bool JB_OutOfMemoryOccurred () {
    // read by ErrorReceiver!
    return OutOfMemoryHappenedAlready;
}



static SuperBlock* Super_calloc(MemoryWorld* World) {
    int N = (1 << World->SuperSize);
    int Align = (1 << World->BlockSize);

    while (N >= Align*4) {
        SuperBlock* bla = (SuperBlock*)malloc_zone_memalign(malloc_default_zone(), Align, N);
        if (bla) {
//            printf("allocating %i (%s): %X\n", N, World->Name, (void*)bla);
            memset(bla, 0, N);
            bla->BlockEnd = ((u8*)bla) + N;
            return bla;
        }
        N -= Align;
    }
    
    JB_OutOfMemory(N);
    return 0;
}


static void Super_free(SuperBlock* Super) {
    Super->World->RefCount--;
//    printf("freeing super %X\n", (void*)Super);
    malloc_zone_free(malloc_default_zone(), Super);
}


static SuperBlock* AllocSuper(MemoryWorld* World) {
    SuperBlock* NewSuper = Super_calloc(World);
    require(NewSuper);
    
    NewSuper->ID = World->SupersMade++;

    int BlockSize = 1 << World->BlockSize;

    FreeObject* FirstWriteable = (FreeObject*)JBShift(NewSuper, sizeof(SuperBlock));
    
    int Alignment = 1 << World->Alignment;
    int Extra = (IntPtr)(FirstWriteable) & (Alignment - 1);
    if (Extra) {
        FirstWriteable = (FreeObject*)JBShift(FirstWriteable, Alignment - Extra);
    }

    NewSuper->StartObj = FirstWriteable;
    NewSuper->StartBlock = OfficialStart_(NewSuper, BlockSize);

    return NewSuper;
}


static AllocationBlock* NewSuperBlock_(MemoryLayer* Mem, MemoryWorld* World) {
    SuperBlock* Super = AllocSuper(World);
    require(Super);
    return SuperBlockSetup_( Super, World );
}


static AllocationBlock* FindAllocBlock_(MemoryWorld* World) {
    SuperBlock* First = World->CurrSuper;
    if (!First) {
        return 0;
    }
    SuperBlock* Curr = First;
    
    do {
        GoodBlock(Curr);
        AllocationBlock* Item = Curr->FirstBlock;
        if (Item) {
            Sanity(Item);
            if (Curr == World->SpareSuper) {
                World->SpareSuper = 0;
            }
            World->CurrSuper = Curr;
            Curr->BlocksActive++;
            Curr->FirstBlock = Item->Next;
            Item->Next = 0;
            return Item;
        }
        
        Curr = Curr->Next;
    } while (First != Curr);

    return 0;
}


static AllocationBlock* ReturnSpareHidden_(AllocationBlock* CurrBlock) {
    AllocationBlock* NewBlock = CurrBlock->Next;
    Sanity(CurrBlock);
    if (NewBlock != CurrBlock) {        // use this!
        Unlink_((LinkHelper*)CurrBlock);
        return NewBlock;
    }
    return 0;
}


static AllocationBlock* ReturnSpare_(MemoryLayer* Mem) {
// Allocate a "NewBlock" by just re-using the spareblock as the currentblock...
    AllocationBlock* NewBlock = ReturnSpareHidden_( Mem->CurrBlock );
    if (NewBlock) {
        return NewBlock;
    }

    NewBlock = Mem->SpareBlock;
    Sanity(NewBlock);
    if (NewBlock) { // Improvement?: Stick the spareblock on the normal "next" list. And just test that it's a spare. 1 less branch!
        Mem->SpareBlock = 0;
        NewBlock->Super->BlocksActive++;
        return NewBlock;
    }
    return 0;
}


u16 HiddenRef_(float R, int ObjSize) {
    int N = (1<<kBlockSize) - sizeof(AllocationBlock);
    int N2 = N * R;
    return N2 / ObjSize;
}


FreeObject* JB_NewBlock( AllocationBlock* CurrBlock, MemoryLayer* Mem ) {
// Needs both params... We basically can't correctly figure out one from the other in every situation...
    Sanity(CurrBlock);

    MemoryWorld* World = Mem->World;
    if (!IsDummy(CurrBlock)) {
        u16 Hidden = Mem->HiddenRefCount;       // trigger re-use of this block before it hits empty.
        if (!Hidden) {
            Hidden = HiddenRef_(World->SpareTrigger, Mem->Class->Size);
            Mem->HiddenRefCount = Hidden;
        }
        CurrBlock->HiddenObjCount = Hidden;
        CurrBlock->ObjCount -= Hidden;

        AllocationBlock* Spare = ReturnSpare_( Mem );
        if (Spare) {
            return LinkIn_(Mem, Spare);
        }
    }


    Sanity(CurrBlock);
    AllocationBlock* Result = FindAllocBlock_( World );
    if (!Result) {
        Result = NewSuperBlock_( Mem, World );
    }
    return BlockSetup_( Mem, Result, World );

// I could take "LinkIn" out of BlockSetup, and put it here? It should work?
// at least allow it to be called from less places... Or perhaps make a wrapper
// func so all the different paths are merged into one. FindAllocBlock would call BlockSetup_ (for consistancy)
}


static void ResetClass_( JB_Class* Cls ) {
//    Cls->Memory.RefCount = 2; // i think that's the start number?
    Cls->DefaultBlock = (AllocationBlock*)&(Cls->Memory.Dummy);
}

static void CleanSpares_( SuperBlock* Super, bool ResettingApp ) {
    MemoryWorld* World = Super->World;
    int N = 1 << World->BlockSize;
    AllocationBlock* Curr = StartBlock_(Super);
    AllocationBlock* End = EndBlock_(Super);

    while (Curr < End) { // not too sure this test is correct!
        MemoryLayer* Mem = Curr->Owner;
        if ( Mem ) { // Only exists if its a spare, seeing as the superblock's refcount is 0.
            if (ResettingApp) {
                ResetClass_(Mem->Class);
            } 
            Mem->SpareBlock = 0;
        }
        Curr = JBShift(Curr, N);
    }
}


static void PossiblyLast_(SuperBlock* Super) {
    GoodBlock(Super);
    MemoryWorld* World = Super->World;
    if (World->CurrSuper == Super) {  // issue?
        SuperBlock* Next = Super->Next;
        if (Next == Super) {
            Next = 0;
        }
        World->CurrSuper = Next; // issue?
    }
}


static void JustGetRidOfIt_(SuperBlock* Super, bool ActuallyGetRidOfIt, bool ResettingApp) {
    GoodBlock(Super);
    GoodBlock(Super->Next);
    PossiblyLast_(Super);
    Unlink_( (LinkHelper*)Super );
    CleanSpares_( Super, ResettingApp );
    if (ActuallyGetRidOfIt) {
        Super_free(Super);
    } else {
        SuperBlockSetup_(Super, Super->World);
    }
}


static bool IsAlone_(SuperBlock* Super) {
    return Super->Next == Super;
}


static void SuperBlockFree_(SuperBlock* Super) {
    MemoryWorld* World = Super->World;
    if ( World->SpareSuper ) {
        JustGetRidOfIt_(Super, true, false);

    } else if ( !IsAlone_( Super ) ) {
        World->SpareSuper = Super; // issue?
    }
}


static void BlockFree_( AllocationBlock* FreeBlock ) {
    Sanity(FreeBlock);
    MemoryLayer* Mem = FreeBlock->Owner;
    SuperBlock* Super = FreeBlock->Super;
    if (Mem->RefCount == 2) {
//        DebuggerAt(1);
        if (!Mem->World->SpareSuper and IsAlone_( Super ) ) { // avoid freeing last super, avoid thrashing.
//            printf("Super: %s Keeping %i blocks\n", Super->World->Name, Super->BlocksActive);
            return;
        }
    }
    
    if (Mem->CurrBlock == FreeBlock) {
        AllocationBlock* NewCurr = ReturnSpareHidden_(FreeBlock);
        if (!NewCurr) {
            NewCurr = (AllocationBlock*)&(Mem->Dummy);
        }
        SetCurrBlock_(Mem, NewCurr);
    }
    Unlink_((LinkHelper*)FreeBlock);

    if (!Mem->SpareBlock) {
        Mem->SpareBlock = FreeBlock;
    } else {
        // return block to superblock

        FreeBlock->Prev = 0;
        #ifdef DEBUG
        FreeBlock->FuncTable = &SuperSanityTable;
        #endif
        FreeBlock->Next = Super->FirstBlock;
        Super->FirstBlock = FreeBlock;
        Sanity(FreeBlock->Next);
    }

    JB_Decr(Mem); // i hope this works...
    
    int N = --(Super->BlocksActive);
//    if (Super->World!=&MemoryManager) {
//        printf("Super: %s down to %i blocks\n", Super->World->Name, N);
//    }
    if (!N) {
        SuperBlockFree_(Super);
    }
}


//  OK so we got an issue where we decr an object, it's deleted, then we incr it
//  how to stop? delete could "mark as deleted"? And Incr could test for shit?
void JB_DeleteSub_( FreeObject* Obj, AllocationBlock* Block ) {
    Obj->Next = Block->FirstFree;
    Block->FirstFree = Obj;
    
    #ifdef JB_TEST_REFCOUNTING
        Obj->RefCount = 0xBABEFACE; // OK so it's normally expecting it to be 0...
        // will it affect alloc or anything else? I think just alloc?
    #endif

    if_usual (--(Block->ObjCount) >= 1) {
        return;
    }

    int Hidden = Block->HiddenObjCount;
    if ( Hidden ) { // unhide
        Block->ObjCount = Hidden;
        Block->HiddenObjCount = 0;
        AllocationBlock* Curr = Block->Owner->CurrBlock;
        if ( IsDummy(Curr) ) {
            SetCurrBlock_(Block->Owner, Block);
        } else {
            AddLink_( (LinkHelper*)Curr, (LinkHelper*)Block ); // allow it to be allocated from.
        }
        Sanity(Block);
    } else {
        BlockFree_( Block );
    }
}


__hot void JB_Delete( FreeObject* Obj ) {
    AllocationBlock* Block = ObjBlock_(Obj);
    Sanity(Block);
    fpDestructor Destructor = GetDestructor_(Block);
    if (Destructor) {
        (Destructor)((JB_Object*)Obj); // do this before altering memory.
    }
    JB_DeleteSub_(Obj, Block);
}


static inline JB_Object* Trap_(FreeObject* Obj) {
    #ifdef JB_TEST_REFCOUNTING
        Obj->RefCount = 0; // cos it's checked for elsewhere...
    #endif
    return (JB_Object*)Obj;
}


__hot JB_Object* JB_Alloc2( AllocationBlock* CurrBlock ) {
    FreeObject* Obj = CurrBlock->FirstFree;
    if_usual (Obj) {
        //Trap_(Obj);
        CurrBlock->ObjCount++;
        CurrBlock->FirstFree = Obj->Next;
        return Trap_(Obj);
    }
    return Trap_(JB_NewBlock( CurrBlock, CurrBlock->Owner ));
}



__hot JB_Object* JB_Alloc( MemoryLayer* Mem ) {
    AllocationBlock* CurrBlock = Mem->CurrBlock;
    FreeObject* Obj = CurrBlock->FirstFree;
    if_usual (Obj) {
        //Trap_(Obj);
        CurrBlock->ObjCount++;
        CurrBlock->FirstFree = Obj->Next;
        return Trap_(Obj);
    }
    return Trap_(JB_NewBlock( CurrBlock, Mem ));
}



MemoryWorld* JB_MemStandardWorld() {
    return &MemoryManager;
}



void JB_MemFree(MemoryWorld* World) {
    JB_MemoryReset(World, 0);
}


void JB_MemoryReset(MemoryWorld* World, int Max) {
    SuperBlock* First = World->CurrSuper;
    SuperBlock* Super = First;
    SuperBlock* Next = 0;
    int Count = 0;
    while (Next != First) {
        Next = Super->Next;
        if ((u32)Count >= (u32)Max) {
            Count++;
            JustGetRidOfIt_(Super, true, true);
        } else {
            JustGetRidOfIt_(Super, false, true);
        }
        if (!World->CurrSuper) {
            break; // last remaining.
        }   
        Super = Next;
    }
    #if DEBUG
//    printf("freed %i supers\n", Count);
    #endif
}


struct MemStats {
    int Objs;
    int Blocks;
};

MemStats JB_MemoryStats(bool CountObjs, bool ListAllClasses, MemoryWorld* World) {
    SuperBlock* First = World->CurrSuper; // issue?
    SuperBlock* Super = First; // issue?
    MemStats Result = {0, 0};
    if (!Super) { return Result; }
    
    do {
        Result.Blocks += (Super->BlocksActive);
        
        if (CountObjs) {
            AllocationBlock* Start = StartBlock_(Super);
            AllocationBlock* Finish = EndBlock_(Super);

            do {
                int C = Start->ObjCount + Start->HiddenObjCount;
                Result.Objs += C;
                Start = JBShift(Start, 1 << World->BlockSize);
            } while (Start < Finish);
        }

        Super = Super->Next;
    } while (Super != First);
    
#ifdef JB_ClassListing
//    if (ListAllClasses) JB_ListAllClasses(); // deleted that function cos it annoyed me.
#endif
    return Result;
}


u32 JB_MemCount() {
    MemoryWorld* World = JB_MemStandardWorld();
    return ( JB_MemoryStats(false, 0, World).Blocks ) << World->BlockSize;
}


bool JB_IsDebug() {
    #if DEBUG
    return true;
    #else
    return false;
    #endif
}





////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////


JBClassPlace3( MemoryLayer, JB_Mem_Destructor, JB_AsClass(JB_Object), 0 );

}


////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////


// tasks and threads... add it when I need it...


/* Amazing abilities and qualities

FAST
    * Typically 5 instructions for allocation of an object.
        * Refcount isn't set per object cos we know it's already zero!
    * 11x faster than C++'s new/delete
    * Instant block-reuse if old size matches new size.
    * 3 anti-thrash systems in total. 1 for superblocks... 2 for normal blocks.
    * Constructing simply over-writes. Doesn't pre-zero. FAST.
    * Destructor is stored per-block, avoids 3 pointer chases.
    * Refcounting is done with an optimised design... designed to be "optimised away".

TIGHT
    * Misaligned superblocks don't waste RAM.
    * Less than 1% overhead.
        * Class Information is stored once per block.
    * Incredibly small! Only 6K of real code.
        * Almost all code is debug only, headers, or utilities...

AWESOME
    * Multiple worlds allowed... objects + spacechunks.
        * Block/Superblock sizes can be adjusted... doesn't need 4K blocks...
    * Memory-layer oriented system allows grouping objects together meaningfully.
    * Has optional sanity-checking system, in case of errors.

HATED
    * Humans hate me and everything I do... at least that's how the past has been. I want things to change.
*/

