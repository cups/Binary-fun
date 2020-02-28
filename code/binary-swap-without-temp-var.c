#include <stdio.h>
#include <string.h>
#include "binary_printout.h"
	
/* short series of stupid stunts extracted from Hackers Delight book 2nd Ed. */	

int main(void) {

	printf("\n\nExchanging Registers with NO temp var (pp 45)\n");
	int x = 7;
	int y = 9;
	
	printf("x = %d\n", x);
	printf("y = %d\n", y);
	
	
	pbin8_nb(x, "x");
	pbin8_nb(y, "y");
	
	x = x^y;
	pbin8_nb(x, "x = x^y");
	y = y^x;
	pbin8_nb(y, "y = y^x");
	x = x^y;
	pbin8_nb(x, "x = x^y");

	printf("x = %d\n", x);
	printf("y = %d\n\n", y);
	printf("Now swap back (method 2): \n");
	
	x = x+y;
	pbin8_nb(x, "x = x+y");
	y = x-y;
	pbin8_nb(y, "y = x-y");
	x = x-y;
	pbin8_nb(x, "x = x-y");

	
	printf("x = %d\n", x);
	printf("y = %d\n", y);

return 1;
}
