
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

extern "C" {


u8* EntityRead_( FastString* fs, u8 FirstChar, u8* NextRead, u8* SelfEnd, JB_ErrorReceiver* Rec ) {
    u8* EntPos = NextRead;
	u32 EntityFound = 0;
	bool IsHex = true;

    if (FirstChar == '\\') { // "\$"
        ; //
    } else if ( *EntPos == 'x' ) {
        EntPos++;
    } else {
        IsHex = false;
    }

	while ( EntPos < SelfEnd ) {
		u32 ThisChar = (u32)(*EntPos++);
		
		if ( ThisChar <= '9' and ThisChar >= '0'  ) { // 0 - 9
			ThisChar = ThisChar - '0'; // Numeric

		} else if ( ThisChar <= 'F' and ThisChar >= 'A' ) { // A - F
			ThisChar = ThisChar - ('A' - 10); // makes A=10

		} else if ( ThisChar <= 'f' and ThisChar >= 'a' ) { // a - f
			ThisChar = ThisChar - ('a' - 10); // makes a=10

		} else if (FirstChar != '\\' and ThisChar == ';') { // End of ent!
            JB_FS_AppendUTF8Char( fs, EntityFound );
            return EntPos;

        } else {
            if (FirstChar == '\\' and (EntPos == NextRead+2)) {
                EntPos--;
                goto DoItAnyWay;
            }
            break; // ERROR
        }

		if (IsHex) {
			EntityFound = EntityFound*16 + ThisChar;
		} else {
			EntityFound = EntityFound*10 + ThisChar;
		}

        if (FirstChar=='\\' and ((EntPos == NextRead+2) or EntPos == SelfEnd)) { //    '\0'    too short, but we'll allow.
            DoItAnyWay:;
            JB_FS_AppendByte( fs, EntityFound );
            return EntPos;
        }
	}

    // failed... sigh. Really we should just create an error? How serious is this error, though. That's the issue.
    // Do we even WANT to trap it? Errors. What a mess.
    // maybe a warning?

    if (FirstChar != '\\') {
        JB_FS_AppendByte( fs, FirstChar );
    }
    
    return NextRead;
}



// I can't do entity validation properly here, because there are too many error conditions,
// and this class simply does not do validation. All it really needs to do, is parse
// correct conditions properly, and handle incorrect enities gracefully, not ruining the
// rest of the text that is valid.

//	>>>		>>>		>>>		>>>


JB_String* JB_MSR_ReplaceAll( Dictionary* Dict, JB_String* Data, FastString* fs_in, JB_ErrorReceiver* Rec ) {
    if (!Data) {
        return 0;
    }

	JB_String* EntityMarker = JB_Str_ChrB( '&' );
	
    u8* SearchStart = Data->Addr;
	u8* SearchEnd = SearchStart + Data->Length;
    FastString* fs = fs_in;
	
	do {
        MiniStr FoundStr;
        MiniStr Input = {SearchStart, (int)(SearchEnd - SearchStart)};
        JB_String* Found = (JB_String*)JB_Dict_Scan_(Dict, Input, &FoundStr);

        if (!fs) {
            if ( !Found ) {
                return Data;
            }
            fs = JB_FS__FastNew(fs_in);
        }

		JB_FS_AppendMem_( fs, SearchStart, (int)(FoundStr.Addr - SearchStart) );
		if ( ! Found ) { break; }
		
        SearchStart = FoundStr.Addr + FoundStr.Length;
		if ( Found != EntityMarker ) {
			JB_FS_AppendMem_( fs, Found->Addr, Found->Length );
		} else {
			SearchStart = EntityRead_( fs, *FoundStr.Addr, SearchStart, SearchEnd, Rec );
		}
	} while ( true );

	return JB_FS_SmartResult( fs, fs_in );
}
	//	>>>		>>>		>>>		>>>


		

// combiner stuff. Good for UTF-8 processing!!
// maybe don't add it? Is it worth it?
int JB_MSR_CombiningCode( Dictionary* self, JB_String* Data ) {
	if ( Data ) {
		Data = (JB_String*)JB_Dict_Value( self, Data );
		if (Data) {
			if (Data->Length) {
				return *Data->Addr;
			}
			return -1; // error, shouldn't have 0 length as a combiner!!
		}
	}
	return 0;
}





struct CharList {
	u8* Addr;
	u8 Length;
	u8 Score;
	CharList* Next;
};

inline CharList* CharNext_( CharList* C ) {
	return C->Next;
}

inline void CharNextSet_( CharList* C, CharList* N ) {
	C->Next = N;
}


CharList* ReorderArrays_( CharList* First ) {
	CharList* i = First;
	CharList Dummy;
	CharList* p = &Dummy;

	for ( ; i; i = CharNext_(i) ) {
		CharList* LowScore = i;
		CharList* pLow = i;
		CharList* j = CharNext_(i);

		for ( ; j; j = CharNext_(j) ) {
			if ( j->Score < LowScore->Score ) {
				LowScore = j;
			}
			pLow = j;
		}
		
		if (LowScore != i) { // should be more than i!!
			CharNextSet_( pLow, CharNext_(LowScore) );
			CharNextSet_( p, LowScore );
			CharNextSet_( LowScore, i );
			if (i == First) {
				First = LowScore;
			}
		}

		p = i;
	}
	
	return First;
}


u8* ReorderCombiners_( Dictionary* Dict, u8* Start, u8* ReadEnd, FastString* fs ) {
#define nChars 32
	CharList Chars[nChars]; // 32*12 == 384?
	CharList* CharsEnd = Chars + nChars - 1;
	CharList* Char = &Chars[0];
	u8 LastByte = 0;
	bool UnOrdered = false;

	while ( Char < CharsEnd ) {
		u8* MatchEnd;
        debugger;
        JB_Object* Value = 0; //JB_Dict_LongestKey_( Dict, Start, ReadEnd, &MatchEnd );
		if (!Value) {
			break;
		}
		JB_String* e = (JB_String*)( Value );
		u8 CurrByte = e->Addr[0];
		if (CurrByte < LastByte) {
			UnOrdered = true;
		}

		Char->Next = Char + 1; // set the prev's next!!
		
		Char = CharNext_( Char );
		Char->Score = CurrByte;
		Char->Length = (u8)(MatchEnd - Start);
		Char->Addr = Start;
		Char->Next = 0;
		
		Start = MatchEnd;	
	};
	
	if (UnOrdered == false) {
		return Start;
	}
	
	int fsl = fs->Length;
	JB_String* e = 0;
	JB_FS_AppendMem_( fs, e->Addr + fsl, (e->Length - fsl) );

	Char = &Chars[0];
	while (Char) {
		JB_FS_AppendMem_( fs, Char->Addr, Char->Length );
		Char = CharNext_( Char );
	}

	return 0;
}

JB_String* JB_MSR_ReorderCombiners( Dictionary* di, JB_String* Data ) {
	if (!JB_Str_Exists( Data )) {
        return Data;
	}

	u8* Read = Data->Addr;
	u8* ReadEnd = Read + Data->Length;
	u8* PrevCombiner = Read;
	FastString* fs = JB_FS__FastNew(0);
	JB_Object* Place = 0;
	
	do {
		u8* Result; u8* ResultEnd;
        debugger;
//		Place = JB_Dict_Scan_(StartItems, Read, ReadEnd, &Result, &ResultEnd);
		if (Result == Read and Read != Data->Addr) { // 2 adjacent combiners!!
			Read = ReorderCombiners_( di, PrevCombiner, ReadEnd, fs );
		} else {
			PrevCombiner = Result;
			Read = ResultEnd;
		}
	} while (Place);


	int fsl = fs->Length;
	if (fsl > 0) { // only return stuff in FS if it's really been filled up!!
		JB_FS_AppendMem_( fs, Data->Addr + fsl, Data->Length - fsl );
	}
	
    return JB_FS_GetResult(fs);
}




		// Object Properties
    
void EntitySet_(Dictionary* self, JB_String* Key, bool Value) {
    JB_String* ent = 0;
    if (Value) {
        ent = JB_Str_ChrB( '&' );
    }
    JB_Dict_ValueSet(self, Key, ent);
}

void JB_MSR_DecodeEntitySet(Dictionary* self, bool Value) {
    static JB_String* V;
    if (!V) {
        V = JB_Str("&#");
    }
    EntitySet_( self, V, Value );
}

void JB_MSR_EscapeCodeSet(Dictionary* self, bool Value) {
    EntitySet_( self, JB_Str_ChrB( '\\' ), Value );
}


} // 


