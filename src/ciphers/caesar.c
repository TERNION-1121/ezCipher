#include <ctype.h>
#include <stdlib.h>
#include <string.h>

int only_digits(char * s)
{
    for (int i = 0; s[i] != '\0'; ++i)
        if (!isdigit(s[i]))
            return 0;
    return 1;
}

char *caesar_cipher(char *plainText, int key)
{
    char *cipherText = (char *) malloc(sizeof(char) * (strlen(plainText) + 1));

    char ch;
    for (int i = 0; (ch = plainText[i]) != '\0'; ++i)
    {
        if (!isalpha(ch)) // not an alphabet
        {
            cipherText[i] = ch;
            continue;
        }

        if (isupper(ch))
            cipherText[i] = ((ch - 'A') + key) % 26 + 'A';
        else
            cipherText[i] = tolower(((ch - 'a') + key) % 26 + 'A');
    }
    return cipherText;
}