#include <stdio.h>
#include <string.h>
#include "binary_printout.h"
	
/* short series of stupid stunts extracted from Hackers Delight book 2nd Ed. */	

int main(void) {


	// pbin8 - only send chars - testing overflow vs binary print out we are using
	
	printf("\n\nPredict Over/Underflow on math ops on signed integers (this e.g. signed chars - 127 max)\n" );
	
	char u = 13;
	char v = 10;
	printf("let u = %d, v= %d\n", u, v);
	
	// overflow prediction for multiplication
	
	if(u > 127/v)
		printf("Warning %d * %d will overflow!\n", u, v);
	
	pbin8_nb(u*v, "Multiplication Overflow on bytes u*v == negative!\n");	
	
	
	
	// overflow prediction for addition
	
	v = 123;
	printf("let u = %d, v= %d\n", u, v);
//	if ((x > 0) && (a > INT_MAX - x)) /* `a + x` would overflow */;
	
	
	if( (u > 0) &&(v > 127 - u))
		printf("Warning %d + %d will overflow!\n", u, v);
	
	pbin8_nb(u+v, "Addition Overflow on bytes u+v == negative!\n");	


	v = -123;
	u = -10;
	printf("let u = %d, v= %d\n", u, v);

//  if ((x < 0) && (a < INT_MIN - x)) /* `a + x` would underflow */;

	if( (u < 0) && (v < 127 - u))
		printf("Warning %d - %d will underflow!\n", u, v);
	
	
	pbin8_nb(u-v, "Subtraction Underflow on bytes u-v == positive!\n");	
	
return 1;
}	
	
		
