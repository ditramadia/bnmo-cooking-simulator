#include <stdio.h>
#include <../src/adt/prioqueuetime/prioqueuetime.c>


void notifikasiExp(PrioQueueTime q){
    if(Time(q)==0){
        printf("%s sudah kedaluwarsa",Info(Head(q)));
    }
}
void notifikasiExp(PrioQueueTime q){
    if(Time(q)==0){
        printf("%s sudah masuk ke dalam inventory",Info(Head(q)));
    }
}