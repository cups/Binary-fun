#include <stdio.h>
#include <string.h>
#include "binary_printout.h"
	
/* short series of stupid stunts extracted from Hackers Delight book 2nd Ed. */	

int main(void) {



	printf("\n\nAlternating between boolean values - no branch (pp 48)\n");
	printf("Bool Toggle - When comparing two boolean vars\n");
	
	
	int X = 1;
	int A = 1;
	int B = 0;
	
	printf("\nStart : X=%d, A=%d, B=%d\n Traditionally : \n",X, A, B);
	printf("if X(%d) ==  A(%d) \n\tthen X=B (%d)\n else\n\tset X = A (%d)\n", X, A, B, A);
/* // traditionally what you'd do, or ternary switcher
	if(X == A) 
		X = B;
	else
		X = A;

	X = (X==A) ? B : A ;
*/

	X = A^B^X;
	
	printf("\nUsing X = A^B^X  reveals : \n");
	printf("END : X=%d, A=%d, B=%d\n",X, A, B);
	
	// NB this could also be like : X = (x>y)^B^X;
	

return 1;
}	
