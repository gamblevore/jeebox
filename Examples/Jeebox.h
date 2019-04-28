
// Jeebox, by Theodore H. Smith, released under zlib licence v1.2.11

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

    // C++ version of Jeebox!
        // Use this instead of jeebox_api.h if possible.

    // Automated RefCounting!:
        // Does away with manual refcounting! VERY error-prone.
        // It's a very bad experience trying to manual refcount!


#include "jeebox_api.h"
#include <stdlib.h>


//#undef __nodebug
//#define __nodebug 
namespace Jeebox {


class String;
class Message;
class Syntax;
class MessageIterator;


#if __x86_64__ || __ppc64__ || _WIN64 
    #error 64-bit Jeebox not supported yet.
#endif


class Syntax {
// no need refcount. they always exist and are never destroyed.
public:
    jbsyntax* _self;
    __nodebug operator bool() const { return _self; }
    __nodebug Syntax (jbsyntax* s) { _self = s; }


    __nodebug bool operator==(const jbsyntax* other) {
      return _self == other;
    }
    __nodebug bool operator!=(const jbsyntax* other) {
      return _self != other;
    }

    __nodebug String name() const;
    __nodebug String longname() const;
};


class String {
public:
    jbstring* _self;
    __nodebug ~String () {jb_decr(_self);}
    __nodebug String (jbstring* s) {
        jb_incr(_self = s);
    }
    __nodebug String (const char* s) {
        jb_incr(_self = jb_str(s,0,0,0));
    }
    __nodebug String (const char* s, int n) {
        jb_incr(_self = jb_str(s,n,0,0));
    }
    __nodebug String (const String &s) {
        jb_incr(_self = s._self);
    }
    __nodebug String& operator = (const String &s) {
        jbstring* Old = _self;
        jb_incr(_self = s._self);
        jb_decr(Old);
        return *this;
    }
    
    __nodebug Message     parse () const;
    __nodebug void        print () const      {jb_string_print(_self);}
    __nodebug void        printline () const  {jb_string_printline(_self);}
    __nodebug const char* address ()const     {return jb_string_address(_self);}
    __nodebug int         length () const     {return jb_string_length(_self);}
    __nodebug String      copy () const       {return jb_string_copy(_self);}

    __nodebug operator bool() const           { return length(); }
};



class Message {
public:
    jbmessage* _self;
    __nodebug operator bool() const { return _self; }
    
    __nodebug ~Message () {
        jb_decr(_self);
    }
    __nodebug Message (jbmessage* s) {
        jb_incr(_self = s);
    }
    __nodebug Message (const Message &s) {
        jb_incr(_self = s._self);
    } 
    __nodebug Message& operator = (const Message &s) {
        jbmessage* Old = _self;
        jb_incr(_self = s._self);
        jb_decr(Old);
        return *this;
    }
/*    Message operator[] (int index) {
        if (index < 0) {
            return Message(0);
        }
        auto F = jb_msg_first(_self);
        while (F and index-- >= 1) {
            F = jb_msg_next(F);
        }
        return F;
    }
*/
    __nodebug MessageIterator begin () const; 
    __nodebug MessageIterator end () const;
    

    __nodebug Message create (const Syntax& X, const String& Name=(const char*)0) {
        return jb_msg_create(_self, X._self, Name._self);
    }

    __nodebug Syntax  syntax () const  {return jb_msg_syntax(_self);}
    __nodebug String  name () const    {return jb_msg_name(_self);}
    __nodebug int     position() const {return jb_msg_position(_self);}
    __nodebug void*   tag () const     {return jb_msg_tag(_self);}
    __nodebug Message first() const    {return jb_msg_first(_self);}
    __nodebug Message last() const     {return jb_msg_last(_self);}
    __nodebug Message prev() const     {return jb_msg_prev(_self);}
    __nodebug Message next() const     {return jb_msg_next(_self);}

    __nodebug Message parent() const   {return jb_msg_parent(_self);}
    __nodebug Message flatnext() const {return jb_msg_flatnext(_self);}
    __nodebug Message flatafter() const{return jb_msg_flatafter(_self);}
    __nodebug Message copy() const     {return jb_msg_copy(_self);}
    __nodebug String  render() const   {return jb_msg_render(_self);}
    __nodebug Message root() const     {return jb_msg_root(_self);}
__nodebug String  renderreadable()const {return jb_msg_renderreadable(_self);}
__nodebug Message convertreadable()const{return jb_msg_convertreadable(_self);}

    __nodebug void    remove()    {return jb_msg_remove(_self);}
    
    __nodebug void    syntax (const Syntax& s) {jb_msg_syntaxset(_self, s._self);}
    __nodebug void    name (const String& s)   {jb_msg_nameset(_self, s._self);}
    __nodebug void    position(int s)          {jb_msg_positionset(_self, s);}
    __nodebug void    tag (void* s)            {jb_msg_tagset(_self, s);}
    __nodebug void    first(const Message& s)  {jb_msg_firstset(_self, s._self);}
    __nodebug void    last(const Message& s)   {jb_msg_lastset(_self, s._self);}
    __nodebug void    prev(const Message& s)   {jb_msg_prevset(_self, s._self);}
    __nodebug void    next(const Message& s)   {jb_msg_nextset(_self, s._self);}
        
    __nodebug void    append(const Message& s)   {last(s);}
};





__nodebug Message String::parse () const {
    return jb_string_parse(_self);
}
__nodebug String Syntax::name() const {
    return jb_syx_name(_self);
}
__nodebug String Syntax::longname() const {
    return jb_syx_longname(_self);
}
__nodebug Message errors() {
    return jb_errors();
}
__nodebug Syntax syntax(const String& name) {
    return jb_syntax(name._self);
}




static void string_free(void* addr, void* Tag) {
    free(addr);
}

__nodebug String string_owned(const char* Addr, int n) {
    return jb_str(Addr, n, (void*)string_free, (void*)Addr);
}


__nodebug String string_copy(const char* Addr, int n) {
    return String(Addr,n).copy();
}



/// C++ iterators...
class MessageIterator {
public:
    __nodebug MessageIterator (jbmessage* M) {
        msg = M;
    }
 
    __nodebug bool operator != (const MessageIterator& other) const {
        return msg != other.msg;
    }
 
    __nodebug Message operator* () const {
        return msg;
    }
 
    __nodebug const MessageIterator& operator++ () {
        msg = jb_msg_next(msg);
        return *this;
    }
 
private:
    jbmessage* msg;
};


__nodebug MessageIterator Message::begin () const {
    return MessageIterator( jb_msg_first(_self) );
}

__nodebug MessageIterator Message::end () const {
    return MessageIterator( 0 );
}


}


