#include <stdio.h>
#include "../../adt/food/food.h"
#include "../../adt/wordMachineFood/wordMachineFood.h"
#include "../../adt/tree/tree.h"

void cookbook(List l[100][100], Foodlist fl, Foodlist listBuy)
{
    int bin;
    int n = listlength(fl) - listlength(listBuy);
    printf("%d\n", n);

    printf("====================================================================================\n");
    printf("|                                     COOKBOOK                                     |\n");
    printf("====================================================================================\n");
    printf("|  (Aksi yang diperlukan - bahan...)\n");
    printf("\n");
    for (int i = 0; i < n; i++)
    {
        int x = INFO(NEXT(FIRST(l[i][0])));
        printf("|  %d. ", i + 1);
        displayWordFood(fl.F[x].name);
        printf("\n");
        displayWordFood(fl.F[x].act);
        int panjang = 0;
        while (FIRST(l[i][panjang]) != NULL)
        {
            panjang++;
        }
        for (int j = 0; j < panjang; j++)
        {
            printf(" - ");
            displayWordFood(fl.F[INFO(FIRST(l[i][j]))].name);
        }
        printf("\n");
    }

    printf("|  \n");
    printf("====================================================================================\n");
    printf("\n");

    printf("Tekan enter menutup inventory\n");
    getchar();
}