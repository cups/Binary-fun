#include <stdio.h>
#include <string.h>
#include "binary_printout.h"
	
/* short series of stupid stunts extracted from Hackers Delight book 2nd Ed. */	

int main(void) {
	printf("\n2.2 Page 16 - Addition combined with logical operations\n=============================\n");
	
	int x = 23;
	
	pbin_nb (x, "23 - take an integer");
	pbin_nb (-x, "-23 - when minussed");
	pbin_nb (~x, "~23 then inversed");
	pbin_nb (~x+1, "~23 and add +1");
	printf( (-x == ~x+1) ? "a) -x and ~x+1 are the same\n": "-x == ~x+1 NOT the same\n");

	pbin_nb (~(x-1), "~23 or inverse (that number - 1)");
	printf( (-x == ~(x-1)) ? "b) -x and ~(x-1) are the same\n": "-x == ~(x-1) NOT the same\n");

	
	pbin_nb (~x, "~23 inverse a number");
	pbin_nb (~x, "then minus it and 1");
	printf( (~x == -x-1) ? "c) ~x and -x-1 are the same\n": "~x == -x-1 NOT the same\n");
	
	printf("\n(minus, invert) -~x SAME AS increment++\n");
	printf( (-~x == x+1) ? "d) -~x and x+1 are the same\n": "-~x == x+1 NOT the same\n");
	
	printf("\n(minus, invert) -~x SAME AS increment++, so increment by 3 :\n");
	printf( (-~-~-~x == x+3) ? "d) -~-~-~x and x+3 are the same\n": "-~-~-~x == x+3 NOT the same\n");
	
	printf("\n(invert, minus) ~-x SAME AS decrement--\n");
	printf( (~-x == x-1) ? "e) ~-x and x-1 are the same\n": "~-x == x-1 NOT the same\n");
	
	int y = 13;
		
	printf("\nGiven x and y :\n");
	pbin_nb(x, "x");
	pbin_nb(y, "y");
	pbin_nb(x & y, "x & y");
	pbin_nb(x | y, "x | y");
	pbin_nb(x ^ y, "x ^ y\n");
	
	printf("\n1. x+y are equal to :\n");
	pbin_nb(x+y, "x + y (23+13) : ");
	pbin_nb(x-~y-1, "f) x-~y-1");
	pbin_nb((x^y) + 2*(x&y), "g) (x^y) + 2*(x&y)");
	pbin_nb((x|y) + (x&y), "h) (x|y) + (x&y)") ;
	pbin_nb(2*(x|y) - (x^y), "i) 2*(x|y) - (x^y)") ;
	
	printf("\n2. x-y are equal to :\n");
	pbin_nb(x-y, "x - y (23-13) : ");
	pbin_nb(x+~y+1, "j) x+~y+1");
	pbin_nb((x^y) - 2*(~x&y), "k) (x^y) - 2*(~x&y)");
	pbin_nb((x&-y) - (-x&y), "l) (x&-y) - (-x&y)") ;
	pbin_nb(2*(x&~y) - (x^y), "m) 2*(x|y) - (x^y)") ;
	
	
	printf("\nn)implement x ^ y 'manually' :\n");
	pbin_nb(x ^ y, "x ^ y");
	
	pbin_nb(x|y, "(x|y)");
	pbin_nb(x&y, "(x&y)");
	pbin_nb((x|y)-(x&y), "(x|y)-(x&y)");
	
	

	

return 1;
}
