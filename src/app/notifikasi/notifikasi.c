#include <stdio.h>
#include "../../adt/prioqueuetime/prioqueuetimedel.c"
#include "../../adt/prioqueuetime/prioqueuetimeinv.c"


void notifikasiExp(PrioQueueTime q){
    if(!IsEmpty(q)) {
        if (Time(q) == 0) {
            printf("%s sudah kedaluwarsa\n", Name(Head(q)));
        }
    }
}
void notifikasiDel(PrioQueueTime q){
    if(!IsEmpty(q)) {
        if (Time(q) == 0) {
            printf("%s sudah masuk ke dalam inventory\n", Name(Head(q)));
        }
    }
}