#include "MyBoard.h"

MyBoard::MyBoard(wxFrame * parent)
    : wxPanel(parent, -1, wxDefaultPosition, wxDefaultSize, wxBORDER_NONE), x(4), y(0), score(0), curShape()
{
    sb = parent->GetStatusBar();
    sb->SetStatusText(wxT("0"));

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
    status = 1;
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
    //判断有没有到底
    bool stop = false;
    for(int i=0; i<4; i++) {
        if(board[(curShape.coords[i][1] + y + 1) * BoardWidth + x + curShape.coords[i][0]] == 1) stop = true;
        if(y + curShape.coords[i][1] >= BoardHeight-1) stop = true;
    }

    //往下移动，如果到底修改board
    if(!stop) {
        y++;
    } else {
        for(int i=0; i<4; i++) {
            board[(curShape.coords[i][1] + y) * BoardWidth + x + curShape.coords[i][0]] = 1;
        }

        RemoveFullLine();

        x = 4; y = 0;
        curShape.SetShape();
    }

    Refresh();
}

void MyBoard::RemoveFullLine()
{
    for(int j=BoardHeight-1; j>0; j--)
    {
        bool isFull = true;
        for(int i=0; i<BoardWidth; i++)
        {
            if(ShapeAt(i, j) == 0) isFull = false;
        }
        if(isFull) {
            for(int k=j; k>0; k--)
            {
                for(int i=0; i<BoardWidth; i++)
                    ShapeAt(i, k) = ShapeAt(i, k-1);
            }
            score += 10;
            wxString str;
            str.Printf(wxT("%d"), score);
            sb->SetStatusText(str);
        }
    }

    for(int i=0; i<BoardWidth; i++)
    {
        int t = ShapeAt(i, 0);
        if(ShapeAt(i, 0) != 0) {
            wxString str;
            str.Printf(wxT("Game Over! Final score: %d"), score);
            sb->SetStatusText(str);
            timer->Stop();
            status = 0;
        }
    }
}

void MyBoard::OnKeyDown(wxKeyEvent & event)
{
    int keyCode = event.GetKeyCode();

    if(status == 0) return;

    switch(keyCode) {
        case WXK_LEFT: TryMove(x-1, y); break;
        case WXK_RIGHT: TryMove(x+1, y); break;
        case WXK_DOWN: TryMove(x, y+1); break;
        case WXK_UP: curShape.RotateLeft(); Refresh(); break;
    }
}

void MyBoard::TryMove(int tmpX, int tmpY)
{
    for(int i=0; i<4; i++) {
        if((curShape.coords[i][0] + tmpX) < 0 || (curShape.coords[i][0] + tmpX) >= BoardWidth) return;
        if((curShape.coords[i][1] + tmpY) < 0 || (curShape.coords[i][1] + tmpY) >= BoardHeight) return;
        if(board[(curShape.coords[i][1] + tmpY) * BoardWidth + tmpX + curShape.coords[i][0]] == 1) return;
    }

    timer->Stop();
    x = tmpX;
    y = tmpY;

    Refresh();
    timer->Start(300);
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
