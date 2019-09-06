
// Copyright, Theodore H. Smith 2019.
// Released under jeebox-licence http://jeebox.org/licence.txt

/*
	Copyright (C) 2017 Theodore H. Smith.
*/

#include "JB_Umbrella.h"
#include "smmintrin.h"

#include <vector>

extern "C" {

#ifndef ENV64BIT
    #define kArrayLengthMax (1024*1024*512) // 512MB
#else
    #define kArrayLengthMax (2147483644) // 2GB
#endif
#define PtrSize (sizeof(void*))



inline bool mrealloc(Array* self, u32 N) {
    if (N > kArrayLengthMax) {
        JB_TooLargeAlloc("arrays", N, kArrayLengthMax);
        return false;
    }
    
    try {
        self->Vec.resize(N);
        return true;
    } catch (const std::bad_alloc&) {
        JB_OutOfUserMemory(N*sizeof(void*));
        return false;
    }
}


void JB_Array_AppendCount( Array* self, JB_Object* Value, int Count ) {
    try {
        while (Count-- > 0) {
            self->Vec.push_back(Value);
            JB_Incr(Value);
        }
    } catch (const std::bad_alloc&) {
        JB_OutOfUserMemory((self->Vec.size()+Count)*sizeof(void*));
    }
}

void JB_Array_Insert( Array* self, int Pos, JB_Object* Value ) {
    try {
        self->Vec.insert(self->Vec.begin()+Pos, 1, Value);
        JB_Incr(Value);
    } catch (const std::bad_alloc&) {
        JB_OutOfUserMemory((self->Vec.size()+1)*sizeof(void*));
    }
}


void JB_Array_SizeSet( Array* self, int NewLength ) {
    require0(self);
    int Length = self->Vec.size();
    int Extra = NewLength - Length;
    require0(Extra); 
    if (Extra < 0) {
        JB_Object** Last = &self->Vec[Length];
        JB_Object** Curr = &self->Vec[NewLength];
        while ( Curr < Last ) {
            JB_Decr( *Curr++ );
        }
    }
    mrealloc(self, NewLength);
}


JB_String* JB_Array_Render(Array* self, FastString* fs_in) {
	FastString* fs = JB_FS__FastNew(fs_in);
	JB_FS_AppendByte(fs, '[');
    for (int i = 0; i < JB_Array_Size(self); i++) {
        JB_Object* obj = JB_Array_Value(self, i);
        if (i) {
            JB_FS_AppendCString(fs, ", ");
        }
        JB_ObjRender(obj, fs);
    };
	JB_FS_AppendByte(fs, ']');
	return JB_FS_SmartResult(fs, fs_in);
}



void JB_Array_Append( Array* self, JB_Object* Value ) {
    JB_Array_AppendCount(self, Value, 1);
}

void JB_Array_Reverse( Array* self ) {
    int n = self->Vec.size();
    auto F = self->Vec.begin();
    for (int i = 0; i < n/2; i++) {
        F[i] = F[n-(i+1)];
    }
}

void JB_Array_Remove( Array* self, int Pos ) {
    self->Vec.erase(self->Vec.begin()+Pos);
}


void JB_Array_Destructor( Array* self ) {
    JB_Array_SizeSet( self, 0 );
}


int JB_Array_Size( Array* self ) {
    if (self) {
        return self->Vec.size();
    }
    return 0;
}


void JB_Array_Constructor( Array* self, int Length ) {
    auto Place = &self->Vec;
    auto f = new (Place) std::vector<JB_Object*>(); 
    if (Length >= 1) {
        JB_Array_SizeSet(self, Length);
    }
}


void JB_Array_Constructor0( Array* self ) {
    JB_Array_Constructor(self, 0);
}

int JB_Array_Wipe(Array* self) {
    require(self);
    JB_Array_SizeSet(self, 0);
    return 0;
}

void JB_Array_ValueSet( Array* self, int Pos, JB_Object* Value ) {
    if ((u32)Pos < self->Vec.size()) {
        JB_SetRef( self->Vec[Pos], Value );
        return;
    }
    debugger; // error in caller...
}


JB_Object* JB_Array_Value( Array* self, int Pos ) {
    if ( (u32)JB_Array_Size(self) > (u32)Pos) {
        return self->Vec[ Pos ];
    }
    return 0;
}
    

#ifndef AS_LIBRARY
void JB_Array_Shuffle( Array* self ) {
    int n = JB_Array_Size(self);
    JB_Object** Array = &self->Vec[0];

    u32 CRC = 0x1EDC6F41;
    for (int i = 0; i < n; i++) {
        CRC = __builtin_ia32_crc32si(CRC, 0); // random numbers
        int i2 = CRC&n;
        JB_Object* t = Array[i2];
        Array[i2] = Array[i];
        Array[i] = t;
    }
}
#endif



} // 


