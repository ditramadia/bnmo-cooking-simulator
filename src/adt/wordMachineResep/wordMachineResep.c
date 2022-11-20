#include <stdio.h>

#include "../charMachineResep/charMachineResep.h"
#include "wordMachineResep.h"

int resep_endWord;
ResepWord resep_currentWord;

void ignoreBlanksResep()
{
    while (resep_currentChar == RESEP_BLANK || resep_currentChar == '\n')
    {
        advResep();
    }
}

void startWordResep()
{
    startCharResep();
    ignoreBlanksResep();
    if (resep_retval == EOF)
    {
        resep_endWord = 1;
    }
    else
    {
        resep_endWord = 0;
        setWordResep();
    }
}

void advWordResep()
{
    ignoreBlanksResep();
    if (resep_currentChar == '\n')
    {
        resep_endWord = 1;
    }
    else
    {
        setWordResep();
    }
}

void setWordResep()
{
    resep_currentWord.length = 0;
    while (resep_currentChar != RESEP_BLANK && resep_currentWord.length < RESEP_NMAX && resep_currentChar != '\n' && resep_retval != EOF)
    {
        // printf("masuk gk\n");
        resep_currentWord.buffer[resep_currentWord.length] = resep_currentChar;
        resep_currentWord.length++;
        advResep();
    }
}

void displayWordResep(ResepWord W)
{
    int i;
    for (i = 0; i < W.length; i++)
    {
        printf("%c", W.buffer[i]);
    }
    printf(" ");
}

int wordToIntegerResep()
{
    int i;
    int cc = 1;
    int X = 0;
    for (i = 0; i < resep_currentWord.length; i++)
    {
        X = X * cc + (int)(resep_currentWord.buffer[i] - 48);
        cc *= 10;
    }
    return X;
}

void wordToStringResep(char y[resep_currentWord.length])
{
    int i;
    for (i = 0; i < resep_currentWord.length; i++)
    {
        y[i] = resep_currentWord.buffer[i];
    }
}