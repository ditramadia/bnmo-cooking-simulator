#include <stdio.h>
#include "stackState.h"

void createStackState(StackState *stackState)
{
    (*stackState).idxEff = -1;
    (*stackState).currentStateId = -1;
}

int isStackStateFull(StackState stackState)
{
    return stackState.idxEff == CAPACITY - 1;
}

void insertState(StackState *stackState, GameState currentGameState)
{
    if (!isStackStateFull(*stackState))
    {
        (*stackState).currentStateId++;
        (*stackState).buffer[(*stackState).currentStateId] = currentGameState;
        (*stackState).idxEff = (*stackState).currentStateId;
    }
    else
    {
        for (int i = 0; i < CAPACITY - 1; i++)
        {
            (*stackState).buffer[i] = (*stackState).buffer[i + 1];
        }
        (*stackState).buffer[CAPACITY - 1] = currentGameState;
    }
}

// Undo
void undoState(StackState *stackState, GameState *currentGameState, MatrixChar *map)
{
    if ((*stackState).currentStateId > 0)
    {
        // Undo Game State
        (*stackState).currentStateId--;
        *currentGameState = (*stackState).buffer[(*stackState).currentStateId];

        // Update Map
        updateMap(*currentGameState, map);
    }
}

// Redo
void redoState(StackState *stackState, GameState *currentGameState, MatrixChar *map)
{
    if ((*stackState).currentStateId != (*stackState).idxEff)
    {
        // Redo Game State
        (*stackState).currentStateId++;
        *currentGameState = (*stackState).buffer[(*stackState).currentStateId];

        // Update Map
        updateMap(*currentGameState, map);
    }
}