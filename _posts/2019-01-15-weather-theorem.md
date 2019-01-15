---
layout: post
title: A classic weather theorem
date: 2019-01-15
published: true
mathjax: true
excerpt_separator:  <!--more-->
---
While on holiday with my family over the break, I thought about a classic application of the [Borsuk-Ulam theorem](https://en.wikipedia.org/wiki/Borsuk–Ulam_theorem): There are always two antipodal (exactly opposite) points on the globe with equal temperature. I recited this theorem and its proof to my parents and brother, whose first reaction was to exclaim: "You spend way too much time thinking about pointless math!" &mdash; a valid opinion. Then my dad, still not entirely convinced, asked me: "Okay well, where are these two points?". Like most existence theorems, the Borsuk-Ulam theorem doesn't help much in finding the actual points that it concerns, so I decided to write [a program](https://github.com/marcelgoh/misc-programs/tree/master/haskell/Borsuk-Ulam) to find these antipodal points using data from the web.
<!--more-->
## The theorem
Before we get into the program, let's get the theorem and proof out of the way. We need to assume that temperature varies continuously over the globe, i.e. if you walk from a point with temperature $a$ to another point with temperature $b$, then you passed through all the temperatures between $a$ and $b$. For the most part, this is a sensible thing to assume. Also, it's worth it to note that the statement can be made stronger by either restricting the points to any [great circle](https://en.wikipedia.org/wiki/Great_circle) (e.g. the equator) on the globe or by introducing barometric pressure alongside temperature (on the whole globe). Details can be found on the Wikipedia article I linked at the very top of the article, but in any case the following statement is enough for our purposes:  

__Theorem.__ At any moment in time, there is a point on the globe that has the exact same temperature as its antipode (the opposite point on the globe).  

_Proof._ For every point $p$ on the planet, assign a number $f(p)$ by subtracting the temperature of its antipode from its own. So if $p$ is colder than the opposite point $q$ on the globe, then $f(p)$ will be negative and $f(q)$ will be positive. If $p$ is warmer than $q$, the opposite will be true. And if $p$ has the exact same temperature as $q$, then $f(p)=0=f(q)$. Because temperature is continuous, this new function $f$ defined over the globe is also continuous.  

Now pick any point $a$ and call its antipode $b$. If $f(a)=0$, we're done because then $a$ and $b$ have the same temperature. So assume it's not zero and assume $a$ is colder than $b$ (rename the points if you have to). So $f(a)$ is negative and $f(b)$ is positive. Now draw a line on the globe from point $a$ to point $b$. Because the line starts at a point with negative value of $f$ and ends at one with a positive value, there must be some point $c$ on this line such that $f(c)=0$. This $c$ is the point we're looking for, because $f(c)$ being zero means that it's the same temperature as its antipode!
$$\tag*{$\Box$}$$  

## The code
The [Haskell program](https://github.com/marcelgoh/misc-programs/tree/master/haskell/Borsuk-Ulam) I wrote collects [data from roughly 4,700 weather stations](https://aviationweather.gov) around the world and does a brute-force search for the two points that best match the criteria of the theorem. The file `Point.hs` defines a couple of simple data structures and the main loop and data-fetching procedures are defined in `Main.hs`. Here's what it looks like in action:
```
****************************************
Choose an option by entering a number:
1) Update to current weather data
2) Find antipodes in current weather data
3) Import data from file
4) Exit the program
1
Trying to find data from web...
Data fetched successfully from server.
****************************************
Choose an option by entering a number:
1) Update to current weather data
2) Find antipodes in current weather data
3) Import data from file
4) Exit the program
2
Analysing data on file...
At 15:15:00 GMT on 2019-01-15,
18.35 S 70.32 W and 18.3 N 109.42 E are antipodal with 0.1399% error
and both have temperature 23.0 degrees Celsius.
```
Because the Earth is humongous, 4,700 data stations can't really get a great match, and I printed the error as a percentage partially to hide the fact that the error is pretty massive. The 0.1399% error we just got above, when multiplied by half the circumference of the Earth, is a substantial 28km! Of course, the program would do better with more data, but according to the [World Meteorological Organization](https://public.wmo.int/en), there are only about 10,000 weather stations, so even if we had access to all of them, we would likely still have an error of a couple kilometres.  
In any case, I hope you &mdash; and my dad &mdash; can be satisfied with the result we got. The important take-away here is that even though technological limitations prevent us from actually finding the antipodal points with the same temperature, the Borsuk-Ulam theorem (we actually only really used the 1-dimensional case, the [intermediate value theorem](https://en.wikipedia.org/wiki/Intermediate_value_theorem)) assures us that they have to exist.