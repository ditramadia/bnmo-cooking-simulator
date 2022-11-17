#ifndef FOOD_H
#define FOOD_H

#include <stdio.h>
#include "../time/time.h"
#include "../wordmachinefood/wordmachine.h"

typedef struct {
    int id;
    Word name;
    Time exptime;
    Time deltime;
    Word act;
} Food;

typedef struct{
    Food F[100];
} Foodlist;

#define Id(f) (f).id
#define Name(f) (f).name
#define ExpTime(f) (f).exptime
#define DelTime(f) (f).deltime
#define Act(f) (f).act

void addID(Foodlist *f,int i);
void addName(Foodlist *f,int i);
void addExpTime(Foodlist *f,int i);
void addDelTime(Foodlist *f,int i);
void addAct(Foodlist *f,int i);
void addList();
void displayFood(Food food);
void listshop(Foodlist *s,Foodlist f, int listlength);
void listchop(Foodlist *f);
void listmix(Foodlist *f);
void listfry(Foodlist *s,Foodlist f, int listlength);
void listboil(Foodlist *f);
int length(Foodlist f);


#endif