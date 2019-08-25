

extern "C" {
    JB_String* JB_Platform();
    Array* JB_App__Args();
    JB_String* JB_App__Readline(); 
    Dictionary* JB_App__Env();
    void JB_App__Quit (int Code);
    JB_String* JB_App__Path();
    void JB_Rec__PrintErrors();
    void JB_LibStartup();
    int JB_LibInit();
    int JB_LibShutdown();
    

#if DEBUG
    #define JB_TestInterface(obj) if (!obj) {debugger;}
#else
    #define JB_TestInterface(obj)
#endif
} // ExternCEnd

