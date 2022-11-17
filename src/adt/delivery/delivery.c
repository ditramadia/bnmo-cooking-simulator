#include <stdio.h>
#include "delivery.h"

void addDelivery(Queue *Q, Food x)
{
    address newElmt = newnode(x);

    if (isempty(*Q))
    {
        ADDR_HEAD(*Q) = newElmt;
        ADDR_TAIL(*Q) = newElmt;
    }
    else
    {
        address p = ADDR_HEAD(*Q);

        if (timeToMinute(INFO(p).deltime) > timeToMinute(INFO(newElmt).deltime))
        {
            NEXT(newElmt) = ADDR_HEAD(*Q);
            ADDR_HEAD(*Q) = newElmt;
        }
        else
        {
            while (NEXT(p) != NULL && timeToMinute(NEXT(p)->info.deltime) < timeToMinute(x.deltime))
            {
                p = NEXT(p);
            }
            NEXT(newElmt) = NEXT(p);
            NEXT(p) = newElmt;
        }
    }
}

void delDelivery(Queue *Q, Food *x)
{
    dequeue(Q, x);
}

void displayDelivery(Queue Q)
{
    address p = ADDR_HEAD(Q);
    int n = length(Q);
    char bin;

    if (n == 0)
    {
        printf("==============================================================\n");
        printf("|                          DELIVERY                          |\n");
        printf("==============================================================\n");
        printf("|  Tidak ada pesanan\n");
        printf("|\n");
        printf("==============================================================\n");
        printf("\n");
    }
    else
    {
        int i = 1;

        printf("==============================================================\n");
        printf("|                         INVENTORY                          |\n");
        printf("==============================================================\n");
        printf("|  No. Nama ----- Waktu Delivery\n");
        printf("|\n");

        while (p != NULL)
        {
            printf("|  %d. ", i);
            displayWordFood(INFO(p).name);
            printf(" ----- ");
            displayTime(INFO(p).deltime);
            p = NEXT(p);
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
