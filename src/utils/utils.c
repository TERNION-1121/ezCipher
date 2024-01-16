#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "utils.h"

// starts_with: return true if s1 starts with s2 else false
bool starts_with(const char *s1, const char *s2)
{   
    int lenS1, lenS2;
    lenS1 = strlen(s1);
    lenS2 = strlen(s2);

    if (lenS2 > lenS1)
        return false;

    int i, j;
    for (i = j = 0; i < lenS1 && j < lenS2; ++i, ++j)
        if (s1[i] != s2[j])
            return false;
    
    return true;
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

// getline: get a single line of input from the keyboard into s; maximum lim - 1 characters to be accomodated
int getline(char s[], int lim)
{
    int c, i;
    
    for (i = 0; i < lim - 1 && ((c = getchar())) != EOF && c != '\n'; ++i)
        s[i]= c;

    if (c == '\n')
        s[i++] = c;

    s[i] = '\0';
    return i;
}