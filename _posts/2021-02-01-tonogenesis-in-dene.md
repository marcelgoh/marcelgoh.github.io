---
layout: post
title: Tonogenesis in Dene languages
date: 2021-02-01
published: true
mathjax: true
excerpt_separator:  <!--more-->
---

I'm taking a seminar class this semester on the Na-Dene languages as part of my linguistics minor, and this week
it is my turn to give a presentation on a paper in the field. I am covering a 1999 paper by Jeff Leer called
"Tonogenesis in Athabaskan", and I thought it'd be good preparation to collect my thoughts in a blog post while
reading the paper. This is a bit of a departure from the mathematical content I usually deliver, but should
be in the original spirit of the blog. Most of my early posts involve me grappling and experimenting with
new ideas, and I'm sure there will be a lot of that in this post, since
most of the linguistic concepts found in this paper are completely new to me. Of course, you might get more
out of this post if you have read/are reading the paper as well, but I intend to make this a self-contained summary
of the paper for a somewhat more general audience.
<!--more-->

__Disclaimer.__
This is not intended to be a formal write-up, so I will vaguely mention things that were covered in class without
providing citations for every little detail. The general structure of the blog post mirrors the structure of Leer's
original paper, but please take everything I write with a grain of salt and consult the actual paper before
reaching any conclusions!
I will include the reference to the paper at the end of the post as well as any other papers I do end up citing.

### The Na-Dene languages

Na-Dene is a group of languages spoken by various Indigenous peoples in Alaska,
Northern and Western Canada, as well as in various states in the American Southwest. Here is a map from Wikipedia
that shows the rough distribution of the languages (click [here](/media/tonogenesis-in-dene/map.png) to open a
larger version):

![map](/media/tonogenesis-in-dene/map.png)

All of the languages in the map above fall in the Dene (Athabaskan) family, except for Eyak and Tlingit, which
belong to separate branches. Many of the languages listed above are now extinct, and most of the ones that are
still spoken today are endangered. A notable exception is Navajo, which has over 150,000 speakers.

### A toneless proto-language

The main problem that this paper addresses is the source of tone in Na-Dene languages. Most of the
Na-Dene languages are tonal, but the fact that not all of them are, as well as the fact that the nature
of tone varies across the language family points suggests that the common ancestor of these languages
did not have tone. As a clue,
the Na-Dene languages spoken in Alaska are thought to be more phonologically conservative and indeed,
most of the non-tonal Na-Dene languages are spoken in Alaska. However, this is merely a heuristic,
and the rest of the post will be devoted to painting in broad strokes Leer's complete tonogenesis hypothesis.

This problem has been studied in other tonal language families around the world. For example, it is now widely
believed that Old Chinese (spoken around 2000 years ago) did not have tone, though pretty much every modern
Chinese language today is tonal. The prevailing theory in that domain seems to be that syllable-final consonant
clusters in Old Chinese had, by 600 A.D., developed into the various tones of Middle Chinese. Another example is
Punjabi, notable for being one of the few tonal Indo-European languages. There, it is quite clear (and even
reflected in the orthography)
that tone appears in syllables which used to contain voiced aspirated consonants ([dʰ], [bʰ], etc.).

### Marked and unmarked tone

Most tonal Na-Dene languages possess only two tones, high and low, and one of these is _marked_, while the other
is _unmarked_. In some sense, the unmarked tone is the "default" one, and the marked tone is usually a bit less
common. (A notable exception to this rule is Navajo.)
This is not the same as what happens in pitch-accent languages, since there can be multiple marked
syllables in a given word, whereas words in pitch-accent languages tend to have tone more or less like English words
have stress: generally there is at most one accented syllable per word.

Whether high tone or low tone is marked depends on the specific language, and there
are various examples of neighbouring languages, otherwise very similar, with opposite marked tones. One of the
first linguists to work with Dene languages was Edward Sapir (yes, the same Sapir from the Sapir-Whorf
hypothesis that I wrote a [blog post](/2018/07/20/linguistic-relativity.html)
about a couple of years ago). In the early 20th century,
he studied Navajo, Tsuut'ina, and Gwich'in
and came away with a reconstruction of Proto-Athabaskan (PA) that marked low tone.

However, Sapir's student, Li
Fang-Kuei, studied Chipewyan (Dënësųłinë́) and found the opposite tones! Where Sapir's had reconstructed low
tone in PA, Li found high tone, and where Sapir's PA had high tone, Chipewyan had low tone. He also found
some Dene languages on the Pacific coast that have no tone at all. It turns out that
most of the tonal Dene languages (all of the Southern ones and about half of the Northern ones) are
low-marked, and the rest are high-marked. Here is a rough reconstruction (coloured in by yours truly over
the Wikipedia image above) of Figure 5 of the paper,
which itself references Krauss and Golla 1991, p. 70. Orange indicates low-marked, green indicates high-marked,
and uncoloured indicates that tone is absent or minimal.

![map](/media/tonogenesis-in-dene/high-low-tone.jpg)

As another disclaimer, in case you missed the disclaimer above, please do not take these borders as fact! I
simply eyeballed a rough approximation of the figure from the paper. Some of these classifications are unexplained
in the text, and some are even debated
(e.g. whether or not Dakelh is tonal). For us, the point isn't where exactly the high and
low tone borders are, it's the fact that the distribution is rather sporadic, and
presents a pretty clear obstruction to Sapir's reconstruction.
If PA was low-marked, why did such a significant portion of Northern Dene languages switch to a high-marked
regime?

This leads linguists, like Krauss in 1966, to conclude that Proto-Athabaskan-Eyak (PAE), and possibly even
PA, wasn't tonal.
Li noted in 1933 that high tone in Chipewyan coincided with the historical presence of glottal features, either
a glottal stop or a glottalised consonant towards the end of a syllable, so he hypothesised that this is the
source of the marked tone. It's important to note that Li didn't
actually reconstruct PA with proper stem-final glottalised stops, instead combining a stem-final consonant
with a glottal stop; for example, he reconstructs *tˀ as *d + '. Though there are some holes in Li's argument given
in the thirties, Leer calls his hypothesis "rather ingenious", with an "appeal analogous to elementary particles
in physics".

### Tongass Tlingit and Pre-PA

Leer supplies an extended example of tonogenesis in a Tlingit, a language closely related to the Dene
family. He had discovered a now-extinct dialect of Tlingit called Tongass Tlingit, which did not have tone (unlike
all other Tlingit dialects). Instead, Tongass Tlingit vowels exhibit some length and
glottalisation phenomena that Leer called _stigmata_. A vowel in Tongass Tlingit can be short (V), fading (V`),
glottalised (Vˀ), or lengthened (V·); the latter three features are the stigmata.
Crucially, the Tlingit tone system can be reconstructed
from Tongass Tlingit's stigmatic system.  A rough summary of the correspondences is given in this table:
```
Tongass Tlingit            other Tlingit dialects
-------------------------------------------------------------------------
fading (V`)         ->     long low-tone
glottalised (Vˀ)    ->     long falling-tone in Henya dialect,
                             long high-tone elsewhere
lengthened (V·)     ->     long high-tone
```
To understand the reconstruction of PA that will concern us in the remainder of the blog post, one needs to have
a basic understanding of the syllable structure in
Leer's reconstruction of Pre-PA, the common ancestor of Eyak, Tlingit, and the Dene languages. Most of the
properties listed below have analogues for other languages in the family that are also described in the paper,
but we will gloss over these details, focusing only on Pre-PA:

1. Pre-PA syllables have an onset, which consists of a single consonant. Stops in this position may be plain,
aspirated, or glottalised.
2. A syllable may have a coda, which consists of several consonants (usually no more than two).
At the end of a syllable, plain and aspirated consonants are not contrasted.
3. There are four vowels (i,e,a,u) and vowels without a stigma are said to be _reduced_, and denoted with a
lowercase v.
Leer reconstructs this reduction as a simple shortening of the vowel. A rime cannot consist of a reduced vowel
alone, but full vowels or reduced vowels followed by
coda consonants are both valid.
4. The shape of the rime in Pre-PA is V (·/ˀ) (C) (C) (C)*. The first coda consonant may be a sonorant (R) or
an obstruent (X), while the second is always an obstruent.
5. If the vowel of the rime has glottal stigma, the first coda consonant cannot be a sonorant.

### Constriction

In the transition from Pre-PA to PA, a general phenomenon occurred which Leer calls _suprasegmentalisation_, in
which the vowel takes on suprasegmental properties of a neighbouring coda consonant.
For example, nasal sonorant consonants such as *m or *n in Pre-PA turned a preceding V or V· into a nasalised
long vowel. Myriad other examples of suprasegmentalisation and spirantisation (an obstruent transforming
into a fricative) are presented in the paper, and in particular, the author is able to reconstruct
stem variation in PA verbs and nouns in terms of the stigmatic theory. The only phenomenon
we will focus on in this post is the one that Leer calls _constriction_. It is the
suprasegmentalisation of glottalisation, either in the stigma or in a coda consonant. Constriction in the
vowel will be denoted by V' (the apostrophe is actually placed over the V in the text). 
The rule that describes how Pre-PA glottalisation became constriction in PA is given by

$$\hbox{Pre-PA *VˀX, *vRˀX, *V·RˀX} \rightarrow \hbox{PA *V'·X}.$$

A number of other rules are listed that add constriction, such as $\hbox{Pre-PA *vXˀ}\rightarrow
\hbox{PA *v'Xˀ}$, with Xˀ undergoing spirantisation (transforming into a fricative)
if it is followed by another obstruent. This rule is somewhat interesting because it shows that a feature
may spread leftward from a coda consonant to the vowel while the coda consonant remains unchanged.
Notably, constriction does _not_ occur with Pre-PA *V·Xˀ, which is the same in PA.

### Finally, tone appears

We saw that in the transition from Pre-PA to PA, vowel glottalisation disappeared and was suprasegmentalised
into vowel constriction. No Dene language spoken today actually has vowel constriction as Leer describes it.
Instead, we find that constricted vowels turned into tone:
low tone in some languages, and high tone in others. Interestingly, the (historically)
low-marked language Tsuut'ina (Sarcee), spoken
in central-southern Alberta, developed three tones:
```
Proto-Athabaskan                        Tsuut'ina
-----------------------------------------------------------
lengthened                          ->  marked high tone
short                               ->  unmarked mid tone
constriction (both short and long)  ->  marked low tone
```
In the Southern Dene languages (Navajo and Apache), we have the following development:
```
Proto-Athabaskan                        Southern Dene
-----------------------------------------------------------
lengthened                          ->  long high tone
constricted long                    ->  long low tone
short constricted/unconstricted     ->  short low tone
```
Both of these peoples are thought to have migrated south from around the same geographical
area, which would make it unsurprising if these tonal developments are related somehow. Leer also includes a
couple of examples of Chipewyan alongside Tsuut'ina and Navajo, illustrating that Chipewyan has high tone
wherever vowel constriction in the proto-form is present (as indicated by the tone in the other two languages).

As mentioned before, some
neighbouring languages have opposite tone but are otherwise very similar, such as Northern/Southern Tutchone.
The tone-flipping does not impede communication between these two groups, and a footnote goes so far as to say
that the speakers of these languages do not find the fact that the tones are reversed in the other language
interesting at all---John Ritter is quoted
as calling it a "near universal 'yawn factor'". It seems that speakers of these languages are less aware
or concerned with the high/low contrast than they are with the marked/unmarked contrast, which is much more uniform
across the family.

I find this fascinating, as I am familiar with a partial analogue
of this phenomenon all the way across the world in Singapore. I have family members who speak
Hokkien and some who speak Teochew, two very similar mutually intelligible languages.
One difference between Hokkien and Teochew is that Teochew has a high-level tone where Hokkien has a rising
tone, and emphasising the perceived "musicality" of Teochew by exaggerating these high tones is a mild
source of amusement among some family members (both Hokkien and Teochew) that I have asked about this.

### What exactly was constriction?

The "glottalisation becomes constriction becomes tone" theory explains, with minimal exceptions, the source
of tone in Dene languages. However, given that no extant Dene language has vowel constriction, we are
left wondering what exactly this was, and how it morphed into two different "mirror-image" tone systems.
This question was considered in 1985 by John Kingston. He notes that in some languages, a glottal stop after
a vowel can induce a creaky voice (popularly known as "vocal fry") on the vowel,
whereas in other languages glottal stops induce a "tense" voice, which is characterised by higher frequencies.

Creaky voice involves low-frequency vibration of the vocal folds, and could therefore
have transformed into low tone, while tense voice could become high tone. Thus one could hypothesise that
vowel constriction was realised as creaky voice, which soon became accompanied by low tone. In some places,
both of these properties disappear,
leaving an atonal language. In others, the creaky voice could have disappeared, leaving
behind a low-marked tonal language. In the final case, the low and lax creaky voice became a higher
"tense creaky voice", which leaves behind a high-marked tone.

This hypothesis, though somewhat complex, is somewhat more palatable than the naïve hypothesis that the tones
simply switched places out of nowhere somewhere along the line. Leer discredits this line of thinking,
writing that if spontaneous tone reversal was a real thing, we would have more examples of it in tone languages
around the world. But the creaky-voice theory isn't perfect either, and Leer closes the paper by indicating
possible further research that could be done in the area.

### References

+ John Kingston, "The phonetics and phonology of Athabaskan tonogenesis," Unpublished manuscript (1985),
University of Texas at Austin.
+ Michael E. Krauss and Victor Golla, "Northern Athapaskan Languages," _Handbook of North American Indians,
Vol. 6. Subarctic,_ (1991), Smithsonian Institute, Washington.
+ Fang-Kuei Li, "Chipewyan Consonants," _Bulletin of the Institute of History and Phonology, Academica
Sinica, Ts'ai Yüan P'ei Anniversary Volume, Supplementary Volume 1_ (1933), 429-467.
+ Jeff Leer, "Tonogenesis in Athabaskan," _Cross-linguistic Studies of tonal phenomena:
Tonogenesis, typology, and related topics_ (1999), Shigeki Kaji (ed.), 37-66.

