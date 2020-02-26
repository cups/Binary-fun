#include <stdio.h>
#include <string.h>
#include "binary_printout.h"
	
/* short series of stupid stunts extracted from Hackers Delight book 2nd Ed. */	

int main(void) {

	
	
	printf("\n\nPredicate exactly 2 bools out of 3 are set or not (pp 52)\n");
	
	// return if exactly 2 of 3 bools are set
	int twoSet(int x, int y, int z) {
			pbin_nb(~x&y&z, "~x&y&z");	// all dbg, a function was used for clarity only
			pbin_nb(~x, "\t ~x");
			pbin_nb(x&~y&z, "x&~y&z");	
			pbin_nb(~y, "\t ~y");
			pbin_nb(x&y&~z, "x&y&~z");	
			pbin_nb(~z, "\t ~z");		
		return (x&y&~z) + (x&~y&z) + (~x&y&z);
		
		}
	int X = 1;
	int A = 1;
	int B = 1;
	
	printf("FALSE twoSet(%d,%d,%d) = %d\n", X, A, B, twoSet(X, A, B));
	B = 0;  
	printf("TRUE twoSet(%d,%d,%d) = %d\n", X, A, B, twoSet(X, A, B));
	A = 0;
	printf("FALSE twoSet(%d,%d,%d) = %d\n", X, A, B, twoSet(X, A, B));
	X = 0;
	printf("FALSE twoSet(%d,%d,%d) = %d\n", X, A, B, twoSet(X, A, B));
	A=1, B=1;
	printf("TRUE twoSet(%d,%d,%d) = %d\n", X, A, B, twoSet(X, A, B));
	


return 1;
}
