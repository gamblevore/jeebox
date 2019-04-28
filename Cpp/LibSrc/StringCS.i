
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



bool JB_Str_IsInteger( JB_String* self, int BeginOff, int AfterOff, bool AllowMinus ) {
	int Length = AfterOff - BeginOff;
	SectFix_(BeginOff, Length, self->Length);
	u8* ReadPlace = self->Addr + BeginOff;
	u8* ReadEnd = ReadPlace + Length;
	
	while (ReadPlace < ReadEnd) {
		u8 c = *ReadPlace++;
		if (c >= '0' and c <= '9') {
			;
		} else if ( c == '-' and AllowMinus ) {
			;
		} else {
			return false;
		}
		AllowMinus = false;
	}
	
	return (Length > 0);
}

//-11.22e-33
//-22e-33
#define RequireState_( a ) if (! (State&a) ) return false


/*bool JB_Str_IsDouble( JB_String* self, int BeginOff, int AfterOff ) {
// EndPos is byte AFTER, like range.
	int Length = AfterOff - BeginOff;
	SectFix_(BeginOff, Length, self->Length);
	u8* ReadPlace = self->Addr + BeginOff;
	u8* ReadEnd = ReadPlace + Length;
////////////////////////////////////////////////////////////////////////////////////
	const int kAllowMinus = 1;
	const int kAllowNum = 2;
	const int kAllowE = 4;
	const int kAllowDot = 8;
////////////////////////////////////////////////////////////////////////////////////
	int State = kAllowMinus | kAllowNum | kAllowDot;
	int Restrict = 0;
	bool FoundNum = false;
	
	while (ReadPlace < ReadEnd) {
		u8 c = *ReadPlace++;

		if ( c == '.' ) {
			RequireState_(kAllowDot);
			State = kAllowNum | kAllowE; // "1.e1"?
			Restrict = Restrict | kAllowDot; // no more dots!

		} else if ( c == 'e' ) {
			RequireState_(kAllowE);
			State = kAllowNum|kAllowMinus;
			Restrict = Restrict | kAllowE; // no more e's!

		} else if ( c == '-' ) {
			RequireState_(kAllowMinus);
			State = kAllowNum|kAllowDot;

		} else if ( c >= '0' and c <= '9' ) {
			RequireState_(kAllowNum);
			State = kAllowNum|kAllowDot|kAllowE;
			FoundNum = true;

		} else {
			return false;
		}

		State = State &~ Restrict;
	}
	
	return FoundNum;
}*/


int JB_Str_WhiteSpace( JB_String* self, int StartOff, int AfterOff, bool IsIn ) {
    extern ByteMap* WhiteSpace_;
	return JB_Str_CharSet( self, StartOff, AfterOff, WhiteSpace_, IsIn );
}



         //  Main subroutines. These are generalised, and need interfacing routines.

int JB_Str_CharSet( JB_String* self, int StartOff, int AfterOff, ByteMap* cs, bool IsIn ) {
    MiniStr S = ReadAddrs_(self, StartOff, AfterOff);
		
	if ( cs and S ) {
        int Dir = S.Dir(); // correct the thing...
		
        while (S) {
            if ( BM_In_(cs->Cache, S.Move(Dir)) == IsIn ) {
                return ResultFix_(S, self, Dir);
            }
        }
	}

	return -1;
}

