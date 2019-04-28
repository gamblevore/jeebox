
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

// I can't seem to make up my mind and wasted all this time reworking the function! However,
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
