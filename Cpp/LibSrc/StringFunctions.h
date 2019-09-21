
#ifndef __JB_Str_FUNCTIONS__
#define __JB_Str_FUNCTIONS__

#include "JB_Alloc.h"





extern "C" {

struct JB_String;
struct FastString;
typedef JB_String* (*fpRenderer)(JB_Object* self, FastString* FS);

// obj?
JB_String* JB_ObjRender(JB_Object* self, FastString* fs_in);
JB_String* JB_Obj_GenericRender(JB_Object* self, FastString* fs_in);

// StringCore

struct MiniStr;
struct JB_StringExternal;
JB_String* JB_Str_Realloc(JB_String** u, int Length);
JB_String* JB_Str_New(int Len);
JB_String* JB_Str_Render(JB_String* self, FastString* fs);
JB_String* JB_FS_Render(FastString* self, FastString* fs_in);
JB_String* JB_Str_FromCString_( const char* c );
JB_String* JB_Str_ZeroTerm(JB_String* self);
bool JB_Str_NeedsZeroTerm(JB_String* self);
JB_StringShared* JB_Str_FromPtr( MiniStr M );
JB_String* JB_Str_CopyFromPtr( u8* Addr, int N );
JB_String* JB_Str_Copy( JB_String* self );
void JB_Str_Destructor(JB_StringShared* self);
void JB_XStr_Destructor(JB_StringExternal* self);
void JB_Str_Constructor( JB_String* self );
void JB_Str_Print( JB_String* s );
void JB_Str_PrintLine( JB_String* s );
void JB_Str_PrintError(JB_String* s);
void JB_Str_PrintTo(JB_String* s, int Num);
void JB_Str_PrintConsole(JB_String* s);
int JB_LogOpen_(const char* s);
struct Array;
void JB_Array_Print( Array* R );
Array* JB_Str_ArgV(char** ArgV);
Dictionary* JB_C_Args_Env(char** self);


int JB_Str_IsCompressed(JB_String* self);
JB_String* JB_Str_Compress(JB_String* self, FastString* fs_in);
JB_String* JB_Str_Decompress(JB_String* self, FastString* fs_in);
JB_String* JB_Str_LZ4Transform (JB_String* self, FastString* fs_in);
void RestartDecompReport (const char* Name);
FastString* JB_Str_CompressFS(FastString* fs_in);

// StringConvert

JB_String* JB_Str_ConvertToUTF8(JB_String* self, int From);
JB_String* JB_Str_QuickConvertToUTF8(JB_String* self);
JB_String* JB_Str_ConvertTo( JB_String* self, int From, int To );
JB_String* JB_Str_EncodeB64(JB_String* Str, FastString* fs);
JB_String* JB_Str_DecodeB64(JB_String* Str, FastString* fs);
u32 JB_Str_UTF8Size( u32 c );
JB_String* JB_Str_Cleanse(JB_String* self, u32 Code);



// StringCS

int JB_Str_WhiteSpace( JB_String* self, int StartPos, int EndPos, bool IsIn );
int JB_Str_CharSet( JB_String* self, int BeginPos, int EndPos, ByteMap* Find, bool IsIn );



// StringSearchers

int JB_Str_InStr( JB_String* self, JB_String* Find, int BeginPos, int After, bool CaseAware );
//int JB_Str_InRevStr( JB_String* self, JB_String* Find, int BeginPos, int EndPos, bool Lexer );
int JB_Str_InByte( JB_String* self, int StartPos, int After, int SearchChar );
int JB_Str_OutByte( JB_String* self, int StartPos, int After, int SearchChar );
bool JB_Str_Equals(JB_String* self, JB_String* Search, bool Lexer);
int JB_Str_DiffAt( JB_String* S, JB_String* F );
int JB_Str_Compare(JB_String* self, JB_String* Search, bool Lexer);








bool JB_Str_MidEquals(JB_String* self, int BeginOff, JB_String* find, bool Lexer);
int JB_Str_UTF8Value(JB_String* self, int offset);
int JB_Str_ByteValue(JB_String* self, int offset);
int JB_Str_ShortValue(JB_String* self, u32 offset);
int JB_Str_IntValue(JB_String* self, u32 offset);
double JB_Str_DoubleValue(JB_String* self, u32 offset);
float JB_Str_SingleValue(JB_String* self, u32 offset);


// StringAlterCopy


JB_String* JB_Str_ReplaceAllB(JB_String* self, int cFrom, int cTo);
struct FastString;
struct JB_ErrorReceiver;
JB_String* JB_Str_ReplaceAll(JB_String* self, JB_String* Old, JB_String* New, bool Lex, FastString* fs_in);
JB_String* JB_Str_MultiReplaceAll(JB_String* self, 	Dictionary* Dict, JB_ErrorReceiver* Rec);
//JB_String* JB_Str_MultiReplaceAll(JB_String* self,  Dictionary* Dict, JB_ErrorReceiver* Rec);
JB_String* JB_Str_ReplaceBytesSub_(JB_String* self, int lFrom, int lTo, FastString* fs);
JB_String* JB_Str_UnHex(JB_String* self);
JB_String* JB_Str_Hex(JB_String* self);
JB_String* JB_Str_MapBytes(JB_String* self, ByteMap* CS);
JB_String* JB_Str_LowerCase(JB_String* self);
JB_String* JB_Str_FastLower(JB_String* self);
ByteMap* JB_BM__Lower();
JB_String* JB_Str_UpperCase(JB_String* self);
JB_String* JB_Str_Reverse(JB_String* self);
void JB_Str_StretchBack_(JB_String* self, int i);
JB_String* JB_Str_Trim(JB_String* self);
JB_String* JB_ASCII();
JB_String* JB_Upper();
JB_String* JB_Lower();



// StringCloneAndCopy
/*
    JB_Object* JB_Str_DataCopy(JB_String* self);
    bool JB_Str_UnSplit( JB_String* self );
    bool JB_Str_Acquire( JB_String* self );
    JB_String* JB_Str_ObjectCopy(JB_String* self);
 */



// StringSplitters

//JB_String* JB_Str_Mid(JB_String* self, int Start, int Count);
JB_String* JB_Str_Range(JB_String* self, int Start, int Finish);
JB_String* JB_Str_Left(JB_String* self, int Count);
JB_String* JB_Str_Right(JB_String* self, int Count);
JB_String* JB_Str_OperatorPlus(JB_String* self, JB_String* other);
JB_String* JB_Str_Unshare(JB_String* self);
//JB_String* JB_Str_RevMid(JB_String* self, int Count);



// StringEncoding

struct Message;
JB_String* JB_Str_UnicodeSync(JB_String* Str);
int JB_Str_EncodingXMLGuess(JB_String* Data);
int JB_Str_EncodingReadBOM(JB_String* self);
JB_String* JB_Str_BOM(JB_String* self, int Encoding, bool IsBigEndian);
bool JB_Str_IsInteger( JB_String* self, int BeginPos, int EndPos, bool AllowMinus );
//bool JB_Str_IsDouble( JB_String* self, int BeginPos, int EndPos );
double JB_Str_TextDouble(JB_String* self, Message* Where);
s64 JB_Str_TextInteger(JB_String* self);
s64 JB_Str_HexInteger(JB_String* self);
s64 JB_Str_TextIntegerValid(JB_String* self, Message* b);
s64 JB_Str_HexInteger2(JB_String* self, Message* b);




// StringProperties

bool JB_Str_IsUnder(JB_String* self, u32 Under);
int JB_Str_LengthUTF8(JB_String* self);
bool JB_Str_IsASCII(JB_String* self);
int JB_Str_Length( JB_String* self );
u8* JB_Str_Address(JB_String* self);



// StringVerify

int JB_Str_Verify(JB_String* self, int utf);



// StringGlobals

JB_String* JB_Str_Empty();
bool JB_Str_IsEmpty(JB_String* Obj);
bool JB_Str_Exists(JB_String* Obj);
JB_String* JB_Str_ChrUTF8(u32 c);
JB_String* JB_Str_ChrB(int i);
bool JB_Str_UniValid(u32 c);
JB_String* JB_Str_FromInt( int L, int R );

}

#endif //#ifndef __JB_Str_FUNCTIONS__

