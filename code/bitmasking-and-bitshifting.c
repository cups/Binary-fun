#include <stdio.h>
#include <string.h>
#include "binary_printout.h"
	
/* short series of stupid stunts extracted from Hackers Delight book 2nd Ed. */	

int main(void) {

// https://www.codementor.io/@erikeidt/bit-twiddling-understanding-bit-operations-iqj68ynb7

// bit shifting negative numbers - can be dodgy to move >> right
// unsigned ints = logical shift (adds 000s from right)
// signed ints (negative) = mathematical shift (adds 1s from right)
// signed ints (positive) = same as logical shift


int x = 11;
int y = -11;
	printf("\n\nBit shifting ints, esp negative \tx = %d, y = %d\n", x, y);
	pbin_nb(  x, "x");	
	pbin_nb(  x >> 2, "x >> 2");
	pbin_nb(  x << 2, "x << 2");
		
	pbin_nb(  y, "y");	
	pbin_nb(  y >> 2, "y >> 2 (halving an odd number, add 1 back on when done)");	// GOTCHA
	pbin_nb(  y << 2, "y << 2");

x = 15;
y = 61;
	printf("\n\nBitmasking - 1 with &\tx = %d, y = %d\n", x, y);
	pbin_nb(  x, "x - 1s 'mask' a tpl for what to grab - last 4 bits");	
	pbin_nb(  y, "y = now apply a & mask");		
	pbin(x&y);
	
x = 8;
	printf("\n\nBitmasking - 2 - with &\tx = %d, y = %d\n", x, y);
	pbin_nb(  x, "x - 1+0s 'mask' = tpl for what to grab - and clear");	
	pbin_nb(  y, "y = now apply a & mask");		
	pbin(x&y);
	
x = 79;
	printf("\n\nBitmasking - 3 - with |\tx = %d, y = %d\n", x, y);
	pbin_nb(  x, "x - 1+0s 'mask' to force SET on unset bits");	
	pbin_nb(  y, "y = now apply a | mask");		
	pbin(x|y);	
	
	x = 3;
	printf("\n\nBitmasking - 4 - with ^ (toggle)\tx = %d, y = %d\n", x, y);
	pbin_nb(  x, "x - 1+0s 'mask' to toggle named (1) bits");	
	pbin_nb(  y, "y = now apply a ^ mask");		
	pbin_nb(x^y, "first 2 bits of 61 now toggled");
	
	x = 3;
	printf("\n\nBitmasking - 5 - with ~ (complement)\tx = %d, y = %d\n", x, y);
	pbin_nb(  y, "y apply ~ with no mask");		
	pbin(~y);		
	pbin_nb(~y+1, "apply ~ and add 1 for negation");		
	pbin_nb(  x, "x apply ~ with no mask");		
	pbin(~x);		
	pbin_nb(~x+1, "apply ~ and add 1 for negation");


return 1;
}
