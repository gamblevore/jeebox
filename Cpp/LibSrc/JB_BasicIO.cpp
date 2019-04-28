
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


#include "JB_Umbrella.h"
#include "JB_Log.h"
#include <stdio.h>
#ifndef AS_LIBRARY
#include <unistd.h>
#endif



extern "C" {

int StdOutFD_ = 1;
int StdErrFD_ = 2;
extern bool JB_ErrorsPrinted;
   
void JB_Pipe__StdErrorSet(int F) {
    StdErrFD_ = F;
}


void JB_Pipe__StdOutSet(int F) {
    StdOutFD_ = F;
}

#ifndef AS_LIBRARY
static void MyWrite_(int F, const char* s, int N) {
    write(F, s, N); // avoid writing to files if it's just jeebox!
}
void JB_Str_PrintError(JB_String* s) {
    JB_ErrorsPrinted = true;
    JB_Str_PrintTo(s, StdErrFD_);
}
#else
static void MyWrite_(int F, const char* s, int N) {
    printf("%.*s", N, s);
}
#endif

void JB_Str_PrintTo(JB_String* s, int Num) {
    int N = JB_Str_Length( s );
    if ( N ) {
        MyWrite_( Num, (const char*)s->Addr, N );
    }
}

void JB_Str_PrintLine(JB_String* s) {
    JB_Str_PrintTo(s, StdOutFD_);
    MyWrite_( StdOutFD_, "\n", 1 );
}

void JB_Str_Print(JB_String* s) {
    JB_Str_PrintTo(s, StdOutFD_);
}




}


