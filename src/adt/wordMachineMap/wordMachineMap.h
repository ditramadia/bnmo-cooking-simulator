#ifndef WORD_MACHINE_H
#define WORD_MACHINE_H

#include "../charMachineMap/charMachineMap.h"

// Definition
#define MAP_NMAX 50
#define MAP_BLANK ' '

// Declaration
typedef struct
{
    char buffer[MAP_NMAX];
    int length;
} Word;

// State
extern int map_endWord;
extern Word map_currentWord;

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
void wordToStr(Word w, char *str);

#endif