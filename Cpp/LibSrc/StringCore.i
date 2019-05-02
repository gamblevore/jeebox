
// Copyright, Theodore H. Smith 2019.
// Released under jeebox-licence http://jeebox.org/licence.txt

#define kStrLengthMax (16*1024*1024) // 16MB string max

JB_String* JB_BA_Realloc_( JB_String* self, int Length ) {
    if (Length <= 0) {
        JB_free( self->Addr );
        self->Addr = 0; self->Length = 0;
        return 0;
    }

    if (Length > kStrLengthMax) {
        JB_TooLargeAlloc("strings", Length, kStrLengthMax);
        return 0;
    }
    
    u8* Result = (u8*)JB_realloc( self->Addr, Length );
    if (!Result) {
        return 0;
    }
    self->Addr = Result;
	self->Length = Length;
	return self;
}
    

void JB_BA_Destructor( JB_String* self ) {
    JB_free( self->Addr );
}


void JB_Str_Constructor( JB_String* self ) {
    * self = {};
}


JB_String* JB_Str_CopyFromPtr( MiniStr M ) {
    JB_String* e = JB_Str_New( M.Length );
    if (e and M.Length) {
        CopyBytes(M.Addr, e->Addr, M.Length);
    }
    return e;
        
}

JB_String* JB_Str_Copy( JB_String* self ) {
    return JB_Str_CopyFromPtr(*Mini(self));
}

JB_String* JB_Str3(const char* c, int N) {
    JB_StringC* S = JB_New( JB_StringC );
    S->Addr = (u8*)c;
    S->Length = N;
    return S;
}

JB_String* JB_StrFromPtr(const char* c, int N, void* Free, void* Obj) {
    JB_StringExternal* S = JB_New( JB_StringExternal );
    S->Addr = (u8*)c;
    S->Length = N;
    S->Free = Free;
    S->Obj = Obj;
    return S;
}


JB_String* JB_Str_FromCString_( const char* c ) {
    if (!c) {
        return 0;
    }
    int N = (int)strlen( c );
    if (!N) {
        return JB_Str_Empty();
    }
    
    JB_StringC* e = JB_New( JB_StringC );
    e->Addr = (u8*)c;
    e->Length = N;
    return e;
}


		// Utilities

int JB_Str_Length( JB_String* self ) {
	if (self) {
		return self->Length;
	}
	return 0;
}


u8* JB_Str_Address( JB_String* self ) {
	return (u8*)self->Addr;
}

      
JB_String* JB_Str_NewInlined(int Length, JB_Class* Cls) {
    if (!Length) {
        return JB_Str_Empty();
    }
    
    JB_String4* Result = (JB_String4*)(JB_NewClass(Cls));
    *((int*)(Result->Data)) = 0x20202020; // for JB_Str_FastLower
    Result->Addr = (Result->Data);
    Result->Length = Length;
    return (JB_String*)Result;
}


JB_String* JB_Str_New(int Length) {
	if (Length <= 20) {
        if (Length <= 4) {
            if (Length < 0) {return 0;} // error
             return JB_Str_NewInlined( Length, JB_AsClass(JB_String4) );
            // don't use JB_Str_Empty... we are using this with Str_Realloc as a generalised "Grower"...
            // str_empty is reused all over the place!
        }
        return JB_Str_NewInlined( Length, JB_AsClass(JB_String20) );
    }
    
    JB_String* Str = JB_New( JB_String );
    require(Str);
    Str->Addr = 0;
    JB_String* Result = JB_BA_Realloc_(Str, Length);
    if (!Result) {
        JB_FreeIfDead(Str);
    }
    return Result;
}


JB_String* JB_Str_Realloc(JB_String** up, int Length) {
    JB_String* u = *up;
    if (u) {
        if (u->Length == Length) {
            return u;
        }
        JB_Class* Cls = JB_ObjClass(u);

        if ( Cls == JB_AsClass(JB_String) ) {    // so this depends on the class... really!
            return (JB_String*)JB_BA_Realloc_(u, Length);

        } else if ( (Cls == JB_AsClass(JB_String4) and (Length <= 4)) or ((Cls == JB_AsClass(JB_String20)) and Length <= 20) ) {
            u->Length = Length;
            return u;
        }
    }
    
    JB_String* CopyTo = JB_Str_New(Length);
    if (CopyTo) { // always grows... can't over fill.
        if (u) {
            CopyBytes( u->Addr, CopyTo->Addr, u->Length );
        }
        JB_SetRef(*up, CopyTo);
    }
    return CopyTo;
}





void JB_Str_Destructor(JB_StringShared* self) {
	JB_Decr( self->Parent );
}


typedef void (*XStrFree)(const char* Addr, void* Param);

void JB_XStr_Destructor(JB_StringExternal* self) {
    auto F = self->Free; auto O = self->Obj; auto A = self->Addr;
    if (F and O) {
        self->Addr = 0; self->Obj = 0;
        ((XStrFree)(F))((const char*)A, O);
    }
}


