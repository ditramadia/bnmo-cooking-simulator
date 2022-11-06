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

// Move North
void moveNorth(StackState *stateHistory, GameState *gs, MatrixChar *map)
{
    Point currentPos, nextPos;
    createPoint(&currentPos, (*gs).simPos.X, (*gs).simPos.Y);
    createPoint(&nextPos, (*gs).simPos.X, (*gs).simPos.Y - 1);

    if ((*map).buffer[nextPos.Y + 1][nextPos.X + 1] == '#')
    {
        // Update map
        (*map).buffer[nextPos.Y + 1][nextPos.X + 1] = 'S';
        (*map).buffer[currentPos.Y + 1][currentPos.X + 1] = '#';

        // Update game state
        (*gs).simPos.X = nextPos.X;
        (*gs).simPos.Y = nextPos.Y;

        // Insert new state to history
        insertState(stateHistory, *gs);
    }
}

// Move East
void moveEast(StackState *stateHistory, GameState *gs, MatrixChar *map)
{
    Point currentPos, nextPos;
    createPoint(&currentPos, (*gs).simPos.X, (*gs).simPos.Y);
    createPoint(&nextPos, (*gs).simPos.X + 1, (*gs).simPos.Y);

    if ((*map).buffer[nextPos.Y + 1][nextPos.X + 1] == '#')
    {
        // Update map
        (*map).buffer[nextPos.Y + 1][nextPos.X + 1] = 'S';
        (*map).buffer[currentPos.Y + 1][currentPos.X + 1] = '#';

        // Update game state
        (*gs).simPos.X = nextPos.X;
        (*gs).simPos.Y = nextPos.Y;

        // Insert new state to history
        insertState(stateHistory, *gs);
    }
}

// Move South
void moveSouth(StackState *stateHistory, GameState *gs, MatrixChar *map)
{
    Point currentPos, nextPos;
    createPoint(&currentPos, (*gs).simPos.X, (*gs).simPos.Y);
    createPoint(&nextPos, (*gs).simPos.X, (*gs).simPos.Y + 1);

    if ((*map).buffer[nextPos.Y + 1][nextPos.X + 1] == '#')
    {
        // Update map
        (*map).buffer[nextPos.Y + 1][nextPos.X + 1] = 'S';
        (*map).buffer[currentPos.Y + 1][currentPos.X + 1] = '#';

        // Update game state
        (*gs).simPos.X = nextPos.X;
        (*gs).simPos.Y = nextPos.Y;

        // Insert new state to history
        insertState(stateHistory, *gs);
    }
}

// Move West
void moveWest(StackState *stateHistory, GameState *gs, MatrixChar *map)
{
    Point currentPos, nextPos;
    createPoint(&currentPos, (*gs).simPos.X, (*gs).simPos.Y);
    createPoint(&nextPos, (*gs).simPos.X - 1, (*gs).simPos.Y);

    if ((*map).buffer[nextPos.Y + 1][nextPos.X + 1] == '#')
    {
        // Update map
        (*map).buffer[nextPos.Y + 1][nextPos.X + 1] = 'S';
        (*map).buffer[currentPos.Y + 1][currentPos.X + 1] = '#';

        // Update game state
        (*gs).simPos.X = nextPos.X;
        (*gs).simPos.Y = nextPos.Y;

        // Insert new state to history
        insertState(stateHistory, *gs);
    }
}