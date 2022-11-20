#ifndef WORDMACHINERESEP_H
#define WORDMACHINERESEP_H

#include "../charMachineResep/charMachineResep.h"

#define RESEP_NMAX 50
#define RESEP_BLANK ' '

typedef struct
{
   char buffer[RESEP_NMAX];
   int length;
} ResepWord;

// State
extern int resep_endWord;
extern ResepWord resep_currentWord;

void ignoreBlanksResep();

void startWordResep();

void advWordResep();

void setWordResep();

void displayWordResep(ResepWord W);

int wordToIntegerResep();

#endif