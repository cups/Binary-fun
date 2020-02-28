#include <stdio.h>
#include <string.h>
#include "binary_printout.h"
	
/* short series of stupid stunts extracted from Hackers Delight book 2nd Ed. */	

int main(void) {


	printf("\n\n Multiplication by shifting (pp 175)\n");
	printf("\n\n Multiplication by shifting - probably only useful for 'handy' consts\n");
	printf("ie those at or near powers : \n");

	int x = 10;
	int y = 13;
	printf("\nLet x - %d, y = %d\n", x, y);
	pbin(y);
	pbin_nb(x*y, "10*13 (x*y)");
	pbin_nb((x<<3)+(x<<2)+x, "(x<<3)+(x<<2)+x");
	printf("OR, simpler ...\n");
	pbin_nb(x*y, "13*10 (y*x) <-- 10 closer to powers 2");
	pbin_nb((y<<3)+(y<<1),"(y<<3)+(y<<1)");
	
	x = 10;
	y = 45;
	printf("Let x - %d, y = %d\n", x, y);
	pbin(y);
	pbin_nb(x*y, "10*45");
	pbin_nb((x<<5)+(x<<3)+(x<<2)+x, "(x<<5)+(x<<3)+(x<<2)+x");
	printf("OR, simpler ...\n");
	pbin_nb(y*x, "45*10 <--again, 10 closer to powers 2");
	pbin_nb((y<<3)+(y<<1), "(y<<3)+(y<<1)");
	
	

	printf("\n\n Multiplication by shifting - single 0\n");
	int ff = 0b110111;  // look, 3rd bit is zero
	x = 10;
	pbin_nb(ff, "const ff * x (eg single 0 in block of 1s)");
	pbin_nb(x, "x = 10");
	pbin_nb(ff, " * 10");
	printf("so shift 1 extra power up (ie 64) then minus off the zero PLUS the extra pwr 2 used to get to 64");
	pbin_nb((x << 6) - (x << 3) - x, "(x << 6) - (x << 3) - x\n"); 
	
	// another stupid example of what to do with 0s
	
	printf("\n\nMultiplication by shifting - multi 0 - odd nos\n");
	ff = 0b1001;  // look, 1st, 2nd bits are zero
	x = 10;
	pbin_nb(ff, "const ff * x (eg multi 0s in block of 1s)");
	pbin_nb(x, "x = 10");
	pbin_nb(ff, " * 9");
	// so shift ABOVE (16) then minus off the zeros AND the extra pwr 2 used to get to 16
	pbin_nb((x << 4) - (x << 2) - (x << 1) - x, "(x << 4) - (x << 2) - (x << 1) - x");
	
	printf("\n\nMultiplication by shifting - multi 0 - even nos\n");
	ff = 0b1110 ;  // look, first bit is zero
	// formula is preceding bit (pos 4) minus last set bit (pos 1)
	x = 0b1001; 
	pbin_nb(ff*x, "target ff*x");
	pbin_nb(ff, "const ff * x (eg multi 0s in block of 1s)");
	pbin_nb(x, "x = 9");
	pbin_nb(ff, " * 10");
	// so shift ABOVE (16) then minus off the zeros NOT the extra pwr 2 used to get to 16
	pbin_nb((x << 4) - (x << 1), "(x << 4) - (x << 1) ");
	
	
	printf("\n\nMultiplication by shifting - by factors eg 45 = 9*5\n");
	printf("9 = x<<4 + 1x, 5 = x <, 2 + 1x\n");
	x=10;
	pbin_nb(45, "45");
	pbin_nb(9, "9");
	pbin_nb(5, "5");
	pbin_nb(x*45, "10*45\n");
	x = (x<<2)+x;
	pbin_nb(x, "(x<<2)+x now is x is 50");
	pbin_nb((x<<3)+x, "(x<<3)+x multiply 50 by 9 (<<3 + 1)");
	
	


return 1;
}
