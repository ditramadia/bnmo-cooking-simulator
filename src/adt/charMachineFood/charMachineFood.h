#ifndef CHARMACHINEFOOD_H
#define CHARMACHINEFOOD_H

// Dictionary
#define FOOD_CHAR_MARK '.'

// State
extern char food_currentChar;
extern int food_EOP;

static int food_retval;

// Start
void startCharFood();

// Advance
void advFood();

#endif