#include <stdio.h>
#include <string.h>
#include "binary_printout.h"
	
/* short series of stupid stunts extracted from Hackers Delight book 2nd Ed. */	

int main(void) {

	printf("\n\nInteger Logarithm \n");
	printf("Log Power of 2 (trivial) clz() dependent\n");
	
	unsigned int yU = 256;
	int ilog2(int x) {
		return 31 - __builtin_clz(x);
		}
	
	pbin_nb(yU, "get log2 of this");
	pbin_nb(ilog2(yU), "feed an int, get its pwr, just use clz() func");
	
	printf("\nLog Power of 10 (non-trivial) clz() dependent\n");
	
	int iLog10(unsigned int x) {
		
		int y;
		static unsigned int table1[33] = {9,9,9,
			8,8,8,	7,7,7,	6,6,6,6,
			5,5,5,	4,4,4,	3,3,3,3,
			2,2,2,	1,1,1,	0,0,0,0
			};
		
		static unsigned int table2[10] = {1, 10, 100,
			1000, 		10000, 		100000,
			1000000,	10000000, 	100000000,
			1000000000 };
		
		y = table1[__builtin_clz(x)];
		if(x < table2[y]) y = y -1;
		return y;
		}
		yU = 100000;
		pbin_nb(yU, "get log10 of this");
		pbin(iLog10(yU));

return 1;
}
