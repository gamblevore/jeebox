
#include "Jeebox.h"
#include <iostream>
using namespace Jeebox;

struct {
    bool show_input;
    bool readable;
    bool Stdin;
    bool string;
    bool GotAny;
    bool quiet;
    bool xml;
} Options;


void PrintErrors() {
    auto List = Jeebox::errors();
    for (auto Err : List) {
        std::cerr << " :: Error: "; Err.name().print(); std::cerr << " :: \n";
    }
}


void JeeboxToXML (Message M, int Depth=0) {
    for (int i = 0; i < Depth; i++) { // indent
        putchar('\t'); 
    }
    putchar('<'); M.type().name().print(); putchar('>'); M.name().print();

    for (auto C : M) {
        putchar('\n');
        JeeboxToXML(C, Depth+1);
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


void PrintReadable(String A) {
    std::cout << "\n";
    if (Options.show_input) {
        if (!Options.quiet) {std::cout << " :: Displaying input. :: \n";}
        A.printline();
    }
    if (Options.string) {
        Syntax($str).create(A).render().printline();
    } else {
        Message s = A.parse();
        if (!s) {return;}
        if (Options.readable) {
            s = s.convertreadable();
        }
        if (Options.xml) {
            JeeboxToXML(s);
        } else if (Options.readable) {
            if (!Options.quiet) {std::cout << " :: Converting back to jeebox-syntax! :: \n";}
            s.render().printline();
        } else {
            if (!Options.quiet) {std::cout << " :: Displaying the parse tree for you! :: \n";}
            s.renderreadable().printline();
        }
    }
}


void ParseStdIn() {
    if (!Options.quiet) { std::cout << " :: Type some jeebox and press control-D once you are done! :: \n\n";}
    std::string std_string(std::istreambuf_iterator<char>(std::cin), {}); // C++ is so baaad
    PrintReadable(String(std_string));
}


void HandleFile(const char* s) {
    if (s[0] and s[0] != '-') {
        Options.GotAny = true;
        String File = Jeebox::readfile(s);
        if (File) {
            PrintReadable( File );
        }
    }
}


void HandleSwitch(const char* s) {
    if (s[0] == '-') {
        String c = s+1;
        if (c == "s") { Options.string=true;
        } else if (c == "d") {Options.show_input=true;
        } else if (c == "q") {Options.quiet=true;
        } else if (c == "i") {Options.Stdin=true; Options.GotAny=true;
        } else if (c == "r") {Options.readable=true; 
        } else if (c == "x") {Options.xml=true; 
        } else {
            std::cerr << "Unrecognised switch: " << c.address() << "\n";
            exit(-1);
        }
    }
}


int main(int argc, const char* argv[]) {
    int Errs = jb_init(1);
    if (Errs) {return Errs;}

    for (auto c = argv+1; *c; c++) {
        HandleSwitch(*c);
    }
    if (((int)Options.xml + (int)Options.string + (int)Options.readable) >= 2) {
        std::cerr << "bad switch: -x / -s / -r are exclusive\n";
        exit(-1);
    }
    for (auto c = argv+1; *c; c++) {
        HandleFile(*c);
    }
    
    if (Options.Stdin) {
        ParseStdIn();
    } else if (!Options.GotAny) {
        std::cout << R"(Just a simple util for Jeebox.
    Usage: jb /path/to/jb_file.txt
    -r = turn readable-ast into jeebox-syntax
    -i = use stdin
    -s = string escape
    -d = show input
    -q = less noisy
)";
    }

    PrintErrors(); // if any!
    return jb_shutdown();
}

