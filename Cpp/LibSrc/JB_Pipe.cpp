
// Copyright, Theodore H. Smith 2019.
// Released under jeebox-licence http://jeebox.org/licence.txt


#include "JB_Umbrella.h"
#include "JB_Log.h"
#include <stdio.h>

#ifndef AS_LIBRARY
#include <unistd.h>
#include <syslog.h>
#include <execinfo.h>
#include <signal.h>

extern "C" {
void JB_PrintStackTrace() {
    void* array[32];
    int   size      = backtrace( array, 32 );
    char  **strings = backtrace_symbols( array, size );

    for (int i = 0; i < size; i++) {
        puts( strings[i] );
    }
    
    puts("");

    // free( strings ); why free if we just exit?
}

static void PrintStackTraceAndExit_(int Signal) {
    printf( "error: unhandled signal %i\n", Signal);
    JB_PrintStackTrace();
    exit(-1);
}


void JB_Pipe__InstallStackTrace() {
    #if DEBUG
    #else
        signal(SIGSEGV, PrintStackTraceAndExit_);   // install our handler
    #endif
}


JB_Pipe* JB_Pipe_New_( JB_String* S, const char* Mode ) {
    JB_Pipe* P = JB_New(JB_Pipe);
    u8 Buffer[1024];
    P->File = popen( (char*) JB_FastCString( S, Buffer ), Mode);
    return P;
}


JB_Pipe* JB_Pipe_ReadNew( JB_String* S ) {
    return JB_Pipe_New_( S, "r" );
}


JB_Pipe* JB_Pipe_ReadWriteNew( JB_String* S ) {
    return JB_Pipe_New_( S, "w" );
}


JB_String* JB_Pipe_Read( JB_Pipe* self, FastString* FSIn  ) {
    FastString* FS = JB_FS__FastNew(FSIn);
    FILE* F = (FILE*)(self->File);
    char Buffer[1024];
    
    while( fgets(Buffer, sizeof(Buffer), F) ) {
        JB_FS_AppendCString(FS, Buffer);
    }

    return JB_FS_SmartResult(FS, FSIn);
}


void JB_Pipe_Write( JB_Pipe* self, JB_String* Data ) {
    if ( self->File ) {
        fwrite(Data->Addr, Data->Length, 1, (FILE*)(self->File));
    }
}


void JB_Pipe_Destructor( JB_Pipe* self ) {
    JB_Pipe_Close(self);
}


int JB_Pipe_Close( JB_Pipe* self ) {
    if (self->File) {
        int Result = pclose((FILE*)(self->File));
        self->File = 0;
        return Result;
    }
    return -1;
}


int JB_ForkExecPipeDup_IHateUnix(char* Args[], FastString* Out, FastString* Err) {
    const int R = 0;
    const int W = 1;
    int StdOutPipe[2];
    int StdErrPipe[2];
    
    pipe(StdOutPipe);
    pipe(StdErrPipe);
    
    int F = fork();
    if (F == -1) {
        return -101010101;
    }

    if (F == 0) {
        dup2( StdOutPipe[W], STDOUT_FILENO );
        dup2( StdErrPipe[W], STDERR_FILENO );
        
        // We dupped them already. Don't let exec process know they existed.
        close(StdOutPipe[R]);
        close(StdOutPipe[W]);
        close(StdErrPipe[R]);
        close(StdErrPipe[W]);
        
        execv(Args[0], Args);
        _exit(-1);
        return 0; // never come here
        
    } else {
        close(StdOutPipe[W]);
        close(StdErrPipe[W]);
        JB_FS_AppendRead(Out, StdOutPipe[R]);
        JB_FS_AppendRead(Err, StdErrPipe[R]);
        int Status;
        waitpid(F, &Status, 0);
        close(StdOutPipe[R]);
        close(StdErrPipe[R]);
        return Status;
    }
}


int JB_Str_System(JB_String* self) {
// same as JB_Str_Execute, but simpler... :/
// but we don't get a string back, and we need to escape params manually...
    u8 Buffer[1024];
    u8* Result = JB_FastCString(self, Buffer);
    return system((const char*)Result);
}


JB_String* JB_Str_Execute(JB_String* self, Array* R) {
    const int MaxArgs = 1000;
    char* argv[MaxArgs + 1]; // 0-terminate
    char** CurrArgv = argv;
    u8 PBuffer[1024];

    *CurrArgv++ = (char*)JB_FastCString(self, PBuffer);
    char Buffer[1024*128];
    char* CurrBuffer = Buffer;

    
    JB_String** R_ = (JB_String**)(R->ArrData);
    int N = JB_Array_Size(R);
    if (N > MaxArgs) {
        return nil;
    }

    for (int i = 0; i < N; i++) {
        int RN = JB_Str_Length(R_[i]);
        if (CurrBuffer + RN > Buffer + sizeof(Buffer)) {
            return nil;
        }
        char* Addr = (char*)JB_Str_Address(R_[i]);
        memcpy(CurrBuffer, Addr, RN);
        *CurrArgv++ = CurrBuffer;
        CurrBuffer += RN;
        *CurrBuffer++ = 0;
    }
    *CurrArgv++ = 0;
    
    FastString* FSOut = JB_FS__InternalNew();
    FastString* FSErr = JB_FS__InternalNew();
    int Err = JB_ForkExecPipeDup_IHateUnix(argv, FSOut, FSErr);
    JB_String* Result = JB_FS_GetResult(FSOut);
    JB_String* ErrString = JB_FS_GetResult(FSErr);
    if (JB_Str_Length(ErrString)) {
        JB_Rec_NewItemWithNode(JB_StdErr, nil, ErrString);

    } else if (Err) {
        JB_Rec_NewItemWithNode(JB_StdErr, nil, JB_Str_Empty());
    }

    JB_FreeIfDead(FSOut);
    JB_FreeIfDead(FSErr);
    return Result;
}


bool JB_IsTerminal(int FD) {
    return isatty(FD);
}

}

#endif


