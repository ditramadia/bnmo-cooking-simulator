#include <stdio.h>
#include "../../adt/food/food.h"
#include "../../adt/tree/tree.h"
#include "../../adt/queuelinked/queuelinked.h"

void chop(Foodlist l, Queue *q, Foodlist listchop, List treeList[100][100])
{
    // anggep panjang foodlist n

    // printf("list yang bisa di chop :\n");
    // int a = 0;
    // char *listfood[696];

    // for(int i=0; i<foodListLen;i++){
    //     if(compareString(wordToStr((listFood).F[i].act), "Chop")){
    //         displayWord((listFood).F[i].name);
    //         listfood[a] = wordtostr((listFood).F[i].name);
    //         a++;
    //         print("\n");
    //     }
    // }
    // char *c;
    // scanf("%s",&c);
    // int cek = 0;
    // for(int i=0; i<foodListLen; i++){
    //     if(listfood[i] == c) cek = 1;
    // }
    // if(!cek){
    //     print("tidak ada jenis makanan yang memenuhi chop, masukan ulang\n");
    //     scanf("%s",&c);
    //     for(int i=0; i<foodListLen; i++){
    //         if(listfood[i] == c) cek = 1;
    //     }
    // }
    // else{

    // }
    int bin;
    int n = listlength(listchop);
    printf("==============================================================\n");
    printf("|                            CHOP                            |\n");
    printf("==============================================================\n");
    printf("|  No. Nama\n");
    printf("|\n");
    printf("|  0. Batal\n");
    for (int i = 1; i <= n; i++)
    {
        printf("|  %d. ", i);
        displayWordFood(listchop.F[i].name);
        printf("\n");
    }
    printf("|\n");
    printf("==============================================================\n");
    // int a = 0;
    int x;
    printf("Masukkan nomor makanan yang akan dibuat: ");
    scanf("%d", &x);
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
    while ((FIRST(treeList[lengthtree][0])) != NULL)
    {
        lengthtree++;
    }
    //     printf("ADFSAFDSAFDAS");
    //     printf("lengtree%d\n",lengthtree);

    for (int i = 0; i < lengthtree; i++)
    {
        if (listchop.F[x].id == INFO(NEXT(FIRST(treeList[i][0]))))
        {
            idx = i;
            // printf("cek cek%d\n",idx);
        }
    }
    // printf("%d\n",idx);
    int panjang = 0;
    while (FIRST(treeList[idx][panjang]) != NULL)
    {
        panjang++;
    }
    // printf("cek\n");
    // printf("PANJANG %d\n",panjang);

    boolean lengkap = true;

    for (int i = 0; i < panjang; i++)
    {
        // printf("%d\n", i);
        if (!isExist(*q, INFO(FIRST(treeList[idx][i]))))
        {
            lengkap = false;
        }
        else
        {
            // printf("ada\n");
        }
    }

    if (lengkap)
    {
        printf("Bahan lengkap\n");
        for (int i = 0; i < panjang; i++)
        {
            Food temp;
            dequeueAt(q, &temp, INFO(FIRST(treeList[idx][i])));
        }
        AddInventory(q, listchop.F[x]);
        printf("Bahan tersedia, ");
        displayWordFood(listchop.F[x].name);
        printf(" berhasil dibuat dan sudah masuk ke inventory!\n");
    }
    else
    {
        printf("Bahan tidak lengkap\n");
    }
    printf("\nTekan enter untuk kembali ke map\n");
    scanf("%d", &bin);
    return;
}