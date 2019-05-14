
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
//


u16 JB__API_NilHappened;
//


ByteMap* JB__Constants_CSAfterTemporal;
ByteMap* JB__Constants_CSLine;
ByteMap* JB__Constants_CSLineBlack;
ByteMap* JB__Constants_CSNum;
ByteMap* JB__Constants_CSNumUnit;
ByteMap* JB__Constants_CSWordMiddle;
ByteMap* JB__Constants_CSWordStart;
Dictionary* JB__Constants_EscapeChr;
Dictionary* JB__Constants_EscapeStr;
Dictionary* JB__Constants_UnEscapeStr;
//


//


int JB__Tk_BaseMessagePosition;
Message* JB__Tk_ErrNode;
Dictionary* JB__Tk_ErrorNames;
int JB__Tk_StopBars;
//


Array* JB_FuncArray;
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
JB_String* JB_str_14;
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
JB_String* JB_str_27;
JB_String* JB_str_28;
JB_String* JB_str_29;
JB_String* JB_str_3;
JB_String* JB_str_30;
JB_String* JB_str_31;
JB_String* JB_str_32;
JB_String* JB_str_33;
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
__lib__ Syntax* JB_SyxAcc;
__lib__ Syntax* JB_SyxAdj;
__lib__ Syntax* JB_SyxAna;
__lib__ Syntax* JB_SyxARel;
__lib__ Syntax* JB_SyxArg;
__lib__ Syntax* JB_SyxArr;
__lib__ Syntax* JB_SyxBack;
__lib__ Syntax* JB_SyxBin;
__lib__ Syntax* JB_SyxBra;
__lib__ Syntax* JB_SyxBRel;
__lib__ Syntax* JB_SyxChar;
__lib__ Syntax* JB_SyxCnj;
__lib__ Syntax* JB_SyxDecl;
Dictionary* JB_SyxDict;
__lib__ Syntax* JB_SyxDot;
__lib__ Syntax* JB_SyxEmb;
__lib__ Syntax* JB_SyxERel;
__lib__ Syntax* JB_SyxFunc;
__lib__ Syntax* JB_SyxItem;
__lib__ Syntax* JB_SyxList;
__lib__ Syntax* JB_SyxName;
__lib__ Syntax* JB_SyxNum;
__lib__ Syntax* JB_SyxOat;
__lib__ Syntax* JB_SyxOpp;
__lib__ Syntax* JB_SyxPrm;
__lib__ Syntax* JB_SyxRel;
__lib__ Syntax* JB_SyxSCnj;
__lib__ Syntax* JB_SyxSCom;
__lib__ Syntax* JB_SyxSDot;
__lib__ Syntax* JB_SyxSheb;
__lib__ Syntax* JB_SyxSOpp;
__lib__ Syntax* JB_SyxSStr;
__lib__ Syntax* JB_SyxSThg;
__lib__ Syntax* JB_SyxStr;
__lib__ Syntax* JB_SyxThg;
__lib__ Syntax* JB_SyxTmp;
__lib__ Syntax* JB_SyxTRel;
__lib__ Syntax* JB_SyxType;
__lib__ Syntax* JB_SyxUnit;
//


//


Dictionary* JB__Loader_ClassList;
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


//


//


FastString* JB__FS_StdOutFS;
//


//


//


//


bool JB__FAP_Tested;
//


//


inline bool JB_int_Found(int self) {
	return self >= 0;
}

inline bool JB_Obj_NilCheck(JB_Object* self) {
	if (self) {
		return true;
	}
	return JB_API__NilHandler();
}

inline bool JB_DictionaryReader_SyntaxCastBool(DictionaryReader* self) {
	return JB_Nav_MoveNext(self);
}

