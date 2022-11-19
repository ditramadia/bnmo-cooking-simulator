#ifndef MAP_H
#define MAP_H

#include "../matrixChar/matrixChar.h"

void setMapRow(MatrixChar *map, char rowContent[], int row);

void setMapDimension(int *mapRow, int *mapCol);

void setMapMatrix(MatrixChar *map);

void setMap(MatrixChar *map);

void renderMap(MatrixChar m);

#endif