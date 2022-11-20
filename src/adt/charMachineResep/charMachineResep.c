#include <stdio.h>

#include "charMachineResep.h"

char resep_currentChar;
int resep_EOP;

static FILE *resepFile;
static int resep_retval;

void startCharResep()
{
    resepFile = fopen(resepConfig, "r");
    advResep();
}

void advResep()
{
    resep_retval = fscanf(resepFile, "%c", &resep_currentChar);
    resep_EOP = (resep_retval == EOF);
    if (resep_EOP)
    {
        fclose(resepFile);
    }
}