
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



Array* JB_Array__New0();
Array* JB_Str_ArgV(char** ArgV) {
    Array* Result = JB_Array__New0();
    while (true) {
        char* c = *ArgV++;
        if (!c) {break;}
        JB_String* Str = JB_Str_FromCString_(c);
        JB_Array_Append(Result, Str);
    }
    return Result;
}


Dictionary* JB_C_Args_Env(char** self) {
    Dictionary* D = JB_Dict__New();
    
    for (int i = 0; const char* C = self[i]; i++) {
        JB_String* S = JB_Str_FromCString_(C);
        if (JB_Str_Exists(S)) {
            int Eq = JB_Str_FindByte(S, 0, '=');
            JB_String* Before = JB_Str_Range(S, 0, Eq);
            JB_String* After = JB_Str_Range(S, Eq + 1, kJB__int_max);
            (JB_Dict_ValueSet(D, Before, After));
            JB_FreeIfDead(Before);
            JB_FreeIfDead(After);
            JB_FreeIfDead(S);
        }
    };
    return D;
}


/*
void JB_Array_Print(Array* R) {
    int N = JB_Array_Size(R);
    for (int i = 0; i < N; i++) {
        JB_String* S = (JB_String*)JB_Array_Value(R, i);
        JB_Str_Print(S);
        puts("");
    }
}
*/

JB_String* JB_Str_Empty() {
    extern JB_String* EmptyString_;
	return EmptyString_;
}
	
bool JB_Str_Exists(JB_String* Obj) {
	return  (Obj and Obj->Length);
}

JB_String* JB_Str_ChrUTF8(u32 C) {
	if (C <= 127) {
		return JB_Str_ChrB( C );
	}
    
	u32 N = JB_Str_UTF8Size( C );
    if (!N) {
        return 0;
    }

    JB_String* Result = JB_Str_New( N );
    if ( Result ) {
        u8Write_( Result->Addr, C );
    }
    return Result;
}

JB_String* JB_Str_FromInt( int L, int R ) {
	FastString* FS = JB_FS__FastNew( 0 );
	JB_FS_SizeSet( FS, 16 );
	JB_FS_AppendIntegerAsText( FS, L, R );
	return JB_FS_GetResult( FS );
}



JB_String* JB_Str_ChrB(int i) {
    struct ChrBData {
        JB_String* Objects[256];
    };
	static ChrBData* block = 0;
    if (!block) {
        block = (ChrBData*)JB_zalloc(sizeof(ChrBData) );
    }

	i = i & 0xFF; // make sure it's actually a byte!!
	JB_String* Result = block->Objects[i];
	if (Result) {
		return Result;
	}

    Result = JB_Str_New(1);

	block->Objects[i] = (JB_String*)JB_Incr(Result);
    Result->Addr[0] = i;

	return Result;
}


bool JB_Str_UniValid( u32 c ) { // negative c looks like > 2 billion, which is going to return false!
	if ( c < UNI_SUR_HIGH_START ) { // common case first
		return true;
	} else if ( c <= UNI_MAX_UTF and c > UNI_SUR_LOW_END and c != 0xFFFF and c != 0xFFFE ) {
		return true;
	}
	return false;
}

