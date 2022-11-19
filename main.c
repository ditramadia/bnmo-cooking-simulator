#include <stdio.h>

// Import configuration
#include "config/config.h"
#include "config/os.h"

// Import ADT
#include "src/adt/charMachineMap/charMachineMap.c"
#include "src/adt/wordMachineMap/wordMachineMap.c"
#include "src/adt/matrixChar/matrixChar.c"
#include "src/adt/string/string.c"
#include "src/adt/map/map.c"
#include "src/adt/time/time.c"

// Import App
#include "src/app/simulator/simulator.c"
#include "src/app/mainMenu/mainMenu.c"

int main()
{
    mainMenu();
    return 0;
}