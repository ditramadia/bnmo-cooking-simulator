#ifndef FOOD_H
#define FOOD_H

#include "../wordmachinefood/wordmachine.h"
#include "../time/time.h"
#include "../boolean/boolean.h"
#include "../string/string.h"
#include "../foodlist/foodlist.h"

typedef struct
{
    int id;
    word name;
    Time exptime;
    Time deltime;
    word act;
} Food;

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
// void displayFood(Food food);
void listshop(Foodlist *s, Foodlist f, int listlength);
void listchop(Foodlist *f);
void listmix(Foodlist *f);
void listfry(Foodlist *s, Foodlist f, int listlength);
void listboil(Foodlist *f);
int listslength(Foodlist f);

#endif