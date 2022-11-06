#ifndef MATRIXCHAR_H
#define MATRIXCHAR_H

// Definition
#define ROW_CAP 100
#define COL_CAP 100
#define MATRIXMARK '#'

// Declaration
typedef struct
{
    char buffer[ROW_CAP][COL_CAP];
    int rowEff;
    int colEff;
} MatrixChar;

// Constructor
void createMatrix(MatrixChar *m, int nRows, int nCols);

// Display
void displayMatrix(MatrixChar m);

#endif