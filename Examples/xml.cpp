
//  Created by Theodore on 23/04/2019.
//  Copyright © 2019 Theodore. All rights reserved.

#include "jeebox.h"
#include <stdio.h>

using namespace Jeebox;


void ExampleOfJeeboxToXML (Message M, int Depth=0) {
    for (int i = 0; i < Depth; i++) { // indent
        putchar('\t'); 
    }
    putchar('<'); M.type().name().print(); putchar('>'); M.name().print();

    for (auto C : M) {
        putchar('\n');
        ExampleOfJeeboxToXML(C, Depth+1);
    }

    if (M.first()) {
        putchar('\n');
        for (int i = 0; i < Depth; i++) { // indent
            putchar('\t'); 
        }
    }
    printf("</"); M.type().name().print(); putchar('>');
    if (!Depth) {
        putchar('\n');
    }
}



int main(int argc, const char * argv[]) {
    String S = String("@Mary laughed (at:the~adorable~birbs)");
    S.printline();
    ExampleOfJeeboxToXML(S.parse());
}

