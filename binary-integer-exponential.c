#include <stdio.h>
#include <string.h>
#include "binary_printout.h"
	
/* short series of stupid stunts extracted from Hackers Delight book 2nd Ed. */	

int main(void) {
	
	printf("\n\nInteger Exponential Calculator \n");
	
	int iexpVociferous(int x, unsigned int n) {  // vociferous example, just to peek inside
		int p, y;
		
		y = 1;
		p = x;
		while(1) {  // iterates through exp bits from right to left
			printf("iteration");
			if(n & 1) { 
				y = p*y;
				printf(" - 1 - %d\n", y);  // exp bit was on (sum * y) and squared
				
			}else {
				printf(" - 0 - %d\n", y);  // exp bit was off (sum) and squared
				}	
			n = n >> 1;
			if(n == 0) return y;
			p = p*p;             // <- squared
			}
			
	}
	int x = 4;
	unsigned int yU = 13;
	printf("\n%d to the power of %d\n",x, yU );
	pbin_nb(iexpVociferous(x, yU), "iexpVociferous(x, uY)");
	
	printf("\n%d to the power of %d\n",yU, x );
	pbin_nb(iexpVociferous(yU, x), "iexpVociferous(uY, x)");
	
	int iexp(int x, unsigned int n) {  
		int p, y = 1;
		p = x;
		while(1) {  
			if(n & 1) y = p*y;
			n = n >> 1;
			if(n == 0) return y;
			p = p*p;             
			}
	}	
	
	x = 2;
	yU = 8;
	printf("\n%d to the power of %d\n",x, yU );
	pbin_nb(iexp(x, yU), "iexp(x, uY)");
	

return 1;
}
