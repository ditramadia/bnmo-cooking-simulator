#include <stdio.h>
#include "charmachine.h"

char currentChar;
boolean EoP;

static FILE *pita;

void START(){
    pita = fopen("makanan.txt", "r");
    ADV();
}

void ADV(){
    retval = fscanf(pita, "%c", &currentChar);
       EoP = (retval == EOF);
       if (EoP){
              fclose(pita);
       }
       
}