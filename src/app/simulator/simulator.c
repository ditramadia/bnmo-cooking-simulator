#include <stdio.h>

// Global State
char simName[20];
MatrixChar map;
Foodlist listFood, listShop, listFry, listChop, listBoil, listMix;

// Game State
StackState stateHistory;
GameState currentGameState;
Time cgsTime;
Point cgsSimPos;
int nMove;

// Command Parser
void simulatorCommandParser(char query[])
{
    // Available commands
    // 1. Movement
    char moveNCommand[] = "MOVE NORTH";
    char moveECommand[] = "MOVE EAST";
    char moveSCommand[] = "MOVE SOUTH";
    char moveWCommand[] = "MOVE WEST";
    char buyCommand[] = "BUY";
    // N. Exit
    char exitCommand[] = "EXIT";

    char simCommand[50];
    printf("%s: ", query);
    fflush(stdin);
    fgets(simCommand, 50, stdin);

    // MOVE NORTH
    if (compareString(simCommand, moveNCommand))
    {
        system(CLEAR);
        moveNorth(&stateHistory, &currentGameState, &map, &nMove);

        simulator();
    }
    // MOVE EAST
    else if (compareString(simCommand, moveECommand))
    {
        system(CLEAR);
        moveEast(&stateHistory, &currentGameState, &map, &nMove);
        simulator();
    }
    // MOVE SOUTH
    else if (compareString(simCommand, moveSCommand))
    {
        system(CLEAR);
        moveSouth(&stateHistory, &currentGameState, &map, &nMove);
        simulator();
    }
    // MOVE WEST
    else if (compareString(simCommand, moveWCommand))
    {
        system(CLEAR);
        moveWest(&stateHistory, &currentGameState, &map, &nMove);
        simulator();
    }
    // BUY
    else if (compareString(simCommand, buyCommand))
    {
        system(CLEAR);
        buy(listShop);
        simulator();
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

int simulator()
{
    // Update Current Game State
    currentGameState = stateHistory.buffer[stateHistory.currentStateId];

    // Display SimPos
    printf("Posisi %s: (%d, %d)\n", simName, currentGameState.simPos.X, currentGameState.simPos.Y);

    // Display CGS Time
    printf("Waktu: ");
    displayTime(currentGameState.time);
    printf("\n");

    // Display Map
    updateMap(currentGameState, &map);
    renderMap(map);

    // Ask for input
    simulatorCommandParser("Masukkan perintah");
}

int loadSimulator()
{
    // Load simName
    fflush(stdin);
    printf("Masukkan nama Anda: ");
    scanf("%s", &simName);
    system(CLEAR);

    // Load Map
    loadMap(&map);

    // Load Simulator Position
    cgsSimPos = loadSimPos(map);

    // Load nMove
    nMove = 0;

    // Load Foods
    addList(&listFood);
    listshop(&listShop, listFood);

    // Load Current Game State (cgs)
    createTime(&cgsTime, 0, 5, 0);

    // Load Game State
    currentGameState.simPos = cgsSimPos;
    currentGameState.time = cgsTime;
    updateAvailableAction(&currentGameState, map);

    // Load State History
    insertState(&stateHistory, currentGameState);

    // Proceed to simulator
    simulator();
}
