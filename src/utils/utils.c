#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#include "utils.h"

// starts_with: return 1 (true) if s1 starts with s2 else 0 (false)
int starts_with(const char *s1, const char *s2)
{   
    int lenS1, lenS2;
    lenS1 = strlen(s1);
    lenS2 = strlen(s2);

    if (lenS2 > lenS1)
        return 0;

    int i, j;
    for (i = j = 0; i < lenS1 && j < lenS2; ++i, ++j)
        if (s1[i] != s2[j])
            return 0;
    
    return 1;
}

// str_capitalize: capitalize all the letters of the given string
char *str_capitalize(const char *s)
{      
    int size = strlen(s);
    char *capitalized = (char *) malloc(sizeof(char) * (size + 1));

    if (capitalized == NULL || !size)
        return NULL;

    for (int i = 0; s[i] != '\0'; ++i)
        capitalized[i] = toupper(s[i]);

    return capitalized;
}