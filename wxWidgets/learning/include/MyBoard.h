#ifndef MYBOARD_H
#define MYBOARD_H

#include <wx/wx.h>
#include <iostream>

class MyBoard : public wxPanel
{
    public:
        MyBoard(wxFrame * parent);

    private:
        enum { BoardWidth = 10, BoardHeight = 22 };

        void OnPaint(wxPaintEvent & event);
        void OnResize(wxSizeEvent & event);
        void OnTimer(wxCommandEvent & event);

        int SquareWidth() { return GetClientSize().GetWidth() / BoardWidth; }
        int SquareHeight() { return GetClientSize().GetHeight() / BoardHeight; }

        void DrawSquare(wxPaintDC &dc, int x, int y);

        int x,y;
        wxTimer * timer;
};

#endif // MYBOARD_H
