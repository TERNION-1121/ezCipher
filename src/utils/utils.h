#include <stdbool.h>

#ifndef UTILS_H
#define UTILS_H

bool starts_with(const char *s1, const char *s2);

char *str_capitalize(const char *s);

int get_line(char s[], int lim);

int readlines(char *lineptr[], int maxlines);

void writelines(char *lineptr[], int nlines);

#endif