
//  Created by Theodore on 23/04/2019.
//  Copyright © 2019 Theodore. All rights reserved.

#include "Jeebox.h"
#include <stdio.h>

using namespace Jeebox;


void ExampleOfGoodJeebox (String S) { 
    Message M = S.parse();
    M.render().print();
    M.renderreadable().printline();
}


void ExampleOfBadJeebox (String S) {
    printf("Trying to catch bad-input with: '%.*s'\n", S.length(), S.address());
    
    if (S.parse()) {
        puts("failed!!");
    } else for (auto Err : Jeebox::errors()) {
        auto Msg = Err.name();
        printf("Successfully caught input error! (%.*s at byte: %i)\n", Msg.length(), Msg.address(), Err.position());
    }
}


void ExampleOfModifyingJeebox (String S) { 
    Message M = S.parse();
    // two different ways to add to a tree.
    // 1) through parsing, 2) syntactically 

                // Add "%close the~book", through parsing.
    Message M2 = String("%close the~book").parse();
    M.append(M2.first()); // parsing returns the lines wrapped in an $arg
                          // so the first (only) line (%close the~book) is the first (only) child.


                // Add "%open the~door", syntactically.
    auto Added = M.create($oat);
    Added.create($opp, "open");
    auto Adj = Added.create($adj);
    Adj.create($thg, "the");
    Adj.create($thg, "store");
    Adj.last().name("door");
    
    
                // Modify the name and syntax of a message
    auto F = M.first();
    if (F.type() == $tmp) {                   
        F.name("when");
        auto They = F.first().first();
        They.name("fred");                           // Rename something in the tree!
        They.type($name);                          // but only if it's a "tmp" (above test (F.type()==$tmp))
    }
    M.render().print();
    M.renderreadable().printline();
}


void ExampleOfModifyingJeebox2 (String S) { 
    Message M = S.parse();
    // let's alter the name of something in the tree.
    // ideally you want to use std::string or some proper string library, in order to alter names.
    // but this example is OK for now.
    auto Tmp = M.first();
    auto NameMsg = Tmp.first();
    auto Name = NameMsg.name();
    int N = Name.length();
    
    // alteration incoming!
    char* Buff = (char*)malloc(N);
    for (int i = 0; i < N; i++) {
        Buff[i] = Name.address()[N-(i+1)]; // reverse string
    }
    auto NewName = Jeebox::string_owned(Buff,N); // Jeebox will call free() on NewName, when its no longer used.
    M.render().printline();
    NameMsg.name(NewName); // Name is now reversed.
    M.render().printline();
}


int main(int argc, const char * argv[]) {
    int Result = jb_init(0);
    if (Result) {return Result;}
    ExampleOfGoodJeebox("|int| a = b + c");
    ExampleOfBadJeebox("|| (a,+a");
    ExampleOfModifyingJeebox("because @Fred snapped his~fingers");
    ExampleOfModifyingJeebox2("hello @SpongeBob");
    
    return jb_shutdown();
}

