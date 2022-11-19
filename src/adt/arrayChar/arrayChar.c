#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "arrayChar.h"

// Constructor
void createArrayChar(ArrayChar *arrayChar)
{
    (*arrayChar).idxEff = IDX_UNDEF;
    for (int i = 0; i < ARRAYCHARCAPACITY; i++)
    {
        (*arrayChar).buffer[i] = MARK;
    }
}

// Convert ArrayChar to int
int ArrayCharToInt(ArrayChar arrayChar)
{
    int value = 0, nDigit = arrayChar.idxEff + 1;
    int j = 0;
    for (int i = nDigit - 1; i >= 0; i--)
    {
        int charInt = arrayChar.buffer[j] - 48;
        value += charInt * pow(10, i);
        j++;
    }
    return value;
}