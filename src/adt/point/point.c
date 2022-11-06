#include <stdio.h>

#include "point.h"

void createPoint(Point *p, int X, int Y)
{
    (*p).X = X;
    (*p).Y = Y;
}