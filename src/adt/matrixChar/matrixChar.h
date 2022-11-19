#ifndef MATRIXCHAR_H
#define MATRIXCHAR_H

// Definition
#define MATRIX_ROW_CAP 100
#define MATRIX_COL_CAP 100
#define MATRIX_MARK '#'

// Declaration
typedef struct
{
    char buffer[MATRIX_ROW_CAP][MATRIX_COL_CAP];
    int rowEff;
    int colEff;
} MatrixChar;

// Constructor
void createMatrix(MatrixChar *m, int nRows, int nCols);

// Display
void displayMatrix(MatrixChar m);

#endif