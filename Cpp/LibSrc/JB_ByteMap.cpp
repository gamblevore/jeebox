
// By Theodore H. Smith, released under zlib licence v1.2.11
/* zlib.h -- interface of the 'zlib' general purpose compression library
  version 1.2.11, January 15th, 2017

  Copyright (C) 1995-2017 Jean-loup Gailly and Mark Adler

  This software is provided 'as-is', without any express or implied
  warranty.  In no event will the authors be held liable for any damages
  arising from the use of this software.

  Permission is granted to anyone to use this software for any purpose,
  including commercial applications, and to alter it and redistribute it
  freely, subject to the following restrictions:

  1. The origin of this software must not be misrepresented; you must not
     claim that you wrote the original software. If you use this software
     in a product, an acknowledgment in the product documentation would be
     appreciated but is not required.
  2. Altered source versions must be plainly marked as such, and must not be
     misrepresented as being the original software.
  3. This notice may not be removed or altered from any source distribution.

  Jean-loup Gailly        Mark Adler
  jloup@gzip.org          madler@alumni.caltech.edu
*/

/*
	Copyright (C) 2005 Theodore H. Smith.
*/

#include "JB_Umbrella.h"
#include <string.h>


extern "C" {


inline void InitCharset_(ByteMap* cs, u8* SelfPos, u32 Len, bool Ranges) {
	Len = Min(Len, 256);
	u8* Cache = cs->Cache;
    u8* ReadEnd = SelfPos + Len;
    
	if (!Ranges) {
		while ( SelfPos < ReadEnd ) {
			u8 c = *SelfPos++;
			Cache[ c ] = (u8)(255 - c); // inverse it!
		}
	} else {
		while ( SelfPos < ReadEnd ) {
			u8 c = *SelfPos++;
			u8 c2 = *SelfPos++;
			int a = Min( c, c2 );
			int b = Max( c, c2 );

			for ( ; a <= b; a++) {
				Cache[ a ] = (u8)(255 - a); // inverse it!
			}
		}
	}
}


void JB_CSClear_( ByteMap* cs ) {
	u8* Cache = cs->Cache;
	for ( int i = 0; i < 256; i++ ) {
		Cache[i] = (u8)i;
	}
}


void WipeTo_( ByteMap* cs, u8 F ) {
	u8* Cache = cs->Cache;
	for ( int i = 0; i < 256; i++ ) {
		Cache[i] = F;
	}
}


void JB_BM_ConstructorCharset(ByteMap* self, JB_String* Source, bool Ranges) {
	JB_CSClear_( self );
	if ( Source ) {
		InitCharset_( self, Source->Addr, Source->Length, Ranges );
	}
}


ByteMap* JB_BM_InvertCharset( ByteMap* self ) {
    u8* Cache = self->Cache;
    ByteMap* Result = JB_NewEmpty( ByteMap );
    require(Result);

    u8* CacheResult = Result->Cache;
    
    for (int i = 0; i <= 255; i++) {
        if (Cache[ i ] != (u8)i) {
            CacheResult[i] = (u8)i;
        } else {
            CacheResult[i] = (u8)(255-i);
        }
    }
    
    return Result;
}


ByteMap* JB_BM_InvertByteMap( ByteMap* self, int Unfound ) {
    u8* Old = self->Cache;
    ByteMap* Result = JB_NewEmpty( ByteMap );
    require(Result);
    if (Unfound >= 0) {
        WipeTo_(Result, Unfound);
    } else {
        JB_CSClear_( Result );
    }
    
    u8* New = Result->Cache;

// let's say... we are mapping A-Z, to a-z. That's just lowercase
// now we want to map a-z, to A-Z. How to get upper-case, from lowercase?
// well... first, let's only read the ones that are "set".

    for (int i = 0; i <= 255; i++) {
        auto C = Old[i];
        if (BM_In_( Old, i )) {
            // Ok so it's set. Now...?
            // (i == 'A'), and (C == 'a')
            New[C] = (u8)i; // so... let's swap? basically... that's it!
        }
    }
    
    return Result;
}


JB_String* JB_BM_Render(ByteMap* self, FastString* fs_in) {
	u8* Cache = self->Cache;
	FastString* fs = JB_FS__FastNew( fs_in );
    JB_FS_SizeSet(fs, 256);
	
	for (int i = 0; i <= 255; i++) {
		if ( BM_In_( Cache, i ) ) {
			JB_FS_AppendByte( fs, i );
		}
	}

	return JB_FS_SmartResult( fs, fs_in );
}


u8 JB_BM_Access( ByteMap* self, int Value ) {
    return self->Cache[Value&255];
}


bool JB_BM_HasChar( ByteMap* self, int Value ) {
    if ((u32)Value <= 255) {
        return BM_In_( self->Cache, (u8)Value );
    }
    return false;
}


inline void JB_BM_MapWrite( ByteMap* cs, u8* fr, u8* tr, int Len) {
    while ( Len-- ) {
        cs->Cache[ *fr++ ] = *tr++;
    }
}


void JB_BM_Constructor( ByteMap* self, JB_String* From, JB_String* To ) {
    JB_CSClear_( self );
    
    // shouldn't really be putting functions in defines... but one extra func is no worry.
    int Len = Min( JB_Str_Length( From ), JB_Str_Length( To ) );
    if ( Len ) {
        JB_BM_MapWrite( self, (u8*)JB_Str_Address(From), (u8*)JB_Str_Address(To), Len );
    }
}


ByteMap* JB_BM_( JB_String* a, JB_String* b ) {
    ByteMap* Result = JB_New( ByteMap );
    
    JB_BM_Constructor( Result, a, b );
        
    JB_Incr(Result);
    return Result;
}



} // 


