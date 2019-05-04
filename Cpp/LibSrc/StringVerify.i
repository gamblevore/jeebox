
// Copyright, Theodore H. Smith 2019.
// Released under jeebox-licence http://jeebox.org/licence.txt


// its only called from one point, so why not remove the overhead?



inline int VerifyUTF16_(u16* source, u16* sourceEnd) {
	u16* RefPos = source;

	while (source < sourceEnd) {
		u32 ch = *source++;
		if (ch >= UNI_SUR_HIGH_START and ch <= UNI_SUR_HIGH_END) {
			if (source >= sourceEnd) { // unpaired
				goto BadPos;
			}
            
			u32 ch2 = *source;
			if (ch2 >= UNI_SUR_LOW_START and ch2 <= UNI_SUR_LOW_END) {
				ch2 = ((ch - UNI_SUR_HIGH_START) << halfShift) + (ch2 - UNI_SUR_LOW_START) + halfBase;
				if (!JB_Str_UniValid(ch2)) {
					goto BadPos;
				}
				source++;
                
			} else { /* it's an unpaired high surrogate */
				goto BadPos;
			}
            
		} else if (ch >= UNI_SUR_LOW_START and ch <= UNI_SUR_LOW_END) {
			goto BadPos;
            
		} else if (!JB_Str_UniValid(ch)) {
			goto BadPos;
		}

	}
	
	return -1;
	BadPos:;
	return (int)(((u8*)source - (u8*)RefPos) - 1);
}

		

inline int VerifyUTF8_(u8* source, u8* sourceEnd) {
	while (source < sourceEnd) {
		u8 c = *source++;
		if (c >= 0x80) {
			u8* PrevPos = source - 1;
			source = LegalUTF8_(c, source);
			if ( source > sourceEnd or !source ) {
				return (int)(sourceEnd - PrevPos - 1);
			}
		}
	}
	
	return -1;
}

// I can’t seem to make up my mind and wasted all this time reworking the function! However,
// if I have it like this, I can make up mind without barely any reworking.
int JB_Str_Verify(JB_String* self, int utf) {
	if (utf == 8) {
		return Verify8_(self);
	} else if (utf == 16) {
		return Verify16( self );
	}
	return -1;
}

int Verify8_(JB_String* u) {
	if ( JB_Str_IsASCII(u) ) {
		return -1;
	}

	u8* uAddr = u->Addr;
	return VerifyUTF8_(uAddr, uAddr + u->Length);
}

int Verify16(JB_String* u) {
	int Len = u->Length;
	u8* uAddr = u->Addr;
	
	return VerifyUTF16_((u16*)uAddr, (u16*)(uAddr + Len));
}
