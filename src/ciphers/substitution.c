#include <ctype.h>
#include <stdlib.h>
#include <string.h>

int valid_key(char * key)
{
    int alphaFreq[26] = {0}; // to check for duplicate characters
    int length = 0;

    for (; key[length] != '\0' && isalpha(key[length]); ++length) // key[length] is an alphabet
    {
        int i = toupper(key[length]) - 'A';
        if (alphaFreq[i]) // duplicate character
            return 0;
        alphaFreq[i] = 1;
    }
    return length == 26; // key is valid by length
}

char *substitution_cipher(char *plainText, char *key)
{
    char *cipherText = (char *) malloc(sizeof(char) * strlen(plainText)); // dynamically allocate memory to the cipher text

    if (cipherText == NULL)
        return cipherText; 

    char ch;
    for (int i = 0; (ch = plainText[i]) != '\0'; ++i)
    {
        if (!isalpha(ch)) // not an alphabet
        {
            cipherText[i] = ch;
            continue;
        }

        // lowercase char in plaintext remains lowercase in the cipher text, same with uppercase char
        if (islower(ch))
            cipherText[i] = tolower(key[toupper(ch) - 'A']);
        else
            cipherText[i] = toupper(key[ch - 'A']);
    }
    return cipherText;
}