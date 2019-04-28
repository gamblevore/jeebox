

#ifndef __JB_ERRORS__
#define __JB_ERRORS__

#include "JB_Umbrella.h"

extern "C" {

int JB_ErrorHandleFile(JB_String* self, int errno, const char* Operation);
int JB_ErrorHandleC(const char* Msg, bool CanFree);

}

#endif

