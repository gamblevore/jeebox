
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



/*

Hidden Caches:
	* .LowerCase / .UpperCase ByteMap
    * EmptyString_
    * WhiteSpace_
	* JB_FS__FastNew
    * Dict fast name
	* 256 byte block! speeds up splitting when the length = 1!! for .Mid
    * Hex mapping in FastString
*/


#include "JB_Umbrella.h"


extern "C" {

#define JBClassPlaceSaver(a, b, c, d, e, f, g)  \
                                                                            \
JBSaver_Behaviour a ## _FuncTable = {(void*)b,(void*)d,(void*)e,(void*)f,(void*)g};  \
JB_Class a ## Data = {                                                      \
    .Name = (u8*)(#a),                                                      \
    .Parent = c,                                                            \
    .FuncTable = (JBObject_Behaviour*)&(a##_FuncTable),                      \
    .DefaultBlock = (AllocationBlock*)(&((a ## Data).Memory.Dummy)),        \
    .Memory.RefCount = 2,                                                   \
    .Memory.Class = &(a ## Data),                                           \
    .Memory.Dummy.Owner = &((a ## Data).Memory),                            \
    .Memory.CurrBlock = (AllocationBlock*)(&((a ## Data).Memory.Dummy)),    \
    .Memory.World = JB_MemStandardWorld(),                                  \
    .Size = Max(sizeof(a), kObjMinSize),                                    \
};
void JB_Array_SaveWrite(Array* self, void* Other);
void JB_Dict_SaveWrite(Dictionary* self, void* Other);
void JB_Array_SaveCollect(Array* self, void* Other);
void JB_Dict_SaveCollect(Dictionary* self, void* Other);
void JB_Dict_LoadProperties(Dictionary* self, void* Other);
void JB_Array_LoadProperties(Array* self, void* Other);

void JB_Sav_SaveCollect(Saveable* self, void* Saver);
void JB_Sav_SaveWrite(Saveable* self, void* Saver);
void JB_Sav_LoadProperties(Saveable* self, void* Other);


//JBClassPlace3( JB_MemMapper,     JB_Mmp_Destructor,     JB_AsClass(JB_Object),      0 );
#ifndef AS_LIBRARY
JBClassPlace3( JB_File,          JB_File_Destructor,    JB_AsClass(JB_Object),      JB_File_Render );
JBClassPlace3( JB_Pipe,          JB_Pipe_Destructor,    JB_AsClass(JB_Object),      0 );
#endif

JBClassPlace3( JB_String,        JB_BA_Destructor,      JB_AsClass(JB_Object),      JB_Str_Render );
JBClassPlace3( JB_StringC,       0,                     JB_AsClass(JB_String),      JB_Str_Render );
JBClassPlace3( JB_StringShared,  JB_Str_Destructor,     JB_AsClass(JB_String),      JB_Str_Render );
JBClassPlace3( JB_StringExternal,JB_XStr_Destructor,    JB_AsClass(JB_String),      JB_Str_Render );
JBClassPlace3( JB_String4,       0,                     JB_AsClass(JB_String),      JB_Str_Render );
JBClassPlace3( JB_String20,      0,                     JB_AsClass(JB_String),      JB_Str_Render );

JBClassPlace3( IntWrapper,       0,                     JB_AsClass(JB_Object),      0 );
JBClassPlace3( Dictionary1,      JB_Dict_Destructor,    JB_AsClass(JB_Object),      0 );
JBClassPlace3( Dictionary2,      JB_Dict_Destructor,    JB_AsClass(JB_Object),      0 );
JBClassPlace3( Dictionary3,      JB_Dict_Destructor,    JB_AsClass(JB_Object),      0 );
JBClassPlace3( Dictionary4,      JB_Dict_Destructor,    JB_AsClass(JB_Object),      0 );
JBClassPlace3( DictionaryLeaf,   JB_Leaf_Destructor,    JB_AsClass(JB_Object),      0 );
JBClassPlace3( DictionaryReader, JB_Nav_Destructor,     JB_AsClass(JB_Object),      0 );

JBClassPlaceSaver( Dictionary,   JB_Dict_Destructor,    JB_AsClass(Saveable),       JB_Dict_Render,  JB_Dict_LoadProperties,  JB_Dict_SaveCollect, JB_Dict_SaveWrite );
JBClassPlaceSaver( Array,        JB_Array_Destructor,   JB_AsClass(Saveable),       JB_Array_Render, JB_Array_LoadProperties, JB_Array_SaveCollect, JB_Array_SaveWrite );
JBClassPlaceSaver( Saveable,     0,                     0,                          0,               JB_Sav_LoadProperties,                       JB_Sav_SaveCollect, JB_Sav_SaveWrite );

JBClassPlace3( FastString,       JB_FS_Destructor,      JB_AsClass(JB_Object),      JB_Str_Render );
JBClassPlace3( ByteMap,          0,                     JB_AsClass(JB_Object),      JB_BM_Render );
JBClassPlace3( RingTree,         JB_Tree_Destructor,    JB_AsClass(Saveable),       0 );
JBClassPlace3( TokHan,           0,                     JB_AsClass(JB_Object),      0 );
JBClassPlace3( JB_Object,        0,                     0,                          0 );


ByteMap*            WhiteSpace_;
JB_StringC*         EmptyString_;
JBObject_Behaviour  JB_Object_FuncTable_ = {0,0};
JB_Class*           ClassList;
void                JB_Dict__Init();
char**              ArgV_; // externed...
static char**       Env_;
extern bool JB_ErrorsPrinted;




Array* JB_App__Args() { 
    static Array* App_Args;
    if (!App_Args) {
        App_Args = JB_Str_ArgV(ArgV_ + 1); // seems to take no ram?
        JB_Incr(App_Args);
    }

    return App_Args; 
}


Dictionary* JB_App__Env() {
    static Dictionary* App_Env;
    if (!App_Env) {
        App_Env = JB_C_Args_Env(Env_);
        JB_Incr(App_Env);
    }
    return App_Env;
}




int JB_LibInit() {
    if (JB_MemStandardWorld()->CurrSuper) {
        return 0;
    }

    EmptyString_ = JB_New( JB_StringC );
    if (!EmptyString_) {
        return 0x10000;
    }
    JB_Incr( EmptyString_ );
    EmptyString_->Length = 0;
	EmptyString_->Addr = (u8*)"";


    WhiteSpace_ = JB_BM_( JB_Str("\x9\xA\xD\x20"), JB_Str("....") );
    JB_FS__FastNew( 0 ); // stop leak tests catching this.
    JB_Date__Init();
    JB_Dict__Init();

    return JB_Init_();
}


int JB_LibShutdown() {
    JB_MemFree(JB_MemStandardWorld());
    return -(JB_ErrorsPrinted);
}


#ifndef AS_LIBRARY
void JB_App__Quit (int Code) {
    exit(Code);
}

int main (int ArgC, char** ArgV, char** Env) {
    ArgV_ = ArgV;
    Env_ = Env;
    JB_Pipe__InstallStackTrace();
    int Err = JB_LibInit();
    if (Err) {return Err;}
    Err = JB_Main();
    int StopErr = JB_LibShutdown();
//    Err |= JB_LibInit(); // i think the default blocks need resetting? we can do that?
//    StopErr |= JB_LibShutdown();
    if (!Err) {Err = StopErr;}
    return Err;
}
#endif


} // 



