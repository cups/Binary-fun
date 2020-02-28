#include <stdio.h>
#include <string.h>
#include "binary_printout.h"
	
/* short series of stupid stunts extracted from Hackers Delight book 2nd Ed. */	

int main(void) {

int x = 16;
int y = 15;

// wrapped into func just for easier testing, otherwise you wouldnt bother


	int isPowerOf2(int x) {
		return x > 0 && (x & (x - 1)) == 0;
	}
	
	int isOdd(int x) {
		return 1 & x;
	}
	
	int isEven(int x) {  // meh, same as !isOdd()
		return !(1 & x);
	}	
	
	printf("\n\nTest bitwise isPowerof2(%d)", x);
	printf( isPowerOf2(x) ? "\ntrue" : "\nfalse");
	
	printf("\n\nTest bitwise isPowerof2(%d)", y);
	printf( isPowerOf2(y) ? "\ntrue" : "\nfalse");	
	
	printf("\n\nTest bitwise isOdd(%d)", x);
	printf( isOdd(x) ? "\ntrue" : "\nfalse");
	
	printf("\n\nTest bitwise isOdd(%d)", y);
	printf( isOdd(y) ? "\ntrue" : "\nfalse");
	
	
	printf("\n\nTest bitwise isEven(%d)", x);
	printf( isEven(x) ? "\ntrue" : "\nfalse");
	
	printf("\n\nTest bitwise isEven(%d)", y);
	printf( isEven(y) ? "\ntrue" : "\nfalse");	

return 1;
}
