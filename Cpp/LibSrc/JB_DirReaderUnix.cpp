
// Copyright, Theodore H. Smith 2019.
// Released under jeebox-licence http://jeebox.org/licence.txt



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
