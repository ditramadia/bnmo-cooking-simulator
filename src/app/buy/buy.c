#include <stdio.h>

void buy(Foodlist listshop)
{
    // Display buy menu
    int n = listlength(listshop);
    printf("%d\n", n);
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
}