---
layout: page
title: Theoremae
mathjax: true
---

## Prima theorema isomorphismi

__Theorema.__ Sint $G$ et $H$ greges, $\phi : G \rightarrow H$ morphismus gregum, ubi denotabimus $K = \text{ker}\ \phi$. Sit $\psi : G \rightarrow G/K$ morphismus canonicus. Tum existit isomorphismus unicus $\eta : G/K \rightarrow \phi(G)$ ut $\phi = \eta\psi$.

_Demonstratio._
Scimus K normalem in G esse. Definimus $\eta : G/K \rightarrow \phi(G)$ ubi $\eta(gK)=\phi(g)$, et demonstramus $\eta$ functio esse. Si $g_1K = g_2K$, existit $k\in K$ ut $g_1k = g_2$; ergo,

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

Functio $\eta$ superiectiva est. Volumus demonstrare $\eta$ iniectivam esse. Sint $g_1K,g_2K\in G/K$ ut $\eta(g_1K)=\eta(g_2K)$. Tum $\phi(g_1)=\phi(g_2)$. Itaque $\phi(g_1^{-1}g_2) = e$ et $g_1^{-1}g_2\in \text{ker}\ \phi$; ergo, $g_1^{-1}g_2K = K$, aut $g_1K=g_2K$. Quod erat demonstrandum.


## Irrationalitas numeri $\sqrt{2}$

__Theorema.__ Numerus $\sqrt{2}$ irrationalis est.

_Demonstratio._ Demonstramus rationalitam numeri $\sqrt{2}$ contradictionem implicare. Si $\sqrt{2}$ rationalis est, existunt numeri integri $p$ et $q$ ut $\sqrt{2} = \frac{p}{q}$, ubi $p$ and $q$ factores primos aequales non habent. Tum $2 = p^2/q^2$ et $p^2=2q^2$; ergo $a$ est numerus par, et existit numerus integer $r$ ut $p=2r$. A prima aequatione sequitur $2q^2 = (2r)^2 = 4r^2$, ergo $q^2 = 2r^2$ et $q$ est numerus par. Absurdum est quia $p$ et $q$ factores primos aequales habere non possunt. Itaque coniectura falsa est et $\sqrt{2}$ irrationalis est. Quod erat demonstrandum.