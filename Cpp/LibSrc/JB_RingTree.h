
/*
	Copyright (C) 2005 Theodore H. Smith.
*/


#ifndef __RINGTREE__
#define __RINGTREE__

#include "JB_String.h"


extern "C" {

JBClass( RingTree, Saveable,
	RingTree* Parent;
	RingTree* Prev;
	RingTree* Next;
	RingTree* Child;
);


struct DepthNode { RingTree* Node; int Depth; };


#define ksRing		"RingTree"

DepthNode JB_Tree_FlatNext( RingTree* self, bool AllowDown );
RingTree* JB_Tree_FlatNext0( RingTree* self );
RingTree* JB_Tree_FlatAfter( RingTree* self );
RingTree* JB_Tree_NextSib( RingTree* self );
RingTree* JB_Tree_PrevSib( RingTree* self );
RingTree* JB_Tree_Parent( RingTree* self );
RingTree* JB_Tree_First( RingTree* self );
RingTree* JB_Tree_Last( RingTree* self );
RingTree* JB_RT_SyntaxAccess( RingTree* self, int N );
void JB_Tree_TotalSanity(RingTree* Root);

RingTree* JB_Tree_Root( RingTree* self );
bool JB_Tree_IsRoot( RingTree* self );
bool JB_Tree_HasChildCount( RingTree* self, int HasCount );
int JB_Tree_Count( RingTree* self );
bool JB_Tree_HasChildren( RingTree* self );
void JB_Tree_Destructor( RingTree* self );
void JB_Tree_Dispose( RingTree* self );
void JB_Tree_Constructor0( RingTree* self );
void JB_Tree_Constructor( RingTree* self, RingTree* Parent );

void JB_Tree_ParentSet( RingTree* self, RingTree* NewParent );
void JB_Tree_NextSibSet( RingTree* self, RingTree* NewParent );
void JB_Tree_PrevSibSet( RingTree* self, RingTree* NewParent );
void JB_Tree_LastSet( RingTree* self, RingTree* NewParent );
void JB_Tree_FirstSet( RingTree* self, RingTree* New );

bool JB_Tree_Sanity( RingTree* ring );



} // extern "C"

#endif //__RINGTREE__
