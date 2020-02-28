#include <stdio.h>
#include <string.h>
#include "binary_printout.h"
	
/* short series of stupid stunts extracted from Hackers Delight book 2nd Ed. */	

int main(void) {

	printf("\n\n(signed) Integer Square Root\n");
	printf("\n1. Newton Method (with __builtin_clz() available\n");
	
	int sqrtNewtonsMethod(int x) {
	int s, g0, g1;
	
	if(x <= 1) return x;	
	
	s = 16 - (__builtin_clz(x - 1) >> 1); 
	g0 = 1<<s;
	g1 = (g0 + (x >> s)) >> 1;	
	
		while(g1 < g0) {
			g0 = g1;
			g1 = (g0 + (x/g0)) >> 1;  // <-- eek, division
		}
	return g0;
	}
	
	unsigned int yU = 146456;
	pbin_nb(yU, "yU");
	pbin_nb(sqrtNewtonsMethod(yU), "Newton Method sqrt of yU");
	
	printf("\n\n2. Binary Search Method (with __builtin_clz() available\n");	
	
	int sqrtBinarySearch(int x) {
		int a, b, m; // t;
		
		// yeah, I think maybe I refactored out the division...
		
		// SANS a clz function - tgt = 146456 = 13 iterations
		// a = 1;
		// b = (x >> 5) + 8;

		// WITH a clz function - tgt = 146456 = 8 iterations	
		b = (1 << ((33 - __builtin_clz(x)) >>1)) - 1;
		a = (b + 3) >> 1;
		
		if(b > 65535) b = 65535;
		
		do{
			m = (a + b) >> 1;
			if(m*m > x) 
				b = m -1;
			else
				a = m +1;
			} while (b>=a);
		
		return a-1;
	}
	
	pbin_nb(yU, "yU");
	pbin_nb(sqrtBinarySearch(yU), "Binary Search sqrt of yU");
	

return 1;
}
