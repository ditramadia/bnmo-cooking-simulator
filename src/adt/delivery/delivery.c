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
