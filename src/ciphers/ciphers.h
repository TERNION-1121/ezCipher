#include <stdbool.h>

#ifndef CIPHERS_H
#define CIPHERS_H

char *caesar_encrypt(const char *plainText, int key);
char *caesar_decrypt(const char *cipherText, int key);
bool valid_caesar_key(const char *s);

char *substitution_encrypt(const char *plainText, const char *key);
char *substitution_decrypt(const char *cipherText, const char *key);
bool valid_substitution_key(const char *key);

#endif