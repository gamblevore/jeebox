
// Copyright, Theodore H. Smith 2019.
// Released under jeebox-licence http://jeebox.org/licence.txt


        void JB_DebugPrint(JB_Object* self);

/*
 		Unicode Ranges:

		// Functions that appreciate unicode numbers!
These must be unified in appreciation of the numbers, or chaos will bomb us!

  JB_Str_UTF8Size
  u8Write_
  JB_Str_UniValid
  c32to8_ etc etc


Table 3.1B. Legal UTF-8 Byte Sequences
 Code Points		1st Byte	2nd Byte	3rd Byte	4th Byte
U+0000..U+007F		00..7F	 	 	 
U+0080..U+07FF		C2..DF		80..BF 	 	 
U+0800..U+0FFF		E0			A0..BF		80..BF 	 
U+1000..U+CFFF		E1..EC		80..BF		80..BF 	 
U+D000..U+D7FF		ED			80..9F		80..BF 	 
U+D800..U+DFFF		ill-formed
U+E000..U+FFFF		EE..EF		80..BF		80..BF 	 
U+10000..U+3FFFF	F0			90..BF		80..BF		80..BF
U+40000..U+FFFFF	F1..F3		80..BF		80..BF		80..BF
U+100000..U+10FFFF	F4			80..8F		80..BF	 	80..BF

*/



//typedef int (*UTFConvFunc)(u8* source, int Len, JB_String** e);
//
//// [cols][rows]!
//UTFConvFunc UTFConvTable[3][3] = {
//	{0,			cLto8_,		cLto16_		},
//	{c8toL_,	0,			c8to16_		},
//	{c16toL_,	c16to8_,	0,			},
//};
//

inline u8* u8Read( u8* source, u32* pch ) {
	u32 ch = *source++;
    
	if (ch >= 0x80) {
        u32 ch0 = ch;
        ch <<= 6;
        ch += *source++;
		if (ch0 <= 0xDF) {
			ch -= 0x00003080;
            
		} else {
            ch <<= 6;
            ch += *source++;
            if (ch0 <= 0xEF) {
                ch -= 0x000E2080;
                
            } else {
                ch <<= 6;
                ch += *source++;
                ch -= 0x03C82080;
            }
        }
        
	}
    
    *pch = ch;
    return source;
}



u8* u8Write_( u8* target, u32 ch ) {
	if (ch < 0x80) {
		*target++ = (u8)ch;

	} else {
        
		if (ch < 0x800) {
            *target++ = (u8)( (ch >> 6) | 0xC0 );

		} else {
            if (ch < 0x10000) {
                *target++ = (u8)( (ch >> 12) | 0xE0 );
                
            } else {
                *target++ = (u8)( (ch >> 18) | 0xF0 );
                *target++ = (u8)( ((ch >> 12) | byteMark) & byteMask );
            }
            *target++ = (u8)( (ch >> 6  | byteMark) & byteMask );
        }
        *target++ = (u8)( (ch >> 0  | byteMark) & byteMask );
	}

	return target;
}




inline u16* u16Read( u16* source, u32* ch ) {
	*ch = *source++;
	if (*ch >= UNI_SUR_HIGH_START and *ch <= UNI_SUR_HIGH_END) {
		u32 ch2 = *source++;
        *ch = ((*ch - UNI_SUR_HIGH_START) << halfShift) + (ch2 - UNI_SUR_LOW_START) + halfBase;
	}
	return source;
}

inline u16* u16Write( u16* target, u32 ch ) {
	if (ch <= UNI_MAX_BMP) {	/* Target is a character <= 0xFFFF */
	    *target++ = (u16)ch;	/* normal case */
	} else {					/* target is a character in range 0xFFFF - 0x10FFFF. */
		ch -= halfBase;
		*target++ = (u16)((ch >> halfShift) + UNI_SUR_HIGH_START);
		*target++ = (u16)((ch & halfMask) + UNI_SUR_LOW_START);
	}
	return target;
}


