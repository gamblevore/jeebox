

//  Created by Theodore on 23/04/2019.
//  Copyright © 2019 Theodore. All rights reserved.

#include "Jeebox.h"
#include <stdio.h>
#include <vector>

using namespace Jeebox;
using namespace std;
/*
	user UnicronKid (85910191) {
		screen_name "üñîçrøñ Kî∂"
		inventory (framed_glasses, glitter)
		clothing (kids_unicron_suit)
	}
*/

class UserDemo {
public:;
    int                 ID;
    std::string         AccountName;
    std::string         ScreenName;
    vector<std::string> Inventory;
    vector<std::string> Clothing;
};


Message MessageError (Message self, Syntax S, const char* ErrorName, const char* ItemName) {
    if (self) {
// Replace this with your own error reporting code. In case printf isn't good enough.
        printf("Error (%s): Needed a '%s'", ErrorName, S.name().address());
        if (ItemName) {
            printf(" of name '%s'\n", ItemName);
        } else {
            printf("\n");
        }
    }
    // now we need some way to "locate" this message in the original string... sigh.
    // layers. We need layers. 
    return 0;
}


Message ExpectMatch (Message F, Syntax S, const char* NameMatch=0, Message self=nullptr) {
    if (!F) {
        return MessageError(self, S, "missing item", NameMatch);
    } else if (F.type() != S) {
        return MessageError(F, S, "wrong type", NameMatch);
    } else if (NameMatch and F.name() != NameMatch) {
        return MessageError(F, S, "wrong name", NameMatch);
    }
    return F;
}

Message First (Message self, Syntax S, const char* NameMatch=nullptr) {
    return ExpectMatch(self.first(), S, NameMatch, self); 
}
Message FirstOK (Message self, Syntax S, const char* NameMatch=nullptr) {
    return ExpectMatch(self.first(), S, NameMatch, 0); 
}

Message Next (Message self, Syntax S, const char* NameMatch=nullptr) {
    return ExpectMatch(self.next(), S, NameMatch, self); 
}

Message NextOK (Message self, Syntax S, const char* NameMatch=nullptr) {
    return ExpectMatch(self.next(), S, NameMatch, 0); 
}

Message Any (Message self, Syntax S, const char* NameMatch=nullptr) {
    auto Curr = self.first();
    while (Curr) {
        if (Curr.type() == S and (!NameMatch or Curr.name() == NameMatch)) {
            return Curr;
        }
        Curr = Curr.next();
    }
    return ExpectMatch(self, S, NameMatch, nullptr); 
}

vector <UserDemo*> UsrList;


void LoadUserArg (UserDemo* User, Message Arg) {
    auto Screen = Any(Arg, $tmp, "screen_name");
    User->ScreenName = First(Screen, $str).name();
    auto Inv = Any(Arg, $tmp, "inventory");
    for (auto Name : FirstOK(Inv, $list)) {
        ExpectMatch(Name, $thg);
        User->Inventory.push_back(Name.name());
    }
/*
    || Clothing = Arg[@tmp, "clothing"][0, @list]
    for (Name : Clothing) {
        expect (Name = @thg) (Name)
        User.Inventory ~ Name.name
    }
*/    
    auto Clothing = Any(Arg, $tmp, "clothing");
    for (auto Name : FirstOK(Clothing, $list)) {
        ExpectMatch(Name, $thg);
        User->Inventory.push_back(Name.name());
    }
}


void LoadUsers (String S) {
    Message Root = S.parse();
    Message user_list = Next( First(First(Root, $tmp, "user_list"), $bra), $arg);
    for (auto U : user_list) {
        if (!Jeebox::ok()) return;

        if (ExpectMatch(U, $tmp, "user")) {
            auto User = new UserDemo();
            UsrList.push_back(User);

            auto NameMsg = First(U, $thg);
            User->AccountName = NameMsg.name();
            auto IDMsg = Next(NameMsg,   $bra);
            auto Arg = Next(IDMsg, $arg);
            IDMsg = First(IDMsg,   $num);
            User->ID = (int)IDMsg.nameint();

            LoadUserArg(User, Arg);
        }
    }
}


void UsersExample (String S) {
    // want to add a user, and alter a user.
    // first lets load the users file!
    LoadUsers(S);
    if (!Jeebox::ok()) return;
    
    
    
}


void PrintErrors() {
    for (auto Err : Jeebox::errors()) {
        printf("Error: ");
        Err.name().printline();
    }
}


int main() {
    String S = jb_readfile("Users.box", false);
    if (Jeebox::ok()) {
        UsersExample(S);
    }
    PrintErrors();
    return jb_shutdown();
}


