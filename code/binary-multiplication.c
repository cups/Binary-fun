#include <stdio.h>
#include <string.h>
#include "binary_printout.h"
	
/* short series of stupid stunts extracted from Hackers Delight book 2nd Ed. */	

int main(void) {
	
	printf("\nMultiply by power and add a number\n");
	int hi = 3, lo = 6, lshift = 4;
	printf("shift by %d (%d)\n", lshift, 1 << lshift);
	pbin_nb(hi, "hi");
	pbin_nb(lo, "lo (doesnt work at 16 or above)");
	pbin_nb(hi << lshift, "hi << 4");
	
	
	
	printf("\nMultiply by power and add a number\n");
	printf("\n(hi*16)+lo) = %d", (hi*16)+lo);
	printf("\n(hi << lshift)|lo = %d", (hi << lshift)|lo);

return 1;
}
