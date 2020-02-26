#include <stdio.h>
#include <string.h>
#include "binary_printout.h"
	
/* short series of stupid stunts extracted from Hackers Delight book 2nd Ed. */	

int main(void) {




	printf("\n2.4 Average ints (no overflow)\n");
	
	int x = 12;
	int y = 25;
	pbin_nb(x, "x");
	pbin_nb(y, "y");
	printf("Math : avg x, y %d\n", (x+y) >> 1);
	
	pbin_nb(x&y, " (&): x&y");
	pbin_nb((x^y), "(^) x^y");
	pbin_nb((x^y) >> 1, "(halve): (x^y) >> 1");
	pbin_nb((x&y)+((x^y) >> 1), "(x&y)+((x^y) >> 1) -- ooh! round down");  	// USEFUL
	
	printf("\nAverage ints (sans overflow protection)\n");

	pbin_nb(x|y, " (|): x|y");
	pbin_nb((x^y), "(^) x^y");
	pbin_nb((x^y) >> 1, "(halve): (x^y) >> 1");
	pbin_nb((x|y) - ((x^y) >> 1), "(x|y) - ((x^y) >> 1)  -- ooh! round up\n");  			// USEFUL

	pbin_nb((x+y) >> 1,"simplest, (x+y) >>1");
	
	return 1;
}
