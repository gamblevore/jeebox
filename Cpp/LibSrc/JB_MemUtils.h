


#include <string.h>
#if defined(__linux__)
    #include <stdlib.h>
    #include <malloc.h>
#else
    #include <malloc/malloc.h>
#endif

extern "C" {
#define CopyBytes(s0, d, Length) memcpy((void*)(d), (void*)(s0), (unsigned int)(Length));

struct JB_Object;

bool JB_OutOfMemoryOccurred();
u64 JB_TotalMemoryCount();
void JB_TooLargeAlloc(const char* S, int N, int R);
void JB_OutOfMainMemory(int N);
void JB_OutOfUserMemory(int N);
void* JB_malloc(int N);
void* JB_zalloc(int N);
void* JB_realloc(const void* Arr, int N);
void JB_free(const void* Arr);
u64 JB_msize(const void* Arr);
void JB_mtest(const void* M);


inline void memzero(void* Where, int N) {
    memset(Where, 0, N);
}

inline int JB_Int_CountBits (int X) {
    return __builtin_popcount(X);
}

inline int JB_f_AsInt(float f) {
    float* fp = &f;
    int* ip = (int*)fp;
    return *ip;
}

inline int JB_Int_Log2 (int X) {
    return (31 xor __builtin_clz(X)); // Y-X = Y xor X, if X > Y.... or something like that!
}


inline int JB_u64_Log2 (u64 X) {
    return (63 xor __builtin_clzll(X)); // Y-X = Y xor X, if X > Y.... or something like that!
}

inline int JB_Int_BiggestBit (int X) {
    int N = JB_Int_Log2( X );
    return 1 << (N - 1);
}

inline int JB_Int_RoundUp(int N, int To) {
    int Over = N % To;
    if (!Over) {return N;}
    return N + (To-Over);
}

}


