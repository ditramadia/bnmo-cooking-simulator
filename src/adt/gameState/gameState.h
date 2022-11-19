#include "../point/point.h"
#include "../simPos/simPos.h"
#include "../matrixChar/matrixChar.h"
#include "../time/time.h"
#include "../queuelinked/queuelinked.h"

#ifndef GAMESTATE_H
#define GAMESTATE_H

// Declaration
typedef struct
{
    Point simPos;
    Time time;
    Queue delivery;
    int isAbleBuy;
    int isAbleMix;
    int isAbleChop;
    int isAbleFry;
    int isAbleBoil;
} GameState;

// State
extern GameState currentGameState;

Queue updateDeliveryTime(Queue *delivery, int day, int hour, int minute);

// Add time
void addTime(GameState *gs, int day, int hour, int minute);

// Update map
void updateMap(GameState gs, MatrixChar *map);

// Update available action
void updateAvailableAction(GameState *gs, MatrixChar map);

// Display
void displayDelivery(GameState gs);

#endif