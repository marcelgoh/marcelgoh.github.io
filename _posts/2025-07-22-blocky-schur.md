---
layout: post
title: Blocky matrices and idempotent Schur multipliers
date: 2025-07-22
published: true
mathjax: true
excerpt_separator:  <!--more-->
---

My supervisor [Hamed Hatami](https://www.cs.mcgill.ca/~hatami/) and I have just uploaded to the arXiv
two new preprints: "[Block complexity and idempotent Schur multipliers](https://arxiv.org/pdf/2506.21752)" and
"[Block structure in Boolean matrices with bounded factorization norm](https://arxiv.org/abs/2507.00872)".
These papers are strongly related, and this blog post I'll introduce their common background before discussing
what have recently we managed to prove.

<!--more-->

### Cohen's idempotent theorem

We begin with some
background on Cohen's celebrated idempotent theorem, which we import (in abbreviated form)
from Chapter 3 of Rudin's 1962 book _Fourier Analysis on Groups_.

Let $G$ be a locally compact abelian group. The set of all measures $\mu$ on $G$ forms a topological
semigroup under convolution, and we shall say that a measure $\mu$ is _idempotent_ if $\mu * \mu = \mu$.
By Parseval's identity, we have $\widehat\mu^2 = \widehat\mu$, so $\widehat\mu(a) = 1$ or $\widehat\mu(a) = 0$
for all $\gamma$ in the dual group $\Gamma$ of $G$, and to $\mu$ we can identify the set

$$S(\mu) = \{ \gamma\in \Gamma: \widehat\mu(\gamma) = 1\}.$$

Let $\Lambda$ be an open subgroup of $\Gamma$. Let $H$ be the annihilator subgroup

$$H = \{ x\in G : \gamma(x) = 1\ \hbox{for all}\ \gamma\in \Lambda\}$$

of $\Lambda$. It can be shown that $H$ must be compact (since $\Lambda$ is open), and we can normalise
the Haar measure $m_H$ on $H$ so that $m_H(H) = 1$, which yields a measure on $G$ as well. By orthogonality,
we have $\widehat{m_H}(\gamma) = 1$ for all $\gamma\in \Lambda$ and
$\widehat{m_H}(\gamma) = 0$ for all $\gamma\notin \Lambda$,
so $S(m_H) = \Lambda$.
Likewise, if $E = \Lambda + \gamma_0$, then $E = S(\mu)$ for the measure $\mu$ on $G$ with
$d\mu(x) = \gamma_0(x)\;dm_H$. We have shown that every open coset of $G$ is equal to $S(\mu)$
for some idempotent measure on $G$.

Note that if $\mu$ and $\nu$ are idempotent measures, then so are $\mu* \nu$, $\mu \vee \nu = \mu+\nu - \mu* \nu$,
and $\delta_0 - \mu$, where $\delta_0$ is the point measure of norm $1$ concentrated at the point $0\in G$.
We have

$$S(\mu * \nu) = S(\mu) \cap S(\nu), \qquad S(\mu \vee \nu) = S(\mu)\cup S(\nu),$$

and $S(\delta_0 - \mu)$ is the complement of $S(\mu)$. Let $\Omega$ be the set of all $S(\mu)$, where $\mu$
is an idempotent measure on $G$. We saw earlier that all open cosets of $\Gamma$ are in $\Omega$, so
now we know that all finite intersections, unions, and complements of
open cosets are in $\Omega$. Cohen's idempotent theorem states that this is it.

__Theorem C__ (_Cohen,_ 1960). _Let $G$ be a locally compact abelian group and let $\Gamma$ be its dual group.
A subset $E$ of $\Gamma$ is equal to $S(\mu)$ for some idempotent measure $\mu$ on $G$ if and only if
$E$ can be (finitely) expressed in terms of open cosets using the intersection, union, and complement operators._

### The Green--Sanders theorem

We now discuss a 2008 theorem of Green and Sanders. A good starting point is to think about what Cohen's
theorem means for finite groups. It is easy to see that, while obviously still true, Cohen's theorem
offers no content here, since now $\Gamma$ is finite and any subset $E$ in it can obviously be expressed
as a finite union of cosets of $$\{0\}$$. So instead of characterising subsets that can be finitely expressed
in terms of cosets, we should perhaps try to characterise subsets that can be thus expressed with
a _small number_ of terms.

Before, we were working with subsets of $\Gamma$, but in the finite case,
subsets of $\Gamma$ can really be interpreted as subsets of $G$, and we can regard any subset of $G$
as a boolean function $$f : G\to \{0,1\}$$. Then it makes sense to define the _Fourier algebra norm_

$$\Vert f\Vert_A = \sum_{\gamma\in \Gamma} |\hat f(\gamma)|$$

of $f$. Since $\Vert fg\Vert_A\le \Vert f\Vert_A \cdot \Vert g\Vert_A$, the set of boolean functions is
a Banach algebra under addition and pointwise product.
It was shown by Kawada and Itô in 1940 that $\Vert f\Vert_A \le 1$ if and only if $f$ is
the indicator function of a coset. So we see that (subsets corresponding to)
functions with algebra norm at most $1$ are exactly cosets of $G$. The Green--Sanders theorem
extends this to functions with $\Vert f\Vert_A \le M$ for $M\ge 1$.

__Theorem G__ (_Green--Sanders,_ 2008). _Let $G$ be a finite abelian group and let
$$f : G\to \{0,1\}$$ be a boolean function with $\Vert f\Vert_A \le M$. Then $f$ can be expressed
as the signed sum

$$f = \sum_{i=1}^L \pm{\bf 1}_{E_i},$$

where the $E_i$ are cosets of $G$ and $L$ depends only on $M$._

In other words, the Theorem&nbsp;G tells us that in some quantitative sense, the subsets of
$G$ that can be expressed in terms of a small number of cosets are those with small Fourier algebra norm.

### Schur multipliers

In our papers, we investigate an analogue of Cohen's idempotent theorem in the algebra of Schur multipliers,
which we now introduce.

Let $l_2$ denote the Hilbert space of all square-summable complex sequences, and let $B(l_2)$ be the
space of bounded linear operators, equipped with the operator norm

$$\Vert A\Vert_{\rm op} = \sup_{y\ne 0} {\Vert Ay\Vert_2 \over \Vert y\Vert_2}.$$

Every operator $A\in B(l_2)$ is uniquely identified by its associated matrix
$$(a_{i,j})_{i,j\in {\bf N}}$$
, where $$a_{i,j} = \langle Ae_i, e_j\rangle$$ for the standard
orthonormal basis $$\{e_i\}_{i\in {\bf N}}$$ of $l_2$.
Each matrix $${\bf N}\times {\bf N}\to {\bf C}$$ gives rise to a linear transformation on the space
of all matrices $$A : {\bf N}\times {\bf N} \to {\bf C}$$ by mapping $A \mapsto M\circ A$, where
$\circ$ denotes the entrywise (Schur) product. The matrix $M$ is called a _Schur multiplier_
if $M\circ A\in B(l_2)$ for every $A\in B(l_2)$. Equivalently, $M$ is a Schur multiplier
if its _Schur multiplier norm_, defined by

$$\Vert A\Vert_{\rm m} = \sup_{y\ne 0} {\Vert Ay\Vert_{\rm op} \over \Vert y\Vert_{\rm op}},$$

is finite. The set of Schur multipliers is closed under addition and Schur product, and thus forms a
Banach algebra.

An element of an algebra is said to be _idempotent_ if $a^2 = a$. Any matrix satisfying
$M\circ M = M$ must be boolean, but not all infinite boolean matrices are Schur multipliers.
The boolean matrix $M$ corresponds to the operation that maps a matrix $A$ to a new matrix
that agrees with $A$ everywhere $M$ equals $1$, and is $0$ everywhere $M$ is $0$.
This is the natural question that our papers investigate: _What are the idempotent elements of the Schur
multiplier algebra?_

### Contractive idempotents and block complexity

As we did before with the Fourier algebra norm,
we now characterise the _contractive_ idempotent elements, that is, those
with Schur multiplier norm at most $1$. We call a boolean matrix $B$ _blocky_ if there exist families
$$\{S_i\}_{i\in {\bf N}}$$ and $$\{T_i\}_{i\in {\bf N}}$$ of pairwise disjoint subsets of ${\bf N}$ such that
the support of $B$ is exactly $$\bigcup_{i\in {\bf N}} S_i\times T_i$$. Simple examples of blocky
matrices are the zero matrix, $m\times n$ all-ones matrices, and $n\times n$ identity matrices.
The following proposition of Livshits shows that set of contractive idempotent Schur multipliers
is exactly the set of blocky matrices.

__Proposition L__ (_Livshits_, 1995). _A boolean matrix satisfies $\Vert A\Vert_{\rm m} \le 1$
if and only if it is a blocky matrix. (More precisely,
a _nonzero_ boolean matrix satisfies $\Vert A\Vert_{\rm m} = 1$ if and only if it is blocky.)_

In the same way that Cohen's idempotent theorem shows that any idempotent element of the Fourier
algebra can be written as a finite sum of contractive idempotents, it is an open problem, dating
back to at least 2005, whether any idempotent Schur multiplier can be written as a finite sum
of contractive idempotents. A straightforward compactness argument of Hambardzumyan, Hatami, and Hatami
shows that a positive resolution to this problem, while only being meaningful for infinite matrices,
is equivalent to the following conjecture for finite matrices.

__Conjecture H__ (_Hambardzumyan--Hatami--Hatami,_ 2023). _Suppose that $A$ is a finite boolean matrix
with $\Vert A\Vert_{\rm m} \le \gamma$. Then we may express $A$ as the signed sum_

$$A = \sum_{i=1}^L \pm B_i,$$

_where the $B_i$ are blocky matrices and $L$ depends only on $\gamma$._

Given a finite group and
a boolean function, define the matrix $M_f : G\times G\to {\bf C}$ by setting
$M_f(x,y) = f(y^{-1} x)$. We have $\Vert M_f\Vert_{\rm m} = \Vert f\Vert_A$, so Theorem&nbsp;G
(along with its subsequent extension of Sanders to nonabelian groups)
shows that Conjecture&nbsp;H is true for this special case of boolean matrices.

We define the _block complexity_ ${\rm block}(A)$ of an $m\times n$ (integer) matrix $A$ to be
the smallest integer $A$ such that there exist blocky matrices $B_1,\ldots, B_l$ and signs
$\sigma_1,\ldots,\sigma_L$ such that $A = \sum_{i=1}^L \sigma_iB_i$. It is immediate from the
definition of block complexity (as well as Proposition&nbsp;L and the triangle inequality)
that $\Vert A\Vert_{\rm m} \le {\rm block}(A)$. Conjecture&nbsp;H claims that, conversely
the block complexity can be bounded by a function of the Schur multiplier norm.

In the first of our new preprints, Hamed and I proved that the any boolean matrix with bounded
Schur multiplier norm has block complexity at most polylogarithmic in its dimension.

__Theorem P__ (_G.--Hatami_, 2025). Let $A$ be an $m\times n$ integer matrix with
$\Vert A\Vert_{\rm m}\le \gamma$. Denoting $$k= \min\{m,n\}$$, the block complexity of $A$ satisfies

$${\rm block}(A) \le 2^{O(\gamma^7)} \log(k)^2.$$

Our proof of this result bears some resemblance to Green and Sanders' proof for boolean functions.
One important similarity is that its induction step partitions the matrix and takes averages within
the individual partitions, so we must consider real-valued matrices (and, in particular, we employ
the definition of _almost integer-valued matrix_ in much the same way that Green and Sanders work with
almost integer-valued functions).
Another notion we use in our proof is that of the Littlestone dimension of a (sign) matrix,
and we develop a weighted generalisation of this parameter for real matrices.

### Monochromatic rectangles and block substructure

It should be noted that we mostly work with the _$\gamma_2$ norm_ or _factorisation norm_, which
is defined to be
$$\Vert A\Vert_{\gamma_2} = \min_{UV=A} \Vert U\Vert_{\rm row} \Vert V\Vert_{\rm col},$$
where the minimum is taken over all factorisations $A = UV$ of $A$, $\Vert U\Vert_{\rm row}$
is the maximum $l_2$-norm of any row in $U$, and $\Vert V\Vert_{\rm col}$ is the maximum
$l_2$-norm of any column in $V$. It is a result of Grothendieck (proved in 1954)
that the Schur multiplier norm of any matrix equals its factorisation norm.

If Conjecture&nbsp;H is true, then for any boolean matrix $A$ of bounded factorisation norm,
one should expect to find a large block inside $A$ that either comprised entirely of $1$s or entirely
of $0$s. In other words, there should be a large _monochromatic rectangle_ in $A$. This is exactly
what Balla, Hambardzumyan, and Tomon showed in a very recent preprint.

__Theorem B__ (_Balla--Hambardzumyan--Tomon,_ 2025). _Suppose that $A$ is an $m\times n$ boolean
matrix with $$\Vert A\Vert_{\gamma_2} \le \gamma$$. There is a monochromatic rectangle $S\times T$
in $A$, where $S\subseteq [m]$ and $T\subseteq[n]$ satisfy_

$${|S|\times |T|\over mn} \ge 2^{-O(\gamma^2)}.$$

_Specifically, if more than half of $A$'s entries are $1$, then $S\times T$ is a rectangle of $1$s,
and otherwise it is a rectangle of $0$s._

The density of $A$ determines whether this theorem furnishes a rectangle of $0$s or a rectangle of $1$s.
Thus, given a sparse blocky matrix such as the identity matrix, the theorem simply identifies a large
$0$-rectangle and we gain little information regarding a purported blocky decomposition of $A$.
The main theorem of our second preprint, whose proof relies on Theorem&nbsp;B above, shows that
in any boolean matrix of bounded $$\gamma_2$$ norm, one can pick out a constant fraction of the $1$-entries
to form a blocky matrix.

__Theorem S__ (_G.--Hatami_, 2025). Let $A$ be an $m\times n$ boolean matrix $A$ with
$$\Vert A\Vert_{\gamma_2}\le \gamma$$ in which the number of $1$-entries is $F$. There exists an $m\times n$
blocky matrix $B$ containing at least $F/2^{2^{O(\gamma)}}$ entries, such that, for all $(i,j)\in [m]\times[n]$,
$B(i,j) = 1$ only if $A(i,j) = 1$.

To compare our theorem to Theorem&nbsp;B, it is perhaps illuminating to narrow our focus to the case
where $$A(x,y) = f(x-y)$$ for some boolean function $$f:{\bf Z}_2^n \to \{0,1\}$$, where
$$\Vert A\Vert_{\gamma_2} = \Vert f\Vert_A \le \gamma$$. (This is the abelian case of the construction above,
with $A = M_f$.) In this setting, a 2017 theorem of Shpilka, Tal, and Volk states that there must exist
some affine subspace $V \subseteq {\bf Z}_2^n$ of codimension at most $\gamma^2$ such that $f$ is constant
on $V$. One can view Theorem&nbsp;B as an analogue of this theorem, as it guarantees the existence of
a large submatrix on which the matrix is constant.

On the other hand, Theorem&nbsp;G implies that $f$ must be identically equal to $1$ on an affine
subspace $V\subseteq {\bf Z}_2^n$ whose size is at least a constant fraction (depending on $\gamma$)
of the support of $f$. Theorem&nbsp;S can be viewed as the matrix analogue of this latter statement.

Our proof of Theorem&nbsp;S uses the notion of the threshold dimension of a matrix, a well-known parameter
closely connected with the ideas of stability in model theory.

### References

+ Igor Balla, Lianna Hambardzumyan, and István Tomon, "Factorization norms and an inverse theorem
for MaxCut," _arXiv:2506.23989_ (2025), 23&nbsp;pp.
+ Paul Joseph Cohen, "On a conjecture of Littlewood and idempotent measures,"
_American Journal of Mathematics_ __82__ (1960), 191--212.
+ Ben Green and Tom Sanders,
"Boolean functions with small spectral norm," _Geometric and Functional Analysis_ *18* (2008), 144--162].
+ Alexander Grothendieck, "Résumé des résultats essentiels dans la théorie des produits tensoriels
topologiques et des espaces nucléaires," _Annales de l'institut Fourier_ __4__ (1954), 73--112.
+ Lianna Hambardzumyan, Hamed Hatami, and Pooya Hatami, "Dimension-free bounds and structural
results in communication complexity" _Israel Journal of Mathematics_ __253__ (2023), 555--616.
+ Leo Livshits, "A note on 0-1 Schur multipliers," _Linear Algebra and its Applications_ __222__
(1995), 15--22.
+ Yukiyosi Kawada and Kiyosi Itô, "On the probability distribution on a compact group. I,"
_Proceedings of the Physico-Mathematical Society of Japan_ __22__ (1940), 977--998
+ Walter Rudin,
_Fourier Analysis on Groups_ (New York: Dover Publications, 2017).
+ Amir Shpilka, Avishay Tal, and Ben Lee Volk, "On the structure of boolean functions with
small spectral norm," _Computational Complexity_ __26__ (2017), 229--273.



