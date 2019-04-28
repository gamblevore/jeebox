


#ifndef __String_FUNCTIONS_LIB__
#define __String_FUNCTIONS_LIB__


extern "C" {
    
    
u8* JB_FastFileString( JB_String* S, u8* Buff);
u8* JB_FastCString( JB_String* S, u8* Buff);
u8* JB_BigCString( JB_String* Str, u8** ToFree );
   
inline JB_String* JB_Str(const char* c) {
    return JB_Str_FromCString_(c);
}

JB_String* JB_Str3(const char* c, int N);
JB_String* JB_StrFromPtr(const char* c, int N, void* Free, void* Obj);


inline JB_String* JB_Str2(u8* c) {
    return JB_Str_FromCString_((const char*)c);
}


struct MiniStr;
u8* SearchForward_ ( MiniStr S, MiniStr F, bool Lex );
JB_String* JB_Split_(JB_String* fd, int ByteOff, int LenB);
u8* u8Write_( u8* target, u32 ch );
u8* u8Write2_( u8* target, u32 ch );




// StringConvert
//int c8to16_(u8* source, int Len, JB_String** e);
//int c16to8_(u8* pSource, int Len, JB_String** e);
//int cLto8_(u8* pSource, int Len, JB_String** e);
//int cLto16_(u8* pSource, int Len, JB_String** e);
//
//int c8toL_(u8* pSource, int Len, JB_String** e);
//int c8to16_(u8* source, int Len, JB_String** e);
//int c16toL_( u8* source, int Len, JB_String** e);
//int c16to8_(u8* pSource, int Len, JB_String** e);

u8* LegalUTF8_(u8 FirstChar, u8* source);
//static int RevByteCount_(u8* a, int Len, int CharCount);
//static int ByteCount_(u8* a, int Len, int CharCount);
//static int u8Count_(u8* a, int Len);
//static u32 u8Size_( u8 FirstChar );



// StringSearchers

void Clear_(JB_String* self);
u32* Mark4Find_(u32* pSelfPos, u32 pLength, u32 Mask);

int StrDiffAt( MiniStr S, MiniStr F );
bool StrEqualsLex( MiniStr S, MiniStr F );
bool StrEquals( MiniStr A, MiniStr B );
inline bool OffsetEquals_( u8* S, MiniStr F );
bool OffsetEqualsLex( u8* S, MiniStr F );
int OffsetCompareLex( MiniStr* S, MiniStr* F );

bool IsAscii_(JB_String* e);
bool IsAsciiSub_(u8* SelfPos, u32 Length);


// StringAlterCopy

void SwapShortEndian_(u8* CurrShort, u8* WriteTo, int Len);
static JB_String* Swap_(u8* source, int Len, JB_String* u);
static void SwapM_(JB_String* self);






// StringEncoding

static int ReadBOM_(u8* StartPos, int Len, int* Flags );




// StringVerify

static int VerifyUTF16_(u16* source, u16* sourceEnd);
static int VerifyUTF8_(u8* source, u8* sourceEnd);
static int Verify8_(JB_String* self); // blah
static int Verify16(JB_String* self);
static int Verify32_(JB_String* self);



} // ExternCEnd


#endif


