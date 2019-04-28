
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


#ifndef AS_LIBRARY

#include "JB_Umbrella.h"
#include "JB_DirReaderUnix.h"

extern "C" {

#if TrackDirsOn	
	bool TrackDirs = false;
#endif
	
inline bool IgnoreDotDot( u8* c ) {
	if ( c[0] != '.' ) {
		return false;
	}

	char c1 = c[ 1 ];
	if ( c1 == 0 ) {
		return true;
	}

	return (c1 == '.' and c[2] == 0);
}

dirent* ReadDir_( DirReader* D ) {
// assumes we are in the current directory that this is being read from!!
// assumes DRR is a real pointer to an opendir.
	dirent* Child;
    const char* ChildName;
	DIR* DR = *D;
    if (!DR) {
        return 0;
    }

	do {
		Child = trreaddir( DR );
		if ( ! Child ) return 0;

		ChildName = Child->d_name;
	} while ( IgnoreDotDot( (u8*)ChildName ) );

    return Child;
}
	
}



#endif
