#include <stdio.h>
#include <string.h>
#include "binary_printout.h"
	
/* short series of stupid stunts extracted from Hackers Delight book 2nd Ed. */	

/**
 * Rounding up and down by powers of 2 - depends on whether the __builtin_clz()
 * (number[or count] leading [or trailing] zeros)instruction or equivalent is 
 * available on your target processor
**/

int main(void) {



	printf("\n\nRound DOWN to nearest power-of (signed) (pp 59)\n");
	int x = 71;
	pbin_nb(x, "let x");
	pbin_nb((x>>2) << 2, "a) use >> << to reduce down to nearest pwr of 4");
	pbin_nb((x>>3) << 3, "a) use >> << to reduce down to nearest pwr of 8\n");
	
	pbin(-4);
	pbin_nb(x, "x");
	pbin_nb(x&-4, "b) use neg mask to reduce down to nearest pwr of 4");
	pbin(-8);
	pbin_nb(x, "x");
	pbin_nb(x&-8, "b) use neg mask to reduce down to nearest pwr of 8");
	
	printf("\n\nRound UP to nearest power-of (signed) (pp 59)\n");
	x = 65;
	pbin_nb(x, "x");
	pbin_nb((x+3)&-4, "a) Round x up to pwr of 4 - set 3 then unset 3");
	pbin_nb((x+7)&-8, "a) Round up to pwr of 8 set 7 then unset 7");
	pbin_nb(x+(-x&3), "b) alt Round up to pwr of 4");
	pbin_nb(x+(-x&7), "b) alt Round up to pwr of 8");
	
	

	
	
	printf("\n\nALT Round DOWN to nearest power-of (signed) (pp 59)\n");
	x =15;
	pbin(x);
	pbin_nb(x&((-1)<<2),"use a mask to round down to by pwr 2");

	// function to Floor to next Lowest Pwr (FLP) (32 bit int only)

	int flp0(int x) {
		return 1<< (31-__builtin_clz(x));
		}
	int flp1(int x) {
		return 1 << (__builtin_clz(x)^31);
		}
	int flp2(int x) {
		return 0x80000000 >> (__builtin_clz(x));
		}		
		
	printf("\n\nFloor DOWN to nearest power-of  (pp 61)\n");
	unsigned int ui = 9;
	printf("where ui is %d\n", ui);	
	pbin(ui);
	pbin_nb(flp0(ui), "floor pwr funct 0");
	pbin_nb(flp1(ui), "floor pwr funct 1");
	pbin_nb(flp2(ui), "floor pwr funct 2");

	int clp0(int x) {
		return 1 << (32 - __builtin_clz(x-1));
		}	
	int clp1(int x) {
		return 0x80000000 >> (__builtin_clz(x-1)-1);
		}	
	printf("\n\nCeil UP to nearest power-of  (pp 61)\n");
	printf("where ui is %d\n", ui);	
	pbin(ui);
	pbin_nb(clp0(ui), "ceiling up pwr 0");
	pbin_nb(clp1(ui), "ceiling up pwr 1");
	
return 1;
}	
