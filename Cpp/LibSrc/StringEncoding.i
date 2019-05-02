
// Copyright, Theodore H. Smith 2019.
// Released under jeebox-licence http://jeebox.org/licence.txt




static int ReadBOM_( u8* StartPos, int Len, int* Flags ) {
	if ( Len >= 2 ) {
		u8 Char1 = *StartPos++;
		if ( ((u32)Char1)-1  <  kUTF8BOM1-1 ) {
			return 0; // ascii or something thats not a BOM! 0->ff which is more than utf8bom1. utf8bom1 is the lowest char1...
		}
		u8 Char2 = *StartPos++;
		u8 Char3 = 0;
		u8 Char4 = 0;
		if (Len >= 3) {
			Char3 = *StartPos++;
			if (Len >= 4) {
				Char4 = *StartPos;
			}
		}
		if (Char1 == kUTF8BOM1 and Char2 == kUTF8BOM2 and kUTF8BOM3 == Char3) {
 			*Flags = kEncUTF8 | kEncBE; //0xEFBBBF
 			return 3;
		} else if (Char4 == 0xFF and Char3 == 0xFE and !Char2 and !Char1) {
			*Flags = kEncUTF32 | kEncBE; //0x0000FEFF
			return 4;
		} else if (Char1 == 0xFF and Char2 == 0xFE and !Char3 and !Char4) {
			*Flags = kEncUTF32; //0xFFFE0000
			return 4;
		} else if ( Char1 == 0xFF and Char2 == 0xFE ) {
			*Flags = kEncUTF16; //0xFFFE
			return 2;
		} else if ( Char1 == 0xFE and Char2 == 0xFF ) {
			*Flags = kEncUTF16 | kEncBE; //0xFEFF
			return 2;
		}
	}

	return 0;
}



JB_String* JB_Str_UnicodeSync(JB_String* Str) {
    int i = JB_Str_Scan_BadUTF8AtEnd(Str);
    if (i) {
        return JB_Str_Range(Str, 0, JB_Str_Length(Str) - i);
    }
    return Str;
}




JB_String* JB_Str_BOM(JB_String* self, int Encoding, bool IsBigEndian) {
	u8 Write[4];
	int Len = 0;

	if (Encoding == kEncUTF8) {
		Len = 3;
		Write[0] = (u8)kUTF8BOM1;
		Write[1] = (u8)kUTF8BOM2;
		Write[2] = (u8)kUTF8BOM3;
	} else if (Encoding == kEncUTF16) {
		Len = 2;
		if (IsBigEndian) {
			*(u16*)Write = (u16)kUTF16BBOM;
		} else {
			*(u16*)Write = (u16)kUTF16LBOM;
		}
	} else if (Encoding == kEncUTF32) {
		Len = 4;
		if (IsBigEndian) {
			*(u32*)Write = (u32)kUTF32BBOM;
		} else {
			*(u32*)Write = (u32)kUTF32LBOM;
		}
	}

	JB_String* result = JB_Str_New( Len );
	if (result and Len) {
		CopyBytes( Write, result->Addr, Len );
	}

	return result;
}

