#ifndef NOTIFIKASI_H
#define NOTIFIKASI_H

#include "../food/food.h"

typedef struct{
    int typenotif;
    Food food;
} Notifikasi;

typedef struct{
    Notifikasi N[1000];
} Notiflist;




#endif