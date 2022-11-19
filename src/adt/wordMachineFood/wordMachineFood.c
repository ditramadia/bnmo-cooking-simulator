#include <stdio.h>

#include "../charMachineFood/charMachineFood.h"
#include "wordMachineFood.h"

int food_endWord;
FoodWord food_currentWord;

void ignoreBlanksFood()
{
    while (food_currentChar == FOOD_BLANK || food_currentChar == '\n')
    {
        advFood();
    }
}

void startWordFood()
{
    startFood();
    if (food_currentChar == '\n')
    {
        food_endWord = 1;
    }
    else
    {
        food_endWord = 0;
        setWordFood();
    }
}

void advWordFood()
{
    ignoreBlanksFood();
    if (food_currentChar == '\n')
    {
        food_endWord = 1;
    }
    else
    {
        setWordFood();
    }
}

void setWordFood()
{
    food_currentWord.length = 0;
    while (food_currentChar != FOOD_CHAR_MARK && food_currentWord.length < FOOD_NMAX && food_currentChar != '\n' && food_retval != EOF)
    {
        food_currentWord.buffer[food_currentWord.length] = food_currentChar;
        food_currentWord.length++;
        advFood();
    }
}

void displayWordFood(FoodWord W)
{
    int i;
    for (i = 0; i < W.length; i++)
    {
        printf("%c", W.buffer[i]);
    }
}

int wordToIntegerFood()
{
    int i;
    int cc = 1;
    int X = 0;
    for (i = 0; i < food_currentWord.length; i++)
    {
        while (food_currentWord.buffer[i] == ' ')
        {
            i++;
        }
        X = X * cc + (int)(food_currentWord.buffer[i] - 48);
        cc *= 10;
    }
    return X;
}

void wordToStri(FoodWord w, char *str)
{
    int i = 0;
    while (i < w.length)
    {
        str[i] = w.buffer[i];
        i++;
    }
    str[i] = '\0';
}

void currentWts(char *y)
{
    int i;
    for (i = 0; i < food_currentWord.length; i++)
    {
        y[i] = food_currentWord.buffer[i];
    }
}