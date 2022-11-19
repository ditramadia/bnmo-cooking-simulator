#include "../gameState/gameState.h"

#ifndef STACKSTATE_H
#define STACKSTATE_H

// Definition
#define CAPACITY 10

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

#endif