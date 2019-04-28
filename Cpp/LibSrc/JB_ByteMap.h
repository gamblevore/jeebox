
/*
	Copyright (C) 2005 Theodore H. Smith.
*/


#ifndef __CHARSET__        // InLines and useful
#define __CHARSET__

#include "JB_Alloc.h"

extern "C" {

JBClass( ByteMap, JB_Object,
	u8			Cache[256];
);

inline bool BM_In_( u8* cache, u8 charr ) {
    return cache[charr] != charr;
}

inline bool BM_Out_( u8* cache, u8 charr ) {
    return cache[charr] == charr;
}
//#define BM_Out_( cache, charr ) ( cache[charr] == charr )


        // function Declarations

void JB_BM_ConstructorCharset(ByteMap* self, JB_String* Source, bool Ranges);
bool JB_BM_HasChar( ByteMap* self, int Value );
u8 JB_BM_Access( ByteMap* self, int Value );
JB_String* JB_BM_Render(ByteMap* self, FastString* Orig);
ByteMap* JB_BM_InvertCharset( ByteMap* self );
ByteMap* JB_BM_InvertByteMap( ByteMap* self, int Unfound );
JB_String* JB_BM_Strip( ByteMap* self, JB_String* Data );
int JB_BM_Count( ByteMap* self, JB_String* CharSet );

void JB_BM_Constructor(ByteMap* self, JB_String* From, JB_String* To);
ByteMap* JB_BM_( JB_String* a, JB_String* b );


} // ExternCEnd

#endif //__CHARSET__


