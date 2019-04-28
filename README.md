# jeebox

http://jeebox.org – theo@jeebox.org

Compile using:

    cd </path/to/jeebox-master>
    cmake -BBuild; cd Build; sudo make

# About
Jeebox tries to fulfil the goal of describing everything. Here's an example of Jeebox syntax.

	\You can (% describe anything, in: Jeebox)

[See real syntax examples here](http://jeebox.org/stuff/introduction). While Jeebox is useful for describing code, and save-files, and natural-language, the original goal was to allow describing the meaning-of-code, as a goal towards artificial-intelligence. But Jeebox doesn't have any AI in it, it's simply a data-format! A good one. The library is small at 165K compiled.

Basically, Jeebox parses source-code into a tree. Just like an XML, Jeebox is extensible, it has no keywords. This means you can describe anything very easily.

Jeebox has a C-API and a C++ API. It parses UTF-8 only. The parse-speed is around the same as TinyXML2's parse-speed, it's pretty fast! Jeebox tends to be very expressive, meaning documents can be much smaller than XML/JSON.

Jeebox is also pretty memory-tight, the C++ interface is quite easy to use (you don't have to worry about memory-management). And the model for Jeebox is very simple! Jeebox nodes can be described with two strings only, the `name` and the `type`.

Jeebox has many features designed for programmers, compiled from my 20 year experience. For example string support is pretty good, strings can have embedded expressions, and the escape-code parsing is strong too. Read the website to get an idea of what I put into Jeebox.

This is the first release so email any questions to theo@jeebox.org!


# Why use Jeebox?

Well... Jeebox has so many uses, the question might be "why not use Jeebox?" I've built a programming language around Jeebox, so I know it's really easy to use and fun to use. The language is beautiful, and I never feel "restricted", because I can always just use more of the existing Jeebox syntax. If you were writing a programming language, then using Jeebox means you basically don't need to write your own parser.

Being open-sourced on github means that if you were worried about me not adding things you needed, you could add them yourself. So I'm not controlling anyone's future.

Jeebox can also describe human language, like English/Spanish/German/etc. I think writing a translation program (convert English/Spanish/etc to other languages) would be a great idea! This would help test Jeebox's use for describing meaning, and I'd get a chance to improve Jeebox's syntax for "real world meanings". Only minor improvements would be needed, perhaps none.

Jeebox has incredible potential when it comes to translation, because it captures the grammatical structure of a sentance, it can allow for near-perfect translations. And the syntax is very light, considering the amount of grammatical structure it describes!
    
Jeebox isn't a static thing, it will be modified slightly over time. But on the whole (I've been using it for 7 years) it's barely changed much, just a few additions, almost no changes that break anything. Jeebox is pretty stable and mature by now!

Jeebox has a lot of potential. It could become sort of like "The Unicode of programming languages". (I know that's just an idealistic version of reality! I know reality doesn't work like that.) I did say "potential".


# Notes
For the moment Jeebox is 32-bit only. However the tests work and you can compile projects with it. I am working on a 64-bit version. My 32-bit version made some assumptions that aren't valid in 64-bits.

The Cpp/JB.cpp file is actually auto-generated by my compiler, `Speedie`. This means any changes to it, will be a little hard to merge back into the main source.

Speedie takes Speedie source-code, and turns it into C. Almost all early compilers did this! Even C++ and Java did this once. Speedie isn't part of the distribution, but it's nice to know that Jeebox is being used for a big real-world project (Speedie is based on Jeebox).

I'll release Speedie at some point in the future anyhow. Releasing Jeebox was a big enough job!
