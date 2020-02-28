#include <stdio.h>
#include <string.h>
#include "binary_printout.h"
	
/* short series of stupid stunts extracted from Hackers Delight book 2nd Ed. */	

/**
 * Again, division is costly, so to be avoided where pos.
 * This is what modulo uses, so is it worth? :
 *  
 * a) creating a function, storing it etc
 * b) calling it
 * 
 * Probably best to time it, or if you know you have a modulo eating
 * up resources in a loop somewhere, well maybe give this a try.
 * 
 * 
 * */


int main(void) {


	
	
	printf("\n\n(unsigned) Modulo extraction without pp 272\n");
	int remu3(int n) {
		return (0x55555555*n + (n >> 1) - (n >> 3)) >> 30;
	}
	unsigned int yU = 13;
	pbin_nb(yU, "get mod 3 of this (unsigned)");
	pbin_nb(yU%3, "classically");
	pbin_nb(remu3(yU), "remu3(yU)");
	
	
	printf("\n\n(signed) Modulo extraction without pp 272\n");
	
	int rems3(int n) {
		unsigned int r;
		r = n;
		r = (0x55555555*r + (r >> 1) - (r >> 3)) >> 30;
		return r - (((unsigned)n >> 31) << (r & 2));
		}
		
	int y = 17;	
	pbin_nb(y, "get mod 3 of this (signed)");
	pbin_nb(y%3, "classically");
	pbin_nb(rems3(y), "rems3(y)");	
	
	
	printf("\n\n(unsigned) Modulo and Quotient extraction pp 274\n");
	
	// reuse previous unsigned modulo extraction to work out quotient
	
	pbin_nb(yU, " yU = target");
	int modulo = remu3(yU);
	pbin_nb(modulo, " Modulo");
	pbin_nb((yU - modulo) * 0xAAAAAAAB, " generated Quotient");
	
	
	
	printf("\n\n(signed) Modulo and Quotient extraction pp 275\n");
	pbin_nb(y, " y = target");
	modulo = rems3(y);
	pbin_nb(modulo, " Modulo");
	pbin_nb((y - modulo) * 0xAAAAAAAB, " generated Quotient");

return 1;
}
