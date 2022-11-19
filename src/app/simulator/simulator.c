#include <stdio.h>

// Global State
char simName[20];
MatrixChar map;
// CurrentGameState
Time cgstime;

int simulator()
{
    // Display CGS Time
    printf("Waktu: ");
    displayTime(cgstime);
    printf("\n");

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

    // Load Current Game State (cgs)
    createTime(&cgstime, 0, 5, 0);

    // Proceed to simulator
    simulator();
}
