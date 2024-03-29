#include <stdio.h>
#include <stdlib.h>

#include "queuelinked.h"

address newnode(Food val)
{
    address p = (address)malloc(sizeof(NodE));
    if (p != NULL)
    {
        Info(p) = val;
        Next(p) = NULL;
    }
    return p;
}

int isempty(Queue q)
{
    return (ADDR_HEAD(q) == NULL && ADDR_TAIL(q) == NULL);
}

int length(Queue q)
{
    address P = ADDR_HEAD(q);
    int i = 0;
    while (P != NULL)
    {
        P = Next(P);
        i++;
    }
    return i;
}

void CreateQueue(Queue *q)
{
    ADDR_HEAD(*q) = NULL;
    ADDR_TAIL(*q) = NULL;
}

void DisplayQueue(Queue q)
{
    address p = ADDR_HEAD(q);
    printf("");
    int i = 1;
    while (p != NULL)
    {
        // displayWordFood(Info(p).name);
        printf("%d. ", i);
        displayWordFood(Info(p).name);
        printf("     ");
        displayTime(Info(p).exptime);
        p = Next(p);
        if (p != NULL)
        {
            printf("\n");
        }
        i++;
    }
    printf("");
}

void enqueue(Queue *q, Food x)
{
    address p = newnode(x);
    if (p != NULL)
    {
        if (isempty(*q))
        {
            ADDR_HEAD(*q) = p;
            ADDR_TAIL(*q) = p;
        }
        else
        {
            Next(ADDR_TAIL(*q)) = p;
            ADDR_TAIL(*q) = p;
        }
    }
}

void dequeue(Queue *q, Food *x)
{
    if (!isempty(*q))
    {
        address p = ADDR_HEAD(*q);
        *x = Info(p);
        ADDR_HEAD(*q) = Next(p);
        free(p);
        if (ADDR_HEAD(*q) == NULL)
        {
            ADDR_TAIL(*q) = NULL;
        }
    }
}

void insertprio(Queue *q, Food x)
{
    address newElmt = newnode(x);

    if (isempty(*q))
    {
        ADDR_HEAD(*q) = newElmt;
        ADDR_TAIL(*q) = newElmt;
    }
    else
    {
        address p = ADDR_HEAD(*q);

        if (timeToMinute(Info(p).exptime) > timeToMinute(Info(newElmt).exptime))
        {
            Next(newElmt) = ADDR_HEAD(*q);
            ADDR_HEAD(*q) = newElmt;
        }
        else
        {
            while (Next(p) != NULL && timeToMinute(Next(p)->info.exptime) < timeToMinute(x.exptime))
            {
                p = Next(p);
            }
            Next(newElmt) = Next(p);
            Next(p) = newElmt;
        }
    }
}

void dequeueAt(Queue *q, Food *x, int id)
{
    if (!isempty(*q))
    {
        address p = ADDR_HEAD(*q);
        if (Info(p).id == id)
        {
            *x = Info(p);
            ADDR_HEAD(*q) = Next(p);
            free(p);
            if (ADDR_HEAD(*q) == NULL)
            {
                ADDR_TAIL(*q) = NULL;
            }
        }
        else
        {
            while (Next(p) != NULL && Next(p)->info.id != id)
            {
                p = Next(p);
            }
            if (Next(p) != NULL)
            {
                address point = Next(p);
                *x = Info(point);
                Next(p) = Next(point);
                free(point);
                if (Next(p) == NULL)
                {
                    ADDR_TAIL(*q) = p;
                }
            }
        }
    }
}

int isExist(Queue q, int id)
{
    address p = ADDR_HEAD(q);
    while (p != NULL)
    {
        // printf("cek\n");
        if (Info(p).id == id)
        {
            return 1;
        }
        p = Next(p);
    }
    return 0;
}