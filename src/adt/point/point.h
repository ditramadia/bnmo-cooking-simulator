#ifndef POINT_H
#define POINT_H

// Declaration
typedef struct
{
    int X;
    int Y;
} Point;

// Constructor
void createPoint(Point *p, int X, int Y);

#endif