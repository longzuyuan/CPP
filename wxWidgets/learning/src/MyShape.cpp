#include "MyShape.h"

MyShape::MyShape()
{
    SetShape();
}

void MyShape::SetShape()
{
    int x = rand() % 7 + 1;

    static const int coordsTable[8][4][2] = {
        { { 0, 0 },   { 0, 0 },   { 0, 0 },   { 0, 0 } }, //No shape
        { { 0, -1 },  { 0, 0 },   { -1, 0 },  { -1, 1 } }, //S shape
        { { 0, -1 },  { 0, 0 },   { 1, 0 },   { 1, 1 } }, //Z shape
        { { 0, -1 },  { 0, 0 },   { 0, 1 },   { 0, 2 } }, //Line shape
        { { -1, 0 },  { 0, 0 },   { 1, 0 },   { 0, 1 } }, //T shape
        { { 0, 0 },   { 1, 0 },   { 0, 1 },   { 1, 1 } }, //Square Shape
        { { -1, -1 }, { 0, -1 },  { 0, 0 },   { 0, 1 } }, //Mirrored L Shape
        { { 1, -1 },  { 0, -1 },  { 0, 0 },   { 0, 1 } } //L shape
    };

    for (int i = 0; i < 4 ; i++) {
        for (int j = 0; j < 2; ++j)
            coords[i][j] = coordsTable[x][i][j];
    }
}


void MyShape::RotateLeft()
{

    for (int i = 0; i < 4 ; i++) {
        int tmp = coords[i][0];
        coords[i][0] = coords[i][1];
        coords[i][1] = -tmp;
    }
}
