#include <stdio.h>
// #include "../../adt/prioqueuetime/prioqueuetimedel.c"
// #include "../../adt/prioqueuetime/prioqueuetimeinv.c"
// #include "../../adt/queuelinked/queuelinked.h"
#include "notifikasi.h"

Notiflist Nl;


void addNotif(Notiflist *Nl,int typenotif, Food food){
    int length;
    length = nbelmt(*Nl);
    (*Nl).N[length].typenotif = typenotif;
    (*Nl).N[length].food = food;
}

int nbelmt(Notiflist Nl){
    int i = 0;
    while(Nl.N[i].typenotif != 0){
        i++;
    }
    // printf("%d",i);
    return i;
}

void resetNotif(Notiflist *Nl){
    int length;
    length = nbelmt(*Nl);
    for(int i=0;i<length;i++){
        (*Nl).N[i].typenotif = 0;
    }
}

void displayNotif(Notiflist Nl){
    int length;
    length = nbelmt(Nl);
    if (length == 0){
        printf ("Notifikasi : -\n");
    }
    else {
        printf("Notifikasi : \n");
    for(int i=0;i<length;i++){
        
        printf("%d. ",i+1);
        if(Nl.N[i].typenotif == 1){
            printf("Pesanan ");
            displayWordFood(Nl.N[i].food.name);
            printf(" telah tiba\n");
        }
        else if(Nl.N[i].typenotif == 2){
            // printf("Pesanan ");
            displayWordFood(Nl.N[i].food.name);
            printf(" sudah kadaluwarsa\n");
        }
        else if(Nl.N[i].typenotif == 3){ // FRY
            printf("Proses penggorengan  ");
            displayWordFood(Nl.N[i].food.name);
            printf(" dibatalkan\n");
        }
        else if(Nl.N[i].typenotif == 4){ // BOIL
            printf("Proses rebusan  ");
            displayWordFood(Nl.N[i].food.name);
            printf(" dibatalkan\n");
        }
        else if(Nl.N[i].typenotif == 5){   //CHOP
            printf("Proses pemotongan ");
            displayWordFood(Nl.N[i].food.name);
            printf(" dibatalkan\n");
        }
        else if(Nl.N[i].typenotif == 6){  // MIX
            printf("Proses pembuatan ");
            displayWordFood(Nl.N[i].food.name);
            printf(" dibatalkan\n");
        }
}
    }
}





