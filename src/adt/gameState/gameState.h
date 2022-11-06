#include "../point/point.h"
#include "../matrixChar/matrixChar.h"
#include "../time/time.h"

#ifndef GAMESTATE_H
#define GAMESTATE_H

// Declaration
typedef struct
{
    Point simPos;
    Time time;
} GameState;

// State
extern GameState currentGameState;

// Find simPos
Point setSimPos(MatrixChar map);

// Set time
Time setTime(int hour, int minute);

// Constructor
void setGameState(GameState *gs, MatrixChar map);

// Display
void renderGameState(GameState gs);

// Update map
void updateMap(GameState gs, MatrixChar *map);

// Update time
void updateTime(GameState *gs, int hour, int minute);

#endif