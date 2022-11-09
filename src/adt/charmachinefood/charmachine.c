#include <stdio.h>
#include "../charmachinefood/charmachine.h"
#include "../../../config/config.h"

char currentChar;
boolean EOP;

static FILE *pita;

void START(){
    pita = fopen("makanan.txt", "r");
    ADV();
}

void ADV(){
    retval = fscanf(pita, "%c", &currentChar);
       EOP = (retval == EOF);
       if (EOP){
              fclose(pita);
       }
       
}