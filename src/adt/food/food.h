#include <stdio.h>
#include "../time/time.h"

#ifndef FOOD_H
#define FOOD_H

typedef struct {
    int id;
    char name[50];
    Time exptime;
    Time deltime;
    char act[10];
} Food;

void displayFood(Food food);
#endif