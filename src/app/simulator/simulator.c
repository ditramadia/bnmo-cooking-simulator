#include <stdio.h>

#include "../../adt/map/map.c"
#include "../../adt/string/string.c"
#include "../../adt/gameState/gameState.c"

// Command Parser
void simulatorCommandParser(char query[], GameState *currentGameState, MatrixChar *map)
{
    // Available commands
    char moveNCommand[] = "MOVE NORTH";
    char moveECommand[] = "MOVE EAST";
    char moveSCommand[] = "MOVE SOUTH";
    char moveWCommand[] = "MOVE WEST";
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
        moveNorth(currentGameState, map);
        simulator(currentGameState, map);
    }
    else if (compareString(simCommand, moveECommand))
    {
        // Move east
        system("cls");
        moveEast(currentGameState, map);
        simulator(currentGameState, map);
    }
    else if (compareString(simCommand, moveSCommand))
    {
        // Move south
        system("cls");
        moveSouth(currentGameState, map);
        simulator(currentGameState, map);
    }
    else if (compareString(simCommand, moveWCommand))
    {
        // Move west
        system("cls");
        moveWest(currentGameState, map);
        simulator(currentGameState, map);
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
        simulator(currentGameState, map);
    }
}

int loadSimulator()
{
    // Load Map
    MatrixChar map;
    setMap(&map);

    // Set up gameState
    GameState currentGameState;
    setGameState(&currentGameState, map);

    // Simulator
    renderGameState(currentGameState);
    printf("\n");
    renderMap(map);
    simulatorCommandParser("Masukkan perintah", &currentGameState, &map);

    return 0;
}

int simulator(GameState *currentGameState, MatrixChar *map)
{
    renderGameState(*currentGameState);
    printf("\n");
    renderMap(*map);

    simulatorCommandParser("Masukkan perintah", currentGameState, map);

    return 0;
}