#include <stdio.h>
#include "charMachineMap.h"

// Definition
char map_currentChar;
int map_EOP;
static FILE *map_file;
static int map_retval;

// Start
void startCharMap(char *directory)
{
    map_file = fopen(directory, "r");
    advMap();
}

// Advance
void advMap()
{
    map_retval = fscanf(map_file, "%c", &map_currentChar);
    map_EOP = (map_retval == MAP_CHAR_MARK);
    if (map_EOP)
    {
        fclose(map_file);
    }
}

// Get Current Character
char getCCMap()
{
    return map_currentChar;
}

// End of File
int isEOPMap()
{
    return map_EOP;
}
