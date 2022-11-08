#include <stdio.h>
#include "../time/time.h"

#ifndef FOOD_H
#define FOOD_H

typedef struct {
    int id;
    char *name;
    Time exptime;
    Time deltime;
    char *act;
} Food;

void displayFood(Food food);
#endif