/*
 * Index into the table below with the first byte of a UTF-8 sequence to
 * get the number of trailing bytes that are supposed to follow it.
 */

int c16to8_(u8* pSource, int Len, JB_String** ep) {
	Len = Len &~ 0x01; // align to 2, by clearing the 1 value
    JB_String* e = JB_Str_Realloc( ep, Len*2 );
	if ( e ) { // potentially 1.5x as long! but lets just do 2x
		u8* targetStart = e->Addr;
		u8* target = targetStart;
		u16* source = (u16*)pSource;
		u16* sourceEnd = (u16*)(pSource + Len );
		u32 ch;

		while (source < sourceEnd) {
			source = u16Read( source, &ch );
			target = u8Write_( target, ch );
		}
		int written = (int)((u8*)target - targetStart);
		return written;
	}
	return 0;
}


int c8to16_(u8* source, int Len, JB_String** ep) {
    JB_String* e = JB_Str_Realloc( ep, 2+(Len*2) );
	if ( e ) {
		u8* targetStart = e->Addr;
		u16* target = (u16*)targetStart;
		u8* sourceEnd = source + Len;
		u32 ch;
		
		while (source < sourceEnd) {
			source = u8Read( source, &ch );
			target = u16Write( target, ch );
		}
		return (int)((u8*)target - targetStart);
	}
	return 0;
}
//
//// latin1 can’t hold all the range. So, we will not totally ruin the data, just "clip"
//// the chars like we clip sounds. This means it can’t do a few more opts, but whatever!!
//int c8toL_(u8* source, int Len, JB_String** ep) {
//    JB_String* e = JB_Str_Realloc( ep, Len );
//	if ( e ) { // can’t be longer!
//		u8* target = e->Addr;
//		u8* targetStart = target;
//		u8* sourceEnd = source + Len;
//		while (source < sourceEnd) {
//			u32 ch;
//			source = u8Read(source, &ch);
//			*target++ = (u8)ch;
//		}
//		return ( target - targetStart );
//	}
//
//	return 0;
//}
//
//int cLto8_(u8* source, int Len, JB_String** ep) {
//    JB_String* e = JB_Str_Realloc( ep, Len*2 );
//	if ( e ) { // maybe 2x longer!
//		u8* target = e->Addr;
//		u8* targetStart = target;
//		u8* sourceEnd = source + Len;
//		
//		while (source < sourceEnd) {
//			target = u8Write_( target, *source++ );
//		}
//		return target - targetStart;
//	}
//	return 0;
//}



//
//int c16toL_(u8* pSource, int Len, JB_String** ep) {
//	Len = Len &~ 0x01; // squip the last byte off if its not 2 aligned.
//	int newLen = Len/2;
//    JB_String* e = JB_Str_Realloc( ep, newLen );
//	if ( e ) {
//		u16* sr16 = (u16*)pSource;
//		u16* sEnd = (u16*)(pSource+Len);
//		u8* target = e->Addr;
//		for ( ; sr16 < sEnd; sr16++ ) {
//			*target++ = (u8)(*sr16);
//		};
//		return (int)newLen;
//	}
//	return 0;
//}
//
////
//
//int cLto16_(u8* source, int Len, JB_String** ep) {
//	int newLen = Len*2;
//    JB_String* e = JB_Str_Realloc( ep, newLen );
//	if ( e ) {
//		u8* sEnd = source+Len;
//		u16* target = (u16*)e->Addr;
//		for ( ; source < sEnd; source++ ) {
//			*target++ = (u16)(*source);
//		};
//		return (int)newLen;
//	}
//	return 0;
//}

/* --------------------------------------------------------------------- */


