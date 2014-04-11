#include "MyTetris.h"

MyTetris::MyTetris(const wxString & title)
    : wxFrame(NULL, -1, title, wxDefaultPosition, wxSize(180, 380))
{
    MyBoard * board = new MyBoard(this);
    board->SetFocus();

    Centre();
}

