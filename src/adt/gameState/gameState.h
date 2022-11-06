#include "../point/point.h"
#include "../matrixChar/matrixChar.h"

#ifndef GAMESTATE_H
#define GAMESTATE_H

// Definition

// Declaration
typedef struct
{
    Point simPos;
} GameState;

// Find simPos
Point setSimPos(MatrixChar map);

// Constructor
void setGameState(GameState *gs, MatrixChar map);

// Display
void renderGameState(GameState gs);

// Move north
void moveNorth(GameState *gs, MatrixChar *map);

#endif