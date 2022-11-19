#include <stdio.h>

#include "../../adt/string/string.c"
#include "../../adt/time/time.c"
#include "../../adt/gameState/gameState.c"
#include "../../adt/stackState/stackState.c"
#include "../../adt/map/map.c"
#include "../../adt/inventory/inventory.c"
#include "../../adt/point/point.c"
#include "../../adt/wordmachinefood/wordmachine.c"
#include "../../adt/matrixChar/matrixChar.c"
#include "../../adt/queuelinked/queuelinked.c"
#include "../../adt/wordmachineresep/wordmachine.c"
#include "../../adt/notifikasi/notifikasi.c"
#include "../catalog/catalog.c"
// #include "../cookbook/cookbook.c"
#include "../buy/buy.c"
#include "../chop/chop.c"
#include "../fry/fry.c"
#include "../boil/boil.c"
#include "../mix/mix.c"
#include "../../adt/food/food.c"
#include "../../adt/tree/tree.c"

// Global State
MatrixChar map;
GameState currentGameState;
StackState stateHistory;
Foodlist listFood, listShop, listFry, listChop, listBoil, listMix;
Queue inventory;
Queue delivery;
List treeList[100][100];
Notiflist Nl;
int nMove;

// Command Parser
void simulatorCommandParser(char query[])
{
    // Available commands
    char moveNCommand[] = "MOVE NORTH";
    char moveECommand[] = "MOVE EAST";
    char moveSCommand[] = "MOVE SOUTH";
    char moveWCommand[] = "MOVE WEST";
    char undoCommand[] = "UNDO";
    char redoCommand[] = "REDO";
    char waitCommand[] = "WAIT";
    char buyCommand[] = "BUY";
    char catalogCommand[] = "CATALOG";
    // char cookbookCommand[] = "COOKBOOK";
    char deliveryCommand[] = "DELIVERY";
    char invenCommand[] = "INVENTORY";
    char chopCommand[] = "CHOP";
    char mixCommand[] = "MIX";
    char boilCommand[] = "BOIL";
    char fryCommand[] = "FRY";
    char exitCommand[] = "EXIT";

    char simCommand[50];
    printf("%s: ", query);
    fflush(stdin);
    fgets(simCommand, 50, stdin);

    if (compareString(simCommand, moveNCommand))
    {
        // Move north
        system(CLEAR);
        moveNorth(&stateHistory, &currentGameState, &map, &delivery, &inventory, &nMove, &Nl);

        simulator();
    }
    else if (compareString(simCommand, moveECommand))
    {
        // Move east
        system(CLEAR);
        moveEast(&stateHistory, &currentGameState, &map, &delivery, &inventory, &nMove, &Nl);
        simulator();
    }
    else if (compareString(simCommand, moveSCommand))
    {
        // Move south
        system(CLEAR);
        moveSouth(&stateHistory, &currentGameState, &map, &delivery, &inventory, &nMove, &Nl);
        simulator();
    }
    else if (compareString(simCommand, moveWCommand))
    {
        // Move west
        system(CLEAR);
        moveWest(&stateHistory, &currentGameState, &map, &delivery, &inventory, &nMove, &Nl);
        simulator();
    }
    else if (compareString(simCommand, undoCommand))
    {
        // Undo
        system(CLEAR);
        undoState(&stateHistory, &currentGameState, &map, &delivery, &inventory);
        simulator();
    }
    else if (compareString(simCommand, redoCommand))
    {
        // Redo
        system(CLEAR);
        redoState(&stateHistory, &currentGameState, &map, &delivery, &inventory);
        simulator();
    }
    else if (containFirstWordString(simCommand, waitCommand))
    {
        // Wait
        system(CLEAR);
        waitTime(&stateHistory, &currentGameState, &delivery, &inventory, getWaitHour(simCommand), getWaitMinute(simCommand), &Nl);
        simulator();
    }
    else if (compareString(simCommand, buyCommand))
    {
        // Call buy app
        system(CLEAR);
        if (currentGameState.isAbleBuy)
        {
            // buy(delivery, listShop);
            buy(&delivery, listShop);
            system(CLEAR);
            simulator();
        }
        else
        {
            printf("==============================================================\n");
            printf("|    Anda harus berada di lokasi 'T' untuk melakukan BUY.    |\n");
            printf("==============================================================\n");
            simulator();
        }
    }
    else if (compareString(simCommand, catalogCommand))
    {
        // Call Catalog App
        system(CLEAR);
        catalog(listFood);
        system(CLEAR);
        simulator();
    }
    // else if (compareString(simCommand, cookbookCommand))
    // {
    //     // Call Cookbook App
    //     system(CLEAR);
    //     cookbook(listFood);
    //     system(CLEAR);
    //     simulator();
    // }
    else if (compareString(simCommand, deliveryCommand))
    {
        // Call delivery App
        system(CLEAR);
        displayDelivery(delivery);
        system(CLEAR);
        simulator();
    }
    else if (compareString(simCommand, invenCommand))
    {
        // Call Inventory App
        system(CLEAR);
        DisplayInventory(inventory);
        system(CLEAR);
        simulator();
    }
    else if (compareString(simCommand, chopCommand))
    {
        // Call chop app
        system(CLEAR);
        if (currentGameState.isAbleChop)
        {
            chop(listFood, &inventory, listChop, treeList);
            system(CLEAR);
            simulator();
        }
        else
        {
            printf("==============================================================\n");
            printf("|    Anda harus berada di lokasi 'C' untuk melakukan CHOP.   |\n");
            printf("==============================================================\n");
            simulator();
        }
    }
    else if (compareString(simCommand, mixCommand))
    {
        // Call mix app
        system(CLEAR);
        if (currentGameState.isAbleMix)
        {
            // printf("Call Mix Function.\n");
            mix(listFood, &inventory, listMix, treeList);
            system(CLEAR);
            simulator();
        }
        else
        {
            printf("==============================================================\n");
            printf("|    Anda harus berada di lokasi 'M' untuk melakukan MIX.    |\n");
            printf("==============================================================\n");
            simulator();
        }
    }
    else if (compareString(simCommand, boilCommand))
    {
        // Call boil app
        system(CLEAR);
        if (currentGameState.isAbleBoil)
        {
            boil(listFood, &inventory, listBoil, treeList);
            system(CLEAR);
            simulator();
        }
        else
        {
            printf("==============================================================\n");
            printf("|    Anda harus berada di lokasi 'B' untuk melakukan BOIL.   |\n");
            printf("==============================================================\n");
            simulator();
        }
    }
    else if (compareString(simCommand, fryCommand))
    {
        // Call fry app
        system(CLEAR);
        if (currentGameState.isAbleFry)
        {
            fry(listFood, &inventory, listFry, treeList);
            system(CLEAR);
            simulator();
        }
        else
        {
            printf("==============================================================\n");
            printf("|    Anda harus berada di lokasi 'F' untuk melakukan FRY.    |\n");
            printf("==============================================================\n");
            simulator();
        }
    }
    else if (compareString(simCommand, exitCommand))
    {
        // Call exit app
        exit(0);
    }
    else
    {
        system(CLEAR);
        printf("==============================================================\n");
        printf("|                   Perintah tidak tersedia                  |\n");
        printf("==============================================================\n");
        simulator();
    }
}

