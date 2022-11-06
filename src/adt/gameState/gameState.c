#include <stdio.h>

#include "gameState.h"
#include "../point/point.c"

// Find sPos
Point setSimPos(MatrixChar map)
{
    Point simPos;
    for (int i = 0; i < map.rowEff; i++)
    {
        for (int j = 0; j < map.colEff; j++)
        {
            if (map.buffer[i][j] == 'S')
            {
                createPoint(&simPos, j - 1, i - 1);
                return simPos;
            }
        }
    }
}

// Constructor
void setGameState(GameState *gs, MatrixChar map)
{
    // Set sPos
    (*gs).simPos = setSimPos(map);
    // Set notification
}

// Display
void renderGameState(GameState gs)
{
    printf("DINNER DASH\n");
    printf("\n");
    printf("Posisi Anda: (%d,%d)\n", gs.simPos.X, gs.simPos.Y);
    printf("Waktu: \n");
    printf("Notifikasi: -\n");
    printf("\n");
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
