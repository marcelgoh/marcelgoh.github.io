---
layout: page
title: Theoremae
mathjax: true
---

## Prima theorema isomorphismi

__Theorema.__ Sint $G$ et $H$ greges, $\phi : G \rightarrow H$ morphismus gregum, ubi denotabimus $K = \text{ker}\ \phi$. Sit $\psi : G \rightarrow G/K$ morphismus canonicus. Tum existit isomorphismus unicus $\eta : G/K \rightarrow \phi(G)$ ut $\phi = \eta\psi$.

_Demonstratio._
Scimus K normalis in G esse. Definimus $\eta : G/K \rightarrow \phi(G)$ ubi $\eta(gK)=\phi(g)$, et demonstramus $\eta$ functio esse. Si $g_1K = g_2K$, existit $k\in K$ ut $g_1k = g_2$; ergo,

$$\eta(g_1 K) = \phi(g_1) = \phi(g_1)\phi(k) = \phi(g_1k) = \phi(g_2) = \eta(g_2K).$$

Tum $\eta$ selectione testis classis lateralis non dependet et congruentia $\eta$ unica est quod $\phi = \eta\psi$. Nunc monstramus $\eta$ morphismus esse:

$$
\begin{align}
    \eta(g_1Kg_2K) &= \eta(g_1g_2K)\\
    &= \phi(g_1g_2)\\
    &= \phi(g_1)\phi(g_2)\\
    &= \eta(g_1K)\eta(g_2K).
\end{align}
$$

Functio $\eta$ superiectiva est. Volimus demonstrare $\eta$ iniectiva esse. Sint $g_1K,g_2K\in G/K$ ut $\eta(g_1K)=\eta(g_2K)$. Tum $\phi(g_1)=\phi(g_2)$. Itaque $\phi(g_1^{-1}g_2) = e$ et $g_1^{-1}g_2\in \text{ker}\ \phi$; ergo, $g_1^{-1}g_2K = K$, aut $g_1K=g_2K$. Quod erat demonstrandum.
