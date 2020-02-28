
/**
 * Just some helpers to dump binary and arabic values
 * onto the screen
 * depends on string.h
 * byte to binary was found somewhere on s.o. cant remember
 * where
 */

const char *byte_to_binary(int);
const char *byte_to_binary8(char);
void pbin(int);
void pbin_nb(int, char*);
void pbin8(char);
void pbin8_nb(char, char*);

const char *byte_to_binary(int x) {
    
    static char b[9];
    b[0] = '\0';
	int ctr = 0;
    int z;
    for (z = 128; z > 0; z >>= 1) {
		
        strcat(b, ((x & z) == z) ? "1" : "0");
        if(ctr == 3)
			strcat(b, " ");
        ctr++;
    }

    return b;
}

const char *byte_to_binary8(char x) {
    
    static char b[9];
    b[0] = '\0';
	char ctr = 0;
    int z;
    for (z = 128; z > 0; z >>= 1) {
		
        strcat(b, ((x & z) == z) ? "1" : "0");
        if(ctr == 3)
			strcat(b, " ");
        ctr++;
    }

    return b;
}


	/* pbin - print binary */
void pbin(int x) {
	
	printf("%s\t", byte_to_binary(x));
    printf("(%d)\n", x);
	
	}
	/* pbin - print binary with note*/
void pbin_nb(int x, char *nb) {
	
	printf("%s\t", byte_to_binary(x));
    printf("(%d) ", x);
    printf(" <-- %s\n", nb);
	
	}	
	
	
	/* pbin - print binary 1 byte only*/
void pbin8(char x) {
	
	printf("%s\t", byte_to_binary8(x));
    printf("(%d)\n", x);
	
	}
	/* pbin - print binary 1 byte only with note*/
void pbin8_nb(char x, char *nb) {
	
	printf("%s\t", byte_to_binary8(x));
    printf("(%d) ", x);
    printf(" <-- %s\n", nb);
	
	}

