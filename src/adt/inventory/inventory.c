#include "inventory.h"
#include <stdio.h>
#include <stdlib.h>

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
    char bin;
    int i = 1;

    if (length(Q) == 0)
    {
        printf("==============================================================\n");
        printf("|                         INVENTORY                          |\n");
        printf("==============================================================\n");
        printf("|  Inventory-mu masih kosong\n");
        printf("|\n");
        printf("==============================================================\n");
        printf("\n");
    }
    else
    {
        printf("==============================================================\n");
        printf("|                         INVENTORY                          |\n");
        printf("==============================================================\n");
        printf("|  No. Nama ----- Waktu Kadaluarsa\n");
        printf("|\n");

        while (p != NULL)
        {
            printf("|  %d. ", i);
            displayWordFood(Info(p).name);
            printf(" ----- ");
            displayTime(Info(p).exptime);
            p = Next(p);
            if (p != NULL)
            {
                printf("\n");
            }
            i++;
        }
        printf("\n");
        printf("|\n");
        printf("==============================================================\n");
        printf("\n");
    }

    printf("Tekan enter menutup inventory\n");
    scanf("%c", &bin);
    return;
}