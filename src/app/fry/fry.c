#include<stdio.h>
// #include "../../adt/queuelinked/queuelinked.c"
#include "../../adt/tree/tree.h"
#include "../../adt/food/food.h"
#include "../../adt/queuelinked/queuelinked.h"
#include "../../adt/wordmachinefood/wordmachine.h"

// boolean isThere(int arr[],int val,int lengthArr){
//     for(int i=0;i<lengthArr;i++){
//         if(arr[i]==val) return true;
//     }
// }

void fry(Foodlist l,Queue *q,Foodlist listFry,List treeList[100][100],int LengthTree){
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
        if(listFry.F[x].id == INFO(NEXT(FIRST(treeList[i][0])))){
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
        printf("%d\n",i);
        if(!isExist(*q, INFO(FIRST(treeList[idx][i])))){
            lengkap = false;
        }
        else{
            printf("ada\n");
        }
    }
    // int xyz;
    // scanf("%d",&xyz);

    // // dibawah ini yang belom selesai
    // // int isTrue=0;
    // // int pack[listlength(listFry)];
    // // for(int i=0;i<listlength(listFry);i++){
    // //     for(int j=0;j<length(q);j++){
    // //         if(isExist(q,INFO(FIRST(treeList[idx][i]))) && (!isThere(pack,Elmt(q,j),isTrue))){
    // //             pack[isTrue] = ;
    // //             isTrue++;
    // //         }
    // //     }
    // // }


    if(lengkap){
        printf("Bahan lengkap\n");
        for(int i=0; i<idx;i++){
            Food temp;
            dequeueAt(q,&temp,INFO(FIRST(treeList[idx][i])));
        }
        AddInventory(q,listFry.F[x]);
        printf("berhasil ges\n");
    }
    else{
        printf("Bahan tidak lengkap\n");
    }
    // // if(isTrue == listlength(listFry)){
    // //     for(int i=0; i < listlength(listFry); i++){
    // //         for(int j=0;j<length(q);j++){
    // //         if(isExist(q, INFO(FIRST(treeList[idx][i])))){
    // //                 // HEAD(q) = Elmt(q,j);
    // //                 Food temp;
    // //                 // dequeue(&q,&val);
    // //                 dequeueAt(&q,&temp, INFO(FIRST(treeList[idx][i])));
    // //             }
    // //         }
    // //     }
    // // }
    // int temp;
    // scanf("%d",&temp);
}