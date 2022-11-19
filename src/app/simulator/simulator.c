#include <stdio.h>

// Global State
char simName[20];
MatrixChar map;

int loadSimulator()
{
    // Load simName
    fflush(stdin);
    printf("Masukkan nama Anda: ");
    scanf("%s", &simName);
    system(CLEAR);

    // Load Map
    // loadMap(&map);
}