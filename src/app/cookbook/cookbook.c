#include <stdio.h>
#include "../../adt/food/food.h"
#include "../../adt/wordmachinefood/wordmachine.h"
#include "../../adt/tree/tree.h"

void cookbook(List l[100][100], Foodlist fl )
{
    int bin;
    int n = listlength(fl);
    
    printf("====================================================================================\n");
    printf("|                                     COOKBOOK                                     |\n");
    printf("====================================================================================\n");
    printf("(Aksi yang diperlukan - bahan...)\n");
    // printf("|  No.  Nama\n");
    printf("\n");
    for(int i=0; i<n;i++){
        int x = INFO(NEXT(FIRST(l[i][0])));
        // printf("%d",x);
        printf("%d. ",i+1);
        displayWordFood(fl.F[x].name);
        printf("\n");
        displayWordFood(fl.F[x].act);
        int panjang = 0;
        while (FIRST(l[i][panjang]) != NULL){
            panjang++;
        }
        for(int j=0; j<panjang; j++){
            printf(" - ");
            displayWordFood(fl.F[INFO(FIRST(l[i][j]))].name);
        }
        printf("\n");
    }


    // for (int i = 1; i <= n; i++)
    // {
    //     char* buy;
    //     wordToStri(l.F[i].act, &buy);
    //     if (buy != "Buy")
    //     {
    //         printf("|  %d. ", i);
    //         displayWordFood(l.F[i].name);
    //         printf("\n");
    //         printf("|     ");
    //         displayWordFood(l.F[i].act);
    //         printf(" ===== ");
        
    //         // output akhir
    //         // 2.  nasi goreng
    //         //     FRY ===== nasi ----- mentega ----- kecap ----- otakangger
    //         printf("\n"); 
    //         printf("|     \n");
    //     }
    // }
    printf("|\n");
    printf("====================================================================================\n");
    printf("\n");

    printf("Tekan enter menutup inventory\n");
    // scanf("%d", &bin);
    // return;
}