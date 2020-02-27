# Binary Fun

When I say fun, I don't mean you are necessarily going to laugh, unless its at my attempts at so called 'programming'.

Here be a series of C files each illustrating a facet of binary integer manipulation which might be useful if you have processor intensive code squirrelled away which you know are slowing down your application. e.g. in nested loops somewhere. I correlated these files as part of a self-learning process.

## Me

An ex LAMP dev now fiddling with Micro Controllers. Yeah, sure, I'm a big believer in premature optimization being evil etc what? Even got POEAA and Refactoring on the bookshelf and all that, hold up ...

SUDDENLY thats all shoved to one side, because now processor cycles REALLY DO matter: 

* they eat battery up 
* vociferous code eats up precious tiny memory
* I'm using C/C++ now, not PHP
* wireless data gotta be succinct

So I thought I'd better stop massacring C++, change down a gear, and learn C properly - get 'closer to the metal' and all that. Now that I appreciate uController ports and muliple I/O switching it makes sense to now go on and fully grok binary/bitwise ops.  Hence I ploughed merrily thru "Hackers Delight" and thought I'd share what I learned and leave it hanging around the web in case I need it when being remote somewhere.

## You

Maybe you are in a  similar boat to me in that you did not study CS formally so skipped this important part of your trade, or put it off. Maybe you are just struggling to understand all the palaver about binary and bitwise operations. These files might help, I hope so.

Maybe you want an accompaniment to your own digestion of "Hackers Delight".

## Usage

Each of the c files is designed to run on its own and show at least a single binary or bitwise operation, 

There is one include file with some binary print functions which might help you visualise the 1s and 0s of the values.
Thes are called `pbin(int)` (print binary) and `pbin_nb(int, *char)` (print binary with a note) in case you want to add some annotation.

### Example : write a file containing  :

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

In your console you'll see :
```console 
  0000 1111	(15)
  0001 0111	(23)  <-- take an integer
  0001 1000	(24)  <-- ^ acts as a toggle
```
Then play around with values 'till your brain figures out what is going on, and where on earth you may finally find a place for that information in your life.   

There are also two equivalent functions named `pbin8(char)` and `pbin8_nb(char, *char)` which accept 8 bit chars instead of 32 bit integers.

When using 32 bit integers the `pbin(int)` functions truncate the first 24 bits, so you cannot see exactly what is going on on the binary front. I did not realise the imlication of this 'till I dealt with negative signed ints, hence you may notice the more char-friendly `pbin8(char)` function appears somewhat randomly so don't read anything else into their my choice of using them or not. 

## Caveats

This is all written in straight c - but the basic binary manipulation outcomes should hold true in all languages, but be warned stuff like Big Endian, 2s Complement integer size and so on may cause differences.

This is only tested on an x86 64 bit intel processor, running Ubuntu 14.04. Gcc version 4.8.4, 32 bit integers, 2's complement.

I'd love to be able to compare these outcomes to those on an ARM processor, but I'm not (back) there yet.

Gcc makes `__builtin_clz()` (count leading zeros) and ` __builtin_ctz()` (count trailing zeros) available. This enabled me to take an integer such as 4 (0000 0100) and know that the count of trailing zeros is 2 which is sometimes useful. I have used this method in some examples. Check your environment carefully, else "Hackers Delight" shows how to roll your own.

Programmers following you may hate you for using some of these tricks unless :

* You document your code liberally
* You actually do save the day by speeding something up

The initial title of this repo was to be "Binary Fun with Hackers Delight" but I realised that the majority of that book went straight over my head. These are just a few tricks I gleaned and managed to get working, so be aware.

Much of this may not make any sense if you do not have a copy of "Hackers Delight" - and I sometimes mention the relevant page numbers of Revision 2 of the book. Search and you will find it all online, if you can read books on a screen. 

## Hold your horses

I'm a git newb. I've never contributed anything to Open Source despite being a huge fan, and frequent advocate, so I still have to sort out licensing includes for these files, but honestly, help yourself. I also plaguerised a couple of SO posts and binary articles and intend to give due credit - though the comments should show these quite clearly.

I am not planning on spending any more time elucidating upon, or embroidering these files, but if I do actually come across places where I have used I may add working examples into the code samples.
