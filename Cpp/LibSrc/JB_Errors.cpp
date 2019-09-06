
// Copyright, Theodore H. Smith 2019.
// Released under jeebox-licence http://jeebox.org/licence.txt


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
    JB_Error* Err = JB_Err__New(0);
    JB_Err_Fill(Err, FreeableStr_(Path, CanFreePath), FreeableStr_(Desc, CanFreeDesc)); 
    JB_Rec_NewItem(JB_StdErr, Err);
}




void JB_ErrorHandleFileC(const char* Path, int err, const char* Operation) {
    JB_ErrorHandleFile(JB_Str_FromCString_(Path), err, Operation);
}


static JB_String* Desc_(JB_String* self, int err, const char* Operation) {
    FastString* FS = JB_FS__FastNew(0);
    JB_FS_AppendIntegerAsText(FS, err, 1);
    JB_FS_AppendCString(FS, " (");
    JB_FS_AppendCString(FS, strerror(err));
    JB_FS_AppendCString(FS, ") occured trying to ");
    JB_FS_AppendCString(FS, Operation);
    JB_FS_AppendCString(FS, " file: '");
    JB_FS_AppendString(FS, self);
    JB_FS_AppendCString(FS, "'.");
    return JB_FS_GetResult(FS);
}

static JB_String* Path_(JB_String* self) {
    if (!self or JB_Str_ByteValue(self, 0)== '/') {
        return self;
    }
    FastString* FS = JB_FS__FastNew(0);
    char* cwd = getcwd( 0, 0 );
    JB_FS_AppendCString(FS, cwd);
    free( cwd );
    JB_FS_AppendByte(FS, '/');
    JB_FS_AppendString(FS, self);
    return JB_FS_GetResult(FS);
}

int JB_ErrorHandleFile(JB_String* self, int err, const char* op) {
    JB_Error* Err = JB_Err__New(0);
    if (!Err) {
        return -1;
    }
    JB_String* Desc = Desc_(self, err, op);
    JB_String* Path = Path_(self);
    JB_Err_Fill(Err, Path, Desc ); 
    JB_Rec_NewItem(JB_StdErr, Err);

    return 0;
}


int JB_ErrorHandleC(const char* Desc, bool CanFreeDesc) {
    JB_Error* Err = JB_Err__New(0);
    if (!Err) {
        return -1;
    }
    JB_Err_Fill(Err, nil, FreeableStr_(Desc, CanFreeDesc)); 
    JB_Rec_NewItem(JB_StdErr, Err);
    return 0;
}



void JB_Str_SyntaxExpect(JB_String* self);

void JB_OutOfUserMemory(int N) {
    static u8 ReportCount = 0;
    if (ReportCount < 50) {
        FastString* FS = JB_FS__FastNew(0);
        if (FS) {
            JB_FS_AppendCString(FS, "Jeebox: Can't allocate ");
            JB_FS_AppendIntegerAsText(FS, N, 0);
            JB_FS_AppendCString(FS, " bytes of memory.");
            JB_String* Str = JB_FS_GetResult(FS);
            if (JB_Str_Length(Str)) {
                ReportCount++;
                JB_Str_SyntaxExpect(Str);
            }
        }
    }
}


}

