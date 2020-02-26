#include <stdio.h>
#include <string.h>
#include "binary_printout.h"
	
/* short series of stupid stunts extracted from Hackers Delight book 2nd Ed. */	

int main(void) {

	printf("\nInvert trailing 0s, rest to 0s (1) ~x & -1\n");
	int x = 88;
	pbin_nb(x, "88");
	pbin_nb(x-1, "-1 : 87");
	pbin_nb(~x, "~88");
	x = ~x & (x-1); 
	pbin_nb(x, "& applied");
	
	printf("\nInvert trailing 0s, rest to 0s (2) ~ x | -x\n");
	x = 88;
	pbin(x);
	pbin_nb(-88, "now run OR on these two");
	pbin_nb(-89, "+1, fyi, now this is the inverse");
	x = (x | -x); 
	pbin_nb(x, "intermediate after OR, without the not ~");
	pbin_nb(~x, "after inverse ~");
	
	
	printf("\nInvert trailing 0s, rest to 0s (3) x & -x -1\n");
	x = 88;
	pbin(x);
	pbin_nb(-88, "now run & on these two");
	x = 88 & -88;
	pbin_nb(x, "now minus 1");
	pbin(x-1);
	
	printf("\nSubtraction (1)\n");
	x = 17;
	int y = 5;
	pbin(x);
	pbin(y);
	pbin(x-y);


	
	pbin(x+(x+y));
	pbin(167);
	pbin(-168);
	pbin(88);
	
	
	printf("\n0s replace trailing 1s - fill all else with 1s\n");
	x = 119;
	pbin(x);
	pbin_nb(~x | (x+1), "~x | (x+1)");
	
	
	printf("\n0s replace trailing 1s - fill all else with 1s\n");
	x = 88;
	pbin(x);
	pbin_nb(x ^ (x-1), "x ^ (x-1)");
	
return 1;
}	
