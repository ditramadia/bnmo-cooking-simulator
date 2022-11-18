#ifndef CHARMACHINE_H
#define CHARMACHINE_H

// Dictionary
#define CHARMARK -1

// State
extern char currentChar;
extern int EOP;

// Start
void startChar();

// Advance
void adv();

// Get Current Character
char getCC();

// End of File
int isEOP();

#endif