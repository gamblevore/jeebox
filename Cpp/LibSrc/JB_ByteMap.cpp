
// Copyright, Theodore H. Smith 2019.
// Released under jeebox-licence http://jeebox.org/licence.txt


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





// over engineered? unused?
int JB_BM_Count(ByteMap* self, JB_String* Source) {
	u8* Cache = self->Cache;
    int N = JB_Str_Length(Source);
    int Count = 0;
	for (int i = 0; i < N; i++) {
		if ( BM_In_( Cache, Source->Addr[i] ) ) {
            Count++;
		}
	}

	return Count;
}


JB_String* JB_BM_Remove(ByteMap* self, JB_String* Source, FastString* fs_in) {
    int N = JB_Str_Length(Source);
    if (JB_Str_CharSet(Source, 0, N, self, false) == -1) {
        // entirely in. append entire thing.
        if (!fs_in) {
            return Source;
        }
        JB_FS_AppendString(fs_in, Source);
        return 0;
    }
    
	u8* Cache = self->Cache;
    FastString* fs = 0;
    
	for (int i = 0; i < N; i++) {
        u8 B = Source->Addr[i];
		if ( BM_Out_( Cache, B ) ) {
            if (!fs) {
                fs = JB_FS__FastNew(fs_in);
            }
            JB_FS_AppendByte(fs, B); 
		}
	}

	JB_String* Result = JB_FS_SmartResult(fs, fs_in);
    JB_FreeIfDead(fs);
    return Result;
}


} // 


