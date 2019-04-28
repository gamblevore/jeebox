
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


#ifndef AS_LIBRARY // overkill

#include "JB_Umbrella.h"
#include <time.h>
#include <sys/time.h>
#include <unistd.h>


#ifdef __MACH__
#include <mach/clock.h>
#include <mach/mach.h>
#endif


extern "C" {

void JB_Date__Sleep(float Time) {
    Time = Time * 1000000.0;
    int TimeInt = (int)Time;
    usleep(TimeInt);
}

int JB_Date__TimeID () {
// 2017y02m13d05h10m --> 2017021305
/*
    struct tm {
        int	 tm_sec;
        int	 tm_min;
        int	 tm_hour;
        int	 tm_mday;
        int	 tm_mon;
        int	 tm_year;
        int	 tm_wday;
        int	 tm_yday;
        int	 tm_isdst;
        long tm_gmtoff;
    };
*/    

    time_t t = time(NULL);
    tm* Time = localtime( &t );
    
    int H = Time->tm_hour;
    int D = Time->tm_mday         * 100;
    int M = (Time->tm_mon+1)      * 10000;
    int Y = (Time->tm_year+1900)  * 1000000;

    return (H + D) + (M + Y);
}


Date JB_Date__SpecToDate( timespec* tm ) {
    u64 NS = tm->tv_nsec;
    NS /= (u64)15259;
    u64 S = tm->tv_sec;
    S <<= 16;
    return S + NS;
}


Date JB_Date__MachSpecToDate( mach_timespec_t* tm ) {
    u64 NS = tm->tv_nsec; // Took me like 2 hours to get this function working
    NS /= (u64)15259;     // The original one-line version made sense... the compiler screwed up.
    u64 S = tm->tv_sec;   // Even: S *= kTicksPerSecond... failed. and kTicksPerSecond was in brackets!!
    S <<= 16;
    return S + NS;
}
// 0xFFFF -> 0.9999
// 0x8000 -> 0.5...

    
#ifdef __MACH__
    clock_serv_t cclock;
    void JB_Date__Init( ) {
        mach_port_t self = mach_host_self();
        host_get_clock_service(self, SYSTEM_CLOCK, &cclock); // doesn't actually allocate anything.
        // just returns a stupid number like 2051
    }
    
    Date JB_Date__Now( ) {
        mach_timespec_t mts;
        clock_get_time(cclock, &mts);
        return JB_Date__MachSpecToDate(&mts);
    }
#else
    Date JB_Date__Now( ) {
        struct timespec ts;
        clock_gettime(CLOCK_REALTIME, &ts);
        return JB_Date__SpecToDate(&ts);
    }
#endif
    
}
#else
    extern "C" void JB_Date__Init( ) {
        // nothing
    }

#endif
