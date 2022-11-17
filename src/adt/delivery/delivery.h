#include "../boolean/boolean.h"
#include "../food/food.h"
#include "../queuelinked/queuelinked.c"

#ifndef DELIVERY_H
#define DELIVERY_H

#define ID(f) (f).id
#define NAME(f) (f).name
#define Time(f) (f).Time
#define ACT(f) (f).act
#define DURATION(f) (f).duration

void addDelivery(Queue *Q, Food I);
void delDelivery(Queue *Q, Food *I);
void displayDelivery(Queue Q);



#endif