
#include "JB_Alloc.h"
#include <chrono>

#define Time(a,b) (std::chrono::duration_cast<std::chrono::duration<double>>(a - b).count())

struct OurClass {
    int A;
    int B;
    int C;
    int D;
};
JBClassPlace( OurClass, 0, 0, 0 );

struct OurClass2 {
    int A;
    int B;
    int C;
    int D[4];
};
JBClassPlace( OurClass2, 0, 0, 0 );

struct OurClass3 {
    int A;
    int B;
    int C;
    int D[7];
};
JBClassPlace( OurClass3, 0, 0, 0 );

struct OurClass4 {
    int A;
    int B;
    int C;
    int D[10];
};
JBClassPlace( OurClass4, 0, 0, 0 );

struct OurClass5 {
    int A;
    int B;
    int C;
    int D[13];
};
JBClassPlace( OurClass5, 0, 0, 0 );

struct OurClass6 {
    int A;
    int B;
    int C;
    int D[16];
};
JBClassPlace( OurClass6, 0, 0, 0 );


void AllocSpeedTest() {
    const int ArraySize = 100000;
    const int TestReps = 50;
    
    OurClass* Array[ArraySize];

    for (int i = 0; i < 50; i++) { // warmup jb
        OurClass* S = JB_New( OurClass );
        JB_Delete((FreeObject*)S);
    }
    
    auto JBStart = std::chrono::high_resolution_clock::now();
    for (int SlowCount = 0; SlowCount < TestReps; SlowCount++) {
        for (int i = 0; i < ArraySize; i++) {
            OurClass* S = JB_New( OurClass ); 
            Array[i] = S;
        }
        for (int i = 0; i < ArraySize; i++) {
            JB_Delete((FreeObject*)Array[i]);
        }
    }
    auto JBEnd = std::chrono::high_resolution_clock::now();
    
    
    for (int i = 0; i < 50; i++) { // warmup new/delete
        OurClass* S = new(OurClass); 
        delete(S);
    }
    auto NewStart = std::chrono::high_resolution_clock::now();
    for (int SlowCount = 0; SlowCount < TestReps; SlowCount++) {
        for (int i = 0; i < ArraySize; i++) {
            Array[i] = new(OurClass);
        }
        for (int i = 0; i < ArraySize; i++) {
            delete(Array[i]);
        }
    }
    auto NewEnd = std::chrono::high_resolution_clock::now();
    
//
    for (int i = 0; i < 50; i++) { // warmup malloc/free
        OurClass* S = (OurClass*)malloc(sizeof(OurClass)); 
        free(S);
    }
    auto MallocStart = std::chrono::high_resolution_clock::now();
    for (int SlowCount = 0; SlowCount < TestReps; SlowCount++) {
        for (int i = 0; i < ArraySize; i++) {
            Array[i] = (OurClass*)malloc(sizeof(OurClass));
        }
        for (int i = 0; i < ArraySize; i++) {
            free(Array[i]);
        }
    }
    auto MallocEnd = std::chrono::high_resolution_clock::now();
    
//
    double MTime = Time(MallocEnd, MallocStart);
    double NTime = Time(NewEnd, NewStart);
    double JTime = Time(JBEnd, JBStart);
    
    printf("new/delete:  %fs\n", NTime);
    printf("malloc/free: %fs\n", MTime);
    printf("jballoc:     %fs\n", JTime);
    printf("jballoc vs new/delete = %fx (%i allocs)\n\n", NTime/JTime, ArraySize*TestReps);
}




#ifndef __linux__
u64 TotalMemoryCount() {
    malloc_statistics_t stats;
    malloc_zone_statistics(0, &stats);
    return stats.size_in_use;
}
#endif


struct LinkTest {
    void* Next;
};

LinkTest* Link(void* New, LinkTest* Curr) {
    Curr->Next = New;
    return (LinkTest*)New; // ensure all new/mallocs are used, and not optimised away!
}

void AllocSizeTest(const char* type) {
    int N = 100000;
    // simply leak! No need to free as we are testing memory efficiency.
    LinkTest L = {};
    LinkTest* Curr = &L;
    if (!strcmp(type, "jb")) {
        for (int i = 0; i < N; i++) {
            Curr = Link( JB_New(OurClass), Curr);
            Curr = Link( JB_New(OurClass2), Curr);
            Curr = Link( JB_New(OurClass3), Curr);
            Curr = Link( JB_New(OurClass4), Curr);
            Curr = Link( JB_New(OurClass5), Curr);
            Curr = Link( JB_New(OurClass6), Curr);
        }
    } else if (!strcmp(type, "malloc")) {
        for (int i = 0; i < N; i++) {
            Curr = Link( malloc(sizeof(OurClass)), Curr);
            Curr = Link( malloc(sizeof(OurClass2)), Curr);
            Curr = Link( malloc(sizeof(OurClass3)), Curr);
            Curr = Link( malloc(sizeof(OurClass4)), Curr);
            Curr = Link( malloc(sizeof(OurClass5)), Curr);
            Curr = Link( malloc(sizeof(OurClass6)), Curr);
        }
    } else if (!strcmp(type, "new")) {
        for (int i = 0; i < N; i++) {
            Curr = Link( new OurClass, Curr);
            Curr = Link( new OurClass2, Curr);
            Curr = Link( new OurClass3, Curr);
            Curr = Link( new OurClass4, Curr);
            Curr = Link( new OurClass5, Curr);
            Curr = Link( new OurClass6, Curr);
        }
    } else {
        puts("unrecognised name");
        exit(-1);
    }
    
    int MinSize = (sizeof(OurClass) + sizeof(OurClass2) + sizeof(OurClass3) + sizeof(OurClass4) + sizeof(OurClass5) + sizeof(OurClass6))*N;
    
    #if __linux__
    malloc_stats();
    #else
    printf("%iKB allocated for %s allocating %i objects (%iKB min)\n", (int)(TotalMemoryCount()/1024), type, N*6, MinSize/1024);
    #endif
}

// from my test in ubuntu linux 18.04
// jb:  28716640
// new: 36873312
// new is about 28% bigger. so JB does give
// space savings, and some speed savings too.



int main(int argc, const char * argv[]) {
    const char* type = argv[1];
    if (!type or !strcmp(type, "")) {
        for (int i = 0; i < 10; i++) {
            AllocSpeedTest();
        }
    } else {
        AllocSizeTest(type);
    }
    return 0;
}



