#include<stdio.h>

#include "../../adt/tree/tree.h"
#include "../../adt/food/food.h"
#include "../../adt/queuelinked/queuelinked.h"
#include "../../adt/wordmachinefood/wordmachine.h"

void mix(Foodlist l,Queue *q,Foodlist listMix,List treeList[100][100]){
    int n = listlength(listMix);
    printf("==============================================================\n");
    printf("|                              MIX                           |\n");
    printf("==============================================================\n");
    printf("|  No. Nama\n");
    printf("|\n");
    printf("|  0. Batal\n");
    for(int i=1; i<=n;i++){
        printf("|  %d. ", i);
        displayWordFood(listMix.F[i].name);
        printf("\n");
    }
    printf("|\n");
    printf("==============================================================\n");
    int x;
    // printf("fjdsklajfkldsajfkl;dsjalfdjsakl;fj;as\n");
    printf("Masukkan nomor barang yang ingin dibuat: ");
    scanf("%d",&x);
    if (x == 0)
    {
        system(CLEAR);
        return;
    }
    while (x > n || x < 0)
    {
        printf("Nomor barang tidak valid. Masukkan nomor barang yang ingin dibuat: ");
        scanf("%d", &x);
        if (x == 0)
        {
            system(CLEAR);
            return;
        }
    }
    int idx;
    int lengthtree = 0;
    while((FIRST(treeList[lengthtree][0])) != NULL){
        lengthtree++;
    }
    
    for(int i=0;i<lengthtree;i++){
        if(listMix.F[x].id == INFO(NEXT(FIRST(treeList[i][0])))){
            idx=i;
        }
    }

    int panjang = 0;
    while(FIRST(treeList[idx][panjang]) != NULL){
        panjang++;
    } 
    
    // // printf("idx %d\n", idx);
    // printf("lengtree %d\n", lengthtree);
    // printf("panjang %d\n", panjang);
    boolean lengkap = true;
    

    for(int i=0; i<panjang;i++){
        // printf("%d\n",i);
        if(!isExist(*q, INFO(FIRST(treeList[idx][i])))){
            lengkap = false;
        }
        else{
            // printf("ada\n");
        }
    }

    if(lengkap){
        // printf("Bahan lengkap\n");
        for(int i=0; i<panjang;i++){
            Food temp;
            dequeueAt(q,&temp,INFO(FIRST(treeList[idx][i])));
            printf("%d",temp.id);
        }
        AddInventory(q,listMix.F[x]);
        printf("Bahan tersedia, makanan berhasil dibuat\n");
    }
    else{
        printf("Bahan tidak lengkap\n");
    }
    // int xyz;
    // scanf("%d",&xyz);
}