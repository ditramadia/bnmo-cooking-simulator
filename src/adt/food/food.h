#include <stdio.h>
#include "../time/time.h"

#ifndef FOOD_H
#define FOOD_H

typedef struct {
    int id;
    Word name;
    Time exptime;
    Time deltime;
    Word act;
} Food;

#define Id(f) (f).id
#define Name(f) (f).name
#define ExpTime(f) (f).exptime
#define DelTime(f) (f).deltime
#define Act(f) (f).act

void addID();
void addName();
void addExpTime();
void addDelTime();
void addAct();
void addList();
void displayFood(Food food);


#endif