#include <stdio.h>
#include <stdlib.h>
#include "../../adt/food/food.h"
#include "../../adt/tree/tree.h"
#include "../../adt/queuelinked/queuelinked.h"

void chop(StackState *stateHistory, GameState *currentGameState, Foodlist l, Foodlist listchop, List treeList[100][100])
{
    char bin;
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
    int lengthtree = 0;
    while ((FIRST(treeList[lengthtree][0])) != NULL)
    {
        lengthtree++;
    }

    for (int i = 0; i < lengthtree; i++)
    {
        if (listchop.F[x].id == INFO(NEXT(FIRST(treeList[i][0]))))
        {
            idx = i;
        }
    }
    int panjang = 0;
    while (FIRST(treeList[idx][panjang]) != NULL)
    {
        panjang++;
    }

    int lengkap = 1;

    Queue newInventory;
    newInventory = (*currentGameState).inventory;

    for (int i = 0; i < panjang; i++)
    {
        if (!isExist(newInventory, INFO(FIRST(treeList[idx][i]))))
        {
            lengkap = 0;
        }
        else
        {
        }
    }

    if (lengkap)
    {
        printf("Bahan lengkap\n");
        for (int i = 0; i < panjang; i++)
        {
            Food temp;
            dequeueAt(&newInventory, &temp, INFO(FIRST(treeList[idx][i])));
        }
        addTime(currentGameState, 0, 0, 1);
        AddInventory(&newInventory, listchop.F[x]);

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