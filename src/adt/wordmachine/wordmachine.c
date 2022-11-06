#include <stdio.h>

#include "wordmachine.h"
#include "../charmachine/charmachine.c"

int endWord;
Word currentWord;

void ignoreBlanks()
{
    while (currentChar == BLANK || currentChar == '\n')
    {
        adv();
    }
}

void startWord(char *directory)
{
    startChar(directory);
    ignoreBlanks();
    if (currentChar == '\n' || retval == CHARMARK)
    {
        endWord = 1;
    }
    else
    {
        endWord = 0;
        setWord();
    }
}

void advWord()
{
    ignoreBlanks();
    if (currentChar == '\n' || retval == CHARMARK)
    {
        endWord = 1;
    }
    else
    {
        setWord();
        ignoreBlanks();
    }
}

void setWord()
{
    int i = 0;
    while (retval != CHARMARK && currentChar != '\n' && currentChar != BLANK && i < NMAX)
    {
        currentWord.buffer[i] = currentChar;
        adv();
        i++;
    }
    currentWord.length = i;
}

int isEndWord()
{
    return endWord;
}

void wordToStr(Word w, char *str)
{
    int i = 0;
    while (i < w.length)
    {
        str[i] = w.buffer[i];
        i++;
    }
    str[i] = '\0';
}