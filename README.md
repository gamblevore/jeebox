# jeebox

[http://jeebox.org](http://jeebox.org) \- [theo@jeebox.org](mailto:theo@jeebox.org)

Join the reddit group [http://reddit.com/r/jeebox](http://reddit.com/r/Jeebox)

Compile:

    cd </path/to/jeebox-master>
    cmake -B Build .; cd Build; sudo make install

# About

Jeebox tries to fulfil the goal of describing everything.     `You can %describe (anything, in: Jeebox)`

* Code : Build a programming language using Jeebox, or anything with code-like syntax (databases).
* Save-files : For just about anything.
* Natural-language : English/Spanish/Russian/etc.
* Other things : Like maths! Or freely mix any combination of the above.

(The original goal was to describe the meaning-of-code, as a step towards artificial-intelligence. But Jeebox doesn't have any AI in it, it's just a good data-format!)
	
                        /*** English examples ***/
    how::can (someone fall so~far) #without %realising it
    this~window plays music #until the~user presses the~cancel~key
    
                        /***  Code examples   ***/
    print "Hello ${username}! You have ${Mail.Inbox.Count} pieces of mail for you!"
    function funcname (|int| n) {arr[n] = obj.func(var)}
    
                        /***   Data example   ***/
	user_list {
		user fred (id:85719) (inventory:(spoon))
		user mlg_haxx_420 (id:97653) (inventory:(rifle, boots))
	}

[Learn Jeebox syntax here](http://jeebox.org/stuff/introduction).


Jeebox parses a UTF-8 string into a tree of 'nodes'. Jeebox is simple because each node only needs the `name` and the `type` (both strings) to describe it. Jeebox is extensible (no keywords), meaning you can describe **anything** unambiguously. Being simple also makes Jeebox memory-tight.

Jeebox's parse-speed is near that of TinyXML2's, it's pretty fast! Jeebox is highly expressive, meaning that (depending on what you are doing) documents **can be** much smaller than XML/JSON, but never bigger. Jeebox itself is small at ~155K compiled.

I added many features to make programmers lives easier. For example: "Double-quoted" strings allow embedded expressions, unicode and byte escape codes. But \`backtick\` strings have none of that. [Read the website](http://jeebox.org/stuff/introduction) to see what I put into Jeebox. Jeebox is clean, because unlike [Javascript / C# / Java](https://msdn.microsoft.com/en-us/data/aa664669(v=vs.85)) Jeebox strings **can** express characters above `&#xFFFF;` without 'surrogates'!

# Why Use Jeebox?

Jeebox is good-looking, modern and combines the best parts from many languages.

Lets say you want to "create your own file format". Using Jeebox you'll find it much easier than if you had to create a parser or a "grammar" for a parser-generator. Also, Jeebox gives you the best string-parsing built in. And it's reusable anytime you need a new format!

I built a programming language `Speedie` around Jeebox, so I know using Jeebox is easy to use and fun. `Speedie` is beautiful and Jeebox never restricts me.

Being open-sourced on github means that I'm not controlling the future of Jeebox users.

The downsides to using Jeebox? Well... it is another language to learn, its an eye-opening experience.



# Notes

Jeebox has a C-API and a C++ API. Jeebox can compile for 64-bit or 32-bit environments. Tested on OS X, and Ubuntu Linux. Windows will come when I have people interested in it. Jeebox is single-threaded right now.

The C++ version is easier, because it has automatic memory-management. The C version requires you to manually do memory-management, which is best avoided. The C version is intended for writing a Jeebox binding for another languages (python/ruby/etc).

