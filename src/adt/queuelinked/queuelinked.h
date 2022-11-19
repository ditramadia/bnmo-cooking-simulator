#ifndef QUEUELINKED_H
#define QUEUELINKED_H

#include <stdlib.h>

#include "../food/food.h"

#define NIL NULL

typedef struct nOde *address;
typedef struct nOde
{
    Food info;
    address next;
} NodE;
typedef struct
{
    address addrHead;
    address addrTail;
} Queue;

#define Next(p) (p)->next
#define Info(p) (p)->info

#define ADDR_HEAD(q) (q).addrHead
#define ADDR_TAIL(q) (q).addrTail
#define HEAD(q) (q).addrHead->info

address newnode(Food x);
int isempty(Queue q);
int length(Queue q);

void CreateQueue(Queue *q);
void DisplayQueue(Queue q);

void enqueue(Queue *q, Food x);
void dequeue(Queue *q, Food *x);
void insertprio(Queue *q, Food x);
void dequeueAt(Queue *q, Food *x, int id);
int isExist(Queue q, int id);
#endif