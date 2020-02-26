#include <stdio.h>
#include <string.h>
#include "binary_printout.h"
	
/* short series of stupid stunts extracted from Hackers Delight book 2nd Ed. */	

int main(void) {




printf("\n2.3 Inequality among Logical and Math expressions\n\nLet x and y be\n");
	
	int x = 23;
	int y = 13;
	
	pbin_nb(x, "x");
	pbin_nb(y, "y\n");
	
	pbin_nb(x^y, "x^y");
	pbin_nb(x|y, "x|y\n");
	
	printf(((x^y) <= (x|y)) ? "^ always <= |\n" : "nope, bigger\n");
	
	pbin_nb((x|y) >= x, "x|y will always be >= than biggest of x and y");
	pbin_nb((x&y) <= x, "x&y will always be <= than lowest of x and y");
	
	
return 1;
}		
	
