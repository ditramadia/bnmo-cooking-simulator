#include "inventory.h"
#include<stdio.h>
#include<stdlib.h>


/* ********* AKSES (Selektor) ********* */
/* Jika e adalah infotype dan Q adalah PrioQueueTime, maka akses elemen : */

void Createinventory(Queue *Q)
{
    CreateQueue(Q);
}

void AddInventory(Queue *Q, Food I)
{
    insertprio(Q, I);
}

void delInventory(Queue *Q, Food *I)
{
    dequeue(Q, I);
}

void DisplayInventory(Queue Q)
{
    address p = ADDR_HEAD(Q);
    int i=1;
    while (p != NULL) {
        // displayWord(INFO(p).name);
        printf("%d. ", i);
        displayWord(INFO(p).name);
        printf ("         ");
        displayTime(INFO(p).exptime);
        p = NEXT(p);
        if (p != NULL) {
            printf("\n");
        }
        i++;
    }
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