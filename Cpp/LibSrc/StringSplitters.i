
// Copyright, Theodore H. Smith 2019.
// Released under jeebox-licence http://jeebox.org/licence.txt



static Dictionary* StrUniquer = 0;
void JB_Str__Uniqify(Dictionary* D) {
    JB_SetRef(StrUniquer, D);
}


JB_String* JB_Str_UniqueSplit(JB_String* self, int StartOff, int Length, Dictionary* D);


JB_String* JB_Str_Range(JB_String* self, int StartOff, int AfterOff) {
	if_rare ( StartOff < 0 ) {
		StartOff = 0;
	}

	int CurrLen = self->Length;
	if_rare ( (u32)AfterOff > (u32)CurrLen ) {
		AfterOff = CurrLen;
	}

    int Length = AfterOff - StartOff;
    if ( CurrLen == Length ) {
        return self;
    }

	if_usual ( Length > 1 ) {
        if (StrUniquer) {
            return JB_Str_UniqueSplit(self, StartOff, Length, StrUniquer);
        }
        if (Length <= 4) {
            return JB_Str_CopyFromPtr( (u8*)self->Addr + StartOff, Length);
        }
        
        JB_StringShared* u = JB_New( JB_StringShared );
        if_usual ( u ) {
            u->Addr = self->Addr + StartOff;
            u->Length = Length;
            JB_Class* Cls = JB_ObjClass(self);
            if (Cls==JB_AsClass(JB_StringShared)) {
                self = (JB_String*)((JB_StringShared*)self)->Parent;
            }
            u->Parent = JB_Incr( self );
        }

        return u;

    } else if ( Length == 1 ) {
		return JB_Str_ChrB( self->Addr[StartOff] );
	}

	return JB_Str_Empty();
}



JB_String* JB_Str_Left(JB_String* self, int Count) {
	return JB_Str_Range(self, 0, Count);
}

JB_String* JB_Str_Right(JB_String* self, int Count) {
	return JB_Str_Range(self, self->Length - Count, self->Length);
}



// useful later when I add support for faster string appends...
// to make error reporting take up less code = less bloat!
static JB_String* Str_Append_(JB_String* Items[], int N) {
    if (N <= 2) {
        return JB_Str_OperatorPlus(Items[0], Items[1]);
    }

    int Bytes = 0;
    for (int i = 0; i < N; i++) {
        JB_String* Curr = Items[i];
        Bytes += Curr->Length;
    }

    // OK so we got the length...
    JB_String* Result = JB_Str_New( Bytes );
    if (!Result) {
        return 0;
    }
    
    u8* WriteTo = Result->Addr;
    for (int i = 0; i < N; i++) {
        JB_String* S = Items[i];
        CopyBytes(S->Addr, WriteTo, S->Length);
        WriteTo += S->Length;
    }
    
    return Result;
}


/*
#define Append_(X) if (JB_Str_Length(X)) {Items[i++] = X;}
JB_String* JB_Str_Append3(JB_String* A, JB_String* B, JB_String* C) {
    JB_String* Items[4];
    int i = 0;
    Append_(A);
    Append_(B);
    Append_(C);
    return Str_Append_(Items, i);
}

JB_String* JB_Str_Append5(JB_String* A, JB_String* B, JB_String* C, JB_String* D, JB_String* E) {
    JB_String* Items[4];
    int i = 0;
    Append_(A);
    Append_(B);
    Append_(C);
    Append_(D);
    Append_(E);
    return Str_Append_(Items, i);
}

#undef Append_
*/

JB_String* JB_Str_OperatorPlus(JB_String* self, JB_String* other) {
    int NS = JB_Str_Length(self);
    if (!NS) {
        return other;
    }
    
    int NO = JB_Str_Length(other);
    if (!NO) {
        return self;
    }

    JB_String* s = JB_Str_New( NS + NO );
    if (s) {
        CopyBytes(self->Addr, s->Addr, NS);
        CopyBytes(other->Addr, s->Addr + NS, NO);
    }
    return s;
}


JB_String* JB_Str_Unshare(JB_String* self) {
// avoid wasting RAM when we this str is only a small part of a big file!!
    if (self and JB_ObjClass(self) == JB_AsClass(JB_StringShared)) {
        return JB_Str_Copy(self);
    }
    return self;
}


