
/* 
	By Theodore H. Smith, 2019, theo@jeebox.org
	This software is provided 'as-is', without any warranty.
	In no event will the authors be held liable for any damages
	arising from the use of this software.

	Permission is granted to anyone to use this software for any purpose,
	including commercially, and to alter it and redistribute it
	freely, subject to the following restrictions:

	1. The origin of this software must not be misrepresented; you must not
		claim that you wrote the original software.
    2. If you use this software or portions of this software in a product, you
        are required to acknowledge this in one of:
        About-window / launch-screen / help-files / read-me-file
	3. Altered source versions must be plainly marked as such, and must not be
		misrepresented as being the original software.
	4. This notice may not be removed or altered from any source distribution.

    Non-licence personal-note:
    Sorry about asking for acknowledgement of using Jeebox, but I have no career at all.
    I don't think it's too much to ask that someone with a career gives a chance
    to someone with none.
*/



#include "JB_Umbrella.h"
#include <stdio.h>
#include <errno.h>
#include <sys/stat.h>


extern "C" {
void JB_ErrorHandleFileC(u8* Path, int err, const char* Operation);
static JB_String* errr(const char* path, const char* op) {
    JB_ErrorHandleFileC((u8*)path, errno, op);
    return 0;
}
    

static int GetFileSize(const char* filename) {
    struct stat stat_buf;
    int rc = stat(filename, &stat_buf);
    return rc == 0 ? (int)stat_buf.st_size : -1;
}


JB_String* JB_cPath_ReadAll (const char* path, bool AllowMissingFile, int MaxFile) {
    FILE* fp = fopen(path, "rb");
    if (!fp) {
        if (AllowMissingFile and errno == ENOENT) {
            return JB_Str_Empty();
        }
        return errr(path, "open");
    }

    JB_String* Result = 0;
    int N = GetFileSize(path);
    if (N < 0) {
        errr(path, "open");
    } else {
        Result = JB_Str_New(N);
        if (!Result) {
            errr(path, "allocate memory");
        } else {
            int Size = fread(JB_Str_Address(Result), 1, N, fp);
            if (ferror(fp)) {
                errr(path, "read");
                JB_Delete((FreeObject*)Result); Result = 0;
            } else {
                Result = JB_Str_Realloc(&Result, Size);
            }
        }
    }
    
    fclose(fp);
    return Result;
}


}


