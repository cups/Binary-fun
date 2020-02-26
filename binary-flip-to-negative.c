#include <stdio.h>
#include <string.h>
#include "binary_printout.h"
	
/* short series of stupid stunts extracted from Hackers Delight book 2nd Ed. */	

int main(void) {




		// https://ryanstutorials.net/binary-tutorial/binary-negative-numbers.php

	printf("\nNegative numbers\n");
	int x = 3;
	int y = -3;
	pbin_nb(x, "3");
	pbin_nb(~x, "~ 3\n");
	
	pbin_nb(y, " -3");	
	pbin_nb(~y, "~ -3");
	
	
	printf("\nNegative numbers - equivalent of flip (~) and add one\n");
	pbin_nb(~x+1, "~ 3 +1");
	pbin_nb(~y+1, "~ -3 +1");
	
	
	
return 1;
}	
