---
layout: page
title: Mathjax test
mathjax: true
---

Considering that you want an upper bound, it is reasonable to work with

$$\sum_{i=1}^\frac{\sqrt{2n+2}-1}{2} \frac{n-i}{2i}-i+1,$$

noting that this much easier sum is always greater than or equal to yours (and asymptotically it behaves the same). Let $k=(\sqrt{2n+2}-1)/2$ and we proceed:

$$\begin{align}
\sum_{i=1}^k \frac{n-i}{2i}-i+1 &= \sum_{i=1}^k\frac{n}{2i} - \frac{i}{2i}-i +1\\
&= \frac{n}{2}\bigl(\sum_{i=1}^k \frac{1}{i}\bigr) - \sum_{i=1}^k i + \frac{1}{2}\bigl(\sum_{i=1}^k 1 \bigr)\\
&= \frac{1}{2}nH_{\lfloor k\rfloor} - \frac{1}{2}\lfloor k\rfloor^2 -\frac{1}{2} \lfloor k \rfloor+\frac{1}{2}\lfloor k\rfloor\\
&= \frac{1}{2}(nH_{\lfloor k\rfloor} - \lfloor k\rfloor^2)
\end{align}$$

Here $H_n$ denotes the $n$th harmonic number, whose asymptotic value is

$$H_n = \ln n + \gamma + O(n^{-1}).$$

(The constant $\gamma\approx 0.5772$ is called Euler's constant.) We may plug $n=\lfloor k\rfloor$ in the preceding result to obtain

$$\frac{1}{2}(n \ln \lfloor k \rfloor + \gamma n - \lfloor k \rfloor^2) + O(1)$$

Now we use the fact that

$$ \frac{\sqrt{2n+2}-3}{2} \leq \lfloor k\rfloor \leq \frac{\sqrt{2n+2}-1}{2}$$

to show that

$$\begin{align}
\frac{1}{2}(n \ln \lfloor k \rfloor + \gamma n - \lfloor k \rfloor^2) + O(1) &\leq  \frac{1}{2}\bigl( n\ln \bigl( \frac{\sqrt{2n+2}-1}{2} \bigr) + \gamma n - \bigl( \frac{\sqrt{2n+2}-3}{2}\bigr)^2 \bigr) + O(1)\\
&\leq \frac{1}{2} \bigl( n \ln \bigr( \sqrt{2n+2} \bigr) - \ln 2 + \gamma n - \frac{2n  - 6\sqrt{2n+2} + 11}{4} \bigr) + O(1)
\end{align}
$$

This last (horrendous) result can simply be expressed as $(n\ln\sqrt{2n+2})/2 + O(n)$, and this can be further simplified

$$
\begin{align}
\sum_{i=1}^k \frac{n-i}{2i}-i+1  &= \frac{1}{2} n\ln\sqrt{2n+2}+ O(n)\\
&= \frac{1}{4} n\ln(n+1) + \ln 2 + O(n)\\
&= \frac{1}{4}n\ln n + O(n)\\
\end{align}$$

So, returning to your original sum, we find that

$$\sum_{i=1}^\frac{\sqrt{2n+2}-1}{2} \frac{n-i}{1+2i}-i+1 = O(\frac{1}{4}n\ln n).$$
