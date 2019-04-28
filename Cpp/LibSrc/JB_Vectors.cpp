
// By Theodore H. Smith, released under zlib licence v1.2.11
/* zlib.h -- interface of the 'zlib' general purpose compression library
  version 1.2.11, January 15th, 2017

  Copyright (C) 1995-2017 Jean-loup Gailly and Mark Adler

  This software is provided 'as-is', without any express or implied
  warranty.  In no event will the authors be held liable for any damages
  arising from the use of this software.

  Permission is granted to anyone to use this software for any purpose,
  including commercial applications, and to alter it and redistribute it
  freely, subject to the following restrictions:

  1. The origin of this software must not be misrepresented; you must not
     claim that you wrote the original software. If you use this software
     in a product, an acknowledgment in the product documentation would be
     appreciated but is not required.
  2. Altered source versions must be plainly marked as such, and must not be
     misrepresented as being the original software.
  3. This notice may not be removed or altered from any source distribution.

  Jean-loup Gailly        Mark Adler
  jloup@gzip.org          madler@alumni.caltech.edu
*/

/*
	Copyright (C) 2013 Theodore H. Smith.
*/

#ifndef AS_LIBRARY
#include "JB_Umbrella.h"
#include <cpuid.h>

extern "C" {

void cpuid(int CPUInfo[4], int InfoType) {
    __asm__ __volatile__ (
        "cpuid":
        "=a" (CPUInfo[0]),
        "=b" (CPUInfo[1]),
        "=c" (CPUInfo[2]),
        "=d" (CPUInfo[3]) :
        "a" (InfoType), "c" (0)
    );
}

bool SimdDetectAVX() {
    int info[4];
    cpuid(info, 0x00000001);
    return (info[2] & ((int)1 << 28)) != 0;
}

bool SimdDetectAVX2() {
    int info[4];
    cpuid(info, 0x00000001);
    return (info[1] & ((int)1 <<  5)) != 0;
}


bool SimdDetectAVX512() {
    int info[4];
    cpuid(info, 0x00000001);
    return (info[1] & ((int)1 << 16)) != 0;
}

bool SimdDetectSSE42() {
    int info[4];
    cpuid(info, 0x00000001);
    return (info[2] & ((int)1 << 20)) != 0;
}

inline u64 RDTSC() {
	unsigned long long tsc;
	asm("rdtsc" : "=A"(tsc));
    return tsc;
}

} // 


#endif

