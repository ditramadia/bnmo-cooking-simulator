#include <stdio.h>
#include "charmachine.h"


char currentChar;
boolean Eop;

static FILE *pita;
static int retval;

void START(){
    pita = fopen(resepConfig, "r");
    ADV();
}

void ADV(){
    retval = fscanf(pita, "%c", &currentChar);
       Eop = (retval == EOF);
       if (Eop){
              fclose(pita);
       }
}