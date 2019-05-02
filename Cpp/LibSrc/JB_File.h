

#ifndef __JB_FILE__
#define __JB_FILE__

#include "JB_Umbrella.h"

extern "C" {
    
    // remove the path? And just get it via..
    //        char filePath[PATH_MAX];
    //        (fcntl(fd, F_GETPATH, filePath); // ????
    // why? Well... what if the FileName changes? moved... etc. Perhaps a filedescriptor can keep track of it...
    // open( "./abc.txt" ) // now whats the filepath? best to remove path really...!
    // also... remove funcs ! the stat ones! statclass! or stat-datatype. class...

    // I think it's better! We only use the path for a few things...
    // * opening the file... (just open on the constructor then)
    // * Listing files (just list from a string then)
    // * doing stat (just give stat to a string then, might be better even.)

    // for listing files... I think we'd need a new class... but that's OK! Yeah a class of "dir"....
    // the thing is... the "stat" on a dir is the same as a stat... except we can just stat path
    // and that's all we can do... Perhaps dirs are what need... paths?
    
    // I think even "Stat" Should be it's own class... I mean... we are testing STAT anyhow, right?
    // so why not? Really... allocating stat via a class is OK. Remember SC has super-fast allocation!
    


JBClass( JB_File, JB_Object,
	int             FileDes;
	JB_String*		Path;
        // i love... myself.
        
    int*            Dir;
    int*            DirEnt;
);


JB_String* JB_File__FileData( JB_String* Path );
void ED_FS_AppendPathsRecursive( FastString* self, JB_String* EDPath, bool Prepend, long Sep );

JB_String* JB_File_CurrChild (JB_File* self);
long JB_File_Test( );
JB_String* JB_File_Render(JB_File* self, FastString* fs);
bool JB_File_MoveNext(JB_File* self);
bool JB_File_ListStart( JB_File* self );
JB_Object JB_File__File( JB_File* self );
void JB_FS_AppendRead(FastString* self, int fd);

JB_String* JB_Str_ResolvePath( JB_String* self );
int JB_Str_CopyFile(JB_String* self, JB_String* To);
int JB_File_Copy(JB_File* self, JB_File* To);
u8* FastShellPath_( JB_String* Path, u8* WriteTo );
int JB_File_Delete (JB_File* self);
u64 JB_File_Size( JB_File* self );
int JB_File_SizeSet( JB_File* self, IntPtr N );
void JB_File_Flush( JB_File* self );
bool JB_File_EOF( JB_File* self );
JB_String* JB_File_ReadAll( JB_File* self, bool Ignore );
JB_String* JB_File_PathFix_(JB_String* S);
bool JB_File_IsDir (JB_File* self);
int JB_Str_MakeDir(JB_String* self);
JB_String* JB_File_Read(JB_File* self, IntPtr Length, bool Ignore);
JB_String* JB_File_ReadFD( int* FD, int Length, JB_String* Path );
void JB_File_DataSet( JB_File* self, JB_String* Data );
JB_String* JB_Str_FileData( JB_String* Path, bool Ignore );
JB_File* JB_Str_File( JB_String* Path );
JB_File* JB_File__StdOut( );
int JB_File_MoveTo(JB_File* self, JB_String* New);

bool JB_File_Exists( JB_File* self );
Date JB_File_Modified( JB_File* self );
Date JB_File_Created( JB_File* self );
JB_String* JB_cPath_ReadAll (const char* path, bool AllowMissingFile, int MaxFile);

long JB_File__chdir( JB_String* Path );
JB_String* JB_File__CWD( );
long JB_File_Remaining( JB_File* self );
int JB_File_Write( JB_File* self, JB_String* Data );
s64 JB_File_WriteRaw_( JB_File* self, u8* Data, int N );
int JB_File_WriteCompressed_( JB_File* self, JB_String* str );

int JB_File_OpenBlank( JB_File* self );
int JB_File_Open(JB_File* self, int OpenFlags, bool ignore);
int JB_Str_Open(JB_String* Path, int Flags, bool Ignore);
void ErrorHandleSub_(JB_String* self, const char* Operation);
void JB_File_Constructor(JB_File* self, JB_String* Path);
void JB_File_OffsetSet( JB_File* self, s64 NewValue );
s64 JB_File_Offset( JB_File* self );
s64 JB_File_Size_( int FileDes );

void JB_File_Destructor( JB_File* self );
void JB_File_Close( JB_File* self );



}

#endif

