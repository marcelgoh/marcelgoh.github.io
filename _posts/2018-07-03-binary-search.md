---
layout: post
title: The Error-proneness of Binary Search
date: 2018-07-03
published: true
excerpt_separator:  <!--more-->
---
Yesterday I started the [Algorithms, Part I](https://www.coursera.org/learn/algorithms-part1) course on Coursera, taught by Prof. Robert Sedgewick of Princeton University. In a lecture on algorithmic complexity he goes over the binary search algorithm and its advantages, while also warning the student that the algorithm is not necessarily trivial to implement. In the lecture slide, he claims that the first binary search was published in 1946, but the first bug-free one would not be published until 1962. Today I tried to implement the algorithm for the first time in MIT Scheme.  
<!--more-->

A [blog post](https://reprog.wordpress.com/2010/04/19/are-you-one-of-the-10-percent/) I found, written by Mike Taylor, talks about the error-proneness of binary search. In his post, which claims that 90% of programmers write faulty versions of binary search, he challenges the reader to implement the algorithm in the high-level language of his/her choice and to start testing only when sure of the program's correctness.  

So I tried to write out the program on paper without looking up any implementations of the algorithm beforehand (besides the Java one I briefly saw in Prof. Sedgewick's lecture earlier, which was iterative rather than recursive anyway). I did allow myself to have the Edwin Scheme interpreter open so I could check the syntax of certain primitive functions. After 44 minutes, this is what I came up with:  

[View the handwritten version (PDF)](/media/binary-search/binary-search.pdf)  

Because no one should be subjected to reading my handwriting, I have transcribed it here:  

{% highlight scheme %}
; returns index of item in list
(define (binary item list)
  ; returns element of list at index n
  (define (nth n list)
    (if (= n 0) (car list) (nth (- n 1) (cdr list))))
  ; returns sublist before index n
  (define (before n list)
    (if (= n 0) '() (cons (car list) 
                          (before (- n 1) (cdr list)))))
  ; returns sublist after index n
  (define (after n list)
    (if (= n 0) (cdr list) (after (- n 1) (cdr list))))
  ; add is offset from start of original list
  (define (search item list add)
    (let ((mid (floor (/ (length list) 2))))
      (cond ((null? list) false)
            ((= item (nth mid list))
             (+ add mid))
            ((< item (nth mid list))
             (search item (before mid list) add))
            ((> item (nth mid list))
             (search item (after mid list) (+ add mid 1))))))
  (search item list 0))
{% endhighlight %}

I actually finished it in 37 minutes but decided to take some extra time to "test" it on paper before trying it on my computer, which was lucky because I found three typos! (write-os?) In any case, my code seemed to pass every test I gave it in the interpreter, returning the 0-indexed location of `item` in `list` if it was present and false otherwise.  

But is it actually correct? In this [StackOverflow thread about the pitfalls of implementing binary search](https://stackoverflow.com/questions/504335/what-are-the-pitfalls-in-implementing-binary-search), the top answer enumerates some common errors programmers make (paraphrased in Scheme syntax):  

__1. It doesn't run in O(log n) time.__ And here my implementation already fails. First of all, my procedures `nth`, `before`, and `after` all run in linear time, because I have to recurse through the list to find the spot to return. Furthermore, my `search` procedure passes the list as an argument every time it loops (linear time), upping my time complexity to linearithmic.  
__2. It fails when__ `(length list)` __equals 0.__ Here my implementation works. Passing the empty list into my function simply returns false.  
__3. It gives a wrong answer.__ In the 15 minutes or so I spent testing my code, it seems to always return the correct index, so I'd like to say my code passes this test.  
__4. It causes an error if__ `item` __is less than the smallest element of the list.__ Here my code passes. `(binary 1 '(3 4 5))` returns false, as expected.  
__5. It causes an error if 'item' is greater than the largest element of the list.__ Here again my code passes. `(binary 7 '(2 4 6))` returns false.  

Although my implementation of binary search ended up being a failure, I found this exercise to be a good lesson nonetheless. In my effort to write good functional code, I forgot the entire point of the algorithm and created a version that actually runs slower than simply iterating though the list!
