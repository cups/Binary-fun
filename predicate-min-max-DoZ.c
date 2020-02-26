#include <stdio.h>
#include <string.h>
#include "binary_printout.h"
	
/* short series of stupid stunts extracted from Hackers Delight book 2nd Ed. */	

int main(void) {



	printf("\n\nPredicate Max and Min using a doz() Diff or Zero [SIGNED]\n");
	
	// pp 43 hackers delight
	
	// Difference Or Zero if x > y only
	int doz(int x, int y){
		return (x-y) & -(x>=y);  // get diff then apply a switch/mask of 0s or 1s
		}
		
	int x= 7;
	int y= 9;
	printf("\ndoz(%d, %d) = %d (Gotcha: x not > 9!)\n", x, y, doz(x, y));
	printf("Max using doz(%d, %d) + y = %d\n", x, y, y + doz(x, y));	
	printf("Min using doz(%d, %d) sans x = %d\n", x, y, x - doz(x, y));
		
	x= -7;
	y= 9;
	printf("\ndoz(%d, %d) = %d\n", x, y, doz(x, y));
	printf("Max using doz(%d, %d) = %d\n", x, y, y + doz(x, y));	
	printf("Min using doz(%d, %d) = %d\n", x, y, x - doz(x, y));
	x= 7;
	y= -9;
	printf("\ndoz(%d, %d) = %d\n", x, y, doz(x, y));
	printf("Max using doz(%d, %d) = %d\n", x, y, y + doz(x, y));	
	printf("Min using doz(%d, %d) = %d\n", x, y, x - doz(x, y));
		
	x = 9;
	y = 7;
	printf("\ndoz(%d, %d) = %d\n", x, y, doz(x, y));	
	printf("Max using doz(%d, %d) = %d\n", x, y, y + doz(x, y));	
	printf("Min using doz(%d, %d) = %d\n", x, y, x - doz(x, y));	
	

	
return 1;
}	
