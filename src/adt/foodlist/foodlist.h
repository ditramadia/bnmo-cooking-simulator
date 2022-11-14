#include <stdio.h>
#include "../food/food.c"

#ifndef FOODLIST_H
#define FOODLIST_H

typedef struct{
    Food F[100];
} Foodlist;

#endif