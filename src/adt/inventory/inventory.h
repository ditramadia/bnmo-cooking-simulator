/* ADT Food */
#include "../wordmachinefood/wordmachine.c"
#include "../boolean/boolean.h"
#include "../time/time.c"
#include "../food/food.c"
#include "../point/point.c"
#include "../prioqueuetime/prioqueuetimeinv.c"

#ifndef INVENTORY_H
#define INVENTORY_H

#define INVENTORY_CAP 100
#define IDX_UNDEF -999


// typedef struct
// {
//     Food *I; /* tabel penyimpan elemen */
// } FoodList;

#define ID(f) (f).id
#define NAME(f) (f).name
#define Time(f) (f).Time
#define ACT(f) (f).act
#define DURATION(f) (f).duration

void Createinventory(PrioQueueTime *Q);
/* I.S. f sembarang */
/* F.S. Terbentuk inventory kosong */

//boolean isInventoryEmpty(FoodList f);
/* Mengirim true jika inventory kosong */

void AddInventory(PrioQueueTime *Q, Food I);
/* I.S. f terdefinisi */
/* F.S. food ditambahkan ke inventory */

void DisplayInventory();

void deleteInventory(PrioQueueTime *Q, Food *I);

void deleteInventoryAt(PrioQueueTime *Q, Food *I, int idx);

#endif
