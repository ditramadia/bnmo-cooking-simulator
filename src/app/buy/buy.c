#include <stdio.h>
#include "../../adt/delivery/delivery.c"

void buy(Queue *q, Foodlist listshop)
{
    int n;
    n = listlength(listshop);

    printf("==============================================================\n");
    printf("|                       GRIYA CILEGON                        |\n");
    printf("==============================================================\n");
    printf("|  No. Nama ----- Waktu Kadaluarsa ----- Waktu Delivery\n");
    printf("|\n");
    printf("|  0. Batal\n");
    for (int i = 1; i <= n; i++)
    {
        printf("|  %d. ", i);
        displayWordFood(listshop.F[i].name);
        printf(" ----- ");
        displayTime(listshop.F[i].exptime);
        printf(" ----- ");
        displayTime(listshop.F[i].deltime);
        printf("\n");
    }
    printf("|\n");
    printf("==============================================================\n");
    int x;
    char y;
    printf("Masukkan nomor barang yang ingin dibeli: ");
    scanf("%d", &x);
    if (x == 0)
    {
        system(CLEAR);
        return;
    }
    while (x > n || x < 0)
    {
        printf("Nomor barang tidak valid. Masukkan nomor barang yang ingin dibeli: ");
        scanf("%d", &x);
        if (x == 0)
        {
            system(CLEAR);
            return;
        }
    }
    // addDelivery(&q, listshop.F[x]);
    addDelivery(q, listshop.F[x]);
    updateDeliveryState(&currentGameState, *q);
    insertState(&stateHistory, currentGameState);

    system(CLEAR);
    printf("==============================================================\n");
    printf("|                 Makanan berhasil dipesan!                  |\n");
    printf("==============================================================\n");
}