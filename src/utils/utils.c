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