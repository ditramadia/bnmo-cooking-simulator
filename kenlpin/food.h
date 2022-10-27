/* ADT Food */

#include "../adete/boolean.h"
#include "../adete/time.h"

#ifndef FOOD_H
#define FOOD_H

typedef struct
{
    int id;
    char* name[50];
    TIME exp;
    char act;
    TIME duration;
} Food;

#define ID(f) (f).id
#define NAME(f) (f).name
#define EXP(f) (f).exp
#define ACT(f) (f).act
#define DURATION(f) (f).duration

#endif

