#include <stdio.h>
#include "charmachine.h"

char currentChar;
boolean EoP;

static FILE *pita;

void STARTFOOD()
{
    pita = fopen("makanan.txt", "r");
    ADVFOOD();
}

void ADVFOOD()
{
    retval = fscanf(pita, "%c", &currentChar);
    EoP = (retval == EOF);
    if (EoP)
    {
        fclose(pita);
    }
}