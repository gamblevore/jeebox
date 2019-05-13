

 // Auto-generated file, by speedie.

/* jeebox-licence:
    By Theodore H. Smith, 2019, theo@jeebox.org

    This software is provided 'as-is', without any warranty.
    In no event will the authors be held liable for any damages
    arising from the use of this software.

    Permission is granted to anyone to use this software for any purpose,
    including commercially, and to alter it and redistribute it
    freely, subject to the following restrictions:

    1. The origin of this software must not be misrepresented; you must not
        claim that you wrote the original software.
    2. If you use this software or portions of this software in a product, you
        are required to acknowledge this in at least one of:
        About-window / launch-screen / help-files / read-me-file
    3. Altered source versions must be plainly marked as such, and must not be
        misrepresented as being the original software.
    4. Any jeebox-licence note may not be removed/altered from any source distribution.
*/


#ifndef __JB_H__
#define __JB_H__

extern "C" {

//// HEADER AllTypes.h


struct JB_Class;

struct FreeObject;

struct LLRef;

struct ObjectLoader;

struct ObjectSaver;

struct Random;

struct StructSaveTest;

struct Object_Behaviour;

struct MemoryLayer_Behaviour;

struct Pipe_Behaviour;

struct Saveable_Behaviour;

struct Selector_Behaviour;

struct String_Behaviour;

struct StringFields_Behaviour;

struct TokenHandler_Behaviour;

struct Syntax_Behaviour;

typedef u8 byte;

typedef s64 Date;

struct Array_Behaviour;

struct Charset_Behaviour;

struct Dictionary_Behaviour;

struct DictionaryReader_Behaviour;

struct FastAppender_Behaviour;

struct FastString_Behaviour;

struct File_Behaviour;

struct FixedDict_Behaviour;

struct LeakTester_Behaviour;

struct StripMe_Behaviour;

struct LinkedList_Behaviour;

struct RingTree_Behaviour;

struct SaverClassInfo_Behaviour;

struct ErrorReceiver_Behaviour;

struct Error_Behaviour;

struct Message_Behaviour;

struct FastAppenderChunk_Behaviour;

struct JB_Object;

struct ByteMap;

struct DictionaryReader;

struct FastString;

struct JB_File;

struct LeakTester;

struct JB_MemoryLayer;

struct Saveable;

struct JB_String;

struct StringFields;

struct Syntax;

struct TokHan;

struct Array;

struct Dictionary;

struct FastAppender;

struct JB_LinkedList;

struct RingTree;

struct SaverClassInfo;

struct JB_Error;

struct JB_ErrorReceiver;

struct FastAppenderChunk;

struct Message;

typedef void (*fpDestructor)(JB_Object* self);

typedef void (*fpMsgRender)(Message* self, FastString* fs);

typedef Message* (*ParseHandler)(int Start);

typedef JB_Object* (*TokenHandler_fp)(int Start);

typedef JB_String* (*__Object_Render__)(JB_Object* self, FastString* fs_in);

typedef void (*__Saveable_LoadProperties__)(Saveable* self, ObjectLoader* Loader);

typedef void (*__Saveable_SaveCollect__)(Saveable* self, ObjectSaver* Saver);

typedef void (*__Saveable_SaveWrite__)(Saveable* self, ObjectSaver* Saver);

//// HEADER Proj.h

struct LLRef {
	JB_LinkedList* First;
};

struct ObjectLoader {
	Dictionary* Dict;
	Message* CurrItem;
	JB_Object* CouldntLoad;
	Saveable* Result;
	Message* DataError;
	Message* NoClass;
};

struct ObjectSaver {
	FastString* Dest;
	JB_Object* CantSaveThis;
};

struct Random {
	u64 Fast;
	u64 Adder;
};

struct StructSaveTest {
	Saveable* Sav;
	int Intt;
	JB_String* Str;
};

struct Object_Behaviour {
	void* __destructor__;
	__Object_Render__ render;
};

struct Charset_Behaviour: Object_Behaviour {
};

struct DictionaryReader_Behaviour: Object_Behaviour {
};

struct FastString_Behaviour: Object_Behaviour {
};

struct File_Behaviour: Object_Behaviour {
};

struct LeakTester_Behaviour: Object_Behaviour {
};

JBClass ( LeakTester , JB_Object , 
	int MemUsedStart;
	JB_String* Name;
);

struct MemoryLayer_Behaviour: Object_Behaviour {
};

struct Saveable_Behaviour: Object_Behaviour {
	__Saveable_LoadProperties__ loadproperties;
	__Saveable_SaveCollect__ savecollect;
	__Saveable_SaveWrite__ savewrite;
};

struct String_Behaviour: Object_Behaviour {
};

struct StringFields_Behaviour: Object_Behaviour {
};

JBClass ( StringFields , JB_Object , 
	JB_String* Data;
	JB_String* Sep;
	int SepLen;
);

struct Syntax_Behaviour: Object_Behaviour {
};

JBClass ( Syntax , JB_Object , 
	fpMsgRender RenderAddr;
	fpMsgRender ExportAddr;
	JB_String* Name;
	JB_String* LongName;
	int ID;
);

struct TokenHandler_Behaviour: Object_Behaviour {
};

struct Array_Behaviour: Saveable_Behaviour {
};

struct Dictionary_Behaviour: Saveable_Behaviour {
};

struct FastAppender_Behaviour: Saveable_Behaviour {
};

JBClass ( FastAppender , Saveable , 
	FastAppenderChunk* ActualFirst;
	int DbgCount;
	LLRef Chunks;
);

struct LinkedList_Behaviour: Saveable_Behaviour {
};

struct RingTree_Behaviour: Saveable_Behaviour {
};

struct SaverClassInfo_Behaviour: FastAppender_Behaviour {
};

JBClass ( SaverClassInfo , FastAppender , 
	JB_Class* Cls;
	SaverClassInfo* NextInfo;
	s8* Data;
);

struct Error_Behaviour: LinkedList_Behaviour {
};

JBClass ( JB_Error , JB_LinkedList , 
	int Position;
	int ErrorLevel;
	JB_String* Path;
	JB_String* Description;
	JB_String* OriginalData;
	Message* Node;
);

struct ErrorReceiver_Behaviour: LinkedList_Behaviour {
};

JBClass ( JB_ErrorReceiver , JB_LinkedList , 
	LLRef List;
	int MaxErrors;
	int ErrorCount;
	int WarnCount;
	JB_String* Source;
);

struct FastAppenderChunk_Behaviour: LinkedList_Behaviour {
};

JBClass ( FastAppenderChunk , JB_LinkedList , 
	FastAppenderChunk* Prev;
	int NItems;
	JB_Object* Items[31];
);

struct Message_Behaviour: RingTree_Behaviour {
};

JBClass ( Message , RingTree , 
	JB_Object* Obj;
	Syntax* Type;
	JB_String* Name;
	int Position;
);


// module: __classes__


// module: __modules__


// module: App


// module: Compression


// module: ErrorColors
#define kJB__ErrorColors_bold (JB_str_168)
#define kJB__ErrorColors_error (JB_str_169)
#define kJB__ErrorColors_good (JB_str_170)
#define kJB__ErrorColors_normal (JB_str_167)
#define kJB__ErrorColors_underline (JB_str_170)
#define kJB__ErrorColors_warn (JB_str_171)
//




// module: API
extern u16 JB__API_NilHappened;
//




// module: Constants
extern ByteMap* JB__Constants_CSAfterTemporal;
extern ByteMap* JB__Constants_CSLine;
extern ByteMap* JB__Constants_CSLineBlack;
extern ByteMap* JB__Constants_CSNum;
extern ByteMap* JB__Constants_CSNumUnit;
extern ByteMap* JB__Constants_CSWordMiddle;
extern ByteMap* JB__Constants_CSWordStart;
extern Dictionary* JB__Constants_EscapeChr;
extern Dictionary* JB__Constants_EscapeStr;
extern Dictionary* JB__Constants_UnEscapeStr;
//




// module: LowLevel


// module: Math
#define kJB__Math_E (2.7182818284590452353602874713526)
#define kJB__Math_PI (3.1415926535897932384626433832795)
#define kJB__Math_PI2 (6.2831853071795864769252867665590)
//




// module: Tk
extern int JB__Tk_BaseMessagePosition;
extern Message* JB__Tk_ErrNode;
extern Dictionary* JB__Tk_ErrorNames;
#define kJB__Tk_adjectiveop (1)
#define kJB__Tk_Allow (0)
#define kJB__Tk_bracketstart (2)
#define kJB__Tk_colon (4)
#define kJB__Tk_End ((8 | 16) | 32)
#define kJB__Tk_EndContainer (16)
#define kJB__Tk_EndOfLine (8)
#define kJB__Tk_Expect (1)
#define kJB__Tk_FreeWords (0)
#define kJB__Tk_FuncAfterAny ((64 | 128) | 256)
#define kJB__Tk_FuncAfterBar (64)
#define kJB__Tk_FuncAfterNormal (128)
#define kJB__Tk_FuncAfterNoSpace (256)
#define kJB__Tk_IllegalChar (0x80000000)
#define kJB__Tk_Opp (((512 | 1024) | 2048) | 4096)
#define kJB__Tk_OppBra (512)
#define kJB__Tk_OppChain (4096 | 512)
#define kJB__Tk_OppSyx (1024)
#define kJB__Tk_OppTemporal (2048)
#define kJB__Tk_OppWord (4096)
#define kJB__Tk_SyntacticComment (32)
#define kJB__Tk_Temporal (8192 | 16384)
#define kJB__Tk_TemporalSyx (8192)
#define kJB__Tk_TemporalWord (16384)
#define kJB__Tk_Thing (32768 | 65536)
#define kJB__Tk_ThingSyx (32768)
#define kJB__Tk_ThingWord (65536)
#define kJB__Tk_TmpOpp (2048 | 8192)
#define kJB__Tk_words_line (131072)
#define kJB__Tk_LargestFlag (18)
extern int JB__Tk_StopBars;
//




// module: Platform


// module: JB


// module: JB


// module: JB
extern Array* JB_FuncArray;
#define kJB_SaverEnd (JB_str_0)
#define kJB_SaverStart1 (JB_str_166)
extern JB_ErrorReceiver* JB_StdErr;
extern JB_String* JB_str_0;
extern JB_String* JB_str_1;
extern JB_String* JB_str_10;
extern JB_String* JB_str_100;
extern JB_String* JB_str_101;
extern JB_String* JB_str_102;
extern JB_String* JB_str_103;
extern JB_String* JB_str_104;
extern JB_String* JB_str_105;
extern JB_String* JB_str_106;
extern JB_String* JB_str_107;
extern JB_String* JB_str_108;
extern JB_String* JB_str_109;
extern JB_String* JB_str_11;
extern JB_String* JB_str_110;
extern JB_String* JB_str_111;
extern JB_String* JB_str_112;
extern JB_String* JB_str_113;
extern JB_String* JB_str_114;
extern JB_String* JB_str_115;
extern JB_String* JB_str_116;
extern JB_String* JB_str_117;
extern JB_String* JB_str_118;
extern JB_String* JB_str_119;
extern JB_String* JB_str_12;
extern JB_String* JB_str_120;
extern JB_String* JB_str_121;
extern JB_String* JB_str_122;
extern JB_String* JB_str_123;
extern JB_String* JB_str_124;
extern JB_String* JB_str_125;
extern JB_String* JB_str_126;
extern JB_String* JB_str_127;
extern JB_String* JB_str_128;
extern JB_String* JB_str_129;
extern JB_String* JB_str_13;
extern JB_String* JB_str_130;
extern JB_String* JB_str_131;
extern JB_String* JB_str_132;
extern JB_String* JB_str_133;
extern JB_String* JB_str_134;
extern JB_String* JB_str_135;
extern JB_String* JB_str_136;
extern JB_String* JB_str_137;
extern JB_String* JB_str_138;
extern JB_String* JB_str_139;
extern JB_String* JB_str_14;
extern JB_String* JB_str_140;
extern JB_String* JB_str_141;
extern JB_String* JB_str_142;
extern JB_String* JB_str_143;
extern JB_String* JB_str_144;
extern JB_String* JB_str_145;
extern JB_String* JB_str_146;
extern JB_String* JB_str_147;
extern JB_String* JB_str_148;
extern JB_String* JB_str_149;
extern JB_String* JB_str_15;
extern JB_String* JB_str_150;
extern JB_String* JB_str_151;
extern JB_String* JB_str_152;
extern JB_String* JB_str_153;
extern JB_String* JB_str_154;
extern JB_String* JB_str_155;
extern JB_String* JB_str_156;
extern JB_String* JB_str_157;
extern JB_String* JB_str_158;
extern JB_String* JB_str_159;
extern JB_String* JB_str_16;
extern JB_String* JB_str_160;
extern JB_String* JB_str_161;
extern JB_String* JB_str_162;
extern JB_String* JB_str_163;
extern JB_String* JB_str_164;
extern JB_String* JB_str_165;
extern JB_String* JB_str_166;
extern JB_String* JB_str_167;
extern JB_String* JB_str_168;
extern JB_String* JB_str_169;
extern JB_String* JB_str_17;
extern JB_String* JB_str_170;
extern JB_String* JB_str_171;
extern JB_String* JB_str_172;
extern JB_String* JB_str_173;
extern JB_String* JB_str_174;
extern JB_String* JB_str_175;
extern JB_String* JB_str_176;
extern JB_String* JB_str_177;
extern JB_String* JB_str_178;
extern JB_String* JB_str_179;
extern JB_String* JB_str_18;
extern JB_String* JB_str_180;
extern JB_String* JB_str_181;
extern JB_String* JB_str_182;
extern JB_String* JB_str_183;
extern JB_String* JB_str_184;
extern JB_String* JB_str_185;
extern JB_String* JB_str_186;
extern JB_String* JB_str_187;
extern JB_String* JB_str_188;
extern JB_String* JB_str_189;
extern JB_String* JB_str_19;
extern JB_String* JB_str_190;
extern JB_String* JB_str_191;
extern JB_String* JB_str_192;
extern JB_String* JB_str_193;
extern JB_String* JB_str_194;
extern JB_String* JB_str_195;
extern JB_String* JB_str_196;
extern JB_String* JB_str_197;
extern JB_String* JB_str_198;
extern JB_String* JB_str_199;
extern JB_String* JB_str_2;
extern JB_String* JB_str_20;
extern JB_String* JB_str_200;
extern JB_String* JB_str_201;
extern JB_String* JB_str_202;
extern JB_String* JB_str_203;
extern JB_String* JB_str_204;
extern JB_String* JB_str_205;
extern JB_String* JB_str_206;
extern JB_String* JB_str_207;
extern JB_String* JB_str_208;
extern JB_String* JB_str_209;
extern JB_String* JB_str_21;
extern JB_String* JB_str_210;
extern JB_String* JB_str_211;
extern JB_String* JB_str_212;
extern JB_String* JB_str_213;
extern JB_String* JB_str_214;
extern JB_String* JB_str_215;
extern JB_String* JB_str_216;
extern JB_String* JB_str_217;
extern JB_String* JB_str_218;
extern JB_String* JB_str_219;
extern JB_String* JB_str_22;
extern JB_String* JB_str_220;
extern JB_String* JB_str_221;
extern JB_String* JB_str_222;
extern JB_String* JB_str_223;
extern JB_String* JB_str_224;
extern JB_String* JB_str_225;
extern JB_String* JB_str_226;
extern JB_String* JB_str_227;
extern JB_String* JB_str_228;
extern JB_String* JB_str_229;
extern JB_String* JB_str_23;
extern JB_String* JB_str_230;
extern JB_String* JB_str_231;
extern JB_String* JB_str_232;
extern JB_String* JB_str_233;
extern JB_String* JB_str_234;
extern JB_String* JB_str_235;
extern JB_String* JB_str_236;
extern JB_String* JB_str_237;
extern JB_String* JB_str_238;
extern JB_String* JB_str_239;
extern JB_String* JB_str_24;
extern JB_String* JB_str_240;
extern JB_String* JB_str_241;
extern JB_String* JB_str_242;
extern JB_String* JB_str_243;
extern JB_String* JB_str_244;
extern JB_String* JB_str_245;
extern JB_String* JB_str_246;
extern JB_String* JB_str_247;
extern JB_String* JB_str_248;
extern JB_String* JB_str_249;
extern JB_String* JB_str_25;
extern JB_String* JB_str_250;
extern JB_String* JB_str_251;
extern JB_String* JB_str_252;
extern JB_String* JB_str_253;
extern JB_String* JB_str_254;
extern JB_String* JB_str_255;
extern JB_String* JB_str_256;
extern JB_String* JB_str_257;
extern JB_String* JB_str_258;
extern JB_String* JB_str_259;
extern JB_String* JB_str_26;
extern JB_String* JB_str_260;
extern JB_String* JB_str_261;
extern JB_String* JB_str_27;
extern JB_String* JB_str_28;
extern JB_String* JB_str_29;
extern JB_String* JB_str_3;
extern JB_String* JB_str_30;
extern JB_String* JB_str_31;
extern JB_String* JB_str_32;
extern JB_String* JB_str_33;
extern JB_String* JB_str_34;
extern JB_String* JB_str_35;
extern JB_String* JB_str_36;
extern JB_String* JB_str_37;
extern JB_String* JB_str_38;
extern JB_String* JB_str_39;
extern JB_String* JB_str_4;
extern JB_String* JB_str_40;
extern JB_String* JB_str_41;
extern JB_String* JB_str_42;
extern JB_String* JB_str_43;
extern JB_String* JB_str_44;
extern JB_String* JB_str_45;
extern JB_String* JB_str_46;
extern JB_String* JB_str_47;
extern JB_String* JB_str_48;
extern JB_String* JB_str_49;
extern JB_String* JB_str_5;
extern JB_String* JB_str_50;
extern JB_String* JB_str_51;
extern JB_String* JB_str_52;
extern JB_String* JB_str_53;
extern JB_String* JB_str_54;
extern JB_String* JB_str_55;
extern JB_String* JB_str_56;
extern JB_String* JB_str_57;
extern JB_String* JB_str_58;
extern JB_String* JB_str_59;
extern JB_String* JB_str_6;
extern JB_String* JB_str_60;
extern JB_String* JB_str_61;
extern JB_String* JB_str_62;
extern JB_String* JB_str_63;
extern JB_String* JB_str_64;
extern JB_String* JB_str_65;
extern JB_String* JB_str_66;
extern JB_String* JB_str_67;
extern JB_String* JB_str_68;
extern JB_String* JB_str_69;
extern JB_String* JB_str_7;
extern JB_String* JB_str_70;
extern JB_String* JB_str_71;
extern JB_String* JB_str_72;
extern JB_String* JB_str_73;
extern JB_String* JB_str_74;
extern JB_String* JB_str_75;
extern JB_String* JB_str_76;
extern JB_String* JB_str_77;
extern JB_String* JB_str_78;
extern JB_String* JB_str_79;
extern JB_String* JB_str_8;
extern JB_String* JB_str_80;
extern JB_String* JB_str_81;
extern JB_String* JB_str_82;
extern JB_String* JB_str_83;
extern JB_String* JB_str_84;
extern JB_String* JB_str_85;
extern JB_String* JB_str_86;
extern JB_String* JB_str_87;
extern JB_String* JB_str_88;
extern JB_String* JB_str_89;
extern JB_String* JB_str_9;
extern JB_String* JB_str_90;
extern JB_String* JB_str_91;
extern JB_String* JB_str_92;
extern JB_String* JB_str_93;
extern JB_String* JB_str_94;
extern JB_String* JB_str_95;
extern JB_String* JB_str_96;
extern JB_String* JB_str_97;
extern JB_String* JB_str_98;
extern JB_String* JB_str_99;
extern Syntax* JB_SyxAcc;
extern Syntax* JB_SyxAdj;
extern Syntax* JB_SyxAna;
extern Syntax* JB_SyxARel;
extern Syntax* JB_SyxArg;
extern Syntax* JB_SyxArr;
extern Syntax* JB_SyxBack;
extern Syntax* JB_SyxBin;
extern Syntax* JB_SyxBra;
extern Syntax* JB_SyxBRel;
extern Syntax* JB_SyxChar;
extern Syntax* JB_SyxCnj;
extern Syntax* JB_SyxDecl;
extern Dictionary* JB_SyxDict;
extern Syntax* JB_SyxDot;
extern Syntax* JB_SyxEmb;
extern Syntax* JB_SyxERel;
extern Syntax* JB_SyxFunc;
extern Syntax* JB_SyxItem;
extern Syntax* JB_SyxList;
extern Syntax* JB_SyxName;
extern Syntax* JB_SyxNum;
extern Syntax* JB_SyxOat;
extern Syntax* JB_SyxOpp;
extern Syntax* JB_SyxPrm;
extern Syntax* JB_SyxRel;
extern Syntax* JB_SyxSCnj;
extern Syntax* JB_SyxSCom;
extern Syntax* JB_SyxSDot;
extern Syntax* JB_SyxSheb;
extern Syntax* JB_SyxSOpp;
extern Syntax* JB_SyxSStr;
extern Syntax* JB_SyxSThg;
extern Syntax* JB_SyxStr;
extern Syntax* JB_SyxThg;
extern Syntax* JB_SyxTmp;
extern Syntax* JB_SyxTRel;
extern Syntax* JB_SyxType;
extern Syntax* JB_SyxUnit;
//




// module: _cstring_


// module: _voidptr_


// module: bool_


// module: ClassData_


// module: dbl_


// module: FastAppenderLister_


// module: f_


// module: FloatRange_


// module: FreeObject_


// module: f16_


// module: int_
#define kJB__int_max (0x7FFFffff)
#define kJB__int_min (0x80000000)
//




// module: IntDownRange_


// module: IntRange_


// module: LLRef_


// module: MemoryWorld_


// module: MsgPos_


// module: Loader_
extern Dictionary* JB__Loader_ClassList;
//




// module: Saver_
extern SaverClassInfo* JB__Saver_SaveableList;
//




// module: OverFlow_


// module: Random_
extern Random JB__Random_Shared;
//




// module: s16_
#define kJB__s16_max (0x7fff)
#define kJB__s16_min (0x8000)
//




// module: s64_


// module: s8_
#define kJB__s8_max (0x7f)
#define kJB__s8_min (0x80)
//




// module: StructSaveTest_


// module: u16_
#define kJB__u16_max (0xffff)
#define kJB__u16_min (0)
//




// module: u32_
#define kJB__u32_max (0xffffFFFF)
#define kJB__u32_min (0)
//




// module: u64_
#define kJB__u64_max (-1)
//




// module: u8_
#define kJB__u8_max (0xff)
#define kJB__u8_min (0)
//




// module: Object_Behaviour_


// module: MemoryLayer_Behaviour_


// module: Pipe_Behaviour_


// module: Saveable_Behaviour_


// module: Selector_Behaviour_


// module: String_Behaviour_


// module: StringFields_Behaviour_


// module: TokenHandler_Behaviour_


// module: Syntax_Behaviour_


// module: byte_


// module: Date_
#define kJB__Date_ClocksPerSecond (1000000)
#define kJB__Date_OneSecond (0x010000)
#define kJB__Date_SecondsPerDay (86400)
#define kJB__Date_SecondsPerWeek (604800)
#define kJB__Date_TickBits (16)
#define kJB__Date_Ticks (0x010000)
//




// module: Array_Behaviour_


// module: Charset_Behaviour_


// module: Dictionary_Behaviour_


// module: DictionaryReader_Behaviour_


// module: FastAppender_Behaviour_


// module: FastString_Behaviour_


// module: File_Behaviour_


// module: FixedDict_Behaviour_


// module: LeakTester_Behaviour_


// module: StripMe_Behaviour_


// module: LinkedList_Behaviour_


// module: RingTree_Behaviour_


// module: SaverClassInfo_Behaviour_


// module: ErrorReceiver_Behaviour_


// module: Error_Behaviour_


// module: Message_Behaviour_


// module: FastAppenderChunk_Behaviour_


// module: Object_


// module: BM_


// module: DictionaryReader_


// module: FS_
extern FastString* JB__FS_StdOutFS;
//




// module: File_
#define kJB__File_CreateErrors (false)
#define kJB__File_IgnoreErrors (true)
#define kJB__File_O_APPEND (0x0008)
#define kJB__File_O_CREAT (0x0200)
#define kJB__File_O_EXCL (0x0800)
#define kJB__File_O_RDONLY (0x0000)
#define kJB__File_O_RDWR (0x0002)
#define kJB__File_O_TRUNC (0x0400)
#define kJB__File_O_WRONLY (0x0001)
//




// module: FDT_


// module: Lk_


// module: Mem_


// module: Pipe_
#define kJB__Pipe_StdErr_ (2)
#define kJB__Pipe_StdIn_ (0)
#define kJB__Pipe_StdOut_ (1)
//




// module: Sav_


// module: Sel_


// module: Str_
#define kJB__Str_UTF16BE (17)
#define kJB__Str_UTF16LE (16)
#define kJB__Str_UTF32BE (33)
#define kJB__Str_UTF32LE (32)
//




// module: FI_


// module: StripMe_


// module: Fn_


// module: TH_


// module: fpDestructor_


// module: fpMsgRender_


// module: ParseHandler_


// module: SaverLoadClass_


// module: TokenHandler_fp_


// module: __Render___


// module: __LoadProperties___


// module: __SaveCollect___


// module: __SaveWrite___


// module: Array_


// module: Dict_


// module: FAP_
extern bool JB__FAP_Tested;
//




// module: LinkedList_


// module: Tree_


// module: sci_


// module: Err_
#define kJB__Err_CriticalError (0)
#define kJB__Err_MightBeAnError (5)
#define kJB__Err_NormalError (1)
#define kJB__Err_WarningError (4)
//




// module: Rec_


// module: FAC_


// module: Msg_

//// HEADER JB.h



// __classes__


// __modules__


// App


// Compression


// ErrorColors


// API
Message* JB_API__errors();

int JB_API__Init(int flags);

int JB_API__Init_();

void JB_API__NilCallBack(JB_String* ErrorMessage);

bool JB_API__NilHandler();

Message* JB_API__Parse(JB_String* s, JB_String* path);



// Constants
int JB_Constants__Init_();

JB_String* JB_Constants__Test();



// LowLevel


// Math


// Tk
Message* JB_Tk__BarThings(int Start, Syntax* Syx);

Message* JB_Tk__BeforeRelSub(int Start, int Mode);

Message* JB_Tk__ChainTemporalRels(Message* FirstThing, Message* opp);

bool JB_Tk__ConsumeLines(Message* output, Message* msg);

Message* JB_Tk__DotSub(Syntax* fn, int Start);

int JB_Tk__EmbeddedArg(JB_String* close, Message* result, Syntax* Mode);

int JB_Tk__EmbeddedCode(JB_String* close, Message* dest, int Mode);

Message* JB_Tk__ErrorAdd(JB_String* s, int Start, bool WasEnder);

void JB_Tk__ErrorEvent2(int Start, int ExpectedBits, int RealBits);

bool JB_Tk__ExpectEndChar(byte s, bool Expect);

Message* JB_Tk__fAccess(int Start);

Message* JB_Tk__fAdjectiveOp(int Start);

Message* JB_Tk__fAdjectiveThing(int Start);

Message* JB_Tk__fAfterRel(int Start);

Message* JB_Tk__fAnaphoricReference(int Start);

Message* JB_Tk__fArray(int Start);

Message* JB_Tk__fAtName(int Start);

Message* JB_Tk__fAtNamedExp(int Start);

Message* JB_Tk__fBackTick(int Start);

Message* JB_Tk__fBarTypeCast(int Start);

Message* JB_Tk__fBeforeRel(int Start);

Message* JB_Tk__fBeforeRelMinus(int Start);

Message* JB_Tk__fBinary(int Start);

Message* JB_Tk__fBracket(int Start);

Message* JB_Tk__fChr(int Start);

Message* JB_Tk__fComment(int Start);

Message* JB_Tk__fCommentLine(int Start);

Message* JB_Tk__fDecl(int Start);

Message* JB_Tk__fDot(int Start);

Message* JB_Tk__fError(int Start);

Message* JB_Tk__fFuncCall(int Start);

int JB_Tk__FindError(int num);

Message* JB_Tk__fNumber(int Start);

Message* JB_Tk__fOpAsThing(int Start);

Message* JB_Tk__fOppBracket(int Start);

Message* JB_Tk__fOppSyx(int Start);

Message* JB_Tk__fOppSyxNeq(int Start);

Message* JB_Tk__fOppWord(int Start);

Message* JB_Tk__fSDot(int Start);

Message* JB_Tk__fShebang(int Start);

Message* JB_Tk__fStatementOpen(int Start);

Message* JB_Tk__fString(int Start);

Message* JB_Tk__fStrSub(int Start, JB_String* Ender, Syntax* syx);

Message* JB_Tk__fSuperStr(int Start);

Message* JB_Tk__fSyntacticComment(int Start);

Message* JB_Tk__fTemporalAsThing(int Start);

Message* JB_Tk__fTemporalRel(int Start);

Message* JB_Tk__fTemporalRelSyx(int Start);

Message* JB_Tk__fTemporalStatement(int Start);

Message* JB_Tk__fThingSyx(int Start);

Message* JB_Tk__fThingWord(int Start);

Message* JB_Tk__GetFuncAfter(Message* input);

void JB_Tk__Init();

int JB_Tk__Init_();

int JB_Tk__IsHexLike(JB_String* S, int N);

Message* JB_Tk__MakeRel(Message* first, int Bits);

int JB_Tk__MessageErrorSub(FastString* fs, int num, int ButFound);

Message* JB_Tk__NewParent(Message* Parent, Syntax* Func, int Start, int End);

Message* JB_Tk__NewParent0(Message* Parent, Syntax* Func, int Start);

Message* JB_Tk__NewParentName(Message* Parent, Syntax* Func, int Start, JB_String* name);

Message* JB_Tk__NewSkip(Message* P, Syntax* F, int Start, int NameStart, int NameEnd);

Message* JB_Tk__NewWord(Message* P, Syntax* F, int Start, int SearchFrom);

bool JB_Tk__NoFuncAfter(byte b);

Message* JB_Tk__NumberSub(int Start, int RealStart);

int JB_Tk__NumEnd(JB_String* D, int Start);

bool JB_Tk__OK();

Message* JB_Tk__OppChain(Message* opp);

void JB_Tk__Params(Message* Parent, int N);

Message* JB_Tk__ParseItem(Message* ch, int TemporalFlags);

bool JB_Tk__ParseLoop(Message* Output, byte Ender);

bool JB_Tk__ParseLoopMode(Message* Output, int Flags);

Message* JB_Tk__ProcessThing(int Ops, int Expect);

Message* JB_Tk__ReRoute(Message* cnj, Message* output);

void JB_Tk__StopParse();

void JB_Tk__Tokens(Array* arr, int bits, ParseHandler func);

void JB_Tk__TokensHandler(Array* arr, TokHan* H);

void JB_Tk__Tokenz(JB_String* s, int bits, ParseHandler func);

bool JB_Tk__WillEnd();

int JB_Tk__WordAfter(int Start);



// Platform
bool JB_Platform__linux();



// main
void JB_BinaryEscapeTest(JB_String* AllBytes);

bool JB_CompareError(Message* expected, Message* found);

Dictionary* JB_Dict_Copy(Dictionary* Dict);

JB_String* JB_EntityTest();

int JB_Init_();

int JB_Main();

Dictionary* JB_Dict_Reverse(Dictionary* Dict);

bool JB_TestCasting();



// _cstring


// _voidptr


// bool


// JB_ClassData
void JB_ClassData_Restore(JB_Class* self);



// f64


// JB_FastAppenderLister


// float
JB_String* JB_f_Render(float self, FastString* fs_in);



// JB_FloatRange


// JB_FreeObject


// hfloat


// int
inline bool JB_int_Found(int self);

int JB_int_OperatorMin(int self, int other);

JB_String* JB_int_Render(int self, FastString* fs_in);



// JB_IntDownRange


// JB_IntRange


// JB_List
void JB_LLRef_Clear(LLRef* self);

void JB_LLRef_Destructor(LLRef* self);

void JB_LLRef_HeaderSanity(LLRef* self);

int JB_LLRef_ListCount(LLRef* self);

void JB_LLRef_SyntaxAppend(LLRef* self, JB_LinkedList* L);



// JB_MemoryWorld


// JB_MessagePosition


// JB_ObjectLoader
bool JB_Loader_HasItem(ObjectLoader* self);

s64 JB_Loader_Int(ObjectLoader* self);

s64 JB_Loader_ItemInt(ObjectLoader* self);

bool JB_Loader_ItemIsInt(ObjectLoader* self);

JB_String* JB_Loader_ItemName(ObjectLoader* self);

JB_Object* JB_Loader_ItemObject(ObjectLoader* self);

void JB_Loader_ListStoreAt(ObjectLoader* self, JB_LinkedList** Place);

Message* JB_Loader_Next(ObjectLoader* self);

JB_Object* JB_Loader_Object(ObjectLoader* self);

JB_Object* JB_Loader_ObjectSub(ObjectLoader* self, Message* c);

JB_String* JB_Loader_String(ObjectLoader* self);



// JB_ObjectSaver
void JB_Saver_AppendInt(ObjectSaver* self, s64 i);

void JB_Saver_AppendObject(ObjectSaver* self, JB_Object* o);

void JB_Saver_AppendString(ObjectSaver* self, JB_String* s);

void JB_Saver_Destructor(ObjectSaver* self);

int JB_Saver__Init_();



// JB_OverFlow


// JB_Random
void JB_Random_LoadProperties(Random* self, ObjectLoader* Loader);

void JB_Random_SaveWrite(Random* self, ObjectSaver* Saver);

int JB_Random__Init_();



// s16


// s64
JB_String* JB_s64_Render(s64 self, FastString* fs_in);



// s8


// JB_StructSaveTest
void JB_StructSaveTest_LoadProperties(StructSaveTest* self, ObjectLoader* Loader);

void JB_StructSaveTest_SaveWrite(StructSaveTest* self, ObjectSaver* Saver);



// u16


// u32


// u64


// u8


// JB_Object_Behaviour


// JB_MemoryLayer_Behaviour


// JB_Pipe_Behaviour


// JB_Saveable_Behaviour


// JB_Selector_Behaviour


// JB_String_Behaviour


// JB_StringFields_Behaviour


// JB_TokenHandler_Behaviour


// JB_Syntax_Behaviour


// byte
bool JB_byte_CanPrintAsNormalChar(byte self);

bool JB_byte_IsNum(byte self);

bool JB_byte_IsNumeric(byte self);

JB_String* JB_byte_Render(byte self, FastString* fs_in);



// Date
JB_String* JB_Date_Render(Date self, FastString* fs_in);



// JB_Array_Behaviour


// JB_Charset_Behaviour


// JB_Dictionary_Behaviour


// JB_DictionaryReader_Behaviour


// JB_FastAppender_Behaviour


// JB_FastString_Behaviour


// JB_File_Behaviour


// JB_FixedDict_Behaviour


// JB_LeakTester_Behaviour


// JB_StripMe_Behaviour


// JB_LinkedList_Behaviour


// JB_RingTree_Behaviour


// JB_SaverClassInfo_Behaviour


// JB_ErrorReceiver_Behaviour


// JB_Error_Behaviour


// JB_Message_Behaviour


// JB_FastAppenderChunk_Behaviour


// JB_Object
void JB_DebugPrint(JB_Object* self);

bool JB_Object_MustBe(JB_Object* self, JB_Class* x, Message* ErrNode);

inline bool JB_Obj_NilCheck(JB_Object* self);

bool JB_Object_Isa(JB_Object* self, JB_Class* x);

void JB_Object_SaveTryCollect(JB_Object* self, ObjectSaver* Saver);

void JB_Object_Fail(JB_Object* self, JB_String* Error);

void JB_Object_SyntaxExpect(JB_Object* self);

void JB_Object_test(JB_Object* self);



// JB_Charset
Array* JB_BM_Bytes(ByteMap* self);

ByteMap* JB_BM__Alloc();

ByteMap* JB_BM__NewCharset(JB_String* charset, bool Ranges);



// JB_DictionaryReader
inline bool JB_DictionaryReader_SyntaxCastBool(DictionaryReader* self);



// JB_FastString
void JB_FS_AppendEscape(FastString* self, JB_String* s);

void JB_FS_AppendHexData1(FastString* self, JB_String* Data);

void JB_FS_AppendObjectID(FastString* self, Saveable* o);

void JB_FS_AppendObjectOrNil(FastString* self, JB_Object* o);

void JB_FS_MsgErrorName(FastString* self, JB_String* name);

JB_String* JB_FS_Render(FastString* self, FastString* fs_in);

void JB_FS_AppendInt32AsText(FastString* self, int data);

void JB_FS_AppendFloatAsText(FastString* self, float F);

void JB_FS_AppendMsg(FastString* self, Message* msg);

inline JB_String* JB_FS_SyntaxCastString(FastString* self);

FastString* JB_FS__Alloc();

int JB_FS__Init_();

FastString* JB_FS__New();



// JB_File


// JB_FixedDict


// JB_LeakTester
void JB_Lk_Constructor(LeakTester* self, JB_String* name);

void JB_Lk_Destructor(LeakTester* self);

void JB_Lk_FinalTest(LeakTester* self);

void JB_Lk_Test(LeakTester* self);

LeakTester* JB_Lk__Alloc();

LeakTester* JB_Lk__New(JB_String* name);



// JB_MemoryLayer


// JB_Pipe


// JB_Saveable
inline void JB_Sav___SaveCollect__(Saveable* self, ObjectSaver* Saver);

bool JB_Sav_IsSaveMarked(Saveable* self);

void JB_Sav_LoadProperties(Saveable* self, ObjectLoader* Loader);

void JB_Sav_SaveCollect(Saveable* self, ObjectSaver* Saver);

bool JB_Sav_SaveMark(Saveable* self);

SaverClassInfo* JB_Sav_SaverInfo(Saveable* self);

void JB_Sav_SaveWrite(Saveable* self, ObjectSaver* Saver);



// JB_Selector


// JB_String
void JB_Str_AppendAsBinary(JB_String* self, FastString* fs);

Array* JB_Str_ByteSplit(JB_String* self);

ByteMap* JB_Str_Charset(JB_String* self, bool Range);

JB_String* JB_Str_Escape(JB_String* self);

JB_String* JB_Str_EscapeChr(JB_String* self);

int JB_Str_FindStr(JB_String* self, int Start, JB_String* find);

int JB_Str_FindByte(JB_String* self, int off, byte find);

int JB_Str_InCharSet(JB_String* self, int Start, int After, ByteMap* cs);

int JB_Str_InWhite(JB_String* self, int Start, int After);

int JB_Str_JBFind(JB_String* self, int Off, int After, byte find);

int JB_Str_LineCount(JB_String* self);

bool JB_Str_OperatorContains(JB_String* self, JB_String* s);

int JB_Str_OutCharSet(JB_String* self, int Start, int After, ByteMap* cs);

int JB_Str_OutWhite(JB_String* self, int Start, int After);

Message* JB_Str_Parse(JB_String* self, Message* Result);

Message* JB_Str_ParseAs(JB_String* self, JB_String* name);

int JB_Str_ParseInt(JB_String* self, Message* Where);

Array* JB_Str_Split(JB_String* self, JB_String* sep);

byte JB_Str_SyntaxAccess(JB_String* self, int index);

JB_String* JB_Str_AccessRange(JB_String* self, int start, int after);

bool JB_Str_SyntaxEquals(JB_String* self, JB_String* Other, bool Aware);

void JB_Str_SyntaxExpect(JB_String* self);

JB_String* JB_Str_Unescape(JB_String* self);



// JB_StringFields
void JB_FI_Constructor(StringFields* self, JB_String* Source, JB_String* Sep);

int JB_FI_Count(StringFields* self);

void JB_FI_Destructor(StringFields* self);

JB_String* JB_FI_Field(StringFields* self, int Prev, int Curr);

int JB_FI_NextSep(StringFields* self, int Prev);

StringFields* JB_FI__Alloc();

StringFields* JB_FI__New(JB_String* Source, JB_String* Sep);



// JB_StripMe


// JB_Syntax
void JB_Fn_Constructor(Syntax* self, fpMsgRender msg, JB_String* name, int ID);

void JB_Fn_Destructor(Syntax* self);

Message* JB_Fn_Msg(Syntax* self, JB_String* name);

Message* JB_Fn_MsgParent(Syntax* self, Message* parent, JB_String* name);

int JB_Fn_Parseflags(Syntax* self);

JB_String* JB_Fn_Render(Syntax* self, FastString* fs_in);

Syntax* JB_Fn__Alloc();

Syntax* JB_Fn__New(fpMsgRender msg, JB_String* name, int ID);

Syntax* JB_Fn__StdNew(fpMsgRender msg, int ID, JB_String* name, JB_String* LongName);



// JB_TokenHandler


// fpDestructor


// fpMsgRender


// ParseHandler
inline TokenHandler_fp JB_ParseHandler_cast(ParseHandler self);



// SaverLoadClass


// TokenHandler_fp


// __Render__


// __LoadProperties__


// __SaveCollect__


// __SaveWrite__


// JB_Array
void JB_Array_LoadProperties(Array* self, ObjectLoader* Loader);

void JB_Array_SaveCollect(Array* self, ObjectSaver* Saver);

void JB_Array_SaveWrite(Array* self, ObjectSaver* Saver);

Array* JB_Array__Alloc();

Array* JB_Array__New(int size);

Array* JB_Array__New0();



// JB_Dictionary
void JB_Dict_LoadProperties(Dictionary* self, ObjectLoader* Loader);

void JB_Dict_SaveCollect(Dictionary* self, ObjectSaver* Saver);

void JB_Dict_SaveWrite(Dictionary* self, ObjectSaver* Saver);

JB_Object* JB_Dict_Syntax(Dictionary* self, JB_String* Key);

void JB_Dict_a2(Dictionary* self, JB_String* Key, s64 Result);

void JB_Dict_a4(Dictionary* self, s64 Key, JB_Object* Result);

Dictionary* JB_Dict__Alloc();

Dictionary* JB_Dict__New();



// JB_FastAppender
void JB_FAP_Destructor(FastAppender* self);

void JB_FAP_Grow(FastAppender* self);

void JB_FAP_LoadProperties(FastAppender* self, ObjectLoader* Loader);

void JB_FAP_SaveWrite(FastAppender* self, ObjectSaver* Saver);

void JB_FAP_SyntaxAppend(FastAppender* self, JB_Object* obj);

int JB_FAP__Init_();



// JB_LinkedList
void JB_LinkedList_ListSanity(JB_LinkedList* self);

void JB_LinkedList_LoadProperties(JB_LinkedList* self, ObjectLoader* Loader);

void JB_LinkedList_SaveWrite(JB_LinkedList* self, ObjectSaver* Saver);



// JB_RingTree
RingTree* JB_Tree_First_(RingTree* self);

bool JB_Tree_HasOneChild(RingTree* self);

bool JB_Tree_IsWithin(RingTree* self, RingTree* other);

void JB_Tree_Remove(RingTree* self);

void JB_Tree_SyntaxAppend(RingTree* self, RingTree* Last);



// JB_SaverClassInfo
void JB_sci_Destructor(SaverClassInfo* self);



// JB_Error
void JB_Err_Constructor(JB_Error* self, Message* node);

void JB_Err_Destructor(JB_Error* self);

void JB_Err_Fill(JB_Error* self, JB_String* path, JB_String* desc);

void JB_Err_GrabLine(JB_Error* self, FastString* fs, bool Usecolor);

bool JB_Err_HasPosition(JB_Error* self);

bool JB_Err_IsWarning(JB_Error* self);

bool JB_Err_LineIdentifiers(JB_Error* self, FastString* fs);

int JB_Err_LinePos(JB_Error* self, JB_String* data);

JB_String* JB_Err_Render(JB_Error* self, FastString* fs_in);

JB_Error* JB_Err__Alloc();

void JB_Err__CantParseNum(Message* Where, JB_String* num, int Pos);

JB_Error* JB_Err__New(Message* node);



// JB_ErrorReceiver
bool JB_Rec_CanAddMore(JB_ErrorReceiver* self);

void JB_Rec_Clear(JB_ErrorReceiver* self);

void JB_Rec_Constructor(JB_ErrorReceiver* self);

void JB_Rec_Destructor(JB_ErrorReceiver* self);

JB_Error* JB_Rec_FirstError(JB_ErrorReceiver* self);

void JB_Rec_NewItemWithNode(JB_ErrorReceiver* self, Message* node, JB_String* Desc);

bool JB_Rec_OK(JB_ErrorReceiver* self);

void JB_Rec_NewItem(JB_ErrorReceiver* self, JB_Error* Err);

int JB_Rec_TotalCount(JB_ErrorReceiver* self);

JB_ErrorReceiver* JB_Rec__Alloc();

JB_String* JB_Rec__ErrorType(bool IsWarning);

JB_ErrorReceiver* JB_Rec__New();



// JB_FastAppenderChunk
void JB_FAC_Add(FastAppenderChunk* self, JB_Object* C);

bool JB_FAC_CantStoreMore(FastAppenderChunk* self);

void JB_FAC_Constructor(FastAppenderChunk* self);

void JB_FAC_Destructor(FastAppenderChunk* self);

FastAppenderChunk* JB_FAC__Alloc();

FastAppenderChunk* JB_FAC__New();



// JB_Message
void JB_Msg_Acc__(Message* self, FastString* fs);

void JB_Msg_AccessErr(Message* self, Syntax* s, JB_String* name);

void JB_Msg_Adj__(Message* self, FastString* fs);

void JB_Msg_Ana__(Message* self, FastString* fs);

void JB_Msg_ARel__(Message* self, FastString* fs);

void JB_Msg_Arg__(Message* self, FastString* fs);

void JB_Msg_Arr__(Message* self, FastString* fs);

void JB_Msg_Back__(Message* self, FastString* fs);

void JB_Msg_Bin__(Message* self, FastString* fs);

void JB_Msg_Bra__(Message* self, FastString* fs);

void JB_Msg_BRel__(Message* self, FastString* fs);

void JB_Msg_Char__(Message* self, FastString* fs);

void JB_Msg_Cnj__(Message* self, FastString* fs);

void JB_Msg_ConstructorCopy(Message* self, Message* other);

void JB_Msg_ConstructorFuncName(Message* self, Syntax* Func, JB_String* Name);

void JB_Msg_ConstructorParentPos(Message* self, Message* Parent, int Position);

void JB_Msg_ConstructorParser(Message* self, Message* Parent, Syntax* Func, int BytePos, JB_String* Name);

Message* JB_Msg_Copy(Message* self, bool DefaultLayer);

void JB_Msg_Decl__(Message* self, FastString* fs);

void JB_Msg_Destructor(Message* self);

void JB_Msg_Dot__(Message* self, FastString* fs);

void JB_Msg_Dummy(Message* self, FastString* fs);

void JB_Msg_Emb__(Message* self, FastString* fs);

void JB_Msg_ERel__(Message* self, FastString* fs);

Message* JB_Msg_Find(Message* self, Syntax* f, JB_String* name, bool Err);

Message* JB_Msg_FixTRels(Message* self, Message* Last);

void JB_Msg_FSListArg(Message* self, FastString* fs);

void JB_Msg_FSListSep(Message* self, FastString* fs, JB_String* sep);

void JB_Msg_Func__(Message* self, FastString* fs);

JB_String* JB_Msg_FuncName(Message* self);

void JB_Msg_Item__(Message* self, FastString* fs);

Message* JB_Msg_LayerCopy(Message* self, JB_MemoryLayer* L);

void JB_Msg_List__(Message* self, FastString* fs);

Message* JB_Msg_LoadNameFromList(Message* self, Message* line);

JB_String* JB_Msg_Locate(Message* self);

JB_String* JB_Msg_MakeReadable(Message* self, FastString* fs_in);

void JB_Msg_Name__(Message* self, FastString* fs);

Message* JB_Msg_NormalCopy(Message* self);

void JB_Msg_Num__(Message* self, FastString* fs);

JB_String* JB_Msg_Nyme(Message* self);

void JB_Msg_Oat__(Message* self, FastString* fs);

void JB_Msg_Opp__(Message* self, FastString* fs);

JB_String* JB_Msg_OriginalParseData(Message* self);

JB_MemoryLayer* JB_Msg_OriginalParseLayer(Message* self);

JB_String* JB_Msg_OriginalParsePath(Message* self);

s64 JB_Msg_ParseInt(Message* self);

Message* JB_Msg_ParseReadable(Message* self);

Message* JB_Msg_PoorAnt(Message* self);

void JB_Msg_Prm__(Message* self, FastString* fs);

void JB_Msg_ReadableParse_(Message* self, Message* Src);

void JB_Msg_Rel__(Message* self, FastString* fs);

JB_String* JB_Msg_Render(Message* self, FastString* fs_in);

void JB_Msg_RenderPrm(Message* self, FastString* fs, byte b1, byte b2);

void JB_Msg_RenderWithSpaces(Message* self, FastString* fs, Message* ch);

void JB_Msg_SCnj__(Message* self, FastString* fs);

void JB_Msg_SCom__(Message* self, FastString* fs);

void JB_Msg_SDot__(Message* self, FastString* fs);

void JB_Msg_Sheb__(Message* self, FastString* fs);

void JB_Msg_SOpp__(Message* self, FastString* fs);

void JB_Msg_SStr__(Message* self, FastString* fs);

void JB_Msg_SThg__(Message* self, FastString* fs);

void JB_Msg_Str__(Message* self, FastString* fs);

bool JB_Msg_SyntaxEquals(Message* self, JB_String* name, bool Aware);

bool JB_Msg_SyxOppEquals(Message* self, Syntax* X, bool Aware);

void JB_Msg_Fail(Message* self, JB_String* Error);

void JB_Msg_Test(Message* self, JB_String* new_render, JB_String* name);

bool JB_Msg_TestSub(Message* self, JB_String* new_render, JB_String* name);

void JB_Msg_Thg__(Message* self, FastString* fs);

void JB_Msg_Tmp__(Message* self, FastString* fs);

bool JB_Msg_TreeCompare(Message* self, Message* other);

void JB_Msg_TRel__(Message* self, FastString* fs);

void JB_Msg_Type__(Message* self, FastString* fs);

void JB_Msg_UnEmbed(Message* self);

void JB_Msg_Unit__(Message* self, FastString* fs);

Message* JB_Msg__Alloc();

Syntax* JB_Msg__GetSyx(Message* msg);

Message* JB_Msg__LayerAlloc(JB_MemoryLayer* _L);

Message* JB_Msg__NewFuncName(Syntax* Func, JB_String* Name);

Message* JB_Msg__NewParentPos(Message* Parent, int Position);

Message* JB_Msg__NewParser(Message* Parent, Syntax* Func, int BytePos, JB_String* Name);

Message* JB_Msg__NewWithLayerCopy(JB_MemoryLayer* _L, Message* other);

JB_String* jb_msg_name(Message* self);

Syntax* jb_msg_type(Message* self);

int jb_msg_position(Message* self);

_voidptr jb_msg_tag(Message* self);

void jb_msg_nameset(Message* self, JB_String* Result);

void jb_msg_typeset(Message* self, Syntax* Result);

void jb_msg_positionset(Message* self, int Result);

void jb_msg_tagset(Message* self, _voidptr Result);

void jb_msg_firstset(Message* self, Message* Result);

void jb_msg_lastset(Message* self, Message* Result);

void jb_msg_prevset(Message* self, Message* Result);

void jb_msg_nextset(Message* self, Message* Result);

Message* jb_msg_first(Message* self);

Message* jb_msg_last(Message* self);

Message* jb_msg_prev(Message* self);

Message* jb_msg_next(Message* self);

Message* jb_msg_parent(Message* self);

Message* jb_msg_flatnext(Message* self);

Message* jb_msg_flatafter(Message* self);

Message* jb_msg_root(Message* self);

void jb_msg_remove(Message* self);

JB_String* jb_msg_render(Message* self);

JB_String* jb_msg_renderreadable(Message* self);

Message* jb_msg_convertreadable(Message* self);

Message* jb_msg_copy(Message* self);

Message* jb_msg_create(Message* self, Syntax* Type, JB_String* Name);

void jb_msg_error(Message* self, JB_String* ErrorMsg);

Message* jb_msg_expect(Message* self, Syntax* Type, JB_String* name, Message* ErrPlace);

Message* jb_msg_find(Message* self, Syntax* Type, JB_String* name, bool IsError);

JB_String* jb_syx_name(Syntax* self);

JB_String* jb_syx_longname(Syntax* self);

_cstring jb_string_address(JB_String* self);

int jb_string_length(JB_String* self);

JB_String* jb_string_copy(JB_String* self);

Message* jb_string_parse(JB_String* self, JB_String* path);

JB_String* jb_string_escape(JB_String* self);

void jb_string_print(JB_String* self);

void jb_string_printline(JB_String* self);

s64 jb_string_int(JB_String* self, Message* m);

Syntax* jb_syntax(JB_String* name);

JB_String* jb_str(_cstring Str, int Length, _voidptr Release, _voidptr Tag);

void jb_delete_(JB_Object* obj);

Message* jb_errors();

bool jb_ok();

void jb_debug(JB_Object* o);

int jb_init(int Flags);

int jb_shutdown();

int jb_version();

JB_String* jb_readfile(_cstring path, bool AllowMissingFile);


//// HEADER SyntaxConstants.h
#define kSyxArg 0
#define kSyxAcc 1
#define kSyxAdj 2
#define kSyxARel 3
#define kSyxArr 4
#define kSyxBack 5
#define kSyxSStr 6
#define kSyxBra 7
#define kSyxBRel 8
#define kSyxChar 9
#define kSyxDecl 10
#define kSyxDot 11
#define kSyxEmb 12
#define kSyxERel 13
#define kSyxFunc 14
#define kSyxItem 15
#define kSyxList 16
#define kSyxPrm 17
#define kSyxName 18
#define kSyxNum 19
#define kSyxOat 20
#define kSyxOpp 21
#define kSyxSOpp 22
#define kSyxRel 23
#define kSyxTRel 24
#define kSyxSDot 25
#define kSyxSCom 26
#define kSyxSheb 27
#define kSyxStr 28
#define kSyxSThg 29
#define kSyxThg 30
#define kSyxTmp 31
#define kSyxAna 32
#define kSyxSCnj 33
#define kSyxCnj 34
#define kSyxType 35
#define kSyxUnit 36
#define kSyxBin 37



#define JB_RB_Constants  "Arg = 0" ,\
 "Acc = 1" ,\
 "Adj = 2" ,\
 "ARel = 3" ,\
 "Arr = 4" ,\
 "Back = 5" ,\
 "SStr = 6" ,\
 "Bra = 7" ,\
 "BRel = 8" ,\
 "Char = 9" ,\
 "Decl = 10" ,\
 "Dot = 11" ,\
 "Emb = 12" ,\
 "ERel = 13" ,\
 "Func = 14" ,\
 "Item = 15" ,\
 "List = 16" ,\
 "Prm = 17" ,\
 "Name = 18" ,\
 "Num = 19" ,\
 "Oat = 20" ,\
 "Opp = 21" ,\
 "SOpp = 22" ,\
 "Rel = 23" ,\
 "TRel = 24" ,\
 "SDot = 25" ,\
 "SCom = 26" ,\
 "Sheb = 27" ,\
 "Str = 28" ,\
 "SThg = 29" ,\
 "Thg = 30" ,\
 "Tmp = 31" ,\
 "Ana = 32" ,\
 "SCnj = 33" ,\
 "Cnj = 34" ,\
 "Type = 35" ,\
 "Unit = 36" ,\
 "Bin = 37" ,\





}
#endif // __JB_H__
