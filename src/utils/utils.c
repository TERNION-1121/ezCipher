#include "utils.h"

#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAXLEN 1000     // max length of any input line; for function readlines


// str_capitalize: capitalize all the letters of the given string
char *str_capitalize(const char *s)
{      
    int size = strlen(s);
    char *capitalized = (char *) malloc(sizeof(char) * (size + 1));

    if (capitalized == NULL || !size)
        return NULL;

    for (int i = 0; s[i] != '\0'; ++i)
        capitalized[i] = toupper(s[i]);
    
    capitalized[size] = '\0';
    return capitalized;
}

// get_line: get a single line of input from the keyboard into s; maximum lim - 1 characters to be accomodated
int get_line(char s[], int lim)
{
    int c, i;
    
    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i]= c;

    if (c == '\n')
        s[i++] = c;

    s[i] = '\0';
    return i;
}

// readlines: read input lines
int readlines(char *lineptr[], int maxlines)
{
    int len, nlines;
    char *p, line[MAXLEN];

    nlines = 0;
    while ((len = get_line(line, MAXLEN)) > 0)
    {   
        if (nlines >= maxlines || (p = (char *) malloc(sizeof(char) * len)) == NULL)
            return -1;
        else
        {
            line[len-1] = '\0'; // delete newline
            strncpy(p, line, len);
            lineptr[nlines++] = p;
        }
    }
    return nlines;
}

// writelines: write output lines
void writelines(char *lineptr[], int nlines)
{
    while (nlines-- > 0)
        printf("%s\n", *lineptr++);
}

// free_pp: free the dynamically allocated memory to a pointer to pointers
void free_pp(void **p, int n)
{
    for (int i = 0; i < n; ++i)
        free(p[i]);
    free(p);
}