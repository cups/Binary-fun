#include <stdio.h>
#include <string.h>
#include "binary_printout.h"
	
/* short series of stupid stunts extracted from Hackers Delight book 2nd Ed. */	

int main(void) {
	// http://graphics.stanford.edu/~seander/bithacks.html#IntegerMinOrMax

	int x = 7;
	int y = 9;

	printf("\n\nPredicate min or max without using a doz() method\n(Difference or Zero)\n");
	printf("\n\nGet MIN of two ints where : \tx = %d, y = %d", x, y);

	pbin_nb(  x, "x");	
	pbin_nb(  y, "y");	
	pbin_nb(  (x ^ y), " (x ^ y) :");	
	pbin_nb(  -(x < y), " -(x < y) - gives either all 1s or all 0s:");	
	pbin_nb( ((x ^ y) & -(x < y)), " right side - ((x ^ y) & -(x < y))");	
	pbin_nb(  y, "y apply ^ vs right side");	
	
	printf("\n1) MIN of %d and %d is %d (method 1)", x, y, y ^ ( (x ^ y) & -(x < y) ));
	printf("\n1 a) MIN of %d and %d is %d\n", y, x, y ^ ( (x ^ y) & -(x < y) ));
	
	printf("\n2) MIN of %d and %d is %d (method 2 [>> 31])", x, y, y + ((x - y) & ((x - y)) >> 31));
	printf("\n2 a) MIN of %d and %d is %d\n", y, x, y + ((x - y) & ((x - y)) >> 31));
	
	printf("\nMAX of %d and %d is %d", x, y, y ^ ( (x ^ y) & -(x > y) ));
	printf("\nMAX of %d and %d is %d\n", y, x, y ^ ( (x ^ y) & -(x > y) ));
	
	
	
/*
 * EXPLANATION of above
 * 
Get MIN of two ints 	x = 7, y = 9
0000 0111	(7)  <-- x
0000 1001	(9)  <-- y
0000 1110	(14)  <--  (x ^ y) :
1111 1111	(-1)  <--  -(x < y) - gives either all 1s or all 0s: <-- i.e. create the mask 
0000 1110	(14)  <--  right side - ((x ^ y) & -(x < y))
0000 1001	(9)  <-- y apply ^ vs right side
MIN of 7 and 9 is 7
 
Get MIN of two ints 	x = 9, y = 7 (swap values)
0000 1001	(9)  <-- x
0000 0111	(7)  <-- y
0000 1110	(14)  <--  (x ^ y) :
0000 0000	(0)  <--  -(x < y) - gives either all 1s or all 0s: <-- i.e. create the mask 
0000 0000	(0)  <--  right side - ((x ^ y) & -(x < y))
0000 0111	(7)  <-- y apply ^ vs right side
MIN of 9 and 7 is 7
 
*/
	
	int getMax(int x, int y){
		return y ^ ( (x ^ y) & -(x > y) );
		}
		
	int getMin(int x, int y) {
		return y ^ ( (x ^ y) & -(x < y) );
		}	
	

		
	printf("\n\nTest bitwise getMax()");
	printf("\nMAX of %d and %d is %d", x, y, getMax(x, y));
	
	printf("\n\nTest bitwise getMin()");
	printf("\nMIN of %d and %d is %d", x, y, getMin(x, y));	
	

	printf("\n\nPredicate Max and Min without a doz() [SIGNED]\n");
	
	x= 7;
	y= 9;
	printf("\nx = %d, y = %d\n", x, y);
	printf("Max of (%d, %d) = %d\n", x, y, ((x^y) & -(x>=y)) ^ y);	
	printf("Min of (%d, %d) = %d\n", x, y, ((x^y) & -(x<=y)) ^ y );	
		
	x = 9;
	y = 7;
	printf("\nx = %d, y = %d\n", x, y);
	printf("Max of (%d, %d) = %d\n", x, y, ((x^y) & -(x>=y)) ^ y);	
	printf("Min of (%d, %d) = %d\n", x, y, ((x^y) & -(x<=y)) ^ y);	 
	
	x= -7;
	y= 9;
	printf("\nx = %d, y = %d\n", x, y);
	printf("Max of (%d, %d) = %d\n", x, y, ((x^y) & -(x>=y)) ^ y);	
	printf("Min of (%d, %d) = %d\n", x, y, ((x^y) & -(x<=y)) ^ y );	
		
	x = -9;
	y = 7;
	printf("\nx = %d, y = %d\n", x, y);
	printf("Max of (%d, %d) = %d\n", x, y, ((x^y) & -(x>=y)) ^ y);	
	printf("Min of (%d, %d) = %d\n", x, y, ((x^y) & -(x<=y)) ^ y);
return 1;
}
