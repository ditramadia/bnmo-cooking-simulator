#include "../point/point.h"
#include "../matrixChar/matrixChar.h"
#include "../time/time.h"
#include "../queuelinked/queuelinked.h"
#include "../notifikasi/notifikasi.h"

#ifndef GAMESTATE_H
#define GAMESTATE_H

// Declaration
typedef struct
{
    Point simPos;
    Time time;
    Queue inventory;
    Queue delivery;
    int isAbleBuy;
    int isAbleMix;
    int isAbleChop;
    int isAbleFry;
    int isAbleBoil;
} GameState;

// State
extern GameState currentGameState;

// Find simPos
Point setSimPos(MatrixChar map);

// Set time
Time setTime(int day, int hour, int minute);

// Constructor
void setGameState(GameState *gs, MatrixChar map, Queue inventory, Queue delivery);

// Display
void renderGameState(GameState gs, Notiflist Nl);

// Update map
void updateMap(GameState gs, MatrixChar *map);

// Update delivery
void updateDeliveryTime(Queue *delivery, Queue *inventory, int day, int hour, int minute, Notiflist *Nl);

// Update time
void updateTime(GameState *gs, int day, int hour, int minute);

// Update available action
void updateAvailableAction(GameState *gs, MatrixChar map);

#endif