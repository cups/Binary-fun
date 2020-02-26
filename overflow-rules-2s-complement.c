#include <stdio.h>
#include <string.h>
#include "binary_printout.h"
	
/* short series of stupid stunts extracted from Hackers Delight book 2nd Ed. */	

int main(void) {


int x = 10;
int y = 14;

	// Overflow rules 2s complement only
	// http://sandbox.mc.edu/~bennet/cs110/tc/orules.html
	
	printf("\n\nOverflow rules on 2s Complement\n" );
	
int max_int = 2147483647;
int min_int = -2147483647 -1;
printf("\nmax %d", max_int);
printf("\nmin %d", min_int);

if((max_int + x) < 0)
	printf("\nOverflow of two positives, gives a negative %d, your stuff would fail", (max_int + x));
	
	x = -10;
if((min_int + x) > 0)
	printf("\nOverflow of two negatives, gives a positive %d, your stuff would fail", (min_int + x));
	 

	printf("\n\nDetect a negative number\n" );
	
if(!__builtin_clz(y))
	printf("\nA negative signed int detected (%d) with __builtin_clz() == %d", y, __builtin_clz(y));

if(!__builtin_clz(x))
	printf("\nA negative signed int detected (%d) with __builtin_clz() == %d", x, __builtin_clz(x));	
	
	
return 1;
}	
