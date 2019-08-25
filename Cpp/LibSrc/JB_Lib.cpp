
// Copyright, Theodore H. Smith 2019.
// Released under jeebox-licence http://jeebox.org/licence.txt



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
JBSaver_Behaviour a ## _FuncTable = {(void*)b,(void*)d,(void*)e,(void*)f,(void*)g};  \
JB_Class a ## Data = JBClassInit(a##Data, (#a), sizeof(a), c, (JBObject_Behaviour*)&(a##_FuncTable));


void JB_Array_SaveWrite(Array* self, void* Other);
void JB_Dict_SaveWrite(Dictionary* self, void* Other);
void JB_Array_SaveCollect(Array* self, void* Other);
void JB_Dict_SaveCollect(Dictionary* self, void* Other);
void JB_Dict_LoadProperties(Dictionary* self, void* Other);
void JB_Array_LoadProperties(Array* self, void* Other);

void JB_Sav_SaveCollect(Saveable* self, void* Saver);
void JB_Sav_SaveWrite(Saveable* self, void* Saver);
void JB_Sav_LoadProperties(Saveable* self, void* Other);


#ifndef AS_LIBRARY
JBClassPlace( JB_File,          JB_File_Destructor,    JB_AsClass(JB_Object),      JB_File_Render );
JBClassPlace( JB_Pipe,          JB_Pipe_Destructor,    JB_AsClass(JB_Object),      0 );
#endif

JBClassPlace( JB_String,        JB_BA_Destructor,      JB_AsClass(JB_Object),      JB_Str_Render );
JBClassPlace( JB_StringC,       0,                     JB_AsClass(JB_String),      JB_Str_Render );
JBClassPlace( JB_StringShared,  JB_Str_Destructor,     JB_AsClass(JB_String),      JB_Str_Render );
JBClassPlace( JB_StringExternal,JB_XStr_Destructor,    JB_AsClass(JB_String),      JB_Str_Render );
JBClassPlace( JB_String4,       0,                     JB_AsClass(JB_String),      JB_Str_Render );
JBClassPlace( JB_String20,      0,                     JB_AsClass(JB_String),      JB_Str_Render );

JBClassPlace( IntWrapper,       0,                     JB_AsClass(JB_Object),      0 );
JBClassPlace( Dictionary1,      JB_Dict_Destructor,    JB_AsClass(JB_Object),      0 );
JBClassPlace( Dictionary2,      JB_Dict_Destructor,    JB_AsClass(JB_Object),      0 );
JBClassPlace( Dictionary3,      JB_Dict_Destructor,    JB_AsClass(JB_Object),      0 );
JBClassPlace( Dictionary4,      JB_Dict_Destructor,    JB_AsClass(JB_Object),      0 );
JBClassPlace( DictionaryLeaf,   JB_Leaf_Destructor,    JB_AsClass(JB_Object),      0 );
JBClassPlace( DictionaryReader, JB_Nav_Destructor,     JB_AsClass(JB_Object),      0 );

JBClassPlaceSaver( Dictionary,   JB_Dict_Destructor,    JB_AsClass(Saveable),       JB_Dict_Render,  JB_Dict_LoadProperties,  JB_Dict_SaveCollect, JB_Dict_SaveWrite );
JBClassPlaceSaver( Array,        JB_Array_Destructor,   JB_AsClass(Saveable),       JB_Array_Render, JB_Array_LoadProperties, JB_Array_SaveCollect, JB_Array_SaveWrite );
JBClassPlaceSaver( Saveable,     0,                     0,                          0,               JB_Sav_LoadProperties,                       JB_Sav_SaveCollect, JB_Sav_SaveWrite );

JBClassPlace( FastString,       JB_FS_Destructor,      JB_AsClass(JB_Object),      JB_Str_Render );
JBClassPlace( ByteMap,          0,                     JB_AsClass(JB_Object),      JB_BM_Render );
JBClassPlace( RingTree,         JB_Ring_Destructor,    JB_AsClass(Saveable),       0 );
JBClassPlace( TokHan,           0,                     JB_AsClass(JB_Object),      0 );


ByteMap*            WhiteSpace_;
JB_StringC*         EmptyString_;
JBObject_Behaviour  JB_Object_FuncTable_ = {0,0};
JB_Class*           ClassList;
void                JB_Dict__Init();
char**              ArgV_; // externed...
static char**       Env_;




Array* JB_App__Args() { 
//    const char* aasds[] = {"a", "b", "c"};
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
    if (sizeof(int)!=4) {
        puts("sizeof(int) is not 4! Jeebox not compiled properly.");
    }
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


extern bool JB_ErrorsPrinted; // terminals complain if printerror without return -1;
int JB_LibShutdown() {
    JB_MemFree(JB_MemStandardWorld());
    return -JB_ErrorsPrinted;
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
    JB_Rec__PrintErrors();
    int StopErr = JB_LibShutdown();
    if (!Err) {Err = StopErr;}
    return Err;
}
#endif


} // 



