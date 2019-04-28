

#ifndef __JB_PIPE__
#define __JB_PIPE__

#include "JB_Umbrella.h"

extern "C" {

JBClass( JB_Pipe, JB_Object,
        void*           File;
        );


JB_Pipe* JB_Pipe_ReadNew( JB_String* S );
JB_Pipe* JB_Pipe_ReadWriteNew( JB_String* S );
JB_String* JB_Pipe_Read( JB_Pipe* self, FastString* FS );
void JB_Pipe_Write( JB_Pipe* self, JB_String* Data );
void JB_Pipe_Destructor( JB_Pipe* self );
void JB_Pipe_Constructor (JB_Pipe* self);
int JB_Pipe_Close( JB_Pipe* self );
JB_String* JB_Str_Execute(JB_String* self, Array* R);
int JB_Str_System(JB_String* self);
bool JB_IsTerminal(int FD);
void JB_PrintStackTrace();
void JB_Pipe__InstallStackTrace();
void JB_Pipe__StdErrorSet(int F);
void JB_Pipe__StdOutSet(int F);
    
}

#endif

