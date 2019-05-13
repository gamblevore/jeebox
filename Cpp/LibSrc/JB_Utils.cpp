
// Copyright, Theodore H. Smith 2019.
// Released under jeebox-licence http://jeebox.org/licence.txt



#include "JB_Umbrella.h"
#include "JB_Log.h"


extern "C" {


/*
    maybe change the API so we have to "Breakdown" the allocation into separate things?
    strings/arrays/JB_MemoryWorlds?
*/

bool JB_IsDebug() {
#if DEBUG
    return true;
#else
    return false;
#endif
}

int JB_PointerSize() {
#ifdef ENV64BIT
    return 64;
#else
    return 32;
#endif
}


static bool TooLargeHappenedAlready;
bool JB_ErrorsPrinted;

//u64 JB_TotalMemoryCount() {
//    malloc_statistics_t stats;
//    malloc_zone_statistics(0, &stats);
//    // DebuggerAt(1);
//    return stats.size_in_use;
//}



void JB_TooLargeAlloc(const char* S, int N, int R) {
    if (!TooLargeHappenedAlready) {
        TooLargeHappenedAlready = true;
        printf("Not allowed to allocate %s over %i size, (%i requested).\n", S, R, N);
        JB_ErrorHandleC("Too large allocation requested", false);
    }
    debugger;
}




void* JB_zalloc(int N) {
    if (N > 0) {
        void* Result = calloc(1, N);
        if (Result) {
            return Result;
        }
        JB_OutOfMemory(N);
    }
    debugger;
    return 0;
}


void* JB_malloc(int N) {
    return JB_zalloc(N);
}


// Setting the size to zero actually DOES make sense, in terms of code... and reallocing zero
void* JB_realloc (const void* Arr, int N) {
    if (N > 0) {
        void* Result = realloc((void*)Arr, N);
        if (Result) { // Nothing has changed...
            return Result;
        }
        JB_OutOfMemory(N);
    } else {
        free((void*)Arr);
    }
    
    return 0;
}


u64 JB_msize(const void* M) {
#ifdef __linux__
    return malloc_usable_size((void*)M);
#else
    return malloc_size(M);
#endif
}


void JB_free(const void* Arr) {
    free((void*)Arr);
}



///   ///   ///   ///   ///   ///   ///   ///   ///   ///   ///   ///   ///   ///   ///   ///   ///   ///   ///   ///   ///   ///   ///   ///   ///   ///   ///   ///   ///   ///   ///   ///   ///   ///   ///   ///   


   
JB_String* JB_Platform() {
    static JB_String* Plat = 0;
    if (Plat) {
        return Plat;
    }
    
    #if defined(__i386__) && ( defined(__APPLE_CPP__) || defined(__APPLE_CC__) || defined(__APPLE__))
        Plat = JB_Str("osx");
    #endif
    
    #ifdef __unix__
        Plat = JB_Str("lin");
    #endif
    
    #ifdef __WIN32__
        Plat = JB_Str("win");
    #endif
    
    JB_Incr(Plat);
    return Plat;    
}



u8* JB_FastCString( JB_String* Path, u8* Tmp ) {
    u32 N = JB_Str_Length( Path );
    if ( ! N ) {
        return (u8*)"";
    }

	u8* Result = Path->Addr;
    if (JB_ObjClass(Path)==JB_AsClass(JB_StringC)) {
        return Result;
    }

    if (N > 1023) {
        N = 1023;
    }
	
    if (!Tmp) {
        debugger;
        return 0;
    }
    
    Tmp[ N ] = 0;
    return (u8*)CopyBytes( Result, Tmp, N );
}


u8* JB_FastFileString( JB_String* Path, u8* Tmp ) { // utf-16 on windows :(? Or do we just use posix funcs?
#ifdef TARGET_UNIX
    return JB_FastCString(Path, Tmp);
#else
	unsigned short* Result16 = (unsigned short*)Result;
    N = local_c8to16( Result, N, &BufferData );
    if ( ! N ) {
        return 0; // error
    }
    Result16 = (unsigned short*)BufferData.Addr;
    Result16[ N / 2 ] = 0;
    Result = (u8*)Result16;
	return Result;
#endif
}


u8* JB_BigCString( JB_String* Str, u8** ToFree ) {
    *ToFree = 0;
    u32 N = JB_Str_Length( Str );
    if ( ! N ) {
        return (u8*)"";
    }
    
    u8* Addr = JB_Str_Address(Str);
    if (JB_ObjClass(Str) == &JB_StringCData) {
        return Addr;
    }
    
    u8* Result = (u8*)JB_malloc(N+1);
    *ToFree = Result;
    if (Result) {
        Result[N] = 0;
        CopyBytes( Addr, Result, N );
    }
	return Result;
}


} // 



