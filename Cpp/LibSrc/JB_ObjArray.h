
/*
	Copyright (C) 2013 Theodore H. Smith.
*/

#ifndef __JB_Array__
#define __JB_Array__


extern "C" {

    JBClass( Array, Saveable,
        MArray          ArrData;
        int             Count;
        int             UsableSize;
    );


JB_String* JB_Array_Render(Array* self, FastString* fs);
void JB_Array_Shuffle( Array* self );
void JB_Array_SizeSet( Array* self, int NewSize );
void JB_Array_Append( Array* self, JB_Object* Value );
void JB_Array_Destructor( Array* self );
int JB_Array_Size( Array* self );
void JB_Array_Constructor( Array* self, int Length );
void JB_Array_ValueSet( Array* self, int Pos, JB_Object* Value );
JB_Object* JB_Array_Value( Array* self, int Pos );
int JB_Array_Find( Array* self, JB_Object* Obj );
void JB_Array_Constructor0( Array* self );
int JB_Array_Wipe(Array* self);
JB_Object* JB_Array_UnorderedRemove( Array* self, int Pos );
    
} // ExternCEnd

#endif //__JB_Array__