inline JB_String* JB_FS_SyntaxCastString(FastString* self) {
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








Message* JB_API__errors() {
	if (JB_Rec_OK(JB_StdErr)) {
		return nil;
	}
	Message* result = JB_Fn_Msg(JB_SyxList, JB_str_0);
	{
		LLRef _LoopSrc2 = JB_StdErr->List;
		JB_Error* err = (JB_Error*)(_LoopSrc2.First);
		while (err) {
			JB_LinkedList_ListSanity(err);
			JB_Error* _N1 = (JB_Error*)(err->_Next);
			Message* node = JB_Fn_MsgParent(JB_SyxStr, result, JB_Err_Render(err, nil));
			node->Position = err->Position;
			err = _N1;
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
	JB_String* msg = JB_Constants__Test();
	JB_Incr(msg);
	if ((!(((bool)(flags & 1))))) {
		JB_Str_PrintLine(msg);
	}
	JB_Decr(msg);
	if ((!JB_Rec_OK(JB_StdErr))) {
		JB_Error* err = (JB_Error*)(JB_StdErr->List.First);
		JB_Incr(err);
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
		JB_API__NilCallBack(JB_str_47);
	} else if (JB__API_NilHappened == 16) {
		JB_API__NilCallBack(JB_str_48);
	}
	return false;
}

Message* JB_API__Parse(JB_String* s, JB_String* path) {
	if ((!(s != nil))) {
		return nil;
	}
	JB_MemoryLayer* L = JB_Mem_UseNewLayer((JB_AsClass(Message)), path);
	JB_Incr(L);
	JB_SetRef(L->Obj2, s);
	Message* Result = JB_Str_Parse(s, nil);
	JB_Incr(Result);
	JB_ClassData_Restore((JB_AsClass(Message)));
	if ((!L)) {
	}
	JB_Decr(L);
	JB_SafeDecr(Result);
	return Result;
}


int JB_Constants__Init_() {
	{
		JB_SetRef(JB__Constants_EscapeStr, JB_Dict__New());
		(JB_Dict_ValueSet(JB__Constants_EscapeStr, JB_str_173, JB_str_174));
		(JB_Dict_ValueSet(JB__Constants_EscapeStr, JB_str_15, JB_str_70));
		(JB_Dict_ValueSet(JB__Constants_EscapeStr, JB_str_175, JB_str_176));
		(JB_Dict_ValueSet(JB__Constants_EscapeStr, JB_str_112, JB_str_177));
		(JB_Dict_ValueSet(JB__Constants_EscapeStr, JB_str_14, JB_str_178));
		(JB_Dict_ValueSet(JB__Constants_EscapeStr, JB_str_85, JB_str_179));
		(JB_Dict_ValueSet(JB__Constants_EscapeStr, JB_str_180, JB_str_181));
		(JB_Dict_ValueSet(JB__Constants_EscapeStr, JB_str_182, JB_str_183));
		JB_SetRef(JB__Constants_UnEscapeStr, JB_Dict_Reverse(JB__Constants_EscapeStr));
		JB_SetRef(JB__Constants_EscapeChr, JB_Dict_Copy(JB__Constants_EscapeStr));
		(JB_Dict_ValueSet(JB__Constants_EscapeChr, JB_str_112, ((JB_String*)nil)));
		(JB_Dict_ValueSet(JB__Constants_UnEscapeStr, JB_str_174, ((JB_String*)nil)));
		(JB_Dict_ValueSet(JB__Constants_UnEscapeStr, JB_str_180, JB_str_0));
		(JB_Dict_ValueSet(JB__Constants_EscapeStr, JB_str_14, ((JB_String*)nil)));
		(JB_Dict_ValueSet(JB__Constants_EscapeStr, JB_str_123, JB_str_184));
		JB_MSR_EscapeCodeSet(JB__Constants_UnEscapeStr, true);
		JB_MSR_DecodeEntitySet(JB__Constants_UnEscapeStr, true);
		JB_SetRef(JB__Constants_CSWordMiddle, JB_Str_Charset(JB_str_185, true));
		JB_SetRef(JB__Constants_CSWordStart, JB_Str_Charset(JB_str_186, true));
		JB_SetRef(JB__Constants_CSNum, JB__Constants_CSWordMiddle);
		JB_SetRef(JB__Constants_CSLine, JB_Str_Charset(JB_str_187, false));
		JB_SetRef(JB__Constants_CSAfterTemporal, JB_Str_Charset(JB_str_188, false));
		JB_SetRef(JB__Constants_CSLineBlack, JB_Str_Charset(JB_str_189, false));
		JB_SetRef(JB__Constants_CSNumUnit, JB_Str_Charset(JB_str_190, true));
	};
	return 0;
}

JB_String* JB_Constants__Test() {
	FastString* fs = JB_FS__New();
	JB_Incr(fs);
	{
		int c = 0;
		while (c < 256) {
			JB_FS_AppendByte(fs, ((byte)c));
			c++;
		};
	};
	JB_String* str = JB_FS_GetResult(fs);
	JB_Incr(str);
	JB_Decr(fs);
	JB_String* _tmp331 = JB_Str_Unescape(JB_Str_Escape(str));
	JB_Incr(_tmp331);
	if ((!(JB_Str_SyntaxEquals(_tmp331, str, false)))) {
		JB_Object_SyntaxExpect(nil);
		JB_Decr(str);
		JB_Decr(_tmp331);
		return nil;
	}
	JB_Decr(_tmp331);
	JB_BinaryEscapeTest(str);
	JB_Decr(str);
	if ((!JB_Rec_OK(JB_StdErr))) {
		return nil;
	}
	JB_String* natural_input = JB_str_159;
	JB_Incr(natural_input);
	JB_String* list_input = JB_str_160;
	JB_Incr(list_input);
	if ((!JB_TestCasting())) {
		debugger;
	}
	int i1 = JB_Str_InWhite(JB_str_74, 0, kJB__int_max);
	if (i1 != 3) {
		debugger;
	}
	int i2 = JB_Str_OutWhite(JB_str_161, 0, kJB__int_max);
	if (JB_int_Found(i2)) {
		debugger;
	}
	int i3 = JB_Str_OutWhite(JB_str_162, 0, kJB__int_max);
	if ((!JB_int_Found(i3))) {
		debugger;
	}
	int i4 = JB_Str_InWhite(JB_str_163, JB_Str_Length(JB_str_163), 1);
	if (i4 != 1) {
		debugger;
	}
	JB_String* x = JB_Str_UpperCase(JB_str_155);
	JB_Incr(x);
	JB_Decr(x);
	LeakTester* LKT = JB_Lk__New(JB_str_164);
	JB_Incr(LKT);
	JB_FreeIfDead(JB_EntityTest());
	JB_Lk_FinalTest(LKT);
	JB_Decr(LKT);
	if ((!JB_Rec_OK(JB_StdErr))) {
		JB_Decr(natural_input);
		JB_Decr(list_input);
		return nil;
	}
	if (JB_Str_Exists(list_input)) {
		Message* root = JB_Str_Parse(natural_input, nil);
		JB_Incr(root);
		if ((!root)) {
			JB_Decr(natural_input);
			JB_Decr(list_input);
			JB_Decr(root);
			return nil;
		}
		Message* _tmp332 = JB_Msg_Copy(root, false);
		JB_Incr(_tmp332);
		JB_Msg_TreeCompare(root, _tmp332);
		JB_Decr(_tmp332);
		Message* _tmp333 = JB_Str_Parse(list_input, nil);
		JB_Incr(_tmp333);
		Message* list = JB_Msg_ParseReadable(_tmp333);
		JB_Incr(list);
		JB_Decr(_tmp333);
		JB_Msg_TreeCompare(root, list);
		JB_Decr(list);
		JB_String* _tmp334 = JB_Msg_Render(root, nil);
		JB_Incr(_tmp334);
		JB_Msg_Test(root, _tmp334, JB_str_155);
		JB_Decr(_tmp334);
		JB_String* _tmp335 = JB_Msg_MakeReadable(root, nil);
		JB_Incr(_tmp335);
		JB_Msg_Test(root, _tmp335, JB_str_156);
		JB_Decr(_tmp335);
		JB_Decr(root);
	} else {
		Message* root = JB_Str_Parse(natural_input, nil);
		JB_Incr(root);
		if ((!root)) {
			JB_Decr(natural_input);
			JB_Decr(list_input);
			JB_Decr(root);
			return nil;
		}
		JB_String* R = JB_Msg_Render(root, nil);
		JB_Incr(R);
		JB_Msg_Test(root, R, JB_str_155);
		JB_Decr(root);
		JB_Str_Print(JB_str_165);
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




Message* JB_Tk__BarThings(int Start, Syntax* Syx) {
	JB__Tk_StopBars = (kJB__Tk_FuncAfterBar | kJB__Tk_TemporalSyx);
	Message* item = JB_Tk__ProcessThing(kJB__Tk_Opp, 0);
	JB_Incr(item);
	if ((!item)) {
		JB_SetRef(item, JB_Tk__NewParent0(nil, JB_SyxEmb, Start));
	} else if (JB_Tk__Allow(kJB__Tk_colon)) {
		JB_SetRef(item, JB_Tk__ParseItem(item, 0));
	}
	JB__Tk_StopBars = 0;
	if ((!JB_Tk__ExpectEndChar('|', true))) {
		JB_Decr(item);
		return nil;
	}
	Message* Result = JB_Tk__NewParent0(nil, Syx, JB_Tk__NextStart() - 1);
	JB_Incr(Result);
	JB_Tree_SyntaxAppend(Result, item);
	JB_Decr(item);
	JB_SafeDecr(Result);
	return Result;
}

Message* JB_Tk__BeforeRelSub(int Start, int Mode) {
	Message* Result = JB_Tk__NewParent(nil, JB_SyxBRel, Start, JB_Tk__NextStart());
	JB_Incr(Result);
	Message* Thg = JB_Tk__ProcessThing(0, Mode);
	JB_Incr(Thg);
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
	Message* Result = JB_Tk__NewParent0(nil, JB_SyxTRel, opp->Position);
	JB_Incr(Result);
	JB_Tree_SyntaxAppend(Result, FirstThing);
	JB_Tree_SyntaxAppend(Result, opp);
	if ((!JB_Tk__WillEnd())) {
		Message* Last = JB_Tk__ProcessThing(kJB__Tk_Opp, 0);
		JB_Incr(Last);
		if (Last) {
			Message* _tmp294 = JB_Msg_FixTRels(Result, Last);
			JB_Incr(_tmp294);
			JB_Decr(Result);
			JB_Decr(Last);
			JB_SafeDecr(_tmp294);
			return _tmp294;
		}
		JB_Decr(Last);
	}
	JB_SafeDecr(Result);
	return Result;
}

bool JB_Tk__ConsumeLines(Message* output, Message* msg) {
	JB_Incr(msg);
	bool result = false;
	while (true) {
		Message* line = JB_Tk__Process(kJB__Tk_EndOfLine | kJB__Tk_SyntacticComment, kJB__Tk_Allow);
		JB_Incr(line);
		if ((!line)) {
			JB_Tree_SyntaxAppend(output, msg);
			JB_Decr(line);
			break;
		}
		Message* _tmp317 = JB_Tk__Avoid();
		JB_Incr(_tmp317);
		if (line == _tmp317) {
			result = true;
		} else {
			JB_Tree_SyntaxAppend(line, msg);
			JB_SetRef(msg, line);
		}
		JB_Decr(_tmp317);
		JB_Decr(line);
		if (msg) {
			if ((!output)) {
				debugger;
			}
			JB_Tree_SyntaxAppend(output, msg);
			JB_SetRef(msg, nil);
		}
	};
	JB_Decr(msg);
	return result;
}

Message* JB_Tk__DotSub(Syntax* fn, int Start) {
	int After = JB_Tk__WordAfter((++Start));
	if ((!After)) {
		return nil;
	}
	Message* Result = JB_Tk__NewParent(nil, fn, Start, After);
	JB_Incr(Result);
	if (JB_Tk__GetNextByte('(')) {
		JB_Tk__Params(Result, After);
	} else {
		JB_FreeIfDead(JB_Tk__NewParent0(Result, JB_SyxEmb, After));
	}
	JB_SafeDecr(Result);
	return Result;
}

int JB_Tk__EmbeddedArg(JB_String* close, Message* result, Syntax* Mode) {
	Message* arg = JB_Tk__NewParent0(result, JB_SyxArg, JB_Tk__NextStart());
	JB_Incr(arg);
	int _tmp314 = JB_Tk__EmbeddedCode(close, arg, JB_Fn_Parseflags(Mode));
	JB_Decr(arg);
	return _tmp314;
}

int JB_Tk__EmbeddedCode(JB_String* close, Message* dest, int Mode) {
	JB_String* _tmp315 = JB_Tk__Data();
	JB_Incr(_tmp315);
	int result = JB_Str_FindStr(_tmp315, JB_Tk__NextStart(), close);
	JB_Decr(_tmp315);
	if ((!JB_int_Found(result))) {
		FastString* _fs_fs = JB_FS__New();
		JB_Incr(_fs_fs);
		JB_FS_AppendString(_fs_fs, JB_str_62);
		JB_FS_AppendString(_fs_fs, close);
		JB_String* _fs_str = JB_FS_SyntaxCastString(_fs_fs);
		JB_Incr(_fs_str);
		JB_SetRef(_fs_fs, nil);
		JB_Decr(_fs_fs);
		JB_FreeIfDead(JB_Tk__ErrorAdd(_fs_str, JB_Tk__NextStart(), false));
		JB_Decr(_fs_str);
		return result;
	}
	JB_Tk__ParseLoopMode(dest, Mode);
	if (JB_Tk__NextStart() > result) {
		FastString* _fs1_fs = JB_FS__New();
		JB_Incr(_fs1_fs);
		JB_FS_AppendString(_fs1_fs, JB_str_128);
		JB_FS_AppendString(_fs1_fs, close);
		JB_FS_AppendString(_fs1_fs, JB_str_129);
		JB_String* _fs1_str = JB_FS_SyntaxCastString(_fs1_fs);
		JB_Incr(_fs1_str);
		JB_SetRef(_fs1_fs, nil);
		JB_Decr(_fs1_fs);
		JB_FreeIfDead(JB_Tk__ErrorAdd(_fs1_str, result, false));
		JB_Decr(_fs1_str);
		return result;
	}
	result = (result + JB_Str_Length(close));
	(JB_Tk__NextStartSet(result));
	return result;
}

Message* JB_Tk__ErrorAdd(JB_String* s, int Start, bool WasEnder) {
	if ((!JB_Tk__OK())) {
		return nil;
	}
	(JB_Tk__ErrorStartSet(Start));
	JB_Error* err = JB_Err__New(JB__Tk_ErrNode);
	JB_Incr(err);
	JB_SetRef(err->Node, nil);
	err->Position = Start;
	JB_SetRef(err->Description, s);
	JB_Rec_NewItem(JB_StdErr, err);
	JB_Decr(err);
	return nil;
}

void JB_Tk__ErrorEvent2(int Start, int ExpectedBits, int RealBits) {
	FastString* Err = JB_FS__New();
	JB_Incr(Err);
	if ((!(((bool)(RealBits & kJB__Tk_IllegalChar))))) {
		if ((!ExpectedBits) or ((!RealBits) or (!JB_Tk__FindError(ExpectedBits)))) {
			JB_FS_AppendString(Err, JB_str_133);
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
			JB_FS_AppendString(Err, JB_str_65);
		}
	}
	if (RealBits == kJB__Tk_EndOfLine) {
		JB_FS_AppendString(Err, JB_str_134);
	} else if (RealBits == kJB__Tk_SyntacticComment) {
		JB_FS_AppendString(Err, JB_str_135);
	} else if ((!RealBits)) {
		JB_FS_AppendString(Err, JB_str_136);
	} else {
		if (JB_Tk__NextStart() <= Start) {
			(JB_Tk__NextStartSet(Start + 1));
		}
		if (((bool)(RealBits & kJB__Tk_IllegalChar))) {
			JB_FS_AppendString(Err, JB_str_137);
			JB_String* _tmp323 = JB_Tk__Data();
			JB_Incr(_tmp323);
			byte illegal = JB_Str_SyntaxAccess(_tmp323, Start);
			JB_Decr(_tmp323);
			if (JB_byte_CanPrintAsNormalChar(illegal)) {
				JB_FS_AppendByte(Err, '\'');
				JB_String* _tmp324 = JB_Tk__Data();
				JB_Incr(_tmp324);
				JB_FS_AppendByte(Err, JB_Str_SyntaxAccess(_tmp324, Start));
				JB_Decr(_tmp324);
				JB_FS_AppendByte(Err, '\'');
			} else {
				JB_FS_AppendString(Err, JB_str_138);
				JB_FS_AppendHex(Err, illegal, 2);
				JB_FS_AppendByte(Err, ' ');
			}
		} else {
			JB_FS_AppendByte(Err, '\'');
			int N = JB_int_OperatorMin(JB_Tk__NextStart(), (Start + 100));
			JB_String* _tmp325 = JB_Str_Escape(JB_Str_AccessRange(JB_Tk__Data(), Start, N));
			JB_Incr(_tmp325);
			JB_FS_AppendString(Err, _tmp325);
			JB_Decr(_tmp325);
			JB_FS_AppendByte(Err, '\'');
		}
	}
	JB_String* _tmp326 = JB_FS_SyntaxCastString(Err);
	JB_Incr(_tmp326);
	JB_Decr(Err);
	JB_FreeIfDead(JB_Tk__ErrorAdd(_tmp326, Start, false));
	JB_Decr(_tmp326);
}

bool JB_Tk__ExpectEndChar(byte s, bool Expect) {
	JB_Tk__CleanSpaces();
	if (JB_Tk__GetNextByte(s)) {
		return true;
	}
	if (Expect) {
		FastString* _fs_fs = JB_FS__New();
		JB_Incr(_fs_fs);
		JB_FS_AppendString(_fs_fs, JB_str_117);
		JB_FS_AppendByte(_fs_fs, s);
		JB_FS_AppendString(_fs_fs, JB_str_14);
		JB_String* _fs_str = JB_FS_SyntaxCastString(_fs_fs);
		JB_Incr(_fs_str);
		JB_SetRef(_fs_fs, nil);
		JB_Decr(_fs_fs);
		JB_FreeIfDead(JB_Tk__ErrorAdd(_fs_str, JB_Tk__NextStart(), true));
		JB_Decr(_fs_str);
	}
	return false;
}

Message* JB_Tk__fAccess(int Start) {
	Message* result = JB_Tk__NewParent0(nil, JB_SyxAcc, Start);
	JB_Incr(result);
	Message* prms = JB_Tk__NewParent0(result, JB_SyxArr, Start);
	JB_Incr(prms);
	JB_Tk__ParseLoop(prms, ']');
	JB_Decr(prms);
	JB_SafeDecr(result);
	return result;
}

Message* JB_Tk__fAdjectiveOp(int Start) {
	Message* result = JB_Tk__NewParent0(nil, JB_SyxAdj, Start);
	JB_Incr(result);
	Message* _tmp305 = JB_Tk__Process(kJB__Tk_OppChain, kJB__Tk_Expect);
	JB_Incr(_tmp305);
	JB_Tree_SyntaxAppend(result, _tmp305);
	JB_Decr(_tmp305);
	JB_SafeDecr(result);
	return result;
}

Message* JB_Tk__fAdjectiveThing(int Start) {
	Message* result = JB_Tk__NewParent0(nil, JB_SyxAdj, Start);
	JB_Incr(result);
	Message* _tmp295 = JB_Tk__ProcessThing(0, kJB__Tk_Expect);
	JB_Incr(_tmp295);
	JB_Tree_SyntaxAppend(result, _tmp295);
	JB_Decr(_tmp295);
	JB_SafeDecr(result);
	return result;
}

Message* JB_Tk__fAfterRel(int Start) {
	return JB_Tk__NewParent(nil, JB_SyxARel, Start, JB_Tk__NextStart());
}

Message* JB_Tk__fAnaphoricReference(int Start) {
	return JB_Tk__NewWord(nil, JB_SyxAna, Start, JB_Tk__NextStart());
}

Message* JB_Tk__fArray(int Start) {
	Message* Result = JB_Tk__NewParent0(nil, JB_SyxArr, Start);
	JB_Incr(Result);
	JB_Tk__ParseLoop(Result, ']');
	JB_SafeDecr(Result);
	return Result;
}

Message* JB_Tk__fAtName(int Start) {
	return JB_Tk__NewWord(nil, JB_SyxName, Start, JB_Tk__NextStart());
}

Message* JB_Tk__fAtNamedExp(int Start) {
	Message* result = JB_Tk__NewParent0(nil, JB_SyxName, Start);
	JB_Incr(result);
	Message* _tmp296 = JB_Tk__ProcessThing(0, kJB__Tk_Expect);
	JB_Incr(_tmp296);
	JB_Tree_SyntaxAppend(result, _tmp296);
	JB_Decr(_tmp296);
	JB_SafeDecr(result);
	return result;
}

Message* JB_Tk__fBackTick(int Start) {
	return JB_Tk__fStrSub(Start, JB_str_113, JB_SyxBack);
}

Message* JB_Tk__fBarTypeCast(int Start) {
	return JB_Tk__BarThings(Start, JB_SyxType);
}

Message* JB_Tk__fBeforeRel(int Start) {
	return JB_Tk__BeforeRelSub(Start, kJB__Tk_Expect);
}

Message* JB_Tk__fBeforeRelMinus(int Start) {
	JB_String* _tmp298 = JB_Tk__Data();
	JB_Incr(_tmp298);
	byte c = JB_Str_SyntaxAccess(_tmp298, Start + 1);
	JB_Decr(_tmp298);
	if (JB_byte_IsNum(c)) {
		return JB_Tk__NumberSub(Start + 1, Start);
	}
	return JB_Tk__BeforeRelSub(Start, kJB__Tk_Allow);
}

Message* JB_Tk__fBinary(int Start) {
	JB_String* _tmp271 = JB_Tk__Data();
	JB_Incr(_tmp271);
	int End = JB_Str_FindStr(_tmp271, Start + 2, JB_str_82);
	JB_Decr(_tmp271);
	if ((!JB_int_Found(End))) {
		return JB_Tk__ErrorAdd(JB_str_83, JB_Tk__NextStart(), false);
	}
	JB_String* _tmp272 = JB_Tk__Data();
	JB_Incr(_tmp272);
	JB_String* S = JB_Str_AccessRange(_tmp272, Start + 2, End);
	JB_Incr(S);
	JB_Decr(_tmp272);
	(JB_Tk__NextStartSet(End + 2));
	JB_String* _tmp273 = JB_Str_DecodeB64(S, nil);
	JB_Incr(_tmp273);
	JB_Decr(S);
	Message* _tmp274 = JB_Tk__NewParentName(nil, JB_SyxBin, Start, _tmp273);
	JB_Incr(_tmp274);
	JB_Decr(_tmp273);
	JB_SafeDecr(_tmp274);
	return _tmp274;
}

Message* JB_Tk__fBracket(int Start) {
	Message* Result = JB_Tk__NewParent0(nil, JB_SyxList, Start);
	if (JB_Tk__ParseLoop(Result, ')')) {
		if ((!JB_Msg_SyxOppEquals(((Message*)JB_Tree_First(Result)), JB_SyxItem, false))) {
			Result->Type = JB_SyxBra;
		}
	}
	return Result;
}

Message* JB_Tk__fChr(int Start) {
	JB_String* _tmp299 = JB_Tk__Data();
	JB_Incr(_tmp299);
	int After = JB_Str_JBFind(_tmp299, JB_Tk__NextStart(), kJB__int_max, '\'');
	JB_Decr(_tmp299);
	if ((!JB_int_Found(After))) {
		return JB_Tk__ErrorAdd(JB_str_119, JB_Tk__NextStart(), false);
	}
	(JB_Tk__NextStartSet(After + 1));
	JB_String* _tmp300 = JB_Str_AccessRange(JB_Tk__Data(), Start + 1, After);
	JB_Incr(_tmp300);
	JB_String* name = JB_Str_Unescape(_tmp300);
	JB_Incr(name);
	JB_Decr(_tmp300);
	Message* _tmp301 = JB_Tk__NewParentName(nil, JB_SyxChar, Start, name);
	JB_Incr(_tmp301);
	JB_Decr(name);
	JB_SafeDecr(_tmp301);
	return _tmp301;
}

Message* JB_Tk__fComment(int Start) {
	int Count = 1;
	int i = JB_Tk__NextStart();
	JB_String* d = JB_Tk__Data();
	JB_Incr(d);
	while (true) {
		i = JB_Str_FindByte(d, i + 1, '/');
		if ((!JB_int_Found(i))) {
			JB_Decr(d);
			return JB_Tk__ErrorAdd(JB_str_120, Start, false);
		} else if (JB_Str_SyntaxAccess(d, i - 1) == '*') {
			Count--;
		} else if (JB_Str_SyntaxAccess(d, i + 1) == '*') {
			Count++;
			i = (i + 2);
		}
		if ((!Count)) {
			break;
		}
	};
	JB_Decr(d);
	(JB_Tk__NextStartSet(i + 1));
	return JB_Tk__Avoid();
}

Message* JB_Tk__fCommentLine(int Start) {
	JB_String* _tmp302 = JB_Tk__Data();
	JB_Incr(_tmp302);
	(JB_Tk__NextStartSet(JB_Str_InCharSet(_tmp302, JB_Tk__NextStart(), kJB__int_max, JB__Constants_CSLine)));
	JB_Decr(_tmp302);
	return JB_Tk__Avoid();
}

Message* JB_Tk__fDecl(int Start) {
	Message* Result = JB_Tk__BarThings(Start, JB_SyxDecl);
	JB_Incr(Result);
	if ((!Result)) {
		JB_Decr(Result);
		return nil;
	}
	while ((!JB_Tk__WillEnd())) {
		Message* Curr = JB_Tk__ProcessThing(kJB__Tk_OppSyx | kJB__Tk_OppTemporal, 0);
		JB_Incr(Curr);
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

Message* JB_Tk__fError(int Start) {
	return nil;
}

Message* JB_Tk__fFuncCall(int Start) {
	Message* Result = JB_Tk__NewParent0(nil, JB_SyxFunc, Start);
	JB_Incr(Result);
	JB_Tk__Params(Result, Start);
	JB_SafeDecr(Result);
	return Result;
}

int JB_Tk__FindError(int num) {
	if (num == kJB__Tk_Thing) {
		return kJB__Tk_Thing;
	}
	{
		DictionaryReader* _nav = JB_Dict_Navigate(JB__Tk_ErrorNames);
		JB_Incr(_nav);
		while (JB_Nav_MoveNext(_nav)) {
			JB_String* Key = JB_Nav_Name(_nav);
			JB_Incr(Key);
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

Message* JB_Tk__fNumber(int Start) {
	return JB_Tk__NumberSub(Start, Start);
}

Message* JB_Tk__fOpAsThing(int Start) {
	Message* Result = JB_Tk__NewParent0(nil, JB_SyxOat, Start);
	JB_Incr(Result);
	Message* _tmp303 = JB_Tk__Process(kJB__Tk_Opp, 0);
	JB_Incr(_tmp303);
	JB_Tree_SyntaxAppend(Result, _tmp303);
	JB_Decr(_tmp303);
	Message* _tmp304 = JB_Tk__ProcessThing(kJB__Tk_Opp, 0);
	JB_Incr(_tmp304);
	JB_Tree_SyntaxAppend(Result, _tmp304);
	JB_Decr(_tmp304);
	JB_SafeDecr(Result);
	return Result;
}

Message* JB_Tk__fOppBracket(int Start) {
	Message* result = JB_Tk__NewParent0(nil, JB_SyxBra, Start);
	JB_Incr(result);
	Message* opp1 = JB_Tk__Process(kJB__Tk_OppChain, 0);
	JB_Incr(opp1);
	Message* opp2 = JB_Tk__Process(kJB__Tk_Opp, 0);
	JB_Incr(opp2);
	if (opp2) {
		Message* rel = JB_Tk__NewParent0(result, JB_SyxRel, JB_Tk__NextStart() - 1);
		JB_Incr(rel);
		JB_Tree_SyntaxAppend(rel, opp1);
		JB_Tree_SyntaxAppend(rel, opp2);
		Message* _tmp307 = JB_Tk__Process(kJB__Tk_OppChain, 0);
		JB_Incr(_tmp307);
		JB_Tree_SyntaxAppend(rel, _tmp307);
		JB_Decr(_tmp307);
		JB_Decr(rel);
	} else {
		JB_Tree_SyntaxAppend(result, opp1);
	}
	JB_Decr(opp2);
	JB_Decr(opp1);
	JB_Tk__ExpectEndChar(')', true);
	Message* _tmp308 = JB_Tk__OppChain(result);
	JB_Incr(_tmp308);
	JB_Decr(result);
	JB_SafeDecr(_tmp308);
	return _tmp308;
}

Message* JB_Tk__fOppSyx(int Start) {
	return JB_Tk__NewParent(nil, JB_SyxSOpp, Start, JB_Tk__NextStart());
}

Message* JB_Tk__fOppSyxNeq(int Start) {
	Message* result = JB_Tk__fOppSyx(Start);
	JB_Incr(result);
	byte c = JB_Tk__NextByte();
	if (c == '=') {
		JB_Decr(result);
		return JB_Tk__ErrorAdd(JB_str_121, JB_Tk__NextStart(), false);
	}
	JB_SafeDecr(result);
	return result;
}

Message* JB_Tk__fOppWord(int Start) {
	Message* opp = JB_Tk__NewParent(nil, JB_SyxOpp, Start, JB_Tk__WordAfter(Start));
	JB_Incr(opp);
	Message* _tmp306 = JB_Tk__OppChain(opp);
	JB_Incr(_tmp306);
	JB_Decr(opp);
	JB_SafeDecr(_tmp306);
	return _tmp306;
}

Message* JB_Tk__fSDot(int Start) {
	if (Start > 0) {
		JB_String* _tmp309 = JB_Tk__Data();
		JB_Incr(_tmp309);
		if (JB_BM_HasChar(JB__Constants_CSWordMiddle, JB_Str_SyntaxAccess(_tmp309, Start - 1))) {
			JB_Decr(_tmp309);
			return nil;
		}
		JB_Decr(_tmp309);
	}
	return JB_Tk__DotSub(JB_SyxSDot, Start);
}

Message* JB_Tk__fShebang(int Start) {
	int S = JB_Tk__NextStart();
	JB_String* _tmp310 = JB_Tk__Data();
	JB_Incr(_tmp310);
	int S2 = JB_Str_InCharSet(_tmp310, S, kJB__int_max, JB__Constants_CSLine);
	JB_Decr(_tmp310);
	(JB_Tk__NextStartSet(S2));
	return JB_Tk__NewSkip(nil, JB_SyxSheb, Start, S, S2);
}

Message* JB_Tk__fStatementOpen(int Start) {
	Message* Result = JB_Tk__NewParent0(nil, JB_SyxArg, Start);
	JB_Incr(Result);
	JB_Tk__ParseLoop(Result, '}');
	JB_SafeDecr(Result);
	return Result;
}

Message* JB_Tk__fString(int Start) {
	JB_String* _tmp311 = JB_Tk__Data();
	JB_Incr(_tmp311);
	int After = JB_Str_JBFind(_tmp311, JB_Tk__NextStart(), kJB__int_max, '"');
	JB_Decr(_tmp311);
	if ((!JB_int_Found(After))) {
		return JB_Tk__ErrorAdd(JB_str_122, JB_Tk__NextStart(), false);
	}
	int StrPos = Start + 1;
	Message* result = JB_Tk__NewParent0(nil, JB_SyxStr, Start);
	JB_Incr(result);
	while (true) {
		JB_String* _tmp312 = JB_Tk__Data();
		JB_Incr(_tmp312);
		int NewStrPos = JB_Str_InStr(_tmp312, JB_str_123, StrPos, After, false);
		JB_Decr(_tmp312);
		if ((!JB_int_Found(NewStrPos))) {
			NewStrPos = After;
		}
		if (NewStrPos > StrPos) {
			Message* Str = JB_Tk__NewParent(result, JB_SyxEmb, StrPos, NewStrPos);
			JB_Incr(Str);
			JB_SetRef(Str->Name, JB_Str_Unescape(Str->Name));
			JB_Decr(Str);
		}
		if (NewStrPos >= After) {
			break;
		}
		(JB_Tk__NextStartSet(NewStrPos + 2));
		Message* OldLast = ((Message*)JB_Tree_Last(result));
		JB_Incr(OldLast);
		StrPos = JB_Tk__EmbeddedCode(JB_str_124, result, JB_Fn_Parseflags(JB_SyxList));
		Message* _tmp313 = ((Message*)JB_Tree_Last(result));
		JB_Incr(_tmp313);
		if (_tmp313 == OldLast) {
			JB_Decr(result);
			JB_Decr(OldLast);
			JB_Decr(_tmp313);
			return JB_Tk__ErrorAdd(JB_str_125, NewStrPos, false);
		}
		JB_Decr(_tmp313);
		JB_Decr(OldLast);
		if (StrPos > After) {
			JB_Decr(result);
			return JB_Tk__ErrorAdd(JB_str_126, NewStrPos, false);
		}
	};
	(JB_Tk__NextStartSet(After + 1));
	JB_Msg_UnEmbed(result);
	JB_SafeDecr(result);
	return result;
}

Message* JB_Tk__fStrSub(int Start, JB_String* Ender, Syntax* syx) {
	JB_String* _tmp297 = JB_Tk__Data();
	JB_Incr(_tmp297);
	int After = JB_Str_FindStr(_tmp297, JB_Tk__NextStart(), Ender);
	JB_Decr(_tmp297);
	if ((!JB_int_Found(After))) {
		return JB_Tk__ErrorAdd(JB_str_118, JB_Tk__NextStart(), false);
	}
	int FindLen = JB_Str_Length(Ender);
	(JB_Tk__NextStartSet(After + FindLen));
	return JB_Tk__NewSkip(nil, syx, Start, Start + FindLen, After);
}

Message* JB_Tk__fSuperStr(int Start) {
	return JB_Tk__fStrSub(Start, JB_str_52, JB_SyxSStr);
}

Message* JB_Tk__fSyntacticComment(int Start) {
	Message* Result = JB_Tk__NewParent0(nil, JB_SyxSCom, Start);
	JB_Incr(Result);
	JB_Tk__EmbeddedArg(JB_str_127, Result, JB_SyxList);
	JB_SafeDecr(Result);
	return Result;
}

Message* JB_Tk__fTemporalAsThing(int Start) {
	return JB_Tk__Process(kJB__Tk_Temporal, kJB__Tk_Expect);
}

Message* JB_Tk__fTemporalRel(int Start) {
	JB_Tk__CleanSpaces();
	return JB_Tk__NewWord(nil, JB_SyxCnj, Start, JB_Tk__NextStart());
}

Message* JB_Tk__fTemporalRelSyx(int Start) {
	return JB_Tk__NewParent(nil, JB_SyxSCnj, Start, JB_Tk__NextStart());
}

Message* JB_Tk__fTemporalStatement(int Start) {
	int After = JB_Tk__WordAfter(Start);
	if (JB_Tk__WillEnd()) {
		return JB_Tk__NewParent(nil, JB_SyxTmp, Start, After);
	}
	if ((!(JB_BM_HasChar(JB__Constants_CSAfterTemporal, JB_Tk__NextByte())))) {
		return nil;
	}
	Message* result = nil;
	JB_Incr(result);
	while (true) {
		Message* item = JB_Tk__ProcessThing(kJB__Tk_Opp & (~kJB__Tk_OppBra), 0);
		JB_Incr(item);
		if ((!item)) {
			JB_Decr(item);
			break;
		}
		if ((!(result))) {
			JB_SetRef(result, JB_Tk__NewParent(nil, JB_SyxTmp, Start, After));
		}
		JB_Tree_SyntaxAppend(result, item);
		if (JB_Tk__WillEnd()) {
			JB_Decr(item);
			JB_SafeDecr(result);
			return result;
		}
		if (JB_Msg_SyxOppEquals(item, JB_SyxArg, false)) {
			Message* SubTmp = JB_Tk__Process(kJB__Tk_TemporalWord, 0);
			JB_Incr(SubTmp);
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

Message* JB_Tk__fThingSyx(int Start) {
	return JB_Tk__NewParent(nil, JB_SyxSThg, Start, JB_Tk__NextStart());
}

Message* JB_Tk__fThingWord(int Start) {
	int name = JB_Tk__WordAfter(Start);
	return JB_Tk__NewParent(nil, JB_SyxThg, Start, name);
}

Message* JB_Tk__GetFuncAfter(Message* input) {
	Message* Result = input;
	JB_Incr(Result);
	while (true) {
		int ThisAfter = kJB__Tk_FuncAfterAny & (~JB__Tk_StopBars);
		if (JB_Tk__NoFuncAfter(JB_Tk__NextByte())) {
			ThisAfter = (ThisAfter & (~kJB__Tk_FuncAfterNoSpace));
		}
		Message* d = JB_Tk__Process(ThisAfter, 0);
		JB_Incr(d);
		if ((!d)) {
			JB_Decr(d);
			break;
		}
		if ((!JB_Msg_SyxOppEquals(d, JB_SyxName, false))) {
			(JB_Tree_FirstSet(d, Result));
		} else if ((!JB_Msg_SyxOppEquals(Result, JB_SyxThg, false))) {
			JB_FreeIfDead(JB_Tk__ErrorAdd(JB_str_130, JB_Tk__NextStart(), false));
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
	JB_String* lines = JB_str_92;
	JB_Incr(lines);
	Array* numb = JB_Str_ByteSplit(JB_str_93);
	JB_Incr(numb);
	JB_String* op_comp = JB_str_94;
	JB_Incr(op_comp);
	JB_String* op_math = JB_str_95;
	JB_Incr(op_math);
	JB_String* PFix = JB_str_96;
	JB_Incr(PFix);
	TokHan* _tmp285 = JB_TH_Link(JB_Tk__Handler(kJB__Tk_ThingWord, ((TokenHandler_fp)JB_Tk__fThingWord)), kJB__Tk_TemporalWord, ((TokenHandler_fp)JB_Tk__fTemporalStatement));
	JB_Incr(_tmp285);
	TokHan* H = JB_TH_Link(_tmp285, kJB__Tk_OppWord, ((TokenHandler_fp)JB_Tk__fOppWord));
	JB_Incr(H);
	JB_Decr(_tmp285);
	Array* _tmp286 = JB_BM_Bytes(JB__Constants_CSWordStart);
	JB_Incr(_tmp286);
	JB_Tk__TokensHandler(_tmp286, H);
	JB_Decr(_tmp286);
	JB_Decr(H);
	TokHan* _tmp287 = JB_TH_Link(JB_TH_Link(JB_Tk__Handler(kJB__Tk_FuncAfterNoSpace, ((TokenHandler_fp)JB_Tk__fFuncCall)), kJB__Tk_ThingSyx, ((TokenHandler_fp)JB_Tk__fBracket)), kJB__Tk_OppBra, ((TokenHandler_fp)JB_Tk__fOppBracket));
	JB_Incr(_tmp287);
	(JB_Tk__TokenSet(JB_str_97, _tmp287));
	JB_Decr(_tmp287);
	TokHan* _tmp288 = JB_TH_Link(JB_Tk__Handler(kJB__Tk_FuncAfterNoSpace, ((TokenHandler_fp)JB_Tk__fAccess)), kJB__Tk_ThingSyx, ((TokenHandler_fp)JB_Tk__fArray));
	JB_Incr(_tmp288);
	(JB_Tk__TokenSet(JB_str_98, _tmp288));
	JB_Decr(_tmp288);
	TokHan* _tmp289 = JB_TH_Link(JB_Tk__Handler(kJB__Tk_FuncAfterNoSpace, ((TokenHandler_fp)JB_Tk__fDot)), kJB__Tk_ThingSyx, ((TokenHandler_fp)JB_Tk__fSDot));
	JB_Incr(_tmp289);
	(JB_Tk__TokenSet(JB_str_20, _tmp289));
	JB_Decr(_tmp289);
	TokHan* _tmp290 = JB_TH_Link(JB_Tk__Handler(kJB__Tk_FuncAfterBar, ((TokenHandler_fp)JB_Tk__fBarTypeCast)), kJB__Tk_TemporalSyx, ((TokenHandler_fp)JB_Tk__fDecl));
	JB_Incr(_tmp290);
	(JB_Tk__TokenSet(JB_str_99, _tmp290));
	JB_Decr(_tmp290);
	TokHan* _tmp291 = JB_TH_Link(JB_Tk__Handler(kJB__Tk_ThingSyx, ((TokenHandler_fp)JB_Tk__fAtName)), kJB__Tk_FuncAfterNormal, ((TokenHandler_fp)JB_Tk__fAtNamedExp));
	JB_Incr(_tmp291);
	(JB_Tk__TokenSet(JB_str_100, _tmp291));
	JB_Decr(_tmp291);
	TokHan* _tmp292 = JB_TH_Link(JB_Tk__Handler(kJB__Tk_FuncAfterNormal, ((TokenHandler_fp)JB_Tk__fAdjectiveThing)), kJB__Tk_adjectiveop, ((TokenHandler_fp)JB_Tk__fAdjectiveOp));
	JB_Incr(_tmp292);
	(JB_Tk__TokenSet(JB_str_101, _tmp292));
	JB_Decr(_tmp292);
	JB_Tk__Tokenz(JB_str_102, kJB__Tk_ThingSyx, JB_Tk__fBeforeRelMinus);
	JB_Tk__Tokenz(PFix, kJB__Tk_ThingSyx, JB_Tk__fBeforeRel);
	JB_Tk__Tokenz(PFix, kJB__Tk_FuncAfterNormal, JB_Tk__fAfterRel);
	JB_Decr(PFix);
	JB_Tk__Tokenz(JB_str_103, kJB__Tk_colon, nil);
	JB_Tk__Tokenz(JB_str_60, kJB__Tk_ThingSyx, JB_Tk__fTemporalAsThing);
	JB_Tk__Tokenz(JB_str_104, kJB__Tk_ThingSyx, JB_Tk__fStatementOpen);
	JB_Tk__Tokenz(JB_str_105, kJB__Tk_TmpOpp, JB_Tk__fTemporalRel);
	JB_Tk__Tokenz(JB_str_106, kJB__Tk_TmpOpp, JB_Tk__fTemporalRelSyx);
	JB_Tk__Tokenz(JB_str_32, kJB__Tk_ThingSyx, JB_Tk__fOpAsThing);
	JB_Tk__Tokenz(JB_str_107, kJB__Tk_ThingSyx, JB_Tk__fAnaphoricReference);
	JB_Tk__Tokens(numb, kJB__Tk_ThingSyx, JB_Tk__fNumber);
	JB_Decr(numb);
	JB_Tk__Tokenz(JB_str_59, kJB__Tk_TemporalSyx, JB_Tk__fShebang);
	JB_Tk__Tokenz(JB_str_108, kJB__Tk_EndOfLine + kJB__Tk_words_line, JB_Tk__fCommentLine);
	JB_Tk__Tokenz(JB_str_109, kJB__Tk_EndOfLine + kJB__Tk_words_line, JB_Tk__fComment);
	JB_Tk__Tokenz(lines, kJB__Tk_EndOfLine + kJB__Tk_words_line, nil);
	JB_Decr(lines);
	JB_Tk__Tokenz(JB_str_110, kJB__Tk_EndOfLine, nil);
	JB_Tk__Tokenz(op_comp, kJB__Tk_OppSyx, JB_Tk__fOppSyxNeq);
	JB_Decr(op_comp);
	JB_Tk__Tokenz(op_math, kJB__Tk_OppSyx, JB_Tk__fOppSyx);
	JB_Decr(op_math);
	JB_Tk__Tokenz(JB_str_111, kJB__Tk_ThingSyx, JB_Tk__fThingSyx);
	JB_Tk__Tokenz(JB_str_112, kJB__Tk_ThingSyx, JB_Tk__fString);
	JB_Tk__Tokenz(JB_str_14, kJB__Tk_ThingSyx, JB_Tk__fChr);
	JB_Tk__Tokenz(JB_str_113, kJB__Tk_ThingSyx, JB_Tk__fBackTick);
	JB_Tk__Tokenz(JB_str_53, kJB__Tk_ThingSyx, JB_Tk__fSuperStr);
	JB_Tk__Tokenz(JB_str_114, kJB__Tk_ThingSyx, JB_Tk__fBeforeRel);
	JB_Tk__Tokenz(JB_str_115, kJB__Tk_SyntacticComment, JB_Tk__fSyntacticComment);
	JB_Tk__Tokenz(JB_str_81, kJB__Tk_ThingSyx, JB_Tk__fBinary);
	JB_Tk__Tokenz(JB_str_116, kJB__Tk_EndContainer, nil);
	TokHan* IllegalHandler = JB_Tk__Handler(-1, ((TokenHandler_fp)JB_Tk__fError));
	JB_Incr(IllegalHandler);
	{
		int i = 0;
		while (i < 256) {
			JB_String* _tmp293 = JB_Str_ChrB(i);
			JB_Incr(_tmp293);
			(JB_Tk__TokenNilSet(_tmp293, IllegalHandler));
			JB_Decr(_tmp293);
			i++;
		};
	};
	JB_Decr(IllegalHandler);
}

int JB_Tk__Init_() {
	{
		JB__Tk_StopBars = 0;
		JB__Tk_BaseMessagePosition = -1;
		(JB_Rec__New());
	};
	return 0;
}

int JB_Tk__IsHexLike(JB_String* S, int N) {
	if (JB_Str_SyntaxAccess(S, N + 0x00) == '0') {
		byte X = JB_Str_SyntaxAccess(S, N + 1);
		if ((X >= 'a') and (X <= 'z')) {
			return 2;
		}
		if ((X >= 'A') and (X <= 'Z')) {
			return 2;
		}
	}
	return 0;
}

Message* JB_Tk__MakeRel(Message* first, int Bits) {
	Message* opp = JB_Tk__Process(Bits, kJB__Tk_Allow);
	JB_Incr(opp);
	if ((!opp)) {
		JB_Decr(opp);
		return first;
	}
	Message* result = JB_Tk__NewParent0(nil, JB_SyxRel, first->Position);
	JB_Incr(result);
	JB_Tree_SyntaxAppend(result, first);
	JB_Tree_SyntaxAppend(result, opp);
	if (JB_Tk__GetNextByte('=')) {
		result->Type = JB_SyxERel;
	}
	int Mode = kJB__Tk_Allow;
	if (JB_Msg_SyxOppEquals(opp, JB_SyxSOpp, false)) {
		Mode = kJB__Tk_Expect;
		Bits = (Bits | kJB__Tk_OppWord);
		opp->Type = JB_SyxOpp;
	}
	JB_Decr(opp);
	Message* _tmp316 = JB_Tk__ProcessThing(Bits, Mode);
	JB_Incr(_tmp316);
	JB_Tree_SyntaxAppend(result, _tmp316);
	JB_Decr(_tmp316);
	JB_SafeDecr(result);
	return result;
}

int JB_Tk__MessageErrorSub(FastString* fs, int num, int ButFound) {
	if ((!JB__Tk_ErrorNames)) {
		JB_SetRef(JB__Tk_ErrorNames, JB_Dict__New());
		(JB_Dict_a4(JB__Tk_ErrorNames, kJB__Tk_Temporal, JB_str_139));
		(JB_Dict_a4(JB__Tk_ErrorNames, kJB__Tk_TemporalSyx, JB_str_140));
		(JB_Dict_a4(JB__Tk_ErrorNames, kJB__Tk_TemporalWord, JB_str_141));
		(JB_Dict_a4(JB__Tk_ErrorNames, kJB__Tk_SyntacticComment, JB_str_135));
		(JB_Dict_a4(JB__Tk_ErrorNames, kJB__Tk_EndOfLine, JB_str_134));
		(JB_Dict_a4(JB__Tk_ErrorNames, kJB__Tk_colon, JB_str_142));
		(JB_Dict_a4(JB__Tk_ErrorNames, kJB__Tk_OppSyx, JB_str_143));
		(JB_Dict_a4(JB__Tk_ErrorNames, kJB__Tk_OppWord, JB_str_144));
		(JB_Dict_a4(JB__Tk_ErrorNames, kJB__Tk_OppTemporal, JB_str_145));
		(JB_Dict_a4(JB__Tk_ErrorNames, kJB__Tk_Opp, JB_str_144));
		(JB_Dict_a4(JB__Tk_ErrorNames, kJB__Tk_FuncAfterBar, JB_str_146));
		(JB_Dict_a4(JB__Tk_ErrorNames, kJB__Tk_Thing, JB_str_147));
		(JB_Dict_a4(JB__Tk_ErrorNames, kJB__Tk_ThingWord, JB_str_147));
		(JB_Dict_a4(JB__Tk_ErrorNames, kJB__Tk_ThingSyx, JB_str_147));
		(JB_Dict_a4(JB__Tk_ErrorNames, kJB__Tk_IllegalChar, JB_str_148));
	}
	if (JB_FS_Length(fs)) {
		JB_FS_AppendString(fs, JB_str_149);
	} else {
		JB_FS_AppendString(fs, JB_str_64);
	}
	int BestValue = JB_Tk__FindError(num);
	if (BestValue) {
		JB_String* _tmp327 = ((JB_String*)JB_Dict_Value(JB__Tk_ErrorNames, JB_int_DictName(BestValue)));
		JB_Incr(_tmp327);
		JB_FS_AppendString(fs, _tmp327);
		JB_Decr(_tmp327);
		return num & (~BestValue);
	}
	JB_FS_AppendString(fs, JB_str_150);
	return 0;
}

Message* JB_Tk__NewParent(Message* Parent, Syntax* Func, int Start, int End) {
	JB_String* Name = JB_Str_AccessRange(JB_Tk__Data(), Start, End);
	Message* Result = JB_Msg__NewParser(Parent, Func, Start, Name);
	return Result;
}

Message* JB_Tk__NewParent0(Message* Parent, Syntax* Func, int Start) {
	return JB_Msg__NewParser(Parent, Func, Start, JB_str_0);
}

Message* JB_Tk__NewParentName(Message* Parent, Syntax* Func, int Start, JB_String* name) {
	return JB_Msg__NewParser(Parent, Func, Start, name);
}

Message* JB_Tk__NewSkip(Message* P, Syntax* F, int Start, int NameStart, int NameEnd) {
	Message* result = JB_Tk__NewParent(P, F, NameStart, NameEnd);
	result->Position = Start;
	return result;
}

Message* JB_Tk__NewWord(Message* P, Syntax* F, int Start, int SearchFrom) {
	int after = JB_Tk__WordAfter(SearchFrom);
	Message* result = JB_Tk__NewParent(P, F, SearchFrom, after);
	result->Position = Start;
	return result;
}

bool JB_Tk__NoFuncAfter(byte b) {
	return (b == '\t') or ((b == ' ') or (b == '\\'));
}

Message* JB_Tk__NumberSub(int Start, int RealStart) {
	JB_String* D = JB_Tk__Data();
	int After = JB_Tk__NumEnd(D, Start);
	(JB_Tk__NextStartSet(After));
	int StartAt = JB_Tk__IsHexLike(D, Start);
	int UnitPos2 = JB_Str_OutCharSet(D, After, Start + StartAt, JB__Constants_CSNumUnit);
	if ((!JB_int_Found(UnitPos2))) {
		UnitPos2 = (After - 1);
	}
	UnitPos2++;
	Message* Num = JB_Tk__NewParent(nil, JB_SyxNum, RealStart, UnitPos2);
	if (After <= UnitPos2) {
		return Num;
	}
	Message* Unit = JB_Tk__NewParent(nil, JB_SyxUnit, UnitPos2, After);
	JB_Tree_SyntaxAppend(Unit, Num);
	return Unit;
}

int JB_Tk__NumEnd(JB_String* D, int Start) {
	int Dot = JB_Str_OutCharSet(D, Start, kJB__int_max, JB__Constants_CSNum);
	if (JB_Str_SyntaxAccess(D, Dot) != '.') {
		return Dot;
	}
	byte CNext = JB_Str_SyntaxAccess(D, Dot + 1);
	if ((!JB_byte_IsNumeric(CNext))) {
		return Dot;
	}
	int Result = JB_Str_OutCharSet(D, Dot + 1, kJB__int_max, JB__Constants_CSNum);
	if ((!JB_int_Found(Result))) {
		Result = JB_Str_Length(D);
	}
	return Result;
}

bool JB_Tk__OK() {
	return (!JB_int_Found(JB_Tk__ErrorStart()));
}

Message* JB_Tk__OppChain(Message* opp) {
	Message* result = JB_Tk__Process(kJB__Tk_adjectiveop, 0);
	JB_Incr(result);
	if ((!result)) {
		JB_Decr(result);
		return opp;
	}
	(JB_Tree_FirstSet(result, opp));
	JB_SafeDecr(result);
	return result;
}

void JB_Tk__Params(Message* Parent, int N) {
	Message* Result = JB_Tk__NewParent0(Parent, JB_SyxPrm, N);
	JB_Incr(Result);
	JB_Tk__ParseLoop(Result, ')');
	JB_Decr(Result);
}

Message* JB_Tk__ParseItem(Message* ch, int TemporalFlags) {
	Message* Result = JB_Tk__NewParent0(nil, JB_SyxItem, JB_Tk__NextStart() - 1);
	JB_Incr(Result);
	JB_Tree_SyntaxAppend(Result, ch);
	Message* ch2 = JB_Tk__Process(TemporalFlags, 0);
	JB_Incr(ch2);
	if ((!(ch2))) {
		JB_SetRef(ch2, JB_Tk__ProcessThing(kJB__Tk_Opp, 0));
	}
	if ((!(ch2))) {
		JB_SetRef(ch2, JB_Tk__NewParent0(nil, JB_SyxEmb, Result->Position));
	}
	JB_Tree_SyntaxAppend(Result, ch2);
	JB_Decr(ch2);
	JB_SafeDecr(Result);
	return Result;
}

bool JB_Tk__ParseLoop(Message* Output, byte Ender) {
	bool Result = JB_Tk__ParseLoopMode(Output, JB_Fn_Parseflags(Output->Type));
	if (Ender) {
		JB_Tk__ExpectEndChar(Ender, true);
	}
	return Result;
}

bool JB_Tk__ParseLoopMode(Message* Output, int Flags) {
	int result = 0;
	if (JB_Tk__ConsumeLines(nil, nil)) {
		result = 2;
	}
	Flags = (Flags & (~JB__Tk_StopBars));
	while ((!JB_Tk__WillEnd())) {
		Message* Item = JB_Tk__Process(kJB__Tk_Temporal & Flags, 0);
		JB_Incr(Item);
		if ((!Item)) {
			JB_SetRef(Item, JB_Tk__ProcessThing(kJB__Tk_Opp, 0));
			if (((bool)Item) and JB_Tk__Allow(kJB__Tk_colon)) {
				JB_SetRef(Item, JB_Tk__ParseItem(Item, Flags));
			}
			if ((!(Item))) {
				JB_Decr(Item);
				break;
			}
		} else {
			Syntax* f = Item->Type;
			JB_Incr(f);
			if ((f == JB_SyxCnj) or (f == JB_SyxSCnj)) {
				JB_SetRef(Item, JB_Tk__ReRoute(Item, Output));
				if ((!Item)) {
					JB_Decr(Item);
					JB_Decr(f);
					break;
				}
			}
			JB_Decr(f);
		}
		result++;
		if ((!JB_Tk__ConsumeLines(Output, Item))) {
			JB_Decr(Item);
			break;
		}
		JB_Decr(Item);
		result++;
	};
	return (result == 1);
}

Message* JB_Tk__ProcessThing(int Ops, int Expect) {
	Message* result = JB_Tk__Process(kJB__Tk_Thing, Expect);
	JB_Incr(result);
	if ((!result) or JB_Tk__WillEnd()) {
		JB_SafeDecr(result);
		return result;
	}
	JB_SetRef(result, JB_Tk__GetFuncAfter(result));
	if (JB_Tk__WillEnd()) {
		JB_SafeDecr(result);
		return result;
	}
	int NotTemp = Ops & (~kJB__Tk_OppTemporal);
	if (((bool)NotTemp) and (!(JB_Msg_SyxOppEquals(result, JB_SyxArg, false)))) {
		JB_SetRef(result, JB_Tk__MakeRel(result, NotTemp));
	}
	if (((bool)(Ops & kJB__Tk_OppTemporal))) {
		Message* opp = JB_Tk__Process(kJB__Tk_OppTemporal, 0);
		JB_Incr(opp);
		if (opp) {
			JB_SetRef(result, JB_Tk__ChainTemporalRels(result, opp));
		}
		JB_Decr(opp);
	}
	JB_SafeDecr(result);
	return result;
}

Message* JB_Tk__ReRoute(Message* cnj, Message* output) {
	Message* f = ((Message*)JB_Tree_Last(output));
	JB_Incr(f);
	if ((!f)) {
		JB_FreeIfDead(JB_Tk__ErrorAdd(JB_str_131, JB_Tk__NextStart(), false));
		JB_Decr(f);
		return nil;
	}
	Message* Result = JB_Tk__ChainTemporalRels(f, cnj);
	JB_Incr(Result);
	JB_Decr(f);
	if ((JB_Tree_HasChildCount(Result, 2)) and JB_Tk__Allow(kJB__Tk_EndOfLine)) {
		Message* _tmp318 = JB_Tk__ProcessThing(kJB__Tk_Opp, 0);
		JB_Incr(_tmp318);
		JB_Tree_SyntaxAppend(Result, _tmp318);
		JB_Decr(_tmp318);
	}
	JB_SafeDecr(Result);
	return Result;
}

void JB_Tk__StopParse() {
	JB_Tk__StartParse(nil);
}

void JB_Tk__Tokens(Array* arr, int bits, ParseHandler func) {
	TokHan* _tmp319 = JB_Tk__Handler(bits, ((TokenHandler_fp)func));
	JB_Incr(_tmp319);
	JB_Tk__TokensHandler(arr, _tmp319);
	JB_Decr(_tmp319);
}

void JB_Tk__TokensHandler(Array* arr, TokHan* H) {
	{
		int _i = 0;
		while (_i < JB_Array_Size(arr)) {
			JB_String* s = ((JB_String*)JB_Array_Value(arr, _i));
			JB_Incr(s);
			(JB_Tk__TokenSet(s, H));
			JB_Decr(s);
			_i++;
		};
	};
}

void JB_Tk__Tokenz(JB_String* s, int bits, ParseHandler func) {
	if (JB_Str_OperatorContains(s, JB_str_36)) {
		Array* _tmp320 = JB_Str_Split(s, JB_str_36);
		JB_Incr(_tmp320);
		JB_Tk__Tokens(_tmp320, bits, func);
		JB_Decr(_tmp320);
	} else {
		TokHan* _tmp321 = JB_Tk__Handler(bits, ((TokenHandler_fp)func));
		JB_Incr(_tmp321);
		(JB_Tk__TokenSet(s, _tmp321));
		JB_Decr(_tmp321);
	}
}

bool JB_Tk__WillEnd() {
	return JB_Tk__CheckEnded(kJB__Tk_End);
}

int JB_Tk__WordAfter(int Start) {
	int After = JB_Str_OutCharSet(JB_Tk__Data(), Start, kJB__int_max, JB__Constants_CSWordMiddle);
	if (After == Start) {
		JB_FreeIfDead(JB_Tk__ErrorAdd(JB_str_132, Start, false));
	} else {
		(JB_Tk__NextStartSet(After));
		return After;
	}
	return 0;
}


bool JB_Platform__linux() {
	JB_String* _tmp202 = JB_Platform();
	JB_Incr(_tmp202);
	bool _tmp203 = (JB_Str_SyntaxEquals(_tmp202, JB_str_27, false));
	JB_Decr(_tmp202);
	return _tmp203;
}


void JB_BinaryEscapeTest(JB_String* AllBytes) {
	FastString* fs = JB_FS__New();
	JB_Incr(fs);
	JB_String* a = JB_str_37;
	JB_Incr(a);
	{
		int _i1 = 0;
		while (_i1 < 10) {
			JB_FreeIfDead(JB_Str_EncodeB64(a, fs));
			JB_String* result = JB_FS_GetResult(fs);
			JB_Incr(result);
			JB_String* b = JB_Str_DecodeB64(result, nil);
			JB_Incr(b);
			JB_Decr(result);
			if ((!(JB_Str_SyntaxEquals(a, b, false)))) {
				FastString* _fs_fs = JB_FS__New();
				JB_Incr(_fs_fs);
				JB_FS_AppendString(_fs_fs, JB_str_38);
				JB_FS_AppendString(_fs_fs, a);
				JB_FS_AppendString(_fs_fs, JB_str_39);
				JB_FS_AppendString(_fs_fs, b);
				JB_String* _fs_str = JB_FS_SyntaxCastString(_fs_fs);
				JB_Incr(_fs_str);
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
			JB_String* _tmp214 = JB_Str_OperatorPlus(JB_str_40, a);
			JB_Incr(_tmp214);
			JB_SetRef(a, JB_Str_OperatorPlus(a, _tmp214));
			JB_Decr(_tmp214);
			_i1++;
		};
	};
	JB_Decr(a);
	JB_FS_AppendHexData1(fs, AllBytes);
	JB_String* Hexed = JB_FS_GetResult(fs);
	JB_Incr(Hexed);
	JB_FS_AppendMultiByte(fs, 0, 256);
	JB_String* Str2 = JB_FS_GetResult(fs);
	JB_Incr(Str2);
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
	FastString* _fs_fs = JB_FS__New();
	JB_Incr(_fs_fs);
	JB_FS_AppendString(_fs_fs, JB_str_64);
	JB_String* _tmp249 = JB_Msg_Locate(expected);
	JB_Incr(_tmp249);
	JB_FS_AppendString(_fs_fs, _tmp249);
	JB_Decr(_tmp249);
	JB_FS_AppendString(_fs_fs, JB_str_65);
	JB_String* _tmp250 = JB_Msg_Locate(found);
	JB_Incr(_tmp250);
	JB_FS_AppendString(_fs_fs, _tmp250);
	JB_Decr(_tmp250);
	JB_String* _fs_str = JB_FS_SyntaxCastString(_fs_fs);
	JB_Incr(_fs_str);
	JB_SetRef(_fs_fs, nil);
	JB_Decr(_fs_fs);
	JB_Str_PrintLine(_fs_str);
	JB_Decr(_fs_str);
	FastString* _fs1_fs = JB_FS__New();
	JB_Incr(_fs1_fs);
	JB_FS_AppendString(_fs1_fs, JB_str_66);
	JB_String* _tmp251 = JB_Msg_Locate(JB_Msg_PoorAnt(expected));
	JB_Incr(_tmp251);
	JB_FS_AppendString(_fs1_fs, _tmp251);
	JB_Decr(_tmp251);
	JB_String* _fs1_str = JB_FS_SyntaxCastString(_fs1_fs);
	JB_Incr(_fs1_str);
	JB_SetRef(_fs1_fs, nil);
	JB_Decr(_fs1_fs);
	JB_Str_PrintLine(_fs1_str);
	JB_Decr(_fs1_str);
	if (found) {
		FastString* _fs2_fs = JB_FS__New();
		JB_Incr(_fs2_fs);
		JB_FS_AppendString(_fs2_fs, JB_str_67);
		JB_String* _tmp252 = JB_Msg_Locate(JB_Msg_PoorAnt(found));
		JB_Incr(_tmp252);
		JB_FS_AppendString(_fs2_fs, _tmp252);
		JB_Decr(_tmp252);
		JB_String* _fs2_str = JB_FS_SyntaxCastString(_fs2_fs);
		JB_Incr(_fs2_str);
		JB_SetRef(_fs2_fs, nil);
		JB_Decr(_fs2_fs);
		JB_Str_PrintLine(_fs2_str);
		JB_Decr(_fs2_str);
	} else {
		found = expected;
	}
	JB_Msg_Fail(found, nil);
	return false;
}

Dictionary* JB_Dict_Copy(Dictionary* Dict) {
	Dictionary* result = JB_Dict__New();
	JB_Incr(result);
	{
		DictionaryReader* _nav = JB_Dict_Navigate(Dict);
		JB_Incr(_nav);
		while (JB_Nav_MoveNext(_nav)) {
			JB_String* key = JB_Nav_Name(_nav);
			JB_Incr(key);
			JB_String* value = ((JB_String*)JB_Nav_Value(_nav));
			JB_Incr(value);
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
	JB_String* raw = JB_str_68;
	JB_Incr(raw);
	JB_String* replicate = JB_str_69;
	JB_Incr(replicate);
	Dictionary* repl = JB_Dict__New();
	JB_Incr(repl);
	(JB_Dict_ValueSet(repl, JB_str_70, JB_str_15));
	JB_MSR_DecodeEntitySet(repl, true);
	JB_MSR_EscapeCodeSet(repl, true);
	JB_String* s3 = JB_Str_Unescape(replicate);
	JB_Incr(s3);
	JB_SetRef(replicate, JB_Str_MultiReplaceAll(replicate, repl, JB_StdErr));
	JB_Decr(repl);
	if ((!JB_Str_SyntaxEquals(raw, replicate, false))) {
		debugger;
	}
	if ((!JB_Str_SyntaxEquals(raw, s3, false))) {
		debugger;
	}
	JB_Decr(s3);
	JB_Decr(raw);
	if (JB_Platform__linux()) {
		JB_SetRef(replicate, JB_str_71);
	}
	JB_String* result = JB_Str_OperatorPlus(replicate, JB_str_72);
	JB_Incr(result);
	JB_Decr(replicate);
	JB_SafeDecr(result);
	return result;
}

int JB_Init_() {
	{
		JB_SetRef(JB_str_261, JB_Str3("Binary", 6));
		JB_SetRef(JB_str_260, JB_Str3("bin", 3));
		JB_SetRef(JB_str_259, JB_Str3("unit", 4));
		JB_SetRef(JB_str_258, JB_Str3("Typecast", 8));
		JB_SetRef(JB_str_257, JB_Str3("type", 4));
		JB_SetRef(JB_str_256, JB_Str3("Conjugate", 9));
		JB_SetRef(JB_str_255, JB_Str3("cnj", 3));
		JB_SetRef(JB_str_254, JB_Str3("Syntactic_Conjugate", 19));
		JB_SetRef(JB_str_253, JB_Str3("scnj", 4));
		JB_SetRef(JB_str_252, JB_Str3("Temporal_Reference", 18));
		JB_SetRef(JB_str_251, JB_Str3("ana", 3));
		JB_SetRef(JB_str_250, JB_Str3("Temporal_Statement", 18));
		JB_SetRef(JB_str_249, JB_Str3("tmp", 3));
		JB_SetRef(JB_str_248, JB_Str3("Thing", 5));
		JB_SetRef(JB_str_247, JB_Str3("thg", 3));
		JB_SetRef(JB_str_246, JB_Str3("Syntactic_Thing", 15));
		JB_SetRef(JB_str_245, JB_Str3("sthg", 4));
		JB_SetRef(JB_str_244, JB_Str3("String", 6));
		JB_SetRef(JB_str_243, JB_Str3("str", 3));
		JB_SetRef(JB_str_242, JB_Str3("Shebang", 7));
		JB_SetRef(JB_str_241, JB_Str3("sheb", 4));
		JB_SetRef(JB_str_240, JB_Str3("Syntactic_Comment", 17));
		JB_SetRef(JB_str_239, JB_Str3("scom", 4));
		JB_SetRef(JB_str_238, JB_Str3("Self_Dot", 8));
		JB_SetRef(JB_str_237, JB_Str3("sdot", 4));
		JB_SetRef(JB_str_236, JB_Str3("Temporal_Relationship", 21));
		JB_SetRef(JB_str_235, JB_Str3("trel", 4));
		JB_SetRef(JB_str_234, JB_Str3("Relationship", 12));
		JB_SetRef(JB_str_233, JB_Str3("rel", 3));
		JB_SetRef(JB_str_232, JB_Str3("Syntactic_Operator", 18));
		JB_SetRef(JB_str_231, JB_Str3("sopp", 4));
		JB_SetRef(JB_str_230, JB_Str3("Operator", 8));
		JB_SetRef(JB_str_229, JB_Str3("opp", 3));
		JB_SetRef(JB_str_228, JB_Str3("Operator_As_Thing", 17));
		JB_SetRef(JB_str_227, JB_Str3("oat", 3));
		JB_SetRef(JB_str_226, JB_Str3("Number", 6));
		JB_SetRef(JB_str_225, JB_Str3("num", 3));
		JB_SetRef(JB_str_224, JB_Str3("name", 4));
		JB_SetRef(JB_str_223, JB_Str3("Parameters", 10));
		JB_SetRef(JB_str_222, JB_Str3("prm", 3));
		JB_SetRef(JB_str_221, JB_Str3("item", 4));
		JB_SetRef(JB_str_220, JB_Str3("Function", 8));
		JB_SetRef(JB_str_219, JB_Str3("func", 4));
		JB_SetRef(JB_str_218, JB_Str3("Equals_Relationship", 19));
		JB_SetRef(JB_str_217, JB_Str3("erel", 4));
		JB_SetRef(JB_str_216, JB_Str3("Embedded_Value", 14));
		JB_SetRef(JB_str_215, JB_Str3("emb", 3));
		JB_SetRef(JB_str_214, JB_Str3("Dot", 3));
		JB_SetRef(JB_str_213, JB_Str3("dot", 3));
		JB_SetRef(JB_str_212, JB_Str3("Declaration", 11));
		JB_SetRef(JB_str_211, JB_Str3("decl", 4));
		JB_SetRef(JB_str_210, JB_Str3("Character", 9));
		JB_SetRef(JB_str_209, JB_Str3("char", 4));
		JB_SetRef(JB_str_208, JB_Str3("Before_Relationship", 19));
		JB_SetRef(JB_str_207, JB_Str3("brel", 4));
		JB_SetRef(JB_str_206, JB_Str3("Bracket", 7));
		JB_SetRef(JB_str_205, JB_Str3("bra", 3));
		JB_SetRef(JB_str_204, JB_Str3("Super_String", 12));
		JB_SetRef(JB_str_203, JB_Str3("sstr", 4));
		JB_SetRef(JB_str_202, JB_Str3("Backtick", 8));
		JB_SetRef(JB_str_201, JB_Str3("back", 4));
		JB_SetRef(JB_str_200, JB_Str3("Array", 5));
		JB_SetRef(JB_str_199, JB_Str3("arr", 3));
		JB_SetRef(JB_str_198, JB_Str3("After_Relationship", 18));
		JB_SetRef(JB_str_197, JB_Str3("arel", 4));
		JB_SetRef(JB_str_196, JB_Str3("Adjective", 9));
		JB_SetRef(JB_str_195, JB_Str3("adj", 3));
		JB_SetRef(JB_str_194, JB_Str3("Access", 6));
		JB_SetRef(JB_str_193, JB_Str3("acc", 3));
		JB_SetRef(JB_str_192, JB_Str3("Argument", 8));
		JB_SetRef(JB_str_191, JB_Str3("arg", 3));
		JB_SetRef(JB_str_190, JB_Str3("AZazÄø¬Ù", 8));
		JB_SetRef(JB_str_189, JB_Str3("\n\r,", 3));
		JB_SetRef(JB_str_188, JB_Str3(" ,:\t\n\r\\", 7));
		JB_SetRef(JB_str_187, JB_Str3("\n\r", 2));
		JB_SetRef(JB_str_186, JB_Str3("AZaz__Äø¬Ù", 10));
		JB_SetRef(JB_str_185, JB_Str3("AZaz09__Äø¬Ù", 12));
		JB_SetRef(JB_str_184, JB_Str3("$\\{", 3));
		JB_SetRef(JB_str_183, JB_Str3("\\&#", 3));
		JB_SetRef(JB_str_182, JB_Str3("&#", 2));
		JB_SetRef(JB_str_181, JB_Str3("\\\\", 2));
		JB_SetRef(JB_str_180, JB_Str3("\\", 1));
		JB_SetRef(JB_str_179, JB_Str3("\\t", 2));
		JB_SetRef(JB_str_178, JB_Str3("\\'", 2));
		JB_SetRef(JB_str_177, JB_Str3("\\\"", 2));
		JB_SetRef(JB_str_176, JB_Str3("\\r", 2));
		JB_SetRef(JB_str_175, JB_Str3("\r", 1));
		JB_SetRef(JB_str_174, JB_Str3("\\0", 2));
		JB_SetRef(JB_str_173, JB_Str3("\0", 1));
		JB_SetRef(JB_str_172, JB_Str3(", but found ", 12));
		JB_SetRef(JB_str_171, JB_Str3("[0;1;33m", 9));
		JB_SetRef(JB_str_170, JB_Str3("[0;1;32m", 9));
		JB_SetRef(JB_str_169, JB_Str3("[0;1;31m", 9));
		JB_SetRef(JB_str_168, JB_Str3("[0;1m", 6));
		JB_SetRef(JB_str_167, JB_Str3("[0m", 4));
		JB_SetRef(JB_str_166, JB_Str3("@JBSave\n", 8));
		JB_SetRef(JB_str_165, JB_Str3("Manual inspection:\n\n", 20));
		JB_SetRef(JB_str_164, JB_Str3("entities", 8));
		JB_SetRef(JB_str_163, JB_Str3("  abc", 5));
		JB_SetRef(JB_str_162, JB_Str3(" a", 2));
		JB_SetRef(JB_str_161, JB_Str3("  ", 2));
		JB_SetRef(JB_str_160, JB_Str3("\n(tmp: \"how\"\n\t(oat: \n\t\t(opp: \"can\")\n\t\t(trel: \n\t\t\t(rel: \n\t\t\t\t(ana: \"someone\")\n\t\t\t\t(opp: \"fall\")\n\t\t\t\t(adj: \n\t\t\t\t\t(thg: \"so\")\n\t\t\t\t\t(thg: \"far\")\n\t\t\t\t)\n\t\t\t)\n\t\t\t(cnj: \"without\")\n\t\t\t(oat: \n\t\t\t\t(opp: \"realising\")\n\t\t\t\t(thg: \"‚Äìit\")\n\t\t\t)\n\t\t)\n\t)\n)\n(tmp: \"story\"\n\t(thg: \"X\")\n\t(list: \n\t\t(trel: \n\t\t\t(rel: \n\t\t\t\t(thg: \"x\")\n\t\t\t\t(bra: \n\t\t\t\t\t(adj: \n\t\t\t\t\t\t(opp: \"a\")\n\t\t\t\t\t\t(opp: \"b\")\n\t\t\t\t\t)\n\t\t\t\t)\n\t\t\t\t(ana: \"c\")\n\t\t\t)\n\t\t\t(scnj: \"-->\")\n\t\t\t(rel: \n\t\t\t\t(ana: \"You\")\n\t\t\t\t(opp: \"can\")\n\t\t\t\t(oat: \n\t\t\t\t\t(opp: \"describe\")\n\t\t\t\t\t(list: \n\t\t\t\t\t\t(thg: \"anything\")\n\t\t\t\t\t\t(item: \n\t\t\t\t\t\t\t(thg: \"with\")\n\t\t\t\t\t\t\t(rel: \n\t\t\t\t\t\t\t\t(name: \"sonic\"\n\t\t\t\t\t\t\t\t\t(adj: \n\t\t\t\t\t\t\t\t\t\t(thg: \"the\")\n\t\t\t\t\t\t\t\t\t\t(thg: \"hedgedog\")\n\t\t\t\t\t\t\t\t\t)\n\t\t\t\t\t\t\t\t)\n\t\t\t\t\t\t\t\t(opp: \"or\")\n\t\t\t\t\t\t\t\t(name: \"jeebox\")\n\t\t\t\t\t\t\t)\n\t\t\t\t\t\t)\n\t\t\t\t\t)\n\t\t\t\t)\n\t\t\t)\n\t\t)\n\t\t(trel: \n\t\t\t(rel: \n\t\t\t\t(thg: \"A\")\n\t\t\t\t(bra: \n\t\t\t\t\t(rel: \n\t\t\t\t\t\t(adj: \n\t\t\t\t\t\t\t(bra: \n\t\t\t\t\t\t\t\t(adj: \n\t\t\t\t\t\t\t\t\t(opp: \"B\")\n\t\t\t\t\t\t\t\t\t(opp: \"C\")\n\t\t\t\t\t\t\t\t)\n\t\t\t\t\t\t\t)\n\t\t\t\t\t\t\t(opp: \"D\")\n\t\t\t\t\t\t)\n\t\t\t\t\t\t(opp: \"E\")\n\t\t\t\t\t\t(adj: \n\t\t\t\t\t\t\t(opp: \"F\")\n\t\t\t\t\t\t\t(opp: \"G\")\n\t\t\t\t\t\t)\n\t\t\t\t\t)\n\t\t\t\t)\n\t\t\t\t(thg: \"I\")\n\t\t\t)\n\t\t\t(cnj: \"W\")\n\t\t\t(rel: \n\t\t\t\t(thg: \"A\")\n\t\t\t\t(opp: \"t\")\n\t\t\t\t(list: \n\t\t\t\t\t(item: \n\t\t\t\t\t\t(thg: \"o\")\n\t\t\t\t\t\t(thg: \"c\")\n\t\t\t\t\t)\n\t\t\t\t)\n\t\t\t)\n\t\t)\n\t)\n)\n(tmp: \"za\"\n\t(tmp: \"xb\"\n\t\t(arg: \n\t\t\t(decl: \n\t\t\t\t(num: \"1\")\n\t\t\t\t(rel: \n\t\t\t\t\t(thg: \"x\")\n\t\t\t\t\t(opp: \"*\")\n\t\t\t\t\t(rel: \n\t\t\t\t\t\t(thg: \"y\")\n\t\t\t\t\t\t(opp: \"*\")\n\t\t\t\t\t\t(rel: \n\t\t\t\t\t\t\t(thg: \"z\")\n\t\t\t\t\t\t\t(opp: \"=\")\n\t\t\t\t\t\t\t(brel: \"\?\"\n\t\t\t\t\t\t\t\t(arel: \"\?\"\n\t\t\t\t\t\t\t\t\t(list: )\n\t\t\t\t\t\t\t\t)\n\t\t\t\t\t\t\t)\n\t\t\t\t\t\t)\n\t\t\t\t\t)\n\t\t\t\t)\n\t\t\t)\n\t\t\t(decl: \n\t\t\t\t(emb: )\n\t\t\t\t(rel: \n\t\t\t\t\t(thg: \"a\")\n\t\t\t\t\t(opp: \"=\")\n\t\t\t\t\t(rel: \n\t\t\t\t\t\t(thg: \"c\")\n\t\t\t\t\t\t(opp: \"or\")\n\t\t\t\t\t\t(thg: \"d\")\n\t\t\t\t\t)\n\t\t\t\t)\n\t\t\t)\n\t\t\t(scom: \n\t\t\t\t(arg: \n\t\t\t\t\t(rel: \n\t\t\t\t\t\t(adj: \n\t\t\t\t\t\t\t(thg: \"vvv\")\n\t\t\t\t\t\t\t(thg: \"fff\")\n\t\t\t\t\t\t)\n\t\t\t\t\t\t(adj: \n\t\t\t\t\t\t\t(opp: \"v\")\n\t\t\t\t\t\t\t(opp: \"f\")\n\t\t\t\t\t\t)\n\t\t\t\t\t)\n\t\t\t\t)\n\t\t\t\t(list: \n\t\t\t\t\t(thg: \"a\")\n\t\t\t\t)\n\t\t\t)\n\t\t\t(list: \n\t\t\t\t(trel: \n\t\t\t\t\t(arr: )\n\t\t\t\t\t(scnj: \"-->\")\n\t\t\t\t\t(rel: \n\t\t\t\t\t\t(thg: \"a\")\n\t\t\t\t\t\t(opp: \"+\")\n\t\t\t\t\t\t(thg: \"a\")\n\t\t\t\t\t)\n\t\t\t\t)\n\t\t\t\t(thg: \"b\")\n\t\t\t\t(item: \n\t\t\t\t\t(thg: \"d\")\n\t\t\t\t\t(thg: \"e\")\n\t\t\t\t)\n\t\t\t)\n\t\t\t(arr: \n\t\t\t\t(type: \n\t\t\t\t\t(thg: \"d\")\n\t\t\t\t\t(num: \"0\")\n\t\t\t\t)\n\t\t\t\t(item: \n\t\t\t\t\t(rel: \n\t\t\t\t\t\t(thg: \"a\")\n\t\t\t\t\t\t(opp: \"+\")\n\t\t\t\t\t\t(thg: \"b\")\n\t\t\t\t\t)\n\t\t\t\t\t(thg: \"c\")\n\t\t\t\t)\n\t\t\t\t(arr: \n\t\t\t\t\t(thg: \"c\")\n\t\t\t\t\t(thg: \"d\")\n\t\t\t\t)\n\t\t\t)\n\t\t)\n\t)\n)\n(bin: \"binary encoding oof\")\n(tmp: \"function\"\n\t(thg: \"name\")\n\t(list: \n\t\t(decl: \n\t\t\t(item: \n\t\t\t\t(thg: \"x\")\n\t\t\t\t(rel: \n\t\t\t\t\t(thg: \"y\")\n\t\t\t\t\t(opp: \"+\")\n\t\t\t\t\t(thg: \"z\")\n\t\t\t\t)\n\t\t\t)\n\t\t\t(adj: \n\t\t\t\t(thg: \"a\")\n\t\t\t\t(thg: \"b\")\n\t\t\t)\n\t\t)\n\t\t(decl: \n\t\t\t(emb: )\n\t\t)\n\t)\n\t(arg: \n\t\t(item: \n\t\t\t(thg: \"label\")\n\t\t\t(func: \n\t\t\t\t(thg: \"func\")\n\t\t\t\t(prm: )\n\t\t\t)\n\t\t)\n\t\t(str: \"'\\\"stri√±g test\\\"'\")\n\t\t(back: \"\\\\n\\\\(\\&#x134;\\&#xEB;\\\\C3\\\\AA\\\\C6\\\\81o\\&#9447;\\\\)\")\n\t\t(erel: \n\t\t\t(brel: \"--\"\n\t\t\t\t(arel: \"--\"\n\t\t\t\t\t(thg: \"x\")\n\t\t\t\t)\n\t\t\t)\n\t\t\t(opp: \"mod\")\n\t\t\t(char: \"ioi '\\\"\\\"'oio\")\n\t\t)\n\t\t(dot: \"y\"\n\t\t\t(dot: \"size\"\n\t\t\t\t(thg: \"y\")\n\t\t\t\t(prm: \n\t\t\t\t\t(arel: \"\?\"\n\t\t\t\t\t\t(sthg: \"...\")\n\t\t\t\t\t)\n\t\t\t\t\t(sthg: \"...\")\n\t\t\t\t\t(sstr: \"s`t`r\")\n\t\t\t\t)\n\t\t\t)\n\t\t\t(prm: \n\t\t\t\t(brel: \"-\"\n\t\t\t\t\t(thg: \"z\")\n\t\t\t\t)\n\t\t\t)\n\t\t)\n\t\t(rel: \n\t\t\t(thg: \"x\")\n\t\t\t(opp: \"=\")\n\t\t\t(rel: \n\t\t\t\t(str: \n\t\t\t\t\t(emb: \"{ab\")\n\t\t\t\t\t(thg: \"x\")\n\t\t\t\t\t(emb: \" \")\n\t\t\t\t\t(thg: \"y\")\n\t\t\t\t\t(thg: \"z\")\n\t\t\t\t\t(emb: \"ab}\")\n\t\t\t\t)\n\t\t\t\t(opp: \"+\")\n\t\t\t\t(back: \"abc\")\n\t\t\t)\n\t\t)\n\t\t(erel: \n\t\t\t(type: \n\t\t\t\t(thg: \"z\")\n\t\t\t\t(list: \n\t\t\t\t\t(thg: \"a\")\n\t\t\t\t)\n\t\t\t)\n\t\t\t(opp: \"+\")\n\t\t\t(sdot: \"exit\"\n\t\t\t\t(prm: \n\t\t\t\t\t(item: \n\t\t\t\t\t\t(thg: \"code\")\n\t\t\t\t\t\t(num: \"-3\")\n\t\t\t\t\t)\n\t\t\t\t)\n\t\t\t)\n\t\t)\n\t\t(tmp: \"for\"\n\t\t\t(list: \n\t\t\t\t(item: \n\t\t\t\t\t(thg: \"a\")\n\t\t\t\t\t(thg: \"b\")\n\t\t\t\t)\n\t\t\t)\n\t\t\t(arg: \n\t\t\t\t(rel: \n\t\t\t\t\t(brel: \"$\"\n\t\t\t\t\t\t(arel: \"$\"\n\t\t\t\t\t\t\t(thg: \"a\")\n\t\t\t\t\t\t)\n\t\t\t\t\t)\n\t\t\t\t\t(opp: \"=\")\n\t\t\t\t\t(rel: \n\t\t\t\t\t\t(brel: \"&\"\n\t\t\t\t\t\t\t(arel: \"&\"\n\t\t\t\t\t\t\t\t(thg: \"b\")\n\t\t\t\t\t\t\t)\n\t\t\t\t\t\t)\n\t\t\t\t\t\t(opp: \"+\")\n\t\t\t\t\t\t(brel: \"!\"\n\t\t\t\t\t\t\t(arel: \"!\"\n\t\t\t\t\t\t\t\t(thg: \"c\")\n\t\t\t\t\t\t\t)\n\t\t\t\t\t\t)\n\t\t\t\t\t)\n\t\t\t\t)\n\t\t\t)\n\t\t)\n\t\t(tmp: \"if\"\n\t\t\t(rel: \n\t\t\t\t(bra: \n\t\t\t\t\t(rel: \n\t\t\t\t\t\t(char: \"a\")\n\t\t\t\t\t\t(opp: \"&&&\")\n\t\t\t\t\t\t(rel: \n\t\t\t\t\t\t\t(thg: \"b\")\n\t\t\t\t\t\t\t(opp: \"===\")\n\t\t\t\t\t\t\t(rel: \n\t\t\t\t\t\t\t\t(brel: \"!\"\n\t\t\t\t\t\t\t\t\t(brel: \"!\"\n\t\t\t\t\t\t\t\t\t\t(brel: \"!\"\n\t\t\t\t\t\t\t\t\t\t\t(thg: \"b\")\n\t\t\t\t\t\t\t\t\t\t)\n\t\t\t\t\t\t\t\t\t)\n\t\t\t\t\t\t\t\t)\n\t\t\t\t\t\t\t\t(opp: \"|||\")\n\t\t\t\t\t\t\t\t(thg: \"c\")\n\t\t\t\t\t\t\t)\n\t\t\t\t\t\t)\n\t\t\t\t\t)\n\t\t\t\t)\n\t\t\t\t(opp: \"^^^\")\n\t\t\t\t(bra: \n\t\t\t\t\t(rel: \n\t\t\t\t\t\t(thg: \"a\")\n\t\t\t\t\t\t(opp: \"~>=\")\n\t\t\t\t\t\t(thg: \"b\")\n\t\t\t\t\t)\n\t\t\t\t)\n\t\t\t)\n\t\t\t(arg: \n\t\t\t\t(tmp: \"return\"\n\t\t\t\t\t(tmp: \"return\"\n\t\t\t\t\t\t(rel: \n\t\t\t\t\t\t\t(unit: \"x\"\n\t\t\t\t\t\t\t\t(num: \"0ff_\")\n\t\t\t\t\t\t\t)\n\t\t\t\t\t\t\t(opp: \"+\")\n\t\t\t\t\t\t\t(unit: \"miles\"\n\t\t\t\t\t\t\t\t(num: \"10_\")\n\t\t\t\t\t\t\t)\n\t\t\t\t\t\t)\n\t\t\t\t\t)\n\t\t\t\t)\n\t\t\t)\n\t\t)\n\t)\n)\n", 4464));
		JB_SetRef(JB_str_159, JB_Str3("// Jeebox self-test file.\n// Tests all syntax in small amount of code.\n// Does not make sense in any other way.\n\nhow %can \\someone fall so~far #without %realising ‚Äìit\n\n\nstory X (\n\tx (a ~ \\\n\t\tb) \\c\n\t\t\t-->\n\t~~You can % describe (anything, with:sonic@the~hedgedog or @jeebox)\n\n\tA ((B~C)~D E F~G) I #W A t (o:c)\n)\n\n\n\n\nza::xb {\n\t|1| x * y * z = \?()\?\n\t|| a = c or d\n\t(a,) /#vvv~fff v~f#/\n\t([] --> a + a,b,d:e)\n\t[d|0|, a+b:c, [c, d]] /* /*\n\t\tnested comments!\n\t\t*/ I found it useful.*/\n\n\t// }\n}\n\n#(OcbkON9v86LkOszaQMvd86zlPW)#\n\nfunction name (|x:y+z| a ~ b, ||) {\n\tlabel: func()\n\t\"'\\\"stri\\c3\\b1g test\\\"'\"\n\t`\\n\\(&#x134;&#xEB;\\C3\\AA\\C6\\81o&#9447;\\)`\n\t--x-- mod= 'ioi \\'\"\"\\'oio'\n\t\n\ty.size(...\?, ..., <(`s`t`r`)>).y(-z)\n\n\tx = \"{ab$\{x} $\{y}$\{z}ab}\" + `abc`\n\tz|(a,)| += .exit(code: -3)\n\n\tfor (a : b) {\n\t\t$a$ = &b& + !c!\n\t}\n\n\tif ('a' &&& b === !!!b ||| c) ^^^ (a ~>= b) {\n\t\treturn::return 0ff_x + 10_miles\n\t}\n}\n\n\n", 900));
		JB_SetRef(JB_str_158, JB_Str3(": Failed\n\n", 10));
		JB_SetRef(JB_str_157, JB_Str3("Test ", 5));
		JB_SetRef(JB_str_156, JB_Str3("list", 4));
		JB_SetRef(JB_str_155, JB_Str3("normal", 6));
		JB_SetRef(JB_str_154, JB_Str3(" in ", 4));
		JB_SetRef(JB_str_153, JB_Str3("' at byte: ", 11));
		JB_SetRef(JB_str_152, JB_Str3(": '", 3));
		JB_SetRef(JB_str_151, JB_Str3("(nil)", 5));
		JB_SetRef(JB_str_150, JB_Str3("something else", 14));
		JB_SetRef(JB_str_149, JB_Str3(" / ", 3));
		JB_SetRef(JB_str_148, JB_Str3("illegal-character", 17));
		JB_SetRef(JB_str_147, JB_Str3("thing", 5));
		JB_SetRef(JB_str_146, JB_Str3("'|'", 3));
		JB_SetRef(JB_str_145, JB_Str3("temporal-operator", 17));
		JB_SetRef(JB_str_144, JB_Str3("operator", 8));
		JB_SetRef(JB_str_143, JB_Str3("syntactic-operator", 18));
		JB_SetRef(JB_str_142, JB_Str3("':'", 3));
		JB_SetRef(JB_str_141, JB_Str3("temporal-word", 13));
		JB_SetRef(JB_str_140, JB_Str3("declaration", 11));
		JB_SetRef(JB_str_139, JB_Str3("temporal", 8));
		JB_SetRef(JB_str_138, JB_Str3("0x", 2));
		JB_SetRef(JB_str_137, JB_Str3("Found illegal-character ", 24));
		JB_SetRef(JB_str_136, JB_Str3("end-of-data", 11));
		JB_SetRef(JB_str_135, JB_Str3("syntactic-comment", 17));
		JB_SetRef(JB_str_134, JB_Str3("end-of-line", 11));
		JB_SetRef(JB_str_133, JB_Str3("Unexpected ", 11));
		JB_SetRef(JB_str_132, JB_Str3("Expected a letter (aA-zZ, '_', etc).", 36));
		JB_SetRef(JB_str_131, JB_Str3("Can‚Äôt use temporals like this.", 32));
		JB_SetRef(JB_str_130, JB_Str3("Must be a proper name (a-z or letters)", 38));
		JB_SetRef(JB_str_129, JB_Str3("' not allowed.", 14));
		JB_SetRef(JB_str_128, JB_Str3("Nested '", 8));
		JB_SetRef(JB_str_127, JB_Str3("#/", 2));
		JB_SetRef(JB_str_126, JB_Str3("Embedded expression didn't close.", 33));
		JB_SetRef(JB_str_125, JB_Str3("No expression found.", 20));
		JB_SetRef(JB_str_124, JB_Str3("}", 1));
		JB_SetRef(JB_str_123, JB_Str3("$\{", 2));
		JB_SetRef(JB_str_122, JB_Str3("String didn't close!", 20));
		JB_SetRef(JB_str_121, JB_Str3("Can‚Äôt have '=' after this operator.", 37));
		JB_SetRef(JB_str_120, JB_Str3("Comment did not close.", 22));
		JB_SetRef(JB_str_119, JB_Str3("Char didn't close!", 18));
		JB_SetRef(JB_str_118, JB_Str3("String did not close.", 21));
		JB_SetRef(JB_str_117, JB_Str3("Missing '", 9));
		JB_SetRef(JB_str_116, JB_Str3("] ) } #/ /~", 11));
		JB_SetRef(JB_str_115, JB_Str3("/#", 2));
		JB_SetRef(JB_str_114, JB_Str3("~~~", 3));
		JB_SetRef(JB_str_113, JB_Str3("`", 1));
		JB_SetRef(JB_str_112, JB_Str3("\"", 1));
		JB_SetRef(JB_str_111, JB_Str3("...", 3));
		JB_SetRef(JB_str_110, JB_Str3(",", 1));
		JB_SetRef(JB_str_109, JB_Str3("/*", 2));
		JB_SetRef(JB_str_108, JB_Str3("//", 2));
		JB_SetRef(JB_str_107, JB_Str3("\\ ~~", 4));
		JB_SetRef(JB_str_106, JB_Str3("--> <-- <-->", 12));
		JB_SetRef(JB_str_105, JB_Str3("#", 1));
		JB_SetRef(JB_str_104, JB_Str3("{", 1));
		JB_SetRef(JB_str_103, JB_Str3(":", 1));
		JB_SetRef(JB_str_102, JB_Str3("- *", 3));
		JB_SetRef(JB_str_101, JB_Str3("~", 1));
		JB_SetRef(JB_str_100, JB_Str3("@", 1));
		JB_SetRef(JB_str_99, JB_Str3("|", 1));
		JB_SetRef(JB_str_98, JB_Str3("[", 1));
		JB_SetRef(JB_str_97, JB_Str3("(", 1));
		JB_SetRef(JB_str_96, JB_Str3("++ -- $ & ! \?", 13));
		JB_SetRef(JB_str_95, JB_Str3("* ** / + - ^ >> << >>> <<< ||| &&& ^^^", 38));
		JB_SetRef(JB_str_94, JB_Str3("= == === < > <= <== >= >== != !== <=> ~>= ~<= ~> ~< ~= ~!= ~<=> :=", 66));
		JB_SetRef(JB_str_93, JB_Str3("0123456789", 10));
		JB_SetRef(JB_str_92, JB_Str3("\r \n", 3));
		JB_SetRef(JB_str_91, JB_Str3("‚Äù", 3));
		JB_SetRef(JB_str_90, JB_Str3(" ‚Äú", 4));
		JB_SetRef(JB_str_89, JB_Str3("Unexpected syntax. Found ", 25));
		JB_SetRef(JB_str_88, JB_Str3("' ", 2));
		JB_SetRef(JB_str_87, JB_Str3(" '", 2));
		JB_SetRef(JB_str_86, JB_Str3("line ", 5));
		JB_SetRef(JB_str_85, JB_Str3("\t", 1));
		JB_SetRef(JB_str_84, JB_Str3("Internal error.", 15));
		JB_SetRef(JB_str_83, JB_Str3("Binary section didn't close!", 28));
		JB_SetRef(JB_str_82, JB_Str3(")#", 2));
		JB_SetRef(JB_str_81, JB_Str3("#(", 2));
		JB_SetRef(JB_str_80, JB_Str3("nil", 3));
		JB_SetRef(JB_str_79, JB_Str3("' but found '", 13));
		JB_SetRef(JB_str_78, JB_Str3("' on '", 6));
		JB_SetRef(JB_str_77, JB_Str3("Expected suffix '", 17));
		JB_SetRef(JB_str_76, JB_Str3("~/Desktop/Decomp.txt", 20));
		JB_SetRef(JB_str_75, JB_Str3("~/Desktop/Original.txt", 22));
		JB_SetRef(JB_str_74, JB_Str3("abc ", 4));
		JB_SetRef(JB_str_73, JB_Str3("\0\0\0\0\0\0", 6));
		JB_SetRef(JB_str_72, JB_Str3(" loaded successfully.\n", 22));
		JB_SetRef(JB_str_71, JB_Str3("jeebox", 6));
		JB_SetRef(JB_str_70, JB_Str3("\\n", 2));
		JB_SetRef(JB_str_69, JB_Str3("\\n\\(&#x134;&#xEB;\\C3\\AA\\C6\\81o&#9447; \\) ", 41));
		JB_SetRef(JB_str_68, JB_Str3("\n(ƒ¥√´√™∆Åo‚ìß ) ", 17));
		JB_SetRef(JB_str_67, JB_Str3("parent of found ", 16));
		JB_SetRef(JB_str_66, JB_Str3("parent of expected ", 19));
		JB_SetRef(JB_str_65, JB_Str3(" but found ", 11));
		JB_SetRef(JB_str_64, JB_Str3("Expected ", 9));
		JB_SetRef(JB_str_63, JB_Str3("Missing child ", 14));
		JB_SetRef(JB_str_62, JB_Str3("Missing ", 8));
		JB_SetRef(JB_str_61, JB_Str3("~~", 2));
		JB_SetRef(JB_str_60, JB_Str3("::", 2));
		JB_SetRef(JB_str_59, JB_Str3("#!", 2));
		JB_SetRef(JB_str_58, JB_Str3(" #/", 3));
		JB_SetRef(JB_str_57, JB_Str3(" /# ", 4));
		JB_SetRef(JB_str_56, JB_Str3(" @ ", 3));
		JB_SetRef(JB_str_55, JB_Str3(": ", 2));
		JB_SetRef(JB_str_54, JB_Str3("= ", 2));
		JB_SetRef(JB_str_53, JB_Str3("<(`", 3));
		JB_SetRef(JB_str_52, JB_Str3("`)>", 3));
		JB_SetRef(JB_str_51, JB_Str3("{\n", 2));
		JB_SetRef(JB_str_50, JB_Str3(", ", 2));
		JB_SetRef(JB_str_49, JB_Str3("Can‚Äôt find syntax: ", 21));
		JB_SetRef(JB_str_48, JB_Str3("Jeebox: Too many NilObjectErrors. Silencing.", 44));
		JB_SetRef(JB_str_47, JB_Str3("Jeebox: NilObjectError in caller.", 33));
		JB_SetRef(JB_str_46, JB_Str3("').", 3));
		JB_SetRef(JB_str_45, JB_Str3("' (found '", 10));
		JB_SetRef(JB_str_44, JB_Str3("Can‚Äôt parse number '", 22));
		JB_SetRef(JB_str_43, JB_Str3("s found.\n", 9));
		JB_SetRef(JB_str_42, JB_Str3("error", 5));
		JB_SetRef(JB_str_41, JB_Str3("warning", 7));
		JB_SetRef(JB_str_40, JB_Str3("z", 1));
		JB_SetRef(JB_str_39, JB_Str3(" b: ", 4));
		JB_SetRef(JB_str_38, JB_Str3("binary escaper different! a: ", 29));
		JB_SetRef(JB_str_37, JB_Str3("they know what they've done", 27));
		JB_SetRef(JB_str_36, JB_Str3(" ", 1));
		JB_SetRef(JB_str_35, JB_Str3("(\n", 2));
		JB_SetRef(JB_str_34, JB_Str3("nil,", 4));
		JB_SetRef(JB_str_33, JB_Str3("This class has no saving function for it.", 41));
		JB_SetRef(JB_str_32, JB_Str3("%", 1));
		JB_SetRef(JB_str_31, JB_Str3("  deviance: ", 12));
		JB_SetRef(JB_str_30, JB_Str3("  found: ", 9));
		JB_SetRef(JB_str_29, JB_Str3("expected: ", 10));
		JB_SetRef(JB_str_28, JB_Str3("win", 3));
		JB_SetRef(JB_str_27, JB_Str3("lin", 3));
		JB_SetRef(JB_str_26, JB_Str3("osx", 3));
		JB_SetRef(JB_str_25, JB_Str3("Expected class ", 15));
		JB_SetRef(JB_str_24, JB_Str3("hello", 5));
		JB_SetRef(JB_str_23, JB_Str3("This class has no loader for it.", 32));
		JB_SetRef(JB_str_22, JB_Str3("Bad data found.", 15));
		JB_SetRef(JB_str_21, JB_Str3("Unknown class.", 14));
		JB_SetRef(JB_str_20, JB_Str3(".", 1));
		JB_SetRef(JB_str_19, JB_Str3(". New Count ", 12));
		JB_SetRef(JB_str_18, JB_Str3(" bytes in ", 10));
		JB_SetRef(JB_str_17, JB_Str3("Leaked ", 7));
		JB_SetRef(JB_str_16, JB_Str3("x", 1));
		JB_SetRef(JB_str_15, JB_Str3("\n", 1));
		JB_SetRef(JB_str_14, JB_Str3("'", 1));
		JB_SetRef(JB_str_13, JB_Str3("Can‚Äôt find '", 14));
		JB_SetRef(JB_str_12, JB_Str3("/", 1));
		JB_SetRef(JB_str_11, JB_Str3("~/Documents/", 12));
		JB_SetRef(JB_str_0, JB_Str3("", 0));
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
		JB_SetRef(JB_SyxDict, JB_Dict__New());
		JB_SetRef(JB_FuncArray, ((Array*)JB_Array__New0()));
		JB_SetRef(JB_SyxArg, JB_Fn__StdNew(JB_Msg_Arg__, 0, JB_str_191, JB_str_192));
		JB_SetRef(JB_SyxAcc, JB_Fn__StdNew(JB_Msg_Acc__, 1, JB_str_193, JB_str_194));
		JB_SetRef(JB_SyxAdj, JB_Fn__StdNew(JB_Msg_Adj__, 2, JB_str_195, JB_str_196));
		JB_SetRef(JB_SyxARel, JB_Fn__StdNew(JB_Msg_ARel__, 3, JB_str_197, JB_str_198));
		JB_SetRef(JB_SyxArr, JB_Fn__StdNew(JB_Msg_Arr__, 4, JB_str_199, JB_str_200));
		JB_SetRef(JB_SyxBack, JB_Fn__StdNew(JB_Msg_Back__, 5, JB_str_201, JB_str_202));
		JB_SetRef(JB_SyxSStr, JB_Fn__StdNew(JB_Msg_SStr__, 6, JB_str_203, JB_str_204));
		JB_SetRef(JB_SyxBra, JB_Fn__StdNew(JB_Msg_Bra__, 7, JB_str_205, JB_str_206));
		JB_SetRef(JB_SyxBRel, JB_Fn__StdNew(JB_Msg_BRel__, 8, JB_str_207, JB_str_208));
		JB_SetRef(JB_SyxChar, JB_Fn__StdNew(JB_Msg_Char__, 9, JB_str_209, JB_str_210));
		JB_SetRef(JB_SyxDecl, JB_Fn__StdNew(JB_Msg_Decl__, 10, JB_str_211, JB_str_212));
		JB_SetRef(JB_SyxDot, JB_Fn__StdNew(JB_Msg_Dot__, 11, JB_str_213, JB_str_214));
		JB_SetRef(JB_SyxEmb, JB_Fn__StdNew(JB_Msg_Emb__, 12, JB_str_215, JB_str_216));
		JB_SetRef(JB_SyxERel, JB_Fn__StdNew(JB_Msg_ERel__, 13, JB_str_217, JB_str_218));
		JB_SetRef(JB_SyxFunc, JB_Fn__StdNew(JB_Msg_Func__, 14, JB_str_219, JB_str_220));
		JB_SetRef(JB_SyxItem, JB_Fn__StdNew(JB_Msg_Item__, 15, JB_str_221, JB_str_0));
		JB_SetRef(JB_SyxList, JB_Fn__StdNew(JB_Msg_List__, 16, JB_str_156, JB_str_0));
		JB_SetRef(JB_SyxPrm, JB_Fn__StdNew(JB_Msg_Prm__, 17, JB_str_222, JB_str_223));
		JB_SetRef(JB_SyxName, JB_Fn__StdNew(JB_Msg_Name__, 18, JB_str_224, JB_str_0));
		JB_SetRef(JB_SyxNum, JB_Fn__StdNew(JB_Msg_Num__, 19, JB_str_225, JB_str_226));
		JB_SetRef(JB_SyxOat, JB_Fn__StdNew(JB_Msg_Oat__, 20, JB_str_227, JB_str_228));
		JB_SetRef(JB_SyxOpp, JB_Fn__StdNew(JB_Msg_Opp__, 21, JB_str_229, JB_str_230));
		JB_SetRef(JB_SyxSOpp, JB_Fn__StdNew(JB_Msg_SOpp__, 22, JB_str_231, JB_str_232));
		JB_SetRef(JB_SyxRel, JB_Fn__StdNew(JB_Msg_Rel__, 23, JB_str_233, JB_str_234));
		JB_SetRef(JB_SyxTRel, JB_Fn__StdNew(JB_Msg_TRel__, 24, JB_str_235, JB_str_236));
		JB_SetRef(JB_SyxSDot, JB_Fn__StdNew(JB_Msg_SDot__, 25, JB_str_237, JB_str_238));
		JB_SetRef(JB_SyxSCom, JB_Fn__StdNew(JB_Msg_SCom__, 26, JB_str_239, JB_str_240));
		JB_SetRef(JB_SyxSheb, JB_Fn__StdNew(JB_Msg_Sheb__, 27, JB_str_241, JB_str_242));
		JB_SetRef(JB_SyxStr, JB_Fn__StdNew(JB_Msg_Str__, 28, JB_str_243, JB_str_244));
		JB_SetRef(JB_SyxSThg, JB_Fn__StdNew(JB_Msg_SThg__, 29, JB_str_245, JB_str_246));
		JB_SetRef(JB_SyxThg, JB_Fn__StdNew(JB_Msg_Thg__, 30, JB_str_247, JB_str_248));
		JB_SetRef(JB_SyxTmp, JB_Fn__StdNew(JB_Msg_Tmp__, 31, JB_str_249, JB_str_250));
		JB_SetRef(JB_SyxAna, JB_Fn__StdNew(JB_Msg_Ana__, 32, JB_str_251, JB_str_252));
		JB_SetRef(JB_SyxSCnj, JB_Fn__StdNew(JB_Msg_SCnj__, 33, JB_str_253, JB_str_254));
		JB_SetRef(JB_SyxCnj, JB_Fn__StdNew(JB_Msg_Cnj__, 34, JB_str_255, JB_str_256));
		JB_SetRef(JB_SyxType, JB_Fn__StdNew(JB_Msg_Type__, 35, JB_str_257, JB_str_258));
		JB_SetRef(JB_SyxUnit, JB_Fn__StdNew(JB_Msg_Unit__, 36, JB_str_259, JB_str_0));
		JB_SetRef(JB_SyxBin, JB_Fn__StdNew(JB_Msg_Bin__, 37, JB_str_260, JB_str_261));
	};
	//// JB_API;
	JB_API__Init_();
	//// Jeebox;
	JB_Constants__Init_();
	//// parser;
	JB_Tk__Init_();
	//// Random;
	JB_Random__Init_();
	//// FastAppender;
	JB_FAP__Init_();
	return 0;
}

int JB_Main() {
	return 0;
}

Dictionary* JB_Dict_Reverse(Dictionary* Dict) {
	Dictionary* result = JB_Dict__New();
	JB_Incr(result);
	{
		DictionaryReader* _nav = JB_Dict_Navigate(Dict);
		JB_Incr(_nav);
		while (JB_Nav_MoveNext(_nav)) {
			JB_String* key = JB_Nav_Name(_nav);
			JB_Incr(key);
			JB_String* value = ((JB_String*)JB_Nav_Value(_nav));
			JB_Incr(value);
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
	Dictionary* d = JB_Dict__New();
	JB_Incr(d);
	JB_String* str = JB_str_73;
	JB_Incr(str);
	if ((!((!JB_Str_SyntaxAccess(str, 0)) and ((!JB_Str_SyntaxAccess(str, 1)) and ((!JB_Str_SyntaxAccess(str, 2)) and ((!JB_Str_SyntaxAccess(str, 3)) and (JB_Str_Length(str) == 6))))))) {
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
	Message* y = JB_Msg__NewParser(nil, JB_SyxBra, 0, JB_str_0);
	JB_Incr(y);
	JB_SetRef(y->Name, JB_str_74);
	JB_Object* yy = nil;
	JB_Incr(yy);
	JB_SetRef(yy, y);
	Array* arr = JB_Array__New(0);
	JB_Incr(arr);
	JB_Array_Append(arr, nil);
	JB_Decr(arr);
	if (JB_Object_Isa(yy, JB_AsClass(Message))) {
		if ((!JB_Str_SyntaxEquals(((Message*)yy)->Name, JB_str_74, false))) {
			debugger;
		}
	}
	JB_Decr(yy);
	bool _tmp253 = (JB_Object_Isa(y, x));
	JB_Decr(y);
	return _tmp253;
}





void JB_ClassData_Restore(JB_Class* self) {
	JB_MemoryLayer* _tmp199 = JB_Class_DefaultLayer(self);
	JB_Incr(_tmp199);
	JB_Mem_Use(_tmp199);
	JB_Decr(_tmp199);
}




JB_String* JB_f_Render(float self, FastString* fs_in) {
	FastString* fs = JB_FS__FastNew(fs_in);
	JB_Incr(fs);
	JB_FS_AppendFloatAsText(fs, self);
	JB_String* _tmp177 = JB_FS_SmartResult(fs, fs_in);
	JB_Incr(_tmp177);
	JB_Decr(fs);
	JB_SafeDecr(_tmp177);
	return _tmp177;
}





int JB_int_OperatorMin(int self, int other) {
	if (self < other) {
		return self;
	}
	return other;
}

JB_String* JB_int_Render(int self, FastString* fs_in) {
	FastString* fs = JB_FS__FastNew(fs_in);
	JB_Incr(fs);
	JB_FS_AppendInt32AsText(fs, self);
	JB_String* _tmp176 = JB_FS_SmartResult(fs, fs_in);
	JB_Incr(_tmp176);
	JB_Decr(fs);
	JB_SafeDecr(_tmp176);
	return _tmp176;
}




void JB_LLRef_Clear(LLRef* self) {
	JB_LinkedList_ClearAll(self->First);
}

void JB_LLRef_Destructor(LLRef* self) {
	JB_LLRef_Clear(self);
}

void JB_LLRef_HeaderSanity(LLRef* self) {
	if ((!(JB_IsDebug()))) {
		return;
	}
	JB_LinkedList* F = self->First;
	if ((!F)) {
		return;
	}
	JB_LinkedList** Addr = (&self->First);
	if (F->_BackRef != Addr) {
		debugger;
	}
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




bool JB_Loader_HasItem(ObjectLoader* self) {
	return ((bool)self->CurrItem);
}

s64 JB_Loader_Int(ObjectLoader* self) {
	Message* C = JB_Loader_Next(self);
	if ((!C)) {
		return nil;
	}
	return JB_Str_TextIntegerValid(C->Name, C);
}

s64 JB_Loader_ItemInt(ObjectLoader* self) {
	Message* c = self->CurrItem;
	if ((!c)) {
		return nil;
	}
	self->CurrItem = ((Message*)JB_Tree_NextSib(c));
	return JB_Msg_ParseInt(((Message*)JB_Tree_Last(c)));
}

bool JB_Loader_ItemIsInt(ObjectLoader* self) {
	Message* C = self->CurrItem;
	return ((JB_Msg_SyxOppEquals(((Message*)JB_Tree_Last(C)), JB_SyxNum, false)));
}

JB_String* JB_Loader_ItemName(ObjectLoader* self) {
	Message* c = self->CurrItem;
	return JB_Str_Unshare(JB_Msg_Nyme(((Message*)JB_Tree_First(c))));
}

JB_Object* JB_Loader_ItemObject(ObjectLoader* self) {
	Message* c = self->CurrItem;
	if ((!c)) {
		return nil;
	}
	self->CurrItem = ((Message*)JB_Tree_NextSib(c));
	return JB_Loader_ObjectSub(self, ((Message*)JB_Tree_Last(c)));
}

void JB_Loader_ListStoreAt(ObjectLoader* self, JB_LinkedList** Place) {
	JB_LinkedList* o = ((JB_LinkedList*)JB_Loader_Object(self));
	if ((!o)) {
		return;
	}
	if (Place[0]) {
		debugger;
	}
	if (o) {
		JB_Incr(o);
		Place[0] = o;
		o->_BackRef = Place;
	}
}

Message* JB_Loader_Next(ObjectLoader* self) {
	Message* C = self->CurrItem;
	if (C) {
		self->CurrItem = ((Message*)JB_Tree_NextSib(C));
		return C;
	}
	return nil;
}

JB_Object* JB_Loader_Object(ObjectLoader* self) {
	return JB_Loader_ObjectSub(self, JB_Loader_Next(self));
}

JB_Object* JB_Loader_ObjectSub(ObjectLoader* self, Message* c) {
	if (JB_Msg_SyxOppEquals(c, JB_SyxThg, false)) {
		return JB_Dict_Value(self->Dict, c->Name);
	} else if (JB_Msg_SyxOppEquals(c, JB_SyxStr, false)) {
		return JB_Str_Unshare(c->Name);
	}
	return nil;
}

JB_String* JB_Loader_String(ObjectLoader* self) {
	Message* C = JB_Loader_Next(self);
	if ((!C)) {
		return nil;
	}
	return JB_Str_Unshare(C->Name);
}


void JB_Saver_AppendInt(ObjectSaver* self, s64 i) {
	JB_FS_AppendIntegerAsText(self->Dest, i, 1);
	JB_FS_AppendByte(self->Dest, ',');
}

void JB_Saver_AppendObject(ObjectSaver* self, JB_Object* o) {
	JB_FS_AppendObjectOrNil(self->Dest, o);
	JB_FS_AppendByte(self->Dest, ',');
}

void JB_Saver_AppendString(ObjectSaver* self, JB_String* s) {
	if (JB_Str_Exists(s) and JB_int_Found(JB_Str_FindByte(s, 0, '`'))) {
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
		JB_Object_Fail(self->CantSaveThis, JB_str_33);
	}
	JB_Decr(self->Dest);
}

int JB_Saver__Init_() {
	{
	};
	return 0;
}



void JB_Random_LoadProperties(Random* self, ObjectLoader* Loader) {
	self->Fast = ((u64)JB_Loader_Int(Loader));
	self->Adder = ((u64)JB_Loader_Int(Loader));
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



JB_String* JB_s64_Render(s64 self, FastString* fs_in) {
	FastString* fs = JB_FS__FastNew(fs_in);
	JB_Incr(fs);
	JB_FS_AppendIntegerAsText(fs, self, 1);
	JB_String* _tmp178 = JB_FS_SmartResult(fs, fs_in);
	JB_Incr(_tmp178);
	JB_Decr(fs);
	JB_SafeDecr(_tmp178);
	return _tmp178;
}



void JB_StructSaveTest_LoadProperties(StructSaveTest* self, ObjectLoader* Loader) {
	JB_SetRef(self->Sav, ((Saveable*)JB_Loader_Object(Loader)));
	self->Intt = JB_Loader_Int(Loader);
	JB_SetRef(self->Str, ((JB_String*)JB_Loader_String(Loader)));
}

void JB_StructSaveTest_SaveWrite(StructSaveTest* self, ObjectSaver* Saver) {
	JB_Saver_AppendObject(Saver, self->Sav);
	JB_Saver_AppendInt(Saver, self->Intt);
	JB_Saver_AppendString(Saver, self->Str);
}















bool JB_byte_CanPrintAsNormalChar(byte self) {
	return ((self <= 127) and (self >= 32));
}

bool JB_byte_IsNum(byte self) {
	return (self >= '0') and (self <= '9');
}

bool JB_byte_IsNumeric(byte self) {
	return (self >= '0') and (self <= '9');
}

JB_String* JB_byte_Render(byte self, FastString* fs_in) {
	if ((!fs_in)) {
		return JB_Str_ChrB(self);
	}
	JB_FS_AppendByte(fs_in, self);
	return nil;
}


JB_String* JB_Date_Render(Date self, FastString* fs_in) {
	FastString* fs = JB_FS__FastNew(fs_in);
	JB_Incr(fs);
	JB_FS_AppendDate(fs, self);
	JB_String* _tmp179 = JB_FS_SmartResult(fs, fs_in);
	JB_Incr(_tmp179);
	JB_Decr(fs);
	JB_SafeDecr(_tmp179);
	return _tmp179;
}



















void JB_DebugPrint(JB_Object* self) {
	JB_String* _tmp198 = JB_ObjRender(self, nil);
	JB_Incr(_tmp198);
	JB_Str_PrintLine(_tmp198);
	JB_Decr(_tmp198);
}

bool JB_Object_MustBe(JB_Object* self, JB_Class* x, Message* ErrNode) {
	if (JB_Object_Isa(self, x)) {
		return true;
	}
	if ((!false)) {
		FastString* _fs_fs = JB_FS__New();
		JB_Incr(_fs_fs);
		JB_FS_AppendString(_fs_fs, JB_str_25);
		JB_FS_AppendCString2(_fs_fs, x->Name);
		JB_String* _fs_str = JB_FS_SyntaxCastString(_fs_fs);
		JB_Incr(_fs_str);
		JB_SetRef(_fs_fs, nil);
		JB_Decr(_fs_fs);
		JB_Msg_Fail(ErrNode, _fs_str);
		JB_Decr(_fs_str);
	}
	return false;
}

bool JB_Object_Isa(JB_Object* self, JB_Class* x) {
	if ((!self)) {
		return nil;
	}
	JB_Class* P = JB_ObjClass(self);
	while (P) {
		if (P == x) {
			return true;
		}
		P = P->Parent;
	};
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
	if (JB_Object_Isa(self, JB_AsClass(Message))) {
		JB_Rec_NewItemWithNode(JB_StdErr, ((Message*)self), Error);
	} else {
		JB_Rec_NewItemWithNode(JB_StdErr, nil, Error);
	}
}

void JB_Object_SyntaxExpect(JB_Object* self) {
	JB_Rec_NewItemWithNode(JB_StdErr, nil, JB_str_84);
}

void JB_Object_test(JB_Object* self) {
	JB_String* s = JB_str_24;
	JB_Incr(s);
	JB_Object* b = s;
	JB_Incr(b);
	JB_Decr(s);
	if (JB_Object_MustBe(b, JB_AsClass(JB_String), nil)) {
		JB_Str_PrintLine(((JB_String*)b));
	}
	JB_Decr(b);
}


Array* JB_BM_Bytes(ByteMap* self) {
	Array* result = JB_Array__New0();
	JB_Incr(result);
	{
		int _i = 0;
		while (_i < 256) {
			if ((!JB_BM_HasChar(self, _i))) {
				_i++;
				continue;
			}
			byte b = ((byte)_i);
			JB_String* _tmp171 = JB_byte_Render(b, nil);
			JB_Incr(_tmp171);
			JB_Array_Append(result, _tmp171);
			JB_Decr(_tmp171);
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



void JB_FS_AppendEscape(FastString* self, JB_String* s) {
	JB_FS_AppendMultiReplace(self, s, JB__Constants_EscapeStr, JB_StdErr);
}

void JB_FS_AppendHexData1(FastString* self, JB_String* Data) {
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
			//"Can happen if we didn't call .property.SaveTryCollect(Saver) in behaviour savecollect.";
			//"I guess we might not want to save all properties, but in that case we should just mark it as not saveable.";
			//"Not sure why we can‚Äôt auto-create property collecting code";
			//"or why we need it even. Why not just save the property? Add it to a savelist if unmarked...?";
			//"I guess we don't want to 'cycle back up' through the entire object-hierarchy. That's why.";
			//"Should only be for things that 'we really own'.";
			JB_DoAt(1);
			JB_FS_AppendString(self, JB_str_80);
		}
	} else if (JB_Object_Isa(o, JB_AsClass(JB_String))) {
		JB_FreeIfDead(JB_ObjRender(((JB_String*)o), self));
	} else {
		JB_FS_AppendString(self, JB_str_80);
	}
}

void JB_FS_MsgErrorName(FastString* self, JB_String* name) {
	if (JB_Str_Exists(name)) {
		JB_FS_AppendString(self, JB_str_87);
		JB_FS_AppendString(self, name);
		JB_FS_AppendString(self, JB_str_88);
	}
}

JB_String* JB_FS_Render(FastString* self, FastString* fs_in) {
	return JB_FS_SmartResult(self, fs_in);
}

void JB_FS_AppendInt32AsText(FastString* self, int data) {
	JB_FS_AppendIntegerAsText(self, ((s64)data), 1);
}

void JB_FS_AppendFloatAsText(FastString* self, float F) {
	JB_FS_AppendDoubleAsText0(self, ((double)F));
}

void JB_FS_AppendMsg(FastString* self, Message* msg) {
	if (msg) {
		(msg->Type->RenderAddr)(msg, self);
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
	JB_Incr(name);
	self->Name = name;
}

void JB_Lk_Destructor(LeakTester* self) {
	JB_Decr(self->Name);
}

void JB_Lk_FinalTest(LeakTester* self) {
	JB_Lk_Test(self);
	self->MemUsedStart = nil;
}

void JB_Lk_Test(LeakTester* self) {
	if ((!self->MemUsedStart)) {
		return;
	}
	int NewAmount = JB_MemCount();
	int Diff = NewAmount - self->MemUsedStart;
	if (Diff > 0) {
		debugger;
		FastString* _fs_fs = JB_FS__New();
		JB_Incr(_fs_fs);
		JB_FS_AppendString(_fs_fs, JB_str_17);
		JB_FS_AppendInt32AsText(_fs_fs, Diff);
		JB_FS_AppendString(_fs_fs, JB_str_18);
		JB_FS_AppendString(_fs_fs, self->Name);
		JB_FS_AppendString(_fs_fs, JB_str_19);
		JB_FS_AppendInt32AsText(_fs_fs, NewAmount);
		JB_FS_AppendString(_fs_fs, JB_str_20);
		JB_String* _fs_str = JB_FS_SyntaxCastString(_fs_fs);
		JB_Incr(_fs_str);
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
	JB_FS_AppendString(Saver->Dest, JB_str_34);
}



void JB_Str_AppendAsBinary(JB_String* self, FastString* fs) {
	JB_FS_AppendString(fs, JB_str_81);
	JB_FreeIfDead(JB_Str_EncodeB64(self, fs));
	JB_FS_AppendString(fs, JB_str_82);
}

Array* JB_Str_ByteSplit(JB_String* self) {
	Array* result = JB_Array__New0();
	JB_Incr(result);
	{
		int _LoopSrc1 = JB_Str_Length(self);
		int n = 0;
		while (n < _LoopSrc1) {
			JB_String* _tmp207 = JB_byte_Render(JB_Str_SyntaxAccess(self, n), nil);
			JB_Incr(_tmp207);
			JB_Array_Append(result, _tmp207);
			JB_Decr(_tmp207);
			n++;
		};
	};
	JB_SafeDecr(result);
	return result;
}

ByteMap* JB_Str_Charset(JB_String* self, bool Range) {
	return JB_BM__NewCharset(self, Range);
}

JB_String* JB_Str_Escape(JB_String* self) {
	return JB_Str_MultiReplaceAll(self, JB__Constants_EscapeStr, JB_StdErr);
}

JB_String* JB_Str_EscapeChr(JB_String* self) {
	return JB_Str_MultiReplaceAll(self, JB__Constants_EscapeChr, JB_StdErr);
}

int JB_Str_FindStr(JB_String* self, int Start, JB_String* find) {
	return JB_Str_InStr(self, find, Start, kJB__int_max, false);
}

int JB_Str_FindByte(JB_String* self, int off, byte find) {
	return JB_Str_InByte(self, off, kJB__int_max, find);
}

int JB_Str_InCharSet(JB_String* self, int Start, int After, ByteMap* cs) {
	return JB_Str_CharSet(self, Start, After, cs, true);
}

int JB_Str_InWhite(JB_String* self, int Start, int After) {
	return JB_Str_WhiteSpace(self, Start, After, true);
}

int JB_Str_JBFind(JB_String* self, int Off, int After, byte find) {
	After = JB_int_OperatorMin(After, JB_Str_Length(self));
	while (Off < After) {
		byte c = JB_Str_SyntaxAccess(self, Off++);
		if (c == '\\') {
			Off++;
		} else if (c == find) {
			return Off - 1;
		}
	};
	return -1;
}

int JB_Str_LineCount(JB_String* self) {
	StringFields* fi = JB_FI__New(self, nil);
	JB_Incr(fi);
	int _tmp208 = JB_FI_Count(fi);
	JB_Decr(fi);
	return _tmp208;
}

bool JB_Str_OperatorContains(JB_String* self, JB_String* s) {
	return JB_int_Found(JB_Str_InStr(self, s, 0, kJB__int_max, true));
}

int JB_Str_OutCharSet(JB_String* self, int Start, int After, ByteMap* cs) {
	return JB_Str_CharSet(self, Start, After, cs, false);
}

int JB_Str_OutWhite(JB_String* self, int Start, int After) {
	return JB_Str_WhiteSpace(self, Start, After, false);
}

Message* JB_Str_Parse(JB_String* self, Message* Result) {
	JB_Incr(Result);
	if ((!JB_Tk__CppInited())) {
		JB_Tk__Init();
	}
	JB__Tk_ErrNode = JB_Fn_Msg(JB_SyxArg, JB_str_0);
	if ((!(Result))) {
		JB_SetRef(Result, JB__Tk_ErrNode);
	}
	int Count = JB_StdErr->ErrorCount;
	JB_Tk__StartParse(self);
	JB__Tk_StopBars = 0;
	JB_Tk__ParseLoop(Result, 0);
	JB_Tk__CleanSpaces();
	if (JB_Tk__Running()) {
		JB_Tk__Expect(0);
	}
	JB__Tk_ErrNode = nil;
	JB_Tk__StopParse();
	if ((!(Count == JB_StdErr->ErrorCount))) {
		JB_Decr(Result);
		return nil;
	}
	JB_SafeDecr(Result);
	return Result;
}

Message* JB_Str_ParseAs(JB_String* self, JB_String* name) {
	if ((!JB_Str_Exists(name)) or (JB_Str_SyntaxEquals(name, JB_str_155, true))) {
		return JB_Str_Parse(self, nil);
	} else if (JB_Str_SyntaxEquals(name, JB_str_156, true)) {
		Message* _tmp329 = JB_Str_Parse(self, nil);
		JB_Incr(_tmp329);
		Message* _tmp330 = JB_Msg_ParseReadable(_tmp329);
		JB_Incr(_tmp330);
		JB_Decr(_tmp329);
		JB_SafeDecr(_tmp330);
		return _tmp330;
	}
	return nil;
}

int JB_Str_ParseInt(JB_String* self, Message* Where) {
	return JB_Str_TextIntegerValid(self, Where);
}

Array* JB_Str_Split(JB_String* self, JB_String* sep) {
	StringFields* fi = JB_FI__New(self, sep);
	JB_Incr(fi);
	Array* result = JB_Array__New0();
	JB_Incr(result);
	{
		int _Prev = 0;
		while (fi->Data != nil) {
			int _Curr_1 = JB_FI_NextSep(fi, _Prev);
			JB_String* field = JB_FI_Field(fi, _Prev, _Curr_1);
			JB_Incr(field);
			JB_Array_Append(result, field);
			JB_Decr(field);
			_Prev = (_Curr_1 + fi->SepLen);
			if ((!JB_int_Found(_Curr_1))) {
				break;
			}
		};
	};
	JB_Decr(fi);
	JB_SafeDecr(result);
	return result;
}

byte JB_Str_SyntaxAccess(JB_String* self, int index) {
	return JB_Str_ByteValue(self, index);
}

JB_String* JB_Str_AccessRange(JB_String* self, int start, int after) {
	return JB_Str_Range(self, start, after);
}

bool JB_Str_SyntaxEquals(JB_String* self, JB_String* Other, bool Aware) {
	return JB_Str_Equals(self, Other, Aware);
}

void JB_Str_SyntaxExpect(JB_String* self) {
	JB_Rec_NewItemWithNode(JB_StdErr, nil, self);
}

JB_String* JB_Str_Unescape(JB_String* self) {
	return JB_Str_MultiReplaceAll(self, JB__Constants_UnEscapeStr, JB_StdErr);
}


StringFields_Behaviour InitTableStringFields_() { // Behaviour 
	StringFields_Behaviour Result;
	Result.__destructor__ = (void*)JB_FI_Destructor;
	Result.render = (__Object_Render__)JB_ObjRender;
	return Result;
}

StringFields_Behaviour StringFields_FuncTable_ = InitTableStringFields_();
JBClassPlace4(StringFields, JB_AsClass(JB_Object), StringFields_FuncTable_);

void JB_FI_Constructor(StringFields* self, JB_String* Source, JB_String* Sep) {
	JB_Incr(Source);
	self->Data = Source;
	JB_Incr(Sep);
	self->Sep = Sep;
	self->SepLen = JB_Str_Length(Sep);
	if ((!JB_Str_Exists(Sep))) {
		self->SepLen = 1;
	}
}

int JB_FI_Count(StringFields* self) {
	int result = 0;
	{
		int _Prev = 0;
		while (self->Data != nil) {
			int _Curr_1 = JB_FI_NextSep(self, _Prev);
			result++;
			_Prev = (_Curr_1 + self->SepLen);
			if ((!JB_int_Found(_Curr_1))) {
				break;
			}
		};
	};
	return result;
}

void JB_FI_Destructor(StringFields* self) {
	JB_Decr(self->Data);
	JB_Decr(self->Sep);
}

JB_String* JB_FI_Field(StringFields* self, int Prev, int Curr) {
	if ((!JB_int_Found(Curr))) {
		Curr = JB_Str_Length(self->Data);
	}
	return JB_Str_AccessRange(self->Data, Prev, Curr);
}

int JB_FI_NextSep(StringFields* self, int Prev) {
	if (self->Sep == nil) {
		if ((JB_Str_SyntaxAccess(self->Data, Prev - 1) == 13) and (JB_Str_SyntaxAccess(self->Data, Prev) == 10)) {
			Prev++;
		}
		return JB_Str_InCharSet(self->Data, Prev, kJB__int_max, JB__Constants_CSLine);
	} else {
		return JB_Str_FindStr(self->Data, Prev, self->Sep);
	}
	return 0;
}

StringFields* JB_FI__Alloc() {
	return ((StringFields*)JB_New(StringFields));
}

StringFields* JB_FI__New(JB_String* Source, JB_String* Sep) {
	StringFields* Result = JB_FI__Alloc();
	if (Result) {
		JB_FI_Constructor(Result, Source, Sep);
	}
	return Result;
}



Syntax_Behaviour InitTableSyntax_() { // Behaviour 
	Syntax_Behaviour Result;
	Result.__destructor__ = (void*)JB_Fn_Destructor;
	Result.render = (__Object_Render__)JB_Fn_Render;
	return Result;
}

Syntax_Behaviour Syntax_FuncTable_ = InitTableSyntax_();
JBClassPlace4(Syntax, JB_AsClass(JB_Object), Syntax_FuncTable_);

void JB_Fn_Constructor(Syntax* self, fpMsgRender msg, JB_String* name, int ID) {
	JB_Incr(JB_str_0);
	self->LongName = JB_str_0;
	self->RenderAddr = msg;
	JB_Incr(name);
	self->Name = name;
	self->ID = ID;
	self->ExportAddr = JB_Msg_Dummy;
}

void JB_Fn_Destructor(Syntax* self) {
	JB_Decr(self->Name);
	JB_Decr(self->LongName);
}

Message* JB_Fn_Msg(Syntax* self, JB_String* name) {
	return JB_Msg__NewParser(nil, self, JB__Tk_BaseMessagePosition, name);
}

Message* JB_Fn_MsgParent(Syntax* self, Message* parent, JB_String* name) {
	return JB_Msg__NewParser(parent, self, JB__Tk_BaseMessagePosition, name);
}

int JB_Fn_Parseflags(Syntax* self) {
	if (self == JB_SyxArg) {
		return kJB__Tk_Temporal;
	} else {
		return kJB__Tk_TemporalSyx;
	}
	return 0;
}

JB_String* JB_Fn_Render(Syntax* self, FastString* fs_in) {
	if ((!fs_in)) {
		return JB_Str_LowerCase(self->LongName);
	}
	JB_String* _tmp248 = JB_Str_LowerCase(self->LongName);
	JB_Incr(_tmp248);
	JB_FS_AppendString(fs_in, _tmp248);
	JB_Decr(_tmp248);
	return JB_str_0;
}

Syntax* JB_Fn__Alloc() {
	return ((Syntax*)JB_New(Syntax));
}

Syntax* JB_Fn__New(fpMsgRender msg, JB_String* name, int ID) {
	Syntax* Result = JB_Fn__Alloc();
	if (Result) {
		JB_Fn_Constructor(Result, msg, name, ID);
	}
	return Result;
}

Syntax* JB_Fn__StdNew(fpMsgRender msg, int ID, JB_String* name, JB_String* LongName) {
	Syntax* result = JB_Fn__New(msg, name, ID);
	JB_Incr(result);
	(JB_Dict_ValueSet(JB_SyxDict, name, result));
	if (JB_Str_Exists(LongName)) {
		(JB_Dict_ValueSet(JB_SyxDict, LongName, result));
		JB_SetRef(result->LongName, LongName);
	} else {
		JB_SetRef(result->LongName, name);
	}
	if ((!(JB_Array_Size(JB_FuncArray) == ID))) {
		JB_Object_SyntaxExpect(nil);
		JB_Decr(result);
		return nil;
	}
	JB_Array_Append(JB_FuncArray, result);
	JB_SafeDecr(result);
	return result;
}












void JB_Array_LoadProperties(Array* self, ObjectLoader* Loader) {
	while (JB_Loader_HasItem(Loader)) {
		JB_Array_Append(self, JB_Loader_Object(Loader));
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
				JB_FS_AppendString(D, JB_str_50);
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
	while (JB_Loader_HasItem(Loader)) {
		JB_String* name = JB_Loader_ItemName(Loader);
		if (JB_Loader_ItemIsInt(Loader)) {
			(JB_Dict_a2(self, name, JB_Loader_ItemInt(Loader)));
		} else {
			(JB_Dict_ValueSet(self, name, JB_Loader_ItemObject(Loader)));
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
	while (JB_DictionaryReader_SyntaxCastBool(L)) {
		JB_FS_AppendString(D, JB_Nav_Name(L));
		JB_FS_AppendString(D, JB_str_55);
		s64 i = 0;
		if (JB_Nav_HasInt(L, (&i))) {
			JB_Saver_AppendInt(Saver, i);
		} else {
			JB_FS_AppendObjectOrNil(D, JB_Nav_Value(L));
		}
		JB_FS_AppendByte(D, ',');
	};
}

JB_Object* JB_Dict_Syntax(Dictionary* self, JB_String* Key) {
	JB_String* _tmp278 = JB_Str_FastLower(Key);
	JB_Incr(_tmp278);
	JB_Object* _tmp279 = JB_Dict_Value(self, _tmp278);
	JB_Incr(_tmp279);
	JB_Decr(_tmp278);
	JB_SafeDecr(_tmp279);
	return _tmp279;
}

void JB_Dict_a2(Dictionary* self, JB_String* Key, s64 Result) {
	(JB_Dict_IntValueSet(self, Key, Result));
}

void JB_Dict_a4(Dictionary* self, s64 Key, JB_Object* Result) {
	(JB_Dict_ValueSet(self, JB_s64_DictName(Key), Result));
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


void JB_LinkedList_ListSanity(JB_LinkedList* self) {
	if ((!(JB_IsDebug()))) {
		return;
	}
	if (self->_Next == self) {
		debugger;
	}
	if (((bool)self->_BackRef) and (self->_BackRef[0] != self)) {
		debugger;
	}
}

void JB_LinkedList_LoadProperties(JB_LinkedList* self, ObjectLoader* Loader) {
	JB_Loader_ListStoreAt(Loader, (&self->_Next));
	JB_LinkedList_ListSanity(self);
}

void JB_LinkedList_SaveWrite(JB_LinkedList* self, ObjectSaver* Saver) {
	JB_Saver_AppendObject(Saver, self->_Next);
}


RingTree* JB_Tree_First_(RingTree* self) {
	if (self) {
		return JB_Tree_First(self);
	}
	return nil;
}

bool JB_Tree_HasOneChild(RingTree* self) {
	return JB_Tree_HasChildCount(self, 1);
}

bool JB_Tree_IsWithin(RingTree* self, RingTree* other) {
	{
		RingTree* curr = self;
		while (curr) {
			if (other == curr) {
				return true;
			}
			curr = JB_Tree_Parent(curr);
		};
	};
	return false;
}

void JB_Tree_Remove(RingTree* self) {
	(JB_Tree_ParentSet(self, nil));
}

void JB_Tree_SyntaxAppend(RingTree* self, RingTree* Last) {
	(JB_Tree_LastSet(self, Last));
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
	self->ErrorLevel = 0;
	JB_Incr(JB_str_0);
	self->Description = JB_str_0;
	int P = -1;
	if (node) {
		P = node->Position;
	}
	self->Position = P;
	JB_Incr(node);
	self->Node = node;
	JB_String* _tmp219 = JB_Msg_OriginalParsePath(node);
	JB_Incr(_tmp219);
	self->Path = _tmp219;
	JB_String* _tmp220 = JB_Msg_OriginalParseData(node);
	JB_Incr(_tmp220);
	self->OriginalData = _tmp220;
}

void JB_Err_Destructor(JB_Error* self) {
	JB_Decr(self->Path);
	JB_Decr(self->Description);
	JB_Decr(self->OriginalData);
	JB_Decr(self->Node);
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
	JB_String* d = self->OriginalData;
	JB_Incr(d);
	if ((!JB_Str_Exists(d))) {
		JB_Decr(d);
		return;
	}
	if ((!JB_Err_HasPosition(self))) {
		JB_Decr(d);
		return;
	}
	int Start = JB_Str_InCharSet(d, self->Position, 0, JB__Constants_CSLine) + 1;
	int Finish = JB_Str_InCharSet(d, self->Position, kJB__int_max, JB__Constants_CSLine);
	if (Finish == -1) {
		Finish = (JB_Str_Length(d) + 1);
	}
	JB_String* _tmp275 = JB_Str_ReplaceAll(JB_Str_AccessRange(d, Start, Finish), JB_str_85, JB_str_36, false, nil);
	JB_Incr(_tmp275);
	JB_Decr(d);
	JB_FS_AppendString(fs, _tmp275);
	JB_Decr(_tmp275);
	int Spaces = (self->Position - Start);
	if ((!(Spaces < 100))) {
		debugger;
		return;
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
	return (self->ErrorLevel >= kJB__Err_WarningError);
}

bool JB_Err_LineIdentifiers(JB_Error* self, FastString* fs, JB_String* path) {
	if ((!(JB_Err_HasPosition(self)))) {
		return nil;
	}
	JB_String* d = self->OriginalData;
	JB_Incr(d);
	if ((!JB_Str_Exists(d))) {
		JB_Decr(d);
		return nil;
	}
	if ((!JB_Str_Exists(path))) {
		JB_FS_AppendString(fs, JB_str_86);
	}
	JB_FS_AppendInt32AsText(fs, JB_Err_LinePos(self, d));
	JB_FS_AppendByte(fs, ':');
	int Start = JB_Str_InCharSet(d, self->Position, 0, JB__Constants_CSLine);
	JB_Decr(d);
	JB_FS_AppendInt32AsText(fs, (self->Position - Start));
	JB_FS_AppendByte(fs, ':');
	return true;
}

int JB_Err_LinePos(JB_Error* self, JB_String* data) {
	if (JB_Err_HasPosition(self)) {
		JB_String* _tmp217 = JB_Str_AccessRange(data, 0, self->Position);
		JB_Incr(_tmp217);
		int _tmp218 = JB_Str_LineCount(_tmp217);
		JB_Decr(_tmp217);
		return _tmp218;
	}
	return 0;
}

JB_String* JB_Err_Render(JB_Error* self, FastString* fs_in) {
	FastString* fs = JB_FS__FastNew(fs_in);
	JB_Incr(fs);
	JB_String* P = self->Path;
	JB_Incr(P);
	if (JB_Str_Exists(P)) {
		JB_FS_AppendString(fs, P);
		JB_FS_AppendByte(fs, ':');
	}
	if ((!JB_Err_LineIdentifiers(self, fs, P)) and ((bool)self->Node)) {
		JB_FreeIfDead(JB_Msg_Render(self->Node, fs));
	}
	JB_Decr(P);
	JB_FS_AppendByte(fs, ' ');
	JB_String* _tmp276 = JB_Rec__ErrorType(JB_Err_IsWarning(self));
	JB_Incr(_tmp276);
	JB_FS_AppendString(fs, _tmp276);
	JB_Decr(_tmp276);
	JB_FS_AppendString(fs, JB_str_55);
	JB_FS_AppendString(fs, self->Description);
	JB_FS_AppendByte(fs, '\n');
	JB_Err_GrabLine(self, fs, false);
	JB_FS_AppendByte(fs, '\n');
	JB_String* _tmp277 = JB_FS_SmartResult(fs, fs_in);
	JB_Incr(_tmp277);
	JB_Decr(fs);
	JB_SafeDecr(_tmp277);
	return _tmp277;
}

JB_Error* JB_Err__Alloc() {
	return ((JB_Error*)JB_New(JB_Error));
}

void JB_Err__CantParseNum(Message* Where, JB_String* num, int Pos) {
	JB_Error* err = JB_Err__New(Where);
	JB_Incr(err);
	FastString* _fs_fs = JB_FS__New();
	JB_Incr(_fs_fs);
	JB_FS_AppendString(_fs_fs, JB_str_44);
	JB_String* _tmp216 = JB_Str_AccessRange(num, 0, 10);
	JB_Incr(_tmp216);
	JB_FS_AppendString(_fs_fs, _tmp216);
	JB_Decr(_tmp216);
	JB_FS_AppendString(_fs_fs, JB_str_45);
	JB_FS_AppendByte(_fs_fs, JB_Str_SyntaxAccess(num, Pos));
	JB_FS_AppendString(_fs_fs, JB_str_46);
	JB_String* _fs_str = JB_FS_SyntaxCastString(_fs_fs);
	JB_Incr(_fs_str);
	JB_SetRef(_fs_fs, nil);
	JB_Decr(_fs_fs);
	JB_SetRef(err->Description, _fs_str);
	JB_Decr(_fs_str);
	JB_Rec_NewItem(JB_StdErr, err);
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
	JB_LLRef_Clear((&self->List));
	self->ErrorCount = 0;
	self->WarnCount = 0;
}

void JB_Rec_Constructor(JB_ErrorReceiver* self) {
	JB_LinkedList_Constructor(self);
	self->List = ((LLRef){
	});
	self->ErrorCount = 0;
	self->WarnCount = 0;
	JB_Incr(JB_str_0);
	self->Source = JB_str_0;
	JB_LinkedList_StoreAt(self, ((JB_LinkedList**)((&JB_StdErr))));
	self->MaxErrors = 512;
	JB__API_NilHappened = nil;
}

void JB_Rec_Destructor(JB_ErrorReceiver* self) {
	JB_LLRef_Destructor((&self->List));
	JB_Decr(self->Source);
	JB_LinkedList_Destructor(self);
}

JB_Error* JB_Rec_FirstError(JB_ErrorReceiver* self) {
	{
		LLRef _LoopSrc2 = self->List;
		JB_Error* err = (JB_Error*)(_LoopSrc2.First);
		while (err) {
			JB_LinkedList_ListSanity(err);
			JB_Error* _N1 = (JB_Error*)(err->_Next);
			if ((!JB_Err_IsWarning(err))) {
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
	JB_Error* err = JB_Err__New(node);
	JB_Incr(err);
	JB_SetRef(err->Description, Desc);
	JB_Rec_NewItem(self, err);
	JB_Decr(err);
}

bool JB_Rec_OK(JB_ErrorReceiver* self) {
	return ((bool)self) and ((!self->ErrorCount));
}

void JB_Rec_NewItem(JB_ErrorReceiver* self, JB_Error* Err) {
	if (JB_Err_IsWarning(Err)) {
		self->WarnCount++;
	} else {
		JB_DoAt(1);
		self->ErrorCount++;
	}
	if ((!(JB_Str_Exists(Err->Path)))) {
		JB_SetRef(Err->Path, self->Source);
	}
	JB_LLRef_SyntaxAppend((&self->List), Err);
}

int JB_Rec_TotalCount(JB_ErrorReceiver* self) {
	return self->ErrorCount + self->WarnCount;
}

JB_ErrorReceiver* JB_Rec__Alloc() {
	return ((JB_ErrorReceiver*)JB_New(JB_ErrorReceiver));
}

JB_String* JB_Rec__ErrorType(bool IsWarning) {
	if (IsWarning) {
		return JB_str_41;
	} else {
		return JB_str_42;
	}
	return JB_str_0;
}

JB_ErrorReceiver* JB_Rec__New() {
	JB_ErrorReceiver* Result = JB_Rec__Alloc();
	if (Result) {
		JB_Rec_Constructor(Result);
	}
	return Result;
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
	if ((self->NItems >= 31) or (self->NItems < 0)) {
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
	Message* _tmp226 = ((Message*)JB_Tree_First(self));
	JB_Incr(_tmp226);
	JB_FS_AppendMsg(fs, _tmp226);
	JB_Decr(_tmp226);
	Message* _tmp227 = ((Message*)JB_Tree_Last(self));
	JB_Incr(_tmp227);
	JB_Msg_RenderPrm(_tmp227, fs, '[', ']');
	JB_Decr(_tmp227);
}

void JB_Msg_AccessErr(Message* self, Syntax* s, JB_String* name) {
	if ((!self)) {
		JB_API__NilHandler();
		return;
	}
	FastString* fs = JB_FS__New();
	JB_Incr(fs);
	JB_FS_AppendString(fs, JB_str_62);
	JB_FS_AppendString(fs, s->LongName);
	JB_FS_MsgErrorName(fs, name);
	JB_String* _tmp247 = JB_FS_GetResult(fs);
	JB_Incr(_tmp247);
	JB_Decr(fs);
	JB_Rec_NewItemWithNode(JB_StdErr, self, _tmp247);
	JB_Decr(_tmp247);
}

void JB_Msg_Adj__(Message* self, FastString* fs) {
	Message* _tmp228 = ((Message*)JB_Tree_First(self));
	JB_Incr(_tmp228);
	JB_FS_AppendMsg(fs, _tmp228);
	JB_Decr(_tmp228);
	JB_FS_AppendByte(fs, '~');
	Message* _tmp229 = ((Message*)JB_Tree_Last(self));
	JB_Incr(_tmp229);
	JB_FS_AppendMsg(fs, _tmp229);
	JB_Decr(_tmp229);
}

void JB_Msg_Ana__(Message* self, FastString* fs) {
	JB_FS_AppendString(fs, JB_str_61);
	JB_FS_AppendString(fs, self->Name);
}

void JB_Msg_ARel__(Message* self, FastString* fs) {
	Message* _tmp230 = ((Message*)JB_Tree_First(self));
	JB_Incr(_tmp230);
	JB_FS_AppendMsg(fs, _tmp230);
	JB_Decr(_tmp230);
	JB_FS_AppendString(fs, self->Name);
}

void JB_Msg_Arg__(Message* self, FastString* fs) {
	Message* P = ((Message*)JB_Tree_Parent(self));
	if (P) {
		if (JB_Msg_SyxOppEquals(P, JB_SyxBra, false)) {
			JB_FS_AppendByte(fs, '{');
			JB_Msg_FSListSep(self, fs, JB_str_50);
			JB_FS_AppendByte(fs, '}');
			return;
		}
		JB_FS_AppendString(fs, JB_str_51);
		fs->Indent++;
	}
	JB_Msg_FSListArg(self, fs);
	if (P) {
		fs->Indent--;
		JB_FS_AppendIndent(fs);
		JB_FS_AppendByte(fs, '}');
	}
}

void JB_Msg_Arr__(Message* self, FastString* fs) {
	JB_FS_AppendByte(fs, '[');
	JB_Msg_FSListSep(self, fs, JB_str_50);
	JB_FS_AppendByte(fs, ']');
}

void JB_Msg_Back__(Message* self, FastString* fs) {
	if (JB_int_Found(JB_Str_FindByte(self->Name, 0, '`'))) {
		JB_Msg_Str__(self, fs);
	} else {
		JB_FS_AppendByte(fs, '`');
		JB_FS_AppendString(fs, self->Name);
		JB_FS_AppendByte(fs, '`');
	}
}

void JB_Msg_Bin__(Message* self, FastString* fs) {
	JB_Str_AppendAsBinary(self->Name, fs);
}

void JB_Msg_Bra__(Message* self, FastString* fs) {
	JB_FS_AppendByte(fs, '(');
	Message* _tmp231 = ((Message*)JB_Tree_First(self));
	JB_Incr(_tmp231);
	JB_FS_AppendMsg(fs, _tmp231);
	JB_Decr(_tmp231);
	JB_FS_AppendByte(fs, ')');
}

void JB_Msg_BRel__(Message* self, FastString* fs) {
	JB_FS_AppendString(fs, self->Name);
	Message* _tmp232 = ((Message*)JB_Tree_First(self));
	JB_Incr(_tmp232);
	JB_FS_AppendMsg(fs, _tmp232);
	JB_Decr(_tmp232);
}

void JB_Msg_Char__(Message* self, FastString* fs) {
	JB_FS_AppendByte(fs, '\'');
	JB_String* _tmp233 = JB_Str_EscapeChr(self->Name);
	JB_Incr(_tmp233);
	JB_FS_AppendString(fs, _tmp233);
	JB_Decr(_tmp233);
	JB_FS_AppendByte(fs, '\'');
}

void JB_Msg_Cnj__(Message* self, FastString* fs) {
	JB_FS_AppendByte(fs, '#');
	JB_FS_AppendString(fs, self->Name);
}

void JB_Msg_ConstructorCopy(Message* self, Message* other) {
	JB_Tree_Constructor0(self);
	self->Type = other->Type;
	JB_String* _tmp221 = other->Name;
	JB_Incr(_tmp221);
	self->Name = _tmp221;
	self->Position = other->Position;
	self->Obj = other->Obj;
}

void JB_Msg_ConstructorFuncName(Message* self, Syntax* Func, JB_String* Name) {
	JB_Tree_Constructor0(self);
	self->Obj = nil;
	self->Type = Func;
	JB_Incr(Name);
	self->Name = Name;
	self->Position = JB__Tk_BaseMessagePosition;
}

void JB_Msg_ConstructorParentPos(Message* self, Message* Parent, int Position) {
	JB_Tree_Constructor(self, Parent);
	self->Obj = nil;
	self->Type = nil;
	JB_Incr(JB_str_0);
	self->Name = JB_str_0;
	self->Position = Position;
}

void JB_Msg_ConstructorParser(Message* self, Message* Parent, Syntax* Func, int BytePos, JB_String* Name) {
	JB_Tree_Constructor(self, Parent);
	self->Obj = nil;
	self->Position = BytePos;
	self->Type = Func;
	JB_Incr(Name);
	self->Name = Name;
}

Message* JB_Msg_Copy(Message* self, bool DefaultLayer) {
	if (DefaultLayer) {
		return JB_Msg_NormalCopy(self);
	} else {
		JB_MemoryLayer* _tmp224 = JB_ObjLayer(self);
		JB_Incr(_tmp224);
		Message* _tmp225 = JB_Msg_LayerCopy(self, _tmp224);
		JB_Incr(_tmp225);
		JB_Decr(_tmp224);
		JB_SafeDecr(_tmp225);
		return _tmp225;
	}
	return nil;
}

void JB_Msg_Decl__(Message* self, FastString* fs) {
	Message* ch = ((Message*)JB_Tree_First(self));
	JB_Incr(ch);
	if ((!ch)) {
		JB_Decr(ch);
		return;
	}
	JB_FS_AppendByte(fs, '|');
	JB_FS_AppendMsg(fs, ch);
	JB_FS_AppendByte(fs, '|');
	JB_SetRef(ch, ((Message*)JB_Tree_NextSib(ch)));
	while (ch) {
		JB_FS_AppendByte(fs, ' ');
		JB_FS_AppendMsg(fs, ch);
		JB_SetRef(ch, ((Message*)JB_Tree_NextSib(ch)));
	};
	JB_Decr(ch);
}

void JB_Msg_Destructor(Message* self) {
	JB_Decr(self->Name);
	JB_Tree_Destructor(self);
}

void JB_Msg_Dot__(Message* self, FastString* fs) {
	Message* ch = ((Message*)JB_Tree_First(self));
	JB_Incr(ch);
	if ((!ch)) {
		JB_Decr(ch);
		return;
	}
	JB_FS_AppendMsg(fs, ch);
	JB_FS_AppendByte(fs, '.');
	JB_FS_AppendString(fs, self->Name);
	Message* _tmp234 = ((Message*)JB_Tree_NextSib(ch));
	JB_Incr(_tmp234);
	JB_Decr(ch);
	JB_FS_AppendMsg(fs, _tmp234);
	JB_Decr(_tmp234);
}

void JB_Msg_Dummy(Message* self, FastString* fs) {
}

void JB_Msg_Emb__(Message* self, FastString* fs) {
	JB_FS_AppendString(fs, self->Name);
	if ((!JB_Tree_HasChildren(self))) {
		return;
	}
	JB_Msg_RenderWithSpaces(self, fs, nil);
}

void JB_Msg_ERel__(Message* self, FastString* fs) {
	Message* ch = ((Message*)JB_Tree_First(self));
	JB_Incr(ch);
	if ((!ch)) {
		JB_Decr(ch);
		return;
	}
	JB_FS_AppendMsg(fs, ch);
	JB_FS_AppendByte(fs, ' ');
	JB_SetRef(ch, ((Message*)JB_Tree_NextSib(ch)));
	if ((!ch)) {
		JB_Decr(ch);
		return;
	}
	JB_FS_AppendMsg(fs, ch);
	JB_FS_AppendString(fs, JB_str_54);
	JB_SetRef(ch, ((Message*)JB_Tree_NextSib(ch)));
	if ((!ch)) {
		JB_Decr(ch);
		return;
	}
	JB_FS_AppendMsg(fs, ch);
	JB_Decr(ch);
}

Message* JB_Msg_FixTRels(Message* self, Message* Last) {
	if ((!Last)) {
	} else if ((!(JB_Msg_SyxOppEquals(Last, JB_SyxTRel, false)))) {
		JB_Tree_SyntaxAppend(self, Last);
	} else {
		Message* _tmp246 = ((Message*)JB_Tree_First(Last));
		JB_Incr(_tmp246);
		JB_Tree_SyntaxAppend(self, _tmp246);
		JB_Decr(_tmp246);
		(JB_Tree_FirstSet(Last, self));
		self = Last;
	}
	return self;
}

void JB_Msg_FSListArg(Message* self, FastString* fs) {
	{
		Message* ch = ((Message*)JB_Tree_First_(self));
		JB_Incr(ch);
		while (ch) {
			Message* _N1 = ((Message*)JB_Tree_NextSib(ch));
			JB_Incr(_N1);
			JB_FS_AppendIndent(fs);
			JB_FS_AppendMsg(fs, ch);
			JB_FS_AppendByte(fs, '\n');
			JB_SetRef(ch, _N1);
			JB_Decr(_N1);
		};
		JB_Decr(ch);
	};
}

void JB_Msg_FSListSep(Message* self, FastString* fs, JB_String* sep) {
	{
		Message* ch = ((Message*)JB_Tree_First_(self));
		JB_Incr(ch);
		Message* _first2 = ch;
		JB_Incr(_first2);
		while (ch) {
			Message* _N1 = ((Message*)JB_Tree_NextSib(ch));
			JB_Incr(_N1);
			if (_first2 != ch) {
				JB_FS_AppendString(fs, sep);
			}
			//start;
			JB_FS_AppendMsg(fs, ch);
			JB_SetRef(ch, _N1);
			JB_Decr(_N1);
		};
		JB_Decr(_first2);
		JB_Decr(ch);
	};
}

void JB_Msg_Func__(Message* self, FastString* fs) {
	Message* ch = ((Message*)JB_Tree_First(self));
	JB_Incr(ch);
	if ((!ch)) {
		JB_Decr(ch);
		return;
	}
	JB_FS_AppendMsg(fs, ch);
	Message* _tmp235 = ((Message*)JB_Tree_NextSib(ch));
	JB_Incr(_tmp235);
	JB_Decr(ch);
	JB_FS_AppendMsg(fs, _tmp235);
	JB_Decr(_tmp235);
}

JB_String* JB_Msg_FuncName(Message* self) {
	return JB_Str_LowerCase(self->Type->LongName);
}

void JB_Msg_Item__(Message* self, FastString* fs) {
	Message* ch = ((Message*)JB_Tree_First(self));
	JB_Incr(ch);
	if ((!ch)) {
		JB_Decr(ch);
		return;
	}
	JB_FS_AppendMsg(fs, ch);
	JB_FS_AppendString(fs, JB_str_55);
	Message* _tmp236 = ((Message*)JB_Tree_NextSib(ch));
	JB_Incr(_tmp236);
	JB_Decr(ch);
	JB_FS_AppendMsg(fs, _tmp236);
	JB_Decr(_tmp236);
}

Message* JB_Msg_LayerCopy(Message* self, JB_MemoryLayer* L) {
	Message* Result = JB_Msg__NewWithLayerCopy(L, self);
	JB_Incr(Result);
	{
		Message* v = ((Message*)JB_Tree_First_(self));
		JB_Incr(v);
		while (v) {
			Message* _N1 = ((Message*)JB_Tree_NextSib(v));
			JB_Incr(_N1);
			Message* _tmp222 = JB_Msg_LayerCopy(v, L);
			JB_Incr(_tmp222);
			JB_Tree_SyntaxAppend(Result, _tmp222);
			JB_Decr(_tmp222);
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
		JB_Incr(ch);
		while (ch) {
			Message* _N1 = ((Message*)JB_Tree_NextSib(ch));
			JB_Incr(_N1);
			count++;
			if (count > 1) {
				JB_FS_AppendString(fs, JB_str_50);
			} else if (((JB_Msg_SyxOppEquals(ch, JB_SyxItem, false))) or ((JB_Msg_SyxOppEquals(ch, JB_SyxDecl, false)))) {
				count = 2;
			}
			JB_FS_AppendMsg(fs, ch);
			JB_SetRef(ch, _N1);
			JB_Decr(_N1);
		};
		JB_Decr(ch);
	};
	if (count == 1) {
		JB_FS_AppendByte(fs, ',');
	}
	JB_FS_AppendByte(fs, ')');
}

Message* JB_Msg_LoadNameFromList(Message* self, Message* line) {
	Message* itm = ((Message*)JB_Tree_First(line));
	JB_Incr(itm);
	if ((!(JB_Msg_SyxOppEquals(itm, JB_SyxItem, false)))) {
		JB_Msg_Fail(itm, nil);
		JB_Decr(itm);
		return nil;
	}
	Message* func = ((Message*)JB_Tree_First(itm));
	JB_Incr(func);
	Syntax* _tmp10 = JB_Msg__GetSyx(func);
	JB_Incr(_tmp10);
	if ((!_tmp10)) {
		JB_Decr(itm);
		JB_Decr(func);
		JB_Decr(_tmp10);
		return nil;
	}
	self->Type = _tmp10;
	JB_Decr(_tmp10);
	Message* _tmp242 = ((Message*)JB_Tree_NextSib(func));
	JB_Incr(_tmp242);
	JB_Decr(func);
	JB_SetRef(self->Name, JB_Msg_Nyme(_tmp242));
	JB_Decr(_tmp242);
	JB_SafeDecr(itm);
	return itm;
}

JB_String* JB_Msg_Locate(Message* self) {
	JB_String* fname = JB_str_151;
	JB_Incr(fname);
	if ((!self)) {
		JB_SafeDecr(fname);
		return fname;
	}
	JB_String* s = self->Name;
	JB_Incr(s);
	if ((!(JB_Str_Exists(s)))) {
		JB_SetRef(s, JB_Msg_Render(self, nil));
	}
	if (self->Type) {
		JB_SetRef(fname, self->Type->Name);
	}
	JB_String* rs = JB_str_151;
	JB_Incr(rs);
	Message* _tmp328 = ((Message*)JB_Tree_Root(self));
	JB_Incr(_tmp328);
	JB_Object* r = _tmp328->Obj;
	JB_Incr(r);
	JB_Decr(_tmp328);
	if (((bool)r) and JB_Object_Isa(r, JB_AsClass(JB_String))) {
		JB_SetRef(rs, r);
	}
	JB_Decr(r);
	FastString* _fs_fs = JB_FS__New();
	JB_Incr(_fs_fs);
	JB_FS_AppendString(_fs_fs, fname);
	JB_Decr(fname);
	JB_FS_AppendString(_fs_fs, JB_str_152);
	JB_FS_AppendString(_fs_fs, s);
	JB_Decr(s);
	JB_FS_AppendString(_fs_fs, JB_str_153);
	JB_FS_AppendInt32AsText(_fs_fs, self->Position);
	JB_FS_AppendString(_fs_fs, JB_str_154);
	JB_FS_AppendString(_fs_fs, rs);
	JB_Decr(rs);
	JB_String* _fs_str = JB_FS_SyntaxCastString(_fs_fs);
	JB_Incr(_fs_str);
	JB_SetRef(_fs_fs, nil);
	JB_Decr(_fs_fs);
	JB_SafeDecr(_fs_str);
	return _fs_str;
}

JB_String* JB_Msg_MakeReadable(Message* self, FastString* fs_in) {
	FastString* fs = JB_FS__FastNew(fs_in);
	JB_Incr(fs);
	bool printself = (((bool)JB_FreeIfDead(((Message*)JB_Tree_Parent(self)))) or (!JB_Msg_SyxOppEquals(self, JB_SyxArg, false)));
	if (printself) {
		JB_FS_AppendByte(fs, '(');
		JB_FS_AppendString(fs, self->Type->Name);
		JB_FS_AppendString(fs, JB_str_55);
		if (JB_Str_Exists(self->Name)) {
			JB_FreeIfDead(JB_ObjRender(self->Name, fs));
		}
	}
	if (JB_Tree_HasChildren(self)) {
		fs->Indent = (fs->Indent + ((int)printself));
		{
			Message* ch = ((Message*)JB_Tree_First_(self));
			JB_Incr(ch);
			while (ch) {
				Message* _N1 = ((Message*)JB_Tree_NextSib(ch));
				JB_Incr(_N1);
				JB_FS_AppendByte(fs, '\n');
				JB_FS_AppendIndent(fs);
				JB_FreeIfDead(JB_Msg_MakeReadable(ch, fs));
				JB_SetRef(ch, _N1);
				JB_Decr(_N1);
			};
			JB_Decr(ch);
		};
		fs->Indent = (fs->Indent - ((int)printself));
		JB_FS_AppendByte(fs, '\n');
		JB_FS_AppendIndent(fs);
	}
	if (printself) {
		JB_FS_AppendByte(fs, ')');
	}
	JB_String* _tmp245 = JB_FS_SmartResult(fs, fs_in);
	JB_Incr(_tmp245);
	JB_Decr(fs);
	JB_SafeDecr(_tmp245);
	return _tmp245;
}

void JB_Msg_Name__(Message* self, FastString* fs) {
	Message* ch = ((Message*)JB_Tree_First(self));
	JB_Incr(ch);
	if (ch) {
		JB_FS_AppendString(fs, self->Name);
		JB_FS_AppendString(fs, JB_str_56);
		JB_FS_AppendMsg(fs, ch);
	} else {
		JB_FS_AppendByte(fs, '@');
		JB_FS_AppendString(fs, self->Name);
	}
	JB_Decr(ch);
}

Message* JB_Msg_NormalCopy(Message* self) {
	Message* Result = JB_Msg__NewFuncName(self->Type, self->Name);
	JB_Incr(Result);
	{
		Message* v = ((Message*)JB_Tree_First_(self));
		JB_Incr(v);
		while (v) {
			Message* _N1 = ((Message*)JB_Tree_NextSib(v));
			JB_Incr(_N1);
			Message* _tmp223 = JB_Msg_NormalCopy(v);
			JB_Incr(_tmp223);
			JB_Tree_SyntaxAppend(Result, _tmp223);
			JB_Decr(_tmp223);
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

s64 JB_Msg_ParseInt(Message* self) {
	return JB_Str_ParseInt(self->Name, self);
}

Message* JB_Msg_ParseReadable(Message* self) {
	if ((!self)) {
		return nil;
	}
	Message* Result = JB_Fn_Msg(JB_SyxArg, JB_str_0);
	JB_Incr(Result);
	Message* _tmp280 = ((Message*)JB_Tree_First(self));
	JB_Incr(_tmp280);
	JB_Msg_ReadableParse_(Result, _tmp280);
	JB_Decr(_tmp280);
	JB_SafeDecr(Result);
	return Result;
}

Message* JB_Msg_PoorAnt(Message* self) {
	if (self) {
		return ((Message*)JB_Tree_Parent(self));
	}
	return nil;
}

void JB_Msg_Prm__(Message* self, FastString* fs) {
	JB_Msg_RenderPrm(self, fs, '(', ')');
}

void JB_Msg_ReadableParse_(Message* self, Message* Src) {
	{
		Message* line = Src;
		JB_Incr(line);
		while (line) {
			if ((!(((JB_Msg_SyxOppEquals(line, JB_SyxList, false))) or ((JB_Msg_SyxOppEquals(line, JB_SyxBra, false)))))) {
				JB_Msg_Fail(line, nil);
				JB_Decr(line);
				return;
			}
			Message* Result = JB_Msg__NewParentPos(self, line->Position);
			JB_Incr(Result);
			Message* C0 = JB_Msg_LoadNameFromList(Result, line);
			JB_Incr(C0);
			if (C0) {
				Message* _tmp243 = ((Message*)JB_Tree_NextSib(C0));
				JB_Incr(_tmp243);
				JB_Msg_ReadableParse_(Result, _tmp243);
				JB_Decr(_tmp243);
			}
			JB_Decr(C0);
			JB_Decr(Result);
			JB_SetRef(line, ((Message*)JB_Tree_NextSib(line)));
		};
		JB_Decr(line);
	};
}

void JB_Msg_Rel__(Message* self, FastString* fs) {
	JB_Msg_RenderWithSpaces(self, fs, nil);
}

JB_String* JB_Msg_Render(Message* self, FastString* fs_in) {
	FastString* fs = JB_FS__FastNew(fs_in);
	JB_Incr(fs);
	JB_FS_AppendMsg(fs, self);
	JB_String* _tmp244 = JB_FS_SmartResult(fs, fs_in);
	JB_Incr(_tmp244);
	JB_Decr(fs);
	JB_SafeDecr(_tmp244);
	return _tmp244;
}

void JB_Msg_RenderPrm(Message* self, FastString* fs, byte b1, byte b2) {
	JB_FS_AppendByte(fs, b1);
	JB_Msg_FSListSep(self, fs, JB_str_50);
	JB_FS_AppendByte(fs, b2);
}

void JB_Msg_RenderWithSpaces(Message* self, FastString* fs, Message* ch) {
	if ((!(ch))) {
		ch = ((Message*)JB_Tree_First(self));
	}
	while (ch) {
		JB_FS_AppendMsg(fs, ch);
		ch = ((Message*)JB_Tree_NextSib(ch));
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
	Message* ch = ((Message*)JB_Tree_First(self));
	JB_Incr(ch);
	Message* _tmp238 = ((Message*)JB_Tree_NextSib(ch));
	JB_Incr(_tmp238);
	JB_FS_AppendMsg(fs, _tmp238);
	JB_Decr(_tmp238);
	JB_FS_AppendString(fs, JB_str_57);
	if (JB_Tree_HasOneChild(ch)) {
		Message* _tmp239 = ((Message*)JB_Tree_First(ch));
		JB_Incr(_tmp239);
		JB_FS_AppendMsg(fs, _tmp239);
		JB_Decr(_tmp239);
	} else {
		JB_FS_AppendByte(fs, '\n');
		JB_Msg_FSListArg(ch, fs);
	}
	JB_Decr(ch);
	JB_FS_AppendString(fs, JB_str_58);
}

void JB_Msg_SDot__(Message* self, FastString* fs) {
	JB_FS_AppendByte(fs, '.');
	JB_FS_AppendString(fs, self->Name);
	Message* _tmp237 = ((Message*)JB_Tree_First(self));
	JB_Incr(_tmp237);
	JB_FS_AppendMsg(fs, _tmp237);
	JB_Decr(_tmp237);
}

void JB_Msg_Sheb__(Message* self, FastString* fs) {
	JB_FS_AppendString(fs, JB_str_59);
	JB_FS_AppendString(fs, self->Name);
}

void JB_Msg_SOpp__(Message* self, FastString* fs) {
	JB_FS_AppendString(fs, self->Name);
}

void JB_Msg_SStr__(Message* self, FastString* fs) {
	if (JB_int_Found(JB_Str_FindStr(self->Name, 0, JB_str_52))) {
		JB_Msg_Str__(self, fs);
	} else {
		JB_FS_AppendString(fs, JB_str_53);
		JB_FS_AppendString(fs, self->Name);
		JB_FS_AppendString(fs, JB_str_52);
	}
}

void JB_Msg_SThg__(Message* self, FastString* fs) {
	JB_FS_AppendString(fs, self->Name);
}

void JB_Msg_Str__(Message* self, FastString* fs) {
	JB_FS_AppendByte(fs, '"');
	JB_FS_AppendEscape(fs, self->Name);
	{
		Message* ch = ((Message*)JB_Tree_First_(self));
		JB_Incr(ch);
		while (ch) {
			Message* _N1 = ((Message*)JB_Tree_NextSib(ch));
			JB_Incr(_N1);
			if (JB_Msg_SyxOppEquals(ch, JB_SyxEmb, false)) {
				JB_FS_AppendEscape(fs, ch->Name);
			} else {
				JB_FS_AppendByte(fs, '$');
				JB_FS_AppendByte(fs, '{');
				JB_FS_AppendMsg(fs, ch);
				JB_FS_AppendByte(fs, '}');
			}
			JB_SetRef(ch, _N1);
			JB_Decr(_N1);
		};
		JB_Decr(ch);
	};
	JB_FS_AppendByte(fs, '"');
}

Message* JB_Msg_AccessSyxName(Message* self, Syntax* s, JB_String* name, bool Err) {
	{
		Message* ch = ((Message*)JB_Tree_First_(self));
		while (ch) {
			Message* _N1 = ((Message*)JB_Tree_NextSib(ch));
			if (((JB_Msg_SyxOppEquals(ch, s, false))) and ((JB_Msg_SyntaxEquals(ch, name, false)))) {
				return ch;
			}
			ch = _N1;
		};
	};
	if (Err) {
		JB_Msg_AccessErr(self, s, name);
	}
	return nil;
}

bool JB_Msg_SyntaxEquals(Message* self, JB_String* name, bool Aware) {
	return ((bool)self) and JB_Str_Equals(self->Name, name, Aware);
}

bool JB_Msg_SyxOppEquals(Message* self, Syntax* X, bool Aware) {
	return ((bool)self) and (self->Type == X);
}

void JB_Msg_Fail(Message* self, JB_String* Error) {
	JB_Incr(Error);
	if ((!(JB_Str_Exists(Error)))) {
		FastString* _fs_fs = JB_FS__New();
		JB_Incr(_fs_fs);
		JB_FS_AppendString(_fs_fs, JB_str_89);
		JB_String* _tmp281 = JB_Msg_FuncName(self);
		JB_Incr(_tmp281);
		JB_FS_AppendString(_fs_fs, _tmp281);
		JB_Decr(_tmp281);
		JB_FS_AppendString(_fs_fs, JB_str_90);
		JB_String* _tmp282 = JB_Msg_Render(self, nil);
		JB_Incr(_tmp282);
		JB_FS_AppendString(_fs_fs, _tmp282);
		JB_Decr(_tmp282);
		JB_FS_AppendString(_fs_fs, JB_str_91);
		JB_String* _fs_str = JB_FS_SyntaxCastString(_fs_fs);
		JB_Incr(_fs_str);
		JB_SetRef(_fs_fs, nil);
		JB_Decr(_fs_fs);
		JB_SetRef(Error, _fs_str);
		JB_Decr(_fs_str);
	}
	JB_Rec_NewItemWithNode(JB_StdErr, self, Error);
	JB_Decr(Error);
}

void JB_Msg_Test(Message* self, JB_String* new_render, JB_String* name) {
	if ((!JB_Msg_TestSub(self, new_render, name))) {
		FastString* _fs_fs = JB_FS__New();
		JB_Incr(_fs_fs);
		JB_FS_AppendString(_fs_fs, JB_str_157);
		JB_FS_AppendString(_fs_fs, name);
		JB_FS_AppendString(_fs_fs, JB_str_158);
		JB_FS_AppendString(_fs_fs, new_render);
		JB_String* _fs_str = JB_FS_SyntaxCastString(_fs_fs);
		JB_Incr(_fs_str);
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
	LeakTester* LKT = JB_Lk__New(name);
	JB_Incr(LKT);
	{
		Message* reparse = JB_Str_ParseAs(new_render, name);
		JB_Incr(reparse);
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
		JB_String* self_render = JB_Msg_Render(self, nil);
		JB_Incr(self_render);
		if ((!JB_Str_Exists(self_render))) {
			JB_Decr(LKT);
			JB_Decr(reparse);
			JB_Decr(self_render);
			return nil;
		}
		JB_String* reparse_render = JB_Msg_Render(reparse, nil);
		JB_Incr(reparse_render);
		JB_Decr(reparse);
		if ((!JB_Str_Exists(reparse_render))) {
			JB_Decr(LKT);
			JB_Decr(self_render);
			JB_Decr(reparse_render);
			return nil;
		}
		if ((!JB_Rec_OK(JB_StdErr))) {
			JB_Decr(LKT);
			JB_Decr(self_render);
			JB_Decr(reparse_render);
			return nil;
		}
		if ((!(JB_Str_SyntaxEquals(self_render, reparse_render, false)))) {
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
	Message* p = ((Message*)JB_Tree_Parent(self));
	if ((!JB_Msg_SyxOppEquals(p, JB_SyxArg, false))) {
		JB_FS_AppendString(fs, JB_str_60);
	}
	JB_FS_AppendString(fs, self->Name);
	if ((!JB_Tree_HasChildren(self))) {
		return;
	}
	JB_FS_AppendByte(fs, ' ');
	JB_Msg_RenderWithSpaces(self, fs, nil);
}

bool JB_Msg_TreeCompare(Message* self, Message* other) {
	if ((!self) or (!other)) {
		return JB_CompareError(self, other);
	}
	if ((self->Type != other->Type) or ((!JB_Str_SyntaxEquals(self->Name, other->Name, true)))) {
		return JB_CompareError(self, other);
	}
	Message* o1 = ((Message*)JB_Tree_First(other));
	JB_Incr(o1);
	Message* m1 = ((Message*)JB_Tree_First(self));
	JB_Incr(m1);
	while (((bool)o1) or ((bool)m1)) {
		if ((!JB_Msg_TreeCompare(m1, o1))) {
			JB_Decr(o1);
			JB_Decr(m1);
			return nil;
		}
		JB_SetRef(o1, ((Message*)JB_Tree_NextSib(o1)));
		JB_SetRef(m1, ((Message*)JB_Tree_NextSib(m1)));
	};
	JB_Decr(m1);
	JB_Decr(o1);
	return true;
}

void JB_Msg_TRel__(Message* self, FastString* fs) {
	JB_Msg_RenderWithSpaces(self, fs, nil);
}

void JB_Msg_Type__(Message* self, FastString* fs) {
	Message* ch = ((Message*)JB_Tree_First(self));
	JB_Incr(ch);
	if ((!ch)) {
		JB_Decr(ch);
		return;
	}
	JB_FS_AppendMsg(fs, ch);
	JB_FS_AppendByte(fs, '|');
	JB_SetRef(ch, ((Message*)JB_Tree_NextSib(ch)));
	if ((!ch)) {
		JB_Decr(ch);
		return;
	}
	JB_FS_AppendMsg(fs, ch);
	JB_Decr(ch);
	JB_FS_AppendByte(fs, '|');
}

void JB_Msg_UnEmbed(Message* self) {
	Message* s1 = ((Message*)JB_Tree_First(self));
	JB_Incr(s1);
	if (((JB_Msg_SyxOppEquals(s1, JB_SyxEmb, false))) and (!JB_FreeIfDead(((Message*)JB_Tree_NextSib(s1))))) {
		JB_Tree_Remove(s1);
		JB_SetRef(self->Name, s1->Name);
	}
	JB_Decr(s1);
}

void JB_Msg_Unit__(Message* self, FastString* fs) {
	if (JB_Str_SyntaxAccess(self->Name, 0) == '0') {
		JB_FS_AppendString(fs, self->Name);
		Message* _tmp240 = ((Message*)JB_Tree_First(self));
		JB_Incr(_tmp240);
		JB_FS_AppendMsg(fs, _tmp240);
		JB_Decr(_tmp240);
	} else {
		Message* _tmp241 = ((Message*)JB_Tree_First(self));
		JB_Incr(_tmp241);
		JB_FS_AppendMsg(fs, _tmp241);
		JB_Decr(_tmp241);
		JB_FS_AppendString(fs, self->Name);
	}
}

Message* JB_Msg__Alloc() {
	return ((Message*)JB_New(Message));
}

Syntax* JB_Msg__GetSyx(Message* msg) {
	Syntax* _tmp8 = ((Syntax*)JB_Dict_Syntax(JB_SyxDict, msg->Name));
	JB_Incr(_tmp8);
	if ((!_tmp8)) {
		FastString* _fs_fs = JB_FS__New();
		JB_Incr(_fs_fs);
		JB_FS_AppendString(_fs_fs, JB_str_49);
		JB_FS_AppendString(_fs_fs, msg->Name);
		JB_String* _fs_str = JB_FS_SyntaxCastString(_fs_fs);
		JB_Incr(_fs_str);
		JB_SetRef(_fs_fs, nil);
		JB_Decr(_fs_fs);
		JB_Msg_Fail(msg, _fs_str);
		JB_Decr(_fs_str);
		JB_Decr(_tmp8);
		return nil;
	}
	JB_SafeDecr(_tmp8);
	return _tmp8;
}

Message* JB_Msg__LayerAlloc(JB_MemoryLayer* _L) {
	return ((Message*)JB_LayerNew(_L, Message));
}

Message* JB_Msg__NewFuncName(Syntax* Func, JB_String* Name) {
	Message* Result = JB_Msg__Alloc();
	if (Result) {
		JB_Msg_ConstructorFuncName(Result, Func, Name);
	}
	return Result;
}

Message* JB_Msg__NewParentPos(Message* Parent, int Position) {
	Message* Result = JB_Msg__Alloc();
	if (Result) {
		JB_Msg_ConstructorParentPos(Result, Parent, Position);
	}
	return Result;
}

Message* JB_Msg__NewParser(Message* Parent, Syntax* Func, int BytePos, JB_String* Name) {
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
	if ((!JB_Obj_NilCheck(self))) {
		return nil;
	}
	return self->Name;
	return JB_str_0;
}

__lib__ Syntax* jb_msg_type(Message* self) {
	if ((!JB_Obj_NilCheck(self))) {
		return nil;
	}
	return self->Type;
	return nil;
}

__lib__ int jb_msg_position(Message* self) {
	if ((!JB_Obj_NilCheck(self))) {
		return nil;
	}
	return self->Position;
	return 0;
}

__lib__ _voidptr jb_msg_tag(Message* self) {
	if ((!JB_Obj_NilCheck(self))) {
		return nil;
	}
	return ((_voidptr)self->Obj);
	return nil;
}

__lib__ void jb_msg_nameset(Message* self, JB_String* Result) {
	if ((!JB_Obj_NilCheck(self))) {
		return;
	}
	JB_SetRef(self->Name, Result);
}

__lib__ void jb_msg_typeset(Message* self, Syntax* Result) {
	if ((!JB_Obj_NilCheck(self))) {
		return;
	}
	self->Type = Result;
}

__lib__ void jb_msg_positionset(Message* self, int Result) {
	if ((!JB_Obj_NilCheck(self))) {
		return;
	}
	self->Position = Result;
}

__lib__ void jb_msg_tagset(Message* self, _voidptr Result) {
	if ((!JB_Obj_NilCheck(self))) {
		return;
	}
	self->Obj = ((JB_Object*)Result);
}

__lib__ void jb_msg_firstset(Message* self, Message* Result) {
	if ((!JB_Obj_NilCheck(self))) {
		return;
	}
	(JB_Tree_FirstSet(self, Result));
}

__lib__ void jb_msg_lastset(Message* self, Message* Result) {
	if ((!JB_Obj_NilCheck(self))) {
		return;
	}
	(JB_Tree_LastSet(self, Result));
}

__lib__ void jb_msg_prevset(Message* self, Message* Result) {
	if ((!JB_Obj_NilCheck(self))) {
		return;
	}
	(JB_Tree_PrevSibSet(self, Result));
}

__lib__ void jb_msg_nextset(Message* self, Message* Result) {
	if ((!JB_Obj_NilCheck(self))) {
		return;
	}
	(JB_Tree_NextSibSet(self, Result));
}

__lib__ Message* jb_msg_first(Message* self) {
	if ((!JB_Obj_NilCheck(self))) {
		return nil;
	}
	return ((Message*)JB_Tree_First(self));
	return nil;
}

__lib__ Message* jb_msg_last(Message* self) {
	if ((!JB_Obj_NilCheck(self))) {
		return nil;
	}
	return ((Message*)JB_Tree_Last(self));
	return nil;
}

__lib__ Message* jb_msg_prev(Message* self) {
	if ((!JB_Obj_NilCheck(self))) {
		return nil;
	}
	return ((Message*)JB_Tree_PrevSib(self));
	return nil;
}

__lib__ Message* jb_msg_next(Message* self) {
	if ((!JB_Obj_NilCheck(self))) {
		return nil;
	}
	return ((Message*)JB_Tree_NextSib(self));
	return nil;
}

__lib__ Message* jb_msg_parent(Message* self) {
	if ((!JB_Obj_NilCheck(self))) {
		return nil;
	}
	return ((Message*)JB_Tree_Parent(self));
	return nil;
}

__lib__ Message* jb_msg_flatnext(Message* self) {
	if ((!JB_Obj_NilCheck(self))) {
		return nil;
	}
	return ((Message*)JB_Tree_FlatNext0(self));
	return nil;
}

__lib__ Message* jb_msg_flatafter(Message* self) {
	if ((!JB_Obj_NilCheck(self))) {
		return nil;
	}
	return ((Message*)JB_Tree_FlatAfter(self));
	return nil;
}

__lib__ Message* jb_msg_root(Message* self) {
	if ((!JB_Obj_NilCheck(self))) {
		return nil;
	}
	return ((Message*)JB_Tree_Root(self));
	return nil;
}

__lib__ void jb_msg_remove(Message* self) {
	if ((!JB_Obj_NilCheck(self))) {
		return;
	}
	JB_Tree_Remove(self);
}

__lib__ JB_String* jb_msg_render(Message* self) {
	if ((!JB_Obj_NilCheck(self))) {
		return nil;
	}
	return JB_Msg_Render(self, nil);
	return JB_str_0;
}

__lib__ JB_String* jb_msg_renderreadable(Message* self) {
	if ((!JB_Obj_NilCheck(self))) {
		return nil;
	}
	return JB_Msg_MakeReadable(self, nil);
	return JB_str_0;
}

__lib__ Message* jb_msg_convertreadable(Message* self) {
	return JB_Msg_ParseReadable(self);
	return nil;
}

__lib__ Message* jb_msg_copy(Message* self) {
	if ((!JB_Obj_NilCheck(self))) {
		return nil;
	}
	return JB_Msg_Copy(self, false);
	return nil;
}

__lib__ Message* jb_msg_create(Message* self, Syntax* Type, JB_String* Name) {
	if ((!JB_Obj_NilCheck(Type))) {
		return nil;
	}
	return JB_Fn_MsgParent(Type, self, Name);
	return nil;
}

__lib__ void jb_msg_error(Message* self, JB_String* ErrorMsg) {
	if ((!JB_Obj_NilCheck(self))) {
		return;
	}
	JB_Rec_NewItemWithNode(JB_StdErr, self, ErrorMsg);
}

__lib__ Message* jb_msg_expect(Message* self, Syntax* Type, JB_String* name, Message* ErrPlace) {
	if (self) {
		if ((self->Type == Type) and ((!JB_Str_Exists(name)) or ((JB_Str_SyntaxEquals(self->Name, name, true))))) {
			return self;
		}
		FastString* fs = JB_FS__New();
		JB_Incr(fs);
		JB_FS_AppendString(fs, JB_str_64);
		JB_FS_AppendString(fs, Type->LongName);
		JB_FS_MsgErrorName(fs, name);
		JB_FS_AppendString(fs, JB_str_172);
		JB_FS_AppendString(fs, self->Type->LongName);
		JB_FS_MsgErrorName(fs, self->Name);
		if ((!false)) {
			JB_String* _tmp336 = JB_FS_SyntaxCastString(fs);
			JB_Incr(_tmp336);
			JB_Msg_Fail(self, _tmp336);
			JB_Decr(_tmp336);
		}
		JB_Decr(fs);
	} else if ((bool)ErrPlace) {
		JB_Msg_AccessErr(ErrPlace, Type, name);
	}
	return nil;
}

__lib__ Message* jb_msg_access(Message* self, Syntax* Type, JB_String* name, bool IsError) {
	return JB_Msg_AccessSyxName(self, Type, name, IsError);
}

__lib__ JB_String* jb_syx_name(Syntax* self) {
	if ((!JB_Obj_NilCheck(self))) {
		return nil;
	}
	return self->Name;
	return JB_str_0;
}

__lib__ JB_String* jb_syx_longname(Syntax* self) {
	if ((!JB_Obj_NilCheck(self))) {
		return nil;
	}
	return self->LongName;
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

__lib__ s64 jb_string_int(JB_String* self, Message* m) {
	return JB_Str_TextIntegerValid(self, m);
	return 0;
}

__lib__ Syntax* jb_syntax(JB_String* name) {
	return ((Syntax*)JB_Dict_Value(JB_SyxDict, name));
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
	JB_DebugPrint(o);
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
	return 2019051415;
}

__lib__ JB_String* jb_readfile(_cstring path, bool AllowMissingFile) {
	JB_API__Init(0);
	return JB_cPath_ReadAll(path, AllowMissingFile, 100000000);
	return JB_str_0;
}

#pragma GCC visibility pop
//// API END! ////

}
