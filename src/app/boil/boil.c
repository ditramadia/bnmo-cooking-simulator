#include <stdio.h>
#include <stdlib.h>

void boil(StackState *stateHistory, GameState *currentGameState, Foodlist l, Foodlist listBoil, List treeList[100][100])
{
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
    for (int i = 1; i <= n; i++)
    {
        printf("|  %d. ", i);
        displayWordFood(listBoil.F[i].name);
        printf("\n");
    }
    printf("|\n");
    printf("==============================================================\n");
    // int a = 0;
    int x;
    printf("Masukkan nomor barang yang ingin dibuat: ");
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
        if (listBoil.F[x].id == INFO(NEXT(FIRST(treeList[i][0]))))
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

    int lengkap = 1;

    Queue newInventory;
    newInventory = (*currentGameState).inventory;

    for (int i = 0; i < panjang; i++)
    {
        // printf("%d\n",i);
        if (!isExist(newInventory, INFO(FIRST(treeList[idx][i]))))
        {
            lengkap = 0;
        }
        else
        {
            // printf("ada\n");
        }
    }

    if (lengkap)
    {
        // printf("Bahan lengkap\n");
        for (int i = 0; i < panjang; i++)
        {
            Food temp;
            dequeueAt(&newInventory, &temp, INFO(FIRST(treeList[idx][i])));
        }
        addTime(currentGameState, 0, 0, 1);
        AddInventory(&newInventory, listBoil.F[x]);

        (*currentGameState).inventory = newInventory;
        insertState(stateHistory, *currentGameState);

        system(CLEAR);
        printf("==============================================================\n");
        printf("|                  Makanan berhasil dibuat!                  |\n");
        printf("==============================================================\n");
        printf("\n");

        return;
    }
    else
    {
        system(CLEAR);
        printf("==============================================================\n");
        printf("|                    Bahan tidak lengkap!                    |\n");
        printf("==============================================================\n");
        printf("\n");
    }
}