

extern "C" {
    void JB_LibStartup();
    int  JB_HostSet (int a); // interfacing...
    void JB_HostClear (int a); // with host.
    void JB_HostException (const char* msg); // with host.
    JB_String* JB_Platform();
    Array* JB_App__Args();
    Dictionary* JB_App__Env();
    void JB_App__Quit (int Code);
    JB_String* JB_App__Path();
    int JB_LibInit();
    int JB_LibShutdown();
    

#if DEBUG
    #define JB_TestInterface(obj) if (!obj) {debugger;}
#else
    #define JB_TestInterface(obj)
#endif
} // ExternCEnd

