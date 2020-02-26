#include <stdio.h>
#include <string.h>
#include "binary_printout.h"
	
/* short series of stupid stunts extracted from Hackers Delight book 2nd Ed. */	

int main(void) {

	printf("\n\nBounds checking - (chap 4)\n");
	printf("\n\nBig Caveats Here: \nUnsigned only\nBounds in hi/lo order\nSee gotchas, test this independently before using\n\n");
	unsigned int x = 12;
	unsigned int y = 4;
	
	unsigned int b = 10;
	unsigned int c = 20;
	printf("Bounds : x = %d, y =%d\n", x, y);
	pbin_nb(b, "target b");

	
	// some kinda magic here, see pp 69
	// only works with unsigned x and y
	
	pbin_nb((x-y) < (b-y), "Method 0  <-- GOTCHA - includes BOTH bounds"); 
	pbin_nb(x-y, "x-y to be less than :");
	pbin_nb(b-y, "b-y");
		
	if((x-y) < (b-y)) 
		printf("\n%d IS NOT between %d and %d", b, y, x);
	else	
		printf("\n%d IS between %d and %d", b, y, x);
		
		
	if((x-y) < (c-y)) 
		printf("\n%d IS NOT between %d and %d\n\n", c, y, x);
	else	
		printf("\n%d IS between %d and %d\n\n", c, y, x);		
		
	
	pbin_nb((b-x) < (b-y), "Method 1  <-- GOTCHA - includes LOWER bound only" );
	pbin_nb((b-x), "(b-x) to be less than :"); 
	pbin_nb((b-y), "(b-y)"); 
	
	if((b-x) < (b-y)) 
		printf("\n%d IS NOT between %d and %d", b, y, x);
	else	
		printf("\n%d IS between %d and %d", b, y, x);
		
		
	if((c-x) < (c-y)) 
		printf("\n%d IS NOT between %d and %d\n\n", c, y, x);
	else	
		printf("\n%d IS between %d and %d\n\n", c, y, x);	
	
	
	pbin_nb((x-y-1) < (b-y-1), "Method 2 <-- GOTCHA - includes HIGHER bound only");
	pbin_nb((x-y-1), "(x-y-1) to be less than : "); 
	pbin_nb((b-y-1), "(b-y-1)"); 
	
	
	if((x-y-1) < (b-y-1)) 
		printf("\n%d IS NOT between %d and %d", b, y, x);
	else	
		printf("\n%d IS between %d and %d", b, y, x);
		
	if((x-y-1) < (c-y-1)) 
		printf("\n%d IS NOT between %d and %d\n\n", c, y, x);
	else	
		printf("\n%d IS between %d and %d\n\n", c, y, x);		
	
	
return 1;
}
