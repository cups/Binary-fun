#include <stdio.h>
#include <string.h>
#include "binary_printout.h"
	
/* short series of stupid stunts extracted from Hackers Delight book 2nd Ed. */	

int main(void) {


	printf("\nManipulation of Rightmost bits\n===================");
    
	printf("\nturn rightmost 1 off with & -1\n");
	int x = 164;
	pbin(x);
	pbin_nb(x-1, "-1, now apply & AND");
	x = x & (x-1);
	pbin(x);
	
	
	printf("\nturn on rightmost 0 with | +1\n");
	x = 167;
	pbin(x);
	pbin_nb(x+1, "+1, now apply OR ");
	x = x | (x+1);
	pbin(x);
	
	printf("\nturn on contigious rightmost 1s off & +1\n");
	x = 27;
	pbin(x);
	pbin_nb(x+1, "+1, now apply & AND ");
	x = x & (x+1);
	pbin(x);
	
	x = 31;
	if( (x & (x+1)) == 0){
		printf("\n%d is a power - 1 or all 0s or all 1s\n", x);
		}
	
	printf("\nturn all trailing 0s on with | -1\n");
	x = 168;
	pbin(x);
	pbin_nb(x-1, "-1, now apply | OR ");
    x = x | (x-1);
    pbin(x);  
    	
	printf("\ncreate single byte at rightmost 0, with ~x & +1\n");
	x = 167;
	pbin(x);
	x = ~x & (x+1);
	pbin(x);
    
	printf("\nturn all on except rightmost 1, at rightmost 1, with ~x | -1\n");
	x = 168;
	pbin(x);
	x = ~x | (x-1);
	pbin(x);
	
	return 1;
	}
