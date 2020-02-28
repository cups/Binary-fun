#include <stdio.h>
#include <string.h>
#include "binary_printout.h"
	
/* short series of stupid stunts extracted from Hackers Delight book 2nd Ed. */		

int main(void) {
    printf("\n\nBitmask operations (basics) \n");

	char x = 0b01110;
	char y = 0b10101;
	
	pbin8_nb(x, "x The target");
	pbin8_nb(y, "y The bitmask\n");
	pbin8_nb(y^x, "^ = Toggle (set bits only)");
	pbin8_nb(x&y, "& = Common set bits");
	pbin8_nb(x|y, "| = Any set bits");    

return 1;
}
