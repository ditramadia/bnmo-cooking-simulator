#include <stdio.h>

// Global State
char simName[20];
MatrixChar map;
Foodlist listFood, listShop, listFry, listChop, listBoil, listMix;
List treeList[100][100];

// Game State
StackState stateHistory;
GameState currentGameState;
Time cgsTime;
Point cgsSimPos;
int nMove;
Queue cgsDelivery;
Queue cgsInventory;
ArrayChar cgsNotifArr;

// Command Parser
void simulatorCommandParser(char query[])
{
    // Available commands
    // 1. Movement
    char moveNCommand[] = "MOVE NORTH";
    char moveECommand[] = "MOVE EAST";
    char moveSCommand[] = "MOVE SOUTH";
    char moveWCommand[] = "MOVE WEST";
    // 2. Catalog
    char catalogCommand[] = "CATALOG";
    // 3. Cook Book
    char cookBookCommand[] = "COOKBOOK";
    // 4. Buy
    char buyCommand[] = "BUY";
    // 5. Delivery
    char deliveryCommand[] = "DELIVERY";
    // 6. Inventory
    char inventoryCommand[] = "INVENTORY";
    // 7. Wait
    char waitCommand[] = "WAIT";
    // 8. Chop
    char chopCommand[] = "CHOP";
    // 9 Boil
    char boilCommand[] = "BOIL";
    // 10 Fry
    char fryCommand[] = "FRY";
    // 11 Mix
    char mixCommand[] = "MIX";
    // 12. Undo
    char undoCommand[] = "UNDO";
    // 13. Redo
    char redoCommand[] = "REDO";
    // 14. Exit
    char exitCommand[] = "EXIT";

    char simCommand[50];
    printf("%s: ", query);
    fflush(stdin);
    fgets(simCommand, 50, stdin);
    fflush(stdin);

    // MOVE NORTH
    if (compareString(simCommand, moveNCommand))
    {
        system(CLEAR);
        moveNorth(&stateHistory, &currentGameState, &map, &nMove);
        simulator();
    }
    // MOVE EAST
    else if (compareString(simCommand, moveECommand))
    {
        system(CLEAR);
        moveEast(&stateHistory, &currentGameState, &map, &nMove);
        simulator();
    }
    // MOVE SOUTH
    else if (compareString(simCommand, moveSCommand))
    {
        system(CLEAR);
        moveSouth(&stateHistory, &currentGameState, &map, &nMove);
        simulator();
    }
    // MOVE WEST
    else if (compareString(simCommand, moveWCommand))
    {
        system(CLEAR);
        moveWest(&stateHistory, &currentGameState, &map, &nMove);
        simulator();
    }
    // CATALOG
    else if (compareString(simCommand, catalogCommand))
    {
        system(CLEAR);
        catalog(listFood);
        system(CLEAR);
        simulator();
    }
    // COOKBOOK
    else if (compareString(simCommand, cookBookCommand))
    {
        system(CLEAR);
        cookbook(treeList, listFood, listShop);
        system(CLEAR);
        simulator();
    }
    // BUY
    else if (compareString(simCommand, buyCommand))
    {
        system(CLEAR);
        if (currentGameState.isAbleBuy)
        {
            buy(&stateHistory, &currentGameState, listShop);
            simulator();
        }
        else
        {
            printf("==============================================================\n");
            printf("|    Anda harus berada di lokasi 'T' untuk melakukan BUY.    |\n");
            printf("==============================================================\n");
            printf("\n");
            simulator();
        }
    }
    // DELIVERY
    else if (compareString(simCommand, deliveryCommand))
    {
        system(CLEAR);
        displayDelivery(currentGameState);
        system(CLEAR);
        simulator();
    }
    // INVENTORY
    else if (compareString(simCommand, inventoryCommand))
    {
        system(CLEAR);
        displayInventory(currentGameState);
        system(CLEAR);
        simulator();
    }
    // WAIT
    else if (containFirstWordString(simCommand, waitCommand))
    {
        system(CLEAR);
        waitTime(&stateHistory, &currentGameState, getWaitHour(simCommand), getWaitMinute(simCommand));
        simulator();
    }
    // CHOP
    else if (compareString(simCommand, chopCommand))
    {
        system(CLEAR);
        chop(&stateHistory, &currentGameState, listFood, listChop, treeList);
        simulator();
    }
    // BOIL
    else if (compareString(simCommand, boilCommand))
    {
        system(CLEAR);
        boil(&stateHistory, &currentGameState, listFood, listBoil, treeList);
        simulator();
    }
    // FRY
    else if (compareString(simCommand, fryCommand))
    {
        system(CLEAR);
        fry(&stateHistory, &currentGameState, listFood, listFry, treeList);
        simulator();
    }
    // MIX
    else if (compareString(simCommand, mixCommand))
    {
        system(CLEAR);
        mix(&stateHistory, &currentGameState, listFood, listMix, treeList);
        simulator();
    }
    // UNDO
    else if (compareString(simCommand, undoCommand))
    {
        system(CLEAR);
        undoState(&stateHistory, &currentGameState, &map);
        simulator();
    }
    // REDO
    else if (compareString(simCommand, redoCommand))
    {
        system(CLEAR);
        redoState(&stateHistory, &currentGameState, &map);
        simulator();
    }
    // EXIT
    else if (compareString(simCommand, exitCommand))
    {
        // Call exit app
        exit(0);
    }
    // COMMAND UNVAILABLE
    else
    {
        system(CLEAR);
        printf("==============================================================\n");
        printf("|                   Perintah tidak tersedia                  |\n");
        printf("==============================================================\n");
        printf("\n");
        simulator();
    }
}

int simulator()
{
    // Update Current Game State
    currentGameState = stateHistory.buffer[stateHistory.currentStateId];

    // Display SimPos
    printf("Posisi %s: (%d, %d)\n", simName, currentGameState.simPos.X, currentGameState.simPos.Y);

    // Display CGS Time
    printf("Waktu: ");
    displayTime(currentGameState.time);
    printf("\n");

    // Display notif
    printf("Notifikasi: \n");
    // displayNotif(currentGameState.notification); // ERROR
    // printf("\n");

    // Display Map
    updateMap(currentGameState, &map);
    renderMap(map);

    // Ask for input
    simulatorCommandParser("Masukkan perintah");
}

int loadSimulator()
{
    // Load simName
    fflush(stdin);
    printf("Masukkan nama Anda: ");
    scanf("%s", &simName);
    system(CLEAR);

    // Load Map
    loadMap(&map);

    // Load Simulator Position
    cgsSimPos = loadSimPos(map);

    // Load nMove
    nMove = 0;

    // Load Foods
    addList(&listFood);
    listshop(&listShop, listFood);
    listchop(&listChop, listFood);
    listboil(&listBoil, listFood);
    listmix(&listMix, listFood);
    listfry(&listFry, listFood);
    createTree(treeList);
    makeTree(treeList);

    // Load delivery
    CreateQueue(&cgsDelivery);

    // Load Inventory
    CreateQueue(&cgsInventory);

    // Load Notif
    createArrayChar(&cgsNotifArr);

    // Load Current Game State (cgs)
    createTime(&cgsTime, 0, 5, 0);

    // Load Game State
    currentGameState.simPos = cgsSimPos;
    currentGameState.time = cgsTime;
    currentGameState.delivery = cgsDelivery;
    currentGameState.inventory = cgsInventory;
    currentGameState.notification = cgsNotifArr;
    updateAvailableAction(&currentGameState, map);

    // Load State History
    insertState(&stateHistory, currentGameState);

    // Proceed to simulator
    simulator();
}
