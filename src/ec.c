#include "utils/utils.h"
#include "ciphers/ciphers.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define None 0

#define MAXLINES 1000   // max #lines to be processed

enum CIPHER_MODE {ENCRYPT = 1, DECRYPT};
enum CIPHER_ALGORITHM {CAESAR = 1, SUBSTITUTION};
enum RETURN_STATUS {SUCCESS, FAILURE};

int MODE = None;
int CIPHER = None;
bool ERROR = false;

void usage_instruction(void);
void process_argument(const char*);

char **substitution(int, const char**, int, const char*);
char **caesar(int, const char**, int, const char*);

int main(int argc, char **argv)
{   
    if (argc != 4) 
        goto error;

    char *key;

    for (int i = 1; i < argc; ++i)
    {   
        if (!starts_with(argv[i], "-"))
        {
            key = argv[i];
            continue;
        }
        
        const char *arg = argv[i] + 1;
        process_argument(arg);
    }
    if (MODE == None || CIPHER == None)
        goto error;

    int nlines;
    char **userText = (char **) malloc(sizeof(char *) * MAXLINES);    
    char **processedText;

    if ((nlines = readlines(userText, MAXLINES)) < 0) // input too big
        goto error;

    switch (CIPHER)
    {
        case CAESAR:
            processedText = caesar(MODE, (const char **) userText, nlines, key);
            break;

        case SUBSTITUTION:
            processedText =  substitution(MODE, (const char **) userText, nlines, key);
            break;

        default:
            goto error;
    }

    if (processedText == NULL)
        goto error;
    
    writelines(processedText, nlines);

    return SUCCESS;

    error:
        usage_instruction();
        return FAILURE;
}

void process_argument(const char* arg)
{
    if (strcmp(arg, "c") == 0)
        CIPHER = CAESAR;

    else if (strcmp(arg, "s") == 0)
        CIPHER = SUBSTITUTION;

    else if (strcmp(arg, "e") == 0)
        MODE = ENCRYPT;

    else if (strcmp(arg, "d") == 0)
        MODE = DECRYPT;
}

char **caesar(int mode, const char **text, int nlines, const char *K)
{   
    if (!valid_caesar_key(K))
        return NULL;
    
    int key = atoi(K);

    // allocate memory
    char **processedText = (char **) malloc(sizeof(char *) * nlines);

    // process text
    for (int i = 0; i < nlines; ++i)
    {   
        if (MODE == ENCRYPT)
            processedText[i] = caesar_encrypt(text[i], key);
        else if (MODE == DECRYPT)
            processedText[i] = caesar_decrypt(text[i], key);
    }

    // return a pointer to processed text
    return processedText;
}


char **substitution(int mode, const char **text, int nlines, const char *key)
{   
    if (!valid_substitution_key(key))
        return NULL;

    // allocate memory
    char **processedText = (char **) malloc(sizeof(char *) * nlines);

    // process text
     for (int i = 0; i < nlines; ++i)
    {   
        if (MODE == ENCRYPT)
            processedText[i] = substitution_encrypt(text[i], key);
        else if (MODE == DECRYPT)
            processedText[i] = substitution_decrypt(text[i], key);
    }

    // return a pointer to processed text
    return processedText;
}

void usage_instruction(void)
{
    printf("\nUSAGE: ./ec -<cipher> -<ENCRYPT/DECRYPT> <key>\n\n");
    printf("<cipher>:\n");
    printf("\tc: caesar\n");
    printf("\ts: substitution\n\n");
    printf("<ENCRYPT/DECRYPT>:\n");
    printf("\te: ENCRYPT\n");
    printf("\td: DECRYPT\n\n");
    printf("<key>: In accordance with the opted cipher\n\n");
}