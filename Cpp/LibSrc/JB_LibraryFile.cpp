
// Copyright, Theodore H. Smith 2019.
// Released under jeebox-licence http://jeebox.org/licence.txt

#include "JB_Umbrella.h"
#include <stdio.h>
#include <errno.h>
#include <sys/stat.h>


extern "C" {
void JB_ErrorHandleFileC(u8* Path, int err, const char* Operation);
static JB_String* jb_lib_file_err(const char* path, const char* op) {
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
        return jb_lib_file_err(path, "open");
    }

    JB_String* Result = 0;
    int N = GetFileSize(path);
    if (N < 0) {
        jb_lib_file_err(path, "open");
    } else {
        Result = JB_Str_New(N+1);
        if (!Result) {
            jb_lib_file_err(path, "allocate memory for");
        } else {
            int Size = (int)fread(JB_Str_Address(Result), 1, N, fp);
            if (ferror(fp)) {
                jb_lib_file_err(path, "read");
                JB_Delete((FreeObject*)Result); Result = 0;
            } else {
                Result = JB_Str_Realloc(&Result, Size+1);
                Result->Addr[Size] = 0; // make life easier for c-folks.
                Result->Length--; // not actual length, though.
            }
        }
    }
    
    fclose(fp);
    return Result;
}


}


