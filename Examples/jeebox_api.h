
/***LICENCE-TEXT***
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
        are required to acknowledge this in one of:
        About-window / launch-screen / help-files / read-me-file
    3. Altered source versions must be plainly marked as such, and must not be
        misrepresented as being the original software.
    4. This notice may not be removed or altered from any source distribution.
*/


		// API

extern "C" {

		// Types
struct jbobject {int RefCount;};
struct jbmessage : jbobject {};
struct jbsyntax : jbobject {};
struct jbstring : jbobject {};

typedef const char* _cstring;
typedef void* _voidptr;


		// Message functions

jbstring* jb_msg_name(jbmessage* self); /* The name of the node! */
jbsyntax* jb_msg_type(jbmessage* self); /* The node's syntactic-type. For example parsing "{}" would give a node of type 'arg', but parsing "()" would give a node of type 'list'. */
int jb_msg_position(jbmessage* self); /* The byte-position of the original syntax that created this node. Useful for error-reporting. */
_voidptr jb_msg_tag(jbmessage* self); /* Attached user-defined value. */
void jb_msg_nameset(jbmessage* self, jbstring* Result); /* Sets the name. */
void jb_msg_typeset(jbmessage* self, jbsyntax* Result); /* Sets the syntactic type */
void jb_msg_positionset(jbmessage* self, int Result); /* Sets the byte-position. Jeebox doesn't use this value other than to store it for you. You might want to set the position if you created some nodes yourself via jb_msg_create. Obviously those nodes wouldn't have a position. */
void jb_msg_tagset(jbmessage* self, _voidptr Result); /* In case you want to attach a user-defined value to the node, to use for your own purposes. */
void jb_msg_firstset(jbmessage* self, jbmessage* Result); /* Inserts 'Result' as the first child, and safely-removes it from it's old tree. You don't need to do anything to keep the next/prev/parent/etc values correct! They are updated for you. Same for all tree-node setters: jb_msg_lastset, jb_msg_prevset, jb_msg_nextset */
void jb_msg_lastset(jbmessage* self, jbmessage* Result); /* Same as jb_msg_firstset. Inserts 'Result' as the last child. */
void jb_msg_prevset(jbmessage* self, jbmessage* Result); /* Same as jb_msg_firstset. Inserts 'Result' as our prev-sibling. Does nothing if 'self' has no parent. */
void jb_msg_nextset(jbmessage* self, jbmessage* Result); /* Same as jb_msg_firstset. Inserts 'Result' as our next-sibling. Does nothing if 'self' has no parent. */
jbmessage* jb_msg_first(jbmessage* self); /* Gets the first child of this node, if it exists. */
jbmessage* jb_msg_last(jbmessage* self); /* Gets the last child of this node, if it exists. */
jbmessage* jb_msg_prev(jbmessage* self); /* Gets the previous-sibling, if it exists. */
jbmessage* jb_msg_next(jbmessage* self); /* Gets the next-sibling, if it exists. */
jbmessage* jb_msg_parent(jbmessage* self); /* Gets the parent of this node, if it exists. */
jbmessage* jb_msg_flatnext(jbmessage* self); /* Lists over the tree as if it were one-dimensional! A kind of 'stateless-tree-traversal'! */
jbmessage* jb_msg_flatafter(jbmessage* self); /* If you want to loop over all the nested-children (descendants) of one node, but that node is contained in a tree (it's not the root), you'll need to call this function first. Returned node is the 'end-marker'. Once you reach it, you stop. Example:
    Message* SearchMe = TheMsgYouWantToSearch();
    Message* LoopEnd = jb_msg_flatafter(SearchMe);
    for (Message* LoopCurr = SearchMe;  LoopCurr!=LoopEnd;  LoopCurr = jb_msg_flatnext(LoopCurr)) {
        DoSomethingTo(LoopCurr); // every descendant of SearchMe comes here!
    }
 */
jbmessage* jb_msg_root(jbmessage* self); /* Finds the top-most parent. */
void jb_msg_remove(jbmessage* self); /* Removes the node from the tree. */
jbstring* jb_msg_render(jbmessage* self); /* Renders the tree as a string! */
jbstring* jb_msg_renderreadable(jbmessage* self); /* Renders the structure of the tree in a human-readable format. It's a bit like XML, except it's still Jeebox. Basically useful when you want to get an idea of what the parse-tree contains, and how it's structured. This gives you an idea of how to move across the tree using jb_msg_child/prev/parent/etc and what to look for and what to expect! */
jbmessage* jb_msg_convertreadable(jbmessage* self); /* Takes the output of jb_msg_render_readable and converts it back into a proper Jeebox tree. You'll have to parse the string first though. So you convert a (readable) string to a (readable) tree, and then convert it into a proper (jeebox) tree. */
jbmessage* jb_msg_copy(jbmessage* self); /* Copies the node's entire tree structure, positions, names and all. */
jbmessage* jb_msg_create(jbmessage* self, jbsyntax* Type, jbstring* Name); /* Creates a new node with the type and name provided.
    
The node is created as the last child of 'self'. If 'self' is nil... the node is created with no parent (this is fine). */


		// Syntax functions

jbstring* jb_syx_name(jbsyntax* self); /* The syntax's short-name, for example "a=b" would return "rel". */
jbstring* jb_syx_longname(jbsyntax* self); /* The syntax's human-readable name, for example "a=b" would return "relationship". */


		// String functions

_cstring jb_string_address(jbstring* self);
int jb_string_length(jbstring* self); /* String length, in bytes. A nil-string is acceptable and gives 0 length. */
jbstring* jb_string_copy(jbstring* self); /* Copies the string into a new string, which you can modify the contents as you like, before passing it to anything else. (Strings are meant to be "immutable" (their content doesn't change), but it's OK to modify it right after copying. */
jbmessage* jb_string_parse(jbstring* self); /* Parses the string into a tree! Parsing is the most important function in Jeebox! Returns nil if invalid jeebox code is detected. You must call jb_errors to detect that parse-error or else you can't parse more jeebox code. */
void jb_string_print(jbstring* self); /* Prints this string to console. Useful for debugging. */
void jb_string_printline(jbstring* self); /* Same as jb_string_print except it ends with a \n. */


		// Global functions

jbsyntax* jb_syntax(jbstring* name); /* Looks up the syntax of that name from the syntax-table. The name must be lower-case and in short-form, like "arg" not "Arg" or "argument". (The list of short-form names is in api.h, you will see $arg, $acc... its those minus the $.) */
jbstring* jb_str(_cstring Str, int Length, _voidptr Release, _voidptr Tag); /* Creates a JBString from a c-string. Expects the c-string to remain unchanged until the JBString is freed. Length is optional. Can optionally pass a call-back to release your c-string, during freeing the JBString. */
void jb_delete_(jbobject* obj); /* Deletes the object from memory. Don't call directly, use jb_incr jb_decr. */
jbmessage* jb_errors(); /* Returns the first parse-error (if any), and removes it from error-list. The node's name is the error-description and the node's position is the error-position. */
int jb_init(int Flags); /* Inits Jeebox. Call this before any other Jeebox functions. Pass 1 to succeed silently, or else a message is printed. Returns zero for success.
    
If jb_init fails it will try print a debug message. If jb_init returns 0x10000 that means an out-of-memory error occurred. You can free memory and try again. */
int jb_shutdown(); /* Frees all memory used by jeebox! */
int jb_version();
jbstring* jb_readfile(_cstring path, bool AllowMissingFile); /* Reads entire file at this path. Relative paths are allowed. Will create jeebox-errors if the file can't be read for any reason (missing file, out of memory, disk-error, etc).
    
    If AllowMissingFile is true then it's OK for the file to not exist, no error is created in that case. This helps make your code is a bit less pedantic. */


		// Jeebox Syntax

extern jbsyntax* JB_SyxArg;
extern jbsyntax* JB_SyxAcc;
extern jbsyntax* JB_SyxAdj;
extern jbsyntax* JB_SyxARel;
extern jbsyntax* JB_SyxArr;
extern jbsyntax* JB_SyxBack;
extern jbsyntax* JB_SyxSStr;
extern jbsyntax* JB_SyxBra;
extern jbsyntax* JB_SyxBRel;
extern jbsyntax* JB_SyxChar;
extern jbsyntax* JB_SyxDecl;
extern jbsyntax* JB_SyxDot;
extern jbsyntax* JB_SyxEmb;
extern jbsyntax* JB_SyxERel;
extern jbsyntax* JB_SyxFunc;
extern jbsyntax* JB_SyxItem;
extern jbsyntax* JB_SyxList;
extern jbsyntax* JB_SyxPrm;
extern jbsyntax* JB_SyxName;
extern jbsyntax* JB_SyxNum;
extern jbsyntax* JB_SyxOat;
extern jbsyntax* JB_SyxOpp;
extern jbsyntax* JB_SyxSOpp;
extern jbsyntax* JB_SyxRel;
extern jbsyntax* JB_SyxTRel;
extern jbsyntax* JB_SyxSDot;
extern jbsyntax* JB_SyxSCom;
extern jbsyntax* JB_SyxSheb;
extern jbsyntax* JB_SyxStr;
extern jbsyntax* JB_SyxSThg;
extern jbsyntax* JB_SyxThg;
extern jbsyntax* JB_SyxChn;
extern jbsyntax* JB_SyxTmp;
extern jbsyntax* JB_SyxAna;
extern jbsyntax* JB_SyxSCnj;
extern jbsyntax* JB_SyxCnj;
extern jbsyntax* JB_SyxType;
extern jbsyntax* JB_SyxUnit;
extern jbsyntax* JB_SyxBin;

#define $arg JB_SyxArg        // Argument
#define $acc JB_SyxAcc        // Access
#define $adj JB_SyxAdj        // Adjective
#define $arel JB_SyxARel      // After_Relationship
#define $arr JB_SyxArr        // Array
#define $back JB_SyxBack      // Backtick
#define $sstr JB_SyxSStr      // Super_String
#define $bra JB_SyxBra        // Bracket
#define $brel JB_SyxBRel      // Before_Relationship
#define $char JB_SyxChar      // Character
#define $decl JB_SyxDecl      // Declaration
#define $dot JB_SyxDot        // Dot
#define $emb JB_SyxEmb        // Embedded_Value
#define $erel JB_SyxERel      // Equals_Relationship
#define $func JB_SyxFunc      // Function
#define $item JB_SyxItem      // item
#define $list JB_SyxList      // list
#define $prm JB_SyxPrm        // Parameters
#define $name JB_SyxName      // name
#define $num JB_SyxNum        // Number
#define $oat JB_SyxOat        // Operator_As_Thing
#define $opp JB_SyxOpp        // Operator
#define $sopp JB_SyxSOpp      // Syntactic_Operator
#define $rel JB_SyxRel        // Relationship
#define $trel JB_SyxTRel      // Temporal_Relationship
#define $sdot JB_SyxSDot      // Self_Dot
#define $scom JB_SyxSCom      // Syntactic_Comment
#define $sheb JB_SyxSheb      // Shebang
#define $str JB_SyxStr        // String
#define $sthg JB_SyxSThg      // Syntactic_Thing
#define $thg JB_SyxThg        // Thing
#define $chn JB_SyxChn        // Temporal_Chain
#define $tmp JB_SyxTmp        // Temporal_Statement
#define $ana JB_SyxAna        // Temporal_Reference
#define $scnj JB_SyxSCnj      // Syntactic_Conjugate
#define $cnj JB_SyxCnj        // Conjugate
#define $type JB_SyxType      // Typecast
#define $unit JB_SyxUnit      // unit
#define $bin JB_SyxBin        // Binary


#ifdef __nodebug
    #undef __nodebug
#endif
#define __nodebug inline __attribute__((__always_inline__, __nodebug__))
__nodebug void jb_incr(jbobject* s) {
    if (s) {s->RefCount++;}
}

__nodebug void jb_decr(jbobject* s) {
    if (s) { if (--s->RefCount <= 0) {jb_delete_(s);} }
}
} //end-extern
