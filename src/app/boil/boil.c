#include<stdio.h>
#include "../../adt/food/food.h"
#include "../../adt/tree/tree.h"
#include "../../adt/queuelinked/queuelinked.h"

void boil(Foodlist l,Queue *q,Foodlist listBoil,List treeList[100][100]){
    // anggep foodlist itu f di global
    // anggep panjang foodlist n

    int bin;
    int n = listlength(listBoil);
    
    printf("==============================================================\n");
    printf("|                             BOIL                           |\n");
    printf("==============================================================\n");
    printf("|  No. Nama\n");
    printf("|\n");
    printf("|  0. Batal\n");
    for(int i=1; i<=n;i++){
        printf("|  %d. ", i);
        displayWordFood(listBoil.F[i].name);
        printf("\n");
    }
    printf("|\n");
    printf("==============================================================\n");
    // int a = 0;
    int x;
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
    // printf("lengtre %d\n",LengthTree);
    // printf(("%d",(FIRST(treeList[5][5]))));
    int lengthtree = 0;
    while((FIRST(treeList[lengthtree][0])) != NULL){
        lengthtree++;
    }
    //     printf("ADFSAFDSAFDAS");
    //     printf("lengtree%d\n",lengthtree);
    
    for(int i=0;i<lengthtree;i++){
        if(listBoil.F[x].id == INFO(NEXT(FIRST(treeList[i][0])))){
            idx=i;
            // printf("cek cek%d\n",idx);
        }
    }
    // printf("%d\n",idx);
    int panjang = 0;
    while(FIRST(treeList[idx][panjang]) != NULL){
        panjang++;
    } 
        // printf("cek\n");
        // printf("PANJANG %d\n",panjang);
    
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
        }
        AddInventory(q,listBoil.F[x]);
        printf("Bahan tersedia, ");
        displayWordFood(listBoil.F[x].name);
        printf(" berhasil dibuat dan sudah masuk ke inventory!\n");
    }
    else{
        printf("Bahan tidak lengkap\n");
    }
    printf("\nTekan enter untuk kembali ke map\n");
    scanf("%d", &bin);
    return;
}