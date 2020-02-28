# Binary Fun

When I say fun, I don't mean you are necessarily going to laugh, unless its at my attempts at so called 'programming'.

Here be a series of C files each illustrating a facet of binary integer manipulation which might be useful if you have processor intensive code squirrelled away which you know are slowing down your application. e.g. in nested loops somewhere. 

I have no training in either mathematics or algebra and I correlated these files as part of a self-learning process. Only the simplest algorithms and tricks which I could imagine myself actually using, based on my experience as a developer, have been extracted.

## Me

An ex LAMP dev now fiddling with Micro Controllers (uControllers). I came from a land steeped in the omens like "premature optimization is the root of all evil" etc with shelves decorated with POEAA, Refactoring, Clean Code and all that, but now, hold up ... readablity may not be one of my main aims ... the balance has shifted.

Extra processor cycles on cControllers REALLY DO matter a LOT and I now understand the consequences :

* the longer they take the more precious battery they eat up 
* vociferous code likewise eats up precious tiny memory
* data to be transmitted over RF should be as succinct as possible

So I thought I'd better stop massacring C++, change down a gear, and learn C properly - get 'closer to the metal' and all that. Now that I appreciate uController ports and muliple I/O switching it makes sense to now go on and fully grok binary/bitwise ops.  Hence I ploughed merrily thru "Hackers Delight" and thought I'd share what I learned and leave it hanging around the web in case I need it when being remote somewhere, and maybe it could help someone else.

## You

Maybe you are also self taught and did not study CS formally, or you skipped this important part of your trade, or you just put it off. Perhaps you are just struggling to understand all the palaver about binary and bitwise operations. 

It could be that you want an accompaniment to your own digestion of "Hackers Delight". These files might help, I hope so.

## Usage

Each of the c files is designed to run on its own and show at least a single binary or bitwise operation, 

There is one include file with some binary print functions which might help you visualise the 1s and 0s of the values.
Thes are called `pbin(int)` (print binary) and `pbin_nb(int, *char)` (print binary with a note) in case you want to add some annotation.

#### Example : write a file containing  :

```c 
#include <stdio.h>
#include <string.h
#include "binary_print.h" 

int main(void) {
 pbin(15);
 pbin_nb(23, "take an integer");
 pbin_nb(15^23, "^ acts as a toggle")
return 1;
}
```

#### In your console you'll see :

```console 
  0000 1111	(15)
  0001 0111	(23)  <-- take an integer
  0001 1000	(24)  <-- ^ acts as a toggle
```
Then play around with values 'till your brain figures out what is going on, and where on earth you may finally find a place for that trick in your life. Do you see how the set bits (1s) in "15" cause the equivalent (ie last 4) bits of "23" to "toggle"?

There are also two equivalent functions named `pbin8(char)` and `pbin8_nb(char, *char)` which accept 8 bit chars instead of 32 bit integers.

When using 32 bit integers the `pbin(int)` functions truncate the first 24 bits, so you cannot see exactly what is going on on the binary front. I did not realise the imlication of this 'till I dealt with negative signed ints, hence you may notice the more char-friendly `pbin8(char)` function appears somewhat randomly so don't read anything else into their my choice of using them or not. 

## Caveats

This is all written in straight c - but the basic binary manipulation outcomes should hold true in all languages, but be warned stuff like Big Endian, 2s complement or not, integer size, signed or unsigned etc may cause different outcomes.

This is only tested on an x86 64 bit intel processor, running Ubuntu 14.04. Gcc version 4.8.4, 32 bit integers, 2's complement.

I'd love to be able to compare these outcomes to those on an ARM processor, but I'm not (back) there yet.

Gcc makes `__builtin_clz()` (count leading zeros) and ` __builtin_ctz()` (count trailing zeros) available. This enabled me to take an integer such as 4 (0000 0100) and know that the count of trailing zeros is 2 which is sometimes useful. I have used this method in some examples. Check your environment carefully, else "Hackers Delight" shows how to roll your own.

Programmers following you may hate you for using some of these tricks unless :

* You document your code liberally
* You actually do save the day by speeding something up

My title for this repo was to be "Binary Fun with Hackers Delight" but I realised that the majority of that book went straight over my head. These are just a few tricks I gleaned and managed to get working, so be aware.

I sometimes mention the relevant page numbers, or chapters of Revision 2 of the book which you will easily find online. 

I also plaguerised the book, obviously, along with a couple of SO posts and binary articles and intend to give due credit - though the in-file comments should show these quite clearly.

I am not planning on spending any more time elucidating upon, or embroidering these files, but if I do actually come across places where I have used I may add working examples into the code samples.

## Going further

If you are intending to press on with your binary journey, it seems you will need to study the next stage which means reading and understanding Assembly. Just because you have substituted some basic c with a fancy binary predicate it does not mean you have tricked the intepreter into speeding up. How did you measure it? 
