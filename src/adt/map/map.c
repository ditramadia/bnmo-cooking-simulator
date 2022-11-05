#include <stdio.h>
#include <stdlib.h>

#include "../matrixChar/matrixChar.c"
#include "../point/point.c"

// KONSTRUKTOR
void setMap(Matrix *map)
{
    // 10 10
    // S#########
    // ####T##X##
    // #M#####X##
    // #######X##
    // ####XXXX##
    // #X########
    // #X######C#
    // #XXX##F###
    // ##########
    // ######B###
    int height = 10 + 2, width = 10 + 2;

    // hard coded map
    createMatrix(height, width, map);
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Border
            if (i == 0 || i == (height - 1) || j == 0 || j == (width - 1))
            {
                setMatrixElmt(i, j, '*', map);
            }
            // Sim
            else if (i == 1 && j == 1)
            {
                setMatrixElmt(i, j, 'S', map);
            }
            // Telephone Area
            else if (i == 2 && j == 5)
            {
                setMatrixElmt(i, j, 'T', map);
            }
            // Mixing Area
            else if (i == 3 && j == 2)
            {
                setMatrixElmt(i, j, 'M', map);
            }
            // Chopping Area
            else if (i == 7 && j == 9)
            {
                setMatrixElmt(i, j, 'C', map);
            }
            // Frying Area
            else if (i == 8 && j == 7)
            {
                setMatrixElmt(i, j, 'F', map);
            }
            // Boiling Area
            else if (i == 10 && j == 7)
            {
                setMatrixElmt(i, j, 'B', map);
            }
            // Wall
            else if ((i == 2 && j == 8) || (i == 3 && j == 8) || (i == 4 && j == 8) || (i == 5 && j == 8) || (i == 5 && j == 7) || (i == 5 && j == 6) || (i == 5 && j == 5) || (i == 6 && j == 2) || (i == 7 && j == 2) || (i == 8 && j == 2) || (i == 8 && j == 3) || (i == 8 && j == 4))
            {
                setMatrixElmt(i, j, 'X', map);
            }
            else
            {
                setMatrixElmt(i, j, ' ', map);
            }
        }
    }
}

// DISPLAY
void renderMap(Matrix map)
{
    for (int i = 0; i < ROW_EFF(map); i++)
    {
        for (int j = 0; j < COL_EFF(map); j++)
        {
            printf("%c", getMatrixElmt(i, j, map));
            printf(" ");
        }
        printf("\n");
    }
}