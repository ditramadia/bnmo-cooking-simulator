#include <stdio.h>

#include "../../adt/string/string.c"
#include "../../adt/gameState/gameState.c"
#include "../../adt/stackState/stackState.c"
#include "../../adt/map/map.c"

// Global State
MatrixChar map;
GameState currentGameState;
StackState stateHistory;

// Command Parser
void simulatorCommandParser(char query[])
{
    // Available commands
    char moveNCommand[] = "MOVE NORTH";
    char moveECommand[] = "MOVE EAST";
    char moveSCommand[] = "MOVE SOUTH";
    char moveWCommand[] = "MOVE WEST";
    char undoCommand[] = "UNDO";
    char redoCommand[] = "REDO";
    char buyCommand[] = "BUY";
    char chopCommand[] = "CHOP";
    char mixCommand[] = "MIX";
    char boilCommand[] = "BOIL";
    char fryCommand[] = "FRY";
    char exitCommand[] = "EXIT";

    char simCommand[50];
    printf("%s: ", query);
    fflush(stdin);
    fgets(simCommand, 50, stdin);

    if (compareString(simCommand, moveNCommand))
    {
        // Move north
        system("cls");
        moveNorth(&stateHistory, &currentGameState, &map);
        simulator();
    }
    else if (compareString(simCommand, moveECommand))
    {
        // Move east
        system("cls");
        moveEast(&stateHistory, &currentGameState, &map);
        simulator();
    }
    else if (compareString(simCommand, moveSCommand))
    {
        // Move south
        system("cls");
        moveSouth(&stateHistory, &currentGameState, &map);
        simulator();
    }
    else if (compareString(simCommand, moveWCommand))
    {
        // Move west
        system("cls");
        moveWest(&stateHistory, &currentGameState, &map);
        simulator();
    }
    else if (compareString(simCommand, undoCommand))
    {
        // Undo
        system("cls");
        undoState(&stateHistory, &currentGameState, &map);
        simulator();
    }
    else if (compareString(simCommand, redoCommand))
    {
        // Redo
        system("cls");
        redoState(&stateHistory, &currentGameState, &map);
        simulator();
    }
    else if (compareString(simCommand, buyCommand))
    {
        // Call buy app
        system("cls");
        printf("Call Buy Function.\n");
    }
    else if (compareString(simCommand, chopCommand))
    {
        // Call chop app
        system("cls");
        printf("Call Chop Function.\n");
    }
    else if (compareString(simCommand, mixCommand))
    {
        // Call mix app
        system("cls");
        printf("Call Mix Function.\n");
    }
    else if (compareString(simCommand, boilCommand))
    {
        // Call boil app
        system("cls");
        printf("Call Boil Function.\n");
    }
    else if (compareString(simCommand, fryCommand))
    {
        // Call chop app
        system("cls");
        printf("Call Fry Function.\n");
    }
    else if (compareString(simCommand, exitCommand))
    {
        // Call exit app
        exit(0);
    }
    else
    {
        system("cls");
        simulator();
    }
}

int loadSimulator()
{
    // Load Map
    setMap(&map);

    // Set up gameState
    setGameState(&currentGameState, map);
    createStackState(&stateHistory);
    insertState(&stateHistory, currentGameState);

    // Simulator
    renderGameState(currentGameState);
    renderMap(map);
    simulatorCommandParser("Masukkan perintah");

    return 0;
}

int simulator()
{
    renderGameState(currentGameState);
    renderMap(map);

    simulatorCommandParser("Masukkan perintah");

    return 0;
}