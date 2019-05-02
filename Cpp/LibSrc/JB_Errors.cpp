
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
#include <unistd.h>

extern "C" {


JB_String* FreeableStr_(const char* Msg, bool CanFree) {
    // if canfree is true, then... we will call free() on dispose.
    // otherwise not.
    if (!CanFree) {
        return JB_Str(Msg);
    }

    JB_String* Result = JB_New( JB_String );
    Result->Addr = (u8*)Msg;
    Result->Length = (int)strlen(Msg);
    return Result;
}


void JB_ErrorHandle2C(const char* Desc, bool CanFreeDesc, const char* Path, bool CanFreePath) {
    JB_Error* Err = JB_Err__New();
    JB_Err_Fill(Err, FreeableStr_(Path, CanFreePath), FreeableStr_(Desc, CanFreeDesc)); 
    JB_Rec_NewItem(JB_StdErr, Err);
}




void JB_ErrorHandleFileC(const char* Path, int err, const char* Operation) {
    JB_ErrorHandleFile(JB_Str_FromCString_(Path), err, Operation);
}

int JB_ErrorHandleFile(JB_String* self, int err, const char* Operation) {
    JB_Error* Err = JB_Err__New();
    FastString* FS = JB_FS__FastNew(0);
    
    JB_FS_AppendIntegerAsText(FS, err, 1);
    JB_FS_AppendCString(FS, " (");
    JB_FS_AppendCString(FS, strerror(err));
    JB_FS_AppendCString(FS, ") occured trying to ");
    JB_FS_AppendCString(FS, Operation);
    JB_FS_AppendCString(FS, " file.");
    
    if (self and JB_Str_ByteValue(self, 0)!= '/') {
        JB_FS_AppendCString(FS, " (at ");
        char* cwd = getcwd( 0, 0 );
        JB_FS_AppendCString(FS, cwd);
        free( cwd );
        JB_FS_AppendCString(FS, "/).");
    }

    JB_Err_Fill(Err, self, JB_FS_GetResult(FS) ); 
    JB_Rec_NewItem(JB_StdErr, Err);

    return 0;
}

int JB_ErrorHandleC(const char* Desc, bool CanFreeDesc) {
    JB_Error* Err = JB_Err__New();
    JB_Err_Fill(Err, nil, FreeableStr_(Desc, CanFreeDesc)); 
    JB_Rec_NewItem(JB_StdErr, Err);
    return 0;
}


}


