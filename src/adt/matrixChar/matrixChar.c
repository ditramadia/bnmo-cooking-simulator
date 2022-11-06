#include <stdio.h>

#include "matrixChar.h"

// Constructor
void createMatrix(MatrixChar *m, int nRows, int nCols)
{
    (*m).rowEff = nRows;
    (*m).colEff = nCols;
    for (int i = 0; i < nRows; i++)
    {
        for (int j = 0; j < nCols; j++)
        {
            (*m).buffer[i][j] = MATRIXMARK;
        }
    }
}

void displayMatrix(MatrixChar m)
{
    for (int i = 0; i < m.rowEff; i++)
    {
        for (int j = 0; j < m.colEff; j++)
        {
            printf("%c ", m.buffer[i][j]);
        }
        printf("\n");
    }
}