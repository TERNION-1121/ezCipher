#include "ciphers.h"

#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>


// valid_vigenere_key: return true if key is an all alphabet string, else false
bool valid_vigenere_key(const char *key)
{
    for (int i = 0; key[i] != '\0'; ++i)
        if (!isalpha(key[i]))
            return false;
    return true;
}

/*
    Assume caller passes a valid all-alphabetical and capitalized string
*/

// vigenere_encrypt: encrypt the given plaintext with the given key
char *vigenere_encrypt(const char *plaintext, const char *key)
{   
    int N = strlen(key);
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
        char charPos = ch - asciishift;
        int shift = key[ i % N ] - 'A';

        ciphertext[i] = (charPos + shift) % 26 + asciishift;
    }
    ciphertext[size] = '\0';
    return ciphertext;
}

// vigenere_decrypt: decrypt the given ciphertext with the given key
char *vigenere_decrypt(const char *ciphertext, const char *key)
{
    int N = strlen(key);
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
        char charPos = ch - asciishift;
        int shift = key[ i % N ] - 'A';

        plaintext[i] = (charPos - shift + 26) % 26 + asciishift;
    }
    plaintext[size] = '\0';
    return plaintext;
}