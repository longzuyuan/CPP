#ifndef MYBOARD_H
#define MYBOARD_H

#include <wx/wx.h>
#include <iostream>
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

        void DrawSquare(wxPaintDC &dc, int x, int y);

        int x,y;
        MyShape curShape;
        wxTimer * timer;

        int board[BoardWidth * BoardHeight];
};

#endif // MYBOARD_H
