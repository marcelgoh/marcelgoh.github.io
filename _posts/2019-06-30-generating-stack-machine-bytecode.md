---
layout: post
title: Generating stack-machine bytecode
date: 2019-06-30
published: true
mathjax: true
excerpt_separator:  <!--more-->
---

During the last four months, I've been working on an individual software project called [OPythn](https://github.com/marcelgoh/opythn). It's an interpreter for a subset of Python, written in OCaml. Now that the project is complete, I wanted to write about one of the most interesting parts of OPythn's development: translating control structures into stack-machine bytecode. The procedures described in this article are my own work, but a great deal of credit must be given to my supervisor Adam Dingle, who guided me over the course of many meetings. The OPythn stack machine is designed to be very similar to the one inside a conventional Python installation. I'd like to stress, however, that my program might not resemble how real Python's bytecode is compiled at all; indeed, Python's methods are likely more sophisticated and optimised. This article is intended to be rather technical and quite long. Feel free to treat it as a reference and skim to find the bits that interest you.
<!--more-->

### The role of the bytecode interpreter

Broadly, the OPythn interpreter passes through four stages when reading a program: lexing, parsing, (bytecode) compilation, and interpretation. This article will focus on the third step. The full OCaml implementation can be found [here](https://github.com/marcelgoh/opythn/blob/master/src/bytecode.ml), but this article will explain everything in plain English, so you might like to code these procedures in your own favourite programming language. To set the stage, at the compilation step the parser has already transformed OPythn code such as `print(x + 3)` into an abstract syntax tree (or AST) that looks like

```
[(Expr (Call ((Var "print"), [(Op (Plus, [(Var "x"); (IntLit 4)]))])))]
```

The goal is to traverse the tree and emit the instructions

```
0   LOAD_GLOBAL     "print"
1   LOAD_GLOBAL     "x"
2   LOAD_CONST      (Int 4)
3   BINARY_ADD
4   CALL_FUNCTION   1
```

You might notice that the "line numbers" of the instructions are zero-indexed. This is because the compiler actually produces an array as output. Crucially, the current length of the array (5, in the above case) would equal the line number of the next instruction, if we were to add one.  

For most expressions and statements, compilation is a straightforward recursive process. For example, to compile a function call like the one above, we simply load the first expression onto the stack, compile the expression within the brackets (in this case, an addition operation), and then produce a `CALL_FUNCTION` instruction on the correct number of arguments.

### Stack-machine instructions

Before we get into the details of how some more complex structures are compiled, we will have to get familiar with how the stack machine works. When reading OPythn bytecode, one needs to keep an imaginary stack in mind at all times. A `LOAD` instruction puts a value on the top of the stack. For example, `LOAD_CONST (Int 4)` pushes the integer 4 and the instruction `LOAD_GLOBAL "x"` consults a hashtable to find the value associated with the name "x" in the global scope, then pushes that value onto the stack.  

Popping values off the stack isn't usually done explicitly. Instead, many instructions will pop values from the stack as a side-effect of their operations. The `BINARY_ADD` instruction pops two values off the stack, adds them together, then pushes the result back onto the stack. The `CALL_FUNCTION n` instruction pops $n$ values off the stack, then pops a value that should represent a function. It subsequently calls the function on the $n$ arguments and pushes the result onto the stack.  

Usually, after each instruction is executed, the interpreter increments its internal program counter by one. When the program counter's value is too large, the program halts. There are bytecode instructions that modify the program counter explicitly. The most basic of these is `JUMP`. In the code above, if we appended the instruction `JUMP 2` to line 5, then the program would repeat lines 2 to 5 over and over.  

So much for the basic operation of the OPythn stack machine. Most instructions have names that are self-explanatory, but I've included more detailed descriptions of relevant bytecode instructions in an appendix at the very bottom of the article. If you're feeling particularly daring, you might like to read the actual OCaml code for the OPythn virtual machine, which may be found [here](https://github.com/marcelgoh/opythn/blob/master/src/interpreter.ml).

### If-statements

If-statements in OPythn are comprised of an if-clause, zero or more elif-clauses, and possibly an else-clause. The parser converts any `ELIF` tokens it finds into new if-statements nested inside the else-clause, so we need only worry about how to compile if-clauses and else-clauses. Consider the following code snippet:

```python
x = 0
if x == 3:
    print(3)
elif x == 0:
    x += 1
else:
    print("Oh no.")
print(x)
```

The AST corresponding to this snippet is

```
[(Assign ((Var "x"), (IntLit 0)));
  (If ((Op (Eq, [(Var "x"); (IntLit 3)])),
     [(Expr (Call ((Var "print"), [(IntLit 3)])))],
     (Some [(If ((Op (Eq, [(Var "x"); (IntLit 0)])),
               [(Assign ((Var "x"), (Op (Plus, [(Var "x"); (IntLit 1)]))))],
               (Some [(Expr (Call ((Var "print"), [(StrLit "Oh no.")])))])))
             ])
     ));
  (Expr (Call ((Var "print"), [(Var "x")])))]
```

and the bytecode output is

```
0   LOAD_CONST          (Int 0)
1   STORE_GLOBAL        "x"
2   LOAD_GLOBAL         "x"
3   LOAD_CONST          (Int 3)
4   COMPARE_EQ
5   POP_JUMP_IF_FALSE   11
6   LOAD_GLOBAL         "print"
7   LOAD_CONST          (Int 3)
8   CALL_FUNCTION       1
9   POP_TOP
10  JUMP                24
11  LOAD_GLOBAL         "x"
12  LOAD_CONST          (Int 0)
13  COMPARE_EQ
14  POP_JUMP_IF_FALSE   20
15  LOAD_GLOBAL         "x"
16  LOAD_CONST          (Int 1)
17  BINARY_ADD
18  STORE_GLOBAL        "x"
19  JUMP                24
20  LOAD_GLOBAL         "print"
21  LOAD_CONST          (Str "Oh no.")
22  CALL_FUNCTION       1
23  POP_TOP
24  LOAD_GLOBAL        "print"
25  LOAD_GLOBAL        "x"
26  CALL_FUNCTION      1
27  POP_TOP
```

Lines 2 to 23 correspond to the actual if-statement. Let us trace through how OPythn produced this sequence of instructions. Generally, an if-statement is of the form

```
if <cond>:
    <s1>
[else:
    <s2>]
```

where `cond` is an expression and `s1` and `s2` are lists of statements. The square brackets indicate that the else-clause is optional. The first step is to compile `cond`. At this point, lines 0 to 4 are compiled. These are instructions whose net result is that one new value will be pushed to the stack. If this value is found to be false, we'll need to skip all of `s1`, so we need a `POP_JUMP_IF_FALSE` instruction. The trouble is, we don't yet know how far forward we have to jump: `s1` could consist of one statement or a thousand. So for now, we just stick a dummy integer, say, $-1$ in the argument of `POP_JUMP_IF_FALSE`. Of course we'll need to save the index where this dummy instruction is and remember to fix it later. We'll call it $i_1$ (in our example, $i_1\gets 5$).  

Now we recursively call the "compile" procedure on the statements in `s1`. This produces lines 6 to 9 of the example. At this point, we need to check if the else-clause is present or not. If it isn't, we just measure the length of the array and amend the `POP_JUMP_IF_FALSE` instruction at index $i_1$ to jump forward to this location. The compilation of the else-less if-statement is complete.  

In the case that an else-clause is present, we need to produce a non-conditional `JUMP` instruction at the end of `s1` that will skip `s2`. This is to avoid both `s1` and `s2` being executed. However, again we run into the problem of not knowing the destination of the forward jump, so we need to emit another dummy instruction. We put `JUMP -1` and save the index by setting $i_2\gets 10$. Now the compilation of `s1` is complete and we may repair the instruction at location $i_1$ to jump to the current length of the array. So line 5 now reads `POP_JUMP_IF_FALSE 11`.  

We're almost done. The last step is to recursively compile `s2` (lines 11 to 23 &mdash; notice that in our case, `s2` contains an entire if-statement corresponding to the elif in the OPythn source), measure the length of the array at this point, and amend the instruction at location $i_2$.

Conditional expressions of the form `<e1> if <cond> else <e2>` are compiled in a similar manner.

### While-statements

OPythn's while-statements are simpler than Python's, in that they may not contain an else-clause. This means that while-statements are always compiled the same way. Consider the following (rather useless) example of OPythn source code:

```python
x = 0
while True:
    break
    continue
    print("Ahoj")
print(x)
```

The abstract syntax tree is

```
[(Assign ((Var "x"), (IntLit 0)));
  (While ((BoolLit true),
     [Break; Continue; (Expr (Call ((Var "print"), [(StrLit "Ahoj")])))]));
  (Expr (Call ((Var "print"), [(Var "x")])))]
```

and the bytecode we want to produce looks like

```
0   LOAD_CONST          (Int 0)
1   STORE_GLOBAL        "x"
2   LOAD_CONST          (Bool true)
3   POP_JUMP_IF_FALSE   11
4   JUMP                11
5   JUMP                2
6   LOAD_GLOBAL         "print"
7   LOAD_CONST          (Str "Ahoj")
8   CALL_FUNCTION       1
9   POP_TOP
10  JUMP                2
11  LOAD_GLOBAL         "print"
12  LOAD_GLOBAL         "x"
13  CALL_FUNCTION       1
14  POP_TOP
```

The while-loop corresponds to lines 2 to 10. Generally, a while-loop has the form

```
while <cond>:
    <ss>
```

The first step is to save the index of the start of the loop, $i_s\gets 2$. We will need this to compile any continue-statements as well as fill in the backward jump at the end of the loop. Then we compile `cond`, which should push a truth-value onto the stack, push a dummy `POP_JUMP_IF_FALSE -1`, and save its location $i_1\gets 3$. So far so good. Now we need to compile `ss`. Were it not for the presence of break- and continue-statements, this would be a simple case of recursively calling "compile" on the statements in `ss`.  

Instead, we need a helper "compile loop" procedure that takes $i_s$ and $i_1$ as arguments. It compiles most statements normally, but it has the extra responsibility of needing to produce the correct `JUMP` instructions for break- and continue-statements. This cannot be done in one pass, because we do not yet know where the `ss` block ends. The solution is to compile normally but produce tagged dummy `JUMP` instructions whenever a break or continue is encountered. So we might emit a `JUMP -10` for every break and `JUMP -20` for every continue. (At this time, line 4 reads `JUMP -10` and line 5 reads `JUMP -20`.) After this first pass, we know the address of the end of the loop so we may save it in a variable $i_e\gets 11$.  

Now we need to go back and fix all the dummy instructions. Like in the if-statement example, the `POP_JUMP_IF_FALSE -1` instruction at location $i_1$ needs to change to `POP_JUMP_IF_FALSE 11` since $i_e = 11$. Then every `JUMP -10` represents a break, so $i_e$ needs to be filled in here as well. Finally, every `JUMP -20` represents a continue, so we need to fill in the start location of the loop $i_s = 2$.

For-statements also need to handle breaks and continues, but much of the complexity of OPythn for-statements lies not in compilation but rather in how the virtual machine deals with iterable types, so it is beyond the scope of this article.

### And- and or-expressions

This last example of jump-laden bytecode might come as a bit of a surprise. But short-circuiting boolean expressions are not just a question of optimisation; they are vital to the execution of certain programs. Consider the code

```python
node = None
if node != None and node.info == 0
    print("Zero node")
```

A quick glance at the program tells us that the block of the if-statement should not execute. The catch is that the interpreter must realise this _before_  the test `node.info == 0` is executed. This is because trying to get the `info` attribute of the `None` object will cause a runtime error. Once again, let us deconstruct the source code. The AST of this snippet is

```
[(Assign ((Var "node"), None));
  (If (
     (Op (And,
        [(Op (Neq, [(Var "node"); None]));
          (Op (Eq, [(AttrRef ((Var "node"), "info")); (IntLit 0)]))]
        )),
     [(Expr (Call ((Var "print"), [(StrLit "Zero node")])))], None))
  ]
```

and the desired bytecode is

```
0   LOAD_CONST              None
1   STORE_GLOBAL            "node"
2   LOAD_GLOBAL             "node"
3   LOAD_CONST              None
4   COMPARE_NEQ
5   JUMP_IF_FALSE_OR_POP    10
6   LOAD_GLOBAL             "node"
7   LOAD_ATTR               "info"
8   LOAD_CONST              (Int 0)
9   COMPARE_EQ
10  POP_JUMP_IF_FALSE       15
11  LOAD_GLOBAL             "print"
12  LOAD_CONST              (Str "Zero node")
13  CALL_FUNCTION           1
14  POP_TOP
```

In general, an and-expression looks like

```
<e1> and <e2>
```

By now, you know the name of the game. We first compile `e1`. Next we save the current length of the array $i_1\gets 5$ and produce a dummy `JUMP_IF_FALSE_OR_POP -1` instruction, because we don't yet know where the bytecode for `e2` ends. Then we recursively compile `e2`, and finally we may fill in the argument to `JUMP_IF_FALSE_OR_POP` at location $i_1$, setting it to $10$, the new length of the bytecode array. Or-expressions are handled analogously with the `JUMP_IF_TRUE_OR_POP` instruction.

### Conclusion

I hope this article gave you some idea of how OPythn/Python code can be compiled to bytecode. Like I said above, these are actually some of the trickier cases. In general, generating code for stack-machines is easy since no register management is required, which is why many virtual machines are stack-based (Java and Python are notable examples).

### Appendix

Here are the detailed descriptions of the bytecode instructions that appeared in the above sections:

+ `BINARY_ADD` Two values are popped off the stack and their sum is pushed onto the stack.
+ `CALL_FUNCTION n` The interpreter pops $n$ values off the stack and then pops a function. The function is called on the $n$ arguments and the result is pushed onto the stack.
+ `COMPARE_EQ` Two values are popped off the stack and compared for equality. If they are equal, `True` is pushed onto the stack, otherwise `False` is.
+ `COMPARE_NEQ` Same as above, with `True` and `False` flipped.
+ `JUMP n` The program counter, instead of incrementing by one as usual, sets itself to the value $n$.
+ `JUMP_IF_FALSE_OR_POP n` Looks at the value on the top of the stack without popping it. If this value is false, the program counter is set to $n$. Otherwise, the stack is popped and the program counter increments as usual.
+ `JUMP_IF_TRUE_OR_POP n` Same as above, except the jump happens if the top of stack is true instead of false.
+ `LOAD_ATTR id` The top of the stack is popped and treated as an object. The value corresponding to the attribute `id` of this object is pushed to the stack.
+ `LOAD_CONST val` The indicated OPythn value is pushed onto the stack.
+ `LOAD_GLOBAL id` A hashtable that contains all global variable bindings is consulted and the value corresponding to the key `id` is pushed onto the stack.
+ `POP_JUMP_IF_FALSE n` One value is popped of the stack and tested for truth value. If the result is false, the program counter is set to location $n$.
+ `POP_TOP` The top of the stack is popped and its value discarded.
+ `STORE_GLOBAL id` One value is popped off the stack and bound to the name `id` in the global scope.
