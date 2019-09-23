
/*
	Copyright (C) 2005 Theodore H. Smith.
*/


#ifndef __FastString__
#define __FastString__

#include "JB_Umbrella.h"

extern "C" {

typedef void (*FSEventResize)(FastString* self, int Needed);


JBClass( FastString, JB_Object,
	int 			Length;
    u8*				ResultPtr;
    int             WrittenLength;

    u16             Indent;    // Jeebox itself needs this.
    u8              IndentChar;
    u8              IndentMul;

    JB_String*      Result;
    int 			Reserved;  // actual size of buffer.

    JB_File*        File;
);


#define ksFastString		"FastString"
#define kFSDefaultSize		(1*1024)




        /* function Declarations */

void JB_FS_AppendMini(FastString* fs, MiniStr S);
void JB_FS_AppendMem_(FastString* fs, u8* s0, int len);
void JB_FS_AppendCString(FastString* self, const char* c);
void JB_FS_AppendCString2(FastString* self, u8* c);
bool JB_FS_ResizeTo_(FastString* fs, int NewLength);
bool JB_FS_NeedSpare(FastString* fs, int Extra);
void JB_FS_RemoveByte(FastString* self, byte B);

    
FastString* JB_FS__InternalNew();
FastString* JB_FS__FastNew(FastString* Old);
JB_String* JB_FS_SmartResult(FastString* fs, FastString* Orig);
#ifdef TARGET_WIN32
	#define JB_FS_AppendFileChar( a, b ) JB_FS_AppendShort( a, b )
#else
	#define JB_FS_AppendFileChar( a, b ) JB_FS_AppendByte( a, b )
#endif 

u8*  JB__WriteIntToBuffer (u8* wp, s64 LeftOver);
bool JB_FS_SizeIf_( FastString* fs, int InitLength);
void JB_FS_ByteSet(FastString* self, int offset, int Val);
u8*  JB_FS_WriteAlloc_(FastString* fs, int GrowBy);
void JB_FS_AppendString(FastString* self, JB_String* u);
void JB_FS_AppendLine(FastString* self, JB_String* s);
void JB_FS_AppendSection(FastString* self, JB_String* u, int srStart, int srLength);
void JB_FS_AppendFastString(FastString* self, FastString* po);
void JB_FS_AppendSectFastString(FastString* self, FastString* po, int srStart, int srLength);
void JB_FS_ConstructorSize(FastString* self, int wtf);
void JB_FS_Constructor(FastString* self);
void JB_FS_AppendByte(FastString* self, int byte);
void JB_FS_AppendMultiByte(FastString* self, int byte, int Count);
void JB_FS_AppendUTF8Char(FastString* self, int Char);
void JB_FS_AppendDoubleAsText0(FastString* self, double D);
void JB_FS_AppendDoubleAsText(FastString* self, double D, u8* fmt);
int JB_FS_Byte(FastString* self, int offset);
void JB_FS_AppendHex(FastString* self, int64 tVal, int PadTo);
void JB_FS_AppendHexData(FastString* fs, u8* Addr, int N);
void JB_FS_AppendHex3(FastString* fs, int tVal);
void JB_FS_AppendIntegerAsText(FastString* self, s64 LeftOver, int RoundTo);
    void JB_FS_AppendIndent( FastString* self );

void JB_FS_AppendDate(FastString* self, Date D);
void JB_FS_AppendShort(FastString* self, int s);
void JB_FS_AppendInteger(FastString* self, int l);
void JB_FS_AppendSingle(FastString* self, float f);
void JB_FS_AppendFract16(FastString* self, u16 Fract);
void JB_FS_AppendDouble(FastString* self, double d);
void JB_FS_AppendInteger(FastString* self, int i);
void JB_FS_Compact(FastString* self);
void JB_FS_EnsureMinSize(FastString* self, int minSize);
int JB_FS_BufferSize(FastString* self);
void JB_FS_SizeSet(FastString* self, int newsize);
int JB_FS_FreeSize(FastString* self);
void JB_FS_FreeSizeSet(FastString* self, int nExtraBytes);
int JB_FS_Length(FastString* self);
void JB_FS_LengthSet(FastString* self, int newLength);
void JB_FS_AppendReplaceB(FastString* self, JB_String* Data, int From, int To);
void JB_FS_AppendMultiReplace(FastString* self, JB_String* Data, Dictionary* MSR, JB_ErrorReceiver* Rec);
void JB_FS_AppendByteMap(FastString* self, JB_String* Data, ByteMap* MSR);
void JB_FS_AppendLower(FastString* fs, JB_String* Data);
bool JB_FS_Flush(FastString* self);
JB_File* JB_FS_File(FastString* fs);

struct JB_File;
void JB_FS_FileSet(FastString* fs, JB_File* F);

void JB_FS_Destructor(FastString* self);
JB_String* JB_FS_GetResult(FastString* self);
u8* JB_FS_GrowBy(FastString* fs, int Needs);
u8* JB_FS_Request_(FastString* fs, int Length);

void JB_Str_UnHexRaw(JB_String* Str, u8* Data, int N);


#ifndef JB_DEBUG_ON
	#define FS_SanityCheck_(fs)
#else
	void FS_SanityCheck_( FastString* fs );
#endif

inline u8* JB_FS_WriteAlloc_Inline_(FastString* fs, int GrowBy) {
//	expect( GrowBy >= 1 );

	int OldLen = fs->Length;
	int NewLen = OldLen + GrowBy;

	if ( fs->Reserved >= NewLen ) { // we put the usual case first :)
		fs->Length = NewLen;
		return fs->ResultPtr + OldLen;
	}

    return JB_FS_GrowBy(fs, GrowBy);
}


inline void JB_FS_AdjustLength_( FastString* fs, int Expected, int Actual ) {
	fs->Length = fs->Length + Actual - Expected;
	FS_SanityCheck_(fs);
}


	// INLINED CODE DIRECTLY. TO AVOID COMPILER NOT INLINING IT!!!!

} // ExternCEnd

#endif //__FastString__


