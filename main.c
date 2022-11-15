#include <stdio.h>

#include "./src/app/Inisiasi/splashScreen.c"
#include "./src/adt/food/food.c"
#include "./src/adt/inventory/inventory.c"

Foodlist F;
PrioQueueTime Inventory;


int main()
{
    addList(&F);
    Createinventory(&Inventory);

    mainMenu();

    return 0;
}