#include <stdio.h>

#include "../../adt/map/map.c"

int main()
{
    // Map
    Matrix map;
    setMap(&map);
    renderMap(map);

    return 0;
}