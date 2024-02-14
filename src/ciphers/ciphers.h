#include <stdbool.h>

#ifndef CIPHERS_H
#define CIPHERS_H

bool valid_caesar_key(const char *s);

char *caesar_encrypt(const char *plainText, int key);
char *caesar_decrypt(const char *cipherText, int key);


bool valid_substitution_key(const char *key);

char *substitution_encrypt(const char *plainText, const char *key);
char *substitution_decrypt(const char *cipherText, const char *key);

bool valid_vigenere_key(const char *key);

char *vigenere_encrypt(const char *plaintext, const char *key);
char *vigenere_decrypt(const char *plaintext, const char *key);

#endif