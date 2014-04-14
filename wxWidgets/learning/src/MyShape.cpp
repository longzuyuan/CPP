#include "MyShape.h"

MyShape::MyShape()
{
    int coordsTable[4][2] = { {-1, -1}, {-1, 0}, {0, 0}, {1, 0} };

    for (int i = 0; i < 4 ; i++) {
        for (int j = 0; j < 2; ++j)
            coords[i][j] = coordsTable[i][j];
    }
}
