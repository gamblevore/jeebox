
// Copyright, Theodore H. Smith 2019.
// Released under jeebox-licence http://jeebox.org/licence.txt




        /* InLines and useful */


#include "JB_Umbrella.h"

extern "C" {

#define kDefaultSize (1024*2)

inline u8 NumToHex(u32 Num) {
	if ( Num <= 9 ) {
		return Num + '0';
	}
	return Num + ('A'-10);
}

static void ClearFS_(FastString* fs) {
    JB_ClearRef( fs->Result );
    JB_ClearRef( fs->File );

    JB_FS_Constructor(fs);
}



void FS_CheckLast(FastString* fs) {
    // check output ! the old way was perfect.
//    if (fs->Comparable) {
    // Compare(fs->Comparable, fs->LastPos, fs->Length );
// }
    // fs->LastPos = fs->Length;
}


     /* Usables. Not directly called by the plugin, but called as a sub method */


void JB_FS_AppendMini(FastString* fs, MiniStr S) {
	FS_SanityCheck_(fs);
	dbgexpect(fs);
	dbgexpect(S.Length >= 0);

    u8* Write = JB_FS_WriteAlloc_Inline_(fs, (int)S.Length);
    
//	dbgexpect( fs->ResultPtr <= Write );
//	dbgexpect( fs->ResultPtr + fs->Reserved >= Write + S.Length );
	if (S.Length < 8) { // I think that it is faster to copy, but only up to 8??? My xtensive tests show so!
		while ( S ) {
			*Write++ = S.Next();
		}
	} else {
		CopyBytes(S.Addr, Write, S.Length);
	}
    
	FS_SanityCheck_(fs);
}


void JB_FS_AppendMem_(FastString* fs, u8* s0, int Length) {
    MiniStr S = {Length, s0};
	JB_FS_AppendMini(fs, S);
}

u8* JB_FS_WriteAlloc_(FastString* fs, int GrowBy) {
	return JB_FS_WriteAlloc_Inline_(fs, GrowBy);
}



bool JB_FS_NeedSpare(FastString* fs, int Extra) {
    int Spare = fs->Reserved - fs->Length;
    if (Spare < Extra) {
        return JB_FS_ResizeTo_(fs, fs->Reserved + Extra );
    }
    return true;
}

bool JB_FS_ResizeTo_(FastString* fs, int NewLength) {
    FS_SanityCheck_(fs);
    
    if (NewLength == fs->Reserved) {
        return true;
    }
    
    if (!JB_Str_Realloc( &fs->Result, NewLength ) ) {
        return false; // if we can’t grow, just keep the old.
    }
    
    fs->ResultPtr = fs->Result->Addr;
    fs->Reserved = NewLength;
    
    if (NewLength < fs->Length) {
        fs->Length = NewLength;
    }
    return true;
}


u8* JB_FS_GrowBy(FastString* fs, int Needs) {
    if ( JB_FS_Flush( fs ) and fs->Reserved >= Needs ) {
        fs->Length = Needs;
        return fs->ResultPtr;
    }

    int NewLength = fs->Length + Needs;
    if ( NewLength < kDefaultSize ) {
        NewLength = kDefaultSize;
        if (fs->File) {
            NewLength = 32*1024; 
        }
    }

    for (  int i = 2;   i >= 1;   i = i / 2  ) {
        if (NewLength*i  >=  NewLength) {
            if (JB_FS_ResizeTo_(fs, NewLength*i)) {
                int L = fs->Length;
                fs->Length = L + Needs;
                return fs->ResultPtr + L;
            }
        }
    }

    return 0;
}



	/* Appends */

void JB_FS_AppendString( FastString* self, JB_String* u ) {
	if ( u ) {
		JB_FS_AppendMem_( self, u->Addr, u->Length );
	}
}

void JB_FS_AppendLine( FastString* self, JB_String* u ) {
	JB_FS_AppendString(self, u);
	JB_FS_AppendByte(self, 10);
}


void JB_FS_AppendSection(FastString* self, JB_String* Data, int srStart, int srLength) {
	if ( Data and SectFix_( srStart, srLength, Data->Length ) ) {
        JB_FS_AppendMem_(self, Data->Addr + srStart, srLength );
	}
}

void JB_FS_AppendCString2(FastString* self, u8* c) {
    JB_FS_AppendCString(self, (const char*)c);
}

void JB_FS_AppendCString(FastString* self, const char* c) {
    if ( c ) {
        int Length = (int)strlen( c );
        if (Length) {
            JB_FS_AppendMem_(self, (u8*)c, Length);
        }
    }
}


void JB_FS_AppendByte(FastString* self, int byte) {
	u8* Write = JB_FS_WriteAlloc_Inline_(self, 1);
	if ( Write ) {
		*Write = (u8)byte;
	}
	FS_SanityCheck_(self);
}

    
void JB_FS_RemoveByte(FastString* self, byte B) {
    u8* Addr = self->ResultPtr;
    if (Addr) {
        int Len_m_1 = self->Length - 1;
        if (Addr[Len_m_1] == B) {
            self->Length = Len_m_1;
        }
    }
}


void JB_FS_AppendMultiByte(FastString* self, int byte, int Count) { // - numbers become +2billion!
	if ( Count > 0 ) {
		u8* Write = JB_FS_WriteAlloc_(self, Count);
		if (Write) {
			for ( ; Count > 0; Count-- ) {
				*Write++ = (u8)byte;
			}
		}
	}
	FS_SanityCheck_(self);
}


void JB_FS_AppendIndent( FastString* self ) {
    if (self->Indent >= 20) {
        debugger;
    }
    if (self->IndentChar) {
        int M = Max(self->IndentMul,1);
        JB_FS_AppendMultiByte( self, self->IndentChar, self->Indent*M );
    }
}


void JB_FS_AppendUTF8Char(FastString* self, int Char) {
    u8* WritePos = JB_FS_WriteAlloc_Inline_(self, 4);
    if (WritePos) {
        int WroteLen = (int)(u8Write_( WritePos, Char ) - WritePos);
        JB_FS_AdjustLength_( self, 4, WroteLen );
    }
}


// this function must be able to write hex, in varying outputs.

void JB_FS_AppendHexSub(FastString* fs, int64 tVal, int RoundTo, u8* CharMap) {
	if (RoundTo < 1) {RoundTo = 1;}
    if (RoundTo > 8) {RoundTo = 8;} // invalid input!
	if (!tVal) {
		JB_FS_AppendMultiByte(fs, CharMap[0], RoundTo);
		return;
	}

	u8* wp = JB_FS_WriteAlloc_(fs, 8);
	if (wp) {
		u8* wpStart = wp;
		u32 Val = (u32)tVal;
        // replace with JB_u64_Log2 later...
		int SignificantBytes = 8;
		while (!(Val & 0xF0000000) ) { // soon as we find the half-byte, we exit!
			SignificantBytes--;
			Val <<= 4;
		}

		int PadWrite = RoundTo - SignificantBytes;
		if ( PadWrite < 0 ) {
			// sig=7, round=2, pad=-5
			PadWrite = (int)((u32)SignificantBytes % (u32)RoundTo);
			// sig=7, round=2, pad=1
		}

		for ( ; PadWrite > 0; PadWrite-- ) {
			*wp++ = CharMap[0];
		}
		for ( int i = SignificantBytes; i > 0; i-- ) {
			u32 currWrite = Val >> 28; // 28 = 7 * 4, or 8 - 1 shifts, of 4 bits.
			*wp++ = CharMap[currWrite];
			Val <<= 4;
		}
		JB_FS_AdjustLength_( fs, 8, (int)(wp - wpStart) );
	}
    
    FS_CheckLast(fs);
}


void JB_FS_AppendMultiReplace(FastString* self, JB_String* Data, Dictionary* MSR, JB_ErrorReceiver* Rec) {
	if ( MSR and Data ) {
		JB_MSR_ReplaceAll( MSR, Data, self, Rec );
	} else {
		JB_FS_AppendString( self, Data );
	}
}


void JB_FS_AppendLower(FastString* fs, JB_String* Data) {
    JB_FS_AppendByteMap(fs, Data, JB_BM__Lower());
}


void JB_FS_AppendByteMap(FastString* fs, JB_String* Data, ByteMap* BM) {
	if ( !BM or !Data ) {
		return;
	}

	int Length = Data->Length;
	u8* wp = JB_FS_WriteAlloc_(fs, Length);
	if ( ! wp ) {
		return;
	}
	u8* SelfPos = Data->Addr;
	u8* map = BM->Cache;

	while ( Length-- > 0 ) {
		*wp++ = map[ *SelfPos++ ];
	}
    FS_CheckLast(fs);
}


void JB_FS_AppendReplaceB(FastString* self, JB_String* Data, int From, int To) {
	JB_Str_ReplaceBytesSub_( Data, From, To, self );
}


void JB_FS_AppendHexData( FastString* fs, u8* Addr, int Len ) {
	require0(Len >= 1);
	u8* wp = JB_FS_WriteAlloc_(fs, Len * 2);
    if (!wp) { return; }

    const int CharMap = 'a';
	while (Len-- >= 1) {
        u8 C = *Addr++;
        *wp++ = CharMap + (C>>4);
        *wp++ = CharMap + (C&15);
	}
    FS_CheckLast(fs);
}


void JB_Str_UnHexRaw(JB_String* Str, u8* Write, int N) {
    // So... two bytes of this, become 1 of the other...
    // Might as well just use a normal stuff, don't even need charmap....
    int SrcLength = JB_Str_Length(Str);
    if (SrcLength < N*2) {
        memzero(Write, N); // may as well...
        return;
    }
    
    u8* Addr = Str->Addr;

	while (N-- >= 1) {
        u8 C1 = *Addr++ - 'a';
        u8 C2 = *Addr++ - 'a';
        *Write++ = (C1 << 4) | (C2 & 15);
	} 
}

// "2 000 000 000" is 10 int!

u8* JB__WriteIntToBuffer (u8* wp, int64 LeftOver) {
    do {
        int64 NewLeftOver = LeftOver / 10;
        int64 ThisChar = LeftOver - (NewLeftOver * 10) + '0';
        *--wp = (u8)ThisChar;
        LeftOver = NewLeftOver;
    } while (LeftOver);
    return wp;
}


void JB_FS_AppendIntegerAsText(FastString* self, int64 LeftOver, int RoundTo) {
	if (RoundTo <= 0) {RoundTo = 1;} else if (RoundTo > 16) {RoundTo = 16;}
     
	if (!LeftOver) {
		JB_FS_AppendMultiByte( self, '0', RoundTo ); return;
	}

	u8* wp = JB_FS_WriteAlloc_( self, 16 );

	if ( !wp ) {
        return;
    }
    int SignLen = 0; // can remove signlen and just put PadCount here...
    
    if (LeftOver < 0) {
        *wp++ = '-';
        LeftOver = -LeftOver;
        if (LeftOver <= 0) { return; } // PPC oddity
        SignLen = 1;
    }

    double tmpCount = log10( (double)LeftOver ); // all math lib funcs are DAMN fast.
    dbgexpect( tmpCount >= 0 and tmpCount <= 19 );
    int CountDigits = (int)tmpCount + 1;
    int PadCount = (CountDigits + SignLen) % RoundTo;
    if (PadCount) PadCount = RoundTo - PadCount;
    int PadFirst = PadCount;

    wp = wp + CountDigits + PadCount;
    wp = JB__WriteIntToBuffer(wp, LeftOver);

    while ( PadCount-- ) {
        *--wp = '0';
    }
    
    JB_FS_AdjustLength_( self, 16, CountDigits + PadFirst + SignLen );
}


void JB_FS_AppendDate(FastString* self, Date D) {
    JB_FS_AppendDoubleAsText(self, ((double)D) / 0x10000, (u8*)"%.3g");
    // maybe convert to a double and render it?
}


void JB_FS_AppendDoubleAsText0(FastString* self, double D) {
    JB_FS_AppendDoubleAsText(self, D, 0);
}


void JB_FS_AppendDoubleAsText(FastString* self, double D, u8* fmt) {
    const int Max = 64;
    if (!fmt) {
        fmt = (u8*)"%g";
    }
	u8* wp = JB_FS_WriteAlloc_( self, Max );
    int Used = snprintf((char*)wp, Max, (const char*)fmt, D);
    JB_FS_AdjustLength_( self, Max, Min(Used, Max) );
}


void JB_FS_AppendShort(FastString* self, int s) {
	short* wp = (short*)JB_FS_WriteAlloc_( self, 2 );
	if (wp) {
		*wp = (short)s;
	}
	FS_SanityCheck_(self);
}


// can’t share Appendint, due to float passing conventions :o(   )
void JB_FS_AppendSingle(FastString* self, float f) {
	float* fp = (float*)JB_FS_WriteAlloc_( self, 4 );
	if (fp) {
		*fp = f;
	}
	FS_SanityCheck_(self);
}


void JB_FS_AppendInteger(FastString* self, int l) {
	int* wp = (int*)JB_FS_WriteAlloc_Inline_( self, 4 );
	if (wp) {
		*wp = l;
	}
	FS_SanityCheck_(self);
}


void JB_FS_AppendDouble(FastString* self, double d) {
	double* fp = (double*)JB_FS_WriteAlloc_( self, 8 );
	if (fp) {
		*fp = d;
	}
	FS_SanityCheck_(self);
}


void CleanUTF8_(FastString* self, u32 Code) {
    if (Code >= 0x80) {
        Code = '?'; // can’t uncorrect it!
    }
    u8* SelfPos = self->ResultPtr;
    u8* SelfEnd = SelfPos + self->Length;
    
    while (SelfPos < SelfEnd) {
        u8 FirstChar = *SelfPos++;
        
        if (FirstChar >= 0x80) {
            u8* PrevPos = SelfPos - 1;
            SelfPos = LegalUTF8_(FirstChar, SelfPos);
            if ( SelfPos > SelfEnd  or !SelfPos ) {
                SelfPos = PrevPos;
                *SelfPos++ = (u8)Code;
            }
        }
    }
}



               /* Utilities */

JB_String* JB_FS_GetResult(FastString* self) {
	int Length = self->Length;
	FS_SanityCheck_(self);

	if ( Length == 0 ) {
		JB_FS_Destructor( self );
		return JB_Str_Empty();
	}

#if AS_LIBRARY
    Length++;
#endif
	JB_String* Result = JB_Str_Realloc(&self->Result, Length);

#if AS_LIBRARY
    if (Result) {
        Result->Addr[--Length] = 0; // zero-terminate, make life easier for c-folks
        Result->Length = Length;
    }
#endif

    self->Result = 0;
    JB_SafeDecr(Result);

    ClearFS_(self);

	return Result;
}



int JB_FS_Byte(FastString* fs, int offset) {
	offset--;
	if (offset <= -1) { // handy :)
		offset = fs->Length + offset;
	}
	if ((u32)offset < fs->Reserved) {
		return fs->ResultPtr[offset];
	}
	return -1;
}



               /* Properties */

int JB_FS_BufferSize(FastString* fs) {
	FS_SanityCheck_(fs);
	return fs->Reserved;
}


void JB_FS_SizeSet(FastString* fs, int NewSize) {
	if (NewSize < 1) {
		JB_FS_Destructor( fs );
	} else {
		JB_FS_ResizeTo_( fs, NewSize );
	}
}


int JB_FS_Length(FastString* self) {
	FS_SanityCheck_(self);
	return self->Length;
}


void JB_FS_LengthSet(FastString* fs, int NewLength) {
    if ((u32)NewLength < (u32)fs->Length) {
        fs->Length = NewLength;
    }
	FS_SanityCheck_(fs);
}


#ifndef AS_LIBRARY
bool JB_FS_Flush(FastString* fs) {
    JB_File* File = fs->File;
    if ( File ) {
        int N = fs->Length;
        if ( N ) {
            N = (int)JB_File_WriteRaw_( File, fs->ResultPtr, N );
            fs->WrittenLength += N;
            fs->Length = 0;
            return true;
        }
    }
    return false;
}

JB_File* JB_FS_File(FastString* fs) {
    return fs->File;
}

void JB_FS_FileSet(FastString* fs, JB_File* F) {
    JB_SetRef( fs->File, F );
    if (!F->FileDes) {
        JB_File_OpenBlank(F);
    }
}
#else
    bool JB_FS_Flush(FastString* fs) {return false;}
#endif


            /* Constructors */

void JB_FS_ConstructorSize(FastString* self, int Size) {
    JB_FS_Constructor(self);
	if ( Size ) {
		JB_FS_SizeSet( self, Size );
	}
}

void JB_FS_Constructor(FastString* self) {
    JB_Zero(self);
    self->IndentChar = '\t';
    self->IndentMul = 1;
}

void JB_FS_Destructor(FastString* self) {
    JB_FS_Flush( self );
	ClearFS_( self );
}

FastString* JB_FS__InternalNew() {
    FastString* fs = JB_New(FastString);
    JB_FS_Constructor( fs );
    return fs;
}

FastString* JB_FS__FastNew(FastString* other) {
    if (other) {
        return other;
    }
    
	static FastString* fs;
    
	if ( !fs or (JB_RefCount(fs) > 1)) {
        JB_SetRef(fs, JB_New(FastString));
        JB_FS_Constructor( fs );
    } else {
        fs->Length = 0;
    }
    
    return fs;
}



} // 


