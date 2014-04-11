#include "MyBoard.h"

MyBoard::MyBoard(wxFrame * parent)
    : wxPanel(parent, -1, wxDefaultPosition, wxDefaultSize, wxBORDER_NONE), x(3), y(0)
{
    timer = new wxTimer(this, 1);

    Connect(wxEVT_PAINT, wxPaintEventHandler(MyBoard::OnPaint));
    Connect(wxEVT_SIZE, wxSizeEventHandler(MyBoard::OnResize));
    Connect(wxEVT_TIMER, wxCommandEventHandler(MyBoard::OnTimer));

    timer->Start(500);
}

void MyBoard::OnPaint(wxPaintEvent & event)
{
    wxPaintDC dc(this);

    DrawSquare(dc, x*SquareWidth(), y*SquareHeight());
    DrawSquare(dc, (x+1)*SquareWidth(), y*SquareHeight());
    DrawSquare(dc, (x+2)*SquareWidth(), y*SquareHeight());
    DrawSquare(dc, (x+2)*SquareWidth(), (y+1)*SquareHeight());

}

void MyBoard::OnResize(wxSizeEvent & event)
{
    Refresh();
}

void MyBoard::OnTimer(wxCommandEvent & event)
{
    Refresh();
    y++;
}

void MyBoard::DrawSquare(wxPaintDC &dc, int x, int y)
{
    //light
    wxPen pen(wxColor(248, 159, 171));
    pen.SetCap(wxCAP_PROJECTING);
    dc.SetPen(pen);
    dc.DrawLine(x, y, x+SquareWidth()-1, y);
    dc.DrawLine(x, y, x, y+SquareHeight()-1);

    //dark
    wxPen darkPen(wxColor(128, 59, 59));
    darkPen.SetCap(wxCAP_PROJECTING);
    dc.SetPen(darkPen);
    dc.DrawLine(x+SquareWidth()-1, y+SquareHeight()-1, x, y+SquareHeight()-1);
    dc.DrawLine(x+SquareWidth()-1, y+SquareHeight()-1, x+SquareWidth()-1, y);

    //fill
    dc.SetPen(*wxTRANSPARENT_PEN);
    dc.SetBrush(wxBrush(wxColor(204, 102, 102)));
    dc.DrawRectangle(x+1, y+1, SquareWidth()-2, SquareHeight()-2);

}
