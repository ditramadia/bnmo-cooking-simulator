#include "../charmachine/charmachine.h"

#ifndef WORDMACHINE_H
#define WORDMACHINE_H

// Definition
#define NMAX 50
#define BLANK ' '

// Declaration
typedef struct
{
    char buffer[NMAX];
    int length;
} Word;

// State
extern int endWord;
extern Word currentWord;

// Ignore Blanks
void ignoreBlanks();

// Start Word
void startWord();

// Advance Word
void advWord();

// Set Word
void setWord();

// End of Word
int isEndWord();

// Convert Word to String
void wordToStr(Word w, char *str);

#endif