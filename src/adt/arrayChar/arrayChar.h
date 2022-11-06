#ifndef ARRAYCHAR_H
#define ARRAYCHAR_H

// Definition
#define ARRAYCHARCAPACITY 50
#define IDX_UNDEF -1
#define MARK '#'

// Declaration
typedef struct
{
    char buffer[ARRAYCHARCAPACITY];
    int idxEff;
} ArrayChar;

// Constructor
void createArrayChar(ArrayChar *arrayChar);

// Convert ArrayChar to int
int ArrayCharToInt(ArrayChar arrayChar);

#endif