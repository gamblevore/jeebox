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
	user_list { user fred (id:85719) (inventory:(spoon)), user mlg_haxx_420 (id:97653) (inventory:(rifle, boots)) }

[Learn Jeebox syntax here](http://jeebox.org/stuff/introduction).


Jeebox parses a UTF-8 string into a tree of 'nodes'. Jeebox is simple because each node only needs the `name` and the `type` (both strings) to describe it. Jeebox is extensible (no keywords), meaning you can describe **anything** unambiguously. Being simple also makes Jeebox memory-tight.

Jeebox's parse-speed is near that of TinyXML2's, it's pretty fast! Jeebox is highly expressive, meaning that (depending on what you are doing) documents **can be** much smaller than XML/JSON, but never bigger. Jeebox itself is small at ~155K compiled.

I added many features to make programmers lives easier. For example: "Double-quoted" strings allow embedded expressions, unicode and byte escape codes. But \`backtick\` strings have none of that. [Read the website](http://jeebox.org/stuff/introduction) to see what I put into Jeebox. Jeebox is clean, because unlike [Javascript / C# / Java](https://msdn.microsoft.com/en-us/data/aa664669(v=vs.85)) Jeebox strings **can** express characters above `&#xFFFF;` without 'surrogates'!

# Why use Jeebox?

The issues surrounding Jeebox are not a matter of how good it is. There seems to be "invisible rules" guiding society, including on technical things. People want to move things in a certain direction, and I was moving in a different direction.

I guess I'm moving towards unity/simplicity, while most people move towards fragmentation/complexity. There's other issues like me "not being part of any power-system" (I've never worked at, or have friends with people at apple/google/intel/etc).

And I notice that all big popular stuff (XML/JSON) never had to "get accepted from the outside". They were created by powerful groups in the first place. So, maybe a new approach is needed?

All I can say is that Jeebox is great, it's better than any other format I've seen. And it is multi-purpose so you can replace multiple formats with Jeebox. If everything is in Jeebox, then there's actually less formats you need to learn. It won't let you down. Really all I can say is that I hope Jeebox has a great future...


# Jeebox Is Still Great

If you just look at the code and how easy it is to use... Jeebox is truely amazing! Really frees you from a lot of things.

Like needing to write parsers. You get a load of advanced features built-in. Also, assuming enough languages are expressed in Jeebox, this could reduce code-size because we replace many parsers with Jeebox!

I built a programming language `Speedie` around Jeebox, so I know it's really easy to use and fun. `Speedie` is beautiful and Jeebox never restricts me.

Being open-sourced on github means that if you were worried about me not adding things you need, you could add them yourself. I'm not controlling anyone's future.

# Looking for a translation app, as a real-world-test

Jeebox can also describe human language. I think Jeebox could really do with a real-world translation app to test it, just like I tested Jeebox with my compiler `speedie`. I actually barely modified jeebox during the making of `speedie`, but minor tweaks can be important. I think it will be the same for translation too?

The thing is, I've done far too much alone. Translation is something that needs a team, and I'm not a business person (at all). Don't ask me to come up with a business plan. Just because I know it could transform the world of translation, doesn't mean I can even think about how to make money from it.

I mean the way my mind works is like "Hey, this could make everything better for everyone, surely we should be supported for that? Considering the value of our translation stuff could probably saving people billions of dollars time-worth". Unfortunately that's not how the world works, but it is how **my mind** works, and I'm not gonna change how I work or feel, because I just get frazzled and ruined if I have to think about how to be accepted "just for money".

Jeebox has a lot of potential. By capturing the grammatical structure of a sentence, Jeebox can improve translation accuracy by 10x-100x, and the syntax is light. Jeebox could be very useful for medical documents, or technical documents (electronics/engineering/etc) which need precise translation.

# Notes

Jeebox has a C-API and a C++ API. The C++ version is better, because you can "just use it". The C-API requires you to do memory-management, which is verbose and error-prone. But useful if you are writing a Jeebox binding for another language (python/ruby/etc). Jeebox can compile for 64-bit or 32-bit environments. Tested on OS X, and Ubuntu Linux. Windows will come when I have people interested in it.

Jeebox is single-threaded right now.

Jeebox is being used for one large real-world project right now, my unreleased compiler `Speedie`. In fact, the source code for Jeebox, is written in Jeebox! Imagine trying to write a JSON parser in JSON, impossible ;) because JSON can't describe code. But Jeebox can describe code, data and meaning, so with Jeebox it is possible. I'll release `Speedie` at some point in the future anyhow. Releasing Jeebox was a big enough job!
