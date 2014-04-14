#include "MyBoard.h"

MyBoard::MyBoard(wxFrame * parent)
    : wxPanel(parent, -1, wxDefaultPosition, wxDefaultSize, wxBORDER_NONE), x(4), y(0), curShape()
{
    for(int i=0; i<BoardWidth; i++) {
        for(int j=0; j<BoardHeight; j++) {
            board[j*BoardWidth + i] = 0;
        }
    }

    timer = new wxTimer(this, 1);

    Connect(wxEVT_PAINT, wxPaintEventHandler(MyBoard::OnPaint));
    Connect(wxEVT_SIZE, wxSizeEventHandler(MyBoard::OnResize));
    Connect(wxEVT_TIMER, wxCommandEventHandler(MyBoard::OnTimer));
    Connect(wxEVT_KEY_DOWN, wxKeyEventHandler(MyBoard::OnKeyDown));

    timer->Start(300);
}

void MyBoard::OnPaint(wxPaintEvent & event)
{
    wxPaintDC dc(this);

    for(int i=0; i<BoardWidth; i++) {
        for(int j=0; j<BoardHeight; j++) {
            if(board[j*BoardWidth + i] == 1) {
                DrawSquare(dc, i, j);
            }
        }
    }

    for(int i=0; i<4; i++) {
        DrawSquare(dc, x+curShape.coords[i][0], y+curShape.coords[i][1]);
    }

}

void MyBoard::OnResize(wxSizeEvent & event)
{
    Refresh();
}

void MyBoard::OnTimer(wxCommandEvent & event)
{
    Refresh();


    //for(int i=0; i<4; i++) {
    //    if(curShape.coords[i][])
    //}

    if((y < BoardHeight-1) && (board[(y+2)*BoardWidth + x] != 1)) {
        y++;
    } else {
        for(int i=0; i<4; i++) {
            board[(y+curShape.coords[i][1])*BoardWidth + x + curShape.coords[i][0]] = 1;
        }
        x = 4; y = 0;
    }
}

void MyBoard::OnKeyDown(wxKeyEvent & event)
{
    int keyCode = event.GetKeyCode();

    switch(keyCode) {
        //case WXK_LEFT: TryMove(); break;
    }
}

void MyBoard::DrawSquare(wxPaintDC &dc, int x, int y)
{
    x = x*SquareWidth();
    y = y*SquareHeight();
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
