
#include "JB_Alloc.h"
#include "JB_String.h"
#include <chrono>


#define Time(a,b) (std::chrono::duration_cast<std::chrono::duration<double>>(a - b).count())
void AllocSpeedTest() {
    const int ArraySize = 100000;
    
    JB_StringC* Array[ArraySize];

    for (int i = 0; i < 50; i++) { // warmup jb
        JB_StringC* S = JB_New( JB_StringC );
        JB_Delete((FreeObject*)S);
    }
    
    auto JBStart = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < ArraySize; i++) {
        JB_StringC* S = JB_New( JB_StringC ); 
        Array[i] = S;
    }
    for (int i = 0; i < ArraySize; i++) {
        JB_Delete((FreeObject*)Array[i]);
    }
    auto JBEnd = std::chrono::high_resolution_clock::now();
    
    
    for (int i = 0; i < 50; i++) { // warmup new/delete
        JB_StringC* S = new(JB_StringC); 
        delete(S);
    }
    auto MallocStart = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < ArraySize; i++) {
        Array[i] = new(JB_StringC);
    }
    for (int i = 0; i < ArraySize; i++) {
        delete(Array[i]);
    }
    auto MallocEnd = std::chrono::high_resolution_clock::now();
    
    double MTime = Time(MallocEnd,MallocStart);
    double JTime = Time(JBEnd,JBStart);
    
    printf("new/delete: %f time for %i reps\n", MTime, ArraySize);
    printf("jballoc: %f time for %i reps\n", JTime, ArraySize);
    printf("jb is %f times faster\n", MTime/JTime);
}


int main() {
    for (int i = 0; i < 10; i++) {
        AllocSpeedTest();
    }
    return 0;
}


