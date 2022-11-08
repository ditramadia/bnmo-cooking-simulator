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

#define Id(f) (f).id
#define Name(f) (f).name
#define ExpTime(f) (f).exptime
#define DelTime(f) (f).deltime
#define Act(f) (f).act

void displayFood(Food food);


#endif