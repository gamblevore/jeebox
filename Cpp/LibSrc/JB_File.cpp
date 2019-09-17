
// Copyright, Theodore H. Smith 2019.
// Released under jeebox-licence http://jeebox.org/licence.txt

#ifndef AS_LIBRARY

#include "JB_Umbrella.h"
#include <time.h>
#include <stdlib.h>
#include <sys/mman.h>


// The design of the system... is "errors are soft"
// That means... not being pedantic. If we try to delete a file that doesn't exist who cares?
// I want to keep this "in sync" with my existing system...
// especially for strings... where nil.length = 0

#ifdef TARGET_WIN32
    #include "JB_DirReaderWin32.h"
#else
    #include "JB_DirReaderUnix.h"
#endif



#if defined(TARGET_WIN32)
extern "C" {
	#define fsync _commit

	#ifndef S_IRWXU
		#define O_Win32Sucks   0x8000  /* really this is O_BINARY. */
		#define O_RDONLY       0x0000  /* open for reading only */
		#define O_WRONLY       0x0001  /* open for writing only */
		#define O_RDWR         0x0002  /* open for reading and writing */
		#define O_APPEND       0x0008  /* writes done at eof */

		#define O_CREAT        0x0100  /* create and open file */
		#define O_TRUNC        0x0200  /* open and truncate */
		#define O_EXCL         0x0400  /* open only if file doesn't already exist */

		#define	S_IRWXU	0x0E00		/* Permissions for file owner class */
		#define 	S_IRUSR 0x0800	/* Read permission file owner class */
		#define 	S_IWUSR 0x0400	/* writ permission file owner class */
		#define 	S_IXUSR 0x0200	/* exec permission file owner class */
		#define S_IRWXG 0x01C0		/* permissions for file group class */
		#define 	S_IRGRP 0x0100	/* Read permission file group class */
		#define 	S_IWGRP 0x0080	/* writ permission file group class */
		#define 	S_IXGRP 0x0040	/* exec permission file group class */
		#define S_IRWXO 0x0038		/* permissions for file other class */
		#define 	S_IROTH 0x0020	/* Read permission file other class */
		#define 	S_IWOTH 0x0010	/* writ permission file other class */
		#define 	S_IXOTH 0x0008	/* exec permission file other class */
	#endif

#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>
	
	
	#define close( a ) _close( a ) 
	#define lseek( a, b, c ) _lseek( a, b, c ) 
	#define read( a, b, c ) _read( a, b, c ) 
	#define write( a, b, c ) _write( a, b, c ) 
	#define getcwd( a, b ) _wgetcwd( a, b ) 
	#define chdir( a ) _wchdir( a ) 
	#define open( a, b, c ) _wopen( a, b, c ) 
	#define fstat( a, b ) _fstat( a, b )
	#define stat( a, b ) _wstat( a, b ) 
	int __cdecl 		_commit(int);
	int __cdecl 		_wopen(const unsigned short*, int, int);
	int __cdecl 		_wstat(const unsigned short*, struct _stat*);
	int __cdecl 		_wchdir(const unsigned short*);
	int __stdcall 		GetCurrentDirectoryW(int Length, unsigned short* Buffer);
	u32 __stdcall 		GetLongPathNameW(unsigned short* A, unsigned short* B, int Length);

	#define trchdir chdir

	int* __cdecl 		_errno();

// __declspec(dllimport)
	#define errno (*_errno())
}
#else
	#define O_Win32Sucks   0
	#define _stat stat


	#ifndef S_IRWXU

		#define	S_IRWXU		0000700		/* [XSI] RWX mask for owner */
		#define	S_IRUSR		0000400		/* [XSI] R for owner */
		#define	S_IWUSR		0000200		/* [XSI] W for owner */
		#define	S_IXUSR		0000100		/* [XSI] X for owner */
		/* Read, write, execute/search by group */
		#define	S_IRWXG		0000070		/* [XSI] RWX mask for group */
		#define	S_IRGRP		0000040		/* [XSI] R for group */
		#define	S_IWGRP		0000020		/* [XSI] W for group */
		#define	S_IXGRP		0000010		/* [XSI] X for group */
		/* Read, write, execute/search by others */
		#define	S_IRWXO		0000007		/* [XSI] RWX mask for other */
		#define	S_IROTH		0000004		/* [XSI] R for other */
		#define	S_IWOTH		0000002		/* [XSI] W for other */
		#define	S_IXOTH		0000001		/* [XSI] X for other */

		#define	S_ISUID		0004000		/* [XSI] set user id on execution */
		#define	S_ISGID		0002000		/* [XSI] set group id on execution */
		#define	S_ISVTX		0001000		/* [XSI] directory restrcted delete */

	#endif
#endif


#define kDefaultMode (S_IRWXU | S_IRGRP | S_IXGRP | S_IROTH | S_IXOTH)

extern "C" {
void JB_ErrorHandleFileC(const char* Path, int err, const char* Operation);

bool HasFD (JB_File*f) {
    return (f->FileDes >= 0);
}

int64 ErrorHandleStr_(int64 MaybeErr, JB_String* self, const char* Operation) {
    if (MaybeErr >= 0) {
        return MaybeErr;
    }
    JB_ErrorHandleFile(self, errno, Operation);
    return 0;
}

int64 ErrorHandle_(int64 MaybeErr, JB_File* self, const char* Operation) {
    return ErrorHandleStr_(MaybeErr, self->Path, Operation);
}


int StrOpen_(JB_String* Path, int Flags, bool IgnoreDoesntExist) {
    u8 Buffer[1024];
    NativeFileChar2* CPath = (NativeFileChar2*)JB_FastFileString( Path, Buffer );
    int FD = open( CPath,  O_Win32Sucks | Flags,  kDefaultMode );
    if (FD >= 0) {
        if (!FD) {debugger;} // why would we get 0 back? Who knows? That would mean we just opened stdin... ... ok?
        return FD;
    }
    
    if ((errno == ENOENT) and IgnoreDoesntExist) {
        // ignore it...
    } else {
        JB_ErrorHandleFile(Path, errno, "open");
    }
    return -1;
}


bool Stat_( JB_File* f, struct _stat* st ) {
    int err = 0;
    if (!f) {
        debugger;
        return false;
    } else if ( HasFD(f) ) {
        err = fstat( f->FileDes, st );
    } else {
        u8 Buffer[1024];
        NativeFileChar2* tmp = (NativeFileChar2*)JB_FastFileString( f->Path, Buffer );
        err = stat( tmp, st );
    }

    if (err == -1) {
        if (errno != ENOENT) {
            ErrorHandleStr_(err, f->Path, "get info on");
        }
        return false;
    }
    return true;
}


JB_File TmpFile_(JB_String* self) {
    JB_File F = {};
    F.Path = self; F.FileDes = -1;
    return F;
}

int JB_Str_FileSize(JB_String* self) {
    JB_File F = TmpFile_(self);
    struct _stat st;
    if (Stat_(&F, &st)) {
        return (int)(st.st_size);
    }
    return 0;
}


JB_String* JB_Str_FileData(JB_String* self, bool IgnoreDoesntExist) {
    JB_File F = TmpFile_(self);
    JB_String* Result = JB_File_ReadAll(&F, IgnoreDoesntExist);
    JB_File_Close(&F); // no allocation. Nice.
    return Result;
}



int JB_File_Open( JB_File* f, int OpenFlags, bool IgnoreDoesntExist ) {
    if (!HasFD(f)) {
        f->FileDes = StrOpen_(f->Path, OpenFlags, IgnoreDoesntExist);
    }
    return f->FileDes;
}


int InterWrite(int fd, u8* buffer, int N) {
    int TotalCount = 0;
    while (N > TotalCount) {
        int written = (int)write(fd, buffer+TotalCount, N-TotalCount);
        if (written == -1) {
            if (errno == EINTR) continue;
            return -1;
        }
        TotalCount += written;
    }
    return TotalCount;
}


int InterRead(int fd, void* buffer, int N, JB_String* Path) {
    // EINTR can happen during a read... this just means the read was interupted...
    // and should be tried again. I think?
    int Attempts = 0;
    while (Attempts++ < 1024) {
        int Result = (int)read(fd, buffer, N);
        if (Result >= 0 or errno != EINTR) {
            return Result;
        }
    }
    
    if (!Path and isatty(fd)) {
        JB_ErrorHandleFileC(ttyname(fd), errno, "read");
    } else {
        ErrorHandleStr_( -1, Path, "read" );
    }
    return -1;
}




void JB_FS_AppendRead(FastString* self, int fd) {
    // so.... just allocate?
    const int ReadLength = 64 * 1024;
    int Count = 0;
    while (true) {
        u8* Buffer = JB_FS_WriteAlloc_(self, ReadLength);
        if (!Buffer) {
            break;
        }
        
        int N = InterRead(fd, Buffer, ReadLength, 0);
        if (N < 0) {
            N = 0;
        }
        JB_FS_AdjustLength_(self, ReadLength, N);
        if (!N) { break; }
    }
}


JB_String* JB_File_ReadAll( JB_File* self, bool IgnoreDoesntExist ) {
    u64 Size = JB_File_Size( self );
    if (Size > 2000*1024*1024) {
        return 0;
    }
    JB_String* Result = JB_File_Read( self, (int)Size, IgnoreDoesntExist );
    JB_File_Close(self);
    return Result;
}


JB_String* JB_Str_ResolvePath( JB_String* self, bool Err ) {
     char* realpath(const char* file_name, char* resolved_name);
     u8 Tmp[1024];
     
     JB_String* UserPath = JB_File_PathFix_(self);
     u8* Path = JB_FastFileString(UserPath, Tmp);
     JB_String* Result = 0;
     if (Path) {
         char* Resolved = realpath((const char*)Path, 0);
         if (Resolved) {
             // cool... a string.
             Result = JB_Str_FromCString_( Resolved );
         } else if (Err) {
            JB_ErrorHandleFile(self, errno, "resolve path for");
         }
     }
     if (UserPath!=self) {
        JB_FreeIfDead(UserPath);
     }
     
     return Result;
}


int _NSGetExecutablePath(char* buf, u32* length); // oh apple...
JB_String* JB_App__Path() {
    static JB_String* Result;
    if (!Result) {
        u32 N = 0;
        _NSGetExecutablePath(0, &N);
        JB_String* Tmp = JB_Str_New(N);
        _NSGetExecutablePath((char*)(Tmp->Addr), &N);
        Result = JB_Str_ResolvePath(Tmp, true);
        JB_Decr(Tmp);
        JB_Incr(Result);
    }
    return Result;
}


JB_String* JB_File_Read( JB_File* self, IntPtr Length, bool IgnoreDoesntExist ) {
    if (Length > kMaxint or Length < 0) {
        return 0;
    }
    int FD = JB_File_Open( self, O_RDONLY, IgnoreDoesntExist );
    if (!HasFD(self)) {
        return 0;
    }

    JB_String* Str = JB_Str_New( (int)Length );
    if (Str) {
        int N = InterRead( FD, Str->Addr, (int)Length, self->Path );
        if (N <= 0) {
            JB_FreeIfDead(Str);
            return JB_Str_Empty();
        }
        if (N < Length) {
            JB_Incr(Str);
            JB_Str_Realloc( &Str, N );
            JB_SafeDecr(Str);
        }
    }

    return Str;
}



bool JB_File_EOF( JB_File* self ) {
    if (HasFD(self)) {
        off_t Cur = JB_File_Offset(self);
        if (Cur >= 0) {
            off_t End = lseek( self->FileDes, 0, SEEK_END );
            ErrorHandle_((int)End, self, "find length of");
            return Cur == End;
        }
    }
    return true;
}


int64 JB_File_WriteRaw_( JB_File* self, u8* Data, int N ) {
    N = InterWrite( self->FileDes, Data, N );
    return ErrorHandle_(N, self, "write to");
}


int JB_File_Write( JB_File* self, JB_String* Data ) {
    if ( Data and HasFD(self) ) {
        return (int)JB_File_WriteRaw_(self, Data->Addr, Data->Length );
    }
    return -1;
}
    

void JB_File_Flush(JB_File* self) {
    if ( HasFD(self) ) {
        ErrorHandle_( fsync( self->FileDes ), self, "flush" );
    }
}


bool JB_File_OpenBlank( JB_File* self ) {
	return JB_File_Open( self, O_RDWR | O_CREAT | O_TRUNC, false ) >= 0;
}


int JB_Str_MakeDir(JB_String* self) {
    u8 Buffer[1024];
    NativeFileChar2* tmp = (NativeFileChar2*)JB_FastFileString( self, Buffer );
    int err = mkdir(tmp, kDefaultMode);
    if (err == -1 and errno == EEXIST) {
        return 0; // ignore. really. I don't need this.
    }
    return (int)ErrorHandleStr_(err, self, "makedir");
}


int JB_File_Delete (JB_File* self) {
    u8 Buffer[1024];
    NativeFileChar2* tmp = (NativeFileChar2*)JB_FastFileString( self->Path, Buffer );
    int err = remove( tmp );
    if (err == -1 and errno == ENOENT) {
        return 0;
    }
    return (int)ErrorHandle_(err, self, "delete");
    // handle error
}

    
JB_String* JB_File_PathFix_(JB_String* S) {
    if (JB_Str_ByteValue(S, 0) == '~') {
        JB_String* Home = JB_Str_FromCString_(getenv("HOME"));
        JB_String* Rest = JB_Str_Range(S, 1, -1);
        JB_String* Result = JB_Str_OperatorPlus(Home, Rest);
        JB_FreeIfDead(Home);
        JB_FreeIfDead(Rest);
        return Result;
    }
    return S;
}


void JB_File_Constructor( JB_File* self, JB_String* Path ) {
	self->Path = JB_File_PathFix_(Path);
    JB_Incr(self->Path);
    self->FileDes = -1;
    self->Dir = 0;
    self->DirEnt = 0;
}

JB_String* JB_File_Render(JB_File* self, FastString* fs_in) {
    if (fs_in) {
        JB_FS_AppendString(fs_in, self->Path);
        return 0;
    } else {
        return self->Path;
    }
}
    
void JB_File_Destructor( JB_File* self ) {
    JB_File_Close( self );
	JB_ClearRef( self->Path );
    if (self->Dir) {
        int** I = (&self->Dir);
        DirReader* D = (DirReader*)I;
        CloseDir_(D);
        self->Dir = 0;
    }
    self->DirEnt = 0;
}


void JB_File_Close( JB_File* self ) {
    require0 ( HasFD(self) );
    if (self->FileDes <= 2) {
        debugger; // Happens via stdin.readall? sigh. Can’t reopen stdin either.
        return;     // Let's not close it then.
    }
    int N = close( self->FileDes );
    ErrorHandleStr_(N, self->Path, "close");
    self->FileDes = -1;
}


void JB_File_OffsetSet( JB_File* self, int64 NewValue ) {
    // no need to check for -1 FileDes if lseek handles it?
    ErrorHandle_(
        (int)lseek( self->FileDes, NewValue, SEEK_SET ),
        self, "set offset of");
}

int64 JB_File_Offset( JB_File* self ) {
    // no need to check for -1 FileDes if lseek handles it?
    int64 N = lseek( self->FileDes, 0, SEEK_CUR );
    ErrorHandle_(N, self, "get offset of");
    return N;
}



int JB_File_SizeSet( JB_File* self, IntPtr N ) {
    int err = ftruncate(self->FileDes, N);
    ErrorHandle_(err, self, "set size of");
    return err;
}


long JB_File_Test( ) {
    debugger;
	struct _stat st;
    int err = fstat( 0, &st );
    if (err == -1) {
        ErrorHandleStr_(err, 0, "get info on stdin");
        return 0;
    }
    return (int)st.st_size;
}


u64 JB_File_Size( JB_File* self ) {
	struct _stat st;
    if (Stat_(self, &st)) {
        return (u64)st.st_size;
    }
	return 0;
}

    
Date JB_File_Modified( JB_File* self ) {
    struct _stat st;
    if (Stat_(self, &st)) {
        return JB_Date__SpecToDate(&st.st_mtimespec);
    }
    return 0;
}


Date JB_File_Created( JB_File* self ) {
    struct _stat st;
    if (Stat_(self, &st)) {
        return JB_Date__SpecToDate(&st.st_ctimespec);
    }
    return 0;
}


bool JB_File_Exists( JB_File* self ) {
        u8 Buffer[1024];
    if (self) {
        return (access((const char*)JB_FastFileString(self->Path, Buffer), 0) >= 0);
    }
	return false;
}


void CopyFileSub_(int in_, int out_, JB_String* Path) {
    u8 buf[64 * 1024];
    int N = 0;
    while ((N = InterRead(in_, buf, sizeof(buf), Path)) > 0) {
        if (InterWrite(out_, buf, N) == -1) {
            return;
        }
    }
}


int JB_Str_CopyFile(JB_String* self, JB_String* To) {
    u8 Buffer1[1024];
    u8 Buffer2[1024];
    u8* SelfPath = JB_FastFileString(self, Buffer1);
    u8* ToPath   = JB_FastFileString(To, Buffer2);
    // so firstly... what do I do about the... filedes?
    // basically it shouldn't affect anything...
    // I guess we just open it, again!
    
    int in_ = open((const char*)SelfPath, O_RDONLY);
    if (ErrorHandleStr_(in_, self, "copy")) {
        struct _stat st;
        if (fstat( in_, &st ) == 0) {
        
            if (S_ISDIR(st.st_mode) ) {
                ErrorHandleStr_(EISDIR, To, "copy");// we are copying a folder?? can’t do that!
            } else {
                int out_ = open((const char*)ToPath, O_CREAT | O_WRONLY | O_TRUNC, st.st_mode);
                if (ErrorHandleStr_(out_, To, "copy")) {
                    CopyFileSub_(in_, out_, self);
                    close(out_);
                }
            }
        }
        close(in_);
    }

    return 0;
}


    
int JB_File_MoveTo(JB_File* self, JB_String* New) {
    u8 Buffer1[1024];
    u8 Buffer2[1024];
    u8* SelfPath = JB_FastFileString(self->Path, Buffer1);
    u8* NewPath  = JB_FastFileString(New, Buffer2);
    int Err = rename((const char*)SelfPath, (const char*)NewPath);
    ErrorHandle_(Err, self, "move");
    if (!Err) {
        JB_SetRef(self->Path, New);
    }
    return Err;
}



int JB_File_Copy(JB_File* self, JB_File* To) {
    return JB_Str_CopyFile(self->Path, To->Path);
}




#ifdef TARGET_UNIX
	JB_String* JB_File__CWD( ) {
		char* path = getcwd( 0, 0 );
		IntPtr N = strlen( path );
		while ( path[N-1] == '/' ) { // linux is different than Mac :(
			N = N - 1;
		}
        
        JB_String* Result = JB_Str_CopyFromPtr( (u8*)path, (int)N );
		free( path );
		return Result;
	}


#else
/*
	JB_String* JB_File__CWD( ) {
		u32 Length = GetCurrentDirectoryW( 0, 0 ); // includes 0 terminator.
		JB_String* Result = Str_New( Length*2, kEncUTF16 );
		if ( ! Result ) return 0;

		Length = GetCurrentDirectoryW( Length, (u16*)ElfData_Address(Result) ); // excludes 0 terminator. I know, windows is stupid.
		Result = ShrinkInPlace_( Result, Length*2 );
		return Result;
	}
*/
#endif



void JB_File_DataSet( JB_File* self, JB_String* Data ) {
    JB_File_Open(self, O_RDWR | O_CREAT | O_TRUNC, false);
	if (HasFD(self)) {
		JB_File_SizeSet(self, 0);
        JB_File_Write(self, Data);
        JB_File_Close(self);
	}
}

JB_File* JB_Str_File( JB_String* Path ) {
    JB_File* F = JB_New( JB_File );
    JB_File_Constructor( F, Path );
    return F;
}


long JB_File__chdir( JB_String* Path ) {
    u8 Buffer1[1024];
	return trchdir( (NativeFileChar2*)JB_FastFileString( Path, Buffer1 ) );
}
    
bool JB_File_MoveNext(JB_File* self) {
    int** I = (&self->Dir);
    DirReader* D = (DirReader*)I;
    self->DirEnt = (int*)ReadDir_(D);
    return self->DirEnt;
}

bool JB_File_ListStart (JB_File* self) {
    int** I = (&self->Dir);
    DirReader* D = (DirReader*)I;
    self->DirEnt = 0; // in case already set?
    u8 Buffer1[1024];
    return InitOpenDir_( D, (const char*)JB_FastFileString(self->Path, Buffer1) );
}

 
JB_String* JB_File_CurrChild (JB_File* self) {
    dirent* Child = (dirent*)self->DirEnt;
    if (!Child) {
        return 0;
    }
    
    const char* ChildName = Child->d_name;
#ifdef TARGET_API_MAC_OS
    u32 NameLength = Child->d_namlen;
    if ( ! NameLength ) NameLength = strlen( ChildName );
#else
    u32 NameLength = (u32)strlen( ChildName );
#endif

    return JB_Str_CopyFromPtr( (u8*)ChildName, (int)NameLength );
}


bool JB_File_IsDir (JB_File* self) {
    struct stat st;
    if (Stat_(self, &st)) {
        return ( S_ISDIR(st.st_mode) );
    }
    return false;
}


}

#else 

#endif


    

