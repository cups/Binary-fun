#include <stdio.h>
#include <string.h>
#include "binary_printout.h"

int main(void) { 

        /* binary string to int GOTCHA - does not display negative number*/
        char *tmp;
        char *b = "11111110";
        printf("%ld\n", strtol(b, &tmp, 2));
        
        /* int to binary */
        printf("%s\n", byte_to_binary(127));

return 1;        
        
}
