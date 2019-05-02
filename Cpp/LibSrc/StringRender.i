
// Copyright, Theodore H. Smith 2019.
// Released under jeebox-licence http://jeebox.org/licence.txt




void JB_FS_AppendEscape(FastString* fs, JB_String* self);
                                          // actually made by jeebox... :/ sigh.
                                           // I suppose it COULD be built in? I mean... why not, at this point?
                                           // It's not as if I'm gonna be building tiny 4K apps...
                                           // more like a standard library/compiler/IDE/whatever
                                           // and... tiny 4k apps being VMed by it!!

                                           // Assuming Jeebox might be a GOOD thing. And it's small... besides. 90K?


JB_String* JB_Str_Render(JB_String* self, FastString* fs_in) {
    FastString* fs = JB_FS__FastNew(fs_in);
    JB_FS_AppendByte(fs, '"');
    JB_FS_AppendEscape(fs, self);
    JB_FS_AppendByte(fs, '"');
	return JB_FS_SmartResult( fs, fs_in );
}


JB_String* JB_CStr_Render(const char* Name, FastString* fs_in) {
    if (!fs_in) {
        return JB_Str(Name); 
    }
    
    JB_FS_AppendCString(fs_in, Name);
    return 0;
}


JB_String* JB_Obj_GenericRender(JB_Object* self, FastString* fs_in) {
    // OK so! We have... a generic renderer... what should it do?
    // well... let's see? something that parses OK in jeebox and we can understand OK?
    // ["abc"] // array of string
    // [1234]  // array of int-object
    // [(1,2,3)] // array of set
    // [RingTree(741)] // seems to make sense?
    FastString* fs = JB_FS__FastNew(fs_in);

    JB_Class* Cls = JB_ObjClass(self);
    JB_FS_AppendCString(fs, (const char*)Cls->Name);
    JB_FS_AppendCString(fs, "(");
    JB_FS_AppendIntegerAsText(fs, JB_ObjID(self), 1);
    JB_FS_AppendByte(fs, ')');

	return JB_FS_SmartResult( fs, fs_in );
}


JB_String* JB_ObjRender(JB_Object* self, FastString* fs_in) {
    // OK so first we want the class...
    if (!self) {
        return JB_CStr_Render("(nil)", fs_in);
    }
    
    JB_Class* Cls = JB_ObjClass(self);
    auto R = Cls->FuncTable->render;
    fpRenderer FN = (fpRenderer)R;
    if (!FN or (FN == JB_ObjRender)) {
        return JB_Obj_GenericRender(self, fs_in);
    }
    
    return (FN)(self, fs_in);
}



