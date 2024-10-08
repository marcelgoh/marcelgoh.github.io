---
layout: post
title: The Kelley–Meka bounds in finite fields
date: 2024-06-07
published: false
mathjax: true
excerpt_separator:  <!--more-->
---

Let $A$ be a subset of an abelian group. A question that has motivated much of additive
combinatorics is, roughly, "How big can $A$ get before it must contain some arithmetic progression

$$a, a+r, a+r+r$$

for some $a$ and $r$ in the group?" In 1948 Behrend showed the existence of a constant $C$ such
that for all $N$, one can always find $A \subseteq [N] \subseteq {\bf Z}$ satisfying
$|A| \ge \exp(-C\sqrt{\log N}) N$ but not containing
a three-term arithmetic progression. It has been over seventy years since then and no upper bound has come close
to matching this lower bound, until last year, when Kelley and Meka showed there must exist $c$ such that
for all $N$ and $A\subseteq [N]$ with $|A| \ge \exp(-c(\log N)^{1/11}) N$, $A$
must contain a three-term arithmetic
progression. The exponent has subsequently been improved to $1/9$ by Bloom and Sisask.

I wanted to write up a fairly linear rendition of the proof, simplified to apply only to the
setting of finite fields. We will follow the exposition of Bloom and Sisask, but simplify proofs wherever
the generality is not needed for the finite-field case.

<!--more-->

### Definitions, notation, basic lemmas

We enumerate a number of basic facts and definitions; in this section no proofs shall be given, but the
results here are either well known or else easy to derive as an exercise.
Fix an integer $n$ and $q$ a power of an odd prime, then let $G = {\bf F}_q^n$.
For functions $f,g\to {\bf C}$ we have
the inner product

$$\langle f,g\rangle = {\bf E}_{x\in G} f(x) \overline{g(x)}$$

and the $L_p$ norm

$$ \Vert f\Vert_p = \Bigl( {\bf E}_{x\in G} |f(x)|^p\Bigr)^{1/p} $$

In $L_p$ spaces we have the Hölder inequality

$$ | \langle f,g\rangle | \le \Vert f\Vert_p \cdot \Vert g\Vert_q $$

for $p,q \ge 1$ with $1/p + 1/q = 1$. These norms are monotone in $p$; that is, if $p\le p'$, then
$\Vert f\Vert_p \le \Vert f\Vert_{p'}$ for any $f$.

If $f$ and $g$ are ${\bf R}$-valued, we define the _convolution_

$$ (f*g) (x) = {\bf E}_{y\in G} f(y) g(x-y) $$

and the _difference convolution_

$$ (f\circ g) (x) = {\bf E}_{y\in G} f(y) g(x+y) .$$

Verify that the $*$ operation is symmetric, but $(f\circ g)(x) = (g\circ f) (-x)$.

We also have the following adjoint property.

__Proposition 1__ (_Adjoint property_). _Let $f,g,h : G\to {\bf R}$. We have_

$$\langle f,g*h\rangle = \langle h\circ f, g\rangle.\ \hbox{▮}$$

Recall that the _dual group_ $\widehat G$ is defined to be the set of all homomorphisms from $G$ to
${\bf C}^\times$. Since $G$ is finite it's easy to see that every $\chi\in \widehat G$ is a homomorphism
to the unit circle, so $\overline{\chi(x)} = \chi(-x)$ for all $x\in G$.

The _Fourier transform_ of $f:G\to {\bf C}$ is the function $\widehat f : \widehat G\to {\bf C}$ given by

$$\widehat f (\chi) = \langle f, \chi\rangle = {\bf E}_{x\in G} f(x) \chi(-x).$$

From $\widehat f$ we can recover $f$ via Fourier inversion formula

$$f(x) = \sum_{\chi\in \widehat G} \widehat f(\chi)\chi(x).$$

The following proposition describes how the convolution and difference convolution behave under
the Fourier transform.

__Proposition 2__ (_Convolution laws_). _Let $f,g : G\to {\bf R}$. We have the identities_

1. $\widehat{f*g} = \widehat f \cdot \widehat g$ _and_
2.  $\widehat{f\circ g} = \overline{\widehat f} \cdot \widehat g$;

_in particular, $\widehat{f\circ f} = \vert\widehat f\vert^2$._ ▮

When we convolve two functions $\widehat f$ and $\widehat g$ on the dual group, we take a sum

$$(\widehat f * \widehat g) = \sum_{\psi\in G} \widehat f(\psi) \widehat g(\chi \psi^{-1})$$

instead of an expectation.
The same goes in the definition of an inner product $\langle \widehat f, \widehat g\rangle$.
This is to avoid having to write scaling factors of $|G|$ everywhere.

Let $f^{*k}$ denote the $k$-fold convolution of a function $f$. The next proposition interprets $k$-norms
in terms of $k$-fold convolutions of the Fourier transform. Here (and everywhere), let $\chi_0$ denote
the identity of $\widehat G$.

__Proposition 3.__ _For any integer $k\ge 1$ and any $f:G\to {\bf R}$,_

$${\bf E}_{x\in G} f(x)^k = {\widehat f}^{*k} (\chi_0).$$

For sets $A$ and $X$, let $\mu_X(A) = |A\cap X|/|X|$ denote the relative density of $A$ in $X$, and if
$X$ is understood to be part of a larger subset $G$, then we also use $\mu_X$ to denote
the normalised indicator function given by

$$\mu_X(x) =
\begin{cases}
1/\mu_G(X), & \hbox{if $x\in X$;} \cr
0, & \hbox{otherwise. ▮}
\end{cases}$$

(For the unnormalised indicator function we instead write ${\bf 1}_X = \mu_G(X) \mu_X$.)

The normalised indicator function is useful because
$\Vert \mu_X\Vert_1 = 1$, and of course
$\mu_X \ge 0$. The following proposition
concerns functions with these two properties.

__Proposition 4.__ *If
$\mu: G\to {\bf R}_{\ge 0}$
has $\Vert \mu\Vert_1 = 1$, then*

$$\widehat{\mu - 1} = \hat \mu(1-{\bf 1}_{\chi_0}). \hbox{▮}$$

Check also that if $\Vert \mu\Vert_1 = 1$, then the same is true of $\mu*\mu$ and $\mu\circ \mu$.

### Hölder lifting and unbalancing

We now give the first two lemmas that will be used in the proof below. If you cannot stand reading
lemmas and their proofs without first knowing how the lemmas will be used, you could skip ahead
to the last section, then jump back here.

__Lemma 5.__ (_Hölder lifting_). Let $A$ and $C$ be subsets of $G$, where $C$ has relative density $\gamma$.
Then at least one of the following two statements holds.

1. $\bigl\vert \langle \mu_A * \mu_A, \mu_C\rangle - 1\bigr\vert \le 1/2$.
2. $\Vert \mu_A\circ \mu_A - 1\Vert_p \ge 1/4$ for some $p = O(\log (1/\gamma))$.

_Proof._ Since inner products are linear in the first argument, we have

$$\langle \mu_A*\mu_A - 1, \mu_C\rangle = \langle \mu_A * \mu_A, \mu_C\rangle + \langle -1,\mu_C\rangle
= \langle \mu_A * \mu_A,\mu_C\rangle - 1.$$

So if the first statement above doesn't hold, then for $q = 1/(1-1/p)$, we have

$$\eqalign{
{1\over 2} &< \bigl| \langle \mu_A*\mu_A-1, \mu_C\rangle\bigr| \cr
&\le \Vert \mu_A*\mu_A\Vert_p \Bigl({\bf E}_{x\in G} |\mu_C(x)|^q\Bigr)^{1/q} \cr
&=\Vert \mu_A*\mu_A\Vert_p \biggl({1\over |G|} \sum_{x\in C} \gamma^{-q} \biggr)^{1/q} \cr
&= \Vert \mu_A*\mu_A\Vert_p (\gamma^{1-q})^{1/q} \cr
&= \Vert \mu_A*\mu_A\Vert_p \gamma^{1/q-1},\cr
}$$

where in the second line we used the Hölder inequality. Let $p$ be an even integer
greater than $\log_2(1/\gamma)$, so that $\log \gamma \ge p\log (1/2)$, whence
$\gamma^{1/p} \ge 1/2$. Substituting this in above yields

$$\Vert \mu_A*\mu_A - 1\Vert_p \ge {1\over 4},$$

which is almost what we want. (The $*$ needs to become a $\circ$.)

Since $p$ is even, we can apply Proposition 3 to get

$$\Vert \mu_A*\mu_A-1\Vert_p^p
= {\bf E}_{x\in G} \bigl( (\mu_A*\mu_A)(x) - 1\bigr)^p
= (\widehat{\mu_A*\mu_A-1})^{*p}(\chi_0).$$

We observed earlier that
$ \Vert\mu_A\ast\mu_A\Vert_1 = 1$, so
$\widehat{\mu_A\ast\mu_A -1} = \widehat{\mu_A\ast\mu_A}(1-{\bf 1}_{\chi_0})$ by Proposition
4, and by the convolution law,

$$\Vert\mu_A\ast\mu_A -1\Vert_p^p = \widehat{\mu_A\ast\mu_A}(1-{\bf 1}_{\chi_0})(\chi_0)
= \bigl( \widehat{\mu_A}^2(1-{\bf 1}_{\chi_0})\bigr)^{*p}(\chi_0).$$

Repeating the whole process with $\mu_A\circ\mu_A$ in place of $\mu_A*\mu_A$, we use the other
convolution law in the last step to obtain the very similar identity

$$\Vert\mu_A\circ\mu_A -1\Vert_p^p
= \bigl( \widehat{|\mu_A|}^2(1-{\bf 1}_{\chi_0})\bigr)^{*p}(\chi_0).$$

Hence $\Vert\mu_A\circ\mu_A -1\Vert_p \ge \Vert\mu_A\ast\mu_A -1\Vert_p \ge 1/4$
and we are done. ▮

This lemma tells us that if $\langle \mu_A*\mu_A, \mu_C\rangle \ge 1/2$, then
$\Vert \mu_A\circ\mu_A- 1\Vert_p \ge 1/4$ for some $p = O(\log (1/\gamma))$.
Since $\mu_A\circ\mu_A$ has nonnegative Fourier transform, we can feed the conclusion of this lemma
to the following one.

__Lemma 6.__ (_Unbalancing of spectrally nonnegative functions_). Let $\eps \in (0,1)$ and
let $

### References

+ F. Behrend. "On sets of integers which contain no three terms in arithmetic progression," _Proceedings
of the Natural Academy of Sciences_ __32__ (1946), 331–332.
+ T. F. Bloom and O. Sisask, "The Kelley–Meka bounds for sets free of three-term arithmetic progressions,"
_Essential Number Theory_ __2__ (2023), 15–44.
+ T. F. Bloom and O. Sisask, "An improvement to the Kelley–Meka bounds on three-term arithmetic progressions,"
_arXiv:2309.02353_ (2023), 9 pp.
+ Z. Kelley and R. Meka, "Strong Bounds for 3-Progressions," _IEEE 64th
  Annual Symposium on Foundations of Computer Science (FOCS)_ (2023), 933-973.

