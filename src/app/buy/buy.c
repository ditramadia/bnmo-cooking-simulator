#include <stdio.h>

void buy(StackState *stateHistory, GameState *currentGameState, Foodlist listshop)
{
    // Display buy menu
    int n = listlength(listshop);
    printf("==============================================================\n");
    printf("|                       GRIYA CILEGON                        |\n");
    printf("==============================================================\n");
    printf("|  No. Nama ----- Waktu Kadaluarsa ----- Waktu Delivery\n");
    printf("|\n");
    printf("|  0. Batal\n");
    for (int i = 1; i <= n; i++)
    {
        printf("|  %d. ", i);
        displayWordFood(listshop.F[i].name);
        printf(" ----- ");
        displayTime(listshop.F[i].exptime);
        printf(" ----- ");
        displayTime(listshop.F[i].deltime);
        printf("\n");
    }
    printf("|\n");
    printf("==============================================================\n");

    // Choose Menu
    int selected;
    printf("\n");
    printf("Masukkan nomor makanan yang ingin dibeli: ");

    scanf("%d", &selected);
    fflush(stdin);
    if (selected == 0)
    {
        system(CLEAR);
        return;
    }
    while (selected > n || selected < 0)
    {
        printf("Nomor barang tidak valid. Masukkan nomor barang yang ingin dibeli: ");
        scanf("%d", &selected);
        if (selected == 0)
        {
            system(CLEAR);
            return;
        }
    }

    // Add to Delivery
    Queue newDeliveryState;
    newDeliveryState = (*currentGameState).delivery;
    addDelivery(&newDeliveryState, listshop.F[selected]);

    // Update state
    (*currentGameState).delivery = newDeliveryState;
    insertState(stateHistory, *currentGameState);

    system(CLEAR);
    printf("==============================================================\n");
    printf("|                 Makanan berhasil dipesan!                  |\n");
    printf("==============================================================\n");
    printf("\n");
}