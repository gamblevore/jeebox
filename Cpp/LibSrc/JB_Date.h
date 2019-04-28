

#ifndef __JB_DATE__
#define __JB_DATE__

#include "JB_Umbrella.h"

extern "C" {
    
    // do I really want such a class? why not just use a 64-bit value?
    // I could do... hmmm.... 32+16=48 bits for seconds? and 16 for fractional seconds?
    // That gives us 9 million year time range. Quite enough...
    struct timespec;
    Date JB_Date__SpecToDate( timespec* tm );
    int JB_Date__TimeID ();
    void JB_Date__Sleep(float Time);
    Date JB_Date__Now( );
    void JB_Date__Init( );

}

#endif

