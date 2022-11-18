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
#include "../buy/buy.c"
#include "../chop/chop.c"
#include "../fry/fry.c"
#include "../../adt/food/food.c"
#include "../../adt/tree/tree.c"


// Global State
MatrixChar map;
GameState currentGameState;
StackState stateHistory;
Foodlist listFood, listShop, listFry, listChop;
Queue inventory;
Queue delivery;
List treeList[100][100];
int nMove;
int treeLength;

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
        moveNorth(&stateHistory, &currentGameState, &map, &nMove);
        simulator();
    }
    else if (compareString(simCommand, moveECommand))
    {
        // Move east
        system(CLEAR);
        moveEast(&stateHistory, &currentGameState, &map, &nMove);
        simulator();
    }
    else if (compareString(simCommand, moveSCommand))
    {
        // Move south
        system(CLEAR);
        moveSouth(&stateHistory, &currentGameState, &map, &nMove);
        simulator();
    }
    else if (compareString(simCommand, moveWCommand))
    {
        // Move west
        system(CLEAR);
        moveWest(&stateHistory, &currentGameState, &map, &nMove);
        simulator();
    }
    else if (compareString(simCommand, undoCommand))
    {
        // Undo
        system(CLEAR);
        undoState(&stateHistory, &currentGameState, &map);
        simulator();
    }
    else if (compareString(simCommand, redoCommand))
    {
        // Redo
        system(CLEAR);
        redoState(&stateHistory, &currentGameState, &map);
        simulator();
    }
    else if (containFirstWordString(simCommand, waitCommand))
    {
        // Wait
        system(CLEAR);
        waitTime(&stateHistory, &currentGameState, getWaitHour(simCommand), getWaitMinute(simCommand));
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
    else if (compareString(simCommand, deliveryCommand))
    {
        // Call delivery App
        system(CLEAR);
        displayDelivery(delivery);
        simulator();
    }
    else if (compareString(simCommand, invenCommand))
    {
        // Call Inventory App
        system(CLEAR);
        DisplayInventory(inventory);
        simulator();
    }
    else if (compareString(simCommand, chopCommand))
    {
        // Call chop app
        system(CLEAR);
        if (currentGameState.isAbleChop)
        {
            chop(listFood, &inventory, listChop, treeList, treeLength);
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
            printf("Call Mix Function.\n");
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
            // buy(delivery, listShop);
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
            fry(listFood, &inventory, listFry, treeList, treeLength);
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

    // Set up gameState
    setGameState(&currentGameState, map);
    createStackState(&stateHistory);
    insertState(&stateHistory, currentGameState);
    nMove = 0;
    createTree(treeList);
    makeTree(treeList,treeLength);

    // Load delivery
    addList(&listFood);
    Createinventory(&inventory);
    CreateQueue(&delivery);
    listshop(&listShop, listFood);
    listfry(&listFry, listFood);
    listchop(&listChop, listFood);

    AddInventory(&inventory,listFood.F[4]);
    AddInventory(&inventory,listFood.F[5]);
    AddInventory(&inventory,listFood.F[1]);

    // Simulator
    renderGameState(currentGameState);
    renderMap(map);
    simulatorCommandParser("Masukkan perintah");

    return 0;
}

int simulator()
{
    renderGameState(currentGameState);
    renderMap(map);

    simulatorCommandParser("Masukkan perintah");

    return 0;
}