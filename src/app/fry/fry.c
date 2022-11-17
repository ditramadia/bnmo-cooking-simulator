#include<stdio.h>
// #include "../../adt/queuelinked/queuelinked.c"
// #include "../../adt/tree/tree.c"
#include "../../adt/food/food.h"
#include "../../adt/queuelinked/queuelinked.h"
#include "../../adt/wordmachinefood/wordmachine.h"
#include "../../adt/tree/tree.h"

void fry(Foodlist l,Queue q,Foodlist listFry,List treeList[100][100]){
    int n = listlength(listFry);
    printf("==============================================================\n");
    printf("|                       DAPUR                                |\n");
    printf("==============================================================\n");
    printf("|  No. Nama\n");
    printf("|\n");
    printf("|  0. Batal\n");
    for(int i=1; i<=n;i++){
        printf("|  %d. ", i);
        displayWordFood(listFry.F[i].name);
        printf("\n");
    }
    printf("|\n");
    printf("==============================================================\n");
    // int a = 0;
    int x;
    printf("Masukkan nomor barang yang ingin dibeli: ");
    scanf("%d",&x);
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


    // for(int i=0; i<foodListLen;i++){
    //     char *actfood = wordToStr((l).F[i].act);
    //     if(compareString(actfood, "Fry")){
    //         displayWord((listFood).F[i].name);
    //         listfood[a] = wordtostr((listFood).F[i].name);
    //         a++;
    //         print("\n");
    //     }
    // }
    // char *c;
    // scanf("%s",&c);
    // int cek = 0;
    // int idxFood;
    // for(int i=0; i<foodListLen; i++){
    //     if(listfood[i] == c){
    //         cek =1;
    //         idxFood=i;
    //     };
    // }
    // if(!cek){
    //     print("tidak ada jenis makanan yang memenuhi fry, masukan ulang\n");
    //     scanf("%s",&c);
    //     for(int i=0; i<foodListLen; i++){
    //         if(listfood[i] == c) cek = 1;
    //     }
    // }
    
    int idx;
    for(int i=0;i<n;i++){
        if(listFry.F[x].id==INFO(NEXT(FIRST(treeList[i][0])))){
            idx=i;
        }
    }
    // dibawah ini yang belom selesai
    int isTrue=0;
    for(int i=0;i<length(l[idx]);i++){
        for(int j=0;j<NBElmt(q);j++){
            if(INFO(FIRST(l[idx][i]))==Elmt(q,j)){
                isTrue++;
            }
        }
    }
    if(isTrue==length(l[idx])){
        for(int i=0;i<length(l[idx]);i++){
            for(int j=0;j<NBElmt(q);j++){
            if(INFO(FIRST(l[idx][i]))==Elmt(q,j)){
                    Head(q)=Elmt(q,j);
                    Food val;
                    dequeue(&q,&val);
                }
            }
        }
    }
}