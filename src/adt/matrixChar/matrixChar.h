#ifndef MATRIXCHAR_H
#define MATRIXCHAR_H

#include "../boolean/boolean.h"

#define ROW_CAP 100
#define COL_CAP 100

typedef int IdxType;
typedef char ElType;
typedef struct
{
    ElType mem[ROW_CAP][COL_CAP];
    int rowEff;
    int colEff;
} Matrix;

// KONSTRUKTOR
void createMatrix(int nRows, int nCols, Matrix *m);

// SELEKTOR
#define ROW_EFF(M) (M).rowEff
#define COL_EFF(M) (M).colEff
#define ELMT(M, i, j) (M).mem[(i)][(j)]

// SELEKTOR
/// Setter
void setMatrixElmt(int i, int j, char val, Matrix *m);
/// Getter
ElType getMatrixElmt(int i, int j, Matrix m);

#endif