#ifndef CIPHERS_H
#define CIPHERS_H

#include <stdbool.h>

char *caesar_encrypt(const char *plainText, int key);
char *caesar_decrypt(const char *cipherText, int key);

char *substitution_encrypt(const char *plainText, const char *key);
char *substitution_decrypt(const char *cipherText, const char *key);
bool valid_substitution_key(const char *key);

#endif