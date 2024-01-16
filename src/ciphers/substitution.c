#include "ciphers.h"

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// valid_substitution_key: return true if given key is a valid substitution cipher key, else false
bool valid_substitution_key(const char *key)
{
    int alphaFreq[26] = {0}; // to check for duplicate characters
    int length = 0;

    for (; key[length] != '\0' && isalpha(key[length]); ++length) // key[length] is an alphabet
    {
        int i = key[length] - 'A';
        if (alphaFreq[i]) // duplicate character
            return false;
        alphaFreq[i] = 1;
    }
    return length == 26; // key is valid by length
}


/*  
    Assume caller passes a valid key,
    which is a 26 character long capitalized permutation of the English Alphabet    
*/

// substitution_encrypt: encrypt the given plaintext with the given key
char *substitution_encrypt(const char *plainText, const char *key)
{   
    int size = strlen(plainText);
    char *cipherText = (char *) malloc(sizeof(char) * (size + 1)); 

    if (cipherText == NULL || !size)
        return NULL; 

    char ch;
    for (int i = 0; (ch = plainText[i]) != '\0'; ++i)
    {
        if (!isalpha(ch)) 
        {
            cipherText[i] = ch;
            continue;
        }

        // lowercase char in plaintext remains lowercase in the cipher text, same with uppercase char
        if (islower(ch))
            cipherText[i] = tolower(key[ch - 'a']);
        else
            cipherText[i] = toupper(key[ch - 'A']);
    }
    return cipherText;
}

// substitution_decrypt: decrypt the given plaintext with the given key
char *substitution_decrypt(const char *cipherText, const char *key)
{   
    int size = strlen(cipherText);
    char *plainText = (char *) malloc(sizeof(char) * (size + 1)); 
    
    if (plainText == NULL || !size)
        return NULL; 

    char ch;
    for (int i = 0; (ch = cipherText[i]) != '\0'; ++i)
    {   
        if (!isalpha(ch)) 
        {
            plainText[i] = ch;
            continue;
        }

        if (islower(ch))
            plainText[i] = strchr(key, toupper(ch)) - key + 'a';
        else
            plainText[i] = strchr(key, ch) - key + 'A';
    }
    return plainText;
}