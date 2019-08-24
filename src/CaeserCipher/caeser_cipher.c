#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ASCII_START_UPPER    65
#define ASCII_END_UPPER      90
#define ASCII_START_LOWER    97
#define ASCII_SPACE          32 
#define CIPHER_KEY            3

typedef int bool;

bool is_upper(char c)
{

    return ((c >= ASCII_START_UPPER && c <= ASCII_END_UPPER)? 1: 0);
}

int main(int argc, char *argv[])
{
 
    int ascii_start = 0;
    if (argc != 2) {
        printf("Usage: ./caeser_cipher <input_string>\n");
        return 1;
    }   

    for (int i=0; i<strlen(argv[1]); i++) {
        // do nothing for space
        if (argv[1][i] == ASCII_SPACE)
            continue;

        ascii_start = ( is_upper(argv[1][i]) ? 
                        ASCII_START_UPPER : 
                        ASCII_START_LOWER);
        argv[1][i] = ((((argv[1][i] - ascii_start) + CIPHER_KEY) % 26) + ascii_start);    
    }

    printf ("Cipher string is \"%s\"\n", argv[1]);

    return 0;
}
