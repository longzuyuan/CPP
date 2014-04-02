#include <stdlib.h>
#include <algorithm>
#include "Shape.h"

using namespace std;

void Shape::SetShape(Tetrominoes shape)
{
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
            coords[i][j] = coordsTable[shape][i][j];
    }
    pieceShape = shape;
}



void Shape::SetRandomShape()
{
  int x = rand() % 7 + 1;
  SetShape(Tetrominoes(x));
}

int Shape::MinX() const
{
  int m = coords[0][0];
  for (int i=0; i<4; i++) {
      m = min(m, coords[i][0]);
  }
  return m;
}

int Shape::MaxX() const
{
  int m = coords[0][0];
  for (int i=0; i<4; i++) {
      m = max(m, coords[i][0]);
  }
  return m;
}

int Shape::MinY() const
{
  int m = coords[0][1];
  for (int i=0; i<4; i++) {
      m = min(m, coords[i][1]);
  }
  return m;
}

int Shape::MaxY() const
{
  int m = coords[0][1];
  for (int i=0; i<4; i++) {
      m = max(m, coords[i][1]);
  }
  return m;
}

Shape Shape::RotateLeft() const
{
    if (pieceShape == SquareShape)
        return *this;

    Shape result;
    result.pieceShape = pieceShape;
    for (int i = 0; i < 4; ++i) {
        result.SetX(i, y(i)); // coords[index][0] = coords[index][1]; -> x = y;
        result.SetY(i, -x(i)); // coords[index][1] = - coords[index][0]; -> y = -x
    }
    return result;
}

Shape Shape::RotateRight() const
{
    if (pieceShape == SquareShape)
        return *this;

    Shape result;
    result.pieceShape = pieceShape;
    for (int i = 0; i < 4; ++i) {
        result.SetX(i, -y(i));
        result.SetY(i, x(i));
    }
    return result;
}
