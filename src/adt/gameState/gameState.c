#include <stdio.h>
#include <stdlib.h>

#include "gameState.h"
#include "../point/point.c"
#include "../time/time.c"

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

// Set time
Time setTime(int hour, int minute)
{
    Time retTime;
    createTime(&retTime, hour, minute);
    return retTime;
}

// Constructor
void setGameState(GameState *gs, MatrixChar map)
{
    // Set sPos
    (*gs).simPos = setSimPos(map);
    // Set time
    (*gs).time = setTime(5, 0);
}

// Display
void renderGameState(GameState gs)
{
    printf("BNMO Cooking Simulator\n");
    printf("\n");

    printf("Posisi Anda: (%d,%d)\n", gs.simPos.X, gs.simPos.Y);

    printf("Waktu: ");
    displayTime(gs.time);
    printf("\n");

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

// Update time
void updateTime(GameState *gs, int hour, int minute)
{
    int minutes = timeToMinute((*gs).time);
    int addedMinutes = (60 * hour) + minute;
    int totalMinute = minutes + addedMinutes;
    (*gs).time = minuteToTime(totalMinute);
}
