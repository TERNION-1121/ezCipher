#include "utils/utils.h"
#include "ciphers/ciphers.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define None -1

#define CIPHER_COUNT 2  // #ciphers available to use

#define MAXLINES 1000   // max #lines to be processed

enum CIPHER_MODE {ENCRYPT, DECRYPT};
enum CIPHER_ALGORITHM {
                        CAESAR, 
                        SUBSTITUTION
                        };
enum RETURN_STATUS {
                    SUCCESS, INCORRECT_ARG_COUNT, 
                    INVALID_CIPHER, INVALID_MODE, 
                    INVALID_KEY, INPUT_TOO_BIG
                    };

void usage_instruction(void);

int process_cipher_arg(const char *);
int process_mode_arg(const char *);

/*  cipher algorithms available to use;
    order should match the one in CIPHER_ALGORITHM  */
const char *Ciphers[CIPHER_COUNT] = {
                                        "caesar", 
                                        "substitution"
                                    };

/*  key validation algorithms for different ciphers;
    order should match with the one their corresponding ciphers occur in CIPHER_ALGORITHM and Ciphers */
bool (*KeyValidations[CIPHER_COUNT])(const char *) = {
                                                        valid_caesar_key, 
                                                        valid_substitution_key
                                                    };

char **substitution(int, const char **, int, const char*);
char **caesar(int, const char **, int, const char*);

int main(int argc, char **argv)
{   
    if (argc != 4) 
        goto incorrect_arg_count;

    int cipher, mode;
    char *key;    

    cipher = process_cipher_arg(argv[1]);
    mode = process_mode_arg(argv[2]);
    key = argv[3];

    if (cipher == None)
        goto invalid_cipher;
        
    if (mode == None)
        goto invalid_mode;

    if (!(*KeyValidations[cipher])(key))
        goto invalid_key;


    int nlines;
    char **userText = (char **) malloc(sizeof(char *) * MAXLINES);    
    char **processedText;

    if ((nlines = readlines(userText, MAXLINES)) < 0)   // input too big
        goto input_too_big;

    switch (cipher)
    {
        case CAESAR:
            processedText = caesar(mode, (const char **) userText, nlines, key);
            break;

        case SUBSTITUTION:
            processedText =  substitution(mode, (const char **) userText, nlines, key);
            break;

        default:
            break;
    }

    if (processedText == NULL)
        goto input_too_big;
    
    writelines(processedText, nlines);

    free_pp((void **) userText, nlines);
    free_pp((void **) processedText, nlines);

    return SUCCESS;

    // possible errors
    incorrect_arg_count:
        printf("\nerror: incorrect number of arguments given, expected 4 -> %d\n", argc);
        usage_instruction();
        return INCORRECT_ARG_COUNT;
    
    invalid_cipher:
        printf("\nerror: invalid cipher given as an argument -> %s\n", argv[1]);
        usage_instruction();
        return INVALID_CIPHER;

    invalid_mode:
        printf("\nerror: invalid mode given as an argument -> %s\n", argv[2]);
        usage_instruction();
        return INVALID_MODE;

    invalid_key:
        printf("\nerror: invalid key given as an argument for %s cipher -> %s\n", Ciphers[cipher], key);
        usage_instruction();
        return INVALID_KEY;

    input_too_big:
        printf("\nerror: input too big\n");
        return INPUT_TOO_BIG;
}

/* process_cipher_arg: 
    return the corresponding integer if cipher represents a valid cipher, else None */
int process_cipher_arg(const char *cipher)
{
    for (int i = CAESAR; i < CIPHER_COUNT; ++i)
        if (strcmp(Ciphers[i], cipher) == 0)
            return i;
    return None;
}

/*  process_mode_arg:
    return the corresponding integer if mode represents a valid cipher mode, else None  */
int process_mode_arg(const char *mode)
{
    if (strcmp(mode, "encrypt") == 0)
        return ENCRYPT;
    else if (strcmp(mode, "decrypt") == 0)
        return DECRYPT;
    return None;
}

/*  caesar: process the given text as per specified arguments using caesar cipher   */
char **caesar(int mode, const char **text, int nlines, const char *key)
{   
    int K = atoi(key);

    char **processedText = (char **) malloc(sizeof(char *) * nlines);

    for (int i = 0; i < nlines; ++i)
    {   
        if (mode == ENCRYPT)
            processedText[i] = caesar_encrypt(text[i], K);
        else if (mode == DECRYPT)
            processedText[i] = caesar_decrypt(text[i], K);
    }
    return processedText;
}

/*  substitution: process the given text as per specified arguments using substitution cipher   */
char **substitution(int mode, const char **text, int nlines, const char *key)
{   
    key = str_capitalize(key);

    char **processedText = (char **) malloc(sizeof(char *) * nlines);

     for (int i = 0; i < nlines; ++i)
    {   
        if (mode == ENCRYPT)
            processedText[i] = substitution_encrypt(text[i], key);
        else if (mode == DECRYPT)
            processedText[i] = substitution_decrypt(text[i], key);
    }
    return processedText;
}

/*  usage_instruction: output usage instructions in the terminal    */
void usage_instruction(void)
{
    printf("\nUSAGE: ./ec <cipher> <encrypt/decrypt_mode> <key>\n\n");
    printf("<cipher>:\n");
    printf("\tcaesar\n");
    printf("\tsubstitution\n\n");
    printf("<encrypt/decrypt_mode>:\n");
    printf("\tencrypt\n");
    printf("\tdecrypt\n\n");
    printf("<key>: in accordance with the opted cipher\n\n");
}