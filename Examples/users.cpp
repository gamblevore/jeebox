

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
        User->Clothing.push_back(Name.name());
    }
}


void LoadUsers (String S) {
    Message Root = S.parse();
    Message user_list = Next( First(First(Root, $tmp, "user_list"), $list), $arg);
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


UserDemo* GetUser(int ID) {
    for (auto U : UsrList) {
        if (U->ID == ID) {
            return U;
        }
    }
    return 0;
}


void AddUser() {
    auto User = new UserDemo();
    UsrList.push_back(User);

    User->AccountName = "NewKid";
    User->ID = 12345;
    User->ScreenName = "Hai Im new, first tiem joinig lolxoxlolxdd!";
    User->Inventory.push_back("wooden_sword");
    User->Clothing.push_back("jeans");
    User->Clothing.push_back("t_shirt");
}


void UsersExample (String S) {
    LoadUsers(S);
    if (!Jeebox::ok()) return;

// add a new user to the user-list
    AddUser();
    
// alter an existing user (give him a new item)
    UserDemo* ToAdd = GetUser(85910191);
    if (ToAdd) {
        ToAdd->Inventory.push_back("scrying_sphere");
        ToAdd->ScreenName = "Zach${}attack";
    }
    
// save the user-list to a file...
    FILE* f = fopen("../Build/Users_Altered.box", "w+");
    if (f) {
        fprintf(f, "user_list (count:%i) {\n", (int)UsrList.size());
        for (auto U : UsrList) {
            fprintf(f, "\tuser %s (%i) {\n", U->AccountName.c_str(), U->ID);
            String Esc = String(U->ScreenName).escape();
            fprintf(f, "\t\tscreen_name \"%s\"\n", Esc.address() );
            fprintf(f, "\t\tinventory (");
            for (auto I : U->Inventory) {
                fprintf(f, "%s, ", I.c_str());
            }
            fprintf(f, ")\n");

            fprintf(f, "\t\tclothing (");
            for (auto I : U->Clothing) {
                fprintf(f, "%s, ", I.c_str());
            }
            fprintf(f, ")\n");
            fprintf(f, "\t}\n");
        }
        
        fprintf(f, "}\n");
        fclose(f);
    }
}

/*	user UnicronKid (85910191) {
		screen_name "üñîçrøñ Kî∂"
		inventory (framed_glasses, glitter)
		clothing (kids_unicron_suit,rainbow_boots)
	}
*/

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


