#include <stdbool.h>

#ifndef UTILS_H
#define UTILS_H

char *str_capitalize(const char *s);

int get_line(char s[], int lim);

int readlines(char *lineptr[], int maxlines);

void writelines(char *lineptr[], int nlines);

void free_pp(void **p, int n);

#endif