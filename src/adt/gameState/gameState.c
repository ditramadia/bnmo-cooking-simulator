#include <stdio.h>

#include "gameState.h"
#include "../point/point.c"

// Find sPos
Point setSimPos(MatrixChar map)
{
    Point simPos;
    for (int i = 0; i < map.rowEff; i++)
    {
        for (int j = 0; j < map.colEff; j++)
        {
            if (map.buffer[i][j] == 'S')
            {
                createPoint(&simPos, j - 1, i - 1);
                return simPos;
            }
        }
    }
}

// Constructor
void setGameState(GameState *gs, MatrixChar map)
{
    // Set sPos
    (*gs).simPos = setSimPos(map);
    // printf("Test\n");
}

// Display
void renderGameState(GameState gs)
{
    printf("Posisi BNMO: (%d,%d)", gs.simPos.X, gs.simPos.Y);
}

// Move North
void moveNorth(GameState *gs, MatrixChar *map)
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
    }
}

// Move East
void moveEast(GameState *gs, MatrixChar *map)
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
    }
}

// Move South
void moveSouth(GameState *gs, MatrixChar *map)
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
    }
}

// Move West
void moveWest(GameState *gs, MatrixChar *map)
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
    }
}