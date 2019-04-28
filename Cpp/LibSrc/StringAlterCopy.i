
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



inline bool CanByteReplace_(MiniStr F, MiniStr T, bool Lexer) {
	u8 FindChar = F.Curr();
	if ( F.Length == 1  and  T.Length == 1 ) {
		if (Lexer and FindChar >= 'a' and FindChar <= 'z') {
			; //
		} else if (Lexer and FindChar >= 'A' and FindChar <= 'Z') {
			; //
		} else {
			return true;
		}
	}
	return false;
}



JB_String* JB_Str_ReplaceAll(JB_String* self, JB_String* Old, JB_String* New, bool Lex, FastString* fs_in) {
    FastString* fs = JB_FS__FastNew(fs_in);
    int prev = 0;
    int curr = JB_Str_InStr(self, Old, 0, kJB__int_max, Lex);
    while (curr >= 0) {
        JB_FS_AppendSection(fs, self, prev, curr-prev);
        JB_FS_AppendString(fs, New);
        curr = (curr + JB_Str_Length(Old));
        prev = curr;
        curr = JB_Str_InStr(self, Old, curr, kJB__int_max, Lex);
    };
    if (!fs->Length and !fs_in) {
        return self;
    }
    JB_FS_AppendSection(fs, self, prev, kJB__int_max);
    return JB_FS_SmartResult(fs, fs_in);
}


JB_String* JB_Str_MultiReplaceAll(JB_String* self, Dictionary* Dict, JB_ErrorReceiver* Rec) {
	return JB_MSR_ReplaceAll(Dict, self, 0, Rec);
}


JB_String* ReturnOrAppend_( FastString* fs, JB_String* Data, FastString* Orig ) {
	if ( Orig ) {
        JB_FS_AppendString( fs, Data );
        return 0;
	}

    return Data;
}

JB_String* JB_FS_SmartResult( FastString* fs, FastString* Orig ) {
	if ( !Orig ) {
		return JB_FS_GetResult( fs );
	}
	return 0;
}


JB_String* JB_Str_Hex(JB_String* s) {
	int SelfLen = s->Length;
	JB_String* r = JB_Str_New( SelfLen*2 );
	if ( !r or !SelfLen) {
		return r;
	}

	u8* SelfPos = s->Addr;
	u8* SelfEnd = SelfPos + SelfLen;
	u8* OutPos = r->Addr;
	for ( ; SelfPos < SelfEnd; SelfPos++ ) {
		u8 ThisChar = *SelfPos;
		u8 NextChar = (u8) (ThisChar & 0x0F);
		ThisChar = (u8)(ThisChar >> 4);
		if (ThisChar < 10) {
			ThisChar = (u8)(ThisChar + '0');
		} else {
			ThisChar = (u8)(ThisChar + 55); //'A' - 10
		}
		if (NextChar < 10) {
			NextChar = (u8)(NextChar + '0');
		} else {
			NextChar = (u8)(NextChar + 55); //'A' - 10
		}
		*OutPos++ = ThisChar;
		*OutPos++ = NextChar;
	}

 	return r;
}

JB_String* JB_Str_MapBytes(JB_String* s, ByteMap* CS) {
	int FirstPos = JB_Str_CharSet( s, 0, kMaxint, CS, true );
	if ( FirstPos < 0 ) {
		return s;
	}

	u8* map = CS->Cache;

	JB_String* r = JB_Str_New( s->Length ); // we know that s->Length is positive! because we checked FirstPos above.
	if ( !r ) {
		return 0;
	}

	if (FirstPos) {
		CopyBytes( s->Addr, r->Addr, FirstPos );
	}
	u8* SelfPos = s->Addr + FirstPos;
	u8* OutPos = r->Addr + FirstPos;
	int SelfLen = s->Length - FirstPos;

	while ( SelfLen-- > 0 ) {
		*OutPos++ = map[ *SelfPos++ ];
	}

 	return r;
}


JB_String* JB_Str_UnHex(JB_String* self) {
	int SelfLen = self->Length;
	u8* SelfPos = self->Addr;
	JB_String* r = JB_Str_New( SelfLen / 2 );
	if ( ! JB_Str_Length( r ) ) {
		return r;
	}

	u8* OutPos = r->Addr;
	u32 byte = 0;
	u8 OutBits = 0;

	while ( SelfLen-- ) {
		u32 byte2 = (u32)*SelfPos++;
// we basically add 1 to each byte read, so we know if we really have that byte or not!
		if (byte2 >= '0' and byte2 <= '9') {
			byte2 = byte2 - 48 + 1;
		} else if (byte2 >= 'a' and byte2 <= 'f') {
			byte2 = byte2 - 87 + 1;
		} else if (byte2 >= 'A' and byte2 <= 'F') {
			byte2 = byte2 - 55 + 1;
		} else { // bad data
			byte = 0;
			continue;
		}

		byte = byte2 + byte*16;

		if ( byte >= 17 ) {
			byte = byte - 17;
			*OutPos++ = (u8)byte;
			OutBits = OutBits | byte;
			byte = 0;
		}
	}

    JB_String* S = JB_Str_Realloc(&r, (int)(OutPos - r->Addr));
    JB_SafeDecr(S);
    return S;
}


JB_String* JB_ASCII() {
    static JB_String* ASCII = 0;
    if (!ASCII) {
        const char kASCII[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124, 125, 126, 127};
        ASCII = JB_New(JB_String);
        ASCII->Addr = (u8*)kASCII;
        ASCII->Length = 128;
        JB_Incr(ASCII);
    }
    return ASCII;
}

JB_String* JB_Upper() {
    return JB_Str_Range( JB_ASCII(), 'A', 'Z' + 1 );
}

JB_String* JB_Lower() {
    return JB_Str_Range( JB_ASCII(), 'a', 'z' + 1 );
}

bool JB_IsLetterOrSpace(int N) {
    return (N >= 'a' and N <= 'z') or (N >= 'A' and N <= 'Z') or N == 0x20;
}

JB_String* JB_Str_FastLower(JB_String* self) {
    int N = self->Length;
    if ( ((u32)(N-1)) >= 4 ) {
        return JB_Str_LowerCase(self);
    }
    dbgexpect2(N <= 4 and N >= 1);
    dbgexpect2(JB_IsLetterOrSpace(self->Addr[3]));
    int OldData = *((int*)self->Addr);
    int NewData = OldData | 0x20202020; // assumes ASCII.
    if (OldData != NewData) {
        self = JB_Str_New(N);
        *((int*)(self->Addr)) = NewData;
    }
    return self;
}

ByteMap* JB_BM__Lower() {
    static ByteMap* LowerMap_ = 0;
    if (!LowerMap_) {
        LowerMap_ = JB_BM_( JB_Upper(), JB_Lower() );
    }
    return LowerMap_;
}

JB_String* JB_Str_LowerCase(JB_String* self) {
	return JB_Str_MapBytes( self, JB_BM__Lower() );
}

JB_String* JB_Str_UpperCase(JB_String* self) {
    static ByteMap* UpperMap_ = 0;
    if (!UpperMap_) {
        UpperMap_ = JB_BM_( JB_Lower(), JB_Upper() );
    }
	return JB_Str_MapBytes( self, UpperMap_ );
}


JB_String* JB_Str_Trim(JB_String* self) {
	int First = JB_Str_WhiteSpace( self, 0, kMaxint, false );
	if (First < 0) {
		return JB_Str_Empty();
	}
	int Last = JB_Str_WhiteSpace( self, kMaxint, 0, false );
	return JB_Str_Range(self, First, Last + 1);
}


void SwapintEndian_(u8* Currint, u8* WriteTo, int Len) {
	// Len is in bytes!
	// still works if WriteTo == CurrShort!
	Len -= ( Len % 4 ); // align to 4.
	if (!Currint or Len <= 0) {
		return;
	}

	u8*	EndPos = Currint + Len;

	for ( ; Currint < EndPos; Currint+=4, WriteTo+=4) {
		u8 tmpChar = *Currint;
		*WriteTo = *(Currint + 3);
		*(WriteTo + 3) = tmpChar;

		tmpChar = *(Currint + 1);
		*(WriteTo + 1) = *(Currint + 2);
		*(WriteTo + 2) = tmpChar;
	}
}

void SwapShortEndian_(u8* CurrShort, u8* WriteTo, int Len) {
	// Len is in bytes!
	// still works if WriteTo == CurrShort!
	Len /= 2;
	if (!CurrShort or !WriteTo or Len <= 0) {
		return;
	}

	for ( ; Len > 0; Len-- ) {
		u8 tmpChar = *CurrShort;
		CurrShort += 2;
		*WriteTo = *(CurrShort - 1);
		WriteTo += 2;
		*(WriteTo - 1) = tmpChar;
	}
}


void SwapM_(JB_String* self) {
	u8* source = self->Addr;
	int Len = self->Length;
    SwapShortEndian_(source, source, Len);
}

JB_String* Swap_(u8* source, int Len, JB_String* u) {
	JB_String* result = JB_Str_New( Len );
	if (result) {
        SwapShortEndian_(source, result->Addr, Len);

	}
    return result;
}


JB_String* JB_Str_ReplaceAllB(JB_String* self, int lFrom, int lTo) {
	return JB_Str_ReplaceBytesSub_(self, lFrom, lTo, 0 );
}

JB_String* JB_Str_ReplaceBytesSub_(JB_String* self, int lFrom, int lTo, FastString* fs_in) {
	int FirstOff = JB_Str_InByte( self, 0, kMaxint, lFrom );
	FastString* fs = JB_FS__FastNew(fs_in);
	if ( FirstOff < 0 ) {
		return ReturnOrAppend_(fs, self, fs_in);
	}

	int Length = self->Length;
	u8* WriteTo = JB_FS_WriteAlloc_(fs, Length);
	if (!WriteTo) {
		return 0;
	}
	if (FirstOff) {
		CopyBytes( self->Addr, WriteTo, FirstOff );
	}

	u8* SelfPos = self->Addr + FirstOff;
	u8* OutPos  = WriteTo + FirstOff;
	int SelfLen = Length - FirstOff;

	while ( SelfLen-- ) {
		u8 Char = *SelfPos++;
		if (Char == (u8)lFrom) {
			Char = (u8)lTo;
		}
		*OutPos++ = Char;
	}

    return JB_FS_SmartResult(fs, fs_in);
}


JB_String* JB_Str_Reverse(JB_String* self) {
	int Length = self->Length;
	JB_String* result = JB_Str_New( Length );

	if ( result and Length ) {
		u8* Read = self->Addr + Length - 1;
		u8* Write = result->Addr;
		while ( Length-- ) {
			*Write++ = *Read--;
		}
	}

	return result;
}



