#ifndef MYBOARD_H
#define MYBOARD_H

#include <wx/wx.h>
#include <iostream>
#include <cmath>
#include "MyShape.h"

class MyBoard : public wxPanel
{
    public:
        MyBoard(wxFrame * parent);

    private:
        enum { BoardWidth = 10, BoardHeight = 22 };

        void OnPaint(wxPaintEvent & event);
        void OnResize(wxSizeEvent & event);
        void OnTimer(wxCommandEvent & event);
        void OnKeyDown(wxKeyEvent & event);

        int SquareWidth() { return GetClientSize().GetWidth() / BoardWidth; }
        int SquareHeight() { return GetClientSize().GetHeight() / BoardHeight; }

        int & ShapeAt(int i, int j) {return board[j*BoardWidth + i];}

        void TryMove(int i, int j);
        void DrawSquare(wxPaintDC &dc, int x, int y);
        void RemoveFullLine();

        int x,y;
        MyShape curShape;
        wxTimer * timer;
        wxStatusBar *sb;
        int score;
        int status; //1 on-going 2 pause 0 stop;

        int board[BoardWidth * BoardHeight];
};

#endif // MYBOARD_H
