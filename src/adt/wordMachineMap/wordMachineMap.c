#include <stdio.h>
#include "wordMachineMap.h"

int map_endWord;
MapWord map_currentWord;

void ignoreBlanksMap()
{
    while (map_currentChar == MAP_BLANK || map_currentChar == '\n')
    {
        advMap();
    }
}

void startWordMap(char *directory)
{
    startCharMap(directory);
    ignoreBlanksMap();
    if (map_currentChar == '\n' || map_retval == MAP_CHAR_MARK)
    {
        map_endWord = 1;
    }
    else
    {
        map_endWord = 0;
        setWordMap();
    }
}

void advWordMap()
{
    ignoreBlanksMap();
    if (map_currentChar == '\n' || map_retval == MAP_CHAR_MARK)
    {
        map_endWord = 1;
    }
    else
    {
        setWordMap();
        ignoreBlanksMap();
    }
}

void setWordMap()
{
    int i = 0;
    while (map_retval != MAP_CHAR_MARK && map_currentChar != '\n' && map_currentChar != MAP_BLANK && i < MAP_NMAX)
    {
        map_currentWord.buffer[i] = map_currentChar;
        advMap();
        i++;
    }
    map_currentWord.length = i;
}

int isEndWordMap()
{
    return map_endWord;
}

void wordToStr(MapWord w, char *str)
{
    int i = 0;
    while (i < w.length)
    {
        str[i] = w.buffer[i];
        i++;
    }
    str[i] = '\0';
}