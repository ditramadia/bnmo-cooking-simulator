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
// #include "../chop/chop.c"
#include "../fry/fry.c"
#include "../../adt/food/food.c"


// Global State
MatrixChar map;
GameState currentGameState;
StackState stateHistory;
Foodlist listFood, listFry;
Queue inventory;
int nMove;
int foodListLen;

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
    char chopCommand[] = "CHOP";
    char mixCommand[] = "MIX";
    char boilCommand[] = "BOIL";
    char fryCommand[] = "FRY";
    char exitCommand[] = "EXIT";
    char invenCommand[] = "INVENTORY";

    char simCommand[50];
    printf("%s: ", query);
    fflush(stdin);
    fgets(simCommand, 50, stdin);

    if (compareString(simCommand, moveNCommand))
    {
        // Move north
        system("cls");
        moveNorth(&stateHistory, &currentGameState, &map, &nMove);
        simulator();
    }
    else if (compareString(simCommand, moveECommand))
    {
        // Move east
        system("cls");
        moveEast(&stateHistory, &currentGameState, &map, &nMove);
        simulator();
    }
    else if (compareString(simCommand, moveSCommand))
    {
        // Move south
        system("cls");
        moveSouth(&stateHistory, &currentGameState, &map, &nMove);
        simulator();
    }
    else if (compareString(simCommand, moveWCommand))
    {
        // Move west
        system("cls");
        moveWest(&stateHistory, &currentGameState, &map, &nMove);
        simulator();
    }
    else if (compareString(simCommand, undoCommand))
    {
        // Undo
        system("cls");
        undoState(&stateHistory, &currentGameState, &map);
        simulator();
    }
    else if (compareString(simCommand, redoCommand))
    {
        // Redo
        system("cls");
        redoState(&stateHistory, &currentGameState, &map);
        simulator();
    }
    else if (containFirstWordString(simCommand, waitCommand))
    {
        // Wait
        system("cls");
        waitTime(&stateHistory, &currentGameState, getWaitHour(simCommand), getWaitMinute(simCommand));
        simulator();
    }
    else if (compareString(simCommand, buyCommand))
    {
        // Call buy app
        system("cls");
        if (currentGameState.isAbleBuy)
        {
            printf("Call Buy Function.\n");
            system("cls");
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
    else if (compareString(simCommand, chopCommand))
    {
        // Call chop app
        system("cls");
        if (currentGameState.isAbleChop)
        {
            // chop();
            system("cls");
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
        system("cls");
        if (currentGameState.isAbleMix)
        {
            printf("Call Mix Function.\n");
            system("cls");
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
        system("cls");
        if (currentGameState.isAbleBoil)
        {
            printf("Call Boil Function.\n");
            system("cls");
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
        // Call chop app
        system("cls");
        if (currentGameState.isAbleFry)
        {
            fry(listFood,inventory,foodListLen, listFry);
            system("cls");
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
    // else if (compareString(simCommand, invenCommand))
    // {
        
    //     exit(0);
    // }
    else
    {
        system("cls");
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
    addList(&listFood, foodListLen);
    Createinventory(&inventory);
    listfry(&listFry,listFood,foodListLen);

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