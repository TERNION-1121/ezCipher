#include "utils/utils.h"
#include "ciphers/ciphers.h"

#include <stdio.h>
#include <string.h>


enum CIPHER_MODE {Decrypt, Encrypt};
enum CIPHER_ALGO {Substitution, Caesar};

int main(int argc, char **argv)
{
    if (argc != 4) 
    {
        printf("\nUSAGE: ./ec -<cipher> -<encrypt/decrypt> <key>\n\n");
        printf("<cipher>:\n");
        printf("\tc: caesar\n");
        printf("\ts: substitution\n\n");
        printf("<encrypt/decrypt>:\n");
        printf("\te: encrypt\n");
        printf("\td: decrypt\n\n");
        printf("<key>: In accordance with the opted cipher\n\n");

        return 1;
    }

    for (int i = 1; i < argc; ++i)
    {
        if (!starts_with(argv[i], "-"))
        {
            // validate key or store key without validation (to be thought about)
            continue;
        }
        
        const char *arg = argv[i] + 1;
        // compare arg with 'e', 'd', 's' and 'c'
        // else return 1 with an error message
    }


    return 0;
}