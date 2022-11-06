#include <stdio.h>

#include "../../adt/map/map.c"
#include "../../adt/string/string.c"

// Command Parser
void simulatorCommandParser(char query[])
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

    int isSimCommandValid = 0;
    while (!isSimCommandValid)
    {
        char simCommand[50];
        printf("%s: ", query);
        scanf("%s", &simCommand);
        // fgets(simCommand, 50, stdin); // Need fixing

        if (compareString(simCommand, moveNCommand))
        {
            // Call buy app
            system("cls");
            printf("Move North.\n");
            isSimCommandValid = 1;
        }
        else if (compareString(simCommand, buyCommand))
        {
            // Call buy app
            system("cls");
            printf("Call Buy Function.\n");
            isSimCommandValid = 1;
        }
        else if (compareString(simCommand, chopCommand))
        {
            // Call chop app
            system("cls");
            printf("Call Chop Function.\n");
            isSimCommandValid = 1;
        }
        else if (compareString(simCommand, mixCommand))
        {
            // Call mix app
            system("cls");
            printf("Call Mix Function.\n");
            isSimCommandValid = 1;
        }
        else if (compareString(simCommand, boilCommand))
        {
            // Call boil app
            system("cls");
            printf("Call Boil Function.\n");
            isSimCommandValid = 1;
        }
        else if (compareString(simCommand, fryCommand))
        {
            // Call chop app
            system("cls");
            printf("Call Fry Function.\n");
            isSimCommandValid = 1;
        }
        else if (compareString(simCommand, exitCommand))
        {
            // Call exit app
            exit(0);
        }
        else
        {
            printf("Perintah tidak tersedia.\n");
        }
    }
}

int main()
{
    // Loading Map
    MatrixChar map;
    setMap(&map);

    // Simulator
    renderMap(map);
    simulatorCommandParser("Masukkan perintah");

    return 0;
}