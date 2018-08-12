---
layout: post
title: A naïve parsing algorithm
date: 2018-08-12
published: true
excerpt_separator:  <!--more-->
---
A couple of weeks ago I started reading _Introduction to the Theory of Computation_ by Michael Sipser. As soon as I got to the section on context-free grammars, I wondered if the syntactical rules I learned in my Linguistics class could be modelled in a CFG. I started writing a program with the intention of implementing the [CYK algorithm](https://en.wikipedia.org/wiki/CYK_algorithm) in Haskell, but I had trouble translating the iterative pseudocode into Haskell syntax, which I'm only beginning to get a hang of. Eventually I got side-tracked on my own simplified approach that works surprisingly well. I would eventually like to get the proper algorithm working in my code (perhaps in a language that makes iteration easier) but I wanted to describe my naïve approach and its limitations as well.  
<!--more-->
### How it works
If you like, you can view and download the source code [here](https://github.com/marcelgoh/nl-parser). The code is in the `src` folder, with the main algorithm located in the `Parse.hs` file and the lexicon and grammar rules in `Grammar.hs`. I tried to represent full X-bar structure in my grammar, but soon gave up when it was clear my algorithm isn't robust enough to support it. The simplified grammar that works better is separated into four different sets, each representing a different level of priority. First, nouns and verbs can be noun-phrases and verb-phrases on their own, so we have:
```
NP -> N   -- a noun is a noun-phrase
VP -> V   -- a verb is a verb-phrase
```
Second we have the "complement" rules, loosely related to complements in X-bar structure (again, my algorithm doesn't do X-bar structure, but taking elements from the theory greatly increases the precision of the program). We want to link these pairs of adjacent words as early as possible. For example a verb-phrase like `find` should be linked to an adjacent noun-phrase like `the cheese` as soon as possible because the three words together form a more complex verb phrase:
```
VP -> VP NP  -- a verb and its object form a verb-phrase
VP -> VP CP  -- a verb and a complement clause form a verb-phrase
PP -> P NP   -- a preposition and a noun form a prepositional phrase
CP -> C TP   -- a complementiser and a full sentence make a complement clause
```
After that we have the "adjunct" rules, loosely related to adjuncts in X-bar theory. These are a bit like complements but they are stackable and movable. For example, though a verb may only have one noun-phrase, directly to its right, as its complement, it can have an arbitrary number of adverbs on either side as its adjuncts. Sometimes whether a certain phrase is an adjunct or complement depends on context. For the sake of my programs priority queue, these are always treated as adjuncts.
```
NP -> Adj NP  -- a noun can be preceded by an adjective
NP -> NP PP   -- a noun can be followed by a prepositional phrase
VP -> VP PP   -- a verb can be followed by a prepositional phrase
VP -> Adv VP  -- a verb can be preceded by an adverb
VP -> VP Adv  -- a verb can be followed by an adverb
```
Lastly we have the "specifier" rules, related to the highest node in an X-bar phrase. These are the combinations we want to do last. For example, a noun-phrase and a verb-phrase form a full sentence or TP, but we don't want to prematurely link them.
```
NP -> Det NP  -- a noun can be preceded by a determiner like "a" or "the"
VP -> T VP    -- a verb can be preceded by an auxiliary verb like "will" or "should"
TP -> CP VP   -- a full sentence can be formed from a subordinate clause and a verb-phrase
TP -> NP VP   -- a full sentence can be formed from a noun-phrase (subject) and a verb-phrase (predicate)
```
To determine if a sentence is valid, the program simply performs as many reductions as it can, always choosing higher-priority reductions first. When it finishes, if the result is `TP`, the sentence is deemed valid. Before we go into the various defects of the algorithm, let's show that for simple sentences, the program does indeed work. For the sentence `The quick brown fox jumps over the lazy dog.`, the program spits this out:
```
[TP]
[NP VP]
[NP VP PP]
[NP VP P NP]
[Det NP VP P Det NP]
[Det Adj NP VP P Det NP]
[Det Adj Adj NP VP P Det Adj NP]
[Det Adj Adj N V P Det Adj N]
The quick brown fox jumps over the lazy dog.
SENTENCE IS VALID.
```
It can even parse more complex sentences like the following:
```
[TP]
[CP VP]
[C TP VP]
[C NP VP VP]
[C NP VP NP VP]
[C Det NP T VP Det NP VP]
[C Det NP T Adv VP Det NP VP]
[C Det NP T Adv VP Det NP VP NP]
[C Det N T Adv V Det N V N]
That the mouse may never find the cheese saddens me.
SENTENCE IS VALID.
```
The program ignores punctuation, but because the order of some combinations doesn't matter, certain reversed constructions like the following can also be recognised.
```
[TP]
[CP VP]
[CP VP PP]
[C TP VP P NP]
[C NP VP T VP P Det NP]
[C NP VP T VP P Det NP PP]
[C NP VP NP T VP P Det NP P NP]
[C N V N T V P Det N P N]
If it rains, Rhonda will dance in the road with Jennifer.
SENTENCE IS VALID.
```
But when we get into larger constructions, we start to see the limitations of the algorithm. This valid sentence is not recognised by the parser:
```
[TP CP]
[TP C TP]
[TP C NP VP]
[TP C NP VP CP]
[TP C NP VP C TP]
[NP VP C NP T VP C NP VP]
[NP VP C NP T VP PP C NP VP]
[NP VP C NP T VP P NP C NP VP]
[N V C N T V P N C N V]
Rhonda decided that she will dance with Jennifer if it rains.
SENTENCE IS NOT VALID.
```
What happened here is that the subordinate clause `that she will dance with Jennifer if it rains` didn't get constructed before the two-word "sentence" `Rhonda decided` was already made into a `TP`.
### The algorithm falls apart
The biggest issue with the algorithm is that it doesn't recognise many valid sentences. A proper parsing procedure, when faced with a choice between two valid reductions, considers both and will accept the input if either one passes. My program simply chooses one. The reason it can fake correctness is because it tends to choose the correct pairings based on the priority coded in.  

Less commonly, the program will also accept invalid input. As I said above, there is no way for the program to know what kind of relationships the phrases have. A real noun-phrase cannot have two complements but the program will happily recognise an incorrect sentence like the following:
```
[TP]
[NP VP]
[Det NP VP]
[Det NP PP VP]
[Det NP PP PP VP]
[Det NP P NP P NP VP]
[Det N P N P N V]
The students of mathematics of linguistics sleep.
SENTENCE IS VALID.
```
It's possible that this could be fixed by creating a new class of preposition, say `Q` that governs these kinds of phrases, then mark any noun that already has a complement phrase as `QNP` so that it acts like a normal `NP` except that it cannot combine with another `Q`. But this is a great deal of hassle to only partially solve the problem. What about prepositions that can form both complements and adjuncts? How should the program know which one to pick?  

Some other concepts, like _wh_-movement and inversion, are completely out of reach. In a sentence like `Who did Rhonda dance with?` which is valid in all but the most prescripivist grammars, the program would never hope to guess that `Rhonda` and `did` switched places and that the pronoun `who` moved all the way from the end of the sentence to the beginning.  

I've been testing the limits of my algorithm, trying to see if adding extra rules or additional priority levels could make it more accurate, but this is as far as I've gotten. I'm sure there is a fairly simple proof that the algorithm doesn't work, i.e. for some valid sentence, prove that no amount of new rules, priority levels, or word classes would allow it to be recognised. I haven't found this proof yet but I will definitely update the post if I do find it.  

Moving forward, I'd like to implement the actual CYK algorithm working in a procedural language like C, then experiment with the limitations of that. I did a bit of research on the web into the question of whether natural language is context-free and found some disagreement so it's something to play around with for sure.