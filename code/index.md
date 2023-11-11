---
layout: page
title: Code
mathjax: true
---

I was once a computer science undergraduate student and wrote a lot of code back then.
I write less code now as a math graduate student, but it still comes in now and then. Here
are some programs I've written over the years.

### Literate programs

These programs are written in [CWEB](http://www.literateprogramming.com/cweb_download.html), and are meant to be read!
I have also included the C and PDF outputs so you don't
have to download a CWEB compiler to read them.

+ [LLL-ALGORITHM](https://raw.githubusercontent.com/marcelgoh/marcelgoh.github.io/master/code/literate/lll.w). A program that performs lattice reduction
via the famous LLL algorithm ([C]({{ site.baseurl }}/code/literate/lll.c)) ([PDF]({{ site.baseurl }}/code/literate/lll.pdf)).
+ [LP-BALLS](https://raw.githubusercontent.com/marcelgoh/marcelgoh.github.io/master/code/literate/lp-balls.w).
A program for experimenting with points in the unit ball of $L^p$.
([C]({{ site.baseurl }}/code/literate/lp-balls.c)) ([PDF]({{ site.baseurl }}/code/literate/lp-balls.pdf)).

### TeX macros

If you wish to compile my sources from TeX, you'll need to download these macros and typeset using the Plain TeX engine. Feel free to use and modify them for your own purposes as well.

+ [fontmac.tex](https://raw.githubusercontent.com/marcelgoh/marcelgoh.github.io/master/code/tex-macros/fontmac.tex) (Fonts and document formatting)
+ [mathmac.tex](https://raw.githubusercontent.com/marcelgoh/marcelgoh.github.io/master/code/tex-macros/mathmac.tex) (Mathematical shortcuts)
+ [proofmac.tex](https://raw.githubusercontent.com/marcelgoh/marcelgoh.github.io/master/code/tex-macros/proofmac.tex) (Proof figures)

If you use LaTeX and want your documents to kind of look like my Plain TeX documents, I have a LaTeX `.sty` [file](https://raw.githubusercontent.com/marcelgoh/marcelgoh.github.io/master/code/tex-macros/gohlatex.sty) that sort of approximates it.
You can see a demo I prepared ([LaTeX](https://raw.githubusercontent.com/marcelgoh/marcelgoh.github.io/master/code/tex-macros/gohlatex-demo.tex)/[PDF]({{ site.baseurl }}/code/tex-macros/gohlatex-demo.pdf)). I'm not going to keep this updated though, so if you like the style you should consider switching to Plain TeX. Terms and conditions apply. GohLaTeX should not be used to typeset machine learning documents.

### Exercise solutions

Solutions to exercises in various computer science textbooks.

+ [_Structure and Interpretation of Computer Programs_, by H. Abelson and G. Sussman](https://github.com/marcelgoh/sicp-exercises) (Scheme)
+ [_The Art of Computer Programming_, by D. E. Knuth](https://github.com/marcelgoh/misc-programs/tree/master/mix) (MIX Assembly)

### Projects

#### [OPythn](https://github.com/marcelgoh/opythn)
A compiler and bytecode interpreter for a sizeable subset of Python, written in OCaml (with the help of Ocamllex and Menhir for lexing and parsing). Created as an individual semester-long software project under the supervision of Adam Dingle at Charles University in Prague. Relevant blog posts: [1]({{ site.baseurl }}/2019/04/14/scanning-spaces.html), [2]({{ site.baseurl }}/2019/06/30/generating-stack-machine-bytecode.html).

#### [Alonzo](https://github.com/marcelgoh/alonzo)
An interactive lambda-calculus interpreter that performs normal-order beta-reduction and includes support for variable bindings.

#### [Natural-Language Parser](https://github.com/marcelgoh/nl-parser)
A program that generates syntax trees for English sentences, written in Haskell. A blog post detailing the approach as well as the limitations of the program can be found [here](https://marcelgoh.github.io/2018/08/12/naive-parser.html).

#### [Miscellaneous Programs](https://github.com/marcelgoh/misc-programs)
A collection of small programs and scripts I wrote while learning new languages. Many are solutions to coding puzzles and challenges. Some of the most fleshed-out are:
+ [A calculator, implemented as a stack-based virtual machine](https://github.com/marcelgoh/misc-programs/tree/master/ocaml/ocalc) (OCaml)
+ [A program that collects and analyses weather data](https://github.com/marcelgoh/misc-programs/tree/master/haskell/Borsuk-Ulam) (Haskell)
+ [An implementation of some abstract data structures](https://github.com/marcelgoh/misc-programs/tree/master/c/data_structures) (C)
+ [A tool for analysing/generating Cayley tables](https://github.com/marcelgoh/misc-programs/tree/master/haskell/Cayley)  (Haskell)

### Hackathons

#### [HackPrague 2019](https://github.com/mattonicorp/mattoni)
My teammate and I created Mattoni, a program that allows you to generate and interact with escape-time fractals. We used the SDL2 graphics library and wrote the program in C. I wrote more about it [here]({{ site.baseurl }}/2019/05/06/escape-time-fractals.html). (May 2019)
#### [ConUHacks IV](https://github.com/conudihedral4/nim)
My team implemented [Nim](https://en.wikipedia.org/wiki/Nim), a mathematical strategy game, using the [Processing](https://processing.org) programming language and platform. I wrote more about it [here]({{ site.baseurl }}/2019/02/03/bits-and-doughnuts.html). (January 2019)
#### [HackPrinceton Fall 2018](https://github.com/marcelgoh/hackprinceton-2018)
My team created CourseTalk, a discussion and collaboration platform for students. A blog post describing the process and functionality can be found [here]({{ site.baseurl }}/2018/11/14/coursetalk.html). (November 2018)

### School

These are my assignment solutions for certain classes. They were made public only after their respective course end dates.

#### [COMP 206 Winter 2018](https://github.com/marcelgoh/comp-206-winter-2018)
Assignments from [COMP 206 Introduction to Software Systems](https://www.mcgill.ca/study/2017-2018/courses/comp-206) at McGill University.

#### [COMP 321 Fall 2019](https://github.com/marcelgoh/comp-321-fall-2019)
Assignments from [COMP 321 Programming Challenges](https://www.mcgill.ca/study/2019-2020/courses/comp-321) at McGill University.
