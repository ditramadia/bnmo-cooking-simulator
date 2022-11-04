#include <stdio.h>
#include <string.h>

#include "../../adt/liststatik/liststatik.c"
#include "../../adt/string/string.c"

int main()
{
    // Commands
    /// Simulator Movement
    char moveNorth[50] = "MOVE NORTH";
    char moveEast[50] = "MOVE EAST";
    char moveWest[50] = "MOVE WEST";
    char moveSouth[50] = "MOVE SOUTH";

    // Calling an app
    int isCommandValid = 0;
    while (!isCommandValid)
    {
        char command[50];
        printf("Masukkan perintah: ");
        fgets(command, 50, stdin);

        isCommandValid = 1;
        // Simulator Movement
        if (cmpStr(command, moveNorth))
        {
            printf("Move North");
        }
        else if (cmpStr(command, moveEast))
        {
            printf("Move East");
        }
        else if (cmpStr(command, moveWest))
        {
            printf("Move West");
        }
        else if (cmpStr(command, moveSouth))
        {
            printf("Move South");
        }
        // Invalid command
        else
        {
            printf("Perintah tidak ditemukan.\n");
            isCommandValid = 0;
        }
    }
}