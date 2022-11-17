#include<stdio.h>

#include "../inventory/inventory.c"



int main(){
    Foodlist f;
    Foodlist s;
    Queue Q;
    Food temp;
    int N;
    // Createinventory(&Q);
    addList(&f,N);
    // AddInventory(&Q, f.F[1]);
    // AddInventory(&Q, f.F[2]);
    // AddInventory(&Q, f.F[3]);
    // AddInventory(&Q, f.F[4]);
    // printf("%d\n",isExist(Q, 2));
    // printf("%d\n",isExist(Q, 5));
    // dequeueAt (&Q, &temp, 2);
    // // printf("\n\n%d\n",f.F->id);

    // // printf("%d\n", IsEmpty(Q));
    // DisplayQueue(Q);

    listfry(&s,f, 6);
}