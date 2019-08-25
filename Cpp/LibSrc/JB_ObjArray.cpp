
// Copyright, Theodore H. Smith 2019.
// Released under jeebox-licence http://jeebox.org/licence.txt

/*
	Copyright (C) 2017 Theodore H. Smith.
*/

#include "JB_Umbrella.h"
#include "smmintrin.h"


extern "C" {

#ifndef ENV64BIT
    #define kArrayLengthMax (1024*1024*512) // 512MB
#else
    #define kArrayLengthMax (2147483644) // 2GB
#endif
#define PtrSize (sizeof(void*))


inline MArray mrealloc(Array* self, u32 N) {
    MArray M = self->ArrData;
    if (N > kArrayLengthMax) {
        JB_TooLargeAlloc("arrays", N, kArrayLengthMax);
        return 0;
    }
    MArray Result = (MArray)JB_realloc(M, N*PtrSize);
    if (!Result and N) {return 0;} // we tried to allocate something but couldnt, so return 0.
    self->ArrData = Result;
    self->UsableSize = (u32)JB_msize(Result) / PtrSize;
    return Result;
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


JB_Object* JB_Array_UnorderedRemove(Array* self, int Item) {
    MArray M = self->ArrData;
    int Length = self->Count;
    require (Item < Length);
    
    self->Count = Length-1;
    JB_Object* ToRemove = M[Item];
    JB_Object* Last = M[Length-1];
    M[Item] = Last;
    JB_SafeDecr(ToRemove);
    return ToRemove;
}


void JB_Array_SizeSet( Array* self, int NewSize ) {
    require0(self);
    MArray M = self->ArrData;
    // JB_mtest(M);
    
    int Length = self->Count;
    if (NewSize < Length) {
        self->Count = NewSize;
        while ( NewSize < Length ) {
            JB_Decr( M[--Length] );
        }
    }
    mrealloc(self, NewSize);
}


void JB_Array_Append( Array* self, JB_Object* Value ) {
    MArray M = self->ArrData;
    // JB_mtest(M);
    int Length = self->Count;
    int Size = self->UsableSize;
    if (Length >= Size) {
        Size += Size/2;
        M = mrealloc(self, Max(Size, 8));
        require0(M);
    }

    // JB_mtest(M);
    self->Count = Length + 1;
    M[Length] = Value;
    JB_Incr(Value);
    // JB_mtest(M);
}


void JB_Array_Destructor( Array* self ) {
    JB_Array_SizeSet( self, 0 );
}


int JB_Array_Size( Array* self ) {
    if (self) {
        return self->Count;
    }
    return 0;
}


void JB_Array_Constructor( Array* self, int Length ) {
    self->ArrData = 0;
    self->Count = 0;
    self->UsableSize = 0;
    if (Length >= 0) {
        mrealloc(self, Length);
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
    MArray Data = self->ArrData;
    u32 Size = self->UsableSize;
    if ((u32)Pos < Size) {
        int Length = self->Count; 
        if (Pos < Length) {
            JB_SetRef( Data[Pos], Value );
            return;
        }
    }
    debugger; // error in caller...
}


JB_Object* JB_Array_Value( Array* self, int Pos ) {
    if ( (u32)JB_Array_Size(self) > (u32)Pos) {
        return self->ArrData[ Pos ];
    }
    return 0;
}
    

#ifndef AS_LIBRARY
void JB_Array_Shuffle( Array* self ) {
    int n = JB_Array_Size(self);
    JB_Object** Array = self->ArrData;

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