// returns 0 if it fails! source point to the 2nd byte of the UTF8!
u8* LegalUTF8_(u8 FirstChar, u8* source) {
	if (FirstChar < 0xC2 or FirstChar > 0xF4) {
		return 0; // dissallows ASCII! No point calling this on ASCII!
	}
	u32 ch = FirstChar;
	u32 offset;
	u8 a = *source++;
	switch (FirstChar) {    /* no fall-through in this inner switch */
	    case 0xE0: if (a < 0xA0) return 0; break;
	    case 0xF0: if (a < 0x90) return 0; break;
	    case 0xF4: if (a > 0x8F) return 0; break;
	}
	
	if (ch <= 0xDF) {
		offset = 0x00003080;
		goto case2; // this goto remains from old code I copied and didn't have time to fully clean up.
	} else if (ch <= 0xEF) {
		offset = 0x000E2080;
		goto case3;
	} else { // case 4
		offset = 0x03C82080;
	}

	ch <<= 6; ch += a;
	if (a < 0x80 or a > 0xBF) {
		return 0;
	}
	a = *source++;

	case3:;	ch <<= 6; ch += a;
	if (a < 0x80 or a > 0xBF) {
		return 0;
	}
	a = *source++;

	case2:;	ch <<= 6; ch += a;
	if (a < 0x80 or a > 0xBF) {
		return 0;
	}
	
	if (JB_Str_UniValid(ch-offset)) {
		return source;
	}
	return 0;
}



// 3 functions for interconverting character and bytes! It's a lot of processing
// so actually, the user is best off not passing chars, but bytes instead. These
// are really just utility functions, IE functions for processes that don't need
// performance! These functions shouldn't break the String splitting theorem, of
// alowing exces ranges in params,but only keeping what of the range does exist.


// kUTF8FirstMin is a special trick to test for a UTF8 starter, in 1 test, instead of 2



//// 1 based! Returns 1 based result
//int RevByteCount_(u8* a, int Len, int CharCount) {
//	if ( (Len <= 0) or (CharCount <= 0) ) {
//		return 0;
//	}
//
//	s8* s = (s8*)a + Len;
//	s8* sEnd = s;
//	int lCount = 0;
//	for (int ToDo = Len; ToDo > 0; ToDo--) {
//		if ( *(--s) >= kUTF8FirstMin ) {
//			if ( ++lCount >= CharCount ) { // we have the correct pos!
//				return sEnd - s;
//			}
//		}
//	}
//
//	return Len; // the whole thing?
//}


// param and return is 1 based!
//int ByteCount_(u8* a, int Len, int CharCount) {
//	if (CharCount <= 0) {
//		return 0;
//	}
//
//	s8* s = (s8*)a;
//	int Count = 0;
//	for (int n = Len; n > 0; n--) {
//		if ( *s++ >= kUTF8FirstMin ) {
//			Count++;
//		 	if ( Count > CharCount ) {
//				return ((u8*)s - a) - 1;
//			}
//		}
//	}
//
//	if (Count == CharCount) {
//		return Len;
//	}
//	return Len + 1;
//}

int u8Count_(u8* a, int Len) {
	s8* s = (s8*)a;	
	int cCount = 0;
	while (Len-- > 0) {
		if ( *s++ >= kUTF8FirstMin ) {
			cCount++;
		}
	}
	return cCount;
}

u32 JB_Str_UTF8Size( u32 c ) {
	if (c < 0x80) { // common case first!
		return 1;
	} else if (c <= UNI_MAX_2BYTES) {
		return 2;
	} else if (c < 0xFFFE) {
		if (c >= UNI_SUR_HIGH_START and c <= UNI_SUR_LOW_END) {
			return 0;
		}
		return 3;
	} else if (c == 0xFFFE or c == 0xFFFF) {
		return 0;
	} else if (c <= UNI_MAX_UTF) { // logically can only be this now!
		return 4;
	}
	return 0;
}

u32 u8Size_( u8 FirstChar ) {
	if (FirstChar < 0x80) return 1;
	if (FirstChar <= 0xDF) return 2;
	if (FirstChar <= 0xEF) return 3;
	return 4;
}


// Tells us how many bytes on the end of the UTF8 are not a complete byte
int JB_Str_Scan_BadUTF8AtEnd(JB_String* u) {
	int Len = u->Length;
	if ( Len ) {
        s8* Last = (s8*)u->Addr + Len;
        int LastCharLen = 0;

        while (LastCharLen < Len) {
            s8 c = *(--Last);
            LastCharLen++;  // we found it...
            if (c >= kUTF8FirstMin) {
                return u8Size_((u8)c) - LastCharLen;
            }
        }
	}

    return Len;
}


//
//JB_String* JB_Str_ConvertToUTF8(JB_String* self, int FlagsFrom) {
//	return JB_Str_ConvertTo( self, FlagsFrom, kEncUTF8 + kEncBE );
//}
//
//
//
//// Purpose: Convert the data from 1 enc to another, as fast as possible, saving as much RAM as possible.
//// this means it needs some intelligence, hence all the stuff it handles.
//// Manages: Endian conversion, conversion extra buffer management, shortcuts, bad params, BOMs
//
//JB_String* JB_Str_ConvertTo( JB_String* ud, int FlagsFrom, int FlagsTo ) {
//	
//	// *** REJECT BAD INPUT ***
//    if ((FlagsTo|FlagsFrom) &~ (8+16+1)) { // only convert 8/16BE/16LE/latin-1
//        return 0;
//    }
//	
//	
//	// *** DETECT "FROM" FORMAT ***
//    u8* source = ud->Addr;
//    int Len = ud->Length;
//	int EncSize = ReadBOM_(source, Len, &FlagsFrom);
//    source += EncSize;
//    Len -= EncSize;
//	if (Len <= 0) {
//		return JB_Str_Empty();
//	}
//
//
//
//    // *** NORMALISE UTF/BE FROM/TO ***
//    if ( FlagsTo <= kEncUTF8_BE ) {
//        FlagsTo &= ~kEncBE; // strip out endian... we know what we mean!!
//    }
//    if ( FlagsFrom <= kEncUTF8_BE ) {
//        FlagsFrom &= ~kEncBE;
//    }
//
//	
//	if (  FlagsFrom <= 8  and  IsAsciiSub_( source, Len ) ) { // we got ascii
//		FlagsFrom = 0; // pretend we convert from latin-1
//		if ( FlagsTo == 8 ) {
//			FlagsTo = 0; // pretend we convert to latin-1
//		}
//	}
//	
//
//
//	// *** MATCH! FAST RETURN ***
//    if (FlagsFrom == FlagsTo) {
//        return JB_Str_Range( ud, EncSize, kMaxint );
//    }
//	if ( (FlagsTo xor FlagsFrom) == kEncBE ) { // utf-16 by now, endian mismatch.
//		return Swap_( source, Len, ud );
//    }
//    
//    
//    
//    // *** ALLOCATE ***
//    JB_String* result = JB_Str_New(Len);
//    if (!result) {
//        return 0;
//    }
//    JB_Incr(result);
//
//    
//    // *** SWAP IF NOT PLATFORM ENDIAN ***
//	JB_String* swap = 0;
//	if ( FlagsFrom == kWrongUTF16 ) {
//		swap = Swap_( source, Len, ud );
//        if ( ! swap ) {return 0;}
//		source = swap->Addr;
//        JB_Incr(swap);
//	}
//
//    
//    // *** CONVERT ***
//	// [cols][rows]!
//    UTFConvFunc fConv = UTFConvTable[ FlagsFrom / 8 ][ FlagsTo / 8 ];
//    int ConvLen = fConv( source, (int)Len, &result );
//
//    if ( ConvLen ) {
//        JB_Str_Realloc( &result, ConvLen );
//        if ( FlagsTo == kWrongUTF16 ) {
//            SwapM_( result );
//        }
//    } else {
//        JB_ClearRef( result ); // a memory error occured because we definitely had a length at the start!
//    }
//	JB_ClearRef( swap );
//
//	// *** END CONV! ***
//
//    JB_SafeDecr(result);
//	return result;
//}
//
//





///// base64... sigh.

static const u8 EscapeTable_[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz._";

void JB_FS_AppendHexSub(FastString* fs, int64 tVal, int RoundTo, const u8* CharMap);
void JB_FS_AppendHexData( FastString* fs, u8* Addr, int Len );

void JB_FS_AppendHex(FastString* fs, int64 tVal, int RoundTo) {
    JB_FS_AppendHexSub(fs, tVal, RoundTo, EscapeTable_);
}

void JB_FS_AppendHexStr( FastString* fs, JB_String* Data ) {
	if (Data) {
        JB_FS_AppendHexData(fs, Data->Addr, Data->Length);
    }
}


// JB_FS_AppendHexSub


void JB_FS_AppendHex3(FastString* fs, int tVal) {
    JB_FS_AppendHexSub(fs, tVal, 1, EscapeTable_ + 10);
}





const u8* DecodeTable_() {
    static u8* T = 0;
    if (!T) {
        T = (u8*)JB_zalloc(256);
        if (T) {
            memset(T, 255, 256);
            for (int i = 0; i < 64; i++) {
                T[EscapeTable_[i]] = i;
            }
        }
    }
    return T;
}

static inline u8 SafeEnc_(const u8*& Read, const u8* End) {
    if (Read < End) {
        return *Read++;
    }
    return 0;
}


JB_String* JB_Str_EncodeBinary(JB_String* self, FastString* fs_in) {
    FastString* fs = JB_FS__FastNew(fs_in);
    const u8* in = JB_Str_Address(self);
    int N = JB_Str_Length(self);
    const u8* end = in + N;
    int WriteLength = 4 * ((N + 2) / 3);                /* 3-byte blocks to 4-byte */
    u8* Pos = JB_FS_WriteAlloc_(fs, WriteLength);
    require(Pos);

    const u8* T = EscapeTable_;
    while (end - in >= 1) {
        u8 c0 = SafeEnc_(in, end);
        u8 c1 = SafeEnc_(in, end);
        u8 c2 = SafeEnc_(in, end);
        *Pos++ = T[c0 >> 2];
        *Pos++ = T[((c0 & 0x03) << 4) | (c1 >> 4)];
        *Pos++ = T[((c1 & 0x0f) << 2) | (c2 >> 6)];
        *Pos++ = T[c2 & 0x3f];
    }

    N = N % 3;
    if (N) {
        fs->Length -= (3-N);
    }
    return JB_FS_SmartResult(fs, fs_in);
}



static u8 SafeDec_(const u8*& Read, const u8* End,  const u8* T) {
    while (Read < End) {
        u8 C = T[*Read++];
        if (C < 64) {
            return C;
        }
    }
    Read++; // mark it...
    return 0;
}


JB_String* JB_Str_DecodeBinary(JB_String* self, FastString* fs_in) {
    const u8* T = DecodeTable_();    // go handle whitespace and stuff...
    require(T);
    FastString* fs = JB_FS__FastNew(fs_in);
    const u8* r = JB_Str_Address(self);
    int L = JB_Str_Length(self);
    u8* j = JB_FS_WriteAlloc_(fs, ((L + 3) / 4) * 3);
    require(j);
    
    const u8* End = r + L;
    
    while (r < End) {
        u32 
        C  = SafeDec_(r, End, T) << 18;
        C |= SafeDec_(r, End, T) << 12;
        C |= SafeDec_(r, End, T) << 6;
        C |= SafeDec_(r, End, T) << 0;
        *j++ = C >> 16;
        *j++ = C >> 8 & 0xFF;
        *j++ = C & 0xFF;
    }

    while (r-- > End) {
        j--;
    }
    fs->Length = (int)(j - fs->ResultPtr);

    return JB_FS_SmartResult(fs, fs_in);
}

    
JB_String* JB_Str_EncodeB64(JB_String* self, FastString* fs_in) {
    return JB_Str_EncodeBinary(self, fs_in);
}


JB_String* JB_Str_DecodeB64(JB_String* self, FastString* fs_in) {
    return JB_Str_DecodeBinary(self, fs_in);
}

