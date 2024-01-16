#include "utils/utils.h"
#include "ciphers/ciphers.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define None 0

enum CIPHER_MODE {ENCRYPT, DECRYPT};
enum CIPHER_ALGORITHM {CAESAR, SUBSTITUTION};
enum RETURN_STATUS {SUCCESS, FAILURE};

int MODE = None;
int CIPHER = None;

void usage_instruction(void);
void process_argument(const char*);

char **substitution(int, const char**, const char*);
char **caesar(int, const char**, const char*);

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
        

    char **userText;    
    /* get one or more lines of input using getline*/

    char **processedText;

    switch (CIPHER)
    {
        case CAESAR:
            processedText = caesar(MODE, (const char **) userText, key);
            break;

        case SUBSTITUTION:
            processedText =  substitution(MODE, (const char **) userText, key);
            break;

        default:
            goto error; 
    }

    if (processedText == NULL)
        goto error;

    error:
        usage_instruction();
        return FAILURE;
    
    // print contents of processedText

    return SUCCESS;
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

char **caesar(int mode, const char **text, const char *key)
{   
    // validate key
    // allocate memory
    // process text
    // return a pointer to processed text

    return NULL;
}


char **substitution(int mode, const char **text, const char *key)
{
    // validate key
    // allocate memory
    // process text
    // return a pointer to processed text

    return NULL;
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