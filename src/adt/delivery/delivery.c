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

        if (timeToMinute(Info(p).deltime) > timeToMinute(Info(newElmt).deltime))
        {
            Next(newElmt) = ADDR_HEAD(*Q);
            ADDR_HEAD(*Q) = newElmt;
        }
        else
        {
            while (Next(p) != NULL && timeToMinute(Info(Next(p)).deltime) < timeToMinute(x.deltime))
            {
                p = Next(p);
            }
            Next(newElmt) = Next(p);
            Next(p) = newElmt;
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
        printf("|                          DELIVERY                          |\n");
        printf("==============================================================\n");
        printf("|  No. Nama ----- Waktu Delivery\n");
        printf("|\n");

        while (p != NULL)
        {
            printf("|  %d. ", i);
            displayWordFood(Info(p).name);
            printf(" ----- ");
            displayTime(Info(p).deltime);
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

    printf("Tekan enter menutup delivery\n");
    scanf("%c", &bin);
    return;
}
