#include "inventory.h"
#include<stdio.h>
#include<stdlib.h>
#include "../food/food.c"
#include "../point/point.c"
#include "../prioqueuetime/prioqueuetimeinv.c"

/* ********* AKSES (Selektor) ********* */
/* Jika e adalah infotype dan Q adalah PrioQueueTime, maka akses elemen : */

void Createinventory(PrioQueueTime *Q)
{
    MakeEmpty(Q, INVENTORY_CAP);
}

void AddInventory(PrioQueueTime *Q, Food I)
{
    Enqueue(Q, I);
}

void  deleteInventory(PrioQueueTime *Q, Food *I)
{
    Dequeue(Q, I);
}

/*void gadgetInfo(FoodList *L){
    createInventory(L);
    ID((*L).buffer[0]) = 0;
    Ti((*L).buffer[0]) = "Kain Pembungkus Waktu";
    TIME((*L).buffer[0]) = 800;

    ID_GADGET((*L).buffer[1]) = 1;
    NAME((*L).buffer[1])  = "Senter Pembesar";
    PRICE((*L).buffer[1]) = 1200;

    ID_GADGET((*L).buffer[2]) = 2;
    NAME((*L).buffer[2])  = "Pintu Kemana Saja";
    PRICE((*L).buffer[2]) = 1500;

    ID_GADGET((*L).buffer[3]) = 3;
    NAME((*L).buffer[3])  = "Mesin Waktu";
    PRICE((*L).buffer[3]) = 3000;

    ID_GADGET((*L).buffer[4]) = 4;
    NAME((*L).buffer[4])  = "Senter Pengecil";
    PRICE((*L).buffer[4]) = 800;
}*/
// int main(){
//     FoodList I;
    
// }