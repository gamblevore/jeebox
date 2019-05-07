
// Copyright, Theodore H. Smith 2019.
// Released under jeebox-licence http://jeebox.org/licence.txt

/*
	Copyright (C) 2005 Theodore H. Smith.
*/


/*
    A tree good for fast insert, append, remove and with no cyclical refcounting.

    No RingTree can be moved into it's own desendant or itself.

    I do things a bit lopsided, but it works out for the best!
    LastChild.next = 0, apart from that it's a plain double-ring.
*/


#include "JB_Umbrella.h"


extern "C" {

static void RingLeave_( RingTree* rt );
static void Move_( RingTree* a, RingTree* b, bool After );


inline bool RingIsRoot_( RingTree* rt ) {
	if ( !rt->Parent ) {
		dbgexpect2( !rt->Prev );
		dbgexpect2( !rt->Next );
		return true;
	}
	return false;
}

#define Sanity_(s)
#ifndef Sanity_

static void AncestorSanity_(RingTree* Curr) {
    // not parent of myself
    RingTree* Parent = Curr->Parent;
    while (Parent) {
        if (Curr == Parent) {
            debugger;
        }
        Parent = Parent->Parent;
    }
}

static void AmContainedSanity_(RingTree* Curr) {
    // find self in parent
    RingTree* Parent = Curr->Parent;
    if (!Parent) {
        return;
    }

    bool Found = false;
    RingTree* Ch = Parent->Child;
    while (Ch) {
        if (Ch == Curr) {
            Found = true;
        }
        Ch = Ch->Next;
        if (!Ch) {
            break;
        }

        RingTree* Prev = Ch->Prev;
        if (Prev->Next != Ch) {
            debugger;
        }
    }

    if (!Found) {
        debugger; // not found
    }
}

static void Sanity_(RingTree* Curr) {
    if (!Curr) {
        return;
    }

    
    AncestorSanity_( Curr );
    AmContainedSanity_( Curr );
}


static RingTree* LastSanity = 0;
void JB_Tree_TotalSanity(RingTree* Root) {
    if (!Root) {
        Root = LastSanity;
        if (!Root) {
            return;
        }
    } else {
        LastSanity = Root;
    }
    
    RingTree* After = JB_Tree_FlatAfter(Root);
    RingTree* Curr = Root;
    while (Curr != After) {
        AmContainedSanity_(Curr);
        Curr = JB_Tree_FlatNext0(Curr);
    }
}
#endif

inline void RingOwnForDeref_( RingTree* Curr ) {
//	if ( JB_RefCount(Curr) > 1 ) { // ownerify it
    Curr->Next = 0;
    Curr->Parent = 0;
    Curr->Prev = 0;
//	}
}

static bool RingIsAncestor_( RingTree* child, RingTree* ance ) {
#if DEBUG || AS_LIBRARY // important!
	RingTree* p = child->Parent;
	while ( p ) {
		if ( p == ance ) {
			return true;
		}

		p = p->Parent;
	}
#endif

	return false;   
}



inline bool PrepareMove_( RingTree* place, RingTree* mover ) {
    if (!mover) {
        return false;
    }
    
	if ( place != mover ) {
        if ( mover->Child and RingIsAncestor_( place, mover ) ) {
            ; //
        } else {
            if ( mover->Parent ) {
                RingLeave_( mover );
            } else {
                JB_Incr( mover );
            }
            return true;
        }
    }

    JB_ErrorHandleC("Error: moved a RingTree node to the wrong place", false);

    return false;
}

static bool Remove_( RingTree* self ) {
	Sanity_(self);
	if ( self->Parent ) {
		RingLeave_( self );
		RingOwnForDeref_( self );
		Sanity_(self);
		JB_Decr( self );
		return true;
	}

	return false;
}


bool JB_Tree_HasChildren( RingTree* self ) {
    return self->Child;
}

int JB_Tree_Count( RingTree* self ) {
	Sanity_( self );
	RingTree* c = self->Child;
	
    int N = 0;
	while ( c ) {
		c = c->Next;
        N++;
	}
	
	return N;
}

bool JB_Tree_HasChildCount( RingTree* self, int HasCount ) {
//    JB_Tree_Count(0); // stop compiler removing it
	Sanity_( self );
	RingTree* c = self->Child;
	
	while ( HasCount-- >= 1 ) {
		if ( !c ) {
			return false;
		}
		c = c->Next;
	}
	
	return ( !c );
}

RingTree* JB_Tree_Last( RingTree* self ) {
	RingTree* c = self->Child;

	if ( c ) {
		return c->Prev;
	}
	return 0;
}

RingTree* JB_Tree_NextSib( RingTree* self ) {
	Sanity_( self );
	return self->Next;
}

RingTree* JB_Tree_PrevSib( RingTree* self ) {
	Sanity_( self );
	RingTree* Prev = self->Prev;
	
	if (Prev and Prev->Next) { // the last one has no next!
		return Prev;
	}
	
	return 0;
}

RingTree* JB_Tree_First( RingTree* self ) {
	return self->Child;
}

RingTree* JB_Tree_Parent( RingTree* self ) {
	return self->Parent;
}

RingTree* JB_Tree_Root( RingTree* self ) {
	Sanity_(self);
	RingTree* p = self->Parent;
	
	while ( p ) {
		self = p;
		p = self->Parent;
	}
	
	return self;
}


bool JB_Tree_IsRoot( RingTree* self ) {
	Sanity_( self );
	return ( !self->Parent );
}



static void RingLeave_( RingTree* rt ) {
    Sanity_(rt);
	dbgexpect( rt );
	dbgexpect( !RingIsRoot_( rt ) ); // 
	RingTree* n = rt->Next;
	RingTree* p = rt->Prev;
	RingTree* Parent = rt->Parent;
	dbgexpect( p );
	dbgexpect( Parent );

	if (p == rt) { // we are the only ones in our parent!
		Parent->Child = 0;
	} else if (!n) { // we are removing the last.
        p->Next = 0;
		Parent->Child->Prev = p;
	} else if (Parent == rt) { // root, unroot us.
		// rt->Parent = 0; // done below.
	} else {
		n->Prev = p;
		p->Next = n;
		if (Parent->Child == rt) {
			Parent->Child = n;
			p->Next = 0;
		}
	}

    rt->Parent = 0;
    Sanity_(rt);
	dbgexpect( Parent->Child != rt );
}


inline void Insert_( RingTree* pl, RingTree* rt, bool After ) {
	dbgexpect( rt );
	dbgexpect( pl );
	RingTree* Parent = pl->Parent;
	dbgexpect( Parent );

	if ( ! After ) {
		RingTree* Prev = pl->Prev;
		if ( Parent->Child == pl ) {
			Parent->Child = rt; // put ourselves first!
		} else {
			Prev->Next = rt;
		}
		pl->Prev = rt;

		rt->Prev = Prev;
		rt->Next = pl;
	} else {
		RingTree* Next = pl->Next;

		rt->Next = Next;
		rt->Prev = pl;

		pl->Next = rt;
		if (Next) {
			Next->Prev = rt;
		} else {
			Parent->Child->Prev = rt;
		}
	}

	rt->Parent = Parent;
}

// very cool
RingTree* JB_Tree_FlatNext0( RingTree* self ) {
	return JB_Tree_FlatNext( self, true ).Node;
}


DepthNode JB_Tree_FlatNext( RingTree* self, bool AllowDown ) {
	Sanity_( self );
	
	RingTree* c = self->Child;
	RingTree* up = self->Parent;
	int Depth = 0;

	if (AllowDown and c) {
		if (up != self) { // owner!
			Depth++;
		}
		return {c, Depth};
	}

	while (up != self  and  up) {
		RingTree* n = self->Next;

		if ( n ) {
			return {n, Depth};
		}

		// we want to go up!
		Depth--;
		self = up;
		up = self->Parent;
	}

	return {0, 0};
}


RingTree* JB_Tree_FlatAfter( RingTree* self ) {
	return JB_Tree_FlatNext( self, false ).Node;
}



static void Move_( RingTree* Place, RingTree* Mover, bool After ) {
    Sanity_( Place );
    if ( Place->Parent and PrepareMove_( Place, Mover ) ) {
        Sanity_( Mover );
        Insert_( Place, Mover, After );
        Sanity_( Mover );
        Sanity_( Place );
    }
}


void JB_Tree_ParentSet( RingTree* self, RingTree* NewParent ) {
	if (NewParent) {
		JB_Tree_LastSet( NewParent, self );
	} else {
		Remove_( self );
	}
}
 // 

void JB_Tree_NextSibSet( RingTree* self, RingTree* Mover ) {
	Move_( self, Mover, true );
}


void JB_Tree_PrevSibSet( RingTree* self, RingTree* Mover ) {
	Move_( self, Mover, false );
}


void JB_Tree_LastSet( RingTree* self, RingTree* New ) {
	Sanity_( self );
	Sanity_( New );
	if ( !PrepareMove_( self, New ) ) {
        return;
    }

	New->Parent = self;
	RingTree* c = self->Child;

	if ( !c ) {
		self->Child = New;
		New->Next = 0;
		New->Prev = New;
	} else {
		RingTree* Last = c->Prev;

		c->Prev = New;

		New->Next = 0;
		New->Prev = Last;

		Last->Next = New;
	}
	Sanity_( self );
	Sanity_( New );
}



void JB_Tree_FirstSet( RingTree* self, RingTree* Mover ) {
	if ( Mover ) {
        RingTree* First = JB_Tree_First( self );
        if ( First ) {
            JB_Tree_PrevSibSet( First, Mover );
        } else {
            JB_Tree_LastSet( self, Mover );
        }
    }
}


void JB_Tree_Constructor0( RingTree* self ) {
    self->Parent = 0;
    self->Next = 0;
    self->Prev = 0;
    self->Child = 0;
}
    
    
void JB_Tree_Constructor( RingTree* self, RingTree* Parent ) {
    self->Next = 0;
    self->Child = 0;
    self->Parent = Parent;
    if (!Parent) {
        self->Prev = 0;
        return;
    }

    Sanity_(Parent);
	RingTree* First = Parent->Child;

    JB_Incr( self );
	
    if ( First ) {
        RingTree* Last = First->Prev;
        First->Prev = self;
        Last->Next = self;
        self->Prev = Last;
    } else {
		Parent->Child = self;
		self->Prev = self;
    }
    Sanity_(self);
    Sanity_(Parent);
}
    

void JB_Tree_Dispose( RingTree* self ) {
	int Ref = JB_RefCount(self); // we want this BEFORE we decr ourself!

	if ( RingIsRoot_( self ) or (Remove_( self ) and Ref > 1) ) { // now we are the owner!
		JB_Tree_Destructor( self );
        JB_Tree_Constructor0(self);
		Sanity_(self);
	}
}


void JB_Tree_Destructor( RingTree* self ) {
    dbgexpect(!self->Parent);
	RingTree* Curr = self->Child;

	while (Curr) {
		RingTree* Next = Curr->Next;
		RingOwnForDeref_( Curr );
		JB_Decr( Curr );

		Curr = Next;
	};
}

} // 

