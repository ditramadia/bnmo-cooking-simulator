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

// Move north
void moveNorth(StackState *stateHistory, GameState *gs, MatrixChar *map, int *nMove);

// Move east
void moveEast(StackState *stateHistory, GameState *gs, MatrixChar *map, int *nMove);

// Move south
void moveSouth(StackState *stateHistory, GameState *gs, MatrixChar *map, int *nMove);

// Move west
void moveWest(StackState *stateHistory, GameState *gs, MatrixChar *map, int *nMove);

// Undo
void undoState(StackState *stackState, GameState *currentGameState, MatrixChar *map);

// Redo
void redoState(StackState *stackState, GameState *currentGameState, MatrixChar *map);

// Wait
int getWaitHour(char command[]);

int getWaitHour(char command[]);

void waitTime(StackState *stateHistory, GameState *currentGameState, int hour, int minute);

#endif