#include <stdio.h>
#include <string.h>
#include "binary_printout.h"
	
/* short series of stupid stunts extracted from Hackers Delight book 2nd Ed. */	

int main(void) {
	
	int x = 25;
	int y = 25;
	
	// Check if two ints are definitely NOT the same
	
	printf("\n\n3) Comparison predicates (neg test for !equal) \tx = %d, y = %d\n", x, y);
	
	pbin_nb( -abs(x-y) >> 31, "-abs(x-y) >> 31 asserts :");	
	printf(	-abs(x-y) >> 31 ? "true\n" : "false\n");
	
	pbin_nb( (__builtin_clz(x-y)-31), "-(__builtin_clz(x-y)-32) >> 31 asserts :");	
	printf(	(__builtin_clz(x-y)-31) ? "true\n" : "false\n");
	
	pbin_nb( (x-y) | (y-x) >> 31, " (x-y | y-x) >> 31 asserts :");	
	printf(	(x-y) | (y-x) >> 31 ? "true\n" : "false\n");
	
	x = 12;
	y = 25;
	
	printf("\n\n3 a) Comparison predicates (neg test for !equal) \tx = %d, y = %d\n", x, y);
	
	pbin_nb( -abs(x-y) >> 31, "-abs(x-y) >> 31 asserts :");	
	printf(	-abs(x-y) >> 31 ? "true\n" : "false\n");
	
	pbin_nb( (__builtin_clz(x-y)-31), "-(__builtin_clz(x-y)-32) >> 31 asserts :");	
	printf(	(__builtin_clz(x-y)-31) ? "true\n" : "false\n");
	
	pbin_nb( (x-y) | (y-x) >> 31, " (x-y | y-x) >> 31 asserts :");	
	printf(	(x-y) | (y-x) >> 31 ? "true\n" : "false\n");
	
	
	y = -7;
	x = -25;
	
	printf("\n\n4) Comparison predicates (pos test for !equal) \tx = %d, y = %d\n", x, y);
	
	pbin_nb( -abs(x-y) >> 31, "-abs(x-y) >> 31 asserts :");	
	printf(	-abs(x-y) >> 31 ? "true\n" : "false\n");
	
	pbin_nb( (__builtin_clz(x-y)-31), "-(__builtin_clz(x-y)-32) >> 31 asserts :");	
	printf(	(__builtin_clz(x-y)-31) ? "true\n" : "false\n");
	
	pbin_nb( (x-y) | (y-x) >> 31, " (x-y | y-x) >> 31 asserts :");	
	printf(	(x-y) | (y-x) >> 31 ? "true\n" : "false\n");

return 1;
}
