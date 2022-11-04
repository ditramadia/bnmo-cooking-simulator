/* ADT Food */

#include "../adete/boolean.h"
#include "../adete/time.h"
#include "../adete/point.h"
#include "../adete/prioqueuetime.h"


#ifndef FOOD_H
#define FOOD_H

#define INVENTORY_CAP 100
#define IDX_UNDEF -999

typedef struct {
    int time;  /* [1..100], waktu dengan nilai 1..100 (1 adalah waktu adalah terendah) */
    char* info[50];  /* elemen karakter */
} infotype;

typedef struct{
    infotype * I;   /* tabel penyimpan elemen */
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

void AddFood (FoodList *f, infotype x);
/* I.S. f terdefinisi */
/* F.S. food ditambahkan ke inventory */


#endif

