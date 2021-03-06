
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
#include "JB_Umbrella.h"
#include "JB.h"


#define __lib__ __attribute__ ((visibility ("default")))
// #pragma GCC visibility push(hidden)

extern "C" {

extern Object_Behaviour JB_Object_FuncTable_;

bool JB__ErrorColors_Enabled;
//


u16 JB__API_NilHappened;
//


ByteMap* JB__Constants_CSAfterTemporal;
ByteMap* JB__Constants_CSLettersOnly;
ByteMap* JB__Constants_CSLine;
ByteMap* JB__Constants_CSLineBlack;
ByteMap* JB__Constants_CSNum;
ByteMap* JB__Constants_CSWordMiddle;
ByteMap* JB__Constants_CSWordStart;
Dictionary* JB__Constants_EscapeChr;
Dictionary* JB__Constants_EscapeStr;
Dictionary* JB__Constants_JS_EscapeStr;
Dictionary* JB__Constants_JS_UnEscapeStr;
Dictionary* JB__Constants_UnEscapeStr;
//


//


JB_String* JB__Tk_Data;
Message* JB__Tk_EndOfLineMarker;
Message* JB__Tk_ErrNode;
Dictionary* JB__Tk_ErrorNames;
bool JB__Tk_IndentationAware;
int JB__Tk_StopBars;
int JB__Tk_UsingPos;
//


SyntaxObj* JB__FuncArray_[64];
Dictionary* JB__SyxDict_;
JB_ErrorReceiver* JB_StdErr;
JB_String* JB_str_0;
JB_String* JB_str_1;
JB_String* JB_str_10;
JB_String* JB_str_100;
JB_String* JB_str_101;
JB_String* JB_str_102;
JB_String* JB_str_103;
JB_String* JB_str_104;
JB_String* JB_str_105;
JB_String* JB_str_106;
JB_String* JB_str_107;
JB_String* JB_str_108;
JB_String* JB_str_109;
JB_String* JB_str_11;
JB_String* JB_str_110;
JB_String* JB_str_111;
JB_String* JB_str_112;
JB_String* JB_str_113;
JB_String* JB_str_114;
JB_String* JB_str_115;
JB_String* JB_str_116;
JB_String* JB_str_117;
JB_String* JB_str_118;
JB_String* JB_str_119;
JB_String* JB_str_12;
JB_String* JB_str_120;
JB_String* JB_str_121;
JB_String* JB_str_122;
JB_String* JB_str_123;
JB_String* JB_str_124;
JB_String* JB_str_125;
JB_String* JB_str_126;
JB_String* JB_str_127;
JB_String* JB_str_128;
JB_String* JB_str_129;
JB_String* JB_str_13;
JB_String* JB_str_130;
JB_String* JB_str_131;
JB_String* JB_str_132;
JB_String* JB_str_133;
JB_String* JB_str_134;
JB_String* JB_str_135;
JB_String* JB_str_136;
JB_String* JB_str_137;
JB_String* JB_str_138;
JB_String* JB_str_139;
JB_String* JB_str_140;
JB_String* JB_str_141;
JB_String* JB_str_142;
JB_String* JB_str_143;
JB_String* JB_str_144;
JB_String* JB_str_145;
JB_String* JB_str_146;
JB_String* JB_str_147;
JB_String* JB_str_148;
JB_String* JB_str_149;
JB_String* JB_str_15;
JB_String* JB_str_150;
JB_String* JB_str_151;
JB_String* JB_str_152;
JB_String* JB_str_153;
JB_String* JB_str_154;
JB_String* JB_str_155;
JB_String* JB_str_156;
JB_String* JB_str_157;
JB_String* JB_str_158;
JB_String* JB_str_159;
JB_String* JB_str_16;
JB_String* JB_str_160;
JB_String* JB_str_161;
JB_String* JB_str_162;
JB_String* JB_str_163;
JB_String* JB_str_164;
JB_String* JB_str_165;
JB_String* JB_str_166;
JB_String* JB_str_167;
JB_String* JB_str_168;
JB_String* JB_str_169;
JB_String* JB_str_17;
JB_String* JB_str_170;
JB_String* JB_str_171;
JB_String* JB_str_172;
JB_String* JB_str_173;
JB_String* JB_str_174;
JB_String* JB_str_175;
JB_String* JB_str_176;
JB_String* JB_str_177;
JB_String* JB_str_178;
JB_String* JB_str_179;
JB_String* JB_str_18;
JB_String* JB_str_180;
JB_String* JB_str_181;
JB_String* JB_str_182;
JB_String* JB_str_183;
JB_String* JB_str_184;
JB_String* JB_str_185;
JB_String* JB_str_186;
JB_String* JB_str_187;
JB_String* JB_str_188;
JB_String* JB_str_189;
JB_String* JB_str_19;
JB_String* JB_str_190;
JB_String* JB_str_191;
JB_String* JB_str_192;
JB_String* JB_str_193;
JB_String* JB_str_194;
JB_String* JB_str_195;
JB_String* JB_str_196;
JB_String* JB_str_197;
JB_String* JB_str_198;
JB_String* JB_str_199;
JB_String* JB_str_2;
JB_String* JB_str_20;
JB_String* JB_str_200;
JB_String* JB_str_201;
JB_String* JB_str_202;
JB_String* JB_str_203;
JB_String* JB_str_204;
JB_String* JB_str_205;
JB_String* JB_str_206;
JB_String* JB_str_207;
JB_String* JB_str_208;
JB_String* JB_str_209;
JB_String* JB_str_21;
JB_String* JB_str_210;
JB_String* JB_str_211;
JB_String* JB_str_212;
JB_String* JB_str_213;
JB_String* JB_str_214;
JB_String* JB_str_215;
JB_String* JB_str_216;
JB_String* JB_str_217;
JB_String* JB_str_218;
JB_String* JB_str_219;
JB_String* JB_str_22;
JB_String* JB_str_220;
JB_String* JB_str_221;
JB_String* JB_str_222;
JB_String* JB_str_223;
JB_String* JB_str_224;
JB_String* JB_str_225;
JB_String* JB_str_226;
JB_String* JB_str_227;
JB_String* JB_str_228;
JB_String* JB_str_229;
JB_String* JB_str_23;
JB_String* JB_str_230;
JB_String* JB_str_231;
JB_String* JB_str_232;
JB_String* JB_str_233;
JB_String* JB_str_234;
JB_String* JB_str_235;
JB_String* JB_str_236;
JB_String* JB_str_237;
JB_String* JB_str_238;
JB_String* JB_str_239;
JB_String* JB_str_24;
JB_String* JB_str_240;
JB_String* JB_str_241;
JB_String* JB_str_242;
JB_String* JB_str_243;
JB_String* JB_str_244;
JB_String* JB_str_245;
JB_String* JB_str_246;
JB_String* JB_str_247;
JB_String* JB_str_248;
JB_String* JB_str_249;
JB_String* JB_str_25;
JB_String* JB_str_250;
JB_String* JB_str_251;
JB_String* JB_str_252;
JB_String* JB_str_253;
JB_String* JB_str_254;
JB_String* JB_str_255;
JB_String* JB_str_256;
JB_String* JB_str_257;
JB_String* JB_str_258;
JB_String* JB_str_259;
JB_String* JB_str_26;
JB_String* JB_str_260;
JB_String* JB_str_261;
JB_String* JB_str_262;
JB_String* JB_str_263;
JB_String* JB_str_264;
JB_String* JB_str_265;
JB_String* JB_str_266;
JB_String* JB_str_267;
JB_String* JB_str_268;
JB_String* JB_str_269;
JB_String* JB_str_27;
JB_String* JB_str_270;
JB_String* JB_str_271;
JB_String* JB_str_272;
JB_String* JB_str_273;
JB_String* JB_str_274;
JB_String* JB_str_275;
JB_String* JB_str_276;
JB_String* JB_str_277;
JB_String* JB_str_278;
JB_String* JB_str_279;
JB_String* JB_str_28;
JB_String* JB_str_280;
JB_String* JB_str_281;
JB_String* JB_str_282;
JB_String* JB_str_283;
JB_String* JB_str_284;
JB_String* JB_str_285;
JB_String* JB_str_286;
JB_String* JB_str_287;
JB_String* JB_str_288;
JB_String* JB_str_289;
JB_String* JB_str_29;
JB_String* JB_str_290;
JB_String* JB_str_291;
JB_String* JB_str_292;
JB_String* JB_str_293;
JB_String* JB_str_294;
JB_String* JB_str_295;
JB_String* JB_str_296;
JB_String* JB_str_297;
JB_String* JB_str_298;
JB_String* JB_str_299;
JB_String* JB_str_3;
JB_String* JB_str_30;
JB_String* JB_str_300;
JB_String* JB_str_301;
JB_String* JB_str_302;
JB_String* JB_str_303;
JB_String* JB_str_304;
JB_String* JB_str_305;
JB_String* JB_str_306;
JB_String* JB_str_307;
JB_String* JB_str_308;
JB_String* JB_str_309;
JB_String* JB_str_31;
JB_String* JB_str_310;
JB_String* JB_str_311;
JB_String* JB_str_312;
JB_String* JB_str_313;
JB_String* JB_str_314;
JB_String* JB_str_315;
JB_String* JB_str_316;
JB_String* JB_str_317;
JB_String* JB_str_318;
JB_String* JB_str_319;
JB_String* JB_str_32;
JB_String* JB_str_320;
JB_String* JB_str_321;
JB_String* JB_str_322;
JB_String* JB_str_323;
JB_String* JB_str_324;
JB_String* JB_str_325;
JB_String* JB_str_326;
JB_String* JB_str_327;
JB_String* JB_str_328;
JB_String* JB_str_329;
JB_String* JB_str_33;
JB_String* JB_str_330;
JB_String* JB_str_331;
JB_String* JB_str_332;
JB_String* JB_str_333;
JB_String* JB_str_334;
JB_String* JB_str_335;
JB_String* JB_str_336;
JB_String* JB_str_337;
JB_String* JB_str_34;
JB_String* JB_str_35;
JB_String* JB_str_36;
JB_String* JB_str_37;
JB_String* JB_str_38;
JB_String* JB_str_39;
JB_String* JB_str_4;
JB_String* JB_str_40;
JB_String* JB_str_41;
JB_String* JB_str_42;
JB_String* JB_str_43;
JB_String* JB_str_44;
JB_String* JB_str_45;
JB_String* JB_str_46;
JB_String* JB_str_47;
JB_String* JB_str_48;
JB_String* JB_str_49;
JB_String* JB_str_5;
JB_String* JB_str_50;
JB_String* JB_str_51;
JB_String* JB_str_52;
JB_String* JB_str_53;
JB_String* JB_str_54;
JB_String* JB_str_55;
JB_String* JB_str_56;
JB_String* JB_str_57;
JB_String* JB_str_58;
JB_String* JB_str_59;
JB_String* JB_str_6;
JB_String* JB_str_60;
JB_String* JB_str_61;
JB_String* JB_str_62;
JB_String* JB_str_63;
JB_String* JB_str_64;
JB_String* JB_str_65;
JB_String* JB_str_66;
JB_String* JB_str_67;
JB_String* JB_str_68;
JB_String* JB_str_69;
JB_String* JB_str_7;
JB_String* JB_str_70;
JB_String* JB_str_71;
JB_String* JB_str_72;
JB_String* JB_str_73;
JB_String* JB_str_74;
JB_String* JB_str_75;
JB_String* JB_str_76;
JB_String* JB_str_77;
JB_String* JB_str_78;
JB_String* JB_str_79;
JB_String* JB_str_8;
JB_String* JB_str_80;
JB_String* JB_str_81;
JB_String* JB_str_82;
JB_String* JB_str_83;
JB_String* JB_str_84;
JB_String* JB_str_85;
JB_String* JB_str_86;
JB_String* JB_str_87;
JB_String* JB_str_88;
JB_String* JB_str_89;
JB_String* JB_str_9;
JB_String* JB_str_90;
JB_String* JB_str_91;
JB_String* JB_str_92;
JB_String* JB_str_93;
JB_String* JB_str_94;
JB_String* JB_str_95;
JB_String* JB_str_96;
JB_String* JB_str_97;
JB_String* JB_str_98;
JB_String* JB_str_99;
__lib__ Syntax JB_SyxAcc;
__lib__ Syntax JB_SyxAdj;
__lib__ Syntax JB_SyxAna;
__lib__ Syntax JB_SyxARel;
__lib__ Syntax JB_SyxArg;
__lib__ Syntax JB_SyxArr;
__lib__ Syntax JB_SyxAsk;
__lib__ Syntax JB_SyxBack;
__lib__ Syntax JB_SyxBin;
__lib__ Syntax JB_SyxBnch;
__lib__ Syntax JB_SyxBra;
__lib__ Syntax JB_SyxBRel;
__lib__ Syntax JB_SyxChar;
__lib__ Syntax JB_SyxCnj;
__lib__ Syntax JB_SyxDecl;
__lib__ Syntax JB_SyxDot;
__lib__ Syntax JB_SyxEmb;
__lib__ Syntax JB_SyxERel;
__lib__ Syntax JB_SyxFunc;
__lib__ Syntax JB_SyxItem;
__lib__ Syntax JB_SyxList;
__lib__ Syntax JB_SyxMsg;
__lib__ Syntax JB_SyxName;
__lib__ Syntax JB_SyxNum;
__lib__ Syntax JB_SyxOat;
__lib__ Syntax JB_SyxOpp;
__lib__ Syntax JB_SyxRel;
__lib__ Syntax JB_SyxSCnj;
__lib__ Syntax JB_SyxSCom;
__lib__ Syntax JB_SyxSDot;
__lib__ Syntax JB_SyxSheb;
__lib__ Syntax JB_SyxSOpp;
__lib__ Syntax JB_SyxSStr;
__lib__ Syntax JB_SyxSThg;
__lib__ Syntax JB_SyxStr;
__lib__ Syntax JB_SyxThg;
__lib__ Syntax JB_SyxTmp;
__lib__ Syntax JB_SyxTodo;
__lib__ Syntax JB_SyxTRel;
__lib__ Syntax JB_SyxType;
__lib__ Syntax JB_SyxUnit;
__lib__ Syntax JB_SyxYoda;
__lib__ Syntax JB_SyxYopp;
//


//


//


Dictionary* JB__ObjectLoader_ClassList;
//


SaverClassInfo* JB__Saver_SaveableList;
//


Random JB__Random_Shared;
//


//


//


//


//


//


Dictionary* JB__DataTypeCode_Types_Dict;
//


//


Array* JB__ErrorSeverity_names;
//


int JB__Syx_CurrFuncID;
//


uint64 JB__Mrap_Dummy[2];
//


FastString* JB__FS_StdOutFS;
//


//


//


//


bool JB__FAP_Tested;
//


bool JB__Rec_BreakOnError;
//



inline bool JB_int_Found(int self) {
	return self >= 0;
}

inline bool JB_Syx_NilCheck(Syntax self) {
	if (self) {
		return true;
	}
	return JB_API__NilHandler();
}

inline bool JB_DictionaryReader_SyntaxCast(DictionaryReader* self) {
	return JB_Nav_MoveNext(self);
}

inline JB_String* JB_FS_SyntaxCast(FastString* self) {
	return JB_FS_GetResult(self);
}

inline void JB_Sav___SaveCollect__(Saveable* self, ObjectSaver* Saver) {
	JB_TestInterface(self);
	Saveable_Behaviour* Table = ((Saveable_Behaviour*)JB_ObjClassBehaviours(self));
	return (Table->savecollect)(self, Saver);
}

inline TokenHandler_fp JB_ParseHandler_cast(ParseHandler self) {
	return ((TokenHandler_fp)self);
}

inline bool JB_Array_SyntaxCast(Array* self) {
	return ((bool)self) and (JB_Array_Size(self) >= 1);
}

inline bool JB_Msg_NilCheck(Message* self) {
	if (self) {
		return true;
	}
	return JB_API__NilHandler();
}




int JB_Main() {
	return 0;
}



int JB_ErrorColors__Init_() {
	{
		JB__ErrorColors_Enabled = false;
	};
	return 0;
}


Message* JB_API__errors() {
	if (JB_Rec_OK(JB_StdErr)) {
		return nil;
	}
	Message* result = (JB_Syx_MsgWithStr(JB_SyxList, JB_str_0));
	{
		JB_Error* err = (JB_Error*)(JB_StdErr->Errors.First);
		while (err) {
			Message* node = (JB_Syx_MsgWithStr(JB_SyxStr, JB_Err_Render(err, nil)));
			JB_Tree_SyntaxAppend(result, node);
			node->Position = err->Position;
			err = ((JB_Error*)JB_LinkedList_Next(err));
		};
	};
	JB_Rec_Clear(JB_StdErr);
	return result;
}

int JB_API__Init(int flags) {
	if ((!(JB_StdErr == nil))) {
		return nil;
	}
	int errCode = JB_LibInit();
	if (errCode) {
		return errCode;
	}
	JB_String* msg = JB_Incr(JB_Constants__Test());
	if (((bool)(flags & 1))) {
		JB_Str_PrintLine(msg);
	}
	JB_Decr(msg);
	if ((!(JB_Rec_OK(JB_StdErr)))) {
		JB_Error* err = JB_Incr((JB_Error*)(JB_StdErr->Errors.First));
		JB_Str_Print(err->Description);
		JB_Decr(err);
		JB_Rec_Clear(JB_StdErr);
		return -1000;
	}
	return 0;
}

int JB_API__Init_() {
	{
		JB__API_NilHappened = 0;
	};
	return 0;
}

void JB_API__NilCallBack(JB_String* ErrorMessage) {
	JB_Str_PrintLine(ErrorMessage);
}

bool JB_API__NilHandler() {
	if ((!JB_Rec_OK(JB_StdErr))) {
		return nil;
	}
	debugger;
	if ((++JB__API_NilHappened) < 16) {
		JB_API__NilCallBack(JB_str_60);
	} else if (JB__API_NilHappened == 16) {
		JB_API__NilCallBack(JB_str_61);
	}
	return false;
}

Message* JB_API__Parse(JB_String* s, JB_String* path) {
	if ((!(s != nil))) {
		return nil;
	}
	JB_MemoryLayer* L = JB_Incr(JB_Mem_CreateLayer((JB_AsClass(Message)), path));
	JB_Mem_Use(L);
	JB_SetRef(L->Obj2, s);
	JB_Decr(L);
	Message* Result = JB_Incr(JB_Str_Parse(s, nil));
	JB_ClassData_Restore((JB_AsClass(Message)));
	JB_SafeDecr(Result);
	return Result;
}


int JB_Constants__Init_() {
	{
		JB_SetRef(JB__Constants_EscapeStr, JB_Dict__New());
		(JB_Dict_ValueSet(JB__Constants_EscapeStr, JB_str_240, JB_str_55));
		(JB_Dict_ValueSet(JB__Constants_EscapeStr, JB_str_13, JB_str_87));
		(JB_Dict_ValueSet(JB__Constants_EscapeStr, JB_str_241, JB_str_242));
		(JB_Dict_ValueSet(JB__Constants_EscapeStr, JB_str_17, JB_str_243));
		(JB_Dict_ValueSet(JB__Constants_EscapeStr, JB_str_54, JB_str_244));
		(JB_Dict_ValueSet(JB__Constants_EscapeStr, JB_str_24, JB_str_245));
		(JB_Dict_ValueSet(JB__Constants_EscapeStr, JB_str_57, JB_str_246));
		(JB_Dict_ValueSet(JB__Constants_EscapeStr, JB_str_247, JB_str_248));
		JB_SetRef(JB__Constants_JS_EscapeStr, JB_Dict__New());
		(JB_Dict_ValueSet(JB__Constants_JS_EscapeStr, JB_str_249, JB_str_250));
		(JB_Dict_ValueSet(JB__Constants_JS_EscapeStr, JB_str_251, JB_str_252));
		(JB_Dict_ValueSet(JB__Constants_JS_EscapeStr, JB_str_13, JB_str_87));
		(JB_Dict_ValueSet(JB__Constants_JS_EscapeStr, JB_str_241, JB_str_242));
		(JB_Dict_ValueSet(JB__Constants_JS_EscapeStr, JB_str_17, JB_str_243));
		(JB_Dict_ValueSet(JB__Constants_JS_EscapeStr, JB_str_54, JB_str_244));
		(JB_Dict_ValueSet(JB__Constants_JS_EscapeStr, JB_str_57, JB_str_246));
		JB_SetRef(JB__Constants_UnEscapeStr, ((Dictionary*)nil));
		JB_SetRef(JB__Constants_JS_UnEscapeStr, ((Dictionary*)nil));
		JB_SetRef(JB__Constants_EscapeChr, ((Dictionary*)nil));
		JB_SetRef(JB__Constants_CSWordMiddle, JB_Str_UniCS(JB_str_253));
		JB_SetRef(JB__Constants_CSLettersOnly, JB_Str_UniCS(JB_str_254));
		JB_SetRef(JB__Constants_CSWordStart, JB_Str_UniCS(JB_str_255));
		JB_SetRef(JB__Constants_CSNum, JB__Constants_CSWordMiddle);
		JB_SetRef(JB__Constants_CSLine, JB_Str_Charset(JB_str_256, false));
		JB_SetRef(JB__Constants_CSAfterTemporal, JB_Str_Charset(JB_str_257, false));
		JB_SetRef(JB__Constants_CSLineBlack, JB_Str_Charset(JB_str_258, false));
		JB_Constants__InitConstants();
	};
	return 0;
}

void JB_Constants__InitConstants() {
	Array* Dummy = JB_Incr(JB_Array__New0());
	JB_Decr(Dummy);
	JB_SetRef(JB__Constants_EscapeChr, JB_Dict_Copy(JB__Constants_EscapeStr));
	{
		ByteMap* _LoopSrc1 = JB_Incr(JB__Constants_CSWordStart);
		int _i = 0;
		while (_i < 256) {
			if ((!JB_BM_HasChar(_LoopSrc1, _i))) {
				_i++;
				continue;
			}
			byte c = ((byte)_i);
			JB_String* cr = JB_Incr(JB_byte_Render(c, nil));
			JB_String* _tmP3 = JB_Incr(JB_Str_OperatorPlus(JB_str_52, cr));
			JB_String* _tmP4 = JB_Incr(JB_Str_OperatorPlus(JB_str_53, cr));
			JB_Decr(cr);
			(JB_Dict_ValueSet(JB__Constants_EscapeStr, _tmP3, _tmP4));
			JB_Decr(_tmP4);
			JB_Decr(_tmP3);
			_i++;
		};
		JB_Decr(_LoopSrc1);
	};
	JB_SetRef(JB__Constants_UnEscapeStr, JB_Dict_Reverse(JB__Constants_EscapeStr));
	JB_SetRef(JB__Constants_JS_UnEscapeStr, JB_Dict_Reverse(JB__Constants_JS_EscapeStr));
	(JB_Dict_ValueSet(JB__Constants_EscapeChr, JB_str_54, ((JB_String*)nil)));
	(JB_Dict_ValueSet(JB__Constants_EscapeChr, JB_str_52, ((JB_String*)nil)));
	(JB_Dict_ValueSet(JB__Constants_UnEscapeStr, JB_str_55, ((JB_String*)nil)));
	(JB_Dict_ValueSet(JB__Constants_UnEscapeStr, JB_str_56, JB_str_0));
	(JB_Dict_ValueSet(JB__Constants_UnEscapeStr, JB_str_57, JB_str_0));
	(JB_Dict_ValueSet(JB__Constants_EscapeStr, JB_str_24, ((JB_String*)nil)));
	JB_MSR_EscapeCodeSet(JB__Constants_UnEscapeStr, true);
	JB_MSR_DecodeEntitySet(JB__Constants_UnEscapeStr, true);
	(JB_Dict_ValueSet(JB__Constants_EscapeStr, JB_str_58, JB_str_59));
}

JB_String* JB_Constants__Test() {
	FastString* fs = JB_Incr(JB_FS__New());
	{
		int c = 0;
		while (c < 256) {
			JB_FS_AppendByte(fs, ((byte)c));
			c++;
		};
	};
	JB_String* str = JB_Incr(JB_FS_GetResult(fs));
	JB_Decr(fs);
	if ((!(({
		JB_String* _tmP415 = JB_Incr(({
			JB_String* _tmP417 = JB_Incr(JB_Str_Escape(str));
			JB_String* _tmP416 = JB_Incr(JB_Str_Unescape(_tmP417));
			JB_Decr(_tmP417);
			JB_SafeDecr(_tmP416);
			 _tmP416;
		}));
		bool _tmP414 = JB_Str_SyntaxEquals(_tmP415, str, false);
		JB_Decr(_tmP415);
		 _tmP414;
	})))) {
		JB_Object_SyntaxExpect(nil);
		JB_Decr(str);
		return nil;
	}
	JB_BinaryEscapeTest(str);
	JB_Decr(str);
	if ((!JB_Rec_OK(JB_StdErr))) {
		return nil;
	}
	JB_String* natural_input = JB_Incr(JB_str_182);
	JB_String* list_input = JB_Incr(JB_str_183);
	if ((!(JB_TestCasting()))) {
		debugger;
	}
	JB_String* x = JB_Incr(JB_Str_UpperCase(JB_str_178));
	JB_Decr(x);
	LeakTester* LKT = JB_Incr(JB_Lk__New(JB_str_184));
	JB_FreeIfDead(JB_EntityTest());
	JB_Lk_FinalTest(LKT);
	JB_Decr(LKT);
	if ((!JB_Rec_OK(JB_StdErr))) {
		JB_Decr(natural_input);
		JB_Decr(list_input);
		return nil;
	}
	if (JB_Str_Exists(list_input)) {
		Message* root = JB_Incr(JB_Str_Parse(natural_input, nil));
		if ((!root)) {
			JB_Decr(natural_input);
			JB_Decr(list_input);
			JB_Decr(root);
			return nil;
		}
		Message* cpy = JB_Incr(JB_Msg_Copy(root, false));
		JB_Msg_TreeCompare(root, cpy);
		JB_Decr(cpy);
		Message* list = JB_Incr(({
			Message* _tmP419 = JB_Incr(JB_Str_Parse(list_input, nil));
			Message* _tmP418 = JB_Incr(JB_Msg_ParseAST(_tmP419));
			JB_Decr(_tmP419);
			JB_SafeDecr(_tmP418);
			 _tmP418;
		}));
		JB_Msg_TreeCompare(root, list);
		JB_Decr(list);
		JB_String* _tmP1 = JB_Incr(JB_Msg_Render(root, nil));
		JB_Msg_Test(root, _tmP1, JB_str_178);
		JB_Decr(_tmP1);
		JB_String* _tmP2 = JB_Incr(JB_Msg_AST(root, nil));
		JB_Msg_Test(root, _tmP2, JB_str_179);
		JB_Decr(_tmP2);
		JB_Decr(root);
	} else {
		Message* root = JB_Incr(JB_Str_Parse(natural_input, nil));
		if ((!root)) {
			JB_Decr(natural_input);
			JB_Decr(list_input);
			JB_Decr(root);
			return nil;
		}
		JB_String* R = JB_Incr(JB_Msg_Render(root, nil));
		JB_Msg_Test(root, R, JB_str_178);
		JB_Decr(root);
		JB_Str_Print(JB_str_185);
		JB_Str_Print(R);
		JB_Decr(R);
	}
	JB_Decr(list_input);
	JB_Decr(natural_input);
	if ((!JB_Rec_OK(JB_StdErr))) {
		return nil;
	}
	return JB_EntityTest();
}



Message* JB_Tk__BarThings(int Start, Syntax Syx) {
	JB__Tk_StopBars = (kJB__Tk_FuncAfterBar | kJB__Tk_TemporalSyx);
	Message* item = JB_Incr(JB_Tk__ProcessThing(kJB__Tk_Opp, false));
	if ((!item)) {
		JB_SetRef(item, JB_Tk__NewParent0(nil, JB_SyxEmb, Start));
	} else if (JB_Tk__Allow(kJB__Tk_colon)) {
		JB_SetRef(item, JB_Tk__ParseItem(item, 0));
	}
	JB__Tk_StopBars = 0;
	if ((!JB_Tk__ExpectEndChar(JB_str_120, true))) {
		JB_Decr(item);
		return nil;
	}
	Message* Result = JB_Incr(JB_Tk__NewParent0(nil, Syx, JB_Tk__NextStart() - 1));
	JB_Tree_SyntaxAppend(Result, item);
	JB_Decr(item);
	JB_SafeDecr(Result);
	return Result;
}

Message* JB_Tk__BeforeRelSub(int Start, bool Mode) {
	Message* Result = JB_Incr(JB_Tk__NewParent(nil, JB_SyxBRel, Start, JB_Tk__NextStart()));
	Message* Thg = JB_Incr(JB_Tk__ProcessThing(0, Mode));
	if ((!Thg)) {
		JB_Decr(Result);
		JB_Decr(Thg);
		return nil;
	}
	JB_Tree_SyntaxAppend(Result, Thg);
	JB_Decr(Thg);
	JB_SafeDecr(Result);
	return Result;
}

Message* JB_Tk__ChainTemporalRels(Message* FirstThing, Message* opp) {
	Message* Result = JB_Incr(JB_Tk__NewParent0(nil, JB_SyxTRel, opp->Position));
	JB_Tree_SyntaxAppend(Result, FirstThing);
	JB_Tree_SyntaxAppend(Result, opp);
	if ((!JB_Tk__WillEnd())) {
		Message* Last = JB_Incr(JB_Tk__ProcessThing(kJB__Tk_Opp, false));
		if (Last) {
			Message* _tmP = JB_Incr(JB_Msg_FixTRels(Result, Last));
			JB_Decr(Result);
			JB_Decr(Last);
			JB_SafeDecr(_tmP);
			return _tmP;
		}
		JB_Decr(Last);
	}
	JB_SafeDecr(Result);
	return Result;
}

int JB_Tk__ConsumeLines(Syntax syx) {
	int flags = JB_Syx_Lineflags(syx);
	{
		int _LoopSrc1 = kJB__int_max;
		int result = 0;
		while (result < _LoopSrc1) {
			Message* line = JB_Tk__Process(flags, kJB__Tk_Allow);
			if ((!(line == JB__Tk_EndOfLineMarker))) {
				return result;
			}
			result++;
		};
	};
	return 0;
}

Message* JB_Tk__DotSub(Syntax fn, int Start) {
	if ((!JB_BM_HasChar(JB__Constants_CSWordStart, JB_Str_ByteValue(JB__Tk_Data, (++Start))))) {
		JB_Tk__ErrorLetter(Start);
		return nil;
	}
	int After = JB_Tk__WordAfter(Start);
	if ((!After)) {
		return nil;
	}
	Message* Result = JB_Tk__NewParent(nil, fn, Start, After);
	if (JB_Tk__EatString(JB_str_118)) {
		JB_Tk__Params(Result, After);
	} else {
		JB_FreeIfDead(JB_Tk__NewParent0(Result, JB_SyxEmb, After));
	}
	return Result;
}

int JB_Tk__EmbeddedCode(JB_String* close, Message* dest, Syntax Syx) {
	int result = JB_Str_InStr(JB__Tk_Data, close, JB_Tk__NextStart(), kJB__int_max, false);
	if ((!(JB_int_Found(result)))) {
		FastString* _fs_fs = JB_Incr(JB_FS__New());
		JB_FS_AppendString(_fs_fs, JB_str_78);
		JB_FS_AppendString(_fs_fs, close);
		JB_String* _fs_str = JB_Incr(JB_FS_SyntaxCast(_fs_fs));
		JB_SetRef(_fs_fs, nil);
		JB_Decr(_fs_fs);
		JB_FreeIfDead(JB_Tk__ErrorAdd(_fs_str, JB_Tk__NextStart()));
		JB_Decr(_fs_str);
		return result;
	}
	JB_Tk__ParseLoopMode(dest, Syx);
	if (JB_Tk__NextStart() > result) {
		FastString* _fs1_fs = JB_Incr(JB_FS__New());
		JB_FS_AppendString(_fs1_fs, JB_str_149);
		JB_FS_AppendString(_fs1_fs, close);
		JB_FS_AppendString(_fs1_fs, JB_str_150);
		JB_String* _fs1_str = JB_Incr(JB_FS_SyntaxCast(_fs1_fs));
		JB_SetRef(_fs1_fs, nil);
		JB_Decr(_fs1_fs);
		JB_FreeIfDead(JB_Tk__ErrorAdd(_fs1_str, result));
		JB_Decr(_fs1_str);
		return result;
	}
	result = (result + JB_Str_Length(close));
	(JB_Tk__NextStartSet(result));
	return result;
}

Message* JB_Tk__ErrorAdd(JB_String* s, int Start) {
	if ((!JB_Tk__OK())) {
		return nil;
	}
	return JB_Tk__ErrorAlwaysAdd(s, Start);
}

Message* JB_Tk__ErrorAlwaysAdd(JB_String* s, int Start) {
	JB_DoAt(1);
	(JB_Tk__ErrorStartSet(Start));
	JB_Error* err = JB_Incr(JB_Err__New(JB__Tk_ErrNode));
	err->Position = Start;
	err->DontStrip = true;
	JB_SetRef(err->Description, s);
	JB_SetRef(err->OriginalData, JB__Tk_Data);
	JB_Rec_SyntaxAppend(JB_StdErr, err);
	JB_Decr(err);
	return nil;
}

void JB_Tk__ErrorEvent(int Start, int ExpectedBits, int RealBits) {
	FastString* Err = JB_Incr(JB_FS__New());
	if ((!(((bool)(RealBits & kJB__Tk_IllegalChar))))) {
		if ((!(((bool)ExpectedBits) and (((bool)RealBits) and ((bool)JB_Tk__FindError(ExpectedBits)))))) {
			JB_FS_AppendString(Err, JB_str_158);
		} else {
			{
				int _i = 0;
				while (_i < 5) {
					ExpectedBits = JB_Tk__MessageErrorSub(Err, ExpectedBits, RealBits);
					_i++;
					if ((!ExpectedBits)) {
						break;
					}
				};
			};
			JB_FS_AppendString(Err, JB_str_82);
		}
	}
	if (RealBits == kJB__Tk_EndOfLine) {
		JB_FS_AppendString(Err, JB_str_159);
	} else if ((!RealBits)) {
		JB_FS_AppendString(Err, JB_str_160);
	} else {
		if (JB_Tk__NextStart() <= Start) {
			(JB_Tk__NextStartSet(Start + 1));
		}
		if (((bool)(RealBits & kJB__Tk_IllegalChar))) {
			JB_FS_AppendString(Err, JB_str_161);
			byte illegal = JB_Str_ByteValue(JB__Tk_Data, Start);
			if (JB_byte_CanPrintAsNormalChar(illegal)) {
				JB_FS_AppendByte(Err, '\'');
				JB_FS_AppendByte(Err, JB_Str_ByteValue(JB__Tk_Data, Start));
				JB_FS_AppendByte(Err, '\'');
			} else {
				JB_FS_AppendString(Err, JB_str_35);
				JB_FS_AppendHex(Err, illegal, 2);
				JB_FS_AppendByte(Err, ' ');
			}
		} else {
			JB_FS_AppendByte(Err, '\'');
			int N = JB_int_OperatorMin(JB_Tk__NextStart(), (Start + 100));
			JB_String* _tmP1 = JB_Incr(({
				JB_String* _tmP407 = JB_Incr(JB_Str_Range(JB__Tk_Data, Start, N));
				JB_String* _tmP406 = JB_Incr(JB_Str_Escape(_tmP407));
				JB_Decr(_tmP407);
				JB_SafeDecr(_tmP406);
				 _tmP406;
			}));
			JB_FS_AppendString(Err, _tmP1);
			JB_Decr(_tmP1);
			JB_FS_AppendByte(Err, '\'');
		}
	}
	JB_FreeIfDead(({
		JB_String* _tmP409 = JB_Incr(JB_FS_SyntaxCast(Err));
		Message* _tmP408 = JB_Incr(JB_Tk__ErrorAdd(_tmP409, Start));
		JB_Decr(_tmP409);
		JB_SafeDecr(_tmP408);
		 _tmP408;
	}));
	JB_Decr(Err);
}

void JB_Tk__ErrorLetter(int Start) {
	JB_FreeIfDead(JB_Tk__ErrorAdd(JB_str_154, Start));
}

bool JB_Tk__ExpectEndChar(JB_String* s, bool Expect) {
	JB_Tk__CleanSpaces();
	if (JB_Tk__EatString(s)) {
		return true;
	}
	if (Expect) {
		FastString* _fs_fs = JB_Incr(JB_FS__New());
		JB_FS_AppendString(_fs_fs, JB_str_136);
		JB_FS_AppendString(_fs_fs, s);
		JB_FS_AppendString(_fs_fs, JB_str_24);
		JB_String* _fs_str = JB_Incr(JB_FS_SyntaxCast(_fs_fs));
		JB_SetRef(_fs_fs, nil);
		JB_Decr(_fs_fs);
		JB_FreeIfDead(JB_Tk__ErrorAdd(_fs_str, JB_Tk__NextStart()));
		JB_Decr(_fs_str);
	}
	return false;
}

Message* JB_Tk__fAccess(int Start) {
	Message* result = JB_Incr(JB_Tk__NewParent0(nil, JB_SyxAcc, Start));
	Message* prms = JB_Incr(JB_Tk__NewParent0(result, JB_SyxArr, Start));
	JB_Tk__ParseLoop(prms, JB_str_137);
	JB_Decr(prms);
	JB_SafeDecr(result);
	return result;
}

Message* JB_Tk__fAdjectiveOp(int Start) {
	Message* result = JB_Incr(JB_Tk__NewParent0(nil, JB_SyxAdj, Start));
	Message* _tmP = JB_Incr(JB_Tk__Process(kJB__Tk_OppChain, kJB__Tk_Expect));
	JB_Tree_SyntaxAppend(result, _tmP);
	JB_Decr(_tmP);
	JB_SafeDecr(result);
	return result;
}

Message* JB_Tk__fAdjectiveThing(int Start) {
	Message* result = JB_Incr(JB_Tk__NewParent0(nil, JB_SyxAdj, Start));
	Message* _tmP = JB_Incr(JB_Tk__ProcessThing(0, kJB__Tk_Expect));
	JB_Tree_SyntaxAppend(result, _tmP);
	JB_Decr(_tmP);
	JB_SafeDecr(result);
	return result;
}

Message* JB_Tk__fAfterRel(int Start) {
	return JB_Tk__NewParent(nil, JB_SyxARel, Start, JB_Tk__NextStart());
}

Message* JB_Tk__fAnaphoricReference(int Start) {
	return JB_Tk__NewWord(nil, JB_SyxAna, Start, JB_Tk__NextStart());
}

Message* JB_Tk__fArgColon(int Start) {
	Message* Result = JB_Incr(JB_Tk__NewParentName(nil, JB_SyxArg, Start, JB_str_112));
	while (true) {
		Message* Item = JB_Incr(JB_Tk__Process(kJB__Tk_Temporal, false));
		if ((!(Item))) {
			JB_SetRef(Item, JB_Tk__ProcessThing(kJB__Tk_Opp, false));
		}
		JB_Tree_SyntaxAppend(Result, Item);
		if ((!(((bool)Item) and JB_Tk__Allow(kJB__Tk_Comma)))) {
			JB_Decr(Item);
			break;
		}
		JB_Decr(Item);
	};
	JB_SafeDecr(Result);
	return Result;
}

Message* JB_Tk__fArgOpen(int Start) {
	Message* Result = JB_Incr(JB_Tk__NewParent0(nil, JB_SyxArg, Start));
	JB_Tk__ParseLoop(Result, JB_str_145);
	JB_SafeDecr(Result);
	return Result;
}

Message* JB_Tk__fArray(int Start) {
	Message* Result = JB_Incr(JB_Tk__NewParent0(nil, JB_SyxArr, Start));
	JB_Tk__ParseLoop(Result, JB_str_137);
	JB_SafeDecr(Result);
	return Result;
}

Message* JB_Tk__fAtName(int Start) {
	return JB_Tk__NewWord(nil, JB_SyxName, Start, JB_Tk__NextStart());
}

Message* JB_Tk__fAtNamedExp(int Start) {
	Message* result = JB_Incr(JB_Tk__NewParent0(nil, JB_SyxName, Start));
	Message* _tmP = JB_Incr(JB_Tk__ProcessThing(0, kJB__Tk_Expect));
	JB_Tree_SyntaxAppend(result, _tmP);
	JB_Decr(_tmP);
	JB_SafeDecr(result);
	return result;
}

Message* JB_Tk__fBackTick(int Start) {
	return JB_Tk__fStrSub(Start, JB_str_133, JB_SyxBack);
}

Message* JB_Tk__fBarTypeCast(int Start) {
	return JB_Tk__BarThings(Start, JB_SyxType);
}

Message* JB_Tk__fBeforeRel(int Start) {
	return JB_Tk__BeforeRelSub(Start, kJB__Tk_Expect);
}

Message* JB_Tk__fBeforeRelMinus(int Start) {
	byte c = JB_Str_ByteValue(JB__Tk_Data, Start + 1);
	if (JB_byte_IsNum(c) and (JB_Str_ByteValue(JB__Tk_Data, Start) == '-')) {
		return JB_Tk__NumberSub(Start + 1, Start);
	}
	return JB_Tk__BeforeRelSub(Start, kJB__Tk_Allow);
}

Message* JB_Tk__fBinary(int Start) {
	int End = JB_Str_InStr(JB__Tk_Data, JB_str_101, Start + 2, kJB__int_max, false);
	if ((!JB_int_Found(End))) {
		return JB_Tk__ErrorAdd(JB_str_102, JB_Tk__NextStart());
	}
	JB_String* S = JB_Incr(JB_Str_Range(JB__Tk_Data, Start + 2, End));
	(JB_Tk__NextStartSet(End + 2));
	Message* _tmP = JB_Incr(({
		JB_String* _tmP328 = JB_Incr(JB_Str_DecodeB64(S, nil));
		Message* _tmP327 = JB_Incr(JB_Tk__NewParentName(nil, JB_SyxBin, Start, _tmP328));
		JB_Decr(_tmP328);
		JB_SafeDecr(_tmP327);
		 _tmP327;
	}));
	JB_Decr(S);
	JB_SafeDecr(_tmP);
	return _tmP;
}

Message* JB_Tk__fBracket(int Start) {
	Message* Result = JB_Tk__NewParent0(nil, JB_SyxList, Start);
	bool Lines = JB_Tk__ParseLoop(Result, JB_str_141);
	if ((!Lines) and JB_Ring_HasChildCount(Result, 1)) {
		JB_Msg_Become(Result, JB_SyxBra, JB_str_0);
	}
	return Result;
}

Message* JB_Tk__fBunchOfThings(int Start) {
	Message* result = JB_Incr(JB_Tk__NewParent(nil, JB_SyxBnch, Start, JB_Tk__NextStart()));
	Message* _tmP = JB_Incr(JB_Tk__ProcessThing(kJB__Tk_Opp, kJB__Tk_Expect));
	JB_Tree_SyntaxAppend(result, _tmP);
	JB_Decr(_tmP);
	JB_SafeDecr(result);
	return result;
}

Message* JB_Tk__fChr(int Start) {
	int After = JB_Str_JBFind(JB__Tk_Data, '\'', JB_Tk__NextStart(), kJB__int_max);
	if ((!JB_int_Found(After))) {
		return JB_Tk__ErrorAdd(JB_str_142, JB_Tk__NextStart());
	}
	(JB_Tk__NextStartSet(After + 1));
	JB_String* name = JB_Incr(({
		JB_String* _tmP388 = JB_Incr(JB_Str_Range(JB__Tk_Data, Start + 1, After));
		JB_String* _tmP387 = JB_Incr(JB_Str_Unescape(_tmP388));
		JB_Decr(_tmP388);
		JB_SafeDecr(_tmP387);
		 _tmP387;
	}));
	Message* _tmP = JB_Incr(JB_Tk__NewParentName(nil, JB_SyxChar, Start, name));
	JB_Decr(name);
	JB_SafeDecr(_tmP);
	return _tmP;
}

Message* JB_Tk__fComment(int Start) {
	int Count = 1;
	int i = JB_Tk__NextStart();
	JB_String* d = JB_Incr(JB__Tk_Data);
	while (true) {
		i = JB_Str_FindWithByteIntInt(d, '/', i + 1, kJB__int_max);
		if ((!JB_int_Found(i))) {
			JB_Decr(d);
			return JB_Tk__ErrorAdd(JB_str_143, Start);
		} else if (JB_Str_ByteValue(d, i - 1) == '*') {
			Count--;
		} else if (JB_Str_ByteValue(d, i + 1) == '*') {
			Count++;
			i = (i + 2);
		}
		if ((!Count)) {
			break;
		}
	};
	JB_Decr(d);
	(JB_Tk__NextStartSet(i + 1));
	return JB__Tk_EndOfLineMarker;
}

Message* JB_Tk__fCommentLine(int Start) {
	(JB_Tk__NextStartSet(JB_Str_FindWithBmIntInt(JB__Tk_Data, JB__Constants_CSLine, JB_Tk__NextStart(), kJB__int_max)));
	return JB__Tk_EndOfLineMarker;
}

Message* JB_Tk__fDecl(int Start) {
	Message* Result = JB_Incr(JB_Tk__BarThings(Start, JB_SyxDecl));
	if ((!Result)) {
		JB_Decr(Result);
		return nil;
	}
	while ((!JB_Tk__WillEnd())) {
		Message* Curr = JB_Incr(JB_Tk__ProcessThing(kJB__Tk_OppSyx | kJB__Tk_OppTemporal, false));
		if ((!Curr)) {
			JB_Tk__Expect(kJB__Tk_End);
			JB_Decr(Curr);
			break;
		}
		JB_Tree_SyntaxAppend(Result, Curr);
		JB_Decr(Curr);
	};
	JB_SafeDecr(Result);
	return Result;
}

Message* JB_Tk__fDot(int Start) {
	return JB_Tk__DotSub(JB_SyxDot, Start);
}

Message* JB_Tk__fEndOfLine(int Start) {
	return JB__Tk_EndOfLineMarker;
}

Message* JB_Tk__fError(int Start) {
	return nil;
}

Message* JB_Tk__fFuncCall(int Start) {
	Message* Result = JB_Incr(JB_Tk__NewParent0(nil, JB_SyxFunc, Start));
	JB_Tk__Params(Result, Start);
	JB_SafeDecr(Result);
	return Result;
}

Message* JB_Tk__fIndentError(int Start) {
	JB_FreeIfDead(JB_Tk__ErrorAdd(JB_str_157, Start));
	return nil;
}

int JB_Tk__FindError(int num) {
	if (num == kJB__Tk_Thing) {
		return kJB__Tk_Thing;
	}
	{
		DictionaryReader* _nav = JB_Incr(JB_Dict_Navigate(JB__Tk_ErrorNames));
		while (JB_Nav_MoveNext(_nav)) {
			JB_String* Key = JB_Incr(JB_Nav_Name(_nav));
			int i = JB_Str_ParseInt(Key, nil);
			JB_Decr(Key);
			if ((num & i) == i) {
				JB_Decr(_nav);
				return i;
			}
		};
		JB_Decr(_nav);
	};
	return 0;
}

Message* JB_Tk__fMsgList(int Start) {
	Message* name = JB_Incr(JB_Tk__Process(kJB__Tk_TemporalWord, true));
	if ((!name)) {
		JB_Decr(name);
		return nil;
	}
	Message* bad = JB_Incr(((Message*)JB_Tree_SyntaxAccessWithInt(name, 1)));
	if (bad) {
		JB_Decr(name);
		Message* _tmP = JB_Incr(JB_Tk__ErrorAdd(JB_str_138, bad->Position));
		JB_Decr(bad);
		JB_SafeDecr(_tmP);
		return _tmP;
	}
	JB_Decr(bad);
	Message* Result = JB_Incr(JB_Tk__NewParent0(nil, JB_SyxMsg, Start));
	JB_Tree_SyntaxAppend(Result, name);
	JB_Decr(name);
	int Ops = kJB__Tk_OppSyx | (kJB__Tk_OppTemporal | kJB__Tk_OppYoda);
	while (JB_Tk__ConsumeLines(JB_SyxList)) {
		Message* item = JB_Incr(JB_Tk__ProcessThing(Ops, false));
		if ((!item)) {
			JB_Decr(item);
			break;
		}
		if (JB_Str_OperatorEndsWith(item->Name, JB_str_77)) {
			JB_Decr(Result);
			Message* _tmP1 = JB_Incr(JB_Tk__ErrorAdd(JB_str_139, item->Position));
			JB_Decr(item);
			JB_SafeDecr(_tmP1);
			return _tmP1;
		}
		JB_Tree_SyntaxAppend(Result, item);
		JB_Decr(item);
	};
	JB_Tk__ExpectEndChar(JB_str_77, true);
	JB_SafeDecr(Result);
	return Result;
}

Message* JB_Tk__fNumber(int Start) {
	return JB_Tk__NumberSub(Start, Start);
}

Message* JB_Tk__fOpAsThing(int Start) {
	Message* Result = JB_Incr(JB_Tk__NewParent0(nil, JB_SyxOat, Start));
	Message* _tmP = JB_Incr(JB_Tk__Process(kJB__Tk_Opp, false));
	JB_Tree_SyntaxAppend(Result, _tmP);
	JB_Decr(_tmP);
	Message* _tmP1 = JB_Incr(JB_Tk__ProcessThing(kJB__Tk_Opp, false));
	JB_Tree_SyntaxAppend(Result, _tmP1);
	JB_Decr(_tmP1);
	JB_SafeDecr(Result);
	return Result;
}

Message* JB_Tk__fOppBracket(int Start) {
	Message* result = JB_Incr(JB_Tk__NewParent0(nil, JB_SyxBra, Start));
	Message* opp1 = JB_Incr(JB_Tk__Process(kJB__Tk_OppChain, false));
	Message* opp2 = JB_Incr(JB_Tk__Process(kJB__Tk_Opp, false));
	if ((!opp2)) {
		JB_Tree_SyntaxAppend(result, opp1);
	} else {
		Message* rel = JB_Incr(JB_Tk__NewParent0(result, JB_SyxRel, JB_Tk__NextStart() - 1));
		JB_Tree_SyntaxAppend(rel, opp1);
		JB_Tree_SyntaxAppend(rel, opp2);
		Message* _tmP = JB_Incr(JB_Tk__Process(kJB__Tk_OppChain, false));
		JB_Tree_SyntaxAppend(rel, _tmP);
		JB_Decr(_tmP);
		JB_Decr(rel);
	}
	JB_Decr(opp2);
	JB_Decr(opp1);
	JB_Tk__ExpectEndChar(JB_str_141, true);
	Message* _tmP1 = JB_Incr(JB_Tk__OppChain(result));
	JB_Decr(result);
	JB_SafeDecr(_tmP1);
	return _tmP1;
}

Message* JB_Tk__fOppSyx(int Start) {
	return JB_Tk__NewParent(nil, JB_SyxSOpp, Start, JB_Tk__NextStart());
}

Message* JB_Tk__fOppSyxNeq(int Start) {
	Message* result = JB_Incr(JB_Tk__fOppSyx(Start));
	byte c = JB_Tk__NextByte();
	if (c == '=') {
		JB_Decr(result);
		return JB_Tk__ErrorAdd(JB_str_144, JB_Tk__NextStart());
	}
	JB_SafeDecr(result);
	return result;
}

Message* JB_Tk__fOppWord(int Start) {
	int After = JB_Tk__WordAfter(Start);
	byte C = JB_Str_ByteValue(JB__Tk_Data, After);
	if ((!(C != '.'))) {
		return nil;
	}
	Message* opp = JB_Incr(JB_Tk__NewParent(nil, JB_SyxOpp, Start, After));
	Message* _tmP = JB_Incr(JB_Tk__OppChain(opp));
	JB_Decr(opp);
	JB_SafeDecr(_tmP);
	return _tmP;
}

Message* JB_Tk__fOppYoda(int Start) {
	return JB_Tk__NewParent(nil, JB_SyxYopp, Start, JB_Tk__NextStart());
}

Message* JB_Tk__fQuestion(int Start) {
	Message* opp = JB_Incr(JB_Tk__Process(kJB__Tk_Opp, kJB__Tk_Expect));
	Message* first = JB_Incr(JB_Tk__ProcessThing(kJB__Tk_OppSyx, kJB__Tk_Expect));
	Message* last = JB_Incr(JB_Tk__ProcessThing(kJB__Tk_Opp, kJB__Tk_Allow));
	if ((!(((bool)first) and ((bool)opp)))) {
		JB_Decr(opp);
		JB_Decr(first);
		JB_Decr(last);
		return nil;
	}
	Message* rel = JB_Incr(JB_Tk__NewParent0(nil, JB_SyxAsk, Start));
	JB_Tree_SyntaxAppend(rel, first);
	JB_Decr(first);
	JB_Tree_SyntaxAppend(rel, opp);
	JB_Tree_SyntaxAppend(rel, last);
	JB_Decr(last);
	if (JB_Msg_SyntaxEqualsWithSyxBool(opp, JB_SyxSOpp, false)) {
		opp->Func = JB_SyxOpp;
	}
	JB_Decr(opp);
	JB_SafeDecr(rel);
	return rel;
}

Message* JB_Tk__fSDot(int Start) {
	if (Start > 0) {
		byte c = JB_Str_ByteValue(JB__Tk_Data, Start - 1);
		if (JB_BM_HasChar(JB__Constants_CSWordMiddle, c)) {
			return nil;
		}
	}
	return JB_Tk__DotSub(JB_SyxSDot, Start);
}

Message* JB_Tk__fShebang(int Start) {
	int S = JB_Tk__NextStart();
	int S2 = JB_Str_FindWithBmIntInt(JB__Tk_Data, JB__Constants_CSLine, S, kJB__int_max);
	(JB_Tk__NextStartSet(S2));
	return JB_Tk__NewSkip(nil, JB_SyxSheb, Start, S, S2);
}

Message* JB_Tk__fStatement(int Start) {
	return JB_Tk__fStatementSub(Start, kJB__Tk_Opp & (~kJB__Tk_OppBra));
}

Message* JB_Tk__fStatementColon(int Start) {
	return JB_Tk__fStatementSub(Start, kJB__Tk_colonarg | (kJB__Tk_Opp & (~kJB__Tk_OppBra)));
}

Message* JB_Tk__fStatementSub(int Start, int Flags) {
	int After = JB_Tk__WordAfter(Start);
	if (JB_Tk__WillEnd()) {
		return JB_Tk__NewParent(nil, JB_SyxTmp, Start, After);
	}
	if ((!JB_BM_HasChar(JB__Constants_CSAfterTemporal, JB_Tk__NextByte()))) {
		return nil;
	}
	Message* result = nil;
	while (true) {
		Message* item = JB_Incr(JB_Tk__ProcessThing(Flags, false));
		if ((!item)) {
			JB_Decr(item);
			break;
		}
		if ((!(result))) {
			JB_SetRef(result, JB_Tk__NewParent(nil, JB_SyxTmp, Start, After));
		}
		JB_Tree_SyntaxAppend(result, item);
		Flags = (Flags | kJB__Tk_colonarg);
		if (JB_Tk__WillEnd()) {
			JB_Decr(item);
			JB_SafeDecr(result);
			return result;
		}
		if (JB_Msg_SyntaxEqualsWithSyxBool(item, JB_SyxArg, false)) {
			Message* SubTmp = JB_Incr(JB_Tk__Process(kJB__Tk_temporalwordcolon, false));
			if (SubTmp) {
				JB_Tree_SyntaxAppend(result, SubTmp);
				JB_Decr(item);
				JB_Decr(SubTmp);
				JB_SafeDecr(result);
				return result;
			}
			JB_Decr(SubTmp);
		}
		JB_Decr(item);
	};
	JB_Decr(result);
	return nil;
}

Message* JB_Tk__fString(int Start) {
	int After = JB_Str_JBFind(JB__Tk_Data, '"', JB_Tk__NextStart(), kJB__int_max);
	if ((!(JB_int_Found(After)))) {
		return JB_Tk__ErrorAdd(JB_str_146, JB_Tk__NextStart());
	}
	int StrPos = Start + 1;
	Message* result = JB_Incr(JB_Tk__NewParent0(nil, JB_SyxStr, Start));
	while (true) {
		int NewStrPos = JB_Str_JBFind(JB__Tk_Data, '$', StrPos, After);
		if ((!(JB_int_Found(NewStrPos)))) {
			NewStrPos = After;
		}
		if (NewStrPos > StrPos) {
			Message* Str = JB_Incr(JB_Tk__NewParent(result, JB_SyxEmb, StrPos, NewStrPos));
			JB_SetRef(Str->Name, JB_Str_Unescape(Str->Name));
			JB_Decr(Str);
		}
		if (NewStrPos >= After) {
			break;
		}
		NewStrPos++;
		byte C0 = JB_Str_ByteValue(JB__Tk_Data, NewStrPos);
		if (C0 == '{') {
			NewStrPos++;
		}
		(JB_Tk__NextStartSet(NewStrPos));
		if (C0 == '{') {
			StrPos = JB_Tk__EmbeddedCode(JB_str_145, result, JB_SyxList);
		} else {
			StrPos = JB_Str_OutCharSet(JB__Tk_Data, JB__Constants_CSWordMiddle, NewStrPos + 1, After);
			if ((!JB_int_Found(StrPos))) {
				StrPos = After;
			}
			JB_FreeIfDead(JB_Tk__NewParent(result, JB_SyxThg, NewStrPos, StrPos));
		}
		if (StrPos > After) {
			JB_Decr(result);
			return JB_Tk__ErrorAdd(JB_str_147, NewStrPos);
		}
	};
	(JB_Tk__NextStartSet(After + 1));
	JB_Msg_UnEmbed(result);
	JB_SafeDecr(result);
	return result;
}

Message* JB_Tk__fStrSub(int Start, JB_String* Ender, Syntax syx) {
	int After = JB_Str_InStr(JB__Tk_Data, Ender, JB_Tk__NextStart(), kJB__int_max, false);
	if ((!JB_int_Found(After))) {
		return JB_Tk__ErrorAdd(JB_str_140, JB_Tk__NextStart());
	}
	int FindLen = JB_Str_Length(Ender);
	(JB_Tk__NextStartSet(After + FindLen));
	return JB_Tk__NewSkip(nil, syx, Start, Start + FindLen, After);
}

Message* JB_Tk__fSuperStr(int Start) {
	return JB_Tk__fStrSub(Start, JB_str_65, JB_SyxSStr);
}

Message* JB_Tk__fTemporalRel(int Start) {
	JB_Tk__CleanSpaces();
	return JB_Tk__NewWord(nil, JB_SyxCnj, Start, JB_Tk__NextStart());
}

Message* JB_Tk__fTemporalRelSyx(int Start) {
	return JB_Tk__NewParent(nil, JB_SyxSCnj, Start, JB_Tk__NextStart());
}

Message* JB_Tk__fThingSyx(int Start) {
	return JB_Tk__NewParent(nil, JB_SyxSThg, Start, JB_Tk__NextStart());
}

Message* JB_Tk__fThingWord(int Start) {
	int name = JB_Tk__WordAfter(Start);
	return JB_Tk__NewParent(nil, JB_SyxThg, Start, name);
}

Message* JB_Tk__GetFuncAfter(Message* input) {
	Message* Result = JB_Incr(input);
	while (true) {
		int ThisAfter = kJB__Tk_FuncAfterAny & (~JB__Tk_StopBars);
		if (JB_Tk__NoFuncAfter(JB_Tk__NextByte())) {
			ThisAfter = (ThisAfter & (~kJB__Tk_FuncAfterNoSpace));
		}
		Message* d = JB_Incr(JB_Tk__Process(ThisAfter, false));
		if ((!(d))) {
			JB_Decr(d);
			break;
		}
		if ((!JB_Msg_SyntaxEqualsWithSyxBool(d, JB_SyxName, false))) {
			(JB_Ring_FirstSet(d, Result));
		} else if ((!JB_Msg_SyntaxEqualsWithSyxBool(Result, JB_SyxThg, false))) {
			JB_FreeIfDead(JB_Tk__ErrorAdd(JB_str_151, JB_Tk__NextStart()));
		} else {
			JB_SetRef(d->Name, Result->Name);
		}
		JB_SetRef(Result, d);
		JB_Decr(d);
	};
	JB_SafeDecr(Result);
	return Result;
}

void JB_Tk__Init() {
	JB_Tk__TokenzWithStrIntParsehandler(JB_str_110, kJB__Tk_EndOfLine, JB_Tk__fEndOfLine);
	TokHan* _tmP1 = JB_Incr(JB_Tk__Handler(kJB__Tk_Comma | kJB__Tk_EndOfLine, ((TokenHandler_fp)JB_Tk__fEndOfLine)));
	(JB_Tk__TokenSet(JB_str_111, _tmP1));
	JB_Decr(_tmP1);
	TokHan* _tmP2 = JB_Incr(({
		TokHan* _tmP351 = JB_Incr(JB_Tk__Handler(kJB__Tk_colon, ((TokenHandler_fp)JB_Tk__fEndOfLine)));
		TokHan* _tmP350 = JB_Incr(JB_TH_Link(_tmP351, kJB__Tk_colonarg, ((TokenHandler_fp)JB_Tk__fArgColon)));
		JB_Decr(_tmP351);
		JB_SafeDecr(_tmP350);
		 _tmP350;
	}));
	(JB_Tk__TokenSet(JB_str_112, _tmP2));
	JB_Decr(_tmP2);
	JB_SetRef(JB__Tk_EndOfLineMarker, JB_Msg__NewWithSyxStr(nil, JB_str_18));
	Array* numb = JB_Incr(JB_Str_ByteSplit(JB_str_113));
	JB_String* op_comp = JB_Incr(JB_str_114);
	JB_String* op_math = JB_Incr(JB_str_115);
	JB_String* op_math2 = JB_Incr(JB_str_116);
	JB_Decr(op_math2);
	JB_String* PFix = JB_Incr(JB_str_117);
	TokHan* H = JB_Incr(({
		TokHan* _tmP353 = JB_Incr(({
			TokHan* _tmP355 = JB_Incr(({
				TokHan* _tmP357 = JB_Incr(JB_Tk__Handler(kJB__Tk_ThingWord, ((TokenHandler_fp)JB_Tk__fThingWord)));
				TokHan* _tmP356 = JB_Incr(JB_TH_Link(_tmP357, kJB__Tk_TemporalWord, ((TokenHandler_fp)JB_Tk__fStatement)));
				JB_Decr(_tmP357);
				JB_SafeDecr(_tmP356);
				 _tmP356;
			}));
			TokHan* _tmP354 = JB_Incr(JB_TH_Link(_tmP355, kJB__Tk_temporalwordcolon, ((TokenHandler_fp)JB_Tk__fStatementColon)));
			JB_Decr(_tmP355);
			JB_SafeDecr(_tmP354);
			 _tmP354;
		}));
		TokHan* _tmP352 = JB_Incr(JB_TH_Link(_tmP353, kJB__Tk_OppWord, ((TokenHandler_fp)JB_Tk__fOppWord)));
		JB_Decr(_tmP353);
		JB_SafeDecr(_tmP352);
		 _tmP352;
	}));
	Array* _tmP3 = JB_Incr(JB_BM_Bytes(JB__Constants_CSWordStart));
	JB_Tk__TokensWithArrayTh(_tmP3, H);
	JB_Decr(_tmP3);
	JB_Decr(H);
	TokHan* _tmP4 = JB_Incr(({
		TokHan* _tmP361 = JB_Incr(({
			TokHan* _tmP363 = JB_Incr(JB_Tk__Handler(kJB__Tk_FuncAfterNoSpace, ((TokenHandler_fp)JB_Tk__fFuncCall)));
			TokHan* _tmP362 = JB_Incr(JB_TH_Link(_tmP363, kJB__Tk_ThingSyx, ((TokenHandler_fp)JB_Tk__fBracket)));
			JB_Decr(_tmP363);
			JB_SafeDecr(_tmP362);
			 _tmP362;
		}));
		TokHan* _tmP360 = JB_Incr(JB_TH_Link(_tmP361, kJB__Tk_OppBra, ((TokenHandler_fp)JB_Tk__fOppBracket)));
		JB_Decr(_tmP361);
		JB_SafeDecr(_tmP360);
		 _tmP360;
	}));
	(JB_Tk__TokenSet(JB_str_118, _tmP4));
	JB_Decr(_tmP4);
	TokHan* _tmP5 = JB_Incr(({
		TokHan* _tmP366 = JB_Incr(JB_Tk__Handler(kJB__Tk_FuncAfterNoSpace, ((TokenHandler_fp)JB_Tk__fAccess)));
		TokHan* _tmP365 = JB_Incr(JB_TH_Link(_tmP366, kJB__Tk_ThingSyx, ((TokenHandler_fp)JB_Tk__fArray)));
		JB_Decr(_tmP366);
		JB_SafeDecr(_tmP365);
		 _tmP365;
	}));
	(JB_Tk__TokenSet(JB_str_119, _tmP5));
	JB_Decr(_tmP5);
	TokHan* _tmP6 = JB_Incr(JB_Tk__Handler(kJB__Tk_ThingSyx, ((TokenHandler_fp)JB_Tk__fMsgList)));
	(JB_Tk__TokenSet(JB_str_75, _tmP6));
	JB_Decr(_tmP6);
	TokHan* _tmP7 = JB_Incr(({
		TokHan* _tmP370 = JB_Incr(JB_Tk__Handler(kJB__Tk_FuncAfterNoSpace, ((TokenHandler_fp)JB_Tk__fDot)));
		TokHan* _tmP369 = JB_Incr(JB_TH_Link(_tmP370, kJB__Tk_ThingSyx, ((TokenHandler_fp)JB_Tk__fSDot)));
		JB_Decr(_tmP370);
		JB_SafeDecr(_tmP369);
		 _tmP369;
	}));
	(JB_Tk__TokenSet(JB_str_29, _tmP7));
	JB_Decr(_tmP7);
	TokHan* _tmP8 = JB_Incr(({
		TokHan* _tmP373 = JB_Incr(JB_Tk__Handler(kJB__Tk_FuncAfterBar, ((TokenHandler_fp)JB_Tk__fBarTypeCast)));
		TokHan* _tmP372 = JB_Incr(JB_TH_Link(_tmP373, kJB__Tk_TemporalSyx, ((TokenHandler_fp)JB_Tk__fDecl)));
		JB_Decr(_tmP373);
		JB_SafeDecr(_tmP372);
		 _tmP372;
	}));
	(JB_Tk__TokenSet(JB_str_120, _tmP8));
	JB_Decr(_tmP8);
	TokHan* _tmP9 = JB_Incr(({
		TokHan* _tmP376 = JB_Incr(JB_Tk__Handler(kJB__Tk_ThingSyx, ((TokenHandler_fp)JB_Tk__fAtName)));
		TokHan* _tmP375 = JB_Incr(JB_TH_Link(_tmP376, kJB__Tk_FuncAfterNormal, ((TokenHandler_fp)JB_Tk__fAtNamedExp)));
		JB_Decr(_tmP376);
		JB_SafeDecr(_tmP375);
		 _tmP375;
	}));
	(JB_Tk__TokenSet(JB_str_121, _tmP9));
	JB_Decr(_tmP9);
	TokHan* _tmP10 = JB_Incr(({
		TokHan* _tmP379 = JB_Incr(JB_Tk__Handler(kJB__Tk_FuncAfterNormal, ((TokenHandler_fp)JB_Tk__fAdjectiveThing)));
		TokHan* _tmP378 = JB_Incr(JB_TH_Link(_tmP379, kJB__Tk_adjectiveop, ((TokenHandler_fp)JB_Tk__fAdjectiveOp)));
		JB_Decr(_tmP379);
		JB_SafeDecr(_tmP378);
		 _tmP378;
	}));
	(JB_Tk__TokenSet(JB_str_122, _tmP10));
	JB_Decr(_tmP10);
	JB_Tk__TokenzWithStrIntParsehandler(JB_str_123, kJB__Tk_ThingSyx, JB_Tk__fBeforeRelMinus);
	JB_Tk__TokenzWithStrIntParsehandler(PFix, kJB__Tk_ThingSyx, JB_Tk__fBeforeRel);
	JB_Tk__TokenzWithStrIntParsehandler(PFix, kJB__Tk_FuncAfterNormal, JB_Tk__fAfterRel);
	JB_Decr(PFix);
	JB_Tk__TokenzWithStrIntParsehandler(JB_str_124, kJB__Tk_ThingSyx, JB_Tk__fBeforeRel);
	JB_Tk__TokenzWithStrIntParsehandler(JB_str_124, kJB__Tk_FuncAfterNormal, JB_Tk__fAfterRel);
	JB_Tk__TokenzWithStrIntParsehandler(JB_str_125, kJB__Tk_ThingSyx, JB_Tk__fArgOpen);
	JB_Tk__TokenzWithStrIntParsehandler(JB_str_126, kJB__Tk_TmpOpp, JB_Tk__fTemporalRel);
	JB_Tk__TokenzWithStrIntParsehandler(JB_str_127, kJB__Tk_TmpOpp, JB_Tk__fTemporalRelSyx);
	JB_Tk__TokenzWithStrIntParsehandler(JB_str_43, kJB__Tk_ThingSyx, JB_Tk__fOpAsThing);
	JB_Tk__TokenzWithStrIntParsehandler(JB_str_72, kJB__Tk_ThingSyx, JB_Tk__fAnaphoricReference);
	JB_Tk__TokenzWithStrIntParsehandler(JB_str_74, kJB__Tk_ThingSyx, JB_Tk__fQuestion);
	JB_Tk__TokensWithArrayIntParsehandler(numb, kJB__Tk_ThingSyx, JB_Tk__fNumber);
	JB_Decr(numb);
	JB_Tk__TokenzWithStrIntParsehandler(JB_str_71, kJB__Tk_TemporalSyx, JB_Tk__fShebang);
	JB_Tk__TokenzWithStrIntParsehandler(JB_str_128, kJB__Tk_EndOfLine, JB_Tk__fCommentLine);
	JB_Tk__TokenzWithStrIntParsehandler(JB_str_129, kJB__Tk_EndOfLine, JB_Tk__fComment);
	JB_Tk__TokenzWithStrIntParsehandler(op_comp, kJB__Tk_OppSyx, JB_Tk__fOppSyxNeq);
	JB_Decr(op_comp);
	JB_Tk__TokenzWithStrIntParsehandler(op_math, kJB__Tk_OppSyx, JB_Tk__fOppSyx);
	JB_Decr(op_math);
	JB_Tk__TokenzWithStrIntParsehandler(JB_str_130, kJB__Tk_OppYoda, JB_Tk__fOppYoda);
	JB_Tk__TokenzWithStrIntParsehandler(JB_str_131, kJB__Tk_ThingSyx, JB_Tk__fBunchOfThings);
	JB_Tk__TokenzWithStrIntParsehandler(JB_str_132, kJB__Tk_ThingSyx, JB_Tk__fThingSyx);
	JB_Tk__TokenzWithStrIntParsehandler(JB_str_54, kJB__Tk_ThingSyx, JB_Tk__fString);
	JB_Tk__TokenzWithStrIntParsehandler(JB_str_24, kJB__Tk_ThingSyx, JB_Tk__fChr);
	JB_Tk__TokenzWithStrIntParsehandler(JB_str_133, kJB__Tk_ThingSyx, JB_Tk__fBackTick);
	JB_Tk__TokenzWithStrIntParsehandler(JB_str_66, kJB__Tk_ThingSyx, JB_Tk__fSuperStr);
	JB_Tk__TokenzWithStrIntParsehandler(JB_str_134, kJB__Tk_ThingSyx, JB_Tk__fBeforeRel);
	JB_Tk__TokenzWithStrIntParsehandler(JB_str_100, kJB__Tk_ThingSyx, JB_Tk__fBinary);
	JB_Tk__TokenzWithStrIntParsehandler(JB_str_135, kJB__Tk_EndContainer, JB_Tk__fEndOfLine);
	TokHan* _tmP11 = JB_Incr(JB_Tk__Handler(-1, ((TokenHandler_fp)JB_Tk__fIndentError)));
	(JB_Tk__TokenNilSet(JB_str_17, _tmP11));
	JB_Decr(_tmP11);
	TokHan* IllegalHandler = JB_Incr(JB_Tk__Handler(-1, ((TokenHandler_fp)JB_Tk__fError)));
	{
		int i = 0;
		while (i < 256) {
			JB_String* _tmP12 = JB_Incr(JB_Str__SyntaxAccess(i));
			(JB_Tk__TokenNilSet(_tmP12, IllegalHandler));
			JB_Decr(_tmP12);
			i++;
		};
	};
	JB_Decr(IllegalHandler);
}

int JB_Tk__Init_() {
	{
		JB_SetRef(JB__Tk_Data, JB_str_0);
		JB__Tk_StopBars = 0;
		JB__Tk_UsingPos = -1;
		JB__Tk_IndentationAware = false;
		JB_StdErr = JB_Rec__New();
	};
	return 0;
}

Message* JB_Tk__InvisArgEscapeNested(Message* curr) {
	while (true) {
		Message* p = ((Message*)JB_Ring_Parent(curr));
		if ((!JB_Msg_SyntaxEqualsWithSyxBool(p, JB_SyxTmp, false))) {
			return curr;
		}
		curr = p;
	};
	return nil;
}

Message* JB_Tk__InvisArgNest(Message* self, Message* curr) {
	JB_Tree_SyntaxAppend(curr, self);
	return JB_Tk__MakeInvisArg(self, self->Indent + 2);
}

Message* JB_Tk__MakeInvisArg(Message* parent, int indent) {
	Message* Arg = JB_Tk__NewParent0(parent, JB_SyxArg, parent->Position);
	Arg->Indent = indent;
	JB_SetRef(Arg->Name, JB_str_17);
	return Arg;
}

Message* JB_Tk__MakeRel(Message* first, int Bits) {
	Message* opp = JB_Incr(JB_Tk__Process(Bits, false));
	if ((!opp)) {
		JB_Decr(opp);
		return first;
	}
	Message* Rel = JB_Incr(JB_Tk__NewParent0(nil, JB_SyxRel, first->Position));
	if (JB_Msg_SyntaxEqualsWithSyxBool(opp, JB_SyxYopp, false)) {
		JB_Decr(opp);
		Message* _tmP1 = JB_Incr(JB_Tk__MakeYoda(first, Bits, Rel));
		JB_Decr(Rel);
		JB_SafeDecr(_tmP1);
		return _tmP1;
	}
	JB_Tree_SyntaxAppend(Rel, first);
	JB_Tree_SyntaxAppend(Rel, opp);
	if (JB_Tk__EatString(JB_str_152)) {
		Rel->Func = JB_SyxERel;
	}
	bool Mode = kJB__Tk_Allow;
	if (JB_Msg_SyntaxEqualsWithSyxBool(opp, JB_SyxSOpp, false)) {
		Mode = kJB__Tk_Expect;
		Bits = (Bits | kJB__Tk_OppWord);
		opp->Func = JB_SyxOpp;
	}
	JB_Decr(opp);
	Message* _tmP = JB_Incr(JB_Tk__ProcessThing(Bits, Mode));
	JB_Tree_SyntaxAppend(Rel, _tmP);
	JB_Decr(_tmP);
	JB_SafeDecr(Rel);
	return Rel;
}

Message* JB_Tk__MakeYoda(Message* first, int Bits, Message* Rel) {
	Message* thg = JB_Incr(JB_Tk__ProcessThing(Bits & (~kJB__Tk_Opp), kJB__Tk_Expect));
	if ((!thg)) {
		JB_Decr(thg);
		return nil;
	}
	JB_Tree_SyntaxAppend(Rel, thg);
	JB_Decr(thg);
	Bits = ((Bits & (~kJB__Tk_OppYoda)) | kJB__Tk_OppBra);
	Message* opp = JB_Incr(JB_Tk__Process(Bits, kJB__Tk_Expect));
	if ((!opp)) {
		JB_Decr(opp);
		return nil;
	}
	JB_Tree_SyntaxAppend(Rel, opp);
	JB_Tree_SyntaxAppend(Rel, first);
	if (JB_Msg_SyntaxEqualsWithSyxBool(opp, JB_SyxSOpp, false)) {
		opp->Func = JB_SyxOpp;
	}
	JB_Decr(opp);
	Rel->Func = JB_SyxYoda;
	return Rel;
}

int JB_Tk__MessageErrorSub(FastString* fs, int num, int ButFound) {
	if ((!JB__Tk_ErrorNames)) {
		JB_SetRef(JB__Tk_ErrorNames, JB_Dict__New());
		(JB_Dict_SyntaxAccessSet(JB__Tk_ErrorNames, kJB__Tk_Temporal, JB_str_162));
		(JB_Dict_SyntaxAccessSet(JB__Tk_ErrorNames, kJB__Tk_TemporalSyx, JB_str_163));
		(JB_Dict_SyntaxAccessSet(JB__Tk_ErrorNames, kJB__Tk_TemporalWord, JB_str_164));
		(JB_Dict_SyntaxAccessSet(JB__Tk_ErrorNames, kJB__Tk_EndOfLine, JB_str_159));
		(JB_Dict_SyntaxAccessSet(JB__Tk_ErrorNames, kJB__Tk_colon, JB_str_165));
		(JB_Dict_SyntaxAccessSet(JB__Tk_ErrorNames, kJB__Tk_OppSyx, JB_str_166));
		(JB_Dict_SyntaxAccessSet(JB__Tk_ErrorNames, kJB__Tk_OppWord, JB_str_166));
		(JB_Dict_SyntaxAccessSet(JB__Tk_ErrorNames, kJB__Tk_Opp, JB_str_166));
		(JB_Dict_SyntaxAccessSet(JB__Tk_ErrorNames, kJB__Tk_OppTemporal, JB_str_167));
		(JB_Dict_SyntaxAccessSet(JB__Tk_ErrorNames, kJB__Tk_FuncAfterBar, JB_str_168));
		(JB_Dict_SyntaxAccessSet(JB__Tk_ErrorNames, kJB__Tk_Thing, JB_str_169));
		(JB_Dict_SyntaxAccessSet(JB__Tk_ErrorNames, kJB__Tk_ThingWord, JB_str_169));
		(JB_Dict_SyntaxAccessSet(JB__Tk_ErrorNames, kJB__Tk_ThingSyx, JB_str_170));
		(JB_Dict_SyntaxAccessSet(JB__Tk_ErrorNames, kJB__Tk_IllegalChar, JB_str_171));
	}
	if (JB_FS_Length(fs)) {
		JB_FS_AppendString(fs, JB_str_172);
	} else {
		JB_FS_AppendString(fs, JB_str_81);
	}
	int BestValue = JB_Tk__FindError(num);
	if (BestValue) {
		JB_String* _tmP = JB_Incr(((JB_String*)JB_Dict_SyntaxAccessWithInt64(JB__Tk_ErrorNames, BestValue)));
		JB_FS_AppendString(fs, _tmP);
		JB_Decr(_tmP);
		return num & (~BestValue);
	}
	JB_FS_AppendString(fs, JB_str_173);
	return 0;
}

Message* JB_Tk__NewParent(Message* Parent, Syntax Func, int Start, int End) {
	JB_String* Name = JB_Str_Range(JB__Tk_Data, Start, End);
	Message* Result = JB_Msg__NewParser(Parent, Func, Start, Name);
	return Result;
}

Message* JB_Tk__NewParent0(Message* Parent, Syntax Func, int Start) {
	return JB_Msg__NewParser(Parent, Func, Start, JB_str_0);
}

Message* JB_Tk__NewParentName(Message* Parent, Syntax Func, int Start, JB_String* name) {
	return JB_Msg__NewParser(Parent, Func, Start, name);
}

Message* JB_Tk__NewSkip(Message* P, Syntax F, int Start, int NameStart, int NameEnd) {
	Message* result = JB_Tk__NewParent(P, F, NameStart, NameEnd);
	result->Position = Start;
	return result;
}

Message* JB_Tk__NewWord(Message* P, Syntax F, int Start, int SearchFrom) {
	int after = JB_Tk__WordAfter(SearchFrom);
	Message* result = JB_Tk__NewParent(P, F, SearchFrom, after);
	result->Position = Start;
	return result;
}

bool JB_Tk__NoFuncAfter(byte b) {
	return (b == '\t') or ((b == ' ') or (b == '\\'));
}

Message* JB_Tk__NumberSub(int Start, int RealStart) {
	int After = JB_Tk__NumEnd(JB__Tk_Data, Start);
	(JB_Tk__NextStartSet(After));
	int StartAt = JB_Str_IsHexLike(JB__Tk_Data, Start);
	int UnitPos2 = JB_Str_OutCharSet(JB__Tk_Data, JB__Constants_CSLettersOnly, After, Start + StartAt);
	if ((!(JB_int_Found(UnitPos2)))) {
		UnitPos2 = (After - 1);
	}
	UnitPos2++;
	Message* Num = JB_Tk__NewParent(nil, JB_SyxNum, RealStart, UnitPos2);
	if (After <= UnitPos2) {
		return Num;
	}
	Message* unit = JB_Tk__NewParent(nil, JB_SyxUnit, UnitPos2, After);
	JB_Tree_SyntaxAppend(unit, Num);
	return unit;
}

int JB_Tk__NumEnd(JB_String* NumStr, int Start) {
	int Dot = JB_Str_OutCharSet(NumStr, JB__Constants_CSNum, Start, kJB__int_max);
	if ((!(JB_int_Found(Dot)))) {
		return JB_Str_Length(NumStr);
	}
	if ((!(JB_Str_ByteValue(NumStr, Dot) == '.'))) {
		return Dot;
	}
	byte AfterDot = JB_Str_ByteValue(NumStr, Dot + 1);
	if ((!(JB_byte_IsNumeric(AfterDot)))) {
		return Dot;
	}
	int Result = JB_Str_OutCharSet(NumStr, JB__Constants_CSNum, Dot + 1, kJB__int_max);
	if ((!(JB_int_Found(Result)))) {
		return JB_Str_Length(NumStr);
	}
	return Result;
}

bool JB_Tk__OK() {
	return (!JB_int_Found(JB_Tk__ErrorStart()));
}

Message* JB_Tk__OppChain(Message* opp) {
	Message* result = JB_Incr(JB_Tk__Process(kJB__Tk_adjectiveop, false));
	if ((!result)) {
		JB_Decr(result);
		return opp;
	}
	(JB_Ring_FirstSet(result, opp));
	JB_SafeDecr(result);
	return result;
}

void JB_Tk__Params(Message* Parent, int N) {
	Message* Result = JB_Incr(JB_Tk__NewParent0(Parent, JB_SyxList, N));
	JB_Tk__ParseLoop(Result, JB_str_141);
	JB_Decr(Result);
}

Message* JB_Tk__ParseItem(Message* ch, int TemporalFlags) {
	Message* Result = JB_Incr(JB_Tk__NewParent0(nil, JB_SyxItem, JB_Tk__NextStart() - 1));
	Message* ch2 = JB_Incr(JB_Tk__Process(TemporalFlags, false));
	if ((!(ch2))) {
		JB_SetRef(ch2, JB_Tk__ProcessThing(kJB__Tk_Opp, false));
	}
	if ((!(ch2))) {
		JB_SetRef(ch2, JB_Tk__NewParent0(nil, JB_SyxEmb, Result->Position));
	}
	JB_Tree_SyntaxAppend(Result, ch);
	JB_Tree_SyntaxAppend(Result, ch2);
	JB_Decr(ch2);
	JB_SafeDecr(Result);
	return Result;
}

bool JB_Tk__ParseLoop(Message* Output, JB_String* Ender) {
	int Result = JB_Tk__ParseLoopMode(Output, Output->Func);
	if (JB_Str_Exists(Ender)) {
		JB_Tk__ExpectEndChar(Ender, true);
	}
	return ((bool)Result);
}

int JB_Tk__ParseLoopMode(Message* Output, Syntax Syx) {
	int Lines = JB_Tk__ConsumeLines(Syx);
	int Flags = JB_Syx_Parseflags(Syx) & (~JB__Tk_StopBars);
	while ((!JB_Tk__WillEnd())) {
		int Indent = -1;
		if (Lines) {
			Indent = JB_Tk__ClearIndent();
		}
		Message* ch = JB_Tk__Process(kJB__Tk_Temporal & Flags, false);
		if ((!(ch))) {
			ch = JB_Tk__ThingOrItem(Flags);
			if ((!ch)) {
				break;
			}
			Lines = (Lines + ((int)((JB_Msg_SyntaxEqualsWithSyxBool(ch, JB_SyxItem, false)))));
		} else if ((JB_Msg_SyntaxEqualsWithSyxBool(ch, JB_SyxCnj, false)) or (JB_Msg_SyntaxEqualsWithSyxBool(ch, JB_SyxSCnj, false))) {
			ch = JB_Tk__ReRoute(ch, Output);
		}
		ch->Indent = Indent;
		JB_Tree_SyntaxAppend(Output, ch);
		if (JB_Msg_SyntaxEqualsWithSyxBool(Output, JB_SyxArg, false)) {
			int IndExtra = JB_Msg_PrevIndentCheck(ch);
			if (IndExtra > 0) {
				Output = JB_Msg_GoIntoInvisArg(ch);
			} else if (IndExtra < 0) {
				Output = JB_Msg_ExitInvisArg(ch, (-IndExtra));
			}
		}
		if ((!(JB_Tk__ConsumeLines(Syx)))) {
			break;
		}
		Lines++;
	};
	return Lines;
}

Message* JB_Tk__ProcessThing(int Ops, bool Expect) {
	int ColonFlags = Ops & kJB__Tk_colonarg;
	Ops = (Ops & (~kJB__Tk_colonarg));
	Message* result = JB_Incr(JB_Tk__Process(kJB__Tk_Thing | ColonFlags, Expect));
	if ((!result)) {
		JB_Decr(result);
		return nil;
	}
	if (JB_Tk__WillEnd()) {
		JB_SafeDecr(result);
		return result;
	}
	JB_SetRef(result, JB_Tk__GetFuncAfter(result));
	if (JB_Tk__WillEnd()) {
		JB_SafeDecr(result);
		return result;
	}
	int NotTemp = Ops & (~kJB__Tk_OppTemporal);
	if (((bool)NotTemp) and (!JB_Msg_SyntaxEqualsWithSyxBool(result, JB_SyxArg, false))) {
		JB_SetRef(result, JB_Tk__MakeRel(result, NotTemp));
	}
	if (((bool)(Ops & kJB__Tk_OppTemporal))) {
		Message* opp = JB_Incr(JB_Tk__Process(kJB__Tk_OppTemporal, false));
		if (opp) {
			JB_SetRef(result, JB_Tk__ChainTemporalRels(result, opp));
		}
		JB_Decr(opp);
	}
	JB_SafeDecr(result);
	return result;
}

Message* JB_Tk__ReRoute(Message* cnj, Message* output) {
	Message* f = JB_Incr(((Message*)JB_Ring_Last(output)));
	if ((!(f))) {
		JB_Decr(f);
		return JB_Tk__ErrorAdd(JB_str_153, JB_Tk__NextStart());
	}
	Message* Result = JB_Incr(JB_Tk__ChainTemporalRels(f, cnj));
	JB_Decr(f);
	if ((JB_Ring_HasChildCount(Result, 2)) and JB_Tk__Allow(kJB__Tk_EndOfLine)) {
		Message* _tmP = JB_Incr(JB_Tk__ProcessThing(kJB__Tk_Opp, false));
		JB_Tree_SyntaxAppend(Result, _tmP);
		JB_Decr(_tmP);
	}
	JB_SafeDecr(Result);
	return Result;
}

void JB_Tk__StopParse() {
	JB_Tk__StartParse(nil);
}

Message* JB_Tk__ThingOrItem(int Flags) {
	Message* item = JB_Tk__ProcessThing(kJB__Tk_Opp, false);
	if ((!item)) {
		return nil;
	}
	if ((!(JB_Tk__Allow(kJB__Tk_colon)))) {
		return item;
	}
	return JB_Tk__ParseItem(item, Flags);
}

void JB_Tk__TokensWithArrayIntParsehandler(Array* arr, int bits, ParseHandler func) {
	TokHan* _tmP = JB_Incr(JB_Tk__Handler(bits, ((TokenHandler_fp)func)));
	JB_Tk__TokensWithArrayTh(arr, _tmP);
	JB_Decr(_tmP);
}

void JB_Tk__TokensWithArrayTh(Array* arr, TokHan* H) {
	{
		int _i = 0;
		while (_i < JB_Array_Size(arr)) {
			JB_String* s = JB_Incr(((JB_String*)JB_Array_Value(arr, _i)));
			(JB_Tk__TokenSet(s, H));
			JB_Decr(s);
			_i++;
		};
	};
}

void JB_Tk__TokenzWithStrIntParsehandler(JB_String* s, int bits, ParseHandler func) {
	if (JB_Str_OperatorContainsWithStr(s, JB_str_15)) {
		Array* _tmP = JB_Incr(JB_Str_Words(s));
		JB_Tk__TokensWithArrayIntParsehandler(_tmP, bits, func);
		JB_Decr(_tmP);
	} else {
		TokHan* _tmP1 = JB_Incr(JB_Tk__Handler(bits, ((TokenHandler_fp)func)));
		(JB_Tk__TokenSet(s, _tmP1));
		JB_Decr(_tmP1);
	}
}

bool JB_Tk__WillEnd() {
	return JB_Tk__CheckEnded(kJB__Tk_End);
}

int JB_Tk__WordAfter(int Start) {
	int After = JB_Str_OutCharSet(JB__Tk_Data, JB__Constants_CSWordMiddle, Start, kJB__int_max);
	if (((After == -1) and (Start >= JB_Str_Length(JB__Tk_Data))) or (After == Start)) {
		JB_Tk__ErrorLetter(Start);
		return 0;
	}
	(JB_Tk__NextStartSet(After));
	return After;
}


bool JB_Platform__linux() {
	return (({
		JB_String* _tmP229 = JB_Incr(JB_Platform());
		bool _tmP228 = JB_Str_SyntaxEquals(_tmP229, JB_str_38, false);
		JB_Decr(_tmP229);
		 _tmP228;
	}));
}


void JB_BinaryEscapeTest(JB_String* AllBytes) {
	FastString* fs = JB_Incr(JB_FS__New());
	JB_String* a = JB_Incr(JB_str_48);
	{
		int _i1 = 0;
		while (_i1 < 10) {
			JB_FreeIfDead(JB_Str_EncodeB64(a, fs));
			JB_String* result = JB_Incr(JB_FS_GetResult(fs));
			JB_String* b = JB_Incr(JB_Str_DecodeB64(result, nil));
			JB_Decr(result);
			if ((!(JB_Str_SyntaxEquals(a, b, false)))) {
				FastString* _fs_fs = JB_Incr(JB_FS__New());
				JB_FS_AppendString(_fs_fs, JB_str_49);
				JB_FS_AppendString(_fs_fs, a);
				JB_FS_AppendString(_fs_fs, JB_str_50);
				JB_FS_AppendString(_fs_fs, b);
				JB_String* _fs_str = JB_Incr(JB_FS_SyntaxCast(_fs_fs));
				JB_SetRef(_fs_fs, nil);
				JB_Decr(_fs_fs);
				JB_Str_SyntaxExpect(_fs_str);
				JB_Decr(_fs_str);
				JB_Decr(fs);
				JB_Decr(a);
				JB_Decr(b);
				return;
			}
			JB_Decr(b);
			JB_SetRef(a, ({
				JB_String* _tmP247 = JB_Incr(JB_Str_OperatorPlus(JB_str_51, a));
				JB_String* _tmP246 = JB_Incr(JB_Str_OperatorPlus(a, _tmP247));
				JB_Decr(_tmP247);
				JB_SafeDecr(_tmP246);
				 _tmP246;
			}));
			_i1++;
		};
	};
	JB_Decr(a);
	JB_FS_AppendHexDataWithStr(fs, AllBytes);
	JB_String* Hexed = JB_Incr(JB_FS_GetResult(fs));
	JB_FS_AppendMultiByte(fs, '\0', 256);
	JB_String* Str2 = JB_Incr(JB_FS_GetResult(fs));
	JB_Decr(fs);
	JB_Str_UnHexRaw(Hexed, Str2->Addr, JB_Str_Length(Str2));
	JB_Decr(Hexed);
	if ((!(JB_Str_SyntaxEquals(Str2, AllBytes, false)))) {
		JB_Object_SyntaxExpect(nil);
		JB_Decr(Str2);
		return;
	}
	JB_Decr(Str2);
}

bool JB_CompareError(Message* expected, Message* found) {
	FastString* _fs_fs = JB_Incr(JB_FS__New());
	JB_FS_AppendString(_fs_fs, JB_str_81);
	JB_String* _tmP3 = JB_Incr(JB_Msg_Locate(expected));
	JB_FS_AppendString(_fs_fs, _tmP3);
	JB_Decr(_tmP3);
	JB_FS_AppendString(_fs_fs, JB_str_82);
	JB_String* _tmP4 = JB_Incr(JB_Msg_Locate(found));
	JB_FS_AppendString(_fs_fs, _tmP4);
	JB_Decr(_tmP4);
	JB_String* _fs_str = JB_Incr(JB_FS_SyntaxCast(_fs_fs));
	JB_SetRef(_fs_fs, nil);
	JB_Decr(_fs_fs);
	JB_Str_PrintLine(_fs_str);
	JB_Decr(_fs_str);
	FastString* _fs1_fs = JB_Incr(JB_FS__New());
	JB_FS_AppendString(_fs1_fs, JB_str_83);
	JB_String* _tmP5 = JB_Incr(({
		Message* _tmP300 = JB_Incr(JB_Msg_PoorAnt(expected));
		JB_String* _tmP299 = JB_Incr(JB_Msg_Locate(_tmP300));
		JB_Decr(_tmP300);
		JB_SafeDecr(_tmP299);
		 _tmP299;
	}));
	JB_FS_AppendString(_fs1_fs, _tmP5);
	JB_Decr(_tmP5);
	JB_String* _fs1_str = JB_Incr(JB_FS_SyntaxCast(_fs1_fs));
	JB_SetRef(_fs1_fs, nil);
	JB_Decr(_fs1_fs);
	JB_Str_PrintLine(_fs1_str);
	JB_Decr(_fs1_str);
	if (found) {
		FastString* _fs2_fs = JB_Incr(JB_FS__New());
		JB_FS_AppendString(_fs2_fs, JB_str_84);
		JB_String* _tmP6 = JB_Incr(({
			Message* _tmP303 = JB_Incr(JB_Msg_PoorAnt(found));
			JB_String* _tmP302 = JB_Incr(JB_Msg_Locate(_tmP303));
			JB_Decr(_tmP303);
			JB_SafeDecr(_tmP302);
			 _tmP302;
		}));
		JB_FS_AppendString(_fs2_fs, _tmP6);
		JB_Decr(_tmP6);
		JB_String* _fs2_str = JB_Incr(JB_FS_SyntaxCast(_fs2_fs));
		JB_SetRef(_fs2_fs, nil);
		JB_Decr(_fs2_fs);
		JB_Str_PrintLine(_fs2_str);
		JB_Decr(_fs2_str);
	} else {
		found = expected;
	}
	JB_Msg_SyntaxExpect(found, nil);
	return false;
}

Dictionary* JB_Dict_Copy(Dictionary* Dict) {
	Dictionary* result = JB_Incr(JB_Dict__New());
	{
		DictionaryReader* _nav = JB_Incr(JB_Dict_Navigate(Dict));
		while (JB_Nav_MoveNext(_nav)) {
			JB_String* key = JB_Incr(JB_Nav_Name(_nav));
			JB_String* value = JB_Incr(((JB_String*)JB_Nav_Value(_nav)));
			(JB_Dict_ValueSet(result, key, value));
			JB_Decr(value);
			JB_Decr(key);
		};
		JB_Decr(_nav);
	};
	JB_SafeDecr(result);
	return result;
}

JB_String* JB_EntityTest() {
	JB_String* raw = JB_Incr(JB_str_85);
	JB_String* replicate = JB_Incr(JB_str_86);
	Dictionary* repl = JB_Incr(JB_Dict__New());
	(JB_Dict_ValueSet(repl, JB_str_87, JB_str_13));
	JB_MSR_DecodeEntitySet(repl, true);
	JB_MSR_EscapeCodeSet(repl, true);
	JB_String* s3 = JB_Incr(JB_Str_Unescape(replicate));
	JB_SetRef(replicate, JB_Str_MultiReplaceAll(replicate, repl, JB_StdErr));
	JB_Decr(repl);
	if ((!(JB_Str_SyntaxEquals(raw, replicate, false)))) {
		debugger;
	}
	if ((!(JB_Str_SyntaxEquals(raw, s3, false)))) {
		debugger;
	}
	JB_Decr(s3);
	JB_Decr(raw);
	if (JB_Platform__linux()) {
	}
	JB_String* result = JB_Incr(({
		JB_String* _tmP305 = JB_Incr(JB_Str_LowerCase(replicate));
		JB_String* _tmP304 = JB_Incr(JB_Str_OperatorPlus(_tmP305, JB_str_88));
		JB_Decr(_tmP305);
		JB_SafeDecr(_tmP304);
		 _tmP304;
	}));
	JB_Decr(replicate);
	JB_SafeDecr(result);
	return result;
}

int JB_Init_() {
	{
		JB_SetRef(JB_str_337, JB_Str3("Binary", 6));
		JB_SetRef(JB_str_336, JB_Str3("bin", 3));
		JB_SetRef(JB_str_335, JB_Str3("To_Do_List", 10));
		JB_SetRef(JB_str_334, JB_Str3("todo", 4));
		JB_SetRef(JB_str_333, JB_Str3("Bunch_Of_Things", 15));
		JB_SetRef(JB_str_332, JB_Str3("bnch", 4));
		JB_SetRef(JB_str_331, JB_Str3("Message_List", 12));
		JB_SetRef(JB_str_330, JB_Str3("msg", 3));
		JB_SetRef(JB_str_329, JB_Str3("Question", 8));
		JB_SetRef(JB_str_328, JB_Str3("ask", 3));
		JB_SetRef(JB_str_327, JB_Str3("yopp", 4));
		JB_SetRef(JB_str_326, JB_Str3("Yoda_Relationship", 17));
		JB_SetRef(JB_str_325, JB_Str3("yoda", 4));
		JB_SetRef(JB_str_324, JB_Str3("Typecast", 8));
		JB_SetRef(JB_str_323, JB_Str3("type", 4));
		JB_SetRef(JB_str_322, JB_Str3("Conjugate", 9));
		JB_SetRef(JB_str_321, JB_Str3("cnj", 3));
		JB_SetRef(JB_str_320, JB_Str3("Syntactic_Conjugate", 19));
		JB_SetRef(JB_str_319, JB_Str3("scnj", 4));
		JB_SetRef(JB_str_318, JB_Str3("Temporal_Reference", 18));
		JB_SetRef(JB_str_317, JB_Str3("ana", 3));
		JB_SetRef(JB_str_316, JB_Str3("Statement", 9));
		JB_SetRef(JB_str_315, JB_Str3("tmp", 3));
		JB_SetRef(JB_str_314, JB_Str3("Thing", 5));
		JB_SetRef(JB_str_313, JB_Str3("thg", 3));
		JB_SetRef(JB_str_312, JB_Str3("Syntactic_Thing", 15));
		JB_SetRef(JB_str_311, JB_Str3("sthg", 4));
		JB_SetRef(JB_str_310, JB_Str3("String", 6));
		JB_SetRef(JB_str_309, JB_Str3("str", 3));
		JB_SetRef(JB_str_308, JB_Str3("Shebang", 7));
		JB_SetRef(JB_str_307, JB_Str3("sheb", 4));
		JB_SetRef(JB_str_306, JB_Str3("Syntactic_Comment", 17));
		JB_SetRef(JB_str_305, JB_Str3("scom", 4));
		JB_SetRef(JB_str_304, JB_Str3("Self_Dot", 8));
		JB_SetRef(JB_str_303, JB_Str3("sdot", 4));
		JB_SetRef(JB_str_302, JB_Str3("Temporal_Relationship", 21));
		JB_SetRef(JB_str_301, JB_Str3("trel", 4));
		JB_SetRef(JB_str_300, JB_Str3("Relationship", 12));
		JB_SetRef(JB_str_299, JB_Str3("rel", 3));
		JB_SetRef(JB_str_298, JB_Str3("Syntactic_Operator", 18));
		JB_SetRef(JB_str_297, JB_Str3("sopp", 4));
		JB_SetRef(JB_str_296, JB_Str3("Operator", 8));
		JB_SetRef(JB_str_295, JB_Str3("opp", 3));
		JB_SetRef(JB_str_294, JB_Str3("Operator_As_Thing", 17));
		JB_SetRef(JB_str_293, JB_Str3("oat", 3));
		JB_SetRef(JB_str_292, JB_Str3("unit", 4));
		JB_SetRef(JB_str_291, JB_Str3("Number", 6));
		JB_SetRef(JB_str_290, JB_Str3("num", 3));
		JB_SetRef(JB_str_289, JB_Str3("name", 4));
		JB_SetRef(JB_str_288, JB_Str3("item", 4));
		JB_SetRef(JB_str_287, JB_Str3("Function", 8));
		JB_SetRef(JB_str_286, JB_Str3("func", 4));
		JB_SetRef(JB_str_285, JB_Str3("Equals_Relationship", 19));
		JB_SetRef(JB_str_284, JB_Str3("erel", 4));
		JB_SetRef(JB_str_283, JB_Str3("Embedded_Value", 14));
		JB_SetRef(JB_str_282, JB_Str3("emb", 3));
		JB_SetRef(JB_str_281, JB_Str3("Dot", 3));
		JB_SetRef(JB_str_280, JB_Str3("dot", 3));
		JB_SetRef(JB_str_279, JB_Str3("Declaration", 11));
		JB_SetRef(JB_str_278, JB_Str3("decl", 4));
		JB_SetRef(JB_str_277, JB_Str3("Character", 9));
		JB_SetRef(JB_str_276, JB_Str3("Before_Relationship", 19));
		JB_SetRef(JB_str_275, JB_Str3("brel", 4));
		JB_SetRef(JB_str_274, JB_Str3("Bracket", 7));
		JB_SetRef(JB_str_273, JB_Str3("bra", 3));
		JB_SetRef(JB_str_272, JB_Str3("Super_String", 12));
		JB_SetRef(JB_str_271, JB_Str3("sstr", 4));
		JB_SetRef(JB_str_270, JB_Str3("Backtick", 8));
		JB_SetRef(JB_str_269, JB_Str3("back", 4));
		JB_SetRef(JB_str_268, JB_Str3("Array", 5));
		JB_SetRef(JB_str_267, JB_Str3("arr", 3));
		JB_SetRef(JB_str_266, JB_Str3("After_Relationship", 18));
		JB_SetRef(JB_str_265, JB_Str3("arel", 4));
		JB_SetRef(JB_str_264, JB_Str3("Adjective", 9));
		JB_SetRef(JB_str_263, JB_Str3("adj", 3));
		JB_SetRef(JB_str_262, JB_Str3("Access", 6));
		JB_SetRef(JB_str_261, JB_Str3("acc", 3));
		JB_SetRef(JB_str_260, JB_Str3("Argument", 8));
		JB_SetRef(JB_str_259, JB_Str3("arg", 3));
		JB_SetRef(JB_str_258, JB_Str3("\n\r,", 3));
		JB_SetRef(JB_str_257, JB_Str3(" ,:\t\n\r\\", 7));
		JB_SetRef(JB_str_256, JB_Str3("\n\r", 2));
		JB_SetRef(JB_str_255, JB_Str3("AZaz__", 6));
		JB_SetRef(JB_str_254, JB_Str3("AZaz", 4));
		JB_SetRef(JB_str_253, JB_Str3("AZaz09__", 8));
		JB_SetRef(JB_str_252, JB_Str3("\\f", 2));
		JB_SetRef(JB_str_251, JB_Str3("", 1));
		JB_SetRef(JB_str_250, JB_Str3("\\b", 2));
		JB_SetRef(JB_str_249, JB_Str3("", 1));
		JB_SetRef(JB_str_248, JB_Str3("\\&#", 3));
		JB_SetRef(JB_str_247, JB_Str3("&#", 2));
		JB_SetRef(JB_str_246, JB_Str3("\\\\", 2));
		JB_SetRef(JB_str_245, JB_Str3("\\'", 2));
		JB_SetRef(JB_str_244, JB_Str3("\\\"", 2));
		JB_SetRef(JB_str_243, JB_Str3("\\t", 2));
		JB_SetRef(JB_str_242, JB_Str3("\\r", 2));
		JB_SetRef(JB_str_241, JB_Str3("\r", 1));
		JB_SetRef(JB_str_240, JB_Str3("\0", 1));
		JB_SetRef(JB_str_239, JB_Str3("[0;1;33m", 9));
		JB_SetRef(JB_str_238, JB_Str3("[0;1;32m", 9));
		JB_SetRef(JB_str_237, JB_Str3("[0;1;31m", 9));
		JB_SetRef(JB_str_236, JB_Str3("[0;1m", 6));
		JB_SetRef(JB_str_235, JB_Str3("[0m", 4));
		JB_SetRef(JB_str_234, JB_Str3("@JBSave\n", 8));
		JB_SetRef(JB_str_233, JB_Str3("unusedtype", 10));
		JB_SetRef(JB_str_232, JB_Str3("point4", 6));
		JB_SetRef(JB_str_231, JB_Str3("point3", 6));
		JB_SetRef(JB_str_230, JB_Str3("point2", 6));
		JB_SetRef(JB_str_229, JB_Str3("ipoint4", 7));
		JB_SetRef(JB_str_228, JB_Str3("ipoint3", 7));
		JB_SetRef(JB_str_227, JB_Str3("ipoint2", 7));
		JB_SetRef(JB_str_226, JB_Str3("s16", 3));
		JB_SetRef(JB_str_225, JB_Str3("u16", 3));
		JB_SetRef(JB_str_224, JB_Str3("s8", 2));
		JB_SetRef(JB_str_223, JB_Str3("f16", 3));
		JB_SetRef(JB_str_222, JB_Str3("f64", 3));
		JB_SetRef(JB_str_221, JB_Str3("u64", 3));
		JB_SetRef(JB_str_220, JB_Str3("s64", 3));
		JB_SetRef(JB_str_219, JB_Str3("u32", 3));
		JB_SetRef(JB_str_218, JB_Str3("uint", 4));
		JB_SetRef(JB_str_217, JB_Str3("int", 3));
		JB_SetRef(JB_str_216, JB_Str3("mat4", 4));
		JB_SetRef(JB_str_215, JB_Str3("mat2", 4));
		JB_SetRef(JB_str_214, JB_Str3("vec4", 4));
		JB_SetRef(JB_str_213, JB_Str3("vec3", 4));
		JB_SetRef(JB_str_212, JB_Str3("vec2", 4));
		JB_SetRef(JB_str_211, JB_Str3("double", 6));
		JB_SetRef(JB_str_210, JB_Str3("float", 5));
		JB_SetRef(JB_str_209, JB_Str3("hfloat", 6));
		JB_SetRef(JB_str_208, JB_Str3("ivec4", 5));
		JB_SetRef(JB_str_207, JB_Str3("ivec3", 5));
		JB_SetRef(JB_str_206, JB_Str3("ivec2", 5));
		JB_SetRef(JB_str_205, JB_Str3("uint64", 6));
		JB_SetRef(JB_str_204, JB_Str3("int64", 5));
		JB_SetRef(JB_str_203, JB_Str3("s16x4", 5));
		JB_SetRef(JB_str_202, JB_Str3("s16x3", 5));
		JB_SetRef(JB_str_201, JB_Str3("s16x2", 5));
		JB_SetRef(JB_str_200, JB_Str3("int16", 5));
		JB_SetRef(JB_str_199, JB_Str3("uint16", 6));
		JB_SetRef(JB_str_198, JB_Str3("sbyte4", 6));
		JB_SetRef(JB_str_197, JB_Str3("sbyte3", 6));
		JB_SetRef(JB_str_196, JB_Str3("sbyte2", 6));
		JB_SetRef(JB_str_195, JB_Str3("sbyte", 5));
		JB_SetRef(JB_str_194, JB_Str3("byte4", 5));
		JB_SetRef(JB_str_193, JB_Str3("byte3", 5));
		JB_SetRef(JB_str_192, JB_Str3("byte2", 5));
		JB_SetRef(JB_str_191, JB_Str3("char", 4));
		JB_SetRef(JB_str_190, JB_Str3("u8", 2));
		JB_SetRef(JB_str_189, JB_Str3("').", 3));
		JB_SetRef(JB_str_188, JB_Str3("' (found '", 10));
		JB_SetRef(JB_str_187, JB_Str3("Can’t parse number '", 22));
		JB_SetRef(JB_str_186, JB_Str3("Not indented properly\?", 22));
		JB_SetRef(JB_str_185, JB_Str3("Manual inspection:\n\n", 20));
		JB_SetRef(JB_str_184, JB_Str3("entities", 8));
		JB_SetRef(JB_str_183, JB_Str3("«tmp \"how\"\n\t«oat \n\t\t«opp \"can\"»\n\t\t«trel \n\t\t\t«rel \n\t\t\t\t«thg \"someone\"»\n\t\t\t\t«opp \"fall\"»\n\t\t\t\t«adj \n\t\t\t\t\t«thg \"so\"»\n\t\t\t\t\t«thg \"far\"»\n\t\t\t\t»\n\t\t\t»\n\t\t\t«cnj \"without\"»\n\t\t\t«oat \n\t\t\t\t«opp \"realising\"»\n\t\t\t\t«ana \"it\"»\n\t\t\t»\n\t\t»\n\t»\n»\n«tmp \"story\"\n\t«thg \"X\"»\n\t«list \n\t\t«trel \n\t\t\t«rel \n\t\t\t\t«thg \"x\"»\n\t\t\t\t«bra \n\t\t\t\t\t«adj \n\t\t\t\t\t\t«opp \"a\"»\n\t\t\t\t\t\t«opp \"b\"»\n\t\t\t\t\t»\n\t\t\t\t»\n\t\t\t\t«thg \"c\"»\n\t\t\t»\n\t\t\t«scnj \"-->\"»\n\t\t\t«rel \n\t\t\t\t«name \"sonic\"\n\t\t\t\t\t«adj \n\t\t\t\t\t\t«thg \"the\"»\n\t\t\t\t\t\t«thg \"hedgedog\"»\n\t\t\t\t\t»\n\t\t\t\t»\n\t\t\t\t«opp \"or\"»\n\t\t\t\t«name \"jeebox\"»\n\t\t\t»\n\t\t»\n\t\t«trel \n\t\t\t«rel \n\t\t\t\t«thg \"A\"»\n\t\t\t\t«bra \n\t\t\t\t\t«rel \n\t\t\t\t\t\t«adj \n\t\t\t\t\t\t\t«bra \n\t\t\t\t\t\t\t\t«adj \n\t\t\t\t\t\t\t\t\t«opp \"B\"»\n\t\t\t\t\t\t\t\t\t«opp \"C\"»\n\t\t\t\t\t\t\t\t»\n\t\t\t\t\t\t\t»\n\t\t\t\t\t\t\t«opp \"D\"»\n\t\t\t\t\t\t»\n\t\t\t\t\t\t«opp \"E\"»\n\t\t\t\t\t\t«adj \n\t\t\t\t\t\t\t«opp \"F\"»\n\t\t\t\t\t\t\t«opp \"G\"»\n\t\t\t\t\t\t»\n\t\t\t\t\t»\n\t\t\t\t»\n\t\t\t\t«thg \"I\"»\n\t\t\t»\n\t\t\t«cnj \"W\"»\n\t\t\t«rel \n\t\t\t\t«thg \"A\"»\n\t\t\t\t«opp \"t\"»\n\t\t\t\t«list \n\t\t\t\t\t«item \n\t\t\t\t\t\t«thg \"o\"»\n\t\t\t\t\t\t«thg \"c\"»\n\t\t\t\t\t»\n\t\t\t\t»\n\t\t\t»\n\t\t»\n\t»\n»\n«tmp \"za\"\n\t«thg \"a\"»\n\t«arg \n\t\t«decl \n\t\t\t«num \"1\"»\n\t\t\t«rel \n\t\t\t\t«thg \"x\"»\n\t\t\t\t«opp \"*\"»\n\t\t\t\t«rel \n\t\t\t\t\t«thg \"y\"»\n\t\t\t\t\t«opp \"*\"»\n\t\t\t\t\t«rel \n\t\t\t\t\t\t«thg \"z\"»\n\t\t\t\t\t\t«opp \"=\"»\n\t\t\t\t\t\t«brel \"\?\"\n\t\t\t\t\t\t\t«arel \"\?\"\n\t\t\t\t\t\t\t\t«list »\n\t\t\t\t\t\t\t»\n\t\t\t\t\t\t»\n\t\t\t\t\t»\n\t\t\t\t»\n\t\t\t»\n\t\t»\n\t\t«decl \n\t\t\t«emb »\n\t\t\t«rel \n\t\t\t\t«thg \"a\"»\n\t\t\t\t«opp \"=\"»\n\t\t\t\t«rel \n\t\t\t\t\t«thg \"c\"»\n\t\t\t\t\t«opp \"or\"»\n\t\t\t\t\t«thg \"d\"»\n\t\t\t\t»\n\t\t\t»\n\t\t»\n\t\t«list \n\t\t\t«thg \"a\"»\n\t\t»\n\t\t«list \n\t\t\t«trel \n\t\t\t\t«arr »\n\t\t\t\t«scnj \"-->\"»\n\t\t\t\t«rel \n\t\t\t\t\t«thg \"a\"»\n\t\t\t\t\t«opp \"+\"»\n\t\t\t\t\t«thg \"a\"»\n\t\t\t\t»\n\t\t\t»\n\t\t\t«thg \"b\"»\n\t\t\t«item \n\t\t\t\t«thg \"d\"»\n\t\t\t\t«thg \"e\"»\n\t\t\t»\n\t\t»\n\t\t«arr \n\t\t\t«type \n\t\t\t\t«thg \"d\"»\n\t\t\t\t«num \"0\"»\n\t\t\t»\n\t\t\t«item \n\t\t\t\t«rel \n\t\t\t\t\t«thg \"a\"»\n\t\t\t\t\t«opp \"+\"»\n\t\t\t\t\t«thg \"b\"»\n\t\t\t\t»\n\t\t\t\t«thg \"c\"»\n\t\t\t»\n\t\t\t«arr \n\t\t\t\t«thg \"c\"»\n\t\t\t\t«thg \"d\"»\n\t\t\t»\n\t\t»\n\t»\n»\n«bin \"binary encoding oof\"»\n«tmp \"function\"\n\t«thg \"name\"»\n\t«list \n\t\t«decl \n\t\t\t«item \n\t\t\t\t«thg \"x\"»\n\t\t\t\t«rel \n\t\t\t\t\t«thg \"y\"»\n\t\t\t\t\t«opp \"+\"»\n\t\t\t\t\t«thg \"z\"»\n\t\t\t\t»\n\t\t\t»\n\t\t\t«adj \n\t\t\t\t«thg \"a\"»\n\t\t\t\t«thg \"b\"»\n\t\t\t»\n\t\t»\n\t\t«decl \n\t\t\t«emb »\n\t\t»\n\t»\n\t«arg \n\t\t«item \n\t\t\t«thg \"label\"»\n\t\t\t«func \n\t\t\t\t«thg \"func\"»\n\t\t\t\t«list »\n\t\t\t»\n\t\t»\n\t\t«str \"'\\\"striñg test\\\"'\"»\n\t\t«back \"\\\\n\\\\(\\&#x134;\\&#xEB;\\\\C3\\\\AA\\\\C6\\\\81o\\&#9447;\\\\)\"»\n\t\t«erel \n\t\t\t«brel \"--\"\n\t\t\t\t«arel \"--\"\n\t\t\t\t\t«thg \"x\"»\n\t\t\t\t»\n\t\t\t»\n\t\t\t«opp \"mod\"»\n\t\t\t«char \"ioi '\\\"\\\"'oio\"»\n\t\t»\n\t\t«dot \"y\"\n\t\t\t«dot \"size\"\n\t\t\t\t«thg \"y\"»\n\t\t\t\t«list \n\t\t\t\t\t«arel \"\?\"\n\t\t\t\t\t\t«sthg \"...\"»\n\t\t\t\t\t»\n\t\t\t\t\t«sthg \"...\"»\n\t\t\t\t\t«sstr \"s`t`r\"»\n\t\t\t\t»\n\t\t\t»\n\t\t\t«list \n\t\t\t\t«brel \"-\"\n\t\t\t\t\t«thg \"z\"»\n\t\t\t\t»\n\t\t\t»\n\t\t»\n\t\t«rel \n\t\t\t«thg \"x\"»\n\t\t\t«opp \"=\"»\n\t\t\t«rel \n\t\t\t\t«str \n\t\t\t\t\t«emb \"{ab\"»\n\t\t\t\t\t«thg \"x\"»\n\t\t\t\t\t«emb \" \"»\n\t\t\t\t\t«thg \"y\"»\n\t\t\t\t\t«thg \"z\"»\n\t\t\t\t\t«emb \"ab}\"»\n\t\t\t\t»\n\t\t\t\t«opp \"+\"»\n\t\t\t\t«back \"abc\"»\n\t\t\t»\n\t\t»\n\t\t«erel \n\t\t\t«type \n\t\t\t\t«thg \"z\"»\n\t\t\t\t«list \n\t\t\t\t\t«thg \"a\"»\n\t\t\t\t»\n\t\t\t»\n\t\t\t«opp \"+\"»\n\t\t\t«sdot \"exit\"\n\t\t\t\t«list \n\t\t\t\t\t«item \n\t\t\t\t\t\t«thg \"code\"»\n\t\t\t\t\t\t«num \"-3\"»\n\t\t\t\t\t»\n\t\t\t\t»\n\t\t\t»\n\t\t»\n\t\t«tmp \"for\"\n\t\t\t«bra \n\t\t\t\t«rel \n\t\t\t\t\t«thg \"a\"»\n\t\t\t\t\t«opp \"in\"»\n\t\t\t\t\t«thg \"b\"»\n\t\t\t\t»\n\t\t\t»\n\t\t\t«arg \n\t\t\t\t«rel \n\t\t\t\t\t«brel \"$\"\n\t\t\t\t\t\t«arel \"$\"\n\t\t\t\t\t\t\t«thg \"a\"»\n\t\t\t\t\t\t»\n\t\t\t\t\t»\n\t\t\t\t\t«opp \"=\"»\n\t\t\t\t\t«rel \n\t\t\t\t\t\t«brel \"&\"\n\t\t\t\t\t\t\t«thg \"b\"»\n\t\t\t\t\t\t»\n\t\t\t\t\t\t«opp \"+\"»\n\t\t\t\t\t\t«brel \"!\"\n\t\t\t\t\t\t\t«arel \"!\"\n\t\t\t\t\t\t\t\t«thg \"c\"»\n\t\t\t\t\t\t\t»\n\t\t\t\t\t\t»\n\t\t\t\t\t»\n\t\t\t\t»\n\t\t\t»\n\t\t»\n\t\t«tmp \"if\"\n\t\t\t«rel \n\t\t\t\t«bra \n\t\t\t\t\t«rel \n\t\t\t\t\t\t«char \"a\"»\n\t\t\t\t\t\t«opp \"&&&\"»\n\t\t\t\t\t\t«rel \n\t\t\t\t\t\t\t«thg \"b\"»\n\t\t\t\t\t\t\t«opp \"===\"»\n\t\t\t\t\t\t\t«rel \n\t\t\t\t\t\t\t\t«brel \"!\"\n\t\t\t\t\t\t\t\t\t«brel \"!\"\n\t\t\t\t\t\t\t\t\t\t«brel \"!\"\n\t\t\t\t\t\t\t\t\t\t\t«thg \"b\"»\n\t\t\t\t\t\t\t\t\t\t»\n\t\t\t\t\t\t\t\t\t»\n\t\t\t\t\t\t\t\t»\n\t\t\t\t\t\t\t\t«opp \"|||\"»\n\t\t\t\t\t\t\t\t«thg \"c\"»\n\t\t\t\t\t\t\t»\n\t\t\t\t\t\t»\n\t\t\t\t\t»\n\t\t\t\t»\n\t\t\t\t«opp \"^^^\"»\n\t\t\t\t«bra \n\t\t\t\t\t«rel \n\t\t\t\t\t\t«thg \"a\"»\n\t\t\t\t\t\t«opp \"~>=\"»\n\t\t\t\t\t\t«thg \"b\"»\n\t\t\t\t\t»\n\t\t\t\t»\n\t\t\t»\n\t\t\t«arg \n\t\t\t\t«tmp \"if\"\n\t\t\t\t\t«thg \"a\"»\n\t\t\t\t\t«arg \":\"\n\t\t\t\t\t\t«tmp \"return\"\n\t\t\t\t\t\t\t«rel \n\t\t\t\t\t\t\t\t«unit \"cm\"\n\t\t\t\t\t\t\t\t\t«num \"0xff_\"»\n\t\t\t\t\t\t\t\t»\n\t\t\t\t\t\t\t\t«opp \"+\"»\n\t\t\t\t\t\t\t\t«unit \"miles\"\n\t\t\t\t\t\t\t\t\t«num \"10_\"»\n\t\t\t\t\t\t\t\t»\n\t\t\t\t\t\t\t»\n\t\t\t\t\t\t»\n\t\t\t\t\t»\n\t\t\t\t»\n\t\t\t»\n\t\t»\n\t»\n»\n", 4262));
		JB_SetRef(JB_str_182, JB_Str3("// Jeebox self-test file.\n// Tests all syntax in small amount of code.\n// Does not make sense in any other way.\n\nhow %can someone fall so~far #without %realising –it\n\n\nstory X (\n\tx (a ~ b) c\n\t\t\t-->\n\tsonic@the~hedgedog or @jeebox\n\n\tA ((B~C)~D E F~G) I #W A t (o:c)\n)\n\n\n\n\nza a {\n\t|1| x * y * z = \?()\?\n\t|| a = c or d\n\t(a,)\n\t([] --> a + a,b,d:e)\n\t[d|0|, a+b:c, [c, d]] /* /*\n\t\tnested comments!\n\t\t*/ I found it useful.*/\n\n\t// }\n}\n\n#(OcbkON9v86LkOszaQMvd86zlPW)#\n\nfunction name (|x:y+z| a ~ b, ||) {\n\tlabel: func()\n\t\"'\\\"stri\\c3\\b1g test\\\"'\"\n\t`\\n\\(&#x134;&#xEB;\\C3\\AA\\C6\\81o&#9447;\\)`\n\t--x-- mod= 'ioi \\'\"\"\\'oio'\n\t\n\ty.size(...\?, ..., <(`s`t`r`)>).y(-z)\n\n\tx = \"{ab$\{x} $\{y}$\{z}ab}\" + `abc`\n\tz|(a,)| += .exit(code: -3)\n\n\tfor (a in b) {\n\t\t\$a$ = &b + !c!\n\t}\n\n\tif ('a' &&& b === !!!b ||| c) ^^^ (a ~>= b) {\n\t\tif a: return 0xff_cm + 10_miles\n\t}\n}\n\n\n", 838));
		JB_SetRef(JB_str_181, JB_Str3(": Failed\n\n", 10));
		JB_SetRef(JB_str_180, JB_Str3("Test ", 5));
		JB_SetRef(JB_str_179, JB_Str3("list", 4));
		JB_SetRef(JB_str_178, JB_Str3("normal", 6));
		JB_SetRef(JB_str_177, JB_Str3(" in ", 4));
		JB_SetRef(JB_str_176, JB_Str3("' at byte: ", 11));
		JB_SetRef(JB_str_175, JB_Str3(": '", 3));
		JB_SetRef(JB_str_174, JB_Str3("(nil)", 5));
		JB_SetRef(JB_str_173, JB_Str3("something else", 14));
		JB_SetRef(JB_str_172, JB_Str3(" / ", 3));
		JB_SetRef(JB_str_171, JB_Str3("illegal-character", 17));
		JB_SetRef(JB_str_170, JB_Str3("something", 9));
		JB_SetRef(JB_str_169, JB_Str3("a name", 6));
		JB_SetRef(JB_str_168, JB_Str3("'|'", 3));
		JB_SetRef(JB_str_167, JB_Str3("temporal-operator", 17));
		JB_SetRef(JB_str_166, JB_Str3("operator", 8));
		JB_SetRef(JB_str_165, JB_Str3("':'", 3));
		JB_SetRef(JB_str_164, JB_Str3("statement", 9));
		JB_SetRef(JB_str_163, JB_Str3("declaration", 11));
		JB_SetRef(JB_str_162, JB_Str3("temporal", 8));
		JB_SetRef(JB_str_161, JB_Str3("Found illegal-character ", 24));
		JB_SetRef(JB_str_160, JB_Str3("end-of-data", 11));
		JB_SetRef(JB_str_159, JB_Str3("end-of-line", 11));
		JB_SetRef(JB_str_158, JB_Str3("Unexpected ", 11));
		JB_SetRef(JB_str_157, JB_Str3("No tabs after a space!", 22));
		JB_SetRef(JB_str_156, JB_Str3(" spaces)", 8));
		JB_SetRef(JB_str_155, JB_Str3("Indents mismatch (", 18));
		JB_SetRef(JB_str_154, JB_Str3("Expected a letter (aA-zZ, '_', etc).", 36));
		JB_SetRef(JB_str_153, JB_Str3("Can’t use temporals like this.", 32));
		JB_SetRef(JB_str_152, JB_Str3("=", 1));
		JB_SetRef(JB_str_151, JB_Str3("Must be a proper name (a-z or letters)", 38));
		JB_SetRef(JB_str_150, JB_Str3("' not allowed.", 14));
		JB_SetRef(JB_str_149, JB_Str3("Nested '", 8));
		JB_SetRef(JB_str_148, JB_Str3("#/", 2));
		JB_SetRef(JB_str_147, JB_Str3("Embedded expression didn't close.", 33));
		JB_SetRef(JB_str_146, JB_Str3("String didn't close!", 20));
		JB_SetRef(JB_str_145, JB_Str3("}", 1));
		JB_SetRef(JB_str_144, JB_Str3("Can’t have '=' after this operator.", 37));
		JB_SetRef(JB_str_143, JB_Str3("Comment did not close.", 22));
		JB_SetRef(JB_str_142, JB_Str3("Char didn't close!", 18));
		JB_SetRef(JB_str_141, JB_Str3(")", 1));
		JB_SetRef(JB_str_140, JB_Str3("String did not close.", 21));
		JB_SetRef(JB_str_139, JB_Str3("Needs a space here.", 19));
		JB_SetRef(JB_str_138, JB_Str3("Unexpected syntax", 17));
		JB_SetRef(JB_str_137, JB_Str3("]", 1));
		JB_SetRef(JB_str_136, JB_Str3("Missing '", 9));
		JB_SetRef(JB_str_135, JB_Str3("] ) } #/ »", 11));
		JB_SetRef(JB_str_134, JB_Str3("~~~", 3));
		JB_SetRef(JB_str_133, JB_Str3("`", 1));
		JB_SetRef(JB_str_132, JB_Str3("...", 3));
		JB_SetRef(JB_str_131, JB_Str3("‡", 3));
		JB_SetRef(JB_str_130, JB_Str3("¬", 2));
		JB_SetRef(JB_str_129, JB_Str3("/*", 2));
		JB_SetRef(JB_str_128, JB_Str3("//", 2));
		JB_SetRef(JB_str_127, JB_Str3("--> <-- <-->", 12));
		JB_SetRef(JB_str_126, JB_Str3("#", 1));
		JB_SetRef(JB_str_125, JB_Str3("{", 1));
		JB_SetRef(JB_str_124, JB_Str3("&", 1));
		JB_SetRef(JB_str_123, JB_Str3("- *", 3));
		JB_SetRef(JB_str_122, JB_Str3("~", 1));
		JB_SetRef(JB_str_121, JB_Str3("@", 1));
		JB_SetRef(JB_str_120, JB_Str3("|", 1));
		JB_SetRef(JB_str_119, JB_Str3("[", 1));
		JB_SetRef(JB_str_118, JB_Str3("(", 1));
		JB_SetRef(JB_str_117, JB_Str3("++ -- $ ! \? ...", 15));
		JB_SetRef(JB_str_116, JB_Str3("* / + - ^ >> << >>> <<< .| .& .^ .~", 35));
		JB_SetRef(JB_str_115, JB_Str3("* / + - ^ >> << >>> <<< ||| &&& ^^^", 35));
		JB_SetRef(JB_str_114, JB_Str3("= == === < > <= <== >= >== != !== <=> ~>= ~<= ~> ~< ~= ~!= ~<=> :=", 66));
		JB_SetRef(JB_str_113, JB_Str3("0123456789", 10));
		JB_SetRef(JB_str_112, JB_Str3(":", 1));
		JB_SetRef(JB_str_111, JB_Str3(",", 1));
		JB_SetRef(JB_str_110, JB_Str3("\r \n", 3));
		JB_SetRef(JB_str_109, JB_Str3("”", 3));
		JB_SetRef(JB_str_108, JB_Str3(" “", 4));
		JB_SetRef(JB_str_107, JB_Str3("Unexpected syntax. Found ", 25));
		JB_SetRef(JB_str_106, JB_Str3(", but found ", 12));
		JB_SetRef(JB_str_105, JB_Str3("' ", 2));
		JB_SetRef(JB_str_104, JB_Str3(" '", 2));
		JB_SetRef(JB_str_103, JB_Str3("80BFC2F4", 8));
		JB_SetRef(JB_str_102, JB_Str3("Binary section didn't close!", 28));
		JB_SetRef(JB_str_101, JB_Str3(")#", 2));
		JB_SetRef(JB_str_100, JB_Str3("#(", 2));
		JB_SetRef(JB_str_99, JB_Str3("nil", 3));
		JB_SetRef(JB_str_98, JB_Str3("Starting: ", 10));
		JB_SetRef(JB_str_97, JB_Str3("' but found '", 13));
		JB_SetRef(JB_str_96, JB_Str3("' on '", 6));
		JB_SetRef(JB_str_95, JB_Str3("Expected suffix '", 17));
		JB_SetRef(JB_str_94, JB_Str3("Internal error.", 15));
		JB_SetRef(JB_str_93, JB_Str3("~/Desktop/Decomp.txt", 20));
		JB_SetRef(JB_str_92, JB_Str3("~/Desktop/Original.txt", 22));
		JB_SetRef(JB_str_91, JB_Str3("abc ", 4));
		JB_SetRef(JB_str_90, JB_Str3("\0\0\0\0\0\0", 6));
		JB_SetRef(JB_str_89, JB_Str3("abc", 3));
		JB_SetRef(JB_str_88, JB_Str3(" loaded successfully.\n", 22));
		JB_SetRef(JB_str_87, JB_Str3("\\n", 2));
		JB_SetRef(JB_str_86, JB_Str3("\\n\\(&#x134;&#xEB;\\C3\\AA\\C6\\81o&#9447;\\) ", 40));
		JB_SetRef(JB_str_85, JB_Str3("\n(ĴëêƁoⓧ) ", 16));
		JB_SetRef(JB_str_84, JB_Str3("parent of found ", 16));
		JB_SetRef(JB_str_83, JB_Str3("parent of expected ", 19));
		JB_SetRef(JB_str_82, JB_Str3(" but found ", 11));
		JB_SetRef(JB_str_81, JB_Str3("Expected ", 9));
		JB_SetRef(JB_str_80, JB_Str3("Incomplete syntax", 17));
		JB_SetRef(JB_str_79, JB_Str3(" at item ", 9));
		JB_SetRef(JB_str_78, JB_Str3("Missing ", 8));
		JB_SetRef(JB_str_77, JB_Str3("»", 2));
		JB_SetRef(JB_str_76, JB_Str3(" »", 3));
		JB_SetRef(JB_str_75, JB_Str3("«", 2));
		JB_SetRef(JB_str_74, JB_Str3("∆", 3));
		JB_SetRef(JB_str_73, JB_Str3(" ¬ ", 4));
		JB_SetRef(JB_str_72, JB_Str3("–", 3));
		JB_SetRef(JB_str_71, JB_Str3("#!", 2));
		JB_SetRef(JB_str_70, JB_Str3(" #/", 3));
		JB_SetRef(JB_str_69, JB_Str3(" /# ", 4));
		JB_SetRef(JB_str_68, JB_Str3(" @ ", 3));
		JB_SetRef(JB_str_67, JB_Str3("= ", 2));
		JB_SetRef(JB_str_66, JB_Str3("<(`", 3));
		JB_SetRef(JB_str_65, JB_Str3("`)>", 3));
		JB_SetRef(JB_str_64, JB_Str3(", ", 2));
		JB_SetRef(JB_str_63, JB_Str3("{\n", 2));
		JB_SetRef(JB_str_62, JB_Str3("Can’t find syntax: ", 21));
		JB_SetRef(JB_str_61, JB_Str3("Jeebox: Too many NilObjectErrors. Silencing.", 44));
		JB_SetRef(JB_str_60, JB_Str3("Jeebox: NilObjectError in caller.", 33));
		JB_SetRef(JB_str_59, JB_Str3("$\\{", 3));
		JB_SetRef(JB_str_58, JB_Str3("$\{", 2));
		JB_SetRef(JB_str_57, JB_Str3("\\", 1));
		JB_SetRef(JB_str_56, JB_Str3("\\\n", 2));
		JB_SetRef(JB_str_55, JB_Str3("\\0", 2));
		JB_SetRef(JB_str_54, JB_Str3("\"", 1));
		JB_SetRef(JB_str_53, JB_Str3("\\$", 2));
		JB_SetRef(JB_str_52, JB_Str3("$", 1));
		JB_SetRef(JB_str_51, JB_Str3("z", 1));
		JB_SetRef(JB_str_50, JB_Str3(" b: ", 4));
		JB_SetRef(JB_str_49, JB_Str3("binary escaper different! a: ", 29));
		JB_SetRef(JB_str_48, JB_Str3("they know what they've done", 27));
		JB_SetRef(JB_str_47, JB_Str3("1", 1));
		JB_SetRef(JB_str_46, JB_Str3("(\n", 2));
		JB_SetRef(JB_str_45, JB_Str3("nil,", 4));
		JB_SetRef(JB_str_44, JB_Str3("This class has no saving function for it.", 41));
		JB_SetRef(JB_str_43, JB_Str3("%", 1));
		JB_SetRef(JB_str_42, JB_Str3("  deviance: ", 12));
		JB_SetRef(JB_str_41, JB_Str3("  found: ", 9));
		JB_SetRef(JB_str_40, JB_Str3("expected: ", 10));
		JB_SetRef(JB_str_39, JB_Str3("win", 3));
		JB_SetRef(JB_str_38, JB_Str3("lin", 3));
		JB_SetRef(JB_str_37, JB_Str3("osx", 3));
		JB_SetRef(JB_str_36, JB_Str3("Expected class ", 15));
		JB_SetRef(JB_str_35, JB_Str3("0x", 2));
		JB_SetRef(JB_str_34, JB_Str3("This class has no loader for it.", 32));
		JB_SetRef(JB_str_33, JB_Str3("Bad data found.", 15));
		JB_SetRef(JB_str_32, JB_Str3("Unknown class.", 14));
		JB_SetRef(JB_str_31, JB_Str3("µs", 3));
		JB_SetRef(JB_str_30, JB_Str3("          ", 10));
		JB_SetRef(JB_str_29, JB_Str3(".", 1));
		JB_SetRef(JB_str_28, JB_Str3(". New Count ", 12));
		JB_SetRef(JB_str_27, JB_Str3(" bytes in ", 10));
		JB_SetRef(JB_str_26, JB_Str3("Leaked ", 7));
		JB_SetRef(JB_str_25, JB_Str3(", trying to ", 12));
		JB_SetRef(JB_str_24, JB_Str3("'", 1));
		JB_SetRef(JB_str_23, JB_Str3("Can’t find '", 14));
		JB_SetRef(JB_str_22, JB_Str3("/", 1));
		JB_SetRef(JB_str_21, JB_Str3("~/Documents/", 12));
		JB_SetRef(JB_str_20, JB_Str3("OK Critical Error Deprecated Warning Hint", 41));
		JB_SetRef(JB_str_19, JB_Str3(": ", 2));
		JB_SetRef(JB_str_18, JB_Str3("line ", 5));
		JB_SetRef(JB_str_17, JB_Str3("\t", 1));
		JB_SetRef(JB_str_16, JB_Str3("s found.\n", 9));
		JB_SetRef(JB_str_15, JB_Str3(" ", 1));
		JB_SetRef(JB_str_0, JB_Str3("", 0));
		JB_SetRef(JB_str_13, JB_Str3("\n", 1));
		JB_SetRef(JB_str_12, JB_Str3("error", 5));
		JB_SetRef(JB_str_11, JB_Str3("warning", 7));
		JB_SetRef(JB_str_10, JB_Str3("false", 5));
		JB_SetRef(JB_str_9, JB_Str3("true", 4));
		JB_SetRef(JB_str_8, JB_Str3("/Users/theodore/Speedie/jbc.scproj/Build/JB.cpp", 47));
		JB_SetRef(JB_str_7, JB_Str3("jb_decomp.txt", 13));
		JB_SetRef(JB_str_6, JB_Str3("/Users/theodore/Speedie/jbc.scproj/Build/JB.cpp.unlz4", 53));
		JB_SetRef(JB_str_5, JB_Str3("lz4_decomp.txt", 14));
		JB_SetRef(JB_str_4, JB_Str3("/Users/theodore/Speedie/jbc.scproj/Build/JB.cpp.lz4", 51));
		JB_SetRef(JB_str_3, JB_Str3("abcd efgh ijkl mnop", 19));
		JB_SetRef(JB_str_2, JB_Str3("Compression Test: OK", 20));
		JB_SetRef(JB_str_1, JB_Str3("abcdabcdabcdabcd", 16));
		JB_SetRef(JB__SyxDict_, JB_Dict__New());
		JB_SyxArg = JB_Syx__StdNew(JB_Msg_Arg__, JB_str_259, JB_str_260);
		JB_SyxAcc = JB_Syx__StdNew(JB_Msg_Acc__, JB_str_261, JB_str_262);
		JB_SyxAdj = JB_Syx__StdNew(JB_Msg_Adj__, JB_str_263, JB_str_264);
		JB_SyxARel = JB_Syx__StdNew(JB_Msg_ARel__, JB_str_265, JB_str_266);
		JB_SyxArr = JB_Syx__StdNew(JB_Msg_Arr__, JB_str_267, JB_str_268);
		JB_SyxBack = JB_Syx__StdNew(JB_Msg_Back__, JB_str_269, JB_str_270);
		JB_SyxSStr = JB_Syx__StdNew(JB_Msg_SStr__, JB_str_271, JB_str_272);
		JB_SyxBra = JB_Syx__StdNew(JB_Msg_Bra__, JB_str_273, JB_str_274);
		JB_SyxBRel = JB_Syx__StdNew(JB_Msg_BRel__, JB_str_275, JB_str_276);
		JB_SyxChar = JB_Syx__StdNew(JB_Msg_Char__, JB_str_191, JB_str_277);
		JB_SyxDecl = JB_Syx__StdNew(JB_Msg_Decl__, JB_str_278, JB_str_279);
		JB_SyxDot = JB_Syx__StdNew(JB_Msg_Dot__, JB_str_280, JB_str_281);
		JB_SyxEmb = JB_Syx__StdNew(JB_Msg_Emb__, JB_str_282, JB_str_283);
		JB_SyxERel = JB_Syx__StdNew(JB_Msg_ERel__, JB_str_284, JB_str_285);
		JB_SyxFunc = JB_Syx__StdNew(JB_Msg_Func__, JB_str_286, JB_str_287);
		JB_SyxItem = JB_Syx__StdNew(JB_Msg_Item__, JB_str_288, JB_str_0);
		JB_SyxList = JB_Syx__StdNew(JB_Msg_List__, JB_str_179, JB_str_0);
		JB_SyxName = JB_Syx__StdNew(JB_Msg_Name__, JB_str_289, JB_str_0);
		JB_SyxNum = JB_Syx__StdNew(JB_Msg_Num__, JB_str_290, JB_str_291);
		JB_SyxUnit = JB_Syx__StdNew(JB_Msg_Unit__, JB_str_292, JB_str_0);
		JB_SyxOat = JB_Syx__StdNew(JB_Msg_Oat__, JB_str_293, JB_str_294);
		JB_SyxOpp = JB_Syx__StdNew(JB_Msg_Opp__, JB_str_295, JB_str_296);
		JB_SyxSOpp = JB_Syx__StdNew(JB_Msg_SOpp__, JB_str_297, JB_str_298);
		JB_SyxRel = JB_Syx__StdNew(JB_Msg_Rel__, JB_str_299, JB_str_300);
		JB_SyxTRel = JB_Syx__StdNew(JB_Msg_TRel__, JB_str_301, JB_str_302);
		JB_SyxSDot = JB_Syx__StdNew(JB_Msg_SDot__, JB_str_303, JB_str_304);
		JB_SyxSCom = JB_Syx__StdNew(JB_Msg_SCom__, JB_str_305, JB_str_306);
		JB_SyxSheb = JB_Syx__StdNew(JB_Msg_Sheb__, JB_str_307, JB_str_308);
		JB_SyxStr = JB_Syx__StdNew(JB_Msg_Str__, JB_str_309, JB_str_310);
		JB_SyxSThg = JB_Syx__StdNew(JB_Msg_SThg__, JB_str_311, JB_str_312);
		JB_SyxThg = JB_Syx__StdNew(JB_Msg_Thg__, JB_str_313, JB_str_314);
		JB_SyxTmp = JB_Syx__StdNew(JB_Msg_Tmp__, JB_str_315, JB_str_316);
		JB_SyxAna = JB_Syx__StdNew(JB_Msg_Ana__, JB_str_317, JB_str_318);
		JB_SyxSCnj = JB_Syx__StdNew(JB_Msg_SCnj__, JB_str_319, JB_str_320);
		JB_SyxCnj = JB_Syx__StdNew(JB_Msg_Cnj__, JB_str_321, JB_str_322);
		JB_SyxType = JB_Syx__StdNew(JB_Msg_Type__, JB_str_323, JB_str_324);
		JB_SyxYoda = JB_Syx__StdNew(JB_Msg_Yoda__, JB_str_325, JB_str_326);
		JB_SyxYopp = JB_Syx__StdNew(JB_Msg_Yopp__, JB_str_327, JB_str_0);
		JB_SyxAsk = JB_Syx__StdNew(JB_Msg_Ask__, JB_str_328, JB_str_329);
		JB_SyxMsg = JB_Syx__StdNew(JB_Msg_Msg__, JB_str_330, JB_str_331);
		JB_SyxBnch = JB_Syx__StdNew(JB_Msg_Bnch__, JB_str_332, JB_str_333);
		JB_SyxTodo = JB_Syx__StdNew(JB_Msg_Todo__, JB_str_334, JB_str_335);
		JB_SyxBin = JB_Syx__StdNew(JB_Msg_Bin__, JB_str_336, JB_str_337);
	};
	//// ErrorColors;
	JB_ErrorColors__Init_();
	//// JB_API;
	JB_API__Init_();
	//// Jeebox;
	JB_Constants__Init_();
	//// parser;
	JB_Tk__Init_();
	//// Random;
	JB_Random__Init_();
	//// ErrorSeverity;
	JB_ErrorSeverity__Init_();
	//// Syntax;
	JB_Syx__Init_();
	//// FastAppender;
	JB_FAP__Init_();
	//// ErrorReceiver;
	JB_Rec__Init_();
	return 0;
}

void JB_Obj_PrintLine(JB_Object* o) {
	JB_String* _tmP = JB_Incr(JB_ObjRender(o, nil));
	JB_Str_PrintLine(_tmP);
	JB_Decr(_tmP);
}

Dictionary* JB_Dict_Reverse(Dictionary* Dict) {
	Dictionary* result = JB_Incr(JB_Dict__New());
	{
		DictionaryReader* _nav = JB_Incr(JB_Dict_Navigate(Dict));
		while (JB_Nav_MoveNext(_nav)) {
			JB_String* key = JB_Incr(JB_Nav_Name(_nav));
			JB_String* value = JB_Incr(((JB_String*)JB_Nav_Value(_nav)));
			(JB_Dict_ValueSet(result, value, key));
			JB_Decr(value);
			JB_Decr(key);
		};
		JB_Decr(_nav);
	};
	JB_SafeDecr(result);
	return result;
}

bool JB_TestCasting() {
	Dictionary* d2 = JB_Incr(JB_Dict__New());
	DTWrap* _tmP = JB_Incr(JB_Wrap__NewWithInt64(((int)({
		DTWrap* _tmP308 = JB_Incr(((DTWrap*)JB_Dict_SyntaxAccessWithStr(d2, JB_str_89)));
		int64 _tmP307 = JB_Wrap_Value(_tmP308);
		JB_Decr(_tmP308);
		 _tmP307;
	})) + 1));
	(JB_Dict_ValueSet(d2, JB_str_89, _tmP));
	JB_Decr(_tmP);
	JB_Decr(d2);
	Dictionary* d = JB_Incr(JB_Dict__New());
	JB_String* str = JB_Incr(JB_str_90);
	if ((!((!JB_Str_ByteValue(str, 0)) and ((!JB_Str_ByteValue(str, 1)) and ((!JB_Str_ByteValue(str, 2)) and ((!JB_Str_ByteValue(str, 3)) and (JB_Str_Length(str) == 6))))))) {
		JB_Object_SyntaxExpect(nil);
		JB_Decr(d);
		JB_Decr(str);
		return nil;
	}
	(JB_Dict_ValueSet(d, str, str));
	JB_Decr(str);
	JB_Decr(d);
	if ('\0') {
		return nil;
	}
	JB_Class* x = JB_AsClass(Message);
	Message* y = JB_Incr(JB_Msg__NewParser(nil, JB_SyxBra, 0, JB_str_0));
	JB_SetRef(y->Name, JB_str_91);
	JB_Object* yy = nil;
	JB_SetRef(yy, y);
	Array* arr = JB_Incr(JB_Array__New(0));
	JB_Array_Append(arr, nil);
	JB_Decr(arr);
	if (JB_Object_FastIsa(yy, JB_AsClass(Message))) {
		if ((!(JB_Str_SyntaxEquals(((Message*)yy)->Name, JB_str_91, false)))) {
			debugger;
		}
	}
	JB_Decr(yy);
	bool _tmP1 = (JB_Object_Isa(y, x));
	JB_Decr(y);
	return _tmP1;
}





void JB_AstUtil_Destructor(AstUtil* self) {
	JB_Decr(self->Mem);
	JB_Decr(self->Initial);
}

AstResult JB_AstUtil_Get(AstUtil* self, Message* node) {
	if (JB_Msg_SyntaxEqualsWithSyxBool(node, JB_SyxTmp, false)) {
		return JB_AstUtil_GetTmp(self, node);
	}
	Message* func = ((Message*)JB_Ring_First(node));
	SyntaxObj* fn = JB_Msg__GetSyx(func);
	if ((!(((bool)fn) and JB_Msg_Expect(node, JB_SyxMsg, JB_str_0)))) {
		return ((AstResult){
		});
	}
	AstResult Result = ((AstResult){
	});
	Result.Func = fn->ID;
	Result.Children = ((Message*)JB_Ring_NextSib(func));
	Result.Name = JB_Msg_Nyme(((Message*)JB_Ring_First(func)));
	return Result;
}

AstResult JB_AstUtil_GetTmp(AstUtil* self, Message* node) {
	SyntaxObj* fn = JB_Msg__GetSyx(node);
	if ((!fn)) {
		return ((AstResult){
		});
	}
	AstResult Result = ((AstResult){
	});
	Result.Func = fn->ID;
	Message* NameOrArg = ((Message*)JB_Ring_First(node));
	if ((!(JB_Msg_SyntaxEqualsWithSyxBool(NameOrArg, JB_SyxArg, false)))) {
		Result.Children = ((Message*)JB_Tree_SyntaxAccessWithInt(((Message*)JB_Ring_NextSib(NameOrArg)), 0));
		Result.Name = JB_Msg_Nyme(NameOrArg);
	} else {
		Result.Children = ((Message*)JB_Ring_First(NameOrArg));
	}
	return Result;
}

void JB_AstUtil_UseLayer(AstUtil* self, Message* src) {
	if ((!(self->Initial))) {
		JB_SetRef(self->Initial, JB_ClassData_CurrLayer((JB_AsClass(Message))));
	}
	if ((!(self->Mem))) {
		JB_SetRef(self->Mem, JB_Dict__New());
	}
	JB_MemoryLayer* L = JB_Incr(({
		JB_String* _tmP288 = JB_Incr(JB_Str_LowerCase(src->Name));
		JB_MemoryLayer* _tmP287 = JB_Incr(((JB_MemoryLayer*)JB_Dict_SyntaxAccessWithStr(self->Mem, _tmP288)));
		JB_Decr(_tmP288);
		JB_SafeDecr(_tmP287);
		 _tmP287;
	}));
	if ((!L)) {
		JB_SetRef(L, JB_Mem_CreateLayer((JB_AsClass(Message)), src->Name));
		JB_String* _tmP = JB_Incr(JB_Str_LowerCase(src->Name));
		(JB_Dict_ValueSet(self->Mem, _tmP, L));
		JB_Decr(_tmP);
	}
	JB_Mem_Use(L);
	JB_Decr(L);
}



JB_MemoryLayer* JB_ClassData_CurrLayer(JB_Class* self) {
	return JB_Class_Layer(self);
}

void JB_ClassData_Restore(JB_Class* self) {
	JB_MemoryLayer* _tmP = JB_Incr(JB_Class_DefaultLayer(self));
	JB_Mem_Use(_tmP);
	JB_Decr(_tmP);
}


JB_String* JB_dbl_Render(double self, JB_String* fmt, FastString* fs_in) {
	FastString* fs = JB_Incr(JB_FS__FastNew(fs_in));
	JB_FS_AppendDoubleAsText(fs, self, ((byte*)JB_Str_Address(fmt)));
	JB_String* _tmP = JB_Incr(JB_FS_SmartResult(fs, fs_in));
	JB_Decr(fs);
	JB_SafeDecr(_tmP);
	return _tmP;
}



JB_String* JB_f_Render(float self, FastString* fs_in) {
	FastString* fs = JB_Incr(JB_FS__FastNew(fs_in));
	JB_FS_AppendFloatAsText(fs, self);
	JB_String* _tmP = JB_Incr(JB_FS_SmartResult(fs, fs_in));
	JB_Decr(fs);
	JB_SafeDecr(_tmP);
	return _tmP;
}






bool JB_int_OperatorIsMul(int self, int x) {
	return (!(((bool)(self % x))));
}

int JB_int_OperatorMin(int self, int other) {
	if (self < other) {
		return self;
	}
	return other;
}

JB_String* JB_int_RenderWithFs(int self, FastString* fs_in) {
	FastString* fs = JB_Incr(JB_FS__FastNew(fs_in));
	JB_FS_SyntaxAppendWithInt(fs, self);
	JB_String* _tmP = JB_Incr(JB_FS_SmartResult(fs, fs_in));
	JB_Decr(fs);
	JB_SafeDecr(_tmP);
	return _tmP;
}

JB_String* JB_int_RenderWithIntFs(int self, int zeros, FastString* fs_in) {
	FastString* fs = JB_Incr(JB_FS__FastNew(fs_in));
	JB_FS_AppendIntegerAsText(fs, self, zeros);
	JB_String* _tmP = JB_Incr(JB_FS_SmartResult(fs, fs_in));
	JB_Decr(fs);
	JB_SafeDecr(_tmP);
	return _tmP;
}



JB_String* JB_int64_Render(int64 self, FastString* fs_in) {
	FastString* fs = JB_Incr(JB_FS__FastNew(fs_in));
	JB_FS_SyntaxAppendWithInt64(fs, self);
	JB_String* _tmP = JB_Incr(JB_FS_SmartResult(fs, fs_in));
	JB_Decr(fs);
	JB_SafeDecr(_tmP);
	return _tmP;
}




JB_String* JB_iPoint2_Render(iPoint2* self, FastString* fs_in) {
	FastString* fs = JB_Incr(JB_FS__FastNew(fs_in));
	JB_FS_AppendByte(fs, '(');
	JB_FS_SyntaxAppendWithInt(fs, self->X);
	JB_FS_AppendByte(fs, ',');
	JB_FS_AppendByte(fs, ' ');
	JB_FS_SyntaxAppendWithInt(fs, self->Y);
	JB_FS_AppendByte(fs, ')');
	JB_String* _tmP = JB_Incr(JB_FS_SmartResult(fs, fs_in));
	JB_Decr(fs);
	JB_SafeDecr(_tmP);
	return _tmP;
}


void JB_LLRef_Clear(LLRef* self) {
	JB_LinkedList_ClearAll(self->First);
}

void JB_LLRef_Destructor(LLRef* self) {
	JB_LLRef_Clear(self);
}

bool JB_LLRef_HeaderSanity(LLRef* self) {
	if (JB_IsDebug()) {
		JB_LinkedList* F = self->First;
		if (F) {
			if ((!(F->_BackRef == (&self->First)))) {
				debugger;
				return nil;
			}
		}
	}
	return true;
}

int JB_LLRef_ListCount(LLRef* self) {
	int Result = 0;
	{
		JB_LinkedList* _LoopSrc2 = self->First;
		JB_LinkedList* A = _LoopSrc2;
		while (A) {
			JB_LinkedList_ListSanity(A);
			JB_LinkedList* _N1 = A->_Next;
			Result++;
			A = _N1;
		};
	};
	return Result;
}

void JB_LLRef_SyntaxAppend(LLRef* self, JB_LinkedList* L) {
	JB_LLRef_HeaderSanity(self);
	JB_LinkedList_StoreAt(L, ((JB_LinkedList**)((&self->First))));
	JB_LLRef_HeaderSanity(self);
}




void JB_ObjectLoader_Destructor(ObjectLoader* self) {
	JB_Decr(self->Result);
}

bool JB_ObjectLoader_HasItem(ObjectLoader* self) {
	return ((bool)self->CurrItem);
}

int64 JB_ObjectLoader_Int(ObjectLoader* self) {
	Message* C = JB_ObjectLoader_Next(self);
	if ((!C)) {
		return nil;
	}
	return JB_Str_TextIntegerValid(C->Name, C);
}

int64 JB_ObjectLoader_ItemInt(ObjectLoader* self) {
	Message* c = self->CurrItem;
	if ((!c)) {
		return nil;
	}
	self->CurrItem = ((Message*)JB_Ring_NextSib(c));
	return JB_Msg_Int(((Message*)JB_Ring_Last(c)));
}

bool JB_ObjectLoader_ItemIsInt(ObjectLoader* self) {
	Message* C = self->CurrItem;
	return ((JB_Msg_SyntaxEqualsWithSyxBool(((Message*)JB_Ring_Last(C)), JB_SyxNum, false)));
}

JB_String* JB_ObjectLoader_ItemName(ObjectLoader* self) {
	Message* c = self->CurrItem;
	return JB_Str_Unshare(JB_Msg_Nyme(((Message*)JB_Ring_First(c))));
}

JB_Object* JB_ObjectLoader_ItemObject(ObjectLoader* self) {
	Message* c = self->CurrItem;
	if ((!c)) {
		return nil;
	}
	self->CurrItem = ((Message*)JB_Ring_NextSib(c));
	return JB_ObjectLoader_ObjectSub(self, ((Message*)JB_Ring_Last(c)));
}

void JB_ObjectLoader_LinkedListWithLinkedlist(ObjectLoader* self, JB_LinkedList** Place) {
	JB_LinkedList* o = ((JB_LinkedList*)JB_ObjectLoader_Object(self));
	if ((!o)) {
		return;
	}
	if ((!(!Place[0]))) {
		debugger;
	}
	if (o) {
		JB_Incr(o);
		Place[0] = o;
		o->_BackRef = Place;
	}
}

Message* JB_ObjectLoader_Next(ObjectLoader* self) {
	Message* C = self->CurrItem;
	if (C) {
		self->CurrItem = ((Message*)JB_Ring_NextSib(C));
		return C;
	}
	return nil;
}

JB_Object* JB_ObjectLoader_Object(ObjectLoader* self) {
	return JB_ObjectLoader_ObjectSub(self, JB_ObjectLoader_Next(self));
}

JB_Object* JB_ObjectLoader_ObjectSub(ObjectLoader* self, Message* c) {
	if (JB_Msg_SyntaxEqualsWithSyxBool(c, JB_SyxThg, false)) {
		return JB_Dict_SyntaxAccessWithStr(self->Dict, c->Name);
	} else if (JB_Msg_SyntaxEqualsWithSyxBool(c, JB_SyxStr, false)) {
		return JB_Str_Unshare(c->Name);
	}
	return nil;
}

JB_String* JB_ObjectLoader_String(ObjectLoader* self) {
	Message* C = JB_ObjectLoader_Next(self);
	if ((!C)) {
		return nil;
	}
	return JB_Str_Unshare(C->Name);
}


void JB_Saver_AppendInt(ObjectSaver* self, int64 i) {
	JB_FS_SyntaxAppendWithInt64(self->Dest, i);
	JB_FS_AppendByte(self->Dest, ',');
}

void JB_Saver_AppendObject(ObjectSaver* self, JB_Object* o) {
	JB_FS_AppendObjectOrNil(self->Dest, o);
	JB_FS_AppendByte(self->Dest, ',');
}

void JB_Saver_AppendString(ObjectSaver* self, JB_String* s) {
	if (JB_Str_Exists(s) and JB_int_Found(JB_Str_FindWithByteIntInt(s, '`', 0, kJB__int_max))) {
		JB_Str_AppendAsBinary(s, self->Dest);
	} else {
		JB_FS_AppendByte(self->Dest, '`');
		JB_FS_AppendString(self->Dest, s);
		JB_FS_AppendByte(self->Dest, '`');
	}
	JB_FS_AppendByte(self->Dest, ',');
}

void JB_Saver_Destructor(ObjectSaver* self) {
	if (self->CantSaveThis) {
		JB_Object_Fail(self->CantSaveThis, JB_str_44);
	}
	JB_Decr(self->Dest);
}

int JB_Saver__Init_() {
	{
	};
	return 0;
}


JB_String* JB_Point2_Render(Point2* self, FastString* fs_in) {
	FastString* fs = JB_Incr(JB_FS__FastNew(fs_in));
	JB_FS_AppendByte(fs, '(');
	JB_FS_AppendFloatAsText(fs, self->X);
	JB_FS_AppendByte(fs, ',');
	JB_FS_AppendByte(fs, ' ');
	JB_FS_AppendFloatAsText(fs, self->Y);
	JB_FS_AppendByte(fs, ')');
	JB_String* _tmP = JB_Incr(JB_FS_SmartResult(fs, fs_in));
	JB_Decr(fs);
	JB_SafeDecr(_tmP);
	return _tmP;
}


void JB_Random_LoadProperties(Random* self, ObjectLoader* Loader) {
	self->Fast = ((uint64)JB_ObjectLoader_Int(Loader));
	self->Adder = ((uint64)JB_ObjectLoader_Int(Loader));
}

void JB_Random_SaveWrite(Random* self, ObjectSaver* Saver) {
	JB_Saver_AppendInt(Saver, self->Fast);
	JB_Saver_AppendInt(Saver, self->Adder);
}

int JB_Random__Init_() {
	{
		JB__Random_Shared = ((Random){
		});
		JB__Random_Shared.Fast = 1;
		JB__Random_Shared.Adder = 1;
	};
	return 0;
}




void JB_StructSaveTest_Destructor(StructSaveTest* self) {
	JB_Decr(self->Sav);
	JB_Decr(self->Str);
}

void JB_StructSaveTest_LoadProperties(StructSaveTest* self, ObjectLoader* Loader) {
	JB_SetRef(self->Sav, ((Saveable*)JB_ObjectLoader_Object(Loader)));
	self->Intt = JB_ObjectLoader_Int(Loader);
	JB_SetRef(self->Str, ((JB_String*)JB_ObjectLoader_String(Loader)));
}

void JB_StructSaveTest_SaveWrite(StructSaveTest* self, ObjectSaver* Saver) {
	JB_Saver_AppendObject(Saver, self->Sav);
	JB_Saver_AppendInt(Saver, self->Intt);
	JB_Saver_AppendString(Saver, self->Str);
}















bool JB_byte_CanPrintAsNormalChar(byte self) {
	return ((self <= 127) and (self >= 32));
}

bool JB_byte_In(byte self, int a, int b) {
	return (self >= a) and (self <= b);
}

bool JB_byte_IsLetter(byte self) {
	return JB_byte_In(self, 'a', 'z') or JB_byte_In(self, 'A', 'Z');
}

bool JB_byte_IsNum(byte self) {
	return (self >= '0') and (self <= '9');
}

bool JB_byte_IsNumeric(byte self) {
	return JB_byte_In(self, '0', '9');
}

JB_String* JB_byte_Render(byte self, FastString* fs_in) {
	if ((!fs_in)) {
		return JB_Str__SyntaxAccess(self);
	}
	JB_FS_AppendByte(fs_in, self);
	return nil;
}

byte JB_byte_UpperCase(byte self) {
	if (JB_byte_In(self, 'a', 'z')) {
		return self - 32;
	}
	return self;
}


bool JB_DataTypeCode_IsFloat(DataTypeCode self) {
	return (((bool)(self >> 7)));
}


JB_String* JB_Date_Render(Date self, FastString* fs_in) {
	FastString* fs = JB_Incr(JB_FS__FastNew(fs_in));
	JB_FS_AppendDate(fs, self);
	JB_String* _tmP = JB_Incr(JB_FS_SmartResult(fs, fs_in));
	JB_Decr(fs);
	JB_SafeDecr(_tmP);
	return _tmP;
}


JB_String* JB_ErrorSeverity_Render(ErrorSeverity self, FastString* fs_in) {
	if (self < kJB__ErrorSeverity_MaxError) {
		if ((!(JB_Array_SyntaxCast(JB__ErrorSeverity_names)))) {
			JB_SetRef(JB__ErrorSeverity_names, JB_Str_Words(JB_str_20));
		}
		if (fs_in) {
			JB_String* _tmP = JB_Incr(((JB_String*)JB_Array_Value(JB__ErrorSeverity_names, self)));
			JB_FS_AppendString(fs_in, _tmP);
			JB_Decr(_tmP);
		}
		else {
			return ((JB_String*)JB_Array_Value(JB__ErrorSeverity_names, self));
		};
	}
	return JB_str_0;
}

int JB_ErrorSeverity__Init_() {
	{
		JB_SetRef(JB__ErrorSeverity_names, ((Array*)JB_Array__New0()));
	};
	return 0;
}


int JB_Syx_Lineflags(Syntax self) {
	if (self == JB_SyxArg) {
		return kJB__Tk_EndOfLine;
	} else {
		return kJB__Tk_EndOfLine | kJB__Tk_Comma;
	}
	return 0;
}

JB_String* JB_Syx_LongName(Syntax self) {
	return JB_Syx_Obj(self)->LongName;
}

Message* JB_Syx_MsgWithStr(Syntax self, JB_String* name) {
	return JB_Msg__NewParser(nil, self, JB__Tk_UsingPos, name);
}

Message* JB_Syx_Msg(Syntax self, Message* parent, JB_String* name) {
	return JB_Msg__NewParser(parent, self, JB__Tk_UsingPos, name);
}

JB_String* JB_Syx_Name(Syntax self) {
	return JB_Syx_Obj(self)->Name;
}

SyntaxObj* JB_Syx_Obj(Syntax self) {
	return JB__FuncArray_[((int)self)];
}

int JB_Syx_Parseflags(Syntax self) {
	if (self == JB_SyxArg) {
		return kJB__Tk_Temporal;
	} else {
		return kJB__Tk_TemporalSyx;
	}
	return 0;
}

JB_String* JB_Syx_Render(Syntax self, FastString* fs_in) {
	FastString* fs = JB_Incr(JB_FS__FastNew(fs_in));
	if (self) {
		JB_FreeIfDead(({
			SyntaxObj* _tmP291 = JB_Incr(JB_Syx_Obj(self));
			JB_String* _tmP290 = JB_Incr(JB_Fn_Render(_tmP291, fs));
			JB_Decr(_tmP291);
			JB_SafeDecr(_tmP290);
			 _tmP290;
		}));
	}
	JB_String* _tmP = JB_Incr(JB_FS_SmartResult(fs, fs_in));
	JB_Decr(fs);
	JB_SafeDecr(_tmP);
	return _tmP;
}

fpMsgRender JB_Syx_RenderAddr(Syntax self) {
	return JB_Syx_Obj(self)->RenderAddr;
}

int JB_Syx__Init_() {
	{
		JB__Syx_CurrFuncID = 0;
	};
	return 0;
}

Syntax JB_Syx__StdNew(fpMsgRender msg, JB_String* name, JB_String* LongName) {
	SyntaxObj* result = JB_Incr(JB_Fn__New(msg, name, (++JB__Syx_CurrFuncID)));
	(JB_Dict_ValueSet(JB__SyxDict_, name, result));
	JB_SetRef(JB__FuncArray_[JB__Syx_CurrFuncID], result);
	if (JB_Str_Exists(LongName)) {
		(JB_Dict_ValueSet(JB__SyxDict_, LongName, result));
		JB_SetRef(result->LongName, LongName);
	} else {
		JB_SetRef(result->LongName, name);
	}
	JB_Decr(result);
	return ((Syntax)JB__Syx_CurrFuncID);
}





















void jdb(JB_Object* self) {
	JB_String* _tmP = JB_Incr(JB_ObjRender(self, nil));
	JB_Str_PrintLine(_tmP);
	JB_Decr(_tmP);
}

bool JB_Object_FastIsa(JB_Object* self, JB_Class* x) {
	return ((bool)self) and (JB_ObjClass(self) == x);
}

bool JB_Object_Isa(JB_Object* self, JB_Class* x) {
	if (self) {
		JB_Class* P = JB_ObjClass(self);
		if (x == P) {
			return true;
		}
		if ((!x->HasSubclasses)) {
			return false;
		}
		P = P->Parent;
		while (P) {
			if (P == x) {
				return true;
			}
			P = P->Parent;
		};
	}
	return false;
}

void JB_Object_SaveTryCollect(JB_Object* self, ObjectSaver* Saver) {
	if (JB_Object_Isa(self, JB_AsClass(Saveable))) {
		if ((!JB_Sav_SaveMark(((Saveable*)self)))) {
			return;
		}
		JB_FAP_SyntaxAppend(JB_Sav_SaverInfo(((Saveable*)self)), ((Saveable*)self));
		JB_Sav___SaveCollect__(((Saveable*)self), Saver);
	} else if ((bool)self) {
		if ((!(JB_Object_Isa(self, JB_AsClass(JB_String))))) {
			Saver->CantSaveThis = self;
		}
	}
}

void JB_Object_Fail(JB_Object* self, JB_String* Error) {
	if (JB_Object_FastIsa(self, JB_AsClass(Message))) {
		JB_Rec_NewItemWithNode(JB_StdErr, ((Message*)self), Error);
	} else {
		JB_Rec_NewItemWithNode(JB_StdErr, nil, Error);
	}
}

void JB_Object_SyntaxExpect(JB_Object* self) {
	JB_Rec_NewItemWithNode(JB_StdErr, nil, JB_str_94);
}


Allocation_Behaviour InitTableMWrap_() { // Behaviour 
	Allocation_Behaviour Result;
	Result.__destructor__ = (void*)JB_Mrap_Destructor;
	Result.render = (__Object_Render__)JB_ObjRender;
	return Result;
}

Allocation_Behaviour MWrap_FuncTable_ = InitTableMWrap_();
JBClassPlace4(MWrap, JB_AsClass(JB_Object), MWrap_FuncTable_);

void JB_Mrap_Clear(MWrap* self) {
	JB_free(JB_Mrap_Ptr(self));
	self->_Ptr = nil;
	self->_ItemCount = 0;
}

void JB_Mrap_Constructor(MWrap* self, int ItemCount, uint ItemSize, bool DummyParam) {
	self->DataType = 0;
	int Request = ItemCount * ItemSize;
	self->_ItemSize = ItemSize;
	self->_Length = ItemCount;
	self->_Ptr = JB_Mrap__Zalloc(Request);
	self->_ItemCount = ItemCount;
	if ((!self->_Ptr)) {
		self->_ItemCount = 0;
	}
}

void JB_Mrap_Destructor(MWrap* self) {
	JB_Mrap_Clear(self);
}

int* JB_Mrap_Ptr(MWrap* self) {
	return ((int*)self->_Ptr);
}

MWrap* JB_Mrap__Alloc() {
	return ((MWrap*)JB_New(MWrap));
}

int JB_Mrap__Init_() {
	{
	};
	return 0;
}

MWrap* JB_Mrap__New(int ItemCount, uint ItemSize, bool DummyParam) {
	MWrap* Result = JB_Mrap__Alloc();
	if (Result) {
		JB_Mrap_Constructor(Result, ItemCount, ItemSize, DummyParam);
	}
	return Result;
}

MWrap* JB_Mrap__Object(int ItemCount, int ItemSize) {
	MWrap* Result = JB_Incr(JB_Mrap__New(ItemCount, ItemSize, false));
	if (Result->_Ptr) {
		JB_SafeDecr(Result);
		return Result;
	}
	JB_Decr(Result);
	return nil;
}

byte* JB_Mrap__Zalloc(int n) {
	return ((byte*)JB_malloc(n));
}


Array* JB_BM_Bytes(ByteMap* self) {
	Array* result = JB_Incr(JB_Array__New0());
	{
		int _i = 0;
		while (_i < 256) {
			if ((!JB_BM_HasChar(self, _i))) {
				_i++;
				continue;
			}
			byte b = ((byte)_i);
			JB_String* _tmP2 = JB_Incr(JB_byte_Render(b, nil));
			JB_Array_Append(result, _tmP2);
			JB_Decr(_tmP2);
			_i++;
		};
	};
	JB_SafeDecr(result);
	return result;
}

ByteMap* JB_BM__Alloc() {
	return ((ByteMap*)JB_New(ByteMap));
}

ByteMap* JB_BM__NewCharset(JB_String* charset, bool Ranges) {
	ByteMap* Result = JB_BM__Alloc();
	if (Result) {
		JB_BM_ConstructorCharset(Result, charset, Ranges);
	}
	return Result;
}


DataTypeWrapper_Behaviour InitTableDTWrap_() { // Behaviour 
	DataTypeWrapper_Behaviour Result;
	Result.__destructor__ = nil;
	Result.render = (__Object_Render__)JB_Wrap_Render;
	return Result;
}

DataTypeWrapper_Behaviour DTWrap_FuncTable_ = InitTableDTWrap_();
JBClassPlace4(DTWrap, JB_AsClass(JB_Object), DTWrap_FuncTable_);

void JB_Wrap_ConstructorWithInt64(DTWrap* self, int64 v) {
	self->DataType = kJB__DataTypeCode_s64;
	self->_PrivValue = v;
}

double JB_Wrap_FloatValue(DTWrap* self) {
	if (self) {
		return self->_PrivValue;
	}
	return 0;
}

JB_String* JB_Wrap_Render(DTWrap* self, FastString* fs_in) {
	FastString* fs = JB_Incr(JB_FS__FastNew(fs_in));
	if (JB_DataTypeCode_IsFloat(self->DataType)) {
		JB_FS_AppendDoubleAsText0(fs, JB_Wrap_FloatValue(self));
	} else if (self->DataType == kJB__DataTypeCode_UnusedType) {
		JB_FS_AppendString(fs, JB_str_35);
		JB_FS_AppendHex(fs, self->_PrivValue, 2);
	} else {
		JB_FS_SyntaxAppendWithInt64(fs, self->_PrivValue);
	}
	JB_String* _tmP = JB_Incr(JB_FS_SmartResult(fs, fs_in));
	JB_Decr(fs);
	JB_SafeDecr(_tmP);
	return _tmP;
}

int64 JB_Wrap_Value(DTWrap* self) {
	if (self) {
		return self->_PrivValue;
	}
	return 0;
}

DTWrap* JB_Wrap__Alloc() {
	return ((DTWrap*)JB_New(DTWrap));
}

DTWrap* JB_Wrap__NewWithInt64(int64 v) {
	DTWrap* Result = JB_Wrap__Alloc();
	if (Result) {
		JB_Wrap_ConstructorWithInt64(Result, v);
	}
	return Result;
}



void JB_FS_AppendEscape(FastString* self, JB_String* s) {
	JB_FS_AppendMultiReplace(self, s, JB__Constants_EscapeStr, JB_StdErr);
}

void JB_FS_AppendFastString(FastString* self, FastString* data) {
	JB_FS_AppendString(self, ((JB_String*)data));
}

void JB_FS_AppendHexDataWithStr(FastString* self, JB_String* Data) {
	if ((!JB_Str_Exists(Data))) {
		return;
	}
	JB_FS_AppendHexData(self, Data->Addr, JB_Str_Length(Data));
}

void JB_FS_AppendObjectID(FastString* self, Saveable* o) {
	JB_FS_AppendHex3(self, JB_ObjID(o));
}

void JB_FS_AppendObjectOrNil(FastString* self, JB_Object* o) {
	if (JB_Object_Isa(o, JB_AsClass(Saveable))) {
		if (JB_Sav_IsSaveMarked(((Saveable*)o))) {
			JB_FS_AppendObjectID(self, ((Saveable*)o));
		} else {
			//"Valid behaviour! For example we save a level, but we don't save the player along with the level. Like terraria.";
			JB_FS_AppendString(self, JB_str_99);
		}
	} else if (JB_Object_Isa(o, JB_AsClass(JB_String))) {
		JB_FreeIfDead(JB_ObjRender(((JB_String*)o), self));
	} else {
		JB_FS_AppendString(self, JB_str_99);
	}
}

void JB_FS_MsgErrorName(FastString* self, JB_String* name) {
	if (JB_Str_Exists(name)) {
		JB_FS_AppendString(self, JB_str_104);
		JB_FS_AppendString(self, name);
		JB_FS_AppendString(self, JB_str_105);
	}
}

JB_String* JB_FS_Render(FastString* self, FastString* fs_in) {
	FastString* fs = JB_FS__FastNew(fs_in);
	JB_FS_AppendFastString(fs, self);
	return JB_FS_SmartResult(fs, fs_in);
}

void JB_FS_SyntaxAppendWithInt64(FastString* self, int64 data) {
	JB_FS_AppendIntegerAsText(self, data, 1);
}

void JB_FS_SyntaxAppendWithInt(FastString* self, int data) {
	JB_FS_SyntaxAppendWithInt64(self, ((int64)data));
}

void JB_FS_AppendFloatAsText(FastString* self, float F) {
	JB_FS_AppendDoubleAsText0(self, ((double)F));
}

void JB_FS_SyntaxAppendWithMsg(FastString* self, Message* msg) {
	if (msg) {
		(JB_Syx_RenderAddr(msg->Func))(msg, self);
	}
}

FastString* JB_FS__Alloc() {
	return ((FastString*)JB_New(FastString));
}

int JB_FS__Init_() {
	{
	};
	return 0;
}

FastString* JB_FS__New() {
	FastString* Result = JB_FS__Alloc();
	if (Result) {
		JB_FS_Constructor(Result);
	}
	return Result;
}



LeakTester_Behaviour InitTableLeakTester_() { // Behaviour 
	LeakTester_Behaviour Result;
	Result.__destructor__ = (void*)JB_Lk_Destructor;
	Result.render = (__Object_Render__)JB_ObjRender;
	return Result;
}

LeakTester_Behaviour LeakTester_FuncTable_ = InitTableLeakTester_();
JBClassPlace4(LeakTester, JB_AsClass(JB_Object), LeakTester_FuncTable_);

void JB_Lk_Constructor(LeakTester* self, JB_String* name) {
	self->MemUsedStart = JB_MemCount();
	self->Name = JB_Incr(name);
	JB_Mem_Mark();
}

void JB_Lk_Destructor(LeakTester* self) {
	JB_Decr(self->Name);
}

void JB_Lk_FinalTest(LeakTester* self) {
	JB_Lk_Test(self);
	self->MemUsedStart = nil;
	JB_Mem_Unmark();
}

void JB_Lk_Test(LeakTester* self) {
	if ((!self->MemUsedStart)) {
		return;
	}
	int NewAmount = JB_MemCount();
	int Diff = NewAmount - self->MemUsedStart;
	if (Diff > 0) {
		debugger;
		FastString* _fs_fs = JB_Incr(JB_FS__New());
		JB_FS_AppendString(_fs_fs, JB_str_26);
		JB_FS_SyntaxAppendWithInt(_fs_fs, Diff);
		JB_FS_AppendString(_fs_fs, JB_str_27);
		JB_FS_AppendString(_fs_fs, self->Name);
		JB_FS_AppendString(_fs_fs, JB_str_28);
		JB_FS_SyntaxAppendWithInt(_fs_fs, NewAmount);
		JB_FS_AppendString(_fs_fs, JB_str_29);
		JB_String* _fs_str = JB_Incr(JB_FS_SyntaxCast(_fs_fs));
		JB_SetRef(_fs_fs, nil);
		JB_Decr(_fs_fs);
		JB_Str_PrintLine(_fs_str);
		JB_Decr(_fs_str);
	}
}

LeakTester* JB_Lk__Alloc() {
	return ((LeakTester*)JB_New(LeakTester));
}

LeakTester* JB_Lk__New(JB_String* name) {
	LeakTester* Result = JB_Lk__Alloc();
	if (Result) {
		JB_Lk_Constructor(Result, name);
	}
	return Result;
}




bool JB_Sav_IsSaveMarked(Saveable* self) {
	int* p = ((int*)self);
	return (((bool)(p[0] & 0x10000000)));
}

void JB_Sav_LoadProperties(Saveable* self, ObjectLoader* Loader) {
	Loader->CouldntLoad = self;
}

void JB_Sav_SaveCollect(Saveable* self, ObjectSaver* Saver) {
}

bool JB_Sav_SaveMark(Saveable* self) {
	int* p = ((int*)self);
	int rc = p[0];
	if (((bool)(rc & 0x10000000))) {
		return nil;
	}
	p[0] = (rc | 0x10000000);
	return true;
}

SaverClassInfo* JB_Sav_SaverInfo(Saveable* self) {
	return ((SaverClassInfo*)JB_ObjClass(self)->SaveInfo);
}

void JB_Sav_SaveWrite(Saveable* self, ObjectSaver* Saver) {
	Saver->CantSaveThis = self;
	JB_FS_AppendString(Saver->Dest, JB_str_45);
}



void JB_Str_AppendAsBinary(JB_String* self, FastString* fs) {
	JB_FS_AppendString(fs, JB_str_100);
	JB_FreeIfDead(JB_Str_EncodeB64(self, fs));
	JB_FS_AppendString(fs, JB_str_101);
}

Array* JB_Str_ByteSplit(JB_String* self) {
	Array* result = JB_Incr(JB_Array__New0());
	{
		int _LoopSrc1 = JB_Str_Length(self);
		int n = 0;
		while (n < _LoopSrc1) {
			JB_String* _tmP2 = JB_Incr(JB_Str__SyntaxAccess(JB_Str_ByteValue(self, n)));
			JB_Array_Append(result, _tmP2);
			JB_Decr(_tmP2);
			n++;
		};
	};
	JB_SafeDecr(result);
	return result;
}

ByteMap* JB_Str_Charset(JB_String* self, bool Range) {
	return JB_BM__NewCharset(self, Range);
}

int JB_Str_Count(JB_String* self, byte b) {
	int Result = 0;
	{
		int _n = JB_Str_Length(self);
		int _i1 = 0;
		while (_i1 < _n) {
			byte c = JB_Str_ByteValue(self, _i1);
			if (c == b) {
				Result++;
			}
			_i1++;
		};
	};
	return Result;
}

JB_String* JB_Str_Escape(JB_String* self) {
	return JB_Str_MultiReplaceAll(self, JB__Constants_EscapeStr, JB_StdErr);
}

JB_String* JB_Str_EscapeChr(JB_String* self) {
	return JB_Str_MultiReplaceAll(self, JB__Constants_EscapeChr, JB_StdErr);
}

int JB_Str_FindWithByteIntInt(JB_String* self, byte find, int Start, int After) {
	return JB_Str_InByte(self, Start, After, find);
}

int JB_Str_FindWithBmIntInt(JB_String* self, ByteMap* cs, int Start, int After) {
	return JB_Str_CharSet(self, Start, After, cs, true);
}

int JB_Str_IsHexLike(JB_String* self, int N) {
	if (JB_Str_ByteValue(self, N + 0x0) == '0') {
		byte X = JB_Str_ByteValue(self, N + 1);
		if (JB_byte_IsLetter(X)) {
			return 2;
		}
	}
	return 0;
}

int JB_Str_JBFind(JB_String* self, byte find, int Off, int After) {
	After = JB_int_OperatorMin(After, JB_Str_Length(self));
	while (Off < After) {
		byte c = JB_Str_ByteValue(self, Off++);
		if (c == '\\') {
			Off++;
		} else if (c == find) {
			if (find == '$') {
				if (Off >= After) {
					break;
				}
				byte nxt = JB_Str_ByteValue(self, Off);
				if ((!((nxt == '{') or JB_BM_HasChar(JB__Constants_CSWordStart, nxt)))) {
					continue;
				}
			}
			return Off - 1;
		}
	};
	return -1;
}

byte JB_Str_Last(JB_String* self) {
	return JB_Str_ByteValue(self, JB_Str_Length(self) - 1);
}

int JB_Str_LineCount(JB_String* self) {
	if ((!JB_Str_Exists(self))) {
		return nil;
	}
	return JB_Str_Count(self, '\n') + 1;
}

bool JB_Str_OperatorContainsWithStr(JB_String* self, JB_String* s) {
	return JB_int_Found(JB_Str_InStr(self, s, 0, kJB__int_max, true));
}

bool JB_Str_OperatorEndsWith(JB_String* self, JB_String* s) {
	int n = JB_Str_Length(self) - JB_Str_Length(s);
	return ((({
		JB_String* _tmP241 = JB_Incr(JB_Str_Range(self, n, -1));
		bool _tmP240 = JB_Str_SyntaxEquals(_tmP241, s, false);
		JB_Decr(_tmP241);
		 _tmP240;
	})));
}

int JB_Str_OutCharSet(JB_String* self, ByteMap* cs, int Start, int After) {
	return JB_Str_CharSet(self, Start, After, cs, false);
}

Message* JB_Str_Parse(JB_String* self, Message* into) {
	JB_Incr(into);
	if ((!JB_Tk__CppInited())) {
		JB_Tk__Init();
	}
	JB__Tk_ErrNode = ({
		Message* __imP = JB_Incr((JB_Syx_MsgWithStr(JB_SyxArg, JB_str_0)));
		JB_SafeDecr(__imP);
		 __imP;
	});
	if ((!(into))) {
		JB_SetRef(into, JB__Tk_ErrNode);
	}
	int Count = JB_StdErr->ErrorCount;
	JB_Tk__StartParse(self);
	JB__Tk_StopBars = 0;
	JB_Tk__ParseLoop(into, JB_str_0);
	JB_Tk__CleanSpaces();
	if (JB_Tk__Running()) {
		JB_Tk__Expect(0);
	}
	JB__Tk_ErrNode = nil;
	JB_Tk__StopParse();
	if ((!(Count == JB_StdErr->ErrorCount))) {
		JB_Decr(into);
		return nil;
	}
	JB_SafeDecr(into);
	return into;
}

Message* JB_Str_ParseAs(JB_String* self, JB_String* name) {
	if ((!JB_Str_Exists(name)) or (JB_Str_SyntaxEquals(name, JB_str_178, true))) {
		return JB_Str_Parse(self, nil);
	} else if (JB_Str_SyntaxEquals(name, JB_str_179, true)) {
		return ({
			Message* _tmP413 = JB_Incr(JB_Str_Parse(self, nil));
			Message* _tmP412 = JB_Incr(JB_Msg_ParseAST(_tmP413));
			JB_Decr(_tmP413);
			JB_SafeDecr(_tmP412);
			 _tmP412;
		});
	}
	return nil;
}

int JB_Str_ParseInt(JB_String* self, Message* Where) {
	return ((int)JB_Str_TextIntegerValid(self, Where));
}

Array* JB_Str_Split(JB_String* self, byte sep) {
	StringFields* fi = JB_Incr(JB_FI__New(self, sep));
	Array* result = JB_Incr(JB_Array__New0());
	{
		int _Prev = 0;
		while (fi->Data != nil) {
			int _Curr_1 = JB_FI_NextSep(fi, _Prev);
			JB_String* field = JB_Incr(JB_FI_Field(fi, _Prev, _Curr_1));
			JB_Array_Append(result, field);
			JB_Decr(field);
			_Prev = (_Curr_1 + 1);
			if ((!JB_int_Found(_Curr_1))) {
				break;
			}
		};
	};
	JB_Decr(fi);
	JB_SafeDecr(result);
	return result;
}

bool JB_Str_SyntaxEquals(JB_String* self, JB_String* Other, bool Aware) {
	return JB_Str_Equals(self, Other, Aware);
}

void JB_Str_SyntaxExpect(JB_String* self) {
	JB_Rec_NewItemWithNode(JB_StdErr, nil, self);
}

JB_String* JB_Str_TitleCase(JB_String* self, FastString* fs_in) {
	FastString* fs = JB_Incr(JB_FS__FastNew(fs_in));
	JB_FS_AppendByte(fs, JB_byte_UpperCase(JB_Str_ByteValue(self, 0)));
	JB_String* _tmP = JB_Incr(({
		JB_String* _tmP237 = JB_Incr(JB_Str_Range(self, 1, kJB__int_max));
		JB_String* _tmP236 = JB_Incr(JB_Str_LowerCase(_tmP237));
		JB_Decr(_tmP237);
		JB_SafeDecr(_tmP236);
		 _tmP236;
	}));
	JB_FS_AppendString(fs, _tmP);
	JB_Decr(_tmP);
	JB_String* _tmP1 = JB_Incr(JB_FS_SmartResult(fs, fs_in));
	JB_Decr(fs);
	JB_SafeDecr(_tmP1);
	return _tmP1;
}

JB_String* JB_Str_Unescape(JB_String* self) {
	return JB_Str_MultiReplaceAll(self, JB__Constants_UnEscapeStr, JB_StdErr);
}

ByteMap* JB_Str_UniCS(JB_String* self) {
	return ({
		JB_String* _tmP331 = JB_Incr((({
			JB_String* _tmP333 = JB_Incr(JB_Str_UnHex(JB_str_103));
			JB_String* _tmP332 = JB_Incr(JB_Str_OperatorPlus(self, _tmP333));
			JB_Decr(_tmP333);
			JB_SafeDecr(_tmP332);
			 _tmP332;
		})));
		ByteMap* _tmP330 = JB_Incr(JB_Str_Charset(_tmP331, true));
		JB_Decr(_tmP331);
		JB_SafeDecr(_tmP330);
		 _tmP330;
	});
}

Array* JB_Str_Words(JB_String* self) {
	return JB_Str_Split(self, ' ');
}

JB_String* JB_Str__SyntaxAccess(int b) {
	return JB_Str_ChrB(b);
}


StringFields_Behaviour InitTableStringFields_() { // Behaviour 
	StringFields_Behaviour Result;
	Result.__destructor__ = (void*)JB_FI_Destructor;
	Result.render = (__Object_Render__)JB_ObjRender;
	return Result;
}

StringFields_Behaviour StringFields_FuncTable_ = InitTableStringFields_();
JBClassPlace4(StringFields, JB_AsClass(JB_Object), StringFields_FuncTable_);

void JB_FI_Constructor(StringFields* self, JB_String* Source, byte Sep) {
	self->Data = JB_Incr(Source);
	self->Sep = Sep;
}

void JB_FI_Destructor(StringFields* self) {
	JB_Decr(self->Data);
}

JB_String* JB_FI_Field(StringFields* self, int Prev, int Curr) {
	if ((!(JB_int_Found(Curr)))) {
		Curr = JB_Str_Length(self->Data);
	}
	return JB_Str_Range(self->Data, Prev, Curr);
}

int JB_FI_NextSep(StringFields* self, int Prev) {
	return JB_Str_FindWithByteIntInt(self->Data, self->Sep, Prev, kJB__int_max);
}

StringFields* JB_FI__Alloc() {
	return ((StringFields*)JB_New(StringFields));
}

StringFields* JB_FI__New(JB_String* Source, byte Sep) {
	StringFields* Result = JB_FI__Alloc();
	if (Result) {
		JB_FI_Constructor(Result, Source, Sep);
	}
	return Result;
}



SyntaxObj_Behaviour InitTableSyntaxObj_() { // Behaviour 
	SyntaxObj_Behaviour Result;
	Result.__destructor__ = (void*)JB_Fn_Destructor;
	Result.render = (__Object_Render__)JB_Fn_Render;
	return Result;
}

SyntaxObj_Behaviour SyntaxObj_FuncTable_ = InitTableSyntaxObj_();
JBClassPlace4(SyntaxObj, JB_AsClass(JB_Object), SyntaxObj_FuncTable_);

void JB_Fn_Constructor(SyntaxObj* self, fpMsgRender msg, JB_String* name, int ID) {
	self->LongName = JB_Incr(JB_str_0);
	self->RenderAddr = msg;
	self->Name = JB_Incr(name);
	self->ID = ((Syntax)ID);
	self->ExportAddr = JB_Msg_Dummy;
}

void JB_Fn_Destructor(SyntaxObj* self) {
	JB_Decr(self->Name);
	JB_Decr(self->LongName);
}

JB_String* JB_Fn_Render(SyntaxObj* self, FastString* fs_in) {
	if ((!(fs_in))) {
		return JB_Str_LowerCase(self->LongName);
	}
	JB_String* _tmP = JB_Incr(JB_Str_LowerCase(self->LongName));
	JB_FS_AppendString(fs_in, _tmP);
	JB_Decr(_tmP);
	return JB_str_0;
}

SyntaxObj* JB_Fn__Alloc() {
	return ((SyntaxObj*)JB_New(SyntaxObj));
}

SyntaxObj* JB_Fn__New(fpMsgRender msg, JB_String* name, int ID) {
	SyntaxObj* Result = JB_Fn__Alloc();
	if (Result) {
		JB_Fn_Constructor(Result, msg, name, ID);
	}
	return Result;
}













void JB_Array_LoadProperties(Array* self, ObjectLoader* Loader) {
	while (JB_ObjectLoader_HasItem(Loader)) {
		JB_Array_Append(self, JB_ObjectLoader_Object(Loader));
	};
}

void JB_Array_SaveCollect(Array* self, ObjectSaver* Saver) {
	{
		int _i = 0;
		while (_i < JB_Array_Size(self)) {
			JB_Object* v = JB_Array_Value(self, _i);
			JB_Object_SaveTryCollect(v, Saver);
			_i++;
		};
	};
}

void JB_Array_SaveWrite(Array* self, ObjectSaver* Saver) {
	FastString* D = Saver->Dest;
	{
		int _i = 0;
		int _first2 = _i;
		while (_i < JB_Array_Size(self)) {
			JB_Object* v = JB_Array_Value(self, _i);
			if (_first2 != _i) {
				JB_FS_AppendString(D, JB_str_64);
			}
			//start;
			JB_FS_AppendObjectOrNil(D, v);
			_i++;
		};
	};
}

Array* JB_Array__Alloc() {
	return ((Array*)JB_New(Array));
}

Array* JB_Array__New(int size) {
	Array* Result = JB_Array__Alloc();
	if (Result) {
		JB_Array_Constructor(Result, size);
	}
	return Result;
}

Array* JB_Array__New0() {
	Array* Result = JB_Array__Alloc();
	if (Result) {
		JB_Array_Constructor0(Result);
	}
	return Result;
}


void JB_Dict_LoadProperties(Dictionary* self, ObjectLoader* Loader) {
	while (JB_ObjectLoader_HasItem(Loader)) {
		JB_String* name = JB_ObjectLoader_ItemName(Loader);
		if (JB_ObjectLoader_ItemIsInt(Loader)) {
			(JB_Dict_ValueSet(self, name, JB_Wrap__NewWithInt64(JB_ObjectLoader_ItemInt(Loader))));
		} else {
			(JB_Dict_ValueSet(self, name, JB_ObjectLoader_ItemObject(Loader)));
		}
	};
}

void JB_Dict_SaveCollect(Dictionary* self, ObjectSaver* Saver) {
	{
		DictionaryReader* _nav = JB_Dict_Navigate(self);
		while (JB_Nav_MoveNext(_nav)) {
			JB_Object* v = JB_Nav_Value(_nav);
			JB_Object_SaveTryCollect(v, Saver);
		};
	};
}

void JB_Dict_SaveWrite(Dictionary* self, ObjectSaver* Saver) {
	FastString* D = Saver->Dest;
	DictionaryReader* L = JB_Dict_Navigate(self);
	while (JB_DictionaryReader_SyntaxCast(L)) {
		JB_FS_AppendString(D, JB_Nav_Name(L));
		JB_FS_AppendString(D, JB_str_19);
		JB_FS_AppendObjectOrNil(D, JB_Nav_Value(L));
		JB_FS_AppendByte(D, ',');
	};
}

JB_Object* JB_Dict_Syntax(Dictionary* self, JB_String* Key) {
	return ({
		JB_String* _tmP337 = JB_Incr(JB_Str_FastLower(Key));
		JB_Object* _tmP336 = JB_Incr(JB_Dict_SyntaxAccessWithStr(self, _tmP337));
		JB_Decr(_tmP337);
		JB_SafeDecr(_tmP336);
		 _tmP336;
	});
}

JB_Object* JB_Dict_SyntaxAccessWithStr(Dictionary* self, JB_String* Key) {
	return JB_Dict_Value(self, Key, nil);
}

void JB_Dict_SyntaxAccessSet(Dictionary* self, int64 Key, JB_Object* Result) {
	(JB_Dict_ValueSet(self, JB_int64_DictName(Key), Result));
}

JB_Object* JB_Dict_SyntaxAccessWithInt64(Dictionary* self, int64 Key) {
	return JB_Dict_SyntaxAccessWithStr(self, JB_int64_DictName(Key));
}

Dictionary* JB_Dict__Alloc() {
	return ((Dictionary*)JB_New(Dictionary));
}

Dictionary* JB_Dict__New() {
	Dictionary* Result = JB_Dict__Alloc();
	if (Result) {
		JB_Dict_Constructor(Result);
	}
	return Result;
}


FastAppender_Behaviour InitTableFastAppender_() { // Behaviour 
	FastAppender_Behaviour Result;
	Result.__destructor__ = (void*)JB_FAP_Destructor;
	Result.loadproperties = (__Saveable_LoadProperties__)JB_FAP_LoadProperties;
	Result.savecollect = (__Saveable_SaveCollect__)JB_Sav_SaveCollect;
	Result.savewrite = (__Saveable_SaveWrite__)JB_FAP_SaveWrite;
	Result.render = (__Object_Render__)JB_ObjRender;
	return Result;
}

FastAppender_Behaviour FastAppender_FuncTable_ = InitTableFastAppender_();
JBClassPlace4(FastAppender, JB_AsClass(Saveable), FastAppender_FuncTable_);

void JB_FAP_Destructor(FastAppender* self) {
	JB_LLRef_Destructor((&self->Chunks));
}

void JB_FAP_Grow(FastAppender* self) {
	FastAppenderChunk* C = JB_FAC__New();
	if ((!C)) {
		return;
	}
	FastAppenderChunk* Old = (FastAppenderChunk*)(self->Chunks.First);
	if (Old) {
		Old->Prev = C;
	} else {
		self->ActualFirst = C;
	}
	JB_LLRef_SyntaxAppend((&self->Chunks), C);
}

void JB_FAP_LoadProperties(FastAppender* self, ObjectLoader* Loader) {
}

void JB_FAP_SaveWrite(FastAppender* self, ObjectSaver* Saver) {
}

void JB_FAP_SyntaxAppend(FastAppender* self, JB_Object* obj) {
	FastAppenderChunk* L = (FastAppenderChunk*)(self->Chunks.First);
	if (JB_FAC_CantStoreMore(L)) {
		JB_FAP_Grow(self);
		L = (FastAppenderChunk*)(self->Chunks.First);
		if ((!L)) {
			return;
		}
	}
	self->DbgCount++;
	JB_FAC_Add(L, obj);
}

int JB_FAP__Init_() {
	{
		JB__FAP_Tested = false;
	};
	return 0;
}



bool JB_LinkedList_ListSanity(JB_LinkedList* self) {
	if (JB_IsDebug()) {
		if ((!(self->_Next != self))) {
			debugger;
			return nil;
		}
		if ((!(((!self->_BackRef)) or (self->_BackRef[0] == self)))) {
			debugger;
			return nil;
		}
	}
	return true;
}

void JB_LinkedList_LoadProperties(JB_LinkedList* self, ObjectLoader* Loader) {
	JB_ObjectLoader_LinkedListWithLinkedlist(Loader, (&self->_Next));
	JB_LinkedList_ListSanity(self);
}

JB_LinkedList* JB_LinkedList_Next(JB_LinkedList* self) {
	return self->_Next;
}

void JB_LinkedList_SaveWrite(JB_LinkedList* self, ObjectSaver* Saver) {
	if (self == Saver->Root) {
		JB_Saver_AppendObject(Saver, nil);
	} else {
		JB_Saver_AppendObject(Saver, self->_Next);
	}
}


RingTree* JB_Tree_First_(RingTree* self) {
	if (self) {
		return JB_Ring_First(self);
	}
	return nil;
}

bool JB_Tree_HasOneChild(RingTree* self) {
	return JB_Ring_HasChildCount(self, 1);
}

void JB_Tree_Remove(RingTree* self) {
	(JB_Ring_ParentSet(self, nil));
}

RingTree* JB_Tree_SyntaxAccessWithInt(RingTree* self, int n) {
	if ((!self)) {
		return nil;
	}
	if (n < 0) {
		return JB_Ring_Last(self);
	}
	RingTree* result = JB_Ring_First(self);
	while (((bool)result) and (n-- >= 1)) {
		result = JB_Ring_NextSib(result);
	};
	return result;
}

void JB_Tree_SyntaxAppend(RingTree* self, RingTree* Last) {
	(JB_Ring_LastSet(self, Last));
}


SaverClassInfo_Behaviour InitTableSaverClassInfo_() { // Behaviour 
	SaverClassInfo_Behaviour Result;
	Result.__destructor__ = (void*)JB_sci_Destructor;
	Result.loadproperties = (__Saveable_LoadProperties__)JB_FAP_LoadProperties;
	Result.savecollect = (__Saveable_SaveCollect__)JB_Sav_SaveCollect;
	Result.savewrite = (__Saveable_SaveWrite__)JB_FAP_SaveWrite;
	Result.render = (__Object_Render__)JB_ObjRender;
	return Result;
}

SaverClassInfo_Behaviour SaverClassInfo_FuncTable_ = InitTableSaverClassInfo_();
JBClassPlace4(SaverClassInfo, JB_AsClass(FastAppender), SaverClassInfo_FuncTable_);

void JB_sci_Destructor(SaverClassInfo* self) {
	JB_Decr(self->NextInfo);
	JB_FAP_Destructor(self);
}


Error_Behaviour InitTableJB_Error_() { // Behaviour 
	Error_Behaviour Result;
	Result.__destructor__ = (void*)JB_Err_Destructor;
	Result.loadproperties = (__Saveable_LoadProperties__)JB_LinkedList_LoadProperties;
	Result.savecollect = (__Saveable_SaveCollect__)JB_Sav_SaveCollect;
	Result.savewrite = (__Saveable_SaveWrite__)JB_LinkedList_SaveWrite;
	Result.render = (__Object_Render__)JB_Err_Render;
	return Result;
}

Error_Behaviour JB_Error_FuncTable_ = InitTableJB_Error_();
JBClassPlace4(JB_Error, JB_AsClass(JB_LinkedList), JB_Error_FuncTable_);

void JB_Err_Constructor(JB_Error* self, Message* node) {
	JB_LinkedList_Constructor(self);
	self->DontStrip = false;
	self->Description = JB_Incr(JB_str_0);
	int P = -1;
	if (node) {
		P = node->Position;
	}
	self->Position = P;
	self->Source = JB_Incr(node);
	self->ErrorLevel = kJB__ErrorSeverity_Error;
	JB_String* _tmP = JB_Msg_OriginalParsePath(node);
	self->Path = JB_Incr(_tmP);
	JB_String* _tmP1 = JB_Msg_OriginalParseData(node);
	self->OriginalData = JB_Incr(_tmP1);
}

void JB_Err_Destructor(JB_Error* self) {
	JB_Decr(self->Path);
	JB_Decr(self->Description);
	JB_Decr(self->OriginalData);
	JB_Decr(self->Source);
	JB_LinkedList_Destructor(self);
}

void JB_Err_Fill(JB_Error* self, JB_String* path, JB_String* desc) {
	JB_SetRef(self->Path, path);
	JB_SetRef(self->Description, desc);
}

void JB_Err_GrabLine(JB_Error* self, FastString* fs, bool Usecolor) {
	if (Usecolor) {
		JB_FS_AppendString(fs, kJB__ErrorColors_normal);
	}
	JB_String* d = JB_Incr(self->OriginalData);
	if ((!JB_Str_Exists(d))) {
		JB_Decr(d);
		return;
	}
	if ((!JB_Err_HasPosition(self))) {
		JB_Decr(d);
		return;
	}
	int Start = JB_Str_FindWithBmIntInt(d, JB__Constants_CSLine, self->Position, 0) + 1;
	int Finish = JB_Str_FindWithBmIntInt(d, JB__Constants_CSLine, self->Position, kJB__int_max);
	if (Finish == -1) {
		Finish = (JB_Str_Length(d) + 1);
	}
	JB_String* _tmP = JB_Incr(({
		JB_String* _tmP198 = JB_Incr(JB_Str_Range(d, Start, Finish));
		JB_String* _tmP197 = JB_Incr(JB_Str_ReplaceAll(_tmP198, JB_str_17, JB_str_15, false, nil));
		JB_Decr(_tmP198);
		JB_SafeDecr(_tmP197);
		 _tmP197;
	}));
	JB_Decr(d);
	JB_FS_AppendString(fs, _tmP);
	JB_Decr(_tmP);
	int Spaces = (self->Position - Start);
	if (Spaces > 200) {
		Spaces = 0;
	}
	JB_FS_AppendByte(fs, '\n');
	if (Usecolor) {
		JB_FS_AppendString(fs, kJB__ErrorColors_underline);
	}
	JB_FS_AppendMultiByte(fs, ' ', Spaces);
	JB_FS_AppendByte(fs, '^');
}

bool JB_Err_HasPosition(JB_Error* self) {
	return self->Position >= 0;
}

bool JB_Err_IsWarning(JB_Error* self) {
	return (self->ErrorLevel >= kJB__ErrorSeverity_Warning);
}

bool JB_Err_LineIdentifiers(JB_Error* self, FastString* fs, JB_String* path) {
	if ((!(JB_Err_HasPosition(self)))) {
		return nil;
	}
	JB_String* d = JB_Incr(self->OriginalData);
	if ((!JB_Str_Exists(d))) {
		JB_Decr(d);
		return nil;
	}
	if ((!(JB_Str_Exists(path)))) {
		JB_FS_AppendString(fs, JB_str_18);
	}
	JB_FS_SyntaxAppendWithInt(fs, JB_Err_LinePos(self, d));
	JB_FS_AppendByte(fs, ':');
	int Start = JB_Str_FindWithBmIntInt(d, JB__Constants_CSLine, self->Position, 0);
	JB_Decr(d);
	JB_FS_SyntaxAppendWithInt(fs, (self->Position - Start));
	JB_FS_AppendByte(fs, ':');
	return true;
}

int JB_Err_LinePos(JB_Error* self, JB_String* data) {
	if (JB_Err_HasPosition(self)) {
		return ({
			JB_String* _tmP195 = JB_Incr(JB_Str_Range(data, 0, self->Position));
			int _tmP194 = JB_Str_LineCount(_tmP195);
			JB_Decr(_tmP195);
			 _tmP194;
		});
	}
	return 0;
}

JB_String* JB_Err_Render(JB_Error* self, FastString* fs_in) {
	FastString* fs = JB_Incr(JB_FS__FastNew(fs_in));
	JB_String* P = JB_Incr(self->Path);
	if (JB_Str_Exists(P)) {
		JB_FS_AppendString(fs, P);
		JB_FS_AppendByte(fs, ':');
	}
	if ((!JB_Err_LineIdentifiers(self, fs, P)) and ((bool)self->Source)) {
		JB_FreeIfDead(JB_ObjRender(self->Source, fs));
	}
	JB_Decr(P);
	JB_FS_AppendByte(fs, ' ');
	JB_FreeIfDead(JB_ErrorSeverity_Render(self->ErrorLevel, fs));
	JB_FS_AppendString(fs, JB_str_19);
	JB_FS_AppendString(fs, self->Description);
	JB_FS_AppendByte(fs, '\n');
	JB_Err_GrabLine(self, fs, false);
	JB_FS_AppendByte(fs, '\n');
	JB_String* _tmP = JB_Incr(JB_FS_SmartResult(fs, fs_in));
	JB_Decr(fs);
	JB_SafeDecr(_tmP);
	return _tmP;
}

JB_Error* JB_Err__Alloc() {
	return ((JB_Error*)JB_New(JB_Error));
}

void JB_Err__CantParseNum(Message* Where, JB_String* num, int Pos) {
	JB_Error* err = JB_Incr(JB_Err__New(Where));
	FastString* _fs_fs = JB_Incr(JB_FS__New());
	JB_FS_AppendString(_fs_fs, JB_str_187);
	JB_String* _tmP1 = JB_Incr(JB_Str_Range(num, 0, 10));
	JB_FS_AppendString(_fs_fs, _tmP1);
	JB_Decr(_tmP1);
	JB_FS_AppendString(_fs_fs, JB_str_188);
	JB_FS_AppendByte(_fs_fs, JB_Str_ByteValue(num, Pos));
	JB_FS_AppendString(_fs_fs, JB_str_189);
	JB_String* _fs_str = JB_Incr(JB_FS_SyntaxCast(_fs_fs));
	JB_SetRef(_fs_fs, nil);
	JB_Decr(_fs_fs);
	JB_SetRef(err->Description, _fs_str);
	JB_Decr(_fs_str);
	JB_Rec_SyntaxAppend(JB_StdErr, err);
	JB_Decr(err);
}

JB_Error* JB_Err__New(Message* node) {
	JB_Error* Result = JB_Err__Alloc();
	if (Result) {
		JB_Err_Constructor(Result, node);
	}
	return Result;
}


ErrorReceiver_Behaviour InitTableJB_ErrorReceiver_() { // Behaviour 
	ErrorReceiver_Behaviour Result;
	Result.__destructor__ = (void*)JB_Rec_Destructor;
	Result.loadproperties = (__Saveable_LoadProperties__)JB_LinkedList_LoadProperties;
	Result.savecollect = (__Saveable_SaveCollect__)JB_Sav_SaveCollect;
	Result.savewrite = (__Saveable_SaveWrite__)JB_LinkedList_SaveWrite;
	Result.render = (__Object_Render__)JB_ObjRender;
	return Result;
}

ErrorReceiver_Behaviour JB_ErrorReceiver_FuncTable_ = InitTableJB_ErrorReceiver_();
JBClassPlace4(JB_ErrorReceiver, JB_AsClass(JB_LinkedList), JB_ErrorReceiver_FuncTable_);

bool JB_Rec_CanAddMore(JB_ErrorReceiver* self) {
	return (!JB_OutOfMemoryOccurred()) and (JB_Rec_TotalCount(self) < self->MaxErrors);
}

void JB_Rec_Clear(JB_ErrorReceiver* self) {
	JB_LLRef_Clear((&self->Errors));
	self->ErrorCount = 0;
	self->WarnCount = 0;
}

void JB_Rec_Constructor(JB_ErrorReceiver* self) {
	JB_LinkedList_Constructor(self);
	self->Errors = ((LLRef){
	});
	self->ErrorCount = 0;
	self->WarnCount = 0;
	self->Source = JB_Incr(JB_str_0);
	JB_LinkedList_StoreAt(self, ((JB_LinkedList**)((&JB_StdErr))));
	self->MaxErrors = 512;
	JB__API_NilHappened = nil;
}

void JB_Rec_Destructor(JB_ErrorReceiver* self) {
	JB_LLRef_Destructor((&self->Errors));
	JB_Decr(self->Source);
	JB_LinkedList_Destructor(self);
}

JB_Error* JB_Rec_FirstError(JB_ErrorReceiver* self) {
	{
		LLRef _LoopSrc2 = self->Errors;
		JB_Error* err = (JB_Error*)(_LoopSrc2.First);
		while (err) {
			JB_LinkedList_ListSanity(err);
			JB_Error* _N1 = (JB_Error*)(err->_Next);
			if ((!(JB_Err_IsWarning(err)))) {
				return err;
			}
			err = _N1;
		};
	};
	return nil;
}

void JB_Rec_NewItemWithNode(JB_ErrorReceiver* self, Message* node, JB_String* Desc) {
	if ((!(JB_Rec_CanAddMore(self)))) {
		return;
	}
	JB_Error* err = JB_Incr(JB_Err__New(node));
	JB_SetRef(err->Description, Desc);
	JB_Rec_SyntaxAppend(self, err);
	JB_Decr(err);
}

void JB_Rec_NewItem(JB_ErrorReceiver* self, JB_Error* Err) {
	JB_Rec_SyntaxAppend(self, Err);
}

bool JB_Rec_OK(JB_ErrorReceiver* self) {
	return ((bool)self) and ((!self->ErrorCount));
}

void JB_Rec_PrintErrors(JB_ErrorReceiver* self, int Flags) {
	if ((!self)) {
		return;
	}
	int Count = 0;
	{
		JB_Error* err = JB_Incr((JB_Error*)(self->Errors.First));
		while (err) {
			if (JB_Err_IsWarning(err) == ((bool)(Flags & kJB__Rec_iswarning))) {
				Count++;
				JB_String* _tmP2 = JB_Incr(({
					JB_String* _tmP193 = JB_Incr(JB_Err_Render(err, nil));
					JB_String* _tmP192 = JB_Incr(JB_Str_OperatorPlus(_tmP193, JB_str_13));
					JB_Decr(_tmP193);
					JB_SafeDecr(_tmP192);
					 _tmP192;
				}));
				JB_Str_PrintError(_tmP2);
				JB_Decr(_tmP2);
			}
			JB_SetRef(err, ((JB_Error*)JB_LinkedList_Next(err)));
		};
		JB_Decr(err);
	};
	if ((!(((bool)Count) and ((bool)(Flags & kJB__Rec_printcount))))) {
		return;
	}
	JB_String* TypeName = JB_Incr(JB_Rec__ErrorType(((bool)(Flags & kJB__Rec_iswarning))));
	FastString* _fs_fs = JB_Incr(JB_FS__New());
	JB_FS_SyntaxAppendWithInt(_fs_fs, Count);
	JB_FS_AppendString(_fs_fs, JB_str_15);
	JB_FS_AppendString(_fs_fs, TypeName);
	JB_Decr(TypeName);
	JB_FS_AppendString(_fs_fs, JB_str_16);
	JB_String* _fs_str = JB_Incr(JB_FS_SyntaxCast(_fs_fs));
	JB_SetRef(_fs_fs, nil);
	JB_Decr(_fs_fs);
	JB_Str_PrintError(_fs_str);
	JB_Decr(_fs_str);
}

void JB_Rec_SyntaxAppend(JB_ErrorReceiver* self, JB_Error* Err) {
	if (JB_Err_IsWarning(Err)) {
		self->WarnCount++;
	} else {
		if (JB_IsDebug() and (!self->ErrorCount)) {
			JB_Obj_PrintLine(Err);
		}
		if (JB__Rec_BreakOnError) {
			JB_DoAt(1);
		}
		self->ErrorCount++;
	}
	if ((!(JB_Str_Exists(Err->Path)))) {
		JB_SetRef(Err->Path, self->Source);
	}
	JB_LLRef_SyntaxAppend((&self->Errors), Err);
}

int JB_Rec_TotalCount(JB_ErrorReceiver* self) {
	return self->ErrorCount + self->WarnCount;
}

JB_ErrorReceiver* JB_Rec__Alloc() {
	return ((JB_ErrorReceiver*)JB_New(JB_ErrorReceiver));
}

JB_String* JB_Rec__ErrorType(bool IsWarning) {
	if (IsWarning) {
		return JB_str_11;
	} else {
		return JB_str_12;
	}
	return JB_str_0;
}

int JB_Rec__Init_() {
	{
		JB__Rec_BreakOnError = false;
	};
	return 0;
}

JB_ErrorReceiver* JB_Rec__New() {
	JB_ErrorReceiver* Result = JB_Rec__Alloc();
	if (Result) {
		JB_Rec_Constructor(Result);
	}
	return Result;
}

void JB_Rec__PrintErrors() {
	if ((!JB_StdErr)) {
		return;
	}
	JB_Rec_PrintErrors(JB_StdErr, 0);
}


FastAppenderChunk_Behaviour InitTableFastAppenderChunk_() { // Behaviour 
	FastAppenderChunk_Behaviour Result;
	Result.__destructor__ = (void*)JB_FAC_Destructor;
	Result.loadproperties = (__Saveable_LoadProperties__)JB_LinkedList_LoadProperties;
	Result.savecollect = (__Saveable_SaveCollect__)JB_Sav_SaveCollect;
	Result.savewrite = (__Saveable_SaveWrite__)JB_LinkedList_SaveWrite;
	Result.render = (__Object_Render__)JB_ObjRender;
	return Result;
}

FastAppenderChunk_Behaviour FastAppenderChunk_FuncTable_ = InitTableFastAppenderChunk_();
JBClassPlace4(FastAppenderChunk, JB_AsClass(JB_LinkedList), FastAppenderChunk_FuncTable_);

void JB_FAC_Add(FastAppenderChunk* self, JB_Object* C) {
	if ((!((self->NItems < 31) and (self->NItems >= 0)))) {
		debugger;
	}
	self->Items[self->NItems++] = C;
}

bool JB_FAC_CantStoreMore(FastAppenderChunk* self) {
	return (!self) or (self->NItems >= 31);
}

void JB_FAC_Constructor(FastAppenderChunk* self) {
	JB_LinkedList_Constructor(self);
	self->Prev = nil;
	self->NItems = 0;
}

void JB_FAC_Destructor(FastAppenderChunk* self) {
	JB_LinkedList_Destructor(self);
}

FastAppenderChunk* JB_FAC__Alloc() {
	return ((FastAppenderChunk*)JB_New(FastAppenderChunk));
}

FastAppenderChunk* JB_FAC__New() {
	FastAppenderChunk* Result = JB_FAC__Alloc();
	if (Result) {
		JB_FAC_Constructor(Result);
	}
	return Result;
}


Message_Behaviour InitTableMessage_() { // Behaviour 
	Message_Behaviour Result;
	Result.__destructor__ = (void*)JB_Msg_Destructor;
	Result.loadproperties = (__Saveable_LoadProperties__)JB_Sav_LoadProperties;
	Result.savecollect = (__Saveable_SaveCollect__)JB_Sav_SaveCollect;
	Result.savewrite = (__Saveable_SaveWrite__)JB_Sav_SaveWrite;
	Result.render = (__Object_Render__)JB_Msg_Render;
	return Result;
}

Message_Behaviour Message_FuncTable_ = InitTableMessage_();
JBClassPlace4(Message, JB_AsClass(RingTree), Message_FuncTable_);

void JB_Msg_Acc__(Message* self, FastString* fs) {
	Message* _tmP = JB_Incr(((Message*)JB_Ring_First(self)));
	JB_FS_SyntaxAppendWithMsg(fs, _tmP);
	JB_Decr(_tmP);
	Message* _tmP1 = JB_Incr(((Message*)JB_Ring_Last(self)));
	JB_Msg_RenderPrm(_tmP1, fs, '[', ']');
	JB_Decr(_tmP1);
}

void JB_Msg_AccessErrWithSyxStr(Message* self, Syntax s, JB_String* name) {
	if ((!self)) {
		JB_API__NilHandler();
		return;
	}
	FastString* fs = JB_Incr(JB_FS__New());
	JB_FS_AppendString(fs, JB_str_78);
	JB_String* _tmP = JB_Incr(JB_Syx_LongName(s));
	JB_FS_AppendString(fs, _tmP);
	JB_Decr(_tmP);
	JB_FS_MsgErrorName(fs, name);
	JB_String* _tmP1 = JB_Incr(JB_FS_GetResult(fs));
	JB_Decr(fs);
	JB_Rec_NewItemWithNode(JB_StdErr, self, _tmP1);
	JB_Decr(_tmP1);
}

void JB_Msg_Adj__(Message* self, FastString* fs) {
	Message* _tmP = JB_Incr(((Message*)JB_Ring_First(self)));
	JB_FS_SyntaxAppendWithMsg(fs, _tmP);
	JB_Decr(_tmP);
	JB_FS_AppendByte(fs, '~');
	Message* _tmP1 = JB_Incr(((Message*)JB_Ring_Last(self)));
	JB_FS_SyntaxAppendWithMsg(fs, _tmP1);
	JB_Decr(_tmP1);
}

void JB_Msg_Ana__(Message* self, FastString* fs) {
	JB_FS_AppendString(fs, JB_str_72);
	JB_FS_AppendString(fs, self->Name);
}

void JB_Msg_ARel__(Message* self, FastString* fs) {
	Message* _tmP = JB_Incr(((Message*)JB_Ring_First(self)));
	JB_FS_SyntaxAppendWithMsg(fs, _tmP);
	JB_Decr(_tmP);
	JB_FS_AppendString(fs, self->Name);
}

void JB_Msg_Arg__(Message* self, FastString* fs) {
	JB_String* n = self->Name;
	if ((!JB_Str_Exists(n))) {
		if (((Message*)JB_Ring_Parent(self))) {
			JB_FS_AppendString(fs, JB_str_63);
			fs->Indent++;
		}
		JB_Msg_FSListArg(self, fs);
		if (((Message*)JB_Ring_Parent(self))) {
			fs->Indent--;
			JB_FS_AppendIndent(fs);
			JB_FS_AppendByte(fs, '}');
		}
	} else if (JB_Str_ByteValue(n, 0) == ':') {
		JB_FS_AppendString(fs, JB_str_19);
		JB_Msg_FSListSep(self, fs, JB_str_64);
	} else {
		if (((Message*)JB_Ring_Parent(self))) {
			JB_FS_AppendByte(fs, '\n');
			fs->Indent++;
		}
		JB_Msg_FSListArg(self, fs);
		if (((Message*)JB_Ring_Parent(self))) {
			fs->Indent--;
			JB_FS_AppendIndent(fs);
		}
	}
}

void JB_Msg_Arr__(Message* self, FastString* fs) {
	JB_FS_AppendByte(fs, '[');
	JB_Msg_FSListSep(self, fs, JB_str_64);
	JB_FS_AppendByte(fs, ']');
}

void JB_Msg_Ask__(Message* self, FastString* fs) {
	Message* first = JB_Incr(((Message*)JB_Ring_First(self)));
	Message* op = JB_Incr(((Message*)JB_Ring_NextSib(first)));
	JB_FS_AppendString(fs, JB_str_74);
	JB_FS_SyntaxAppendWithMsg(fs, op);
	JB_FS_AppendByte(fs, ' ');
	JB_FS_SyntaxAppendWithMsg(fs, first);
	JB_Decr(first);
	Message* last = JB_Incr(((Message*)JB_Ring_NextSib(op)));
	JB_Decr(op);
	if (last) {
		JB_FS_AppendByte(fs, ' ');
		JB_FS_SyntaxAppendWithMsg(fs, last);
	}
	JB_Decr(last);
}

JB_String* JB_Msg_AST(Message* self, FastString* fs_in) {
	FastString* fs = JB_Incr(JB_FS__FastNew(fs_in));
	if ((JB_Msg_SyntaxEqualsWithSyxBool(self, JB_SyxArg, false)) and JB_Ring_IsRoot(self)) {
		{
			Message* ch = JB_Incr(((Message*)JB_Tree_First_(self)));
			while (ch) {
				Message* _N1 = JB_Incr(((Message*)JB_Ring_NextSib(ch)));
				JB_FreeIfDead(JB_Msg_AST(ch, fs));
				JB_FS_AppendByte(fs, '\n');
				JB_SetRef(ch, _N1);
				JB_Decr(_N1);
			};
			JB_Decr(ch);
		};
	} else {
		JB_FS_AppendString(fs, JB_str_75);
		JB_String* _tmP4 = JB_Incr(JB_Syx_Name(self->Func));
		JB_FS_AppendString(fs, _tmP4);
		JB_Decr(_tmP4);
		JB_FS_AppendByte(fs, ' ');
		if (JB_Str_Exists(self->Name)) {
			JB_FS_AppendByte(fs, '"');
			JB_FS_AppendEscape(fs, self->Name);
			JB_FS_AppendByte(fs, '"');
		}
		if (JB_Ring_HasChildren(self)) {
			fs->Indent++;
			{
				Message* ch = JB_Incr(((Message*)JB_Tree_First_(self)));
				while (ch) {
					Message* _N3 = JB_Incr(((Message*)JB_Ring_NextSib(ch)));
					JB_FS_AppendByte(fs, '\n');
					JB_FS_AppendIndent(fs);
					JB_FreeIfDead(JB_Msg_AST(ch, fs));
					JB_SetRef(ch, _N3);
					JB_Decr(_N3);
				};
				JB_Decr(ch);
			};
			fs->Indent--;
			JB_FS_AppendByte(fs, '\n');
			JB_FS_AppendIndent(fs);
		}
		JB_FS_AppendString(fs, JB_str_77);
	}
	JB_String* _tmP5 = JB_Incr(JB_FS_SmartResult(fs, fs_in));
	JB_Decr(fs);
	JB_SafeDecr(_tmP5);
	return _tmP5;
}

void JB_Msg_Back__(Message* self, FastString* fs) {
	if (JB_int_Found(JB_Str_FindWithByteIntInt(self->Name, '`', 0, kJB__int_max))) {
		JB_Msg_Str__(self, fs);
	} else {
		JB_FS_AppendByte(fs, '`');
		JB_FS_AppendString(fs, self->Name);
		JB_FS_AppendByte(fs, '`');
	}
}

void JB_Msg_Become(Message* self, Syntax fn, JB_String* name) {
	self->Func = fn;
	JB_SetRef(self->Name, name);
}

void JB_Msg_Bin__(Message* self, FastString* fs) {
	JB_Str_AppendAsBinary(self->Name, fs);
}

void JB_Msg_Bnch__(Message* self, FastString* fs) {
	JB_FS_AppendString(fs, self->Name);
	Message* _tmP = JB_Incr(((Message*)JB_Ring_First(self)));
	JB_FS_SyntaxAppendWithMsg(fs, _tmP);
	JB_Decr(_tmP);
}

void JB_Msg_Bra__(Message* self, FastString* fs) {
	JB_FS_AppendByte(fs, '(');
	Message* _tmP = JB_Incr(((Message*)JB_Ring_First(self)));
	JB_FS_SyntaxAppendWithMsg(fs, _tmP);
	JB_Decr(_tmP);
	JB_FS_AppendByte(fs, ')');
}

void JB_Msg_BRel__(Message* self, FastString* fs) {
	JB_FS_AppendString(fs, self->Name);
	Message* _tmP = JB_Incr(((Message*)JB_Ring_First(self)));
	JB_FS_SyntaxAppendWithMsg(fs, _tmP);
	JB_Decr(_tmP);
}

void JB_Msg_Char__(Message* self, FastString* fs) {
	JB_FS_AppendByte(fs, '\'');
	JB_String* _tmP = JB_Incr(JB_Str_EscapeChr(self->Name));
	JB_FS_AppendString(fs, _tmP);
	JB_Decr(_tmP);
	JB_FS_AppendByte(fs, '\'');
}

void JB_Msg_Cnj__(Message* self, FastString* fs) {
	JB_FS_AppendByte(fs, '#');
	JB_FS_AppendString(fs, self->Name);
}

void JB_Msg_ConstructorCopy(Message* self, Message* other) {
	JB_Ring_Constructor0(self);
	self->Indent = 0;
	self->MoreFlags = 0;
	JB_String* _tmP = other->Name;
	self->Name = JB_Incr(_tmP);
	self->Obj = other->Obj;
	self->Position = other->Position;
	self->Func = other->Func;
}

void JB_Msg_ConstructorWithSyxStr(Message* self, Syntax Func, JB_String* Name) {
	JB_Ring_Constructor0(self);
	self->Name = JB_Incr(JB_str_0);
	self->Func = nil;
	self->Indent = 0;
	self->MoreFlags = 0;
	self->Obj = nil;
	JB_Msg_Become(self, Func, Name);
	self->Position = JB__Tk_UsingPos;
}

void JB_Msg_ConstructorParser(Message* self, Message* Parent, Syntax Func, int BytePos, JB_String* Name) {
	JB_Ring_Constructor(self, Parent);
	self->Name = JB_Incr(JB_str_0);
	self->Func = nil;
	self->Indent = 0;
	self->MoreFlags = 0;
	self->Obj = nil;
	self->Position = BytePos;
	JB_Msg_Become(self, Func, Name);
}

Message* JB_Msg_Copy(Message* self, bool DefaultLayer) {
	if (DefaultLayer) {
		return JB_Msg_NormalCopy(self);
	} else {
		return ({
			JB_MemoryLayer* _tmP254 = JB_Incr(JB_ObjLayer(self));
			Message* _tmP253 = JB_Incr(JB_Msg_LayerCopy(self, _tmP254));
			JB_Decr(_tmP254);
			JB_SafeDecr(_tmP253);
			 _tmP253;
		});
	}
	return nil;
}

void JB_Msg_Decl__(Message* self, FastString* fs) {
	Message* ch = JB_Incr(((Message*)JB_Ring_First(self)));
	if ((!ch)) {
		JB_Decr(ch);
		return;
	}
	JB_FS_AppendByte(fs, '|');
	JB_FS_SyntaxAppendWithMsg(fs, ch);
	JB_FS_AppendByte(fs, '|');
	JB_SetRef(ch, ((Message*)JB_Ring_NextSib(ch)));
	while (ch) {
		JB_FS_AppendByte(fs, ' ');
		JB_FS_SyntaxAppendWithMsg(fs, ch);
		JB_SetRef(ch, ((Message*)JB_Ring_NextSib(ch)));
	};
	JB_Decr(ch);
}

void JB_Msg_Destructor(Message* self) {
	JB_Decr(self->Name);
	JB_Ring_Destructor(self);
}

void JB_Msg_Dot__(Message* self, FastString* fs) {
	Message* ch = JB_Incr(((Message*)JB_Ring_First(self)));
	if ((!ch)) {
		JB_Decr(ch);
		return;
	}
	JB_FS_SyntaxAppendWithMsg(fs, ch);
	JB_FS_AppendByte(fs, '.');
	JB_FS_AppendString(fs, self->Name);
	Message* _tmP = JB_Incr(((Message*)JB_Ring_NextSib(ch)));
	JB_Decr(ch);
	JB_FS_SyntaxAppendWithMsg(fs, _tmP);
	JB_Decr(_tmP);
}

void JB_Msg_Dummy(Message* self, FastString* fs) {
}

void JB_Msg_Emb__(Message* self, FastString* fs) {
	JB_FS_AppendString(fs, self->Name);
	if ((!JB_Ring_HasChildren(self))) {
		return;
	}
	JB_Msg_RenderWithSpaces(self, fs, nil);
}

void JB_Msg_ERel__(Message* self, FastString* fs) {
	Message* ch = JB_Incr(((Message*)JB_Ring_First(self)));
	if ((!ch)) {
		JB_Decr(ch);
		return;
	}
	JB_FS_SyntaxAppendWithMsg(fs, ch);
	JB_FS_AppendByte(fs, ' ');
	JB_SetRef(ch, ((Message*)JB_Ring_NextSib(ch)));
	if ((!ch)) {
		JB_Decr(ch);
		return;
	}
	JB_FS_SyntaxAppendWithMsg(fs, ch);
	JB_FS_AppendString(fs, JB_str_67);
	JB_SetRef(ch, ((Message*)JB_Ring_NextSib(ch)));
	if ((!ch)) {
		JB_Decr(ch);
		return;
	}
	JB_FS_SyntaxAppendWithMsg(fs, ch);
	JB_Decr(ch);
}

Message* JB_Msg_ExitInvisArg(Message* self, int missing) {
	Message* curr = self;
	while (true) {
		if ((!(JB_Msg_InInvisArg(curr)))) {
			return JB_Tk__ErrorAlwaysAdd(JB_str_186, self->Position);
		}
		Message* place = ((Message*)JB_Ring_Parent(curr));
		curr = ((Message*)JB_Ring_Parent(place));
		if (missing == 2) {
			return JB_Tk__InvisArgNest(self, curr);
		}
		missing = (missing - 4);
		curr = JB_Tk__InvisArgEscapeNested(curr);
		if ((!(missing > 0))) {
			break;
		}
	};
	(JB_Ring_NextSibSet(curr, self));
	return ((Message*)JB_Ring_Parent(curr));
}

bool JB_Msg_Expect(Message* self, Syntax type, JB_String* name) {
	if ((!self)) {
		return true;
	}
	if ((!type) or (self->Func == type)) {
		if ((!JB_Str_Exists(name)) or ((JB_Str_SyntaxEquals(self->Name, name, true)))) {
			return true;
		}
	}
	FastString* fs = JB_Incr(JB_FS__New());
	JB_FS_AppendString(fs, JB_str_81);
	if (type) {
		JB_String* _tmP = JB_Incr(JB_Syx_LongName(type));
		JB_FS_AppendString(fs, _tmP);
		JB_Decr(_tmP);
	}
	JB_FS_MsgErrorName(fs, name);
	JB_FS_AppendString(fs, JB_str_106);
	JB_String* _tmP1 = JB_Incr(JB_Syx_LongName(self->Func));
	JB_FS_AppendString(fs, _tmP1);
	JB_Decr(_tmP1);
	JB_FS_MsgErrorName(fs, self->Name);
	if ((!false)) {
		JB_String* _tmP2 = JB_Incr(JB_FS_SyntaxCast(fs));
		JB_Msg_SyntaxExpect(self, _tmP2);
		JB_Decr(_tmP2);
	}
	JB_Decr(fs);
	return false;
}

Message* JB_Msg_FindFlat(Message* self, Syntax s, JB_String* name, bool Err) {
	{
		Message* ch = JB_Incr(((Message*)JB_Tree_First_(self)));
		while (ch) {
			Message* _N1 = JB_Incr(((Message*)JB_Ring_NextSib(ch)));
			if (((JB_Msg_SyntaxEqualsWithSyxBool(ch, s, false))) and ((JB_Msg_SyntaxEqualsWithStrBool(ch, name, false)))) {
				JB_Decr(_N1);
				JB_SafeDecr(ch);
				return ch;
			}
			JB_SetRef(ch, _N1);
			JB_Decr(_N1);
		};
		JB_Decr(ch);
	};
	if (Err) {
		JB_Msg_AccessErrWithSyxStr(self, s, name);
	}
	return nil;
}

Message* JB_Msg_FixTRels(Message* self, Message* Last) {
	if ((!Last)) {
	} else if ((!JB_Msg_SyntaxEqualsWithSyxBool(Last, JB_SyxTRel, false))) {
		JB_Tree_SyntaxAppend(self, Last);
	} else {
		Message* _tmP = JB_Incr(((Message*)JB_Ring_First(Last)));
		JB_Tree_SyntaxAppend(self, _tmP);
		JB_Decr(_tmP);
		(JB_Ring_FirstSet(Last, self));
		self = Last;
	}
	return self;
}

void JB_Msg_FSListArg(Message* self, FastString* fs) {
	{
		Message* ch = JB_Incr(((Message*)JB_Tree_First_(self)));
		while (ch) {
			Message* _N1 = JB_Incr(((Message*)JB_Ring_NextSib(ch)));
			JB_FS_AppendIndent(fs);
			JB_FS_SyntaxAppendWithMsg(fs, ch);
			JB_FS_AppendByte(fs, '\n');
			JB_SetRef(ch, _N1);
			JB_Decr(_N1);
		};
		JB_Decr(ch);
	};
}

void JB_Msg_FSListSep(Message* self, FastString* fs, JB_String* sep) {
	{
		Message* ch = JB_Incr(((Message*)JB_Tree_First_(self)));
		Message* _first2 = JB_Incr(ch);
		while (ch) {
			Message* _N1 = JB_Incr(((Message*)JB_Ring_NextSib(ch)));
			if (_first2 != ch) {
				JB_FS_AppendString(fs, sep);
			}
			//start;
			JB_FS_SyntaxAppendWithMsg(fs, ch);
			JB_SetRef(ch, _N1);
			JB_Decr(_N1);
		};
		JB_Decr(_first2);
		JB_Decr(ch);
	};
}

void JB_Msg_Func__(Message* self, FastString* fs) {
	Message* ch = JB_Incr(((Message*)JB_Ring_First(self)));
	if ((!ch)) {
		JB_Decr(ch);
		return;
	}
	JB_FS_SyntaxAppendWithMsg(fs, ch);
	Message* _tmP = JB_Incr(((Message*)JB_Ring_NextSib(ch)));
	JB_Decr(ch);
	JB_FS_SyntaxAppendWithMsg(fs, _tmP);
	JB_Decr(_tmP);
}

JB_String* JB_Msg_FuncName(Message* self) {
	return ({
		JB_String* _tmP280 = JB_Incr(JB_Syx_LongName(self->Func));
		JB_String* _tmP279 = JB_Incr(JB_Str_LowerCase(_tmP280));
		JB_Decr(_tmP280);
		JB_SafeDecr(_tmP279);
		 _tmP279;
	});
}

Message* JB_Msg_GoIntoInvisArg(Message* self) {
	Message* result = JB_Tk__MakeInvisArg(((Message*)JB_Ring_PrevSib(self)), self->Indent);
	JB_Tree_SyntaxAppend(result, self);
	return result;
}

bool JB_Msg_InInvisArg(Message* self) {
	Message* p = ((Message*)JB_Ring_Parent(self));
	return (JB_Msg_SyntaxEqualsWithSyxBool(p, JB_SyxArg, false)) and (JB_Msg_SyntaxEqualsWithStrBool(p, JB_str_17, false));
}

int64 JB_Msg_Int(Message* self) {
	return JB_Str_ParseInt(self->Name, self);
}

void JB_Msg_Item__(Message* self, FastString* fs) {
	Message* ch = JB_Incr(((Message*)JB_Ring_First(self)));
	if ((!ch)) {
		JB_Decr(ch);
		return;
	}
	JB_FS_SyntaxAppendWithMsg(fs, ch);
	JB_FS_AppendString(fs, JB_str_19);
	Message* _tmP = JB_Incr(((Message*)JB_Ring_NextSib(ch)));
	JB_Decr(ch);
	JB_FS_SyntaxAppendWithMsg(fs, _tmP);
	JB_Decr(_tmP);
}

Message* JB_Msg_LayerCopy(Message* self, JB_MemoryLayer* L) {
	Message* Result = JB_Incr(JB_Msg__NewWithLayerCopy(L, self));
	{
		Message* v = JB_Incr(((Message*)JB_Tree_First_(self)));
		while (v) {
			Message* _N1 = JB_Incr(((Message*)JB_Ring_NextSib(v)));
			Message* _tmP2 = JB_Incr(JB_Msg_LayerCopy(v, L));
			JB_Tree_SyntaxAppend(Result, _tmP2);
			JB_Decr(_tmP2);
			JB_SetRef(v, _N1);
			JB_Decr(_N1);
		};
		JB_Decr(v);
	};
	JB_SafeDecr(Result);
	return Result;
}

void JB_Msg_List__(Message* self, FastString* fs) {
	JB_FS_AppendByte(fs, '(');
	int count = 0;
	{
		Message* ch = ((Message*)JB_Tree_First_(self));
		while (ch) {
			Message* _N1 = ((Message*)JB_Ring_NextSib(ch));
			count++;
			if (count > 1) {
				JB_FS_AppendString(fs, JB_str_64);
			} else if ((JB_Msg_SyntaxEqualsWithSyxBool(ch, JB_SyxItem, false)) or (JB_Msg_SyntaxEqualsWithSyxBool(ch, JB_SyxDecl, false))) {
				count = 2;
			}
			JB_FS_SyntaxAppendWithMsg(fs, ch);
			ch = _N1;
		};
	};
	if (count == 1) {
		if ((!((Message*)JB_Ring_NextSib(self))) and ((JB_Msg_SyntaxEqualsWithSyxBool(((Message*)JB_Ring_Parent(self)), JB_SyxDot, false)) or (JB_Msg_SyntaxEqualsWithSyxBool(((Message*)JB_Ring_Parent(self)), JB_SyxFunc, false)))) {
		} else {
			JB_FS_AppendByte(fs, ',');
		}
	}
	JB_FS_AppendByte(fs, ')');
}

JB_String* JB_Msg_Locate(Message* self) {
	JB_String* fname = JB_Incr(JB_str_174);
	if ((!self)) {
		JB_SafeDecr(fname);
		return fname;
	}
	JB_String* s = JB_Incr(self->Name);
	if ((!(JB_Str_Exists(s)))) {
		JB_SetRef(s, JB_Msg_Render(self, nil));
	}
	if (self->Func) {
		JB_SetRef(fname, JB_Syx_Name(self->Func));
	}
	JB_String* rs = JB_Incr(JB_str_174);
	Message* _tmP1 = JB_Incr(((Message*)JB_Ring_Root(self)));
	JB_Object* r = JB_Incr(_tmP1->Obj);
	JB_Decr(_tmP1);
	if (((bool)r) and JB_Object_Isa(r, JB_AsClass(JB_String))) {
		JB_SetRef(rs, r);
	}
	JB_Decr(r);
	FastString* _fs_fs = JB_Incr(JB_FS__New());
	JB_FS_AppendString(_fs_fs, fname);
	JB_Decr(fname);
	JB_FS_AppendString(_fs_fs, JB_str_175);
	JB_FS_AppendString(_fs_fs, s);
	JB_Decr(s);
	JB_FS_AppendString(_fs_fs, JB_str_176);
	JB_FS_SyntaxAppendWithInt(_fs_fs, self->Position);
	JB_FS_AppendString(_fs_fs, JB_str_177);
	JB_FS_AppendString(_fs_fs, rs);
	JB_Decr(rs);
	JB_String* _fs_str = JB_Incr(JB_FS_SyntaxCast(_fs_fs));
	JB_SetRef(_fs_fs, nil);
	JB_Decr(_fs_fs);
	JB_SafeDecr(_fs_str);
	return _fs_str;
}

void JB_Msg_Msg__(Message* self, FastString* fs) {
	JB_FS_AppendString(fs, JB_str_75);
	JB_Msg_FSListSep(self, fs, JB_str_64);
	JB_FS_AppendString(fs, JB_str_76);
}

void JB_Msg_Name__(Message* self, FastString* fs) {
	Message* ch = JB_Incr(((Message*)JB_Ring_First(self)));
	if (ch) {
		JB_FS_AppendString(fs, self->Name);
		JB_FS_AppendString(fs, JB_str_68);
		JB_FS_SyntaxAppendWithMsg(fs, ch);
	} else {
		JB_FS_AppendByte(fs, '@');
		JB_FS_AppendString(fs, self->Name);
	}
	JB_Decr(ch);
}

Message* JB_Msg_NormalCopy(Message* self) {
	Message* Result = JB_Incr(JB_Msg__NewCopy(self));
	{
		Message* v = JB_Incr(((Message*)JB_Tree_First_(self)));
		while (v) {
			Message* _N1 = JB_Incr(((Message*)JB_Ring_NextSib(v)));
			Message* _tmP2 = JB_Incr(JB_Msg_Copy(v, false));
			JB_Tree_SyntaxAppend(Result, _tmP2);
			JB_Decr(_tmP2);
			JB_SetRef(v, _N1);
			JB_Decr(_N1);
		};
		JB_Decr(v);
	};
	JB_SafeDecr(Result);
	return Result;
}

void JB_Msg_Num__(Message* self, FastString* fs) {
	JB_FS_AppendString(fs, self->Name);
}

JB_String* JB_Msg_Nyme(Message* self) {
	if (self) {
		return self->Name;
	}
	return JB_str_0;
}

void JB_Msg_Oat__(Message* self, FastString* fs) {
	JB_FS_AppendByte(fs, '%');
	JB_Msg_RenderWithSpaces(self, fs, nil);
}

void JB_Msg_Opp__(Message* self, FastString* fs) {
	JB_FS_AppendString(fs, self->Name);
}

JB_String* JB_Msg_OriginalParseData(Message* self) {
	JB_MemoryLayer* L = JB_Msg_OriginalParseLayer(self);
	if (((bool)L) and JB_Object_Isa(L->Obj2, JB_AsClass(JB_String))) {
		return ((JB_String*)L->Obj2);
	}
	return JB_str_0;
}

JB_MemoryLayer* JB_Msg_OriginalParseLayer(Message* self) {
	if ((!self)) {
		return nil;
	}
	JB_MemoryLayer* L = JB_ObjLayer(self);
	if (((bool)L) and (L != JB_Class_DefaultLayer((JB_AsClass(Message))))) {
		return L;
	}
	return nil;
}

JB_String* JB_Msg_OriginalParsePath(Message* self) {
	JB_MemoryLayer* L = JB_Msg_OriginalParseLayer(self);
	if (((bool)L) and JB_Object_Isa(L->Obj, JB_AsClass(JB_String))) {
		return ((JB_String*)L->Obj);
	}
	return JB_str_0;
}

Message* JB_Msg_ParseAST(Message* self) {
	if ((!self)) {
		return nil;
	}
	AstUtil util = ((AstUtil){
	});
	Message* Result = JB_Incr((JB_Syx_MsgWithStr(JB_SyxArg, JB_str_0)));
	Message* _tmP = JB_Incr(((Message*)JB_Ring_First(self)));
	JB_Msg_ParseAST_(Result, _tmP, (&util));
	JB_Decr(_tmP);
	JB_AstUtil_Destructor((&util));
	JB_SafeDecr(Result);
	return Result;
}

void JB_Msg_ParseAST_(Message* self, Message* Src, AstUtil* Util) {
	if (JB_Msg_SyntaxEqualsWithSyxBool(Src, JB_SyxNum, false)) {
		self->Position = JB_Msg_Int(Src);
	} else if (JB_Msg_SyntaxEqualsWithSyxBool(Src, JB_SyxStr, false)) {
		JB_AstUtil_UseLayer(Util, Src);
	} else {
		{
			Message* MsgDesc = JB_Incr(Src);
			while (MsgDesc) {
				AstResult info = JB_AstUtil_Get(Util, MsgDesc);
				if (info.Func) {
					Message* Result = JB_Incr(JB_Msg__NewParser(self, info.Func, self->Position, info.Name));
					if (info.Children) {
						JB_Msg_ParseAST_(Result, info.Children, Util);
					}
					JB_Decr(Result);
				}
				JB_SetRef(MsgDesc, ((Message*)JB_Ring_NextSib(MsgDesc)));
			};
			JB_Decr(MsgDesc);
		};
	}
}

Message* JB_Msg_PoorAnt(Message* self) {
	if (self) {
		return ((Message*)JB_Ring_Parent(self));
	}
	return nil;
}

int JB_Msg_PrevIndentCheck(Message* self) {
	Message* pr = ((Message*)JB_Ring_PrevSib(self));
	if ((!pr)) {
		return nil;
	}
	int prin = pr->Indent;
	int chin = self->Indent;
	if ((!((prin != chin) and (prin != 255)))) {
		return nil;
	}
	int IndExtra = chin - prin;
	if (JB_int_OperatorIsMul(IndExtra, 2)) {
		if ((IndExtra > 0) and ((JB_Msg_SyntaxEqualsWithSyxBool(pr, JB_SyxTmp, false)))) {
			return IndExtra;
		} else if ((IndExtra < 0) and (JB_Msg_InInvisArg(self))) {
			return IndExtra;
		}
	}
	FastString* _fs_fs = JB_FS__New();
	JB_FS_AppendString(_fs_fs, JB_str_155);
	JB_FS_SyntaxAppendWithInt(_fs_fs, chin);
	JB_FS_AppendString(_fs_fs, JB_str_156);
	JB_String* _fs_str = JB_FS_SyntaxCast(_fs_fs);
	_fs_fs = nil;
	JB_FreeIfDead(JB_Tk__ErrorAlwaysAdd(_fs_str, self->Position));
	FastString* _fs1_fs = JB_FS__New();
	JB_FS_AppendString(_fs1_fs, JB_str_155);
	JB_FS_SyntaxAppendWithInt(_fs1_fs, prin);
	JB_FS_AppendString(_fs1_fs, JB_str_156);
	JB_String* _fs1_str = JB_FS_SyntaxCast(_fs1_fs);
	_fs1_fs = nil;
	JB_FreeIfDead(JB_Tk__ErrorAlwaysAdd(_fs1_str, pr->Position));
	return 0;
}

void JB_Msg_Rel__(Message* self, FastString* fs) {
	JB_Msg_RenderWithSpaces(self, fs, nil);
}

JB_String* JB_Msg_Render(Message* self, FastString* fs_in) {
	FastString* fs = JB_Incr(JB_FS__FastNew(fs_in));
	JB_FS_SyntaxAppendWithMsg(fs, self);
	JB_String* _tmP = JB_Incr(JB_FS_SmartResult(fs, fs_in));
	JB_Decr(fs);
	JB_SafeDecr(_tmP);
	return _tmP;
}

void JB_Msg_RenderPrm(Message* self, FastString* fs, byte b1, byte b2) {
	JB_FS_AppendByte(fs, b1);
	JB_Msg_FSListSep(self, fs, JB_str_64);
	JB_FS_AppendByte(fs, b2);
}

void JB_Msg_RenderWithSpaces(Message* self, FastString* fs, Message* ch) {
	if ((!(ch))) {
		ch = ((Message*)JB_Ring_First(self));
	}
	while (ch) {
		JB_FS_SyntaxAppendWithMsg(fs, ch);
		ch = ((Message*)JB_Ring_NextSib(ch));
		if ((!ch)) {
			return;
		}
		JB_FS_AppendByte(fs, ' ');
	};
}

void JB_Msg_SCnj__(Message* self, FastString* fs) {
	JB_FS_AppendString(fs, self->Name);
}

void JB_Msg_SCom__(Message* self, FastString* fs) {
	Message* ch = JB_Incr(((Message*)JB_Ring_First(self)));
	Message* _tmP = JB_Incr(((Message*)JB_Ring_NextSib(ch)));
	JB_FS_SyntaxAppendWithMsg(fs, _tmP);
	JB_Decr(_tmP);
	JB_FS_AppendString(fs, JB_str_69);
	if (JB_Tree_HasOneChild(ch)) {
		Message* _tmP1 = JB_Incr(((Message*)JB_Ring_First(ch)));
		JB_FS_SyntaxAppendWithMsg(fs, _tmP1);
		JB_Decr(_tmP1);
	} else {
		JB_FS_AppendByte(fs, '\n');
		JB_Msg_FSListArg(ch, fs);
	}
	JB_Decr(ch);
	JB_FS_AppendString(fs, JB_str_70);
}

void JB_Msg_SDot__(Message* self, FastString* fs) {
	JB_FS_AppendByte(fs, '.');
	JB_FS_AppendString(fs, self->Name);
	Message* _tmP = JB_Incr(((Message*)JB_Ring_First(self)));
	JB_FS_SyntaxAppendWithMsg(fs, _tmP);
	JB_Decr(_tmP);
}

void JB_Msg_Sheb__(Message* self, FastString* fs) {
	JB_FS_AppendString(fs, JB_str_71);
	JB_FS_AppendString(fs, self->Name);
}

void JB_Msg_SOpp__(Message* self, FastString* fs) {
	JB_FS_AppendString(fs, self->Name);
}

void JB_Msg_SStr__(Message* self, FastString* fs) {
	if (JB_int_Found(JB_Str_InStr(self->Name, JB_str_65, 0, kJB__int_max, false))) {
		JB_Msg_Str__(self, fs);
	} else {
		JB_FS_AppendString(fs, JB_str_66);
		JB_FS_AppendString(fs, self->Name);
		JB_FS_AppendString(fs, JB_str_65);
	}
}

void JB_Msg_SThg__(Message* self, FastString* fs) {
	JB_FS_AppendString(fs, self->Name);
}

void JB_Msg_Str__(Message* self, FastString* fs) {
	JB_FS_AppendByte(fs, '"');
	JB_FS_AppendEscape(fs, self->Name);
	{
		Message* ch = JB_Incr(((Message*)JB_Tree_First_(self)));
		while (ch) {
			Message* _N1 = JB_Incr(((Message*)JB_Ring_NextSib(ch)));
			if (JB_Msg_SyntaxEqualsWithSyxBool(ch, JB_SyxEmb, false)) {
				JB_FS_AppendEscape(fs, ch->Name);
			} else {
				JB_FS_AppendByte(fs, '$');
				JB_FS_AppendByte(fs, '{');
				JB_FS_SyntaxAppendWithMsg(fs, ch);
				JB_FS_AppendByte(fs, '}');
			}
			JB_SetRef(ch, _N1);
			JB_Decr(_N1);
		};
		JB_Decr(ch);
	};
	JB_FS_AppendByte(fs, '"');
}

bool JB_Msg_SyntaxEqualsWithStrBool(Message* self, JB_String* name, bool Aware) {
	return ((bool)self) and JB_Str_Equals(self->Name, name, Aware);
}

bool JB_Msg_SyntaxEqualsWithSyxBool(Message* self, Syntax X, bool Aware) {
	return ((bool)self) and (self->Func == X);
}

void JB_Msg_SyntaxExpect(Message* self, JB_String* Error) {
	JB_Incr(Error);
	if (JB_Str_Exists(Error)) {
	} else if ((bool)self) {
		FastString* _fs_fs = JB_Incr(JB_FS__New());
		JB_FS_AppendString(_fs_fs, JB_str_107);
		JB_String* _tmP1 = JB_Incr(JB_Msg_FuncName(self));
		JB_FS_AppendString(_fs_fs, _tmP1);
		JB_Decr(_tmP1);
		JB_FS_AppendString(_fs_fs, JB_str_108);
		JB_String* _tmP2 = JB_Incr(JB_Msg_Render(self, nil));
		JB_FS_AppendString(_fs_fs, _tmP2);
		JB_Decr(_tmP2);
		JB_FS_AppendString(_fs_fs, JB_str_109);
		JB_String* _fs_str = JB_Incr(JB_FS_SyntaxCast(_fs_fs));
		JB_SetRef(_fs_fs, nil);
		JB_Decr(_fs_fs);
		JB_SetRef(Error, _fs_str);
		JB_Decr(_fs_str);
	} else {
		debugger;
		JB_SetRef(Error, JB_str_94);
	}
	JB_Rec_NewItemWithNode(JB_StdErr, self, Error);
	JB_Decr(Error);
}

void JB_Msg_Test(Message* self, JB_String* new_render, JB_String* name) {
	if ((!(JB_Msg_TestSub(self, new_render, name)))) {
		FastString* _fs_fs = JB_Incr(JB_FS__New());
		JB_FS_AppendString(_fs_fs, JB_str_180);
		JB_FS_AppendString(_fs_fs, name);
		JB_FS_AppendString(_fs_fs, JB_str_181);
		JB_FS_AppendString(_fs_fs, new_render);
		JB_String* _fs_str = JB_Incr(JB_FS_SyntaxCast(_fs_fs));
		JB_SetRef(_fs_fs, nil);
		JB_Decr(_fs_fs);
		JB_Str_Print(_fs_str);
		JB_Decr(_fs_str);
	}
}

bool JB_Msg_TestSub(Message* self, JB_String* new_render, JB_String* name) {
	if ((!(JB_Str_Exists(new_render)))) {
		return nil;
	}
	LeakTester* LKT = JB_Incr(JB_Lk__New(name));
	{
		Message* reparse = JB_Incr(JB_Str_ParseAs(new_render, name));
		if ((!reparse)) {
			JB_Decr(LKT);
			JB_Decr(reparse);
			return nil;
		}
		if ((!JB_Msg_TreeCompare(self, reparse))) {
			JB_Decr(LKT);
			JB_Decr(reparse);
			return nil;
		}
		JB_String* self_render = JB_Incr(JB_Msg_Render(self, nil));
		if ((!JB_Str_Exists(self_render))) {
			JB_Decr(LKT);
			JB_Decr(reparse);
			JB_Decr(self_render);
			return nil;
		}
		JB_String* reparse_render = JB_Incr(JB_Msg_Render(reparse, nil));
		JB_Decr(reparse);
		if ((!JB_Str_Exists(reparse_render))) {
			JB_Decr(LKT);
			JB_Decr(self_render);
			JB_Decr(reparse_render);
			return nil;
		}
		if ((!(JB_Rec_OK(JB_StdErr) and ((JB_Str_SyntaxEquals(self_render, reparse_render, false)))))) {
			JB_Decr(LKT);
			JB_Decr(self_render);
			JB_Decr(reparse_render);
			return nil;
		}
		JB_Decr(reparse_render);
		JB_Decr(self_render);
	};
	(JB_Lk_FinalTest(LKT));
	JB_Decr(LKT);
	return true;
}

void JB_Msg_Thg__(Message* self, FastString* fs) {
	JB_FS_AppendString(fs, self->Name);
}

void JB_Msg_Tmp__(Message* self, FastString* fs) {
	JB_FS_AppendString(fs, self->Name);
	if ((!JB_Ring_HasChildren(self))) {
		return;
	}
	JB_FS_AppendByte(fs, ' ');
	JB_Msg_RenderWithSpaces(self, fs, nil);
}

void JB_Msg_Todo__(Message* self, FastString* fs) {
	JB_FS_AppendString(fs, self->Name);
	JB_Msg_FSListSep(self, fs, JB_str_15);
}

bool JB_Msg_TreeCompare(Message* self, Message* other) {
	if ((!(((bool)self) and ((bool)other)))) {
		return JB_CompareError(self, other);
	}
	if ((self->Func != other->Func) or ((!JB_Str_SyntaxEquals(self->Name, other->Name, true)))) {
		return JB_CompareError(self, other);
	}
	Message* o1 = JB_Incr(((Message*)JB_Ring_First(other)));
	Message* m1 = JB_Incr(((Message*)JB_Ring_First(self)));
	while (((bool)o1) or ((bool)m1)) {
		if ((!JB_Msg_TreeCompare(m1, o1))) {
			JB_Decr(o1);
			JB_Decr(m1);
			return nil;
		}
		JB_SetRef(o1, ((Message*)JB_Ring_NextSib(o1)));
		JB_SetRef(m1, ((Message*)JB_Ring_NextSib(m1)));
	};
	JB_Decr(m1);
	JB_Decr(o1);
	return true;
}

void JB_Msg_TRel__(Message* self, FastString* fs) {
	JB_Msg_RenderWithSpaces(self, fs, nil);
}

void JB_Msg_Type__(Message* self, FastString* fs) {
	Message* ch = JB_Incr(((Message*)JB_Ring_First(self)));
	if ((!ch)) {
		JB_Decr(ch);
		return;
	}
	JB_FS_SyntaxAppendWithMsg(fs, ch);
	JB_FS_AppendByte(fs, '|');
	JB_SetRef(ch, ((Message*)JB_Ring_NextSib(ch)));
	if (ch) {
		JB_FS_SyntaxAppendWithMsg(fs, ch);
	}
	JB_Decr(ch);
	JB_FS_AppendByte(fs, '|');
}

void JB_Msg_UnEmbed(Message* self) {
	Message* s1 = JB_Incr(((Message*)JB_Ring_First(self)));
	if ((!((JB_Msg_SyntaxEqualsWithSyxBool(s1, JB_SyxEmb, false)) and (!JB_FreeIfDead(((Message*)JB_Ring_NextSib(s1))))))) {
		JB_Decr(s1);
		return;
	}
	JB_Tree_Remove(s1);
	JB_SetRef(self->Name, s1->Name);
	JB_Decr(s1);
}

void JB_Msg_Unit__(Message* self, FastString* fs) {
	Message* _tmP = JB_Incr(((Message*)JB_Ring_First(self)));
	JB_String* num = JB_Incr(_tmP->Name);
	JB_Decr(_tmP);
	JB_FS_AppendString(fs, num);
	if (((bool)JB_Str_IsHexLike(num, 0)) and (JB_Str_Last(num) != '_')) {
		JB_FS_AppendByte(fs, '_');
	}
	JB_Decr(num);
	JB_FS_AppendString(fs, self->Name);
}

void JB_Msg_Yoda__(Message* self, FastString* fs) {
	Message* _tmP = JB_Incr(((Message*)JB_Ring_Last(self)));
	JB_FS_SyntaxAppendWithMsg(fs, _tmP);
	JB_Decr(_tmP);
	JB_FS_AppendString(fs, JB_str_73);
	Message* _tmP1 = JB_Incr(((Message*)JB_Ring_First(self)));
	JB_FS_SyntaxAppendWithMsg(fs, _tmP1);
	JB_Decr(_tmP1);
	JB_FS_AppendByte(fs, ' ');
	Message* _tmP2 = JB_Incr(({
		Message* _tmP274 = JB_Incr(((Message*)JB_Ring_First(self)));
		Message* _tmP273 = JB_Incr(((Message*)JB_Ring_NextSib(_tmP274)));
		JB_Decr(_tmP274);
		JB_SafeDecr(_tmP273);
		 _tmP273;
	}));
	JB_FS_SyntaxAppendWithMsg(fs, _tmP2);
	JB_Decr(_tmP2);
}

void JB_Msg_Yopp__(Message* self, FastString* fs) {
}

Message* JB_Msg__Alloc() {
	return ((Message*)JB_New(Message));
}

SyntaxObj* JB_Msg__GetSyx(Message* msg) {
	SyntaxObj* _tmP = JB_Incr(((SyntaxObj*)JB_Dict_Syntax(JB__SyxDict_, msg->Name)));
	if ((!_tmP)) {
		FastString* _fs1_fs = JB_Incr(JB_FS__New());
		JB_FS_AppendString(_fs1_fs, JB_str_62);
		JB_FS_AppendString(_fs1_fs, msg->Name);
		JB_String* _fs1_str = JB_Incr(JB_FS_SyntaxCast(_fs1_fs));
		JB_SetRef(_fs1_fs, nil);
		JB_Decr(_fs1_fs);
		JB_Msg_SyntaxExpect(msg, _fs1_str);
		JB_Decr(_fs1_str);
		JB_Decr(_tmP);
		return nil;
	}
	JB_SafeDecr(_tmP);
	return _tmP;
}

Message* JB_Msg__LayerAlloc(JB_MemoryLayer* _L) {
	return ((Message*)JB_LayerNew(_L, Message));
}

Message* JB_Msg__NewCopy(Message* other) {
	Message* Result = JB_Msg__Alloc();
	if (Result) {
		JB_Msg_ConstructorCopy(Result, other);
	}
	return Result;
}

Message* JB_Msg__NewWithSyxStr(Syntax Func, JB_String* Name) {
	Message* Result = JB_Msg__Alloc();
	if (Result) {
		JB_Msg_ConstructorWithSyxStr(Result, Func, Name);
	}
	return Result;
}

Message* JB_Msg__NewParser(Message* Parent, Syntax Func, int BytePos, JB_String* Name) {
	Message* Result = JB_Msg__Alloc();
	if (Result) {
		JB_Msg_ConstructorParser(Result, Parent, Func, BytePos, Name);
	}
	return Result;
}

Message* JB_Msg__NewWithLayerCopy(JB_MemoryLayer* _L, Message* other) {
	Message* Result = JB_Msg__LayerAlloc(_L);
	if (Result) {
		JB_Msg_ConstructorCopy(Result, other);
	}
	return Result;
}



//// API START! ////

#pragma GCC visibility push(default)
__lib__ JB_String* jb_msg_name(Message* self) {
	if ((!JB_Msg_NilCheck(self))) {
		return nil;
	}
	return self->Name;
	return JB_str_0;
}

__lib__ Syntax jb_msg_func(Message* self) {
	if ((!JB_Msg_NilCheck(self))) {
		return nil;
	}
	return self->Func;
	return nil;
}

__lib__ int jb_msg_position(Message* self) {
	if ((!JB_Msg_NilCheck(self))) {
		return nil;
	}
	return self->Position;
	return 0;
}

__lib__ _voidptr jb_msg_tag(Message* self) {
	if ((!JB_Msg_NilCheck(self))) {
		return nil;
	}
	return ((_voidptr)self->Obj);
	return nil;
}

__lib__ void jb_msg_nameset(Message* self, JB_String* Result) {
	if ((!JB_Msg_NilCheck(self))) {
		return;
	}
	JB_SetRef(self->Name, Result);
}

__lib__ void jb_msg_funcset(Message* self, Syntax Result) {
	if ((!JB_Msg_NilCheck(self))) {
		return;
	}
	self->Func = Result;
}

__lib__ void jb_msg_positionset(Message* self, int Result) {
	if ((!JB_Msg_NilCheck(self))) {
		return;
	}
	self->Position = Result;
}

__lib__ void jb_msg_tagset(Message* self, _voidptr Result) {
	if ((!JB_Msg_NilCheck(self))) {
		return;
	}
	self->Obj = ((JB_Object*)Result);
}

__lib__ void jb_msg_firstset(Message* self, Message* Result) {
	if ((!JB_Msg_NilCheck(self))) {
		return;
	}
	(JB_Ring_FirstSet(self, Result));
}

__lib__ void jb_msg_lastset(Message* self, Message* Result) {
	if ((!JB_Msg_NilCheck(self))) {
		return;
	}
	(JB_Ring_LastSet(self, Result));
}

__lib__ void jb_msg_prevset(Message* self, Message* Result) {
	if ((!JB_Msg_NilCheck(self))) {
		return;
	}
	(JB_Ring_PrevSibSet(self, Result));
}

__lib__ void jb_msg_nextset(Message* self, Message* Result) {
	if ((!JB_Msg_NilCheck(self))) {
		return;
	}
	(JB_Ring_NextSibSet(self, Result));
}

__lib__ Message* jb_msg_first(Message* self) {
	if ((!JB_Msg_NilCheck(self))) {
		return nil;
	}
	return ((Message*)JB_Ring_First(self));
	return nil;
}

__lib__ Message* jb_msg_last(Message* self) {
	if ((!JB_Msg_NilCheck(self))) {
		return nil;
	}
	return ((Message*)JB_Ring_Last(self));
	return nil;
}

__lib__ Message* jb_msg_prev(Message* self) {
	if ((!JB_Msg_NilCheck(self))) {
		return nil;
	}
	return ((Message*)JB_Ring_PrevSib(self));
	return nil;
}

__lib__ Message* jb_msg_next(Message* self) {
	if ((!JB_Msg_NilCheck(self))) {
		return nil;
	}
	return ((Message*)JB_Ring_NextSib(self));
	return nil;
}

__lib__ Message* jb_msg_parent(Message* self) {
	if ((!JB_Msg_NilCheck(self))) {
		return nil;
	}
	return ((Message*)JB_Ring_Parent(self));
	return nil;
}

__lib__ Message* jb_msg_flatnext(Message* self) {
	if ((!JB_Msg_NilCheck(self))) {
		return nil;
	}
	return ((Message*)JB_Ring_FlatNext0(self));
	return nil;
}

__lib__ Message* jb_msg_flatafter(Message* self) {
	if ((!JB_Msg_NilCheck(self))) {
		return nil;
	}
	return ((Message*)JB_Ring_FlatAfter(self));
	return nil;
}

__lib__ Message* jb_msg_root(Message* self) {
	if ((!JB_Msg_NilCheck(self))) {
		return nil;
	}
	return ((Message*)JB_Ring_Root(self));
	return nil;
}

__lib__ void jb_msg_remove(Message* self) {
	if ((!JB_Msg_NilCheck(self))) {
		return;
	}
	JB_Tree_Remove(self);
}

__lib__ JB_String* jb_msg_render(Message* self) {
	if ((!JB_Msg_NilCheck(self))) {
		return nil;
	}
	return JB_Msg_Render(self, nil);
	return JB_str_0;
}

__lib__ JB_String* jb_msg_ast(Message* self) {
	if ((!JB_Msg_NilCheck(self))) {
		return nil;
	}
	return JB_Msg_AST(self, nil);
	return JB_str_0;
}

__lib__ Message* jb_msg_parseast(Message* self) {
	if ((!JB_Msg_NilCheck(self))) {
		return nil;
	}
	return JB_Msg_ParseAST(self);
	return nil;
}

__lib__ Message* jb_msg_copy(Message* self) {
	if ((!JB_Msg_NilCheck(self))) {
		return nil;
	}
	return JB_Msg_Copy(self, false);
	return nil;
}

__lib__ Message* jb_msg_create(Message* self, Syntax Type, JB_String* Name) {
	if ((!JB_Syx_NilCheck(Type))) {
		return nil;
	}
	return JB_Syx_Msg(Type, self, Name);
	return nil;
}

__lib__ void jb_msg_error(Message* self, JB_String* ErrorMsg) {
	if ((!JB_Msg_NilCheck(self))) {
		return;
	}
	JB_Rec_NewItemWithNode(JB_StdErr, self, ErrorMsg);
}

__lib__ Message* jb_msg_expect(Message* self, Syntax Type, JB_String* name, Message* ErrPlace) {
	if (self) {
		if (JB_Msg_Expect(self, Type, name)) {
			return self;
		}
	} else if ((bool)ErrPlace) {
		JB_Msg_AccessErrWithSyxStr(ErrPlace, Type, name);
	}
	return nil;
}

__lib__ Message* jb_msg_access(Message* self, Syntax Type, JB_String* name, bool IsError) {
	return JB_Msg_FindFlat(self, Type, name, IsError);
}

__lib__ JB_String* jb_syx_name(Syntax self) {
	if ((!JB_Syx_NilCheck(self))) {
		return nil;
	}
	return JB_Syx_Name(self);
	return JB_str_0;
}

__lib__ JB_String* jb_syx_longname(Syntax self) {
	if ((!JB_Syx_NilCheck(self))) {
		return nil;
	}
	return JB_Syx_LongName(self);
	return JB_str_0;
}

__lib__ _cstring jb_string_address(JB_String* self) {
	if ((!(JB_Str_Exists(self)))) {
		return nil;
	}
	return ((_cstring)JB_Str_Address(self));
}

__lib__ int jb_string_length(JB_String* self) {
	return JB_Str_Length(self);
	return 0;
}

__lib__ JB_String* jb_string_copy(JB_String* self) {
	return JB_Str_Copy(self);
	return JB_str_0;
}

__lib__ Message* jb_string_parse(JB_String* self, JB_String* path) {
	if ((!(JB_Str_Exists(self)))) {
		return nil;
	}
	return JB_API__Parse(self, path);
	return nil;
}

__lib__ JB_String* jb_string_escape(JB_String* self) {
	return JB_Str_Escape(self);
	return JB_str_0;
}

__lib__ void jb_string_print(JB_String* self) {
	JB_Str_Print(self);
}

__lib__ void jb_string_printline(JB_String* self) {
	JB_Str_PrintLine(self);
}

__lib__ int64 jb_string_int(JB_String* self, Message* m) {
	return JB_Str_TextIntegerValid(self, m);
	return 0;
}

__lib__ double jb_string_float(JB_String* self, Message* m) {
	return JB_Str_TextDouble(self, m);
	return 0;
}

__lib__ Syntax jb_syntax(JB_String* name) {
	SyntaxObj* _tmP = JB_Incr(((SyntaxObj*)JB_Dict_SyntaxAccessWithStr(JB__SyxDict_, name)));
	if ((!_tmP)) {
		JB_Decr(_tmP);
		return nil;
	}
	Syntax _tmP1 = _tmP->ID;
	JB_Decr(_tmP);
	return _tmP1;
	return nil;
}

__lib__ JB_String* jb_str(_cstring Str, int Length, _voidptr Release, _voidptr Tag) {
	if ((!Str) or (Length < 0)) {
		return JB_str_0;
	}
	if ((!(Length))) {
		Length = strlen(Str);
	}
	return JB_StrFromPtr(Str, Length, Release, Tag);
	return JB_str_0;
}

__lib__ JB_String* jb_cstr(_cstring Str) {
	if (Str) {
		return JB_StrFromPtr(Str, strlen(Str), nil, nil);
	}
	return JB_str_0;
}

__lib__ void jb_delete_(JB_Object* obj) {
	JB_Delete(((FreeObject*)obj));
}

__lib__ Message* jb_errors() {
	return JB_API__errors();
	return nil;
}

__lib__ bool jb_ok() {
	return JB_Rec_OK(JB_StdErr);
	return false;
}

__lib__ void jb_debug(JB_Object* o) {
	jdb(o);
}

__lib__ int jb_init(int Flags) {
	return JB_API__Init(Flags);
	return 0;
}

__lib__ int jb_shutdown() {
	JB_StdErr = nil;
	return JB_LibShutdown();
	return 0;
}

__lib__ int jb_version() {
	return (2019111110);
}

__lib__ JB_String* jb_readfile(_cstring path, bool AllowMissingFile) {
	JB_API__Init(0);
	return JB_cPath_ReadAll(path, AllowMissingFile, 100000000);
	return JB_str_0;
}

#pragma GCC visibility pop
//// API END! ////
}

// -2991435863749934684 6998272850980524272