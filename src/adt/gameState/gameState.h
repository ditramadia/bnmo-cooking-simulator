#include "../point/point.h"
#include "../matrixChar/matrixChar.h"

#ifndef GAMESTATE_H
#define GAMESTATE_H

// Declaration
typedef struct
{
    Point simPos;
    char *notification;
} GameState;

// State
extern GameState currentGameState;

// Find simPos
Point setSimPos(MatrixChar map);

// Constructor
void setGameState(GameState *gs, MatrixChar map);

// Display
void renderGameState(GameState gs);

// Update map
void updateMap(GameState gs, MatrixChar *map);

#endif