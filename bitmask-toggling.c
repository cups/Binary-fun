#include <stdio.h>
#include <string.h>
#include "binary_printout.h"
	
/* short series of stupid stunts extracted from Hackers Delight book 2nd Ed. */	

int main(void) {
	printf("\nToggle all (1) - 8 and ~ not 8\n");
	int x = 8;
	pbin(x);
	x = ~x ;
	pbin(x);
	
	printf("\nToggle all (2) - 7 and ~ not 7\n");
	x = 7;
	pbin(x);
	x = ~x ;
	pbin(x);
	
	

	printf("\nTurn all on (1) ~ not 0\n");
	x = 0;
	pbin(x);
	x = ~x ;
	pbin(x);
	
	printf("\nTurn all on (2) - use straight -1\n");
	x = -1;
	pbin(x);
		
	printf("\nTurn all off - use straight 0\n");
	x = 0;
	pbin(x);
	
	printf("\nMinus number -8 (2s compliment)\n");
	x = -8;
	pbin(x);
	printf("\nMinus number -8, ~ inverted (2s compliment)\n");
	x = ~x;
	pbin(x);

return 1;
}
