
#include <stdlib.h>
#include <stdio.h>

// need to include std headers first, as some use these words "u32", "u16" :(

#ifndef __JB_TYPES__
#define __JB_TYPES__

#ifndef _cstring
    typedef const char*         _cstring;
#endif
#ifndef _voidptr
    typedef void*               _voidptr;
#endif

#ifndef u64
    typedef unsigned long long  u64; 
#endif
#ifndef uint64
    typedef unsigned long long  uint64; 
#endif
#ifndef s64
    typedef long long           s64; 
#endif
#ifndef int64
    typedef long long           int64; 
#endif

#ifndef u32
    typedef unsigned int        u32;
#endif
#ifndef uint
    typedef unsigned int        uint;
#endif
#ifndef Fixed32
    typedef unsigned int        Fixed32;
#endif

#ifndef s16
    typedef short               s16; 
#endif
#ifndef u16
    typedef unsigned short      u16; 
#endif

#ifndef u8
    typedef unsigned char       u8;
#endif
#ifndef s8
    typedef char                s8;
#endif



#if _WIN32 || _WIN64
    #if _WIN64
        #define ENVIRONMENT64
    #else
        #define ENVIRONMENT32
    #endif
#endif

// Check GCC
#if __GNUC__
    #if __x86_64__ || __ppc64__
        #define ENVIRONMENT64
    #else
        #define ENVIRONMENT32
    #endif
#endif

#ifdef ENVIRONMENT64
    typedef long long int IntPtr;
    typedef unsigned long long int UintPtr;
#else
    typedef int IntPtr;
    typedef unsigned int UintPtr;
#endif


// nice simple time system... gives us almost 9 million years and a decent (64 thousand ticks per second) precision...
#define kTicksPerSecond (2^16)
typedef int64 Date;

typedef unsigned char byte;
typedef u32 CodePoint;

#define nil 0

#ifdef TARGET_WIN32
	#define NativeFileChar u16
	#define NativeFileChar2 u16
	#define NFS_ L
#else
	#define NativeFileChar u8
	#define NativeFileChar2 s8
	#define NFS_ 
#endif



struct S24_8 {
    int Data;
    int S8() {
        return Data & 0xFF;
    };
    int S24() {
        return Data >> 8;
    };
    void SetS8(int V) {
        Data = (Data &~ 0xFF) | V;
    };
    void SetS24(int V) {
        Data = (Data & 0xFF) | (V << 8);
    };
};




#ifndef kPlatformEndian
	#define kPlatformEndian 0
#endif

#if kPlatformEndian == 0
    #define kWrongUTF16			/*Becomes*/		(16+1)
	#define kUTF16BBOM			/*Becomes*/		0xFFFE
	#define kUTF16LBOM			/*Becomes*/		0xFEFF
	#define kUTF32LBOM			/*Becomes*/		0x0000FEFF
	#define kUTF32BBOM			/*Becomes*/		0xFFFE0000
#elif kPlatformEndian == 1
    #define kWrongUTF16			/*Becomes*/		(16)
	#define kUTF16BBOM			/*Becomes*/		0xFEFF
	#define kUTF16LBOM			/*Becomes*/		0xFFFE
	#define kUTF32LBOM			/*Becomes*/		0xFFFE0000
	#define kUTF32BBOM			/*Becomes*/		0x0000FEFF
#endif


#define kUTF8BOM			/*Becomes*/		0xEFBBBF
#define kUTF8BOM1			/*Becomes*/		0xEF
#define kUTF8BOM2			/*Becomes*/		0xBB
#define kUTF8BOM3			/*Becomes*/		0xBF
#define kLast3ByteMask		/*Becomes*/		0xFFFFFF00
#define kUTF8FirstMin						-62 /*A magic number! don't change it!*/

enum {
	kEncAscii = 0,
	kEncBytes = 0,
	kEncUTF8 = 8,
	kEncUTF16 = 16,
    kEncUTF32 = 32,
    kEncBE = 1,
    kEncUTF = kEncUTF8|kEncUTF16|kEncUTF32,
    kEncUTF8_BE = kEncUTF8|kEncBE,
    kEncUTF_BE = kEncUTF| kEncBE,
};



#define kMaxint			/*Becomes*/		2147483647


/* used for testing if it is ascii! */
#define k4HighBits 0x80808080
#define Max(a, b) (((a) > (b)) ? (a) : (b))
#define Min(a, b) (((a) < (b)) ? (a) : (b))


#ifndef FieldOffset
	#define FieldOffset(type, field) (int)(&((type *) 0)->field)
#endif
#define CountCArray(x) (sizeof(x)/sizeof(x[0]))



#endif /* __JB_TYPES__ */

