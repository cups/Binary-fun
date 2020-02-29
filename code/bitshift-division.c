#include <stdio.h>
#include <string.h>
#include "binary_printout.h"
	
/* short series of stupid stunts extracted from Hackers Delight book 2nd Ed. */	


/**
 * Division is an extreme processor cylce dependent operation, miles more
 * than multiplication.  Some of this may rarely seem worthwhile, but if
 * the operation is buried in a nested loop somewhere, then it might be 
 * worth taking the time to develop one of these ideas.  
 * 
 * Probably best to try and think of another way round the problem 
 * without resorting to division.
 * 
 * Still, much of this looks like contrived voodoo.
 * */ 

int main(void) {

	printf("\n\nDivision by shifting\n");
	int x = 197;
	pbin_nb(x, "197 shifted >> 1 (ie halve it)");
	pbin(x>>1);

	printf("\n\n(signed) Division by multiplying by Magic Number\n");
	x=150;
	pbin_nb(x, "x");
	pbin_nb(0x55555556, "Magic No. #3 = 0x55555556 >> 1");
	pbin_nb((x*0x55555556) >> 1, "x*0x55555556 >> 1  - WHAAT?\n");

	pbin_nb(0xAAAAAAAB, "Magic No. #3 = 0xAAAAAAAB");
	pbin_nb((x*0xAAAAAAAB) , "x*0xAAAAAAAB - WHAAT?\n");
	
	printf("\nDivide by 10\n");	
	// via https://cboard.cprogramming.com/c-programming/128545-division-ten-magic-numbers.html
	// div by 10 - works up to 99,999
	pbin_nb(x, "x");
	pbin_nb((x * 6554UL) >> 16, "div by 10 (x * 6554UL) >> 16");	
	
	//https://stackoverflow.com/questions/4886290/division-by-a-constant-using-shifts-and-adds-subtracts/6976383#6976383
	printf("\n\nDivide 8000 by 41\n");
	pbin_nb((8000 * 0x5555) >> 22, "(8000 * 0x5555) >> 22");
	
	
	pbin((x * 0x5555) >> 16);
	

	
	// https://stackoverflow.com/questions/4886290/division-by-a-constant-using-shifts-and-adds-subtracts/6976383#6976383
	// file:///home/administrator/Downloads/kdiv/README.html
	// func generator for division by const, eg 23. Uses longs.

printf("\n\nDivision of %d by const 23 (/via S.O. 4886290)\n", x);
	
inline signed int kdiv_s32_p_23 (signed int n) {
	signed int q, M=-1307163959, c;
	signed long long int t;
	t = (signed long long int)M * (signed long long int)n;
	q = t >> 32;
	q = q + n;
	q = q >> 4;
	c = n >> 31;
	q = q + c;
  return (q);
}
	pbin(x); 
    pbin(kdiv_s32_p_23(x));

printf("\n\nDivision of %d by const 7 (pp 260)\n", x);
 
 int divBy7(int n) {
	 int q, r;
	 n = n + (n>>31 & 6);
	 q = (n >> 1) + (n >> 4);
	 q = q + (q >> 6);
	 q = q + (q >> 12) + (q >> 24);
	 q = q >> 2;
	 r = n - q*7;
	 return q + ((r+1) >> 3);
	 }
	 
	pbin(x); 
	pbin(divBy7(x));
	
return 1;
}
