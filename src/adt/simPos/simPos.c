#include <stdio.h>
#include <stdlib.h>

#include "simPos.h"

Point loadSimPos(MatrixChar map)
{
    Point simPos;
    for (int i = 0; i < map.rowEff; i++)
    {
        for (int j = 0; j < map.colEff; j++)
        {
            if (map.buffer[i][j] == 'S')
            {
                createPoint(&simPos, j - 1, i - 1);
                return simPos;
            }
        }
    }
}