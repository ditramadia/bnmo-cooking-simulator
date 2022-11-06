#include <stdio.h>

#include "charmachine.h"

// Definition
char currentChar;
int EOP;
static FILE *file;
static int retval;

// Start
void startChar(char *directory)
{
    file = fopen(directory, "r");
    adv();
}

// Advance
void adv()
{
    retval = fscanf(file, "%c", &currentChar);
    EOP = (retval == CHARMARK);
    if (EOP)
    {
        fclose(file);
    }
}

// Get Current Character
char getCC()
{
    return currentChar;
}

// End of File
int isEOP()
{
    return EOP;
}
