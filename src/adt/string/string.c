#include <stdio.h>

// Compare 2 strings
int compareString(char str1[], char str2[])
{
    int i = 0;
    while (str1[i] != '\0' && str1[i] != '\n' && str2[i] != '\0' && str2[i] != '\n' && i < 100)
    {
        if (str1[i] != str2[i])
        {
            return 0;
        }
        i++;
    }
    return 1;
}

int containFirstWordString(char str1[], char str2[])
{
    int i = 0;
    while (str2[i] != '\0' && str2[i] != '\n' && str2[i] != ' ' && i < 100)
    {
        if (str1[i] != str2[i])
        {
            return 0;
        }
        i++;
    }
    return 1;
}