#include <stdio.h>
#include <stdlib.h>

#include "gameState.h"

// Update delivery state
Queue updateDeliveryTime(Queue *delivery, Queue *inventory, int day, int hour, int minute)
{
    Queue newDelivery;
    newDelivery = *delivery;
    address pointer = ADDR_HEAD(*delivery);
    for (int i = 0; i < length(*delivery); i++)
    {
        int subMinutes = (1440 * day) + (60 * hour) + minute;
        Time subTime = minuteToTime(subMinutes);

        Time oldTime = Info(pointer).deltime;
        int oldMinutes = timeToMinute(oldTime);

        if (oldMinutes <= subMinutes)
        {
            Food food;
            delDelivery(&newDelivery, &food);
            AddInventory(inventory, food);
        }
        else
        {
            // int newMinutes = oldMinutes - subMinutes;
            // Time newTime = minuteToTime(newMinutes);
            // Info(pointer).deltime = newTime;

            Food bin;
            address newFood = newnode(Info(pointer));
            dequeueAt(&newDelivery, &bin, Info(pointer).id);
            int newMinutes = oldMinutes - subMinutes;
            Time newTime = minuteToTime(newMinutes);
            Info(newFood).deltime = newTime;
            addDelivery(&newDelivery, Info(newFood));
        }

        pointer = Next(pointer);
    }

    return newDelivery;
}

// Add time
void addTime(GameState *gs, int day, int hour, int minute)
{
    // Update time state
    int minutes = timeToMinute((*gs).time);
    int addedMinutes = (1440 * day) + (60 * hour) + minute;
    int totalMinute = minutes + addedMinutes;
    (*gs).time = minuteToTime(totalMinute);

    // Update delivery state
    Queue newDeliveryState, newinventoryState;
    newDeliveryState = (*gs).delivery;
    newinventoryState = (*gs).inventory;
    (*gs).delivery = updateDeliveryTime(&newDeliveryState, &newinventoryState, day, hour, minute);
    (*gs).inventory = newinventoryState;
}

// Update map
void updateMap(GameState gs, MatrixChar *map)
{
    Point currentPos = gs.simPos;
    for (int i = 0; i < (*map).rowEff; i++)
    {
        for (int j = 0; j < (*map).colEff; j++)
        {
            if ((*map).buffer[i][j] == 'S')
            {
                (*map).buffer[i][j] = '#';
            }
        }
    }
    (*map).buffer[currentPos.Y + 1][currentPos.X + 1] = 'S';
}

// Update available action
void updateAvailableAction(GameState *gs, MatrixChar map)
{
    // isAbleBuy
    if ((map.buffer[(*gs).simPos.Y][(*gs).simPos.X + 1] == 'T') || (map.buffer[(*gs).simPos.Y + 1][(*gs).simPos.X + 2] == 'T') || (map.buffer[(*gs).simPos.Y + 2][(*gs).simPos.X + 1] == 'T') || (map.buffer[(*gs).simPos.Y + 1][(*gs).simPos.X] == 'T'))
    {
        (*gs).isAbleBuy = 1;
    }
    else
    {
        (*gs).isAbleBuy = 0;
    }

    // isAbleChop
    if ((map.buffer[(*gs).simPos.Y][(*gs).simPos.X + 1] == 'C') || (map.buffer[(*gs).simPos.Y + 1][(*gs).simPos.X + 2] == 'C') || (map.buffer[(*gs).simPos.Y + 2][(*gs).simPos.X + 1] == 'C') || (map.buffer[(*gs).simPos.Y + 1][(*gs).simPos.X] == 'C'))
    {
        (*gs).isAbleChop = 1;
    }
    else
    {
        (*gs).isAbleChop = 0;
    }

    // isAbleMix
    if ((map.buffer[(*gs).simPos.Y][(*gs).simPos.X + 1] == 'M') || (map.buffer[(*gs).simPos.Y + 1][(*gs).simPos.X + 2] == 'M') || (map.buffer[(*gs).simPos.Y + 2][(*gs).simPos.X + 1] == 'M') || (map.buffer[(*gs).simPos.Y + 1][(*gs).simPos.X] == 'M'))
    {
        (*gs).isAbleMix = 1;
    }
    else
    {
        (*gs).isAbleMix = 0;
    }

    // isAbleFry
    if ((map.buffer[(*gs).simPos.Y][(*gs).simPos.X + 1] == 'F') || (map.buffer[(*gs).simPos.Y + 1][(*gs).simPos.X + 2] == 'F') || (map.buffer[(*gs).simPos.Y + 2][(*gs).simPos.X + 1] == 'F') || (map.buffer[(*gs).simPos.Y + 1][(*gs).simPos.X] == 'F'))
    {
        (*gs).isAbleFry = 1;
    }
    else
    {
        (*gs).isAbleFry = 0;
    }

    // isAbleBoil
    if ((map.buffer[(*gs).simPos.Y][(*gs).simPos.X + 1] == 'B') || (map.buffer[(*gs).simPos.Y + 1][(*gs).simPos.X + 2] == 'B') || (map.buffer[(*gs).simPos.Y + 2][(*gs).simPos.X + 1] == 'B') || (map.buffer[(*gs).simPos.Y + 1][(*gs).simPos.X] == 'B'))
    {
        (*gs).isAbleBoil = 1;
    }
    else
    {
        (*gs).isAbleBoil = 0;
    }
}

// Display Delivery
void displayDelivery(GameState gs)
{
    Queue Q = gs.delivery;
    address p = ADDR_HEAD(Q);
    int n = length(Q);
    char bin;

    if (n == 0)
    {
        printf("==============================================================\n");
        printf("|                          DELIVERY                          |\n");
        printf("==============================================================\n");
        printf("|  Tidak ada pesanan\n");
        printf("|\n");
        printf("==============================================================\n");
        printf("\n");
    }
    else
    {
        int i = 1;

        printf("==============================================================\n");
        printf("|                          DELIVERY                          |\n");
        printf("==============================================================\n");
        printf("|  No. Nama ----- Waktu Delivery\n");
        printf("|\n");

        while (p != NULL)
        {
            printf("|  %d. ", i);
            displayWordFood(Info(p).name);
            printf(" ----- ");
            displayTime(Info(p).deltime);
            p = Next(p);
            if (p != NULL)
            {
                printf("\n");
            }
            i++;
        }

        printf("\n");
        printf("|\n");
        printf("==============================================================\n");
        printf("\n");
    }

    printf("Tekan enter menutup delivery\n");
    getchar();
}

// Display Inventory
void displayInventory(GameState gs)
{
    Queue Q = gs.inventory;
    address p = ADDR_HEAD(Q);
    char bin;
    int i = 1;

    if (length(Q) == 0)
    {
        printf("==============================================================\n");
        printf("|                         INVENTORY                          |\n");
        printf("==============================================================\n");
        printf("|  Inventory-mu masih kosong\n");
        printf("|\n");
        printf("==============================================================\n");
        printf("\n");
    }
    else
    {
        printf("==============================================================\n");
        printf("|                         INVENTORY                          |\n");
        printf("==============================================================\n");
        printf("|  No. Nama ----- Waktu Kadaluarsa\n");
        printf("|\n");

        while (p != NULL)
        {
            printf("|  %d. ", i);
            displayWordFood(Info(p).name);
            printf(" ----- ");
            displayTime(Info(p).exptime);
            p = Next(p);
            if (p != NULL)
            {
                printf("\n");
            }
            i++;
        }
        printf("\n");
        printf("|\n");
        printf("==============================================================\n");
        printf("\n");
    }

    printf("Tekan enter menutup inventory\n");
    getchar();
}