#include <stdio.h>
#include <stdlib.h>

#include "matrixChar.h"

// Konstruktor
void createMatrix(int nRows, int nCols, Matrix *m)
{
    ROW_EFF(*m) = nRows;
    COL_EFF(*m) = nCols;
}

// Selektor
/// Setter
void setMatrixElmt(int i, int j, char val, Matrix *m)
{
    ELMT(*m, i, j) = val;
}
/// Getter
ElType getMatrixElmt(int i, int j, Matrix m)
{
    return ELMT(m, i, j);
}