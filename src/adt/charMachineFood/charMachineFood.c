#include <stdio.h>

#include "charMachineFood.h"

char food_currentChar;
int food_EOP;

static FILE *food_file;

void startFood()
{
    food_file = fopen(foodConfig, "r");
    advFood();
}

void advFood()
{
    food_retval = fscanf(food_file, "%c", &food_currentChar);
    food_EOP = (food_retval == EOF);
    if (food_EOP)
    {
        fclose(food_file);
    }
}