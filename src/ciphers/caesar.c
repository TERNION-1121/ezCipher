#include "ciphers.h"

#include <ctype.h>
#include <stdlib.h>
#include <string.h>


/*  
    Assume caller passes a valid integer key in the range [1, 26]   
*/

// caesar_encrypt: encrypt plaintext with the given integer key
char *caesar_encrypt(const char *plainText, int key)
{   
    int size = strlen(plainText);
    char *cipherText = (char *) malloc(sizeof(char) * (size + 1));

    if (cipherText == NULL)
        return NULL;

    char ch;
    for (int i = 0; (ch = plainText[i]) != '\0'; ++i)
    {
        if (!isalpha(ch))
        {
            cipherText[i] = ch;
            continue;
        }

        if (isupper(ch))
            cipherText[i] = ((ch - 'A') + key) % 26 + 'A';
        else
            cipherText[i] = tolower(((ch - 'a') + key) % 26 + 'A');
    }
    cipherText[size] = '\0';
    return cipherText;
}

// caesar_decrypt: decrypt ciphertext with the given integer key
char *caesar_decrypt(const char *cipherText, int key)
{   
    int size = strlen(cipherText);
    char *plainText = (char *) malloc(sizeof(char) * (size + 1));

    if (plainText == NULL)
        return NULL;

    char ch;
    for (int i = 0; (ch = cipherText[i]) != '\0'; ++i)
    {
        if (!isalpha(ch))
        {
            plainText[i] = ch;
            continue;
        }

        if (isupper(ch))
            plainText[i] = (ch - 'A' + 26 - key) % 26 + 'A';
        else 
            plainText[i] = (ch - 'a' + 26 - key) % 26 + 'a';
    } 
    plainText[size] = '\0';
    return plainText;
}