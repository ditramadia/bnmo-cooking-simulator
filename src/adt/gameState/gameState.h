#include "../point/point.h"
#include "../simPos/simPos.h"
#include "../matrixChar/matrixChar.h"
#include "../time/time.h"

#ifndef GAMESTATE_H
#define GAMESTATE_H

// Declaration
typedef struct
{
    Point simPos;
    Time time;
    int isAbleBuy;
    int isAbleMix;
    int isAbleChop;
    int isAbleFry;
    int isAbleBoil;
} GameState;

// State
extern GameState currentGameState;

// Update map
void updateMap(GameState gs, MatrixChar *map);

// Update available action
void updateAvailableAction(GameState *gs, MatrixChar map);

#endif