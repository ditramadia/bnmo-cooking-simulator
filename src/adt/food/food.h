#ifndef FOOD_H
#define FOOD_H

#include "../time/time.h"
#include "../string/string.h"
#include "../wordMachineFood/wordMachineFood.h"

typedef struct
{
    int id;
    FoodWord name;
    Time exptime;
    Time deltime;
    FoodWord act;
} Food;

typedef struct
{
    Food F[100];
} Foodlist;

#define Id(f) (f).id
#define Name(f) (f).name
#define ExpTime(f) (f).exptime
#define DelTime(f) (f).deltime
#define Act(f) (f).act

void addID(Foodlist *f, int i);
void addName(Foodlist *f, int i);
void addExpTime(Foodlist *f, int i);
void addDelTime(Foodlist *f, int i);
void addAct(Foodlist *f, int i);
void addList();
void listshop(Foodlist *s, Foodlist f);
void listchop(Foodlist *s, Foodlist f);
void listmix(Foodlist *s, Foodlist f);
void listfry(Foodlist *s, Foodlist f);
void listboil(Foodlist *s, Foodlist f);
int listlength(Foodlist f);

#endif