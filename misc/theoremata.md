---
layout: page
title: Theoremata
mathjax: true
---

## Primum theorema isomorphismi

__Theorema.__ Sint $G$ et $H$ greges, $\phi : G \rightarrow H$ morphismus gregum, et sit $K = \text{ker}\ \phi$. Sit $\psi : G \rightarrow G/K$ morphismus canonicus. Tum existit isomorphismus unicus $\eta : G/K \rightarrow \phi(G)$ ut $\phi = \eta\psi$.

_Demonstratio._ Scimus $K$ normalem in $G$ esse. Definimus $\eta : G/K \rightarrow \phi(G)$ ubi $\eta(gK)=\phi(g)$, et demonstramus $\eta$ functio esse. Si $g_1K = g_2K$, existit $k\in K$ ut $g_1k = g_2$; ergo,

$$\eta(g_1 K) = \phi(g_1) = \phi(g_1)\phi(k) = \phi(g_1k) = \phi(g_2) = \eta(g_2K).$$

Tum $\eta$ selectione testis classis lateralis non dependet et congruentia $\eta$ unica est quod $\phi = \eta\psi$. Nunc demonstramus $\eta$ morphismum esse:

$$
\begin{align*}
    \eta(g_1Kg_2K) &= \eta(g_1g_2K)\\
    &= \phi(g_1g_2)\\
    &= \phi(g_1)\phi(g_2)\\
    &= \eta(g_1K)\eta(g_2K).
\end{align*}
$$

Functio $\eta$ superiectiva est. Volumus demonstrare $\eta$ iniectivam esse. Sint $g_1K,g_2K\in G/K$ ut $\eta(g_1K)=\eta(g_2K)$. Tum $\phi(g_1)=\phi(g_2)$. Itaque $\phi(g_1^{-1}g_2) = e$ et $g_1^{-1}g_2\in \text{ker}\ \phi$; ergo, $g_1^{-1}g_2K = K$, id est $g_1K=g_2K$, et $\eta$ isomorphismus est. Q.E.D.


## Irrationalitas numeri $\sqrt{2}$

__Theorema.__ Numerus $\sqrt{2}$ irrationalis est.

_Demonstratio._ Demonstramus rationalitam numeri $\sqrt{2}$ contradictionem implicare. Si $\sqrt{2}$ rationalis est, existunt numeri integri $p$ et $q$ ut $\sqrt{2} = \frac{p}{q}$, ubi $p$ and $q$ factores primos aequales non habent. Tum $2 = \frac{p^2}{q^2}$ et $p^2=2q^2$; ergo $p$ est numerus par, et existit numerus integer $r$ ut $p=2r$. A prima aequatione sequitur $2q^2 = (2r)^2 = 4r^2$, ergo $q^2 = 2r^2$ et $q$ est numerus par. Sed $p$ et $q$ factores primos aequales non habent. Q.E.A.

## Theorema parvum Fermatianum

__Theorema.__ Sit $a$ numerus integer aliquis. Si $p$ est numerus primus, $a^p \equiv a\ (\text{mod}\ p)$.

_Demonstratio._ Primo, demonstramus copiam $U(p)=\{1, 2, \ldots , p-1\}$ cum operatione multiplicationis secundum modulum $p$ gregem esse. Clare, copia clausa est et $1$ eius elementum idemfactor est. Associativitas sequitur associativitam multiplicationis integrae. Pro omnia elementa in $U(p)$, debemus invenire elementum inversum. Sit $a\in U(p)$. Cum $1 \leq a \leq p-1$, $\text{gcd}(a, p) = 1$. Tum existunt numeri integri $r$ et $s$ ut $1 = ra + sp$. Secundum modulum $p$, haec aequatio fit $ra \equiv 1\ (\text{mod}\ p)$ et $r$ elementum inversum $a$ in $U(p)$ est. Itaque $U(p)$ grex est, cum $\lvert U(p)\rvert=p-1$.

Nunc theorema demonstrare possumus. Sit $a$ numerus integer. Sine detrimento generalitatis, habere $1 \leq a \leq p-1$ possumus, ergo $a\in U(p)$. Sit $k$ minimus integer satisfaciens $a^k \equiv 1\ (\text{mod}\ p)$, id est, $k$ est ordo $a$ in $U(p)$. Per theorema Lagrangiae, $k$ dividit ordinem gregis, ergo est $m$ ut $km = \lvert U(p)\rvert = p - 1$. Tum

$$a^{p-1} \equiv a^{km} \equiv 1^m \equiv 1\ (\text{mod}\ p).$$

Multiplicare hanc aequationem cum $p$, habemus $a^p \equiv p\ (\text{mod}\ p)$. Q.E.D.

## Theorema Erdős-Szekeres

__Theorema.__ Si $S$ est sequentia finita longitudine $\geq (r-1)(s-1)+1$, erit subsequentia crescens longitudine $r$ vel subsequentia decrescens longitudine $s$.

_Demonstratio._ Theorema demonstratur contrapositione. Assumimus omne sequentia crescens longitudinem $\leq r-1$ habere et omne sequentia decrescens longitudinem $\leq s-1$ habere. Omni $x_i\in S$ assignamus pittacium $(a_i, b_i)$, ubi $a_i$ designat longitudinem longissimae sequentiae _crescentis_ qui terminatur $x_i$ et $b_i$ designat longitudinem longissimae sequentiae _decrescentis_ qui terminatur $x_i$.

Affirmamus pittacia numerorum $x_i$ inter se differre. Sint $i$ et $j$ numeri differentes; sine detrimento generalitate, $i < j$ habetur. Si $x_i\leq x_j$, erit $a_i < a_j$, quia omnis sequentia crescens qui $x_i$ terminatur $x_j$ extendi potest. Similiter, si $x_i\geq x_j$, erit $b_j > b_i$, quia omnis sequentia decrescens qui $x_i$ terminatur $x_j$ extendi potest.

Cum $a_i\leq r-1$ et $b_i\leq s-1$ (omni $i$), sunt $\leq (r-1)(s-1)$ pittacia. Tum sequentia $S$ longitudinem $\leq (r-1)(s-1)$ habet. Q.E.D.
