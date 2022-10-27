/* ADT Food */

#include "../adete/boolean.h"

#ifndef FOOD_H
#define FOOD_H

typedef struct
{
    int id;
    char* name[50];
    int exp;
    int act;
    int duration;
} Food;

#define ID(F) (F).id
#define NAME(F) (F).name
#define EXP(F) (F).exp
#define ACT(F) (F).act
#define DURATION(F) (F).duration

#endif
