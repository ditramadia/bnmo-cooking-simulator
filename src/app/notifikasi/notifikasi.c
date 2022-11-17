#include <stdio.h>
// #include "../../adt/prioqueuetime/prioqueuetimedel.c"
// #include "../../adt/prioqueuetime/prioqueuetimeinv.c"
#include "../../adt/queuelinked/queuelinked.h"


void notifikasiExp(Queue q){
    if(!IsEmpty(q)) {
        if (timeToMinute(q.addrHead->info.exptime)== 0) {
            printf("%s sudah kedaluwarsa\n", q.addrHead->info.name);
        }
    }
}
void notifikasiDel(Queue q){
    if(!IsEmpty(q)) {
        if (timeToMinute(q.addrHead->info.exptime) == 0) {
            printf("%s sudah masuk ke dalam inventory\n", q.addrHead->info.name);
        }
    }
}