#include <stdio.h>
#include "../../adt/food/food.h"
#include "../../adt/wordmachinefood/wordmachine.h"

void cookbook(Foodlist l)
{
    char bin;
    int n = listlength(l);
    
    printf("====================================================================================\n");
    printf("|                                     COOKBOOK                                     |\n");
    printf("====================================================================================\n");
    printf("|  No.  Nama\n");
    printf("|       Aksi yang diperlukan ===== Bahan yang dibutuhkan\n");
    printf("|\n");

    for (int i = 1; i <= n; i++)
    {
        char* buy;
        wordToStri(l.F[i].act, &buy);
        if (buy != "Buy")
        {
            printf("|  %d. ", i);
            displayWordFood(l.F[i].name);
            printf("\n");
            printf("|     ");
            displayWordFood(l.F[i].act);
            printf(" ===== ");
        
            // output akhir
            // 2.  nasi goreng
            //     FRY ===== nasi ----- mentega ----- kecap ----- otakangger
            printf("\n"); 
            printf("|     \n");
        }
    }
    printf("|\n");
    printf("====================================================================================\n");
    printf("\n");

    printf("Tekan enter menutup inventory\n");
    scanf("%c", &bin);
    return;
}