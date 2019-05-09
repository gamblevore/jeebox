
////////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef __JB_ALLOC__
#define __JB_ALLOC__


#include <string.h>

////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// LANGUAGE ADDITIONS
#define JBShift( exp, amount ) ( (__typeof__ ( exp )) ((byte*)(exp)+(amount)))

#define likely(x)   __builtin_expect(!!(x),1)
#define unlikely(x) __builtin_expect(!!(x),0)

#define if_rare(x) if (unlikely(x))
#define if_usual(x) if (likely(x))
#define __hot __attribute__((hot))

#define __visible __attribute__((__visibility__("default")))

#if _WIN64 || __x86_64__ || __ppc64__
    #define ENV64BIT
#else
    #define ENV32BIT
#endif


////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////

extern "C" {

#ifdef JB_DEBUG_ON
    #define JBSanity( a ) // nothing for now
    #define JB_DEBUG(x) x
    #define JB_NOTDEBUG( a )
    #include <assert.h>
#else
    #define JBSanity( a )
    #define JB_NOTDEBUG( a ) a
    #define JB_DEBUG(x)
#endif


#ifdef DEBUG
    #define JB_TEST_REFCOUNTING
    #define debugger __asm__("int3") // int3 works in xcode but not in releasebuilds!
    #define dbgexpect(test)  if  (!(test)) {__asm__("int3"); return;} // int3 works in xcode but not in releasebuilds!
    #define dbgexpect2(test) if  (!(test)) {__asm__("int3"); return 0;} // int3 works in xcode but not in releasebuilds!
    #define JB_DoAt(count) static int DB = 0; DB++; int lDB = DB; if (lDB == count) {debugger;}
    #define DEBUGONLY(x) x
#else
    #define debugger // would crash...
    #define dbgexpect(test)
    #define dbgexpect2(test)
    #define JB_DoAt(count)
    #define DEBUGONLY(x)
#endif


//#define IsKnown(x) (((x) & ((x) - 1)) == 0)
#define AlwaysInline inline __attribute__((__always_inline__))
#define require(test)  if  (!(test)) {return 0;}
#define require0(test)  if  (!(test)) {return;}

//#define JB_Alloca(count) ((u8*)alloca(count)) // BAD! "while (N){alloca(10);}" // might as well exit(-1)
#include "JB_BasicTypes.h"
#include "JB_MemUtils.h"


    

////////////////////////////////////////////////////////////////////////////////////////////////////////////
#define kObjMinSize 8 // for now. In theory I can make it 4 but it would make refcounts slower.
//JB_Alloc2((name)->DefaultBlock)
#define JB_MArray(type, num)    ((type*)(JB_MArray_(sizeof(type),num)))
#define JB_NewClass(name)       (JB_Object*)(JB_Alloc2(name->DefaultBlock))
#define JB_New(name)            (name*)(JB_Alloc2((name ## Data).DefaultBlock))
#define JB_NewEmpty(name)       (name*)(ClearFor_(JB_New(name), sizeof(name)))
#define JB_LayerNew(L, name)    (name*)(JB_Alloc(L))
#define JB_Zero(name)           (ClearFor_((void*)(name), sizeof(__typeof__(*name))))
#define JBStructData(a)         extern JB_Class a ## Data;
#define JBClass(a, b, c)        struct a : b {c}; JBStructData(a);
#define JB_AsClass(Name)        (&(Name ## Data))

//    .Destructor = b,                                       
//    .Renderer = d,                                           
#define JBClassPlace3(a, b, c, d)  \
                                                                            \
JBObject_Behaviour a ## _FuncTable = {(void*)b,(void*)d};                   \
JB_Class a ## Data = {                                                      \
    .Name = (u8*)(#a),                                                      \
    .Parent = c,                                                            \
    .FuncTable = (JBObject_Behaviour*)&(a##_FuncTable),                     \
    .DefaultBlock = (AllocationBlock*)(&((a ## Data).Memory.Dummy)),        \
    .Memory.RefCount = 2,                                                   \
    .Memory.Class = &(a ## Data),                                           \
    .Memory.Dummy.Owner = &((a ## Data).Memory),                            \
    .Memory.CurrBlock = (AllocationBlock*)(&((a ## Data).Memory.Dummy)),    \
    .Memory.IsActive = true,                                                \
    .Memory.World = JB_MemStandardWorld(),                                  \
    .Size = Max(sizeof(a), kObjMinSize),                                    \
};

//    .Destructor = (fpDestructor)(c.__destructor__),                         
//    .Renderer = (fpRenderer)(c.render),                                     
#define JBClassPlace4(a, b, c)  JB_Class a ## Data = {                      \
    .Name = (u8*)(#a),                                                      \
    .Parent = b,                                                            \
    .DefaultBlock = (AllocationBlock*)(&((a ## Data).Memory.Dummy)),        \
    .FuncTable = (JBObject_Behaviour*)(&c),                                 \
    .Memory.RefCount = 2,                                                   \
    .Memory.Class = &(a ## Data),                                           \
    .Memory.Dummy.Owner = &((a ## Data).Memory),                            \
    .Memory.CurrBlock = (AllocationBlock*)(&((a ## Data).Memory.Dummy)),    \
    .Memory.IsActive = true,                                                \
    .Memory.World = JB_MemStandardWorld(),                                  \
    .Size = Max(sizeof(a), kObjMinSize),                                    \
};


////////////////////////////////////////////////////////////////////////////////////////////////////////////

struct MemoryLayer;
struct JB_Class;
struct FreeObject;
struct AllocationBlock;
struct JB_Object;
struct DummyBlock;
struct MemoryWorld;
struct SuperBlock;
struct GameFlyingMem;
struct FastString;
struct JB_String;
struct JBObject_Behaviour;

////////////////////////////////////////////////////////////////////////////////////////////////////////////
typedef JB_String* (*fpRenderer)(JB_Object* self, FastString* FS);
typedef void (*fpDestructor)(JB_Object* self);
typedef void (*fpAllocator)(AllocationBlock* self);
//typedef void (*fpDestructor)(FreeObject* Obj);
////////////////////////////////////////////////////////////////////////////////////////////////////////////

struct DummyBlock {
    MemoryLayer*            Owner;
    FreeObject*             FirstFree;
};


struct JB_Object {
    u32 RefCount;
};

struct MemoryLayer  { // is actually a JBObject... but a clang bug won't let me use "JBClass(MemoryLayer..."
    u32                 RefCount;
    AllocationBlock*    CurrBlock;
    JB_Class*           Class;
    AllocationBlock*    SpareBlock;
    MemoryWorld*        World;
    
    JB_Object*          Obj;
    JB_Object*          Obj2;
    bool                Owned;
    bool                IsActive;
    u16                 HiddenRefCount;

    DummyBlock          Dummy;
}; 
JBStructData (MemoryLayer);



struct JB_Class {
    u8*                 Name;
    JBObject_Behaviour* FuncTable;
    JB_Class*           Parent;
    AllocationBlock*    DefaultBlock;
    JB_Class*           NextClass;
    MemoryLayer         Memory;
    u16                 Size; // Move to MemoryLayer for refcountless allocs. Or put a "UsesRefCounts" bool in MemLayer
    u8*                 SaveInfo;
};

struct MemoryWorld {
    int                 RefCount;
    SuperBlock*         CurrSuper;
    SuperBlock*         SpareSuper;
    u8*                 Name;

    u8                  SuperSize;
    u8                  BlockSize;
    u8                  ShadowSize;
    u8                  Alignment;
    int                 SupersMade;
    
    float               SpareTrigger; // number of objects free in a block after which the block becomes "spare"...
};

struct JBObject_Behaviour {
	const void* __destructor__;
	const void* render;
};
struct JBSaver_Behaviour {
	const void* __destructor__;
	const void* render;
	const void* Load;
	const void* SaveCollect;
	const void* SaveWrite;
};


JBStructData(JB_Object);

////////////////////////////////////////////////////////////////////////////////////////////////////////////

MemoryWorld* JB_MemStandardWorld();
MemoryLayer* JB_Mem__New( JB_Class* Cls );
MemoryLayer* JB_Mem__NewObj(JB_Class* Cls, JB_Object* Obj);
void JB_Mem_Use( MemoryLayer* self );
void JB_Mem_OwnedSet(MemoryLayer* Mem, bool b);
bool JB_ObjIsOwned(JB_Object* Obj);
JB_Class* JB_ObjClass(JB_Object* Obj);
int JB_ObjRefCount(JB_Object* Obj);
u8* JB_ObjClassBehaviours(JB_Object* Obj);
JB_Object* JB_Mem_First( MemoryLayer* Mem );
JB_Object* JB_ObjNext(JB_Object* Obj);
MemoryLayer* JB_ObjLayer( JB_Object* Obj );
int JB_ObjID( JB_Object* Obj );
void JB_ObjDestroy( JB_Object* Obj );
MemoryLayer* JB_Class_DefaultLayer( JB_Class* Cls );
MemoryLayer* JB_Class_CurrLayer( JB_Class* Cls );
JB_Object* JB_Class_AllocZeroed( JB_Class* Cls );
void JB_Class_Add( JB_Class* Cls, const char* s );
JB_Class* JB_Class__First();
MemoryLayer* JB_Mem_UseNewLayer(JB_Class* Cls, JB_Object* Obj);
MemoryLayer* JB_Mem_CreateLayer(JB_Class* Cls, JB_Object* Obj);
void JB_Mem_InitAndUse(MemoryLayer* Mem, JB_Class* Cls);
void JB_Mem_Constructor( MemoryLayer* self, JB_Class* Cls );
void JB_Class_Init(JB_Class* Cls, MemoryWorld* World, int Size);
void JB_Class_SetIndex(JB_Class* cls, int i);
int JB_Class_Index(JB_Class* cls);
void JB_AllocSpeedTest();

////////////////////////////////////////////////////////////////////////////////////////////////////////////

__hot JB_Object* JB_Alloc( MemoryLayer* Mem );
void JB_MemoryReset(MemoryWorld* World, int Max);
__hot JB_Object* JB_Alloc2( AllocationBlock* CurrBlock );
u8* JB_NewStruct_( AllocationBlock* CurrBlock );
void JB_Delete( FreeObject* Obj );
__hot void JB_ClusterDelete( FreeObject* Obj );
void JB_MemFree(MemoryWorld* World);

////////////////////////////////////////////////////////////////////////////////////////////////////////////
#ifdef JB_DEBUG_ON
    void JB_Sanity(JB_Object* obj);
#else
    #define JB_Sanity( obj )
#endif
void JB_SanityCheck(AllocationBlock* Block);
typedef bool (*fpDebug)(void* Space, void* Result);
int JB_LeakTrace(u16 Flag);
typedef void (*fpListAllClasses)(JB_Class* M);
u32 JB_MemCount();
bool JB_IsDebug();
int JB_PointerSize();
void JB_MemList();
u32 JB_ObjCount();


////////////////////////////////////////////////////////////////////////////////////////////////////////////


#define JB_Incr(Obj)        JB_Incr_((JB_Object*)(Obj))
#define JB_Decr(Obj)        JB_Decr_((JB_Object*)(Obj))
#define JB_SafeDecr(Obj)    JB_SafeDecr_((JB_Object*)(Obj))
#define JB_FreeIfDead(Obj)  ((__typeof__(Obj))JB_FreeIfDead_((JB_Object*)(Obj)))
#define JB_SetRef(a,b)      JB_SetRef_((JB_Object**)(&a), (JB_Object*)(b))
#define JB_InitRef(a,b)     JB_InitRef_((JB_Object**)(&a), (JB_Object*)(b))
#define JB_ClearRef(a)      JB_ClearRef_((JB_Object**)(&a))
#define JB_RefCount(a)      JB_RefCount_((JB_Object*)(a))


#define JB_SafeAnd(A, B)              ({ \
    JB_Object* _A = (A);                 \
    JB_Object* _B = 0;                   \
    if (_A) {                            \
        _B = (B);                        \
        JB_FreeIfDead(_B);               \
    }                                    \
    JB_FreeIfDead(_A);                   \
    _B;                                  \
})


#ifdef JB_TEST_REFCOUNTING
    #define JBObjRefTest(obj) if (  (IntPtr)obj < 1000  or  (IntPtr)(obj->RefCount) < 0 ) { debugger; }
#else
    #define JBObjRefTest(obj)
#endif

inline JB_Object* JB_Incr_(JB_Object* obj) {
    if (obj) {
        JBObjRefTest(obj);
        obj->RefCount++;
    }
    return obj;
}

inline void JB_Decr_(JB_Object* obj) {
    if ( obj ) {
        JBObjRefTest(obj);
        if (!--obj->RefCount) {
            JB_Delete( (FreeObject*)obj );
        }
    }
}

inline JB_Object* JB_SafeDecr_(JB_Object* obj) {
    if (obj) {
        JBObjRefTest(obj);
        obj->RefCount--;
    }
    return obj;
}

inline JB_Object* JB_FreeIfDead_(JB_Object* obj) {
    if (obj) {
        JBObjRefTest(obj);
        if (!obj->RefCount) {
            JB_Delete( (FreeObject*)obj );
        }
    }
    return obj;
}

inline void JB_SetRef_(JB_Object** Place, JB_Object* New) {
	JB_Incr(New);
    JB_Object* Old = *Place; // Decr MUST come last, or else
	*Place = New; // a destructor can set a var into Place and we overwrite it.
	JB_Decr(Old);
}

inline void JB_InitRef_(JB_Object** Place, JB_Object* New) {
	JB_Incr(New); // for initing a library, we wanna just overwrite old garbage values.
	*Place = New;
}

inline void JB_ClearRef_(JB_Object** WhereToStore) {
    JB_Object* Old = *WhereToStore; // Decr MUST come last. Same bug as above :)
	*WhereToStore = 0;
	JB_Decr(Old);
}

inline int JB_RefCount_( JB_Object* obj ) {
    return obj->RefCount;
}
    
inline void* ClearFor_(void* Place, u32 Size) {
    memset(JBShift(Place,4), 0, Size - 4); // refcount should be 0. Don't hide bug if refcount > 0!
    return Place;
}
    

}

////////////////////////////////////////////////////////////////////////////////////////////////////////////

#endif // __JB_ALLOC__


