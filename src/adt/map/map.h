#ifndef MAP_H
#define MAP_H

#include "../../../config/config.h"
#include "../wordmachine/wordmachine.c"
#include "../matrixChar/matrixChar.c"

void setMapRow(MatrixChar *map, char rowContent[], int row);

void setMapDimension(int *mapRow, int *mapCol);

void setMapMatrix(MatrixChar *map);

void setMap(MatrixChar *map);

void renderMap(MatrixChar m);

#endif