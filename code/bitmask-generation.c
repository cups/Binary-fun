#include <stdio.h>
#include <string.h>
#include "binary_printout.h"
	
/* short series of stupid stunts extracted from Hackers Delight book 2nd Ed. */	

int main(void) {


	printf("\n\nDynamic Bitmask Generation - 1 - right shift 1 for single pow(2) number\n" );
	int i = 8;
	while(i>0){
		pbin(1 << (8-i));
		i--;
	}
	
	printf("\n\nDynamic Bitmask Generation - 1 - its complement, right shift a 0\n" );
	i = 8;
	while(i>0){
		pbin(~(1 << (8-i)));
		i--;
	}

	printf("\n\nDynamic Bitmask Generation - 2 - generate a set of consecutive 1's\n" );
	// ie if '4' becomes 8, then -1 becomes 7 = 111.
	i = 8;
	while(i>0){
		i--; // GOTCHA
		pbin((1 << (8-i)) - 1);
	}
	
	printf("\n\nDynamic Bitmask Generation - 2 - its complement, infill 0s\n" );
	// ie if '4' becomes 8, then -1 becomes 7 = 111.
	i = 8;
	while(i>0){
		i--; 
		pbin(~((1 << (8-i)) - 1));
	}	
	
	printf("\n\nDynamic Bitmask Generation - 3 - consecutive 1's, leave trailing 0s\n" );
	// ie if '4' becomes 8, then -1 becomes 7 = 111 - but then shift, say, twice = 11100.
	i = 8;
	int trailing = 2;
	while(i>0){
		pbin(((1 << (8-i)) - 1) << trailing);
		i--;
	}
	
	printf("\n\nDynamic Bitmask Generation - 3 - its complement, leave trailing 1s\n" );
	i = 8;
	trailing = 2;
	while(i>0){
		pbin(~(((1 << (8-i)) - 1) << trailing));
		i--;
	}
	


return 1;
}
