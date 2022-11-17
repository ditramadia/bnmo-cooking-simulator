#include "wordmachine.h"
#include <stdio.h>

/* State Mesin word */
boolean EndWord;
word Currentword;

void IgnoreBlanksFood()
{
    while (currentChar == BLANK || currentChar == '\n')
    {
        ADVFOOD();
    }
}

void STARTWORDFOOD()
{
    STARTFOOD();
    // IgnoreBlanks();
    if (currentChar == '\n')
    {
        EndWord = true;
    }
    else
    {
        EndWord = false;
        CopyWordFood();
    }
}

void ADVWORDFOOD()
{
    IgnoreBlanksFood();
    if (currentChar == '\n')
    {
        EndWord = true;
    }
    else
    {
        CopyWordFood();
        //   IgnoreBlanks();
    }
}

void CopyWordFood()
{
    // IgnoreBlanks();
    Currentword.Length = 0;
    while (currentChar != MARK && Currentword.Length < NMax && currentChar != '\n' && retval != EOF)
    {
        // printf("masuk gk\n");
        Currentword.TabWord[Currentword.Length] = currentChar;
        Currentword.Length++;
        ADVFOOD();
    }
}

void displayWordFood(word W)
{
    int i;
    for (i = 0; i < W.Length; i++)
    {
        printf("%c", W.TabWord[i]);
    }
    // printf(" ");
}

int wordToIntegerFood()
{
    int i;
    int cc = 1;
    int X = 0;
    for (i = 0; i < Currentword.Length; i++)
    {
        while (Currentword.TabWord[i] == ' ')
        {
            i++;
        }
        X = X * cc + (int)(Currentword.TabWord[i] - 48);
        cc *= 10;
    }
    return X;
}

void wordToStri(word w, char *str)
{
    int i = 0;
    while (i < w.Length)
    {
        // printf("masuk kh");
        str[i] = w.TabWord[i];
        // printf("%c",str[i]);
        i++;
    }
    str[i] = '\0';
}

void currentWts(char *y)
{
    int i;
    for (i = 0; i < Currentword.Length; i++)
    {
        y[i] = Currentword.TabWord[i];
    }
}