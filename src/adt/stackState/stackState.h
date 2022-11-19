#include "../gameState/gameState.h"
#include "../arrayChar/arrayChar.c"
#include "../notifikasi/notifikasi.h"

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
void undoState(StackState *stackState, GameState *currentGameState, MatrixChar *map, Queue *delivery, Queue *inventory);

// Redo
void redoState(StackState *stackState, GameState *currentGameState, MatrixChar *map, Queue *delivery, Queue *inventory);

// Move north
void moveNorth(StackState *stateHistory, GameState *gs, MatrixChar *map, Queue *delivery, Queue *inventory, int *nMove, Notiflist *nL);

// Move east
void moveEast(StackState *stateHistory, GameState *gs, MatrixChar *map, Queue *delivery, Queue *inventory, int *nMove, Notiflist *nL);

// Move south
void moveSouth(StackState *stateHistory, GameState *gs, MatrixChar *map, Queue *delivery, Queue *inventory, int *nMove, Notiflist *nL);

// Move west
void moveWest(StackState *stateHistory, GameState *gs, MatrixChar *map, Queue *delivery, Queue *inventory, int *nMove, Notiflist *nL);

// Update delivery
void updateDeliveryState(GameState *currentGameState, Queue delivery);

// Update inventory
void updateInventoryState(GameState *currentGameState, Queue inventory);

// Get Wait Hour
int getWaitHour(char command[]);

// Get Wait Hour
int getWaitMinute(char command[]);

// Wait
void waitTime(StackState *stateHistory, GameState *gs, Queue *delivery, Queue *inventory, int hour, int minute, Notiflist *Nl);

#endif