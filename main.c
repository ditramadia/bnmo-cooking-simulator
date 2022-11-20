#include <stdio.h>

// Import configuration
#include "config/config.h"
#include "config/os.h"

// Import ADT
#include "src/adt/charMachineMap/charMachineMap.c"
#include "src/adt/wordMachineMap/wordMachineMap.c"
#include "src/adt/charMachineResep/charMachineResep.c"
#include "src/adt/wordMachineResep/wordMachineResep.c"
#include "src/adt/matrixChar/matrixChar.c"
#include "src/adt/arrayChar/arrayChar.c"
#include "src/adt/string/string.c"
#include "src/adt/point/point.c"
#include "src/adt/simPos/simPos.c"
#include "src/adt/map/map.c"
#include "src/adt/time/time.c"
#include "src/adt/charMachineFood/charMachineFood.c"
#include "src/adt/wordMachineFood/wordMachineFood.c"
#include "src/adt/food/food.c"
#include "src/adt/queuelinked/queuelinked.c"
#include "src/adt/delivery/delivery.c"
#include "src/adt/inventory/inventory.c"
#include "src/adt/gameState/gameState.c"
#include "src/adt/stackState/stackState.c"

// Import App
#include "src/app/buy/buy.c"
#include "src/app/catalog/catalog.c"
#include "src/app/simulator/simulator.c"
#include "src/app/mainMenu/mainMenu.c"

int main()
{
    mainMenu();
    return 0;
}