#include <stdio.h>
#include "charmachine.h"

char currentChar;
boolean EOP;

static FILE *pita;
static int retval;

void START(){
    pita = fopen("konfigResep.txt", "r");
    ADV();
}

void ADV(){
    retval = fscanf(pita, "%c", &currentChar);
       EOP = (retval == EOF);
       if (EOP){
              fclose(pita);
       }
}