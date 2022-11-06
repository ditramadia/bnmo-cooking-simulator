#include "../gameState/gameState.h"

#ifndef STACKSTATE_H
#define STACKSTATE_H

// Definition
#define CAPACITY 3

// Declaration
typedef struct
{
    GameState buffer[CAPACITY];
    int idxEff;
    int currentStateId;
} StackState;

// State
extern StackState stateHistory;

// Constructor
void createStackState(StackState *stackState);

// isEmpty
int isStackStateFull(StackState StackState);

// Insert
void insertState(StackState *stackState, GameState currentGameState);

// Undo
void undoState(StackState *stackState, GameState *currentGameState, MatrixChar *map);

// Redo
void redoState(StackState *stackState, GameState *currentGameState, MatrixChar *map);

// Move north
void moveNorth(StackState *stateHistory, GameState *gs, MatrixChar *map);

// Move east
void moveEast(StackState *stateHistory, GameState *gs, MatrixChar *map);

// Move south
void moveSouth(StackState *stateHistory, GameState *gs, MatrixChar *map);

// Move west
void moveWest(StackState *stateHistory, GameState *gs, MatrixChar *map);

#endif