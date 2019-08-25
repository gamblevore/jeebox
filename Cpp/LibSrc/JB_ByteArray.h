
/*
	Copyright (C) 2013 Theodore H. Smith.
*/

#ifndef __STRING_BASE__
#define __STRING_BASE__

#include "JB_Alloc.h"

extern "C" {

JBClass( JB_String, JB_Object,
    int            Length;
    u8*			   Addr;
);


JB_String* JB_BA_Alloc( int Length );
JB_String* JB_BA_Realloc_( JB_String* self, int Length );
void JB_BA_Destructor( JB_String* self );

}

#endif


