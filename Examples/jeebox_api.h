
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


        // API


extern "C" {

		// Types

typedef const char* _cstring;
typedef void* _voidptr;
#ifndef u8
    typedef unsigned char  u8; 
#endif
#ifndef int64
    typedef long long  int64; 
#endif
#ifndef uint64
    typedef unsigned long long  uint64; 
#endif

struct jbobject {int RefCount;};
struct jbmessage : jbobject {};
typedef u8 jbsyntax;
struct jbstring : jbobject {};


		// Message functions

jbstring* jb_msg_name(jbmessage* self); /* The name of the node! */
jbsyntax jb_msg_func(jbmessage* self); /* The node's syntactic-type. For example parsing "{}" would give a node of type 'arg', but parsing "()" would give a node of type 'list'. */
int jb_msg_position(jbmessage* self); /* The byte-position of the original syntax that created this node. Useful for error-reporting. */
_voidptr jb_msg_tag(jbmessage* self); /* Attached user-defined value. */
void jb_msg_nameset(jbmessage* self, jbstring* Result); /* Sets the name. */
void jb_msg_funcset(jbmessage* self, jbsyntax Result); /* Sets the syntactic type */
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
jbstring* jb_msg_ast(jbmessage* self); /* Renders the structure of the tree in a human-readable format. Useful to understand the parse-tree. This gives you an idea of how to move across the tree using jb_msg_child/prev/parent/etc! */
jbmessage* jb_msg_parseast(jbmessage* self); /* Takes the output of jb_msg_ast and converts it back into a proper Jeebox tree. Used like this: tree = jb_msg_parseast(jb_str_parse(str)). */
jbmessage* jb_msg_copy(jbmessage* self); /* Copies the node's entire tree structure, positions, names and all. */
jbmessage* jb_msg_create(jbmessage* self, jbsyntax Type, jbstring* Name); /* Creates a new node with the type and name provided.
    
The node is created as the last child of 'self'. If 'self' is nil... the node is created with no parent (this is fine). */
void jb_msg_error(jbmessage* self, jbstring* ErrorMsg); /* Lets you add your own error messages to the tree. */
jbmessage* jb_msg_expect(jbmessage* self, jbsyntax Type, jbstring* name, jbmessage* ErrPlace); /* Test the name and type, (or existance) of a message node. */
jbmessage* jb_msg_access(jbmessage* self, jbsyntax Type, jbstring* name, bool IsError);


		// Syntax functions

jbstring* jb_syx_name(jbsyntax self); /* The syntax's short-name, for example "a=b" would return "rel". */
jbstring* jb_syx_longname(jbsyntax self); /* The syntax's human-readable name, for example "a=b" would return "relationship". */


		// String functions

_cstring jb_string_address(jbstring* self);
int jb_string_length(jbstring* self); /* String length, in bytes. A nil-string is acceptable and gives 0 length. */
jbstring* jb_string_copy(jbstring* self); /* Copies the string into a new string, which you can modify the contents as you like, before passing it to anything else. (Strings are meant to be "immutable" (their content doesn't change), but it's OK to modify it right after copying. */
jbmessage* jb_string_parse(jbstring* self, jbstring* path); /* Parses the string into a tree! Parsing is the most important function in Jeebox! Returns nil if invalid jeebox code is detected. You must call jb_errors to detect that parse-error or else you can’t parse more jeebox code.

The optional path is not used for anything except generating better error messages, but good error-messages are quite important! */
jbstring* jb_string_escape(jbstring* self); /* Turns a string like "${}" into a string like "\${}". To make it safe to be parsed b Jeebox. */
void jb_string_print(jbstring* self); /* Prints this string to console. Useful for debugging. */
void jb_string_printline(jbstring* self); /* Same as jb_string_print except it ends with a \n. */
int64 jb_string_int(jbstring* self, jbmessage* m); /* Parses this string into an integer. Allows hex also, like '0xffff'. If you pass a 'message' into this, then invalid strings will get reported into jb_errors()  */
double jb_string_float(jbstring* self, jbmessage* m); /* Parses this string into a double-precision float. If you pass a 'message' into this, then invalid strings will get reported into jb_errors()  */


		// Global functions

jbsyntax jb_syntax(jbstring* name); /* Looks up the syntax of that name from the syntax-table. The name must be lower-case and in short-form, like "arg" not "Arg" or "argument". (The list of short-form names is in api.h, you will see $arg, $acc... its those minus the $.) */
jbstring* jb_str(_cstring Str, int Length, _voidptr Release, _voidptr Tag); /* Creates a JBString from a c-string. Expects the c-string to remain unchanged until the JBString is freed. Length is optional. Can optionally pass a call-back to release your c-string, during freeing the JBString. */
jbstring* jb_cstr(_cstring Str); /* Creates a JBString from a c-string. Expects the c-string to remain unchanged until the JBString is freed. */
void jb_delete_(jbobject* obj); /* Deletes the object from memory. Don't call directly, use jb_incr jb_decr. */
jbmessage* jb_errors(); /* Returns a list of errors as children of the returned node. Also clears the error-list. Each child's name is the error-description and each child's position is the error-position. */
bool jb_ok(); /* Returns if any errors were detected. Doesn't change anything. Call jb_errors to actually get the error-list and remove them. */
void jb_debug(jbobject* o); /* Prints a description of this object, useful for debugging. */
int jb_init(int Flags); /* Inits Jeebox. Call this before any other Jeebox functions. Pass 1 to succeed silently, or else a message is printed. Returns zero for success.
    
If jb_init fails it will try print a debug message. If jb_init returns 0x10000 that means an out-of-memory error occurred. You can free memory and try again. */
int jb_shutdown(); /* Frees all memory used by jeebox! */
int jb_version();
jbstring* jb_readfile(_cstring path, bool AllowMissingFile); /* Reads entire file at this path. Relative paths are allowed. Will create jeebox-errors if the file can’t be read for any reason (missing file, out of memory, disk-error, etc).
    
    If AllowMissingFile is true then it's OK for the file to not exist, no error is created in that case. This helps make your code is a bit less pedantic. */


		// Jeebox Syntax

#define JB_SyxArg 1;
#define $arg 1
#define JB_SyxAcc 2;
#define $acc 2
#define JB_SyxAdj 3;
#define $adj 3
#define JB_SyxARel 4;
#define $arel 4
#define JB_SyxArr 5;
#define $arr 5
#define JB_SyxBack 6;
#define $back 6
#define JB_SyxSStr 7;
#define $sstr 7
#define JB_SyxBra 8;
#define $bra 8
#define JB_SyxBRel 9;
#define $brel 9
#define JB_SyxChar 10;
#define $char 10
#define JB_SyxDecl 11;
#define $decl 11
#define JB_SyxDot 12;
#define $dot 12
#define JB_SyxEmb 13;
#define $emb 13
#define JB_SyxERel 14;
#define $erel 14
#define JB_SyxFunc 15;
#define $func 15
#define JB_SyxItem 16;
#define $item 16
#define JB_SyxList 17;
#define $list 17
#define JB_SyxName 18;
#define $name 18
#define JB_SyxNum 19;
#define $num 19
#define JB_SyxUnit 20;
#define $unit 20
#define JB_SyxOat 21;
#define $oat 21
#define JB_SyxOpp 22;
#define $opp 22
#define JB_SyxSOpp 23;
#define $sopp 23
#define JB_SyxRel 24;
#define $rel 24
#define JB_SyxTRel 25;
#define $trel 25
#define JB_SyxSDot 26;
#define $sdot 26
#define JB_SyxSCom 27;
#define $scom 27
#define JB_SyxSheb 28;
#define $sheb 28
#define JB_SyxStr 29;
#define $str 29
#define JB_SyxSThg 30;
#define $sthg 30
#define JB_SyxThg 31;
#define $thg 31
#define JB_SyxTmp 32;
#define $tmp 32
#define JB_SyxAna 33;
#define $ana 33
#define JB_SyxSCnj 34;
#define $scnj 34
#define JB_SyxCnj 35;
#define $cnj 35
#define JB_SyxType 36;
#define $type 36
#define JB_SyxBin 37;
#define $bin 37


#ifdef __nodebug
    #undef __nodebug
#endif
#if defined(__linux__)
#define __nodebug inline __attribute__((__always_inline__)) // __nodebug__ doesn't exist on linux?
#else
#define __nodebug inline __attribute__((__always_inline__, __nodebug__))
#endif
__nodebug void jb_incr(jbobject* s) {
    if (s) {s->RefCount++;}
}

__nodebug void jb_decr(jbobject* s) {
    if (s) { if (--s->RefCount <= 0) {jb_delete_(s);} }
}

} // end-extern
