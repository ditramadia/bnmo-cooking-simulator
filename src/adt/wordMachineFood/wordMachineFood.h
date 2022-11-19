#ifndef WORDMACHINEFOOD_H
#define WORDMACHINEFOOD_H

#include "../charMachineFood/charMachineFood.h"

// Definition
#define FOOD_NMAX 50
#define FOOD_BLANK ' '

// Declaration
typedef struct
{
   char buffer[FOOD_NMAX];
   int length;
} FoodWord;

// State
extern int food_endWord;
extern FoodWord food_currentWord;

// Ignore Blanks
void ignoreBlanksFood();

// Start Word
void startWordFood();

// Advance Word
void advWordFood();

// Set Word
void setWordFood();

// Display Word
void displayWordFood(FoodWord W);

#endif