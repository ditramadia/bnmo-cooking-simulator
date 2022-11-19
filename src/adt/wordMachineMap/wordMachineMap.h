#ifndef WORDMACHINEMAP_H
#define WORDMACHINEMAP_H

#include "../charMachineMap/charMachineMap.h"

// Definition
#define MAP_NMAX 50
#define MAP_BLANK ' '

// Declaration
typedef struct
{
    char buffer[MAP_NMAX];
    int length;
} MapWord;

// State
extern int map_endWord;
extern MapWord map_currentWord;

// Ignore Blanks
void ignoreBlanksMap();

// Start Word
void startWordMap();

// Advance Word
void advWordMap();

// Set Word
void setWordMap();

// End of Word
int isEndWordMap();

// Convert Word to String
void wordToStr(MapWord w, char *str);

#endif