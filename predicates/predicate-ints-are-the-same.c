#include <stdio.h>
#include <string.h>
#include "binary_printout.h"
	
/* short series of stupid stunts extracted from Hackers Delight book 2nd Ed. */	

int main(void) {
	
	int x = 12;
	int y = 25;

	printf("\n **  NB 0 asserts FALSE, anything else asserts as TRUE **\n");

	// Check if two ints are definitely the same

	printf("\n2.12 Comparison predicates\n");
	printf("\n1) Comparison predicates (neg test equal fails) \tx = %d, y = %d\n", x, y);


	pbin_nb((abs(x-y)-1) >> 31, "abs(x-y)-1 >> 31 asserts :");	
	printf(	(abs(x-y)-1) >> 31 ? "true\n" : "false\n");

	pbin_nb(abs(x-y+0x80000000) >> 31, "abs(x-y+0x80000000) >> 31 asserts :");
	printf( (abs(x-y+0x80000000) >> 31) ? "true\n" : "false\n");
		
	pbin_nb( __builtin_clz(x-y) << 26, "__builtin_clz(x-y) << 26 asserts :");	
	printf(	__builtin_clz(x-y) << 26 ? "true\n" : "false\n");	
	
	pbin_nb( -(__builtin_clz(x-y)) >> 5, "-(__builtin_clz(x-y)) >> 5 asserts :");	
	printf(	-(__builtin_clz(x-y)) >> 5 ? "true\n" : "false\n");	
	
	pbin_nb( ~((x-y) | (y-x)), "~((x-y) | (y-x)) asserts :");	
	printf(	~((x-y) | (y-x)) ? "true\n" : "false\n");	
		
	x = 25;
	y = 25;	
	
	printf("\n\n2) Comparison predicates (pos test equal works) \tx = %d, y = %d\n", x, y);

	pbin_nb((abs(x-y)-1) >> 31, "abs(x-y)-1 >> 31 asserts :");	
	printf(	(abs(x-y)-1) >> 31 ? "true\n" : "false\n");

	pbin_nb(abs(x-y+0x80000000) >> 31, "abs(x-y+0x80000000) >> 31 asserts :");
	printf( (abs(x-y+0x80000000) >> 31) ? "true\n" : "false\n");
		
	pbin_nb( __builtin_clz(x-y) << 26, "__builtin_clz(x-y) << 26 asserts :");	
	printf(	__builtin_clz(x-y) << 26 ? "true\n" : "false\n");	

	pbin_nb( -(__builtin_clz(x-y)) >> 5, "-(__builtin_clz(x-y)) >> 5 asserts :");	
	printf(	-(__builtin_clz(x-y)) >> 5 ? "true\n" : "false\n");		

	pbin_nb( ~((x-y) | (y-x)), "~((x-y) | (y-x)) asserts :");	
	printf(	~((x-y) | (y-x)) ? "true\n" : "false\n");	



return 1;
}
