#ifndef MYSHAPE_H
#define MYSHAPE_H

#include <cstdlib>

class MyShape
{
    public:
        MyShape();
        int x(int i) { return coords[i][0]; };
        int y(int i) { return coords[i][1]; };

        void RotateLeft();
        void SetShape();

    private:
        int coords[4][2];

};

#endif // MYSHAPE_H
