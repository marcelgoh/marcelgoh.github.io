---
layout: post
title: Fun with Cayley tables
date: 2018-10-06
published: true
excerpt_separator:  <!--more-->
---
It's finally fall in Montréal and the semester is in full swing at McGill. Easily my favourite class this semester is [Algebra 1](https://www.mcgill.ca/study/2018-2019/courses/math-235), which, so far, has been largely concerned with introductory group theory. The subject matter is fascinating because it teaches that the common-or-garden mathematical operations on numbers are just a couple of the many algebras that exist. Properties like associativity, commutativity, identity, and inverses don't just apply to numbers but to a whole host of other mathematical objects as well, like symmetries and permutations. I wrote a Haskell program that analyzes group multiplication (Cayley) tables and in this post I wanted to go through some of the algorithms I used as well as outline some of the obstacles I faced.  

<!--more-->
I first thought of making a tool to analyze Cayley tables while doing one of the homework assignments from the (free) textbook [Abstract Algebra](http://abstract.ups.edu) by Tom Judson, which asks you to determine if a given Cayley table froms a group. The existence of inverses and the identity are easy to check just by looking, but associativity requires checking every triple of elements which is unfeasible to do by hand. (The question was actually meant to be solved in a cleverer manner than brute-force anyway, but that's beside the point!) It took a couple of weeks and the assignment's due date is long past due, but I finally finished the program.  

The source code is available [here](https://github.com/marcelgoh/misc-programs/tree/master/haskell/Cayley). Currently, it isn't possible to compile an executable, but the program works great loaded into GHCi.
### Data structures
I tried to keep my data representation simple, though when the program started getting bigger and the similarity between `[Element]` and `[[Element]]` started to get more confusing, I started to feel like I should have created more types to keep them distinct. In any case, here is how I represented group elements and the groups themselves:
```haskell
data Element = Int Int | Char Char | String String
         deriving (Eq, Show)
data Group = Group [Element] [[Element]]
```
I defined a group as a set and a Cayley table, as opposed to a set and an operation, because it is difficult to describe operations between characters and strings in code. To define a numerical group in the more mathematical way, I put in a function that takes a set of integers and an operation (an anonymous function) and generates the group:
```haskell
-- creates a group given a set of integers and a binary operation
groupFromOperation :: [Int] -> (Int -> Int -> Int) -> Group
groupFromOperation ints operation =
  let set = map Int ints
      table = map (\l -> map Int l) $ map (\g -> map (\x -> operation g x) ints) ints
  in Group set table
```
So we can do something like this:
```
*Main> tenGroup = groupFromOperation [x | x <- [0..9], gcd x 10 == 1] (\x y -> (x*y) `mod` 10)
*Main> printCayley tenGroup
  * |   1   3   7   9
----------------------
  1 |   1   3   7   9
  3 |   3   9   1   7
  7 |   7   1   9   3
  9 |   9   7   3   1
```

### Printing the tables
I've been working with Haskell for a couple months, but I still run into a lot of trouble whenever anything has to be printed to the screen. I ended up putting all the messy side-effecty code into a single `printCayley` function (It's big and messy so I didn't put it on this page, but do check it out in `Analyze.hs`. Working with the different possible underlying representations of an `Element` was a little bit challenging, but in the end the function prints out nice tables like this:
```
*Main> printCayley quatGroup
  * |   1  -1   i  -i   j  -j   k  -k
--------------------------------------
  1 |   1  -1   i  -i   j  -j   k  -k
 -1 |  -1   1  -i   i  -j   j  -k   k
  i |   i  -i  -1   1   k  -k  -j   j
 -i |  -i   i   1  -1  -k   k   j  -j
  j |   j  -j  -k   k  -1   1   i  -i
 -j |  -j   j   k  -k   1  -1  -i   i
  k |   k  -k   j  -j  -i   i  -1   1
 -k |  -k   k  -j   j   i  -i   1  -1
 ```
Pretty neat, eh?

### Identity
To find the identity element, I simply checked if there was an element whose corresponding row and column matched the original ordering of the set exactly:
```haskell
getId :: Group -> Maybe Element
getId (Group set rows) =
  let cols = getCols rows
      -- checks if any element in set has the set itself as its row/col
      tryElem :: [Element] -> [[Element]] -> [[Element]] -> Maybe Element
      tryElem setLeft rows cols =
        case setLeft of
          []   -> Nothing
          e:es -> if (((head rows) == set) && (head cols) == set)
                  then Just e
                  else tryElem es (tail rows) (tail cols)
  in tryElem set rows cols
-- checks if group has an identity element
hasId :: Group -> Bool
hasId g = isJust $ getId g
```
If no identity was found, we don't want anything returned, so I implemented a bunch of the functions with the `Maybe`, which was surprisingly easy to work with, even if it makes the outputs a little uglier. I hadn't used it before but it was very similar to the `option` type I learned in Standard ML.

### Inverses
To find inverses for each element, I found which element it multiplies with it on the right to give the identity, then checked that it also gives the identity when left-multiplied (because inverses are commutative).
```haskell
-- given an Element and a Group, find the inverse of that Element in the Group
getInv :: Element -> Group -> Maybe Element
getInv elem (Group set rows) =
  let group = (Group set rows)
      identity = getId group
      rowOfElem = findRow elem group
      -- find the element that gives id in rowOfElem
      findInv :: Element -> [Element] -> [Element] -> Maybe Element
      findInv id setLeft rowsLeft =
        case rowsLeft of
          []   -> Nothing
          e:es -> if e == id then Just (head setLeft) else findInv id (tail setLeft) es
  in case (identity, rowOfElem) of
       (Just id, Just elems) -> let possibleInv = findInv id set elems
                                in case possibleInv of
                                                 -- check if (elem^{-1}*elem = id) as well
                                     (Just p) -> if dot p elem group == identity
                                                 then possibleInv
                                                 else Nothing
                                     _        -> Nothing
       _                     -> Nothing
```
Lots of pattern matching and `Just`s and `Nothing`s but overall a pretty straightforward procedure. Then I defined a function `hasInvs :: Group -> Bool` that checks that every element in the group has an inverse.

### Associativity
The associativity-checker makes use of [Light's associativity test](https://en.wikipedia.org/wiki/Light%27s_associativity_test) but without skipping any elements (it is hard to tell what is a proper generating subset algorithmically) so it is largely brute-force and runs in cubic time:
```haskell
-- checks associativity using Light's Associativity Test (runs with O(n^3))
associative :: Group -> Bool
associative (Group set rows) =
  let group = (Group set rows)
      -- create a table given a binary operation on the group's set
      makeTable :: (Element -> Element -> Element) -> [[Element]]
      makeTable op =
        let construct acc elems =
              case elems of
                []   -> reverse acc
                e:es -> construct ((map (\y -> op e y) set) : acc) es
        in construct [] set
      -- define multiplication within the group
      times :: Element -> Element -> Element
      times g h =
        fromJust (dot g h group)
      -- checks if an element is associative between every two other elements in the group
      sandwichElement :: Element -> Bool
      sandwichElement a =
        let -- define two new binary operations
            star = makeTable (\x y -> x `times` (a `times` y))
            circle = makeTable (\x y -> (x `times` a) `times` y)
        in -- check if they still produce the same table
           equalGroup (Group set star) (Group set circle)
  in if closed group  -- if group is not closed, it cannot possibly be associative
     then foldr (&&) True (map sandwichElement set)
     else False
```
For each element `a` in the set, two new tables are constructed that correspond to `x(ay)` and `(xa)y`. If both these tables are still equal for every element in the set, then associativity holds for the original table.
### Combining everything
All that's left to do is to combine everything into an `isGroup` function! I also added a bonus `abelian` function that checks if a the operation is commutative on the set:
```haskell
-- checks if table represents a group by combining checks for closure, identity,
-- inverses, and associativity
isGroup :: Group -> Bool
isGroup g = closed g && hasId g && hasInvs g && associative g
-- determines if given group is abelian
abelian :: Group -> Bool
abelian (Group set rows) =
  let cols = getCols rows
  in isGroup (Group set rows) && equalGroup (Group set rows) (Group set cols)
```
### What's next?
Like I said above, currently the `Main.hs` file is a dummy wrapper. Another day, I might create a main procedure that allows the program to be compiled into an executable. In any case, I hope you enjoyed reading the post and thinking about groups!