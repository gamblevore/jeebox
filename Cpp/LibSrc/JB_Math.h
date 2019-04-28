

#ifndef __JB_MATH__
#define __JB_MATH__

#include "JB_Umbrella.h"

extern "C" {
    int JB_Math_Rnd32();
    float fclampf (float d, float min, float max);
    float JB_fCluster (float x);
    u32 JB_u32_hash (u32 x);
    u32 JB_u32_unhash (u32 x);
    u64 JB_u64_hash (u64 x);
     
    inline float JB_f__max () {
        return __FLT_MAX__;
    }
    inline float JB_f__nan () {
        return __builtin_nanf("");
    }
}

#endif

