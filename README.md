# Binary Fun

When I say fun, I don't mean you are necessarily going to laugh, unless its at my attempts at so called 'programming'.

Here be a series of C files each illustrating a facet of binary integer manipulation which might be useful if you have processor intensive code squirreled away in nested loops somewhere.

## Me

An ex LAMP dev who winged his way around for 20 years or so, from middle age to old age - only being rumbled once or twice.  Then someone introduced me to  Micro Controllers (yes, you know who you are Anthony). Yeah, sure I'm a big believer in premature optimization being evil etc what? Even got POEAA on the bookshelf and all that, hold up ...

SUDDENLY thats all to one side, because now processor cycles DO matter: 

* they eat battery up 
* vociferous code eats up precious tiny memory
* I'm using C now, not PHP

So I thought I'd better stop, learn C properly, get 'closer to the metal' and all that jazz. Then it makes sense to grok binary / bitwise ops because now I understand about uController ports and I/O. Hence I ploughed merrily thru "Hackers Delight", and thought I'd share what I learned and leave it hanging around the web in case I need it when being remote somewhere.

## You

Maybe you are in a  similar boat, or are just struggling to understand all the palava about binary and bitwise.  These files might help, I hope so.

Maybe you want an accompaniment to your own digestion of "Hackers Delight".

## Usage

There is one include file with some binary print functions which might help you visualise some of the values and two other dependcies,

` #include "binary_print.h" `

so when you do the likes of :

` pbin(7);`

` pbin_nb(23, "take an integer");`

` pbin_nb(7^23, "^ acts as a toggle")`



In your console you'll see :

` 0000 0111	(7)`

` 0001 0111	(23)  <-- take an integer`

` 0001 0000	(16)  <-- ^ acts as a toggle`


Then use the same methods to play around with values.<F8>

## Hold your horses

OK, I'm also learning how to use git, github and so on, so don't shoot me yet. I've never contributed anything to Open Source despite being a huge fan, and frequent advocate, so I still have to sort out licensing includes for these files, but honestly, help yourself. I also plaguerised a couple of SO posts and binary articles and intend to give due credit - though the comments should show these quite clearly.  
