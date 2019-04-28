
// By Theodore H. Smith, released under zlib licence v1.2.11
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


/*
	Copyright (C) 2005 Theodore H. Smith.
	<jeebox.org>
*/




#include "JB_Umbrella.h"
#include <stdio.h>


extern "C" {

// Split off cos having a 10000 line file isn't so cool. However, it
// is designed to be compiled as one file.

    #include "StringCore.i"
    #include "StringConvert.i"
    #include "StringCS.i"
    #include "StringSearchers.i"
    #include "StringAlterCopy.i"
    #include "StringSplitters.i"
    #include "StringEncoding.i"
    #include "StringProperties.i"
    #include "StringVerify.i"
    #include "StringGlobals.i"
    #include "StringRender.i"

} // 


