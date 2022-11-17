#include <stdio.h>
#include "../../adt/delivery/delivery.c"

void buy(Queue q, Foodlist listshop)
{
    int n;
    n = listlength(listshop);

    printf("List barang yang bisa dibeli:\n");
    printf("0. Batal\n");
    for (int i = 1; i <= n; i++)
    {
        printf("%d. ", i);
        displayWordFood(listshop.F[i].name);
        printf("     ");
        displayTime(listshop.F[i].exptime);
        printf("---");
        printf("     ");
        displayTime(listshop.F[i].deltime);
        printf("\n");
    }
    int x;
    char y;
    printf("Masukkan nomor barang yang ingin dibeli:\n");
    scanf("%d", &x);
    if (x == 0)
    {
        printf("apakah anda ingin membatalkan pembelian? (y/n)");
        scanf("%c", &y);
        if (y == 'y')
        {
            printf("pembelian dibatalkan");
            return;
        }
        else
        {
            buy(q, listshop);
        }
    }
    while (x > n || x < 0)
    {
        printf("Nomor barang tidak valid. Masukkan nomor barang yang ingin dibeli: ");
        scanf("%d", &x);
        if (x == 0)
        {
            printf("apakah anda ingin membatalkan pembelian? (y/n)");
            scanf("%c", &y);
            if (y == 'y')
            {
                printf("pembelian dibatalkan");
                return;
            }
            else
            {
                buy(q, listshop);
            }
        }
        addDelivery(&q, listshop.F[x]);
        printf("Barang berhasil dibeli!\n");
    }
}