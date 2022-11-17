#include <stdio.h>
#include <stdlib.h>
#include "queuelinked.h"
// #include "../food/food.c"

address newnode(Food val) {
    address p = (address) malloc(sizeof(NodE));
    if (p != NULL) {
        INFO(p) = val;
        NEXT(p) = NULL;
    }
    return p;
}

boolean isempty(Queue q){
    return (ADDR_HEAD(q) == NULL && ADDR_TAIL(q) == NULL);
}

int length(Queue q){
    address P = ADDR_HEAD(q);
    int i = 0;
    while (P != NULL){
        P = NEXT(P);
        i++;
    }
    return i;
}

void CreateQueue(Queue *q){
    ADDR_HEAD(*q) = NULL;
    ADDR_TAIL(*q) = NULL;
}

void DisplayQueue(Queue q){
    address p = ADDR_HEAD(q);
    printf("");
    int i=1;
    while (p != NULL) {
        // displayWord(INFO(p).name);
        printf("%d. ", i);
        displayWord(INFO(p).name);
        printf ("     ");
        displayTime(INFO(p).exptime);
        p = NEXT(p);
        if (p != NULL) {
            printf("\n");
        }
        i++;
    }
    printf("");
}

void enqueue(Queue *q, Food x){
    address p = newnode(x);
    if (p != NULL) {
        if (isempty(*q)) {
            ADDR_HEAD(*q) = p;
            ADDR_TAIL(*q) = p;
        } else {
            NEXT(ADDR_TAIL(*q)) = p;
            ADDR_TAIL(*q) = p;
        }
    }
}

void dequeue(Queue *q, Food *x){
    if (!isempty(*q)) {
        address p = ADDR_HEAD(*q);
        *x = INFO(p);
        ADDR_HEAD(*q) = NEXT(p);
        free(p);
        if (ADDR_HEAD(*q) == NULL) {
            ADDR_TAIL(*q) = NULL;
        }
    }
}

// void insertprio(Queue *q, Food x){
//     address p = newnode(x);
//     if (p != NULL) {
//         if (isempty(*q)) {
//             ADDR_HEAD(*q) = p;
//             ADDR_TAIL(*q) = p;
//         } else {
//             address point = ADDR_HEAD(*q);
//             // printf("yg diinsert: %d\n", timeToMinute(INFO(p).exptime));
//             // printf("yg udh ada: %d\n", timeToMinute(INFO(point).exptime));
//             if(NEXT(point) == NULL)
//             {
//                 if(timeToMinute(INFO(point).exptime) < timeToMinute(INFO(p).exptime))
//                 {
//                     NEXT(point) = p;
//                     ADDR_TAIL(*q) = p;
//                 }
//                 else
//                 {
//                     NEXT(p) = point;
//                     ADDR_HEAD(*q) = p;
//                     ADDR_TAIL(*q) = point;
//                 }
//             }
//             else
//             {
//             while (NEXT(point) != NULL && timeToMinute(NEXT(point)->info.exptime) < timeToMinute(x.exptime)) {
//                 point = NEXT(point);
//             }
//             }
//             NEXT(p) = NEXT(point);
//             NEXT(point) = p;
//             }
//         }
//     }
// }

void insertprio(Queue *q, Food x)
{
    address newElmt = newnode(x);

    if(isempty(*q))
    {
        ADDR_HEAD(*q) = newElmt;
        ADDR_TAIL(*q) = newElmt;
    }
    else
    {
        address p = ADDR_HEAD(*q);
        
        if(timeToMinute(INFO(p).exptime) > timeToMinute(INFO(newElmt).exptime))
        {
            NEXT(newElmt) = ADDR_HEAD(*q);
            ADDR_HEAD(*q) = newElmt;
        }
        else
        {
            while (NEXT(p) != NULL && timeToMinute(NEXT(p)->info.exptime) < timeToMinute(x.exptime)) {
                p = NEXT(p);
            }
            NEXT(newElmt) = NEXT(p);
            NEXT(p) = newElmt;
        }
    }
}

void dequeueAt(Queue *q, Food *x, int id){
    if (!isempty(*q)) {
        address p = ADDR_HEAD(*q);
        if (INFO(p).id == id) {
            *x = INFO(p);
            ADDR_HEAD(*q) = NEXT(p);
            free(p);
            if (ADDR_HEAD(*q) == NULL) {
                ADDR_TAIL(*q) = NULL;
            }
        } else {
            while (NEXT(p) != NULL && NEXT(p)->info.id != id) {
                p = NEXT(p);
            }
            if (NEXT(p) != NULL) {
                address point = NEXT(p);
                *x = INFO(point);
                NEXT(p) = NEXT(point);
                free(point);
                if (NEXT(p) == NULL) {
                    ADDR_TAIL(*q) = p;
                }
            }
        }
    }
}

boolean isExist(Queue q, int id){
    address p = ADDR_HEAD(q);
    while (p != NULL) {
        if (INFO(p).id == id) {
            return true;
        }
        p = NEXT(p);
    }
    return false;
}