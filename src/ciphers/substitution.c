#include "ciphers.h"

#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>


// valid_substitution_key: return true if given key is a valid substitution cipher key, else false
bool valid_substitution_key(const char *key)
{
    bool alphaFreq[26] = {0}; // to check for duplicate characters
    int length = 0;

    for (; key[length] != '\0' && isalpha(key[length]); ++length) // key[length] is an alphabet
    {
        int i = toupper(key[length]) - 'A';
        if (alphaFreq[i]) // duplicate character
            return false;
        ++alphaFreq[i];
    }
    return length == 26; // key is valid by length
}

/*  
    Assume caller passes a valid key,
    which is a 26 character long uppercase permutation of the English Alphabet    
*/

// substitution_encrypt: encrypt the given plaintext with the given key
char *substitution_encrypt(const char *plaintext, const char *key)
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
        // lowercase char in plaintext remains lowercase in the ciphertext, same with uppercase char
        if (islower(ch))
            ciphertext[i] = tolower(key[ch - 'a']);
        else
            ciphertext[i] = key[ch - 'A'];
    }
    ciphertext[size] = '\0';
    return ciphertext;
}

// substitution_decrypt: decrypt the given ciphertext with the given key
char *substitution_decrypt(const char *ciphertext, const char *key)
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

        if (islower(ch))
            plaintext[i] = strchr(key, toupper(ch)) - key + 'a';
        else
            plaintext[i] = strchr(key, ch) - key + 'A';
    }
    plaintext[size] = '\0';
    return plaintext;
}