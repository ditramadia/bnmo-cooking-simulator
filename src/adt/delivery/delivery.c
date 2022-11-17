#include <stdio.h>
#include "delivery.h"

void addDelivery(Queue *Q, Food x)
{
    address newElmt = newnode(x);

    if(isempty(*Q))
    {
        ADDR_HEAD(*Q) = newElmt;
        ADDR_TAIL(*Q) = newElmt;
    }
    else
    {
        address p = ADDR_HEAD(*Q);
        
        if(timeToMinute(INFO(p).deltime) > timeToMinute(INFO(newElmt).deltime))
        {
            NEXT(newElmt) = ADDR_HEAD(*Q);
            ADDR_HEAD(*Q) = newElmt;
        }
        else
        {
            while (NEXT(p) != NULL && timeToMinute(NEXT(p)->info.deltime) < timeToMinute(x.deltime)) {
                p = NEXT(p);
            }
            NEXT(newElmt) = NEXT(p);
            NEXT(p) = newElmt;
        }
    }
}

void displayDelivery(Queue Q)
{
    address p = ADDR_HEAD(Q);
    int i=1;
    while (p != NULL) {
        // displayWord(INFO(p).name);
        printf("%d. ", i);
        displayWordFood(INFO(p).name);
        printf ("         ");
        displayTime(INFO(p).deltime);
        p = NEXT(p);
        if (p != NULL) {
            printf("\n");
        }
        i++;
    }
}
