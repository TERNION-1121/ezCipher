#include "ciphers.h"

#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>


// valid_caesar_key: return true if whole of s represents a valid integer in range [1, 26], else false
bool valid_caesar_key(const char *key)
{   
    const char* s = key;
    for (;isspace(*s); ++s);

    if (*s == '+' || *s == '-')
        ++s;

    for (int i = 0; i < 2 && isdigit(*s); ++s, ++i);

    if (*s != '\0')
        return false;
    
    int n = abs(atoi(key));
    return n >= 1 && n <= 26;
}

/*  
    Assume caller passes a valid integer key in the range [1, 26)   
*/

// caesar_encrypt: encrypt plaintext with the given integer key
char *caesar_encrypt(const char *plaintext, int key)
{   
    int size = strlen(plaintext);
    char *ciphertext = (char *) malloc(size + 1);

    if (ciphertext == NULL)
        return NULL;

    char ch;
    for (int i = 0; (ch = plaintext[i]) != '\0'; ++i)
    {
        if (!isalpha(ch))
        {
            ciphertext[i] = ch;
            continue;
        }
        
        int asciishift = (isupper(ch) ? 'A' : 'a');
        ciphertext[i] = (ch - asciishift + key) % 26 + asciishift;
    }
    ciphertext[size] = '\0';
    return ciphertext;
}

// caesar_decrypt: decrypt ciphertext with the given integer key
char *caesar_decrypt(const char *ciphertext, int key)
{   
    int size = strlen(ciphertext);
    char *plaintext = (char *) malloc(size + 1);

    if (plaintext == NULL)
        return NULL;

    char ch;
    for (int i = 0; (ch = ciphertext[i]) != '\0'; ++i)
    {
        if (!isalpha(ch))
        {
            plaintext[i] = ch;
            continue;
        }

        int asciishift = (isupper(ch) ? 'A' : 'a');
        plaintext[i] = (ch - asciishift + 26 - key) % 26 + asciishift;
    } 
    plaintext[size] = '\0';
    return plaintext;
}