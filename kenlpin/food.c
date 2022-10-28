#include "food.h"
#include <stdio.h>
#include <stdlib.h>

/* ********* AKSES (Selektor) ********* */
/* Jika e adalah infotype dan Q adalah PrioQueueTime, maka akses elemen : */

void Createinventory (FoodList *I){
    for (int i=0;i<INVENTORY_CAP;i++){
        ID((*I).buffer[i]) = IDX_UNDEF;
    }
}

boolean isInventoryEmpty (FoodList I){
    return (ID(I.buffer[0]) == IDX_UNDEF);
}
void AddFood (FoodList *I, int id){
    if (isInventoryEmpty(*I)){
        ID((*I).buffer[0]) = id;
    }
    else{
        
    }
}