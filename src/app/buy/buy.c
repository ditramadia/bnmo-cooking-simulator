#include <stdio.h>
#include "../../adt/delivery/delivery.h"

void buy(Queue q, Foodlist listshop){
    int n;
    n = listlength(listshop);

    printf("List barang yang bisa dibeli:\n");
    for (int i = 1; i <= n; i++)
    {
        printf("%d. ", i);
        displayWord(listshop.F[i].name);
        printf("     ");
        displayTime(listshop.F[i].exptime);
        printf("\n");
        printf("     ");
        displayTime(listshop.F[i].deltime);
        printf("\n");
    }
    int x;
    char y;
    printf("Masukkan nomor barang yang ingin dibeli:   (Ketik '0' untuk membatalkan pembelian)\n");
    scanf("%d", &x);
    if (x == 0){
        printf("apakah anda ingin membatalkan pembelian? (y/n)");
        scanf("%c", &y);
        if (y == 'y'){
            printf("pembelian dibatalkan");
            simulator();
        }
        else{
            buy(q, listshop);
        }
    }
    while (x > n || x < 0)
    {
        printf("Nomor barang tidak valid. Masukkan nomor barang yang ingin dibeli: ");
        scanf("%d", &x);
        if (x == 0){
        printf("apakah anda ingin membatalkan pembelian? (y/n)");
        scanf("%c", &y);
        if (y == 'y'){
            printf("pembelian dibatalkan");
            simulator();
        }
        else{
            buy(q, listshop);
        }
    }
    addDelivery(&q, listshop.F[x]);
    printf("Barang berhasil dibeli!\n");
}