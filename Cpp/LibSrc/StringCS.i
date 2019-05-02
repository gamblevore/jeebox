
// Copyright, Theodore H. Smith 2019.
// Released under jeebox-licence http://jeebox.org/licence.txt



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

