# Binary Fun

When I say fun, I don't mean you are necessarily going to laugh, unless its at my attempts at so called 'programming'.

Here be a series of C files each illustrating a facet of binary integer manipulation which might be useful if you have processor intensive code squirreled away which you know are slowing down your application. e.g. in nested loops somewhere. 

## Me

An ex LAMP dev now fiddling with Micro Controllers. Yeah, sure, I'm a big believer in premature optimization being evil etc what? Even got POEAA and Refactoring on the bookshelf and all that, hold up ...

SUDDENLY thats all shoved to one side, because now processor cycles REALLY DO matter: 

* they eat battery up 
* vociferous code eats up precious tiny memory
* I'm using C now, not PHP
* wireless data gotta be succinct

So I thought I'd better stop massacring C++ change down a gear, and learn C properly, get 'closer to the metal' and all that jazz.  Now I appreciate uController ports and muliple I/O switching it makes sense to now go on and grok binary / bitwise ops to their fullness. Hence I ploughed merrily thru "Hackers Delight" and thought I'd share what I learned and leave it hanging around the web in case I need it when being remote somewhere.

## You

Maybe you are in a  similar boat, or are just struggling to understand all the palava about binary and bitwise.  These files might help, I hope so.

Maybe you want an accompaniment to your own digestion of "Hackers Delight".

## Usage

There is one include file with some binary print functions which might help you visualise the 1s and 0s of the values.
They are :  `pbin()` [print binary] and `pbin_nb()` [print binary with a note] in case you want to add some annotation.

` #include "binary_print.h" `

Example : write a file containing  :

` pbin(7);`

` pbin_nb(23, "take an integer");`

` pbin_nb(7^23, "^ acts as a toggle")`


In your console you'll see :

` 0000 0111	(7)`
` 0001 0111	(23)  <-- take an integer`

` 0001 0000	(16)  <-- ^ acts as a toggle`


Then use the same methods to play around with values. 

There are also two equivalent functions named `pbin8()` and `pbin8_nb()` which accept 8 bit chars instead of 32 bit integers.

## Caveats

This is only tested on an x86 64 bit intel processor, running Ubuntu 14.04. Gcc version 4.8.4, 32 bit integers, 2's complement.

I'd love to be able to compare this to an ARM processor, but I'm not (back) there yet.

It has `__builtin_clz()` (count leading zeros) and ` __builtin_ctz()` (count trailing zeros) instructions. This enables you to take an integer such as 4 [0000 0100] and know that the count of trailing zeros is 2, sometimes useful. I have used this in some examples. Check your environment carefully, else "Hackers Delight" shows how to roll your own.

When 32 bit integers are used, the included `pbin(int)` function truncates the first 24 bits, so you cannot see exactly what is going on, I did not realise the importance of this 'till I was dealing with negative signed ints, hence you may notice the char-friendly `pbin8(char)` function appears sporadically. 
The initial title of this repo was to be "Binary Fun with Hackers Delight" but I realised that the majority of that book went straight over my head. These are just a few tricks I gleaned and managed to get working, so be aware.

Programmers following you may hate you for using some of these tricks unless :

* You document your code liberally
* You actually do save the day by speeding something up

Much of this may not make any sense if you do not have a copy of "Hackers Delight" - and I sometimes mention the relevant page numbers of Revision 2 of the book. Search and you will find it all online, if you can read books like that. 

## Hold your horses

OK, I'm also learning how to use git, github and so on, so don't shoot me yet. I've never contributed anything to Open Source despite being a huge fan, and frequent advocate, so I still have to sort out licensing includes for these files, but honestly, help yourself. I also plaguerised a couple of SO posts and binary articles and intend to give due credit - though the comments should show these quite clearly.  
