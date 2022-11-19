#include <stdio.h>

// Global State
char simName[20];
MatrixChar map;
StackState stateHistory;
GameState currentGameState;
Time cgsTime;
Point cgsSimPos;

int simulator()
{
    // Update Current Game State
    currentGameState = stateHistory.buffer[stateHistory.currentStateId];

    // Display CGS Time
    printf("Waktu: ");
    displayTime(currentGameState.time);
    printf("\n");

    // Display SimPos
    printf("Posisi %s: (%d, %d)\n", simName, currentGameState.simPos.X, currentGameState.simPos.Y);

    // Display Map
    renderMap(map);
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