int loadSimulator()
{
    // Load Map
    setMap(&map);

    // Load Foods
    addList(&listFood);
    listshop(&listShop, listFood);
    listfry(&listFry, listFood);
    listchop(&listChop, listFood);
    listboil(&listBoil, listFood);
    listmix(&listMix, listFood);
    createTree(treeList);
    makeTree(treeList);

    // Load inventory
    Createinventory(&inventory);

    // Load delivery
    CreateQueue(&delivery);

    // Test
    AddInventory(&inventory, listFood.F[4]);
    AddInventory(&inventory, listFood.F[5]);
    AddInventory(&inventory, listFood.F[1]);
    AddInventory(&inventory, listFood.F[2]);
    AddInventory(&inventory, listFood.F[3]);
    AddInventory(&inventory, listFood.F[6]);

    // Set up gameState
    setGameState(&currentGameState, map, inventory, delivery);
    createStackState(&stateHistory);
    insertState(&stateHistory, currentGameState);
    nMove = 0;

    // Simulator
    renderGameState(currentGameState, Nl);
    renderMap(map);
    simulatorCommandParser("Masukkan perintah");

    return 0;
}

int simulator()
{
    renderGameState(currentGameState, Nl);
    renderMap(map);

    simulatorCommandParser("Masukkan perintah");

    return 0;
}