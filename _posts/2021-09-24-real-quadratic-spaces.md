---
layout: post
title: Orthogonal groups of four-dimensional real quadratic spaces
date: 2021-09-24
published: true
mathjax: true
excerpt_separator:  <!--more-->
---

I'm taking a class on quadratic forms, orthogonal groups, and modular forms this semester, and
the class is formatted such that students present extended solutions to exercises in pairs on a rotating
basis. Well, this week it is my turn to present a description of four dimensional real quadratic spaces
over ${\bf R}$, along with my comrade [Jad Hamdan](https://jadhamdan.github.io/).
Neither
Jad nor I had had any exposure to Lie groups before this week, so we worked out the following with
a great deal of guidance from the instructor of the course, Prof. Henri Darmon.
I'm writing this blog post to organise and collect my thoughts before the actual presentation. I'll go
ahead and assume a level of mathematical background equal to my own before the class started, namely,
an undergraduate understanding of group theory, linear algebra, and topology
but no experience with differential geometry or topological groups.
<!--more-->

### Quadratic forms

We start with some basic facts about quadratic forms. These were given in class, but can also be found
in many textbooks (see, e.g., Chapter IV of Serre (1973)).
For a vector space $V$ over a field $k$ of characteristic not equal to $2$,
a _quadratic form_ is a function $Q:V\to k$ such that

1. $Q(\lambda v) = \lambda^2 Q(v)$ for all $\lambda \in k$ and $v\in V$; and
2. the function $Q(x+y) - Q(x) - Q(y)$ is bilinear.

We let $x\cdot y = (Q(x+y) - Q(x) - Q(y))/2$ and note that $x\cdot x = Q(x)$ for all $x$.
The pair $(V,Q)$ is called a _quadratic space_, and for the remainder of this post we will look at
the case $k={\bf R}$. We assume that $V$ is _nondegenerate_, i.e., if $v\in V$ is such that $v\cdot w$
for all $w\in V$, then $v=0$. In this case, $({\bf R}, Q)$ has an orthogonal basis
$$e_1, \ldots, e_r, e_{r+1}, \ldots, e_{r+s}$$ with $e_i\cdot e_i= 1$ for $1\le i\le r$ and $e_i\cdot e_i=-1$
for $r+1\le i\le r+s$. The pair $(r,s)$ is called the _signature_ of the quadratic space. Since we can always
multiply every element in the basis by $-1$, we assume that $r\ge s$.

### Orthogonal groups

The orthogonal group ${\rm O}(V)$ of a quadratic space $V$ over $R$ is the of linear transformations that
preserve the dot product; that is,

$$ {\rm O}(V) = \{ g\in {\rm Aut}(V) : gv \cdot gw = v\cdot w\ \hbox{for all}\ v,w\in V\}$$

Letting $n=\dim V$ and letting $(r,s)$ be the signature of the space, this
can be viewed as the set of $n\times n$ matrices

$$ {\rm O}(V) =
\biggl\{ A \in M_n({\bf R}) : A^{\rm T} A = AA^{\rm T} = \pmatrix{ I_r & 0\cr 0 & -I_s } \biggr\},$$

where the $I_r$ and $I_s$ that appear in the block matrix are the $r\times r$ and $s\times s$ identity matrices,
respectively. The condition implies that $(\det A)^2 = 1$, meaning that $\det A = \pm 1$ for all $A\in {\rm O}(V)$.
The subgroup of $A\in {\rm O}(V)$ with $\det A = 1$ is called ${\rm SO}(V)$.
It was proven in class (by a standard inductive argument), that ${\rm O}(V)$ is a real manifold
of dimension $n(n-1)/2$, and so is the subgroup ${\rm SO}(V)$.

The problem we shall tackle in this post is the following:

__Exercise.__ _Let $V$ be a four-dimensional real quadratic space. Describe the connected component of
the identity in each of the three cases $(r,s) = (4,0)$, $(r,s) = (3,1)$, and $(r,s) = (2,2)$._

We were also asked to count how many
connected components the whole group ${\rm O}(V)$ has. The number of components is $2$ when $(r,s) = (4,0)$
and $4$ in the other two cases, but the proof is of a rather different flavour than the characterisation
of the identity component and we won't go into it here.

### Quaternions

To deal with the case $(r,s) = (4,0)$, we will need to recall the definition of the quaternions. The _Hamilton
quaternions_ are members of the set ${\bf H} = {\bf R} + {\bf R}i + {\bf R}j + {\bf R}k$ where we impose
the relation $i^2 = j^2 = k^2 = ijk = -1$. (Since the field we're working in is always ${\bf R}$, we allow
the letter $k$ to be used for the third imaginary unit.) If $a = x+yi + zj + wk$ then the _conjugate_
of $a$ is $\overline a = x-yi-zj-wk$ and the _norm_ of $a$ is

$$N(a) = a\overline a = \overline a a=x^2+y^2+z^2+w^2.$$

We see from this that every nonzero element of $a$ has a multiplicative inverse, namely $a^{-1} = \overline
a /N(a)$, with $N(a^{-1}) = N(a)^{-1}$. Hence ${\bf H}^\times = {\bf H}/setminus \{0\}$.
Lastly, we define the _trace_ of $a$ to be its real coordinate
given by the formula ${\rm tr}(a) = (a+\overline a)/2$.

### The case $(r,s) = (4,0)$

This is the situation we're most familiar with, when the dot product of a vector $(x,y,z,w)$ with itself
is given by $Q(x,y,z,w) = x^2+y^2+z^2+w^2$. Here we can identify $(V,Q)$ with $({\bf H}, N)$. Note
that the group ${\bf H}^\times \times {\bf H}^\times$ defines a group action $\star$ on $V$ by
setting $(g,h)\star v = gvh^{-1}$. The norm of $(g,h)\star v = N(g)N(h^{-1})N(v)$, so for an element $(g,h)$ to
preserve the norm, it is necessary and sufficient that $N(g) = N(h)$. We can also assume that $g$ and
$h$ have norm $1$, since if $\lambda = N(g) = N(h)$, then $g = \lambda g'$ and $h=\lambda h'$ for some
unit quaternions $g'$ and $h'$ and

$$(g,h)\star v=(\lambda g',\lambda h')\star v = \lambda g' v \lambda^{-1}h'^{-1} = g'vh'^{-1} = (g',h')\star v.$$

In particular, if $g$ and $h$ are both real, then $(g,h)$ sends any $v\in V$ to itself.
Thus, letting ${\bf H}_1$ denote the set of quaternions with norm $1$, we have the exact sequence

$$ 1 \to \{(-1,-1), (1,1)\} \to {\bf H}_1\times {\bf H}_1 \buildrel\phi\over\to {\rm O}(V).$$

Note that the last map $\phi$ in the sequence is not surjective. Indeed, ${\bf H}_1$ is isomorphic to the
$3$-sphere $S^3$, which is compact and connected, so its image under $\phi$ must be as well. But ${\rm O}(V)$
is not connected, because the inverse images of $(1/2,3/2)$ and $(-3/2,-1/2)$ under the continuous map
$\det : {\rm O}(V) \to {\bf R}$ are disjoint open sets whose union is the whole domain. In fact, the image
of $\phi$ is contained in ${\rm SO}(V)$, since if we interpret the action of
$(g,h) = (a_1 + a_2 i + a_3 j + a_4 k, b_1 + b_2 i + b_3 j + b_4 k)$ on a quaternion $v$, viewed as a vector in
${\bf R}^4$, the matrix of the transformation is $AB$, where

$$ A = \pmatrix {
a_1 & -a_2 & -a_3 & -a_4 \cr
a_2 & a_1 & -a_4 & a_3 \cr
a_3 & a_4 & a_1 & -a_2 \cr
a_4 & -a_3 & a_2 & a_1 \cr
}\qquad\hbox{and}\qquad
B = \pmatrix {
b_1 & -b_2 & -b_3 & -b_4 \cr
b_2 &  b_1 &  b_4 & -b_3 \cr
b_3 & -b_4 &  b_1 &  b_2 \cr
b_4 &  b_3 & -b_2 &  b_1 \cr
}$$

We have $AA^{\rm T} = I$ and $BB^{\rm T} = I$ so $(AB)(AB)^{\rm T} = I$, as prescribed for a member of
${\rm O}(V)$. But we can also see that $\det A = N(g) = 1 = N(h) = \det B$, so that $\det(AB) = 1$ as well.
It remains to show that $\phi$ is surjective.

### Infinitesimals and the tangent space

We pause here to talk about the _tangent space_ of a group at the identity. We will restrict ourselves to
the case where the group is a subgroup of the group of invertible elements
in a unital associative algebra over ${\bf R}$,
and we will stay somewhat informal and heuristic.
The tangent space of such a topological group $M$ at the multiplicative identity $1$ is the space of all
directions one can take to pass through
$1$. In one-dimensional real calculus, we approximated a tangent line at a point $p$ by secant lines passing
through $p$ and $q$ as $|p-q|\to 0$, and here we'll do the same thing. Let $M$ be a topological group that is
also a subgroup of the multiplicative group of an algebra $A$. The tangent space $T_1 M$
at the point $1$
is the space of all $a\in A$ such that $1 + \epsilon a$ is still in $M$, and here
we encapsulate the fact that $\epsilon$ goes to zero by letting
$\epsilon$ be a nonzero formal parameter whose square is zero.
The tangent space is closed under addition, since if $a$ and $b$ are elements of $T_1 M$, then

$$ (1+\epsilon a)(1+\epsilon b) = 1 + \epsilon a + \epsilon b + \epsilon^2 ab = 1+\epsilon(a+b) $$

and we see that $a+b$ is also in the space.
It is also clear that $T_p M$ is closed under multiplication by scalars in the field, so that $T_pM$ is a real
vector space. The tangent space of a point $(p,q)\in M\times N$ is the product of spaces $T_pM\times T_q N$.

Let $M$ and $N$ be two such groups with identities $$1_M$$ and $$1_N$$ respectively and let
$\phi : M\to N$ be a group homomorphism. We define the _differential_ $d\phi$ to be the map
from $$T_{1_M} M$$ to $$T_{1_N} N$$ such that the diagram

$$\matrix{
T_{1_M} M & \buildrel d\phi\over\longrightarrow & T_{1_N} N \cr
\quad\Big\downarrow\pi_N & & \quad\Big\downarrow\pi_N \cr
M & \buildrel \phi\over\longrightarrow & N \cr
}$$

commutes, where $$\pi_M(a) = 1_M +\epsilon a$$ and $$\pi_N(b) = 1_N + \epsilon b$$. The commutativity of the
above diagram tells us that $d\phi(a)$ is given by the formula $$1_N + \epsilon d\phi(a) = \phi(1_M+\epsilon a)$$
for $a\in T_{1_M} M$.


### Surjectivity of $\phi$ on the identity component

The tangent spaces are relevant because the inverse function theorem in
calculus tells us that if $\phi : {\bf R}^n\to{\bf R}^n$
is a differentiable map and its derivative (Jacobian) at a point $x$ is invertible, then there exists an
open neighbourhood $U$ of $x$ that is homeomorphic to its image $\phi(U)$. If $\phi$ is also a group homomorphism,
then we have the following lemma.

__Lemma.__ _Let $\phi:G\to H$ be a homomorphism of topological groups and suppose that there is an open
neighbourhood $S\subseteq \phi(G)$ that contains the identity of $H$. If $G$ is connected, then $\phi(G)$
is the connected component of the identity in $H$._

_Proof._ Since the function $h\mapsto h^{-1}$ is a continuous involution, $S^{-1}$ is also open and so
is $S\cap S^{-1}$, which still contains the identity.
Thus we may assume without loss of generality that $S$ is closed under inverses.
Let $\langle S\rangle$ be the smallest subgroup of $\phi(G)$ with $S\subseteq \langle S\rangle$.
It is easy to see that
$$\langle S\rangle = \bigcup_{h\in \langle S\rangle} hS$$.
For all $h\in \phi(G)$, left multiplication by $h$ is a homeomorphism from $\phi(G)$ to itself, so $\langle S
\rangle$ is open.

It remains to show that $\langle S\rangle$ is closed, so let $h\in \langle S\rangle^c$ be given. If
$hs\in \langle S\rangle$ for some $s\in S$, then $h = hss^{-1}\in \langle S\rangle$. So $hS$ is an open
neighbourhood of $h$ contained in $\langle S\rangle^c$, proving that $\langle S\rangle$ is indeed closed.
Since $\langle S\rangle$ is nonempty,
open, and closed in the connected group $\phi(G)$, $\langle S\rangle = \phi(G)$ and $\phi (G)$ is the connected
component of the identity.&nbsp;&nbsp;∎

### Finishing up the $(r,s) = (4,0)$ case

First we need to find the tangent space of the identity in ${\bf H}_1$. If $1 + \epsilon (x+yi+zj+wk)$
has norm $1$, then we must have
$$ (1+\epsilon x)^2 + \epsilon^2 y^2 + \epsilon^2 z^2 + \epsilon^2 w^2  = (1+\epsilon x)^2 = 1,$$
so the trace $x$ must equal zero. Thus $T_1{\bf H}$ is $3$-dimensional and $T_1({\bf H}_1\times {\bf H}_1)$
is $6$-dimensional. The tangent space of the identity matrix $I$ in ${\rm SO}(V)$ is the set of all
matrices with $A^T = -A$, since the condition that $(I+\epsilon A)(I+\epsilon A)^{\rm T}$ implies
that $I + \epsilon (A + A^{\rm T}) = I$. This is a $6$-dimensional space as well, since the diagonal of $A$
must have all entries zero, and the rest of the matrix is determined by the choice of the six remaining
entries in the upper triangle. Thus to show that $d\phi$ is invertible, it suffices to show that it is injective.

Now for $(a,b)\in T_1( {\bf H}_1\times{\bf H}_1)$, we note that $\phi(1+\epsilon a, 1+\epsilon b)$
is a map on ${\bf H}$ that sends $v$ to $(1+\epsilon a) v (1+\epsilon b)^{-1}$. Since $b$ has zero trace,
$(1+\epsilon b)^{-1}$ is $1-\epsilon b$ and

$$\phi(1+\epsilon a, 1+\epsilon b)(v)
=(1+\epsilon a)v(1+\epsilon b)^{-1} = (v+ \epsilon av)(1-\epsilon b) = v + \epsilon (av-vb).$$

Then since $\epsilon d\phi(a,b) = \phi(1+\epsilon a, 1+\epsilon b) - {\rm id}$, we conclude that
$d\phi(a,b)(v) = av-vb$. If $(a,b)\in \ker(d\phi)$, then $av-vb=0$ for all $v\in {\bf H}$, and taking $v=1$
in particular, we have $a = b$. Thus $av = va$ for all $v\in {\bf H}$ and we see that $a\in {\bf R}$. But we
assumed that $a$ has trace zero, so $(a,b) = (0,0)$.

We have found that $d\phi$ is injective, so it must be surjective as well, since the tangent spaces both
have dimension $6$.
So by the lemma of the previous section,
the image of $\phi$ is the entire component of the identity in ${\rm O}(V)$. In fact, in this case,
this component is all of ${\rm SO}(V)$, which we conclude is
isomorphic to $$({\bf H_1}\times {\bf H_1})/\{\pm 1\}$$.

### The case $(r,s) = (3,1)$

Here $Q(x,y,z,w) = x^2 + y^2 + z^2 - w^2$ but we can perform a change of basis with $u = z+w$ and $v=z-w$
to get $Q(x,y,u,v) = x^2 + y^2 + uv$. Since $x^2 + y^2 = (x+iy)(x-iy)$, we can identify $(V,Q)$ with the set
of all matrices

$$\biggl\{ \pmatrix{x+iy & u \cr v &  iy-x} : x,y,u,v\in {\bf R}\biggr\},$$

with the negative determinant as the norm. Letting $$M^* = \det(M) M^{-1}$$, we find that $V$ is precisely
the set of $M\in M_2({\bf C})$ with $M^* = -\overline M$. We have $$(AB)^* = B^*A^*$$ for
$A,B\in M_2({\bf C})$,
and this operation is also linear. The group ${\rm SL}_2({\bf C})$ acts on $V$ by $g\star M = gM\overline g^{-1}$.
Indeed,

$$(g\star M)^* = (gM\overline g^{-1})^* = \overline g M^* g^* = - \overline g\overline M g^* = -
\overline{gM\overline g^*} -\overline{g\star M},$$

so $g\star M$ is in $V$. Note that the center of ${\rm SL}_2({\bf C})$ is $$\{\pm I\}$$, and we have the
exact sequence

$$ 1\to \{\pm I\} \to {\bf SL}_2({\bf C}) \buildrel\phi\over\to {\rm O}(V).$$

Once again, the image of $\phi$ is connected.

Now we find the tangent space of ${\rm SL}_2({\bf C})$ at the identity. An element

$$A = \pmatrix{ a & b \cr c & d }$$

in this space satisfies
$I + \epsilon A\in {\rm SL}_2({\bf C})$, so $\det (I+\epsilon A) = 1+\epsilon a + \epsilon d = 1$.
This implies that $d=-a$. In other words, the trace of $A$ is zero, and in particular we see that $A^* = -A$.
Now we examine what $I+\epsilon A$ does to a matrix $M\in V$. We note first that

$$(I+\epsilon \overline A)^{-1} =
\pmatrix{ 1 + \epsilon \overline a & \epsilon \overline b \cr
\epsilon\overline c & 1-\epsilon \overline a }^{-1}
=\pmatrix{ 1 - \epsilon \overline a & -\epsilon \overline b \cr
-\epsilon\overline c & 1+\epsilon \overline a } = I+\epsilon \overline{A^*}$$

So

$$(I+\epsilon A)M\overline{(I+\epsilon A)}^{-1} = (M+\epsilon AM)(I+\epsilon \overline{A^*})
= M + \epsilon AM + \epsilon M \overline{A^*} = M+ \epsilon(AM-M\overline A),$$

telling us that $d\phi(A)$ takes matrices $M$ to $AM-M\overline A$. We now investigate what it means for
$A$ to be in the kernel of $d\phi$. If $MA - M\overline A$ for all matrices $M$, then taking
$M = I$, we see that $A = \overline A$, meaning that $A$ has all real entries and $AM = MA$ for all
$M$. This implies that $A$ is a scalar multiple of the identity and since it has zero trace, $A$ must be $0$.
We have found that $\ker(d\phi) = 0$, so the connected component of
the identity is isomorphic to $${\rm SL}_2({\bf C}) / \{\pm I\}$$.

### The case $(r,s) = (2,2)$.

The third and last case feels a bit like a combination of the two cases above.
We have $Q(x,y,z,w) = x^2 + y^2 - z^2 - w^2$ and with the substitutions
$x = x+z, y=x-z, z = w+y, w= w-y$ (the variables on the left-hand side are not the same as the ones on the
right-hand side), we have

$$Q(x,y,z,w) = xy-zw,$$

so we can identify $(V,Q)$ with $(M_2({\bf R}), \det)$. The group ${\rm GL}_2({\bf R})\times{\rm GL}_2({\bf R})$
defines an action on $M_2({\bf R})$ given by $(g,h)\star M = gMh^{-1}$. For $(g,h)$ to preserve the determinant
we must have $\det g = \det h$. We can also require that $g$ and $h$ have determinant $1$, because for any
$\lambda\in {\bf R}$ we have $\det(\lambda g) = \det(\lambda h)$ and

$$ \lambda g M(\lambda h)^{-1} = \lambda^2 g M \lambda^{-2} h^{-1} = gMh^{-1}.$$

Thus we have the exact sequence

$$1 \to \{(I,I), (-I, -I)\} \to {\rm SL}_2({\bf R})\times{\rm SL}_2({\bf R}) \buildrel\phi\over\to {\rm O}(V).$$

The computation we performed above for the tangent space of ${\rm SL}_2({\bf C})$ works when the entries
are real as well, so we find that the tangent space of ${\rm SL}_2({\bf R})\times{\rm SL}_2({\bf R})$
is the set of $(A,B)$ such that ${\rm tr}\,A = {\rm tr}\,B = 0$. In particular, since the trace of $B$
is zero, we can write

$$ B = \pmatrix{a & b \cr c & -a} $$

and the fact that $\det(I + \epsilon B) = 1$ implies that

$$(I + \epsilon B)^{-1} = \pmatrix{ 1+a & b \cr c & 1-a }^{-1} = \pmatrix{1-a & -b \cr -c & 1+a}
= I - \epsilon B.$$

So

$$\phi(I+\epsilon A, I+\epsilon B)(M) = (I+\epsilon A)M(I+\epsilon B)^{-1}
= (M + \epsilon AM)(I-\epsilon B) = M+\epsilon (AM-MB),$$

and $d\phi(A,B)(M) = AM-MB$. 
We argue as before to find that for $(A,B)\in \ker(d\phi)$,
$A=B$ and $A$ is a scalar of the identity with trace zero and thus $(A,B) = (0,0)$.
So $d\phi$ is injective and the image of $\phi$ is isomorphic to
$${\rm SL}_2({\bf R})\times{\rm SL}_2({\bf R})/\{(I,I), (-I,-I)\}$$.


### References

+ Jean-Pierre Serre, _A Course in Arithmetic_ (New York: Springer-Verlag, 1973)

