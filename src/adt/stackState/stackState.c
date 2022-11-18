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
void undoState(StackState *stackState, GameState *currentGameState, MatrixChar *map, Queue *delivery, Queue *inventory)
{
    if ((*stackState).currentStateId > 0)
    {
        // Undo Game State
        (*stackState).currentStateId--;
        *currentGameState = (*stackState).buffer[(*stackState).currentStateId];

        // Update delivery and inventory
        *delivery = (*currentGameState).delivery;
        *inventory = (*currentGameState).inventory;

        // Update Map
        updateMap(*currentGameState, map);
    }
}

// Redo
void redoState(StackState *stackState, GameState *currentGameState, MatrixChar *map, Queue *delivery, Queue *inventory)
{
    if ((*stackState).currentStateId != (*stackState).idxEff)
    {
        // Redo Game State
        (*stackState).currentStateId++;
        *currentGameState = (*stackState).buffer[(*stackState).currentStateId];

        // Update delivery and inventory
        *delivery = (*currentGameState).delivery;
        *inventory = (*currentGameState).inventory;

        // Update Map
        updateMap(*currentGameState, map);
    }
}

// Move North
void moveNorth(StackState *stateHistory, GameState *gs, MatrixChar *map, Queue *delivery, Queue *inventory, int *nMove)
{
    Point currentPos, nextPos;
    createPoint(&currentPos, (*gs).simPos.X, (*gs).simPos.Y);
    createPoint(&nextPos, (*gs).simPos.X, (*gs).simPos.Y - 1);

    if ((*map).buffer[nextPos.Y + 1][nextPos.X + 1] == '#')
    {
        // Update map
        (*map).buffer[nextPos.Y + 1][nextPos.X + 1] = 'S';
        (*map).buffer[currentPos.Y + 1][currentPos.X + 1] = '#';

        // Update game state SimPos
        (*gs).simPos.X = nextPos.X;
        (*gs).simPos.Y = nextPos.Y;

        // Update game state action
        updateAvailableAction(gs, *map);

        // Update time and delivery
        if (*nMove % 3 == 0)
        {
            updateTime(gs, 0, 0, 1);
            updateDeliveryTime(delivery, inventory, 0, 0, 1);
        }
        (*nMove)++;

        // Insert new state to history
        insertState(stateHistory, *gs);
    }
}

// Move East
void moveEast(StackState *stateHistory, GameState *gs, MatrixChar *map, Queue *delivery, Queue *inventory, int *nMove)
{
    Point currentPos, nextPos;
    createPoint(&currentPos, (*gs).simPos.X, (*gs).simPos.Y);
    createPoint(&nextPos, (*gs).simPos.X + 1, (*gs).simPos.Y);

    if ((*map).buffer[nextPos.Y + 1][nextPos.X + 1] == '#')
    {
        // Update map
        (*map).buffer[nextPos.Y + 1][nextPos.X + 1] = 'S';
        (*map).buffer[currentPos.Y + 1][currentPos.X + 1] = '#';

        // Update game state simPos
        (*gs).simPos.X = nextPos.X;
        (*gs).simPos.Y = nextPos.Y;

        // Update game state action
        updateAvailableAction(gs, *map);

        // Update time
        if (*nMove % 3 == 0)
        {
            updateTime(gs, 0, 0, 1);
            updateDeliveryTime(delivery, inventory, 0, 0, 1);
        }
        (*nMove)++;

        // Insert new state to history
        insertState(stateHistory, *gs);
        updateDeliveryState(gs, *delivery);
    }
}

// Move South
void moveSouth(StackState *stateHistory, GameState *gs, MatrixChar *map, Queue *delivery, Queue *inventory, int *nMove)
{
    Point currentPos, nextPos;
    createPoint(&currentPos, (*gs).simPos.X, (*gs).simPos.Y);
    createPoint(&nextPos, (*gs).simPos.X, (*gs).simPos.Y + 1);

    if ((*map).buffer[nextPos.Y + 1][nextPos.X + 1] == '#')
    {
        // Update map
        (*map).buffer[nextPos.Y + 1][nextPos.X + 1] = 'S';
        (*map).buffer[currentPos.Y + 1][currentPos.X + 1] = '#';

        // Update game state simPos
        (*gs).simPos.X = nextPos.X;
        (*gs).simPos.Y = nextPos.Y;

        // Update game state action
        updateAvailableAction(gs, *map);

        // Update time
        if (*nMove % 3 == 0)
        {
            updateTime(gs, 0, 0, 1);
            updateDeliveryTime(delivery, inventory, 0, 0, 1);
        }
        (*nMove)++;

        // Insert new state to history
        insertState(stateHistory, *gs);
    }
}

// Move West
void moveWest(StackState *stateHistory, GameState *gs, MatrixChar *map, Queue *delivery, Queue *inventory, int *nMove)
{
    Point currentPos, nextPos;
    createPoint(&currentPos, (*gs).simPos.X, (*gs).simPos.Y);
    createPoint(&nextPos, (*gs).simPos.X - 1, (*gs).simPos.Y);

    if ((*map).buffer[nextPos.Y + 1][nextPos.X + 1] == '#')
    {
        // Update map
        (*map).buffer[nextPos.Y + 1][nextPos.X + 1] = 'S';
        (*map).buffer[currentPos.Y + 1][currentPos.X + 1] = '#';

        // Update game state simPos
        (*gs).simPos.X = nextPos.X;
        (*gs).simPos.Y = nextPos.Y;

        // Update game state action
        updateAvailableAction(gs, *map);

        // Update time
        if (*nMove % 3 == 0)
        {
            updateTime(gs, 0, 0, 1);
            updateDeliveryTime(delivery, inventory, 0, 0, 1);
        }
        (*nMove)++;

        // Insert new state to history
        insertState(stateHistory, *gs);
    }
}

// Update delivery
void updateDeliveryState(GameState *currentGameState, Queue delivery)
{
    (*currentGameState).delivery = delivery;
}

// Update inventory
void updateInventoryState(GameState *currentGameState, Queue inventory)
{
    (*currentGameState).inventory = inventory;
}

// Get Wait Hour
int getWaitHour(char command[])
{
    // WAIT 2 5
    ArrayChar waitHourArr;
    createArrayChar(&waitHourArr);

    int i = 0;
    while (i < 50 && command[i] != '\0' && command[i] != '\n')
    {
        if (command[i] == ' ')
        {
            i++;

            int j = 0;
            while (command[i] != ' ')
            {
                (waitHourArr).buffer[j] = command[i];
                (waitHourArr).idxEff++;
                j++;
                i++;
            }

            return ArrayCharToInt(waitHourArr);
        }
        i++;
    }
}

// Get Wait Minute
int getWaitMinute(char command[])
{
    // WAIT 2 5
    ArrayChar watMinuteArr;
    createArrayChar(&watMinuteArr);

    int i = 0;
    while (i < 50 && command[i] != '\0' && command[i] != '\n')
    {
        if (command[i] == ' ')
        {
            i++;
            while (i < 50 && command[i] != '\0' && command[i] != '\n')
            {
                if (command[i] == ' ')
                {
                    i++;

                    int j = 0;
                    while (command[i] != '\0' && command[i] != '\n')
                    {
                        (watMinuteArr).buffer[j] = command[i];
                        (watMinuteArr).idxEff++;
                        j++;
                        i++;
                    }

                    return ArrayCharToInt(watMinuteArr);
                }
                i++;
            }
        }
        i++;
    }
}

// Wait
void waitTime(StackState *stateHistory, GameState *gs, Queue *delivery, Queue *inventory, int hour, int minute)
{
    // Update
    int day = hour / 24;
    int nHour = hour % 24;
    int minutes = timeToMinute((*gs).time);
    int addedMinutes = (1440 * day) + (60 * nHour) + minute;
    int totalMinute = minutes + addedMinutes;
    (*gs).time = minuteToTime(totalMinute);

    // Update delivery
    updateDeliveryTime(delivery, inventory, day, nHour, minute);
    updateDeliveryState(gs, *delivery);
    updateInventoryState(gs, *inventory);

    insertState(stateHistory, *gs);
}