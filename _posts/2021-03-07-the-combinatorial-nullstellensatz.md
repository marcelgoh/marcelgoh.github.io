---
layout: post
title: The combinatorial Nullstellensatz
date: 2021-03-07
published: true
mathjax: true
excerpt_separator:  <!--more-->
---

I haven't done a proper math blog post for awhile, and I've been meaning to learn more about the polynomial
method, so I thought I'd sit down and get to grips with the "combinatorial Nullstellensatz" (see Alon (1999)).
This was prompted when I realised that there were a couple of exercises in of Knuth's books (namely Volume 2
and Volume 4, Fascicle 5) that concern
the Nullstellensatz. (I'm working off a preliminary draft of _Mathematical Preliminaries Redux_ (MPR),
which was posted to Knuth's website before the book came out; it is no longer there because the book is now out!
I do not know if the exercises (and numbering) in my draft correspond to the exercises in the actual book.)
I must confess to having seen the proof of the Nullstellensatz before
in Tao and Vu's _Additive Combinatorics_ which I read (read: skimmed) about three months ago, but I have forgotten
it and so this post will see me trying to reconstruct it, with some hints from Knuth.
<!--more-->

### Proof of the theorem

Here is the statement we're trying to prove (exercise 114 of MPR):

__Theorem__ (The combinatorial Nullstellensatz). _Let $k$ be a field and let $f\in k[x_1,\ldots,x_n]$
be a polynomial such that the coefficient of $x_1^{d_1}\cdots x_n^{d_n}$ is nonzero and each term has degree
at most $d_1+\cdots +d_n$. If $S_1, \ldots, S_n$ are subsets of $k$ with $|S_j|>d_j$ for every $1\leq j\leq n$
and we pick $X_1,\ldots,X_n$ uniformly (and independently) at random respectively from $S_1,\ldots,S_n$, then_

$${\bf P}\big\{ f(X_1,\ldots,X_n) \neq0\big\}
\geq {(|S_1|-d_1) + \cdots + (|S_n|-d_n) - n+1\over|S_1|\cdots|S_n|}.$$

This probability is nonzero by our assumption on the sizes of the $S_j$ and indeed,
most applications of the Nullstellensatz simply use the existence of a single
non-root of $f$ in $S_1\times\cdots\times S_n$.
As a hint, Knuth says to consult exercise 4.6.1.-16, which is found in Volume 2. Reformulated in probabilistic
notation to match the notation used in the statement of the Nullstellensatz above, here is its statement and proof:

__Lemma.__ _Let $k$ be a field and fix a nonzero multivariate polynomial $f\in k[x_1,\ldots x_n]$. Suppose that
the degree of $f$ in the variable $x_j$ is at most $d_j$ and let $S_1,\ldots,S_n$ be subsets of $k$ with
$|S_j|\geq d_j$ for all $j$. Then if we sample $X_j$ uniformly (and independently) at random from each $S_j$,_

$${\bf P}\big\{ f(X_1, \ldots, X_n) \neq 0\big\} \geq {\prod_{j=1}^n (|S_j| - d_j)\over |S_1|\cdots|S_n|}.$$

_Proof._ We induce on $n$. When $n = 1$, a polynomial of degree $d_1$ can have at most $d_1$ roots, so there
are at least $|S_1| - d_1$ non-roots in the set $S_1$. Thus the probability of choosing a non-root is
at least $(|S_1| - d_1)/|S_1|$. Now let $n>1$ and suppose the lemma holds for $n-1$. Sample $X_1, \ldots, X_{n-1}$
and note that if we let $g(x) = f(X_1,\ldots,X_{n-1},x)$, then there exist polynomials $f_0,\ldots,f_{d_n}\in
k[x_1,\ldots,x_{n-1}]$ such that

$$g(x) = f_0(X_1,\ldots,X_{n-1}) + x f_1(X_1,\ldots,X_{n-1}) + \cdots + {x}^{d^n}
f_{d_n}(X_1,\ldots,X_{n-1}),$$

with some $i$ such that $f_i$ not identically zero. By the induction hypothesis, we have

$${\bf P}\big\{ f_i(X_1, \ldots, X_{n-1}) \neq 0\big\}\geq{\prod_{j=1}^{n-1} (|S_j|-d_j)\over|S_1|\cdots|S_{n-1}|},$$

meaning that $g(x)$ is a nonzero univariate polynomial with degree at most $d_n$. Thus it has at most $d_n$ roots and
sampling $X_n$ uniformly from $S_n$,
we conclude that

$${\bf P}\big\{g(x_n)\neq 0\big\} \geq {\bf P}\big\{ f_i(X_1, \ldots, X_{n-1})\big\} {|S_n| - d_n\over |S_n|}
\geq {\prod_{j=1}^n (|S_j| - d_j)\over |S_1|\cdots|S_n|}.$$

This completes the induction and proves the lemma.&nbsp;&nbsp;∎

The lemma above is a variant of the
[Schwartz-Zippel lemma](https://en.wikipedia.org/wiki/Schwartz–Zippel_lemma). (Knuth cites DeMillo and Lipton,
and indeed, Wikipedia says that this lemma was independently discovered around the same time by Schwartz, Zippel,
and DeMillo-Lipton; I have included all three references at the bottom of the post.)
It quantifies the intuitive fact that with $f$ fixed, as
the sizes of the $S_j$ increase, the probability of finding a root of $f$ when picking vectors
uniformly at random from $\prod_j S_j$ goes to 0. With this lemma in hand, we can now prove the Nullstellensatz.

_Proof of the Nullstellensatz assuming the lemma._ The main trouble is that the degree of $f$ in the variable $x_j$
is not $\leq d_j$; it is only guaranteed to be $\leq d_1 + \cdots + d_n$. However, note that the polynomial
$f_j(x) = \prod_{s\in S_j} (x-s)$, is of degree $|S_j|$ and is zero on all $s\in S_j$. So modifying $f$ by
replacing ${x_j}^{|S_j|}$ by ${x_j}^{|S_j|} - f_j(x_j)$ everywhere does not change its value on the set $S_j$.
After doing this for all $j$, the value of $f$ on $S_1\times\cdots\times S_n$ has not changed,
but the degree of $f$ in each variable $j$ is at most $|S_j| - 1$. Applying the lemma gives

$${\bf P}\big\{ f(X_1, \ldots, X_n) \neq0\big\} \geq {\prod_{j=1}^n (|S_j| - |S_j|+1)\over |S_1|\cdots|S_n|}
= {1\over|S_1|\cdots|S_n|}$$

and proves the theorem in the case that
$|S_j|= d_j+1$
for all $j$. (It also proves existence of a non-root in the general case.)

We need to increase this probability to match the theorem statement in the general case, where $|S_j| > d_j+1$
for at least some $j$.
From what we have already shown, we know that taking subsets $S_j'\subseteq S_j$ of size $|S_j| = d_j+1$
for all $j$, there is a non-root of $f$ in $S_1'\times\cdots\times S_n'$. We construct
a set $A$ of non-roots as follows. Pick any $S_1'\times\cdots\times S_n'$ with $|S_j'| = d_j+1$ for every $j$.
There is a non-root of $f$ in $S_1'\times\cdots\times S_n'$,
call it $(a_1,\ldots,a_n)$, so we add this non-root to $A$ and then replace $a_1$
with a new element of $S_1\setminus S_1'$. We can do this this $|S_1| - d_1 - 1$ times for the first coordinate,
and, in general, $|S_j|-d_j - 1$ times for the $j$th coordinate. After running out of new elements, we have placed
$(|S_1| - d_1) + \cdots + (|S_n| - d_n)-n$ distinct non-roots in $S_1\times \cdots\times S_n$ into $A$, and then we
add one more in the final iteration of the algorithm. The size of $A$ is enough to give us a lower
bound for the probability of choosing a non-root.&nbsp;&nbsp;∎

### Subgraphs of multigraphs

The next two exercises in MPR deal with applications of the Nullstellensatz. The first is an easy problem about covering
a discrete grid with lines, which we'll skip here. The second is a bit more complicated:

__Proposition.__ Let $p$ be a prime. Any multigraph on $n$ vertices with more than $(p-1)n$ edges contains a nonempty
subgraph in which the degree of every vertex is a multiple of $p$.

_Proof._ Let $G$ be a multigraph satisfying the hypotheses. We construct a polynomial $f$ over the finite field
on $p$ elements with a variable $x_e$ for every edge $e$ in the multigraph. For each vertex $v$ in the multigraph,
form a polynomial $f_v = \sum_{v\in e} x_e$, where $x_e$ is represented twice if $e$ is a loop from $v$ to itself.
Note that $f_v$ has degree no more than 1 in each variable. Let $x$ be a vector indexed by $e\in E(G)$.

$$f(x) = \prod_{v\in V(G)} (1-{f_v}(x)^{p-1}) - \prod_{e\in E(G)} (1-x_e).$$

The first term has degree $(p-1)n < |E(G)|$ and the second term has degree $|E(G)|$, so if we let $d_e =1$ for every
edge $e$, the whole polynomial has degree $|E(G)| = \sum_{e\in E} d_e$. The coefficient of $\prod_{e\in E(G)} x_e$
is $(-1)^{|E(G)|}$, which is nonzero, so letting $$S_e = \{0,1\}$$ for all $e$, by the combinatorial Nullstellensatz
there is a subset $E'$ of $E(G)$ such that setting
$x_e = 1$ for all $e\in E'$ and $x_e = 0$ otherwise, we have $f(x)\neq 0$. Let $G'$ be the subgraph of $G$ defined
by taking the same vertex set and the subset $E'$ of edges.

Note that $f_v(x)$ is the degree of the vertex $v$ in the subgraph $E'$, modulo $p$.
Picking none of the edges cannot be a solution, since then we would have $f(x) = 1 - 1 = 0$. Picking
even one edge causes the second term to be zero, and by Fermat's little theorem,
the first term is nonzero only when $f_v(x) = 0$ for all $v$,
meaning that the degree of each vertex $v$ in the nonempty subgraph is a multiple of $p$.&nbsp;&nbsp;∎

This exercise is related to a result of Alon, Friedland, and Kalai (1984).
Next we will present two classical theorems that can easily be proven using the Nullstellensatz; in fact,
Alon included both as examples in his original 1999 paper.

### The Cauchy-Davenport theorem

This theorem about sumsets is rather oddly named because A. Cauchy died in 1857 and H. Davenport was only born in 1907.
Given two subsets $A$ and $B$ of the finite field with $p$ elements (for a prime $p$), the _sumset_ $A+B$ is the
set of all elements of the form $a+b$, where $a\in A$ and $b\in B$. The Cauchy-Davenport theorem gives a lower
bound on the size of $A+B$:

__Theorem__ (Cauchy-Davenport). _Let $k={\bf F}_p$ be a finite field of prime order.
If $A$ and $B$ are two subsets of $k$, then_

$$|A+B| \geq \min\{p, |A|+|B|-1\}.$$

_Proof._ If $|A|+|B|>p$, then for every $s\in k$, the size of the set $$s-B = \{s - b: b\in B\}$$ has the same
size as $B$, so it must intersect $A$ in some element. This means that $s$ can be written as $a+b$ for some
$a\in A$ and $b\in B$; that is, $A+B = F$ and has size $p$. Now assume $|A|+|B|\leq p$ and let $C$ be any subset
of $k$ with size $|C| = |A|+|B|-2$. Let $f$ be the bivariate polynomial

$$f(x_1,x_2) = \prod_{c\in C} (x_1+x_2-c).$$

Let $d_1 = |A|-1$, $d_2 = |B|-1$, and note that the coefficient of ${x_1}^{d_1}{x_2}^{d_2}$ is, by the binomial
theorem, ${|A|+|B|-2\choose |A|-1}$, and this is nonzero modulo $p$, since $|A|+|B|-2 < p$. Taking $S_1 = A$
and $S_2 = B$ in the Nullstellensatz, we find that there must be some $a\in A$ and $b\in B$ such that

$$f(a,b) = \prod_{c\in C} (a+b-c) \neq 0,$$

implying that $a+b\notin C$. Since $C$ was an arbitrary set
of size $|A|+|B|-2$ and we found that $A+B\not\subseteq C$, this means that $|A+B|\geq |A|-|B|-1$.&nbsp;&nbsp;∎

### Chevalley's theorem

This theorem was proved by C. Chevalley in 1935, and strengthened the same year by E. Warning. The strong version
states that given a set of polynomials $$\{f_i\}$$ over a finite field $k$, if the number of variables is sufficiently
large in comparison to the degrees of the polynomials, the set of points $A$ on which every $f_i$ is zero must be
a multiple of ${\rm char}\,k$.
Chevalley's original formulation simply stated that if the set $A$ is nonempty, then it must
have at least two elements (which follows from the stronger version, since for a finite field $k$,
${\rm char}\,k\geq 2$). This is the version of the theorem we will state and prove.

__Theorem__ (Chevalley). _Let $k = {\bf F}_q$ be the finite field on $q$ elements, where $q$ is a prime power,
and let $f_1, \ldots, f_m$ be polynomials in $k[x_1,\ldots,x_n]$.
If $n > \deg f_1 + \cdots + \deg f_m$ and there exists a point $a = (a_1,\ldots,a_n) \in k^n$
such that $f_i(a) = 0$ for all $f_i$, then there is another point $a'\neq a$ such that $f_i(a') = 0$ for all $f_i$._

_Proof._ Let

$g(x_1, \ldots,x_n) = \prod_{i=1}^m (1-f_i(x_1,\ldots,x_n)^{q-1})\quad\hbox{and}\quad
h(x_1,\ldots,x_n) = \prod_{j=1}^n\prod_{s\in k\setminus\{a_j\}} (x_i - s),$

and let

$$ f(x_1, \ldots,x_n) = g(x_1,\ldots,x_n) - \lambda h(x_1,\ldots,x_n),$$

where $\lambda\in k$ is a scalar chosen such that $f(a) = 0$. Since $g(a) = 1$ and
and $h(a)\neq 0$, $\lambda\neq 0$ is exactly $h(a)^{-1}$.
The total degree of $f$ is $(q-1)n$, since $h$ has exactly this degree and $g$ has degree

$$(q-1)(\deg f_1 + \cdots + \deg f_m) < (q-1)n.$$

Let $d_i = q-1$ for all $1\leq i\leq n$ and note that the coefficient of $\prod_{i=1}^n {x_i}^{d_i}$
is $-\lambda\neq 0$. By the Nullstellensatz with $S_i$ set to the entire field for all $i$, we find that
there must be a point $a' = (a_1',\ldots, a_n')$ with $f(a')\neq 0$. Of course, $a'$ cannot equal $a$ since $f(a)=0$.
But since there exists $i$ for which $a_i' \neq a_i$, we must have $h(a') =0$. So $g(a')\neq 0$, meaning that
$f_i(a')$ is zero for all $i$, since any nonzero element of $k$ equals 1 when taken to the $(q-1)$st power.&nbsp;&nbsp;∎

### References

+ Noga Alon, "Combinatorial Nullstellensatz", _Combinatorics, Probability, and Computing_ __8__ (1999), 7-29.
+ Noga Alon, Shmuel Friedland, and Gil Kalai, "Regular subgraphs of almost regular graphs," _Journal of
Combinatorial Theory, Series B_ __37__ (1984), 79-91.
+ Richard A. DeMillo and Richard J. Lipton, "A probabilistic remark on algebraic program testing," _Information
Processing Letters_ __7__ (1978), 193-195.
+ Donald E. Knuth, _The Art of Computer Programming, Volume 2: Seminumerical Algorithms,_ (Addison-Wesley, 1969).
+ Donald E. Knuth, _The Art of Computer Programming, Volume 4, Fascicle 5:
Mathematical Preliminaries Redux; Introduction to Backtracking; Dancing Links_, (Addison-Wesley, 2019).
+ Jack Schwartz, "Fast probabilistic algorithms for verification of polynomial identities," _Journal of the ACM_
(1980), 701-717.
+ Terence Tao and Van Ha Vu, _Additive Combinatorics_ (Cambridge University Press, 2006).
+ Richard Zippel, "Probabilistic algorithms for sparse polynomials," _Lecture Notes in Computer Science_ __72__ (1979),
216-226.
