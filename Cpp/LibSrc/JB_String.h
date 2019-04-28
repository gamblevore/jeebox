
/*
	Copyright (C) 2005 Theodore H. Smith.
*/


/*
	Q: So the question is... do I remove the stuff in String? OR... move it? I know I want to split faster... it seems wasteful to carry all this clunk around. I mean... it should be a byte orientated string processing plugin, thats also oriented for UTF-8.
	
		A: At least the root String MUST do refcounting on the source string.




Q: Approaches?
	A: Alter as little as possible. Leave strings at 12 + 4 bytes.
		+ Less work as possible.
		+ Gives me more time to try to make the "just avoid making strings totally" approach.
		- Slower string splitting for where I DO need it.
		- Misses a chance to break away from all this complexity.
		- Requires a destructor for BMH!


	A: Alter as little as possible but remove BMH.
		+ As above but doesn't require a destructor.

	A: Make two string classes... String and StringRoot. Strip out most stuff from String. Leave "Str" in the root.
		+ Clean approach
		- A lot of work?


	A: Make two string classes... String and StringRoot. Strip out most stuff from String. Leave the encoding stuff in the root.
		+ Less work than above.
		

	A: Take the "alter little as possible NOW" approach... and focus on splitting them up later.
		+ Neat. I can clean stuff up later rather than all at once.
		- Could introduce dependancies on an outdated design. (But I can't think of any?)

*/



#ifndef __JB_Str__
#define __JB_Str__








			 // Includes

#include "JB_Alloc.h"
#include "JB_LibTypes.h"
#include "StringFunctions.h"
#include "StringFunctionsLib.h"
#include "StringConvert.h"
#include "JB_ByteArray.h"

extern "C" {




inline u8 LowerCaseB(u8 c) {
    if (c <= 90 and c >= 65) {
        return (u8)(c + 32);
    }
    return c;
}


JBClass( JB_StringShared, JB_String,
    JB_Object*      Parent; // refcount parent
);

JBClass( JB_StringExternal, JB_String,
    void*           Free;   // fp
    void*           Obj ;
);


JBClass( JB_StringC, JB_String,

);

JBClass( JB_String4, JB_String,
        u8  Data[4];
);

JBClass( JB_String20, JB_String,
        u8  Data[20];
);



struct MiniStr {
    u8*			Addr; // address
    int			Length; // length
    
    bool Exists() {
        return Length;
    }
    bool Forward() {
        return Length >= 1;
    }
    u8 Next() {
// Tests show that using .Next() intead of *Ptr++ is equally fast.
// Despite that it has to update (length + address) instead of just address.
        Length--;
        return *Addr++;
    }
    u8 Curr() {
        return *Addr;
    }
    u8 NextLower() {
        return LowerCaseB(Next());
    }
    operator bool() {
        return Length;
    }
    operator u8*() {
        return Addr;
    }
    int Dir() {
        if (Length < 0) {
            Addr--;
            return -1;
        } else {
            return 1;
        }
    }
    inline u8 Move(int D) {
        Length -= D;
        u8 Result = *Addr; // Next() already compiled to as fast as *Ptr++, perhaps this will too?
        Addr += D;
        return Result;
    }
    bool operator==(const MiniStr &str) const{
        return Addr==str.Addr and Length == str.Length;
    }
    MiniStr operator+(int D) const{
        MiniStr Result = {Addr + D, Length - D};
        return Result;
    }
//    int operator-(const MiniStr &str) const{
//        return Addr-str.Addr;
//    }
    bool operator!=(const MiniStr &str) const{
        return !(*this == str);
    }
};

// how to "unshare" this? If we are only keeping a small part of many files?
// seems... we could try to re-link the parent memorylayer into the main memorylayer for String, and go through all the AllocationBlocks and set them to use the main memorylayer...


inline bool SectFix_( int& srOffset, int& srLength, int CurrLen ) {
    if (srOffset < 0) {
        srLength += srOffset;
        srOffset = 0;
    }
/*
     * We want to make sure that we fix bad ranges.
     * We want to allow huge ranges, like String.kEnd (largest possible number)
     * We don't need it to be ints or uints specifically.
     * As few operations as possible!
     
     It used to fail with kMax! because kMax + 1 = -1
     
     I hope using u32 fixes this. I can't remember :(
*/
    u32 Final = (u32)srLength + (u32)srOffset;
    if (Final > (u32)CurrLen) {
        srLength = CurrLen - srOffset;
    }
    return (srLength >= 1);
}


inline MiniStr* Mini(JB_String* self) {
    return ((MiniStr*)(JBShift(self,sizeof(void*))));
}

inline MiniStr ReadAddrs_( JB_String* self, int StartOff, int AfterOff ) {
    int SelfAfter = self->Length;
    if (StartOff < 0) {
        StartOff = SelfAfter + 1 + StartOff;
    } else if (StartOff > SelfAfter) {
        StartOff = SelfAfter;
    }
    if (AfterOff > SelfAfter) {
        AfterOff = SelfAfter;
    } else if (AfterOff < 0) {
        AfterOff = SelfAfter + 1 + AfterOff;
    }

    return {self->Addr + StartOff, AfterOff - StartOff};  
}
    

inline int ResultFix_(u8* Result, JB_String* S, int Dir) {
    if (Result) {
        return (int)(Result - (S->Addr + Dir));
    } else {
        return -1;
    }
}





} // extern "C"




#endif // __JB_Str__

