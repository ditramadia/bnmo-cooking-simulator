#ifndef CHARMACHINERESEP_H
#define CHARMACHINERESEP_H

#define RESEP_MARK '.'

// State
extern char resep_currentChar;
extern int resep_EOP;

// Start
void startCharResep();

// Advance
void advResep();

#endif