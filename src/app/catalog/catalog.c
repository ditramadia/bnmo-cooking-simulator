#include "../../adt/food/food.h"
#include "../../adt/time/time.h"

void catalog(Foodlist l)
{
    char bin;
    int n = listlength(l);

    printf("====================================================================================\n");
    printf("|                                      CATALOG                                     |\n");
    printf("====================================================================================\n");
    printf("|  No. Nama ----- Waktu Kadaluarsa ----- Aksi Yang Diperlukan ----- Waktu Pengiriman\n");
    printf("|\n");

    for (int i = 1; i <= n; i++)
    {
        printf("|  %d. ", i);
        displayWordFood(l.F[i].name);
        printf(" ----- ");
        displayTime(l.F[i].exptime);
        printf(" ----- ");
        displayWordFood(l.F[i].act);
        printf(" ----- ");
        printTime(l.F[i].deltime);
        printf("\n");
    }

    printf("|\n");
    printf("==============================================================\n");
    printf("\n");

    printf("Tekan enter menutup inventory\n");
    scanf("%c", &bin);
    return;
}