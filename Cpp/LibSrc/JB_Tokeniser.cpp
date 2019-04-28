
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
 Copyright (C) 2009 Theodore H. Smith.
*/


/// Tokeniser!

#include "JB_Umbrella.h"

extern "C" {

////////////////////////////////////////////////////////////////////////////////
		// Module
////////////////////////////////////////////////////////////////////////////////
Tokeniser OurModule;
#define self (&OurModule)
////////////////////////////////////////////////////////////////////////////////

JB_Object* DummyTokHan_( int TokenAfter ) {
    return self; // right???
}

int JB_Tk__ErrorStart () {
    return self->ErrorStart;
}

JB_String* JB_Tk__Data () {
    return self->Data;
}

void JB_Tk__ErrorStartSet (int Start) {
    self->ErrorStart = Start;
}

Message* JB_Tk__Avoid () {
    return (Message*)(&OurModule);
}

/// stuff


////////////////////////////////////////////////////////////////////////////////

inline fpTok FindBits_( TokHan* FatData, u32 AskBits );

inline bool Running_( u32 NextStart ) {
	return  (NextStart < self->Data->Length)  and  (self->ErrorStart < 0);
}


////////////////////////////////////////////////////////////////////////////////

struct Message;
void JB_Tk__ErrorEvent2(int A, int B, int C);
//void JB_Tk__ErrorImprove(Message* Msg);



////////////////////////////////////////////////////////////////////////////////

bool JB_Tk__CppInited() {
    if (self->RefCount) {
        return true;
    }
    
    self->RefCount = 1000;
    Dictionary* Dict = JB_NewEmpty( Dictionary );
    JB_Dict_Constructor(Dict);
	self->WordDict = Dict;
    JB_Dict_ValueSet(Dict, JB_Str_Empty(), JB_NewEmpty(TokHan));
    return false;
}


void JB_Tk__Clear(  ) { // never called
	JB_ClearRef( self->Data );
	JB_ClearRef( self->WordDict );
    JB_Zero(self);
}

////////////////////////////////////////////////////////////////////////////////


byte JB_Tk__NextByte() {
    byte* B = self->Data->Addr; 
    if (B) {
        int L = self->Data->Length;
        int N = self->NextStart;
        if (N < L) {
            byte b = B[N];
            return b;
        }
    }
    return 0;
}

bool JB_Tk__GetNextByte(byte b) {
    if ((bool)(JB_Tk__NextByte() == b)) {
        self->NextStart++;
        return true;
    }
    return false;
}


void JB_Tk__NextStartSet( u32 NextStart ) {
	if ( NextStart < self->Data->Length ) { // 0 - 1 = 4billion!
		self->NextStart = NextStart;
	} else {
        self->NextStart = self->Data->Length; // Not Running
	}
}


int JB_Tk__NextStart(  ) {
    return self->NextStart;
}

void JB_Tk__StartParse( JB_String* Data ) {
	if ( ! Data ) {
		Data = JB_Str_Empty();
	}

	JB_SetRef( self->Data, Data );
	
	self->NextStart = 0;
	self->ErrorStart = -1;
}

void SetBits_(TokHan* T, u32 BitTypes, fpTok Func) {
    if (!Func) {
        Func = (fpTok)DummyTokHan_;
    }
	for (u32 i = 0; i < kTokHanSize; i++) {
		u32 x = (1 << i);
		if (BitTypes & x) {
			T->Func[i] = Func;
#ifdef DEBUG
			fpTok Found = FindBits_( T, x );
			dbgexpect( Found );
#endif
		}
	}
}



void TH_Copy_( TokHan* T, TokHan* F ) {
	T->BitTypes |= F->BitTypes;
	for (int i = 0; i < kTokHanSize; i++) {
        fpTok fp = F->Func[i];
        if (fp) {
            T->Func[i] = fp;
        }
	}
}


TokHan* JB_Tk__Token(JB_String* s) {
    return (TokHan*)JB_Dict_Value(self->WordDict, s);
}

void JB_Tk__TokenSet( JB_String* TokStr, TokHan* New_ ) {
    if (!New_) {
        return;
    }
    // replace with JB_Dict_ValueSet?

    // u8* Read = TokStr->Addr;
    JB_Object** Place = JB_Dict_MakePlace(self->WordDict, TokStr);
//	JB_Object** Place = Dict_MakePlace_(self->WordDict, TokStr, Read, Read + TokStr->Length);
    dbgexpect(Place);
    TokHan* Old_ = (TokHan*)(*Place);

    if (Old_) {
        if (Old_->RefCount==1) { // optimisation :)
            TH_Copy_(Old_, New_);
            return;
        } else {
            TokHan* Cpy = JB_NewEmpty( TokHan );
            TH_Copy_(Cpy, Old_);
            TH_Copy_(Cpy, New_);
            New_ = Cpy;
        }
    }
    JB_SetRef_(Place, New_);
}



inline fpTok FindBits_( TokHan* FatData, u32 AskBits ) {
    int R = JB_Int_Log2(AskBits);
	return FatData->Func[R];
}



//void JB_Tk__NeedsErrorImprove() { // doesn't help
//    self->ErrorImprove = true;
//}

Message* JB_Tk__Process( u32 AskBits, long Mode ) {
	if_rare ( self->ErrorStart >= 0 ) {
		return 0;
	}
	
	u32 Start = JB_Tk__CleanSpacesSub( );
    MiniStr AL = *Mini(self->Data) + (int)Start;
    ObjLength Found = JB_Dict_LongestKey_( self->WordDict, AL );
    TokHan* FatData = (TokHan*)Found.Obj;
    
	u32 FoundBits = FatData->BitTypes;
    u32 MatchBits = FoundBits & AskBits;

    if ( MatchBits ) {
        u32 Undo = self->NextStart;
        self->NextStart = Start + Found.Length;
        fpTok Func = FindBits_( FatData, MatchBits );
        Message* Result = (Message*)Func( Start );
        if ( Result ) {
//            if_rare (self->ErrorImprove) {
//                self->ErrorImprove = false;
//                JB_Tk__ErrorImprove(Result);
//            }
            return Result;
        }

        self->NextStart = Undo;
    }
	
	if_rare ( Mode == 1 or FoundBits == -1) {
        if ( self->ErrorStart < 0 ) {
            JB_Tk__ErrorEvent2( Start, AskBits, FoundBits );
        }
	}
	
	return 0;
}



////////////////////////////////////////////////////////////////////////////////

int JB_Tk__CleanSpacesSub (  ) {
	JB_String* D = self->Data;
    u8* A = D->Addr;
	int S = self->NextStart;
	int N = D->Length;
	
	while (S < N) {
		int C = A[S++];
		
		if (C==' ' || C=='\t') {
			continue;
			
		} else if (C == '\\') {
			C = A[S];
			if (C=='\n' || C=='\r') {
				S++;
				if (C=='\n' && A[S]=='\r') {
					S++;
				}
				continue;
			}
		}
		
		return S-1;
	}
	
	return N;
}


void JB_Tk__CleanSpaces (  ) {
	self->NextStart = JB_Tk__CleanSpacesSub();
}


	
////////////////////////////////////////////////////////////////////////////////

bool JB_Tk__Expect( u32 AskBits ) {
	return JB_FreeIfDead(JB_Tk__Process( AskBits, 1 ));
}


bool JB_Tk__Allow( u32 AskBits ) {
	return JB_FreeIfDead(JB_Tk__Process( AskBits, 0 ));
}

bool JB_Tk__Consume( u32 AskBits, int Expect ) {
	bool FoundAny = false;
	while ( JB_FreeIfDead(JB_Tk__Process( AskBits, Expect ) ) ) {
		FoundAny = true;
	};
	return FoundAny;
}


bool JB_Tk__CheckEnded ( u32 AskBits ) { // has to be called with an "ender". ") } > ]", "CR/LF", ","
	int NextStart = self->NextStart;
	bool Result = JB_Tk__Allow(AskBits) or !JB_Tk__Running();
	self->NextStart = NextStart;
	return Result;
}


void JB_Tk__TokenNilSet( JB_String* Key, JB_Object* Value ) {
    JB_Object* Curr = JB_Dict_Value( self->WordDict, Key );
    if (!Curr) {
        JB_Dict_ValueSet(self->WordDict, Key, Value);
    }
}



////////////////////////////////////////////////////////////////////////////////

bool JB_Tk__Running(  ) {
	return Running_( self->NextStart );
}




////////////////////////////////////////////////////////////////////////////////
		// TokenHandler
////////////////////////////////////////////////////////////////////////////////

TokHan* JB_TH_Link(TokHan* T, u32 BitTypes, fpTok Func) {
	T->BitTypes |= BitTypes;
	SetBits_( T, BitTypes, Func );
    return T;
}
    
TokHan* JB_Tk__Handler( int BitTypes, fpTok Func ) {
    return JB_TH_Link( JB_NewEmpty( TokHan ), BitTypes, Func );
}



////////////////////////////////////////////////////////////////////////////////
	
} // 

