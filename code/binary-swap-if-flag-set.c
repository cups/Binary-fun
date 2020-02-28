#include <stdio.h>
#include <string.h>
#include "binary_printout.h"
	
/* short series of stupid stunts extracted from Hackers Delight book 2nd Ed. */	

int main(void) {
	
	int x = 13;
	int y = 7;
	
	printf("\n\nExchanging Registers depending on a bit flag (pp 45)\n");
	
	// swap vals of x and y if m_bit is one, or else leave them alone
	
	char flag = 0;
	printf("1. Before : \tx=%d, y=%d, flag=%d (traditionally)\n", x, y, flag);
	
	// traditionally - a branch
	if(!flag){
		x = x+y;
		y = x-y;
		x = x-y;
		}
	printf("1. After : \tx=%d, y=%d, flag=%d (traditionally)\n", x, y, flag);
	
	
	x = 13;
	y = 7;
	flag = -1;  // masks all bits for positive - so DO swap is done
	printf("\n2. Before : \tx=%d, y=%d, flag=%d (predicate)\n", x, y, flag);
	
	x = x^y;
	y = y^(x&flag);
	x = x^y;
	
	printf("2. After : \tx=%d, y=%d, flag=%d (predicate)\n", x, y, flag);
	
	x = 13;
	y = 7;	
	flag = 0;  // flag set to ignore all bits, so no swap is done
	printf("\n3. Before : \tx=%d, y=%d, flag=%d (predicate)\n", x, y, flag);
	
	x = x^y;
	y = y^(x&flag);
	x = x^y;
	
	printf("3. After : \tx=%d, y=%d, flag=%d (predicate)\n", x, y, flag);

return 1;
}
