
// Copyright, Theodore H. Smith 2019.
// Released under jeebox-licence http://jeebox.org/licence.txt






inline u8* u8Pos( MiniStr S, u8 TheChar ) {
	while (	S ) {
		if (S.Next() == TheChar) {
			return S;
		}
	}
	return 0;
}

inline u8* u8NPos( MiniStr S, u8 TheChar ) {
	while (	S ) {
		if (S.Next() != TheChar) {
			return S;
		}
	}
	return 0;
}


inline MiniStr Theo2Pos( MiniStr S, u8 Find1, u8 Find2 ) {
    u32 Read1 = S.Next();
    while (	S ) {
        u32 Read2 = S.Next();
        if (Read1 == Find1 and Read2 == Find2) {
            S.Addr--;
            return S;
        }
        Read1 = Read2;
    }
    return {0,0};
}



inline MiniStr Theo2PosLex( MiniStr S, u8 Find1, u8 Find2 ) {
    u32 Read1 = S.NextLower();
    while (	S ) {
        u32 Read2 = S.NextLower();
        if (Read1 == Find1 and Read2 == Find2) {
            S.Addr--;
            return S;
        }
        Read1 = Read2;
    }
    return {0,0};
}


u8* SearchForward_( MiniStr S, MiniStr F, bool Lex ) {
    if (!F) {
        return 0;
    }

    u32 FirstChar = F.Next();
    if (!F) {
        return u8Pos( S, FirstChar );
    }
    u32 SecondChar = F.Next();
    
	if (!Lex) {
        do {
            S = Theo2Pos( S, FirstChar, SecondChar );
            if (!S.Addr) {
                return 0;
            }
            if (OffsetEquals_( S.Addr + 1, F )) {
                return S.Addr;
            }
        } while (S);
		
	} else {
        SecondChar = LowerCaseB(SecondChar);
        FirstChar = LowerCaseB(FirstChar);
        do {
            S = Theo2PosLex( S, FirstChar, SecondChar );
            if (!S.Addr) {
                return 0;
            }
            if (OffsetEqualsLex( S.Addr + 1, F )) {
                return S.Addr;
            }
        } while (S);
	}

    return 0;
}



inline bool OffsetEquals_( u8* S, MiniStr F ) {
	// you need to compare the length before calling this function!

	if (S != F.Addr) {
		while (F) {
			if (F.Next() != *S++) {
				return false;
			}
		}
	}

	return true;
}

bool StrEquals( MiniStr S, MiniStr F ) {
	return (S.Length == F.Length) and OffsetEquals_( S.Addr, F );
}


bool OffsetEqualsLex( u8* S, MiniStr F ) {
// you need to compare the length before calling this function!
	if (S != F.Addr) {
		while (F) {
			if (F.NextLower() != LowerCaseB(*S++)) {
				return false;
			}
		}
	}
	return true;
}

bool StrEqualsLex( MiniStr S, MiniStr F ) {
    return (S.Length == F.Length) and OffsetEqualsLex( S.Addr, F );
}


int JB_Str_DiffAt( JB_String* S, JB_String* F ) {
    return StrDiffAt( Mini(S), Mini(F) );
}

int StrDiffAt( MiniStr S, MiniStr F ) {
    u8* bS = S;
    u8* bF = F;
    int N = Min(S.Length, F.Length);

    for (int C = 0;  C < N;  C++) {
        if (*bS++ != *bF++) {
            return C + 1;
        }
    }
    
    if (S.Length != F.Length) {
        return -(N + 1);
    }
    
    return 0;
}

inline int OffsetCompare_( MiniStr S, MiniStr F ) {
	int UseLen = Min( S.Length, F.Length );
	
	if (S.Addr != F.Addr) {
		while (UseLen-- > 0) {
			u8 fChar = F.Next();
			u8 sChar = S.Next();
			if (fChar == sChar) {
				; //
			} else if (fChar < sChar) {
				return 1;
			} else {
				return -1;
			}
		}
	}
	
	if ( S.Length > F.Length ) {
		return 1; // should work?
	} else if ( S.Length < F.Length ) {
		return -1;
	}
	return 0;
}


int OffsetCompareLex( MiniStr S_, MiniStr F_ ) {
    MiniStr S = S_;
    MiniStr F = F_;
	int UseLen = Min(S.Length, F.Length);

	if (S.Addr != F.Addr) {
		while (UseLen-- > 0) {
			u8 fChar = F.NextLower();
			u8 sChar = S.NextLower();
			if (fChar == sChar) {
				; //
			} else if (fChar < sChar) {
				return 1;
			} else {
				return -1;
			}
		}
	}

	return OffsetCompare_( S_, F_ );
}

bool JB_Str_Equals(JB_String* self, JB_String* find, bool Lexer) {
    int S = JB_Str_Length(self);
    int F = JB_Str_Length(find);
	if ( !S or !F ) {
		return S == F;
	}

	if ( ! Lexer ) {
		return StrEquals( Mini(self), Mini(find) );
	} else {
		return StrEqualsLex( Mini(self), Mini(find) );
	}
}


int JB_Str_Compare(JB_String* self, JB_String* Find, bool Lexer) {
	if (!Find or !self) {
        if (self < Find) {return -1;}
        bool b = self;
        return (int)b;
	} else if ( ! Lexer ) {
		return OffsetCompare_( Mini(self), Mini(Find) );
	} else {
		return OffsetCompareLex( Mini(self), Mini(Find) );
	}
}




	// Interfaces

bool JB_Str_MidEquals(JB_String* self, int BeginOff, JB_String* find, bool Lexer) {
	if (!find) {
		return false;
	}

	MiniStr S = ReadAddrs_( self,  BeginOff,  BeginOff + find->Length );
	if ( Lexer ) {
		return StrEqualsLex( Mini(find), S );
	} else {
		return StrEquals( Mini(find), S );
	}
}


#include <string.h>
// Move0 Mod0  1234 5678
// Move3 Mod1   123 4567 8
// Move2 Mod2    12 3456 78
// Move1 Mod3     1 2345 678

bool IsAsciiSub_(u8* SelfPos, u32 Length) {
	u8* SelfEnd = SelfPos + Length; // must be done before I alter selfpos!

	while ( ((UintPtr)SelfPos % 4) and SelfPos < SelfEnd ) {
		if ( *SelfPos++ >= 0x80 ) {
			return false;
		}
	}
	
	while ( ((UintPtr)SelfEnd % 4) and SelfPos < SelfEnd ) {
		if ( *(--SelfEnd) >= 0x80 ) {
			return false;
		}
	}
	
	int TrimLength = (int)(SelfEnd - SelfPos) / 4;
	u32* intPos = (u32*)SelfPos;
	while ( TrimLength-- ) {
		if ( (*intPos++) & k4HighBits ) {
			return false;
		}
	}

	return true;
}





/*int JB_Str_InRevStr( JB_String* self, JB_String* Find, int BeginOff, int AfterOff, bool lex ) {
 // I want a simpler version of this! Something that makes more sense and does it mathematically...
 // like ONE string func written to go either way. And done sensibly... where...
 // its not bloated, but all the offsets and stuffs are adjusted to just work.
 // perhaps using defines or inlines and stuff to make it fast and just work.
 // for now.... jeebox doesn't need this!
}*/

int JB_Str_InStr( JB_String* self, JB_String* f, int BeginOff, int AfterOff, bool lex ) {
	if ( f and self ) {
        MiniStr S = ReadAddrs_( self, BeginOff, AfterOff );
        if ( S.Forward() ) {
            MiniStr F = Mini( f );
            int Dir = 1;
            return ResultFix_( SearchForward_( S, F, lex ), self, Dir );
        }
	}

	return -1;
}



int JB_Str_Byte( JB_String* self, int StartOff, int AfterOff, int SearchChar, bool Find ) {
	if (self) {
		MiniStr S = ReadAddrs_( self, StartOff, AfterOff );
		int Dir = S.Dir();
		
		while (	S ) {
			if ((S.Move(Dir) == SearchChar) == Find) {
				return ResultFix_(S, self, Dir);
			}
		}
	}
    
    return -1;
}


int JB_Str_InByte( JB_String* self, int StartOff, int AfterOff, int SearchChar ) {
    return JB_Str_Byte( self, StartOff, AfterOff, SearchChar, true );
}


int JB_Str_OutByte( JB_String* self, int StartOff, int AfterOff, int SearchChar ) {
    return JB_Str_Byte( self, StartOff, AfterOff, SearchChar, false );
}

//
//int JB_Str_UTF8Value(JB_String* self, int Offset) {
//	u8* Source = self->Addr;
//	u8* Read = Source;
//	int Len = self->Length;
//
//// Need to compare if the len < than the read len! if so, return 0xffffffff
//	if (Offset < 0 or Len <= 0) {
//		return UNI_BADOFFSET;
//
//	} else if (Offset > 0) {
//		Offset = ByteCount_( Source, Len, Offset );
//		Read += Offset;
//	}
//
//	u32 Result;
//	u8* SourceEnd = u8Read( Read, &Result );
//	int ReadLen = SourceEnd - Source;
//	if (ReadLen <= Len) {
//		return (int)Result;
//	}
//
//	return UNI_BADOFFSET;
//}
//

int JB_Str_ByteValue(JB_String* self, int offset) {
    if (self) { // should be taken out once nil detection exists.
        if ((u32)offset < (u32)self->Length) {
            return (int) (self->Addr[offset]) ;

        } else if (offset < 0) {
            offset = self->Length + offset;
            if ((u32)offset < (u32)self->Length) {
                return (int) (self->Addr[offset]) ;
            }
        }
    }

    return UNI_BADOFFSET;
}



#define kParseEnd_Dot 1
#define kParseEnd_E 2
#define kParseEnd_Both 3

void JB_Err__CantParseNum(Message* Where, JB_String* self, int Pos);
void ParseNumErr_( JB_String* self, u8* BadPos, Message*& Where ) {
    require0(Where);
    
    int CharPos = (int)(BadPos - self->Addr - 1);
    JB_Err__CantParseNum(Where, self, CharPos);
    
    Where = nil;
}


static double ParseDouble_(JB_String* Str, u8** ReadPlaceOut, u8* ReadEnd, bool IsFrac, Message*& Where, int Endable) {
	double Value = 0;
	double Mul = 10;
	double Div = 0.1;
	u8* Read = *ReadPlaceOut;

	while ( Read < ReadEnd ) {
		int ch = *Read++;
        if (ch != '_') {
            int c = ch - '0';
            if ((u32)c > 9) {
                if (ch == 'e' and Endable&kParseEnd_E) {
                    ; //
                } else if (ch == '.' and Endable&kParseEnd_Dot) {
                    ; //
                } else {
                    ParseNumErr_( Str, Read, Where );
                }
                break;
            };

            double num = (double)c;
            if ( IsFrac ) {
                Value = Value + num*Div;
                Div = Div * 0.1;
            } else {
                Value = Value*Mul + num;
            }
        }
	}

	*ReadPlaceOut = Read;
	return Value;
}


double JB_Str_TextDouble(JB_String* self, Message* Where) {
	int Length = JB_Str_Length(self);
	if (!Length) {
        return 0.0;
    }
	u8* ReadPlace = self->Addr;
	u8* ReadEnd = ReadPlace + Length;

	bool IsMinus = (ReadPlace[0] == '-');
	if (IsMinus) ReadPlace++;

	double Value = ParseDouble_( self, &ReadPlace, ReadEnd, false, Where, kParseEnd_Both );

	if (ReadPlace[-1] == '.') {
		Value += ParseDouble_( self, &ReadPlace, ReadEnd, true, Where, kParseEnd_E );
	}
	if (ReadPlace[-1] == 'e') {
		bool ExpMinus = (ReadPlace[0] == '-');
		if (ExpMinus) ReadPlace++;
		double Exp = ParseDouble_( self, &ReadPlace, ReadEnd, false, Where, 0 );
		if (ExpMinus) Exp = -Exp;
		Value = Value * pow(10, Exp);
	}
	
	if (IsMinus) { Value = -Value; }
	return Value;
}


static int64 ParseNumbers_( JB_String* self, int AsHex, Message* Where ) {
// assumes valid input
    require (JB_Str_Length(self));
    MiniStr S = {self->Length, self->Addr};

	bool IsMinus = (S.Curr() == '-');
	if (IsMinus) {
		S.Next();
	}

	int64 Value = 0;

	while ( S ) {
		int c = S.Next();

        if (AsHex) {
            if (AsHex == 2) {
                c = c - 'a';
                if ((u32)c >= 16) {goto BadPos;}
            } else {
                if ( c >= 'A' and c <= 'F' ) {
                    c = c - ('A' - 10); // makes A=10
                } else if ( c >= 'a' and c <= 'f' ) {
                    c = c - ('a' - 10); // makes a=10
                } else {
                    goto BadPos;
                }
            }
			Value = Value*16 + c;
        
        } else {
             if (c >= '0' and c <= '9') {
                c = c - '0';
                Value = Value*10 + c;
            } else if (c != '_') {
                BadPos:;
                ParseNumErr_(self, S.Addr, Where);
                break;
            }
        }
	}

	if (IsMinus) {
		Value = -Value;
	}
	return Value;
}



int64 JB_Str_TextInteger( JB_String* self) {
	return ParseNumbers_( self, 0, nil );
}

int64 JB_Str_HexInteger(JB_String* self) {
	return ParseNumbers_( self, 1, nil );
}

int64 JB_Str_HexInteger2(JB_String* self, Message* b) {
	return ParseNumbers_( self, 2, b );
}

int64 JB_Str_TextIntegerValid(JB_String* self, Message* b) {
	return ParseNumbers_( self, 0, b );
}

