/* ADT Food */

#include "../adete/boolean.h"
#include "../adete/time.h"
#include "../adete/point.h"
#include "../adete/prioqueuetime.h"


#ifndef FOOD_H
#define FOOD_H

#define INVENTORY_CAP 100
#define IDX_UNDEF -999

typedef struct{
    int id;
    char* name[50];
    TIME Time;
    char act;
    TIME duration;
} Food;

typedef struct{
    Food buffer[INVENTORY_CAP];
}FoodList;

#define ID(f) (f).id
#define NAME(f) (f).name
#define Time(f) (f).Time
#define ACT(f) (f).act
#define DURATION(f) (f).duration

void Createinventory (FoodList *f);
/* I.S. f sembarang */
/* F.S. Terbentuk inventory kosong */

boolean isInventoryEmpty (FoodList f);
/* Mengirim true jika inventory kosong */

void AddFood (FoodList *f, infotype id);
/* I.S. f terdefinisi */
/* F.S. food ditambahkan ke inventory */


#endif

