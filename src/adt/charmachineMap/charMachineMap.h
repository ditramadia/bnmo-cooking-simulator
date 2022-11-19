#ifndef CHARMACHINEMAP_H
#define CHARMACHINEMAP_H

// Dictionary
#define MAP_CHAR_MARK -1

// State
extern char map_currentChar;
extern int map_EOP;

// Start
void startCharMap();

// Advance
void advMap();

// Get Current Character
char getCCMap();

// End of File
int isEOPMap();

#endif