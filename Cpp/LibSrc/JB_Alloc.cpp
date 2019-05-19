
// Copyright, Theodore H. Smith 2019.
// Released under jeebox-licence http://jeebox.org/licence.txt



#include "JB_Alloc.h"
#include "JB_Log.h"


#ifdef ENV64BIT
    #define kBlockSize          13  // 8K!
#else
    #define kBlockSize          12  // 4K
#endif
// #define CheckSanity



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
    JB_MemoryWorld*            World;
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
    JB_MemoryLayer*         Owner;      // these two...
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


struct JBAllocTable {       // for pretending to be realloc. (we aren't)
    // Actually this is VERY inefficient, you lose about 3x of the speed compared to calling
    // JB_Alloc directly, however... many codebases can't simply be altered! That's why this exists.
    u8          Bins[128];  // 63bytes wasted. actually need 65, not 64!
    JB_Class    Classes[20];
};


enum {
    kFineBins = 3,
    kCoarseBins = 2,
};


int JB_AllocationBlockSize() {
    return sizeof(AllocationBlock);
}
void JB_Mem_Destructor( JB_MemoryLayer* self );


////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////

static bool IsDummy( const AllocationBlock* Block ) {
    AllocationBlock* OwnersDummy = (AllocationBlock*)(&Block->Owner->Dummy);
    return OwnersDummy == Block;
}
static fpDestructor GetDestructor_(AllocationBlock* B) {
    return (fpDestructor)(B->FuncTable->__destructor__);
}



static inline AllocationBlock* OfficialStart_(SuperBlock* NewSuper, IntPtr BlockSize) {
    return (AllocationBlock*)(((IntPtr)NewSuper | (BlockSize-1)) &~ (sizeof(AllocationBlock)-1));
}
static inline AllocationBlock* StartBlock_(SuperBlock* Block) {
    return Block->StartBlock;
}
static inline AllocationBlock* EndBlock_(SuperBlock* Block) {return (AllocationBlock*)Block->BlockEnd;}
#ifndef DEBUG
    #define Sanity(x)
#endif

////////////////////////////////////////////////////////////////////////////////////////////////////////////

JB_MemoryWorld MemoryManager;


static JBObject_Behaviour DummyFuncTable = {0, 0};
JB_Class* AllClasses;

JB_Class JBClassInit(JB_Class& Cls, const char* Name, int Size, JB_Class* Parent, JBObject_Behaviour* b) {
    if (!MemoryManager.Name) {
        MemoryManager.Name           = (u8*)"JB Standard Memory";
        MemoryManager.SuperSize      = 20;
        MemoryManager.BlockSize      = kBlockSize;
        MemoryManager.Alignment      = 4;
        MemoryManager.SpareTrigger   = 0.75f;
    }
    Cls.Name = (u8*)Name;
    Cls.Parent = Parent;
    Cls.FuncTable = b;
    Cls.DefaultBlock = (AllocationBlock*)(&Cls.Memory.Dummy);
    Cls.Memory.RefCount = 2;
    Cls.Memory.Class = &Cls;
    Cls.Memory.Dummy.Owner = &Cls.Memory;
    Cls.Memory.CurrBlock = (AllocationBlock*)(&Cls.Memory.Dummy);
    Cls.Memory.IsActive = true;
    Cls.Memory.World = &MemoryManager;
    Cls.Size = Max(Size, kObjMinSize);

    Cls.NextClass = AllClasses;
    AllClasses = &Cls;
    return Cls;
}



#if CheckSanity
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


static void SanityOfInUse(SuperBlock* Sup, JB_MemoryWorld* World) {
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
#else
#define Sanity(x)
#endif


void JB_Class_Init(JB_Class* Cls, JB_MemoryWorld* World, int Size) {
    memzero(Cls, sizeof(JB_Class)); // can’t use JB_Zero.
    Cls->DefaultBlock = (AllocationBlock*)(&Cls->Memory.Dummy);
    Cls->Size = Size;
    Cls->Memory.RefCount = 1, // so it never goes away
    Cls->Memory.CurrBlock = (AllocationBlock*)(&Cls->Memory.Dummy);
    Cls->Memory.Dummy.Owner = &Cls->Memory;
    Cls->Memory.World = World;
    Cls->Memory.Class = Cls;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////


void JB_Mem_Constructor( JB_MemoryLayer* self, JB_Class* Cls ) {
    JB_Zero(self);
    self->Class = Cls;
    self->CurrBlock = (AllocationBlock*)&(self->Dummy);
    self->Dummy.Owner = self;
    self->World = JB_MemStandardWorld();
}


JB_MemoryLayer* JB_Mem_CreateLayer(JB_Class* Cls, JB_Object* Obj) {
    JB_MemoryLayer* Mem = JB_New(JB_MemoryLayer);
    JB_Mem_Constructor(Mem, Cls);
    JB_SetRef(Mem->Obj, Obj);
    return Mem;
}

JB_MemoryLayer* JB_Mem_UseNewLayer(JB_Class* Cls, JB_Object* Obj) {
    JB_MemoryLayer* Mem = JB_Mem_CreateLayer(Cls,Obj);
    JB_Mem_Use(Mem);
    return Mem;
}


void JB_Mem_Use( JB_MemoryLayer* self ) {
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


void JB_Mem_Destructor( JB_MemoryLayer* self ) {
    if (self->SpareBlock) {
        self->SpareBlock->Owner = 0;
    }
    JB_ClearRef( self->Obj );
    JB_ClearRef( self->Obj2 );
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

JB_MemoryLayer* JB_Class_CurrLayer( JB_Class* Cls ) {
    return Cls->DefaultBlock->Owner;
}

JB_Object* JB_Class_AllocZeroed( JB_Class* Cls ) {
    JB_Object* Result = JB_Alloc2(Cls->DefaultBlock);
    if (Result) {
        memzero(Result, Cls->Size);
    }
    return Result;
}

JB_MemoryLayer* JB_Class_DefaultLayer( JB_Class* Cls ) {
    return &Cls->Memory;
}

JB_MemoryLayer* JB_ObjLayer( JB_Object* Obj ) {
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

static void SetCurrBlock_( JB_MemoryLayer* Mem, AllocationBlock* NewBlock ) {
Sanity(NewBlock);
    JB_Class* Cls = Mem->Class;
    if (Cls and (Cls->DefaultBlock == Mem->CurrBlock)) {
        // class is using this JB_MemoryLayer...
        Cls->DefaultBlock = NewBlock;
    }
    
    Mem->CurrBlock = NewBlock;
}

static FreeObject* LinkIn_(JB_MemoryLayer* Mem, AllocationBlock* NewBlock) {
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

static AllocationBlock* LinkInSuper_(JB_MemoryWorld* World, SuperBlock* Super) {
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
static inline void SetupSuper_(SuperBlock* Super, JB_MemoryWorld* W) {
    AllocationBlock* Curr = StartBlock_( Super );
    AllocationBlock* End =  EndBlock_( Super ); // end is too far, somehow. it's 4100K but we only allocated 4096K?
    int Size = 1 << W->BlockSize;

    Super->FirstBlock = Curr;

    while (Curr < End) {
        AllocationBlock* Next = JBShift(Curr, Size);
        Curr->Super = Super;
        #ifdef CheckSanity
        Curr->FuncTable = &SuperSanityTable;
        #endif
        Curr->Owner = 0; // for clearing
        Curr->Next = Next;
        Curr = Next;
    }
    Curr = JBShift(Curr, -Size);
    Curr->Next = 0;
}




static void InitObjectsInBlock_(AllocationBlock* NewBlock, JB_MemoryWorld* W, int Size) {
    // I'm pretty sure this loop is perfect. So if we get any errors... it can’t be from here.
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



static AllocationBlock* SuperBlockSetup_( SuperBlock* Super, JB_MemoryWorld* World ) {
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


static FreeObject* BlockSetup_ ( JB_MemoryLayer* Mem, AllocationBlock* NewBlock, JB_MemoryWorld* World ) {
    if (!NewBlock) {
        return 0;
    }
    Sanity(NewBlock);
    JB_Class* Class = Mem->Class;
    NewBlock->FuncTable = NeedRealTable_(Class->FuncTable); // helps avoid touching uncached RAM.
    int Size = Class->Size;
    NewBlock->Owner = Mem;

    if (NewBlock->ObjSize != Size) {
        InitObjectsInBlock_( NewBlock, World, Size );
    }

    SelfLink_((LinkHelper*)NewBlock);

    return LinkIn_(Mem, NewBlock);
}




// SuperBlocks
// JB_MemoryLayer
// AllocationBlocks
// Objects


static bool OutOfMemoryHappenedAlready;
void JB_OutOfMemory(int N) {
    if (!OutOfMemoryHappenedAlready) {
        OutOfMemoryHappenedAlready = true;
        printf("Failed to allocate RAM (%i bytes) : (JB_Alloc.cpp)\n", N);
    }
}

bool JB_OutOfMemoryOccurred () {
    // read by ErrorReceiver!
    return OutOfMemoryHappenedAlready;
}



static SuperBlock* Super_calloc(JB_MemoryWorld* World) {
    int N = (1 << World->SuperSize);
    int Align = (1 << World->BlockSize);

    while (N >= Align*4) {
        #if __linux__
        SuperBlock* bla = (SuperBlock*)aligned_alloc(Align, N);
        #else 
        SuperBlock* bla = (SuperBlock*)malloc_zone_memalign(malloc_default_zone(), Align, N);
        #endif
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


static void SuperFree_(SuperBlock* Super) {
//    printf("freeing super %X\n", (void*)Super);
    Super->World->RefCount--;
    #if __linux__
    free(Super);
    #else 
    malloc_zone_free(malloc_default_zone(), Super);
    #endif
}


static SuperBlock* AllocSuper(JB_MemoryWorld* World) {
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


static AllocationBlock* NewSuperBlock_(JB_MemoryLayer* Mem, JB_MemoryWorld* World) {
    SuperBlock* Super = AllocSuper(World);
    require(Super);
    return SuperBlockSetup_( Super, World );
}


static AllocationBlock* FindAllocBlock_(JB_MemoryWorld* World) {
    SuperBlock* First = World->CurrSuper;
    if (!First) {
        return 0;
    }
    SuperBlock* Curr = First;
    
    do {
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


static AllocationBlock* ReturnSpare_(JB_MemoryLayer* Mem) {
// Allocate a "NewBlock" by just re-using the spareblock as the currentblock...
    AllocationBlock* NewBlock = ReturnSpareHidden_( Mem->CurrBlock );
    if (NewBlock) {
        return NewBlock;
    }

    NewBlock = Mem->SpareBlock;
    Sanity(NewBlock);
    if (NewBlock) { // Improvement?: Stick the spareblock on the normal "next" list. And just test that it's a spare. 1 less branch!
        if (NewBlock->Owner!=Mem) {
            debugger; // big problem, our cleanspares function assumes this!
        }
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


FreeObject* JB_NewBlock( AllocationBlock* CurrBlock ) {
    Sanity(CurrBlock);

    JB_MemoryLayer* Mem = CurrBlock->Owner;
    if (Mem->DontAlloc) {
        return 0;
    }
    JB_MemoryWorld* World = Mem->World;
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


static JB_Class* ResetClass_( JB_Class* Cls ) {
    auto Mem = &Cls->Memory;
    if (Mem->RefCount != 2) {
//        debugger; /// It's cached somewhere :(
        Mem->RefCount = 2;
    }
    Mem->CurrBlock = Cls->DefaultBlock = (AllocationBlock*)&(Cls->Memory.Dummy);
    JB_Class* Result = Cls->NextClass;
    Cls->NextClass = 0;
    Mem->SpareBlock = 0; // why not?
    return Result;
}


static void CleanSpares_( SuperBlock* Super ) {
    JB_MemoryWorld* World = Super->World;
    int N = 1 << World->BlockSize;
    AllocationBlock* Curr = StartBlock_(Super);
    AllocationBlock* End = EndBlock_(Super);

    while (Curr < End) { // not too sure this test is correct!
        JB_MemoryLayer* Mem = Curr->Owner;
        if ( Mem ) { // Only exists if its a spare, seeing as the superblock's refcount is 0.
            Mem->SpareBlock = 0;
        }
        Curr = JBShift(Curr, N);
    }
}



static void PossiblyLast_(SuperBlock* Super) {
    JB_MemoryWorld* World = Super->World;
    if (World->CurrSuper == Super) {  // issue?
        SuperBlock* Next = Super->Next;
        if (Next == Super) {
            Next = 0;
        }
        World->CurrSuper = Next; // issue?
    }
}


static void JustGetRidOfIt_(SuperBlock* Super, bool ResettingApp) {
    PossiblyLast_(Super);
    Unlink_( (LinkHelper*)Super );
    if (!ResettingApp) {
        CleanSpares_( Super );
    }
    SuperFree_(Super);
}


static bool IsAlone_(SuperBlock* Super) {
    return Super->Next == Super;
}


static void SuperBlockFree_(SuperBlock* Super) {
    JB_MemoryWorld* World = Super->World;
    if ( World->SpareSuper ) {
        JustGetRidOfIt_(Super, false);

    } else if ( !IsAlone_( Super ) ) {
        World->SpareSuper = Super; // issue?
    }
}


static void BlockFree_( AllocationBlock* FreeBlock ) {
    Sanity(FreeBlock);
    JB_MemoryLayer* Mem = FreeBlock->Owner;
    SuperBlock* Super = FreeBlock->Super;
    if (Mem->RefCount == 2) {
        if (!Mem->World->SpareSuper and IsAlone_( Super ) ) { // avoid freeing last super, avoid thrashing.
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
//    FreeBlock->Owner = 0;

    if (!Mem->SpareBlock) {
        Mem->SpareBlock = FreeBlock;
    } else {
        // return block to superblock

        FreeBlock->Prev = 0;
        #ifdef CheckSanity
        FreeBlock->FuncTable = &SuperSanityTable;
        #endif
        FreeBlock->Next = Super->FirstBlock;
        Super->FirstBlock = FreeBlock;
        Sanity(FreeBlock->Next);
    }

    JB_Decr(Mem); // i hope this works...
    
    int N = --(Super->BlocksActive);
    if (!N) {
        SuperBlockFree_(Super);
    }
}


void JB_DeleteSub_( FreeObject* Obj, AllocationBlock* Block ) {
    // used by my other projects for custom memory managers!
    Obj->Next = Block->FirstFree;
    Block->FirstFree = Obj;
    
    #ifdef __SPEEDIE__
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
    #ifdef __SPEEDIE__
        Obj->RefCount = 0; // cos it's checked for elsewhere...
    #endif
    return (JB_Object*)Obj;
}


__hot JB_Object* JB_Alloc2( AllocationBlock* CurrBlock ) {
    FreeObject* Obj = CurrBlock->FirstFree;
    if_usual (Obj) {
        CurrBlock->ObjCount++;
        CurrBlock->FirstFree = Obj->Next;
        return Trap_(Obj);
    }
    return Trap_(JB_NewBlock( CurrBlock ));
}



__hot JB_Object* JB_Alloc( JB_MemoryLayer* Mem ) {
    AllocationBlock* CurrBlock = Mem->CurrBlock;
    FreeObject* Obj = CurrBlock->FirstFree;
    if_usual (Obj) {
        CurrBlock->ObjCount++;
        CurrBlock->FirstFree = Obj->Next;
        return Trap_(Obj);
    }
    return Trap_(JB_NewBlock( CurrBlock ));
}



JB_MemoryWorld* JB_MemStandardWorld() {
    return &MemoryManager;
}


void JB_MemFree(JB_MemoryWorld* World) {
    SuperBlock* First = World->CurrSuper;
    SuperBlock* Super = First;
    JB_Class* Cls = AllClasses; AllClasses = 0;
    while (Cls) {
        Cls = ResetClass_(Cls);
    }

    SuperBlock* Next = 0;
    while (Next != First and World->CurrSuper) {
        Next = Super->Next;
        JustGetRidOfIt_(Super, true);
        Super = Next;
    }
}


struct MemStats {
    int Objs;
    int Blocks;
};

MemStats JB_MemoryStats(bool CountObjs, bool ListAllClasses, JB_MemoryWorld* World) {
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
    return Result;
}


u32 JB_MemCount() {
    JB_MemoryWorld* World = JB_MemStandardWorld();
    return ( JB_MemoryStats(false, 0, World).Blocks ) << World->BlockSize;
}



////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//// CODE FOR PRETENDING TO BE REALLOC
//// USEFUL FOR LUA.
//// SLOWER IN GENERAL!!!!!!!!!!!!!!!!!!!
//// YES, SLOWER. (than "the right way").
//// The-right-way to use jb_alloc is the class-based way, for allocating objects.
//// Maximum speed with minimum overhead.
//// Right-way:                         type* x = JB_New(type);
//// But we can still improve some code-bases by pretending that sizes are classes.
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void BuildAllocSub_(JB_Class& C, JB_MemoryWorld* World, int Size) {
    JB_MemoryLayer& M = C.Memory;
    M.World = World;
    JBClassInit(C, "", Size, nil, nil);
}

void JB_DestroyAllocatorTable(JBAllocTable* Table) {
    JB_MemFree(JB_MemStandardWorld());
    free(Table);
}

void* JB_BuildAllocatorTable(JB_MemoryWorld* World) {
    if (!World) {World = JB_MemStandardWorld();}
#ifdef ENV64BIT
    dbgexpect2(sizeof(JB_Class)==128); // faster
#endif
    
    int N = sizeof(JBAllocTable);
    JBAllocTable* Table = (JBAllocTable*)calloc(N, 1);
    u32 CurrSize = 4;
    u32 CurrStep = 4;
    
    BuildAllocSub_(Table->Classes[0], World, 0);
    Table->Classes[0].Memory.DontAlloc = true; // sometimes we ask for a 0 ptr? Why?
    u32 j = 1;
    
    while (true) {
        if (j >= 32) { debugger; }
        CurrSize += CurrStep;
        if (CurrSize > 256) {break;}
        JB_Class& C = Table->Classes[j++];
        C.Size = CurrSize; // or whatever
        int Granularity = kFineBins;
        if ((CurrSize>>Granularity) >= CurrStep) {
            CurrStep*=2;
        }
        BuildAllocSub_(C, World, CurrSize);
    }
    
    
    j = 1;
    for (CurrSize = 1; CurrSize <= 256; CurrSize++) {
        int ActualNeeded = (CurrSize + 3) &~ 3;
        if (ActualNeeded > Table->Classes[j].Size) {
            j++;
        }
        Table->Bins[ActualNeeded>>2] = j;
    }
    

    return Table;
}


// nice.
JB_Object* jballocn(JBAllocTable* Table, u32 N) {
    N = Table->Bins[(N+3)>>2];
    return JB_Alloc2(Table->Classes[N].DefaultBlock);
}

extern "C" void* jbrealloc(JBAllocTable* Table, int N, JB_Object* Obj) {
    AllocationBlock* B = ObjBlock_(Obj);        // need the old-size first.
    u32 MaxSize = B->ObjSize;                   // nice
    
    // Now compare to see if they are close enough... 
    if (N <= MaxSize and N >= MaxSize/2) {
        return Obj; // nice!
    }

    // I guess we need a new object.
    JB_Object* Result = jballocn(Table, N);
    require(Result);
    memcpy(Result, Obj, Min(N, MaxSize));
    
    return Result;
}


void* JB_LuaAllocator (JBAllocTable* ud, void* ptr, size_t osize, size_t nsize) {
    if (!ptr) {                                 // alloc
        if (nsize <= 256) { // common path
            return jballocn(ud, (int)nsize);
        } else {
            return malloc(nsize);
        }
    } else if (!nsize) {                        // free
        if (osize <= 256) {
            JB_Delete((FreeObject*)ptr);
        } else {
            free(ptr);
        }
        return NULL;
    }
                                                // resize
    if (nsize > 256 and osize > 256) {
        return realloc(ptr, nsize);
    } else if (nsize <= 256 and osize <= 256) {
        return jbrealloc(ud, (int)nsize, (JB_Object*)ptr);
    }
    
    // kinda Awkward copies
    size_t CopySize = nsize;
    if (CopySize > osize) {CopySize = osize;}
    if (nsize <= 256) {
        void* Result = jballocn(ud, (int)nsize);
        if (!Result) return 0;
        memcpy(Result, ptr, CopySize);
        free(ptr);
        return Result;
    }
    
    void* Result = malloc(nsize);
    if (!Result) return 0;
    memcpy(Result, ptr, CopySize);
    JB_Delete((FreeObject*)ptr);
    return Result;
}




/////////////////////////////////////////////////////////////////////////////////////////////////////////
JBClassPlace( JB_Object,       0,                  0,                          0 );
JBClassPlace( JB_MemoryLayer,     JB_Mem_Destructor,  JB_AsClass(JB_Object),      0 );
/////////////////////////////////////////////////////////////////////////////////////////////////////////

}


// tasks and threads... add it when I need it...
// fireballs at da police's heads.
