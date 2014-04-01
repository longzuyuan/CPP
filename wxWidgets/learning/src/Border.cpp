#include "Border.h"

Border::Border(const wxString & title)
    : wxFrame(NULL, -1, title, wxDefaultPosition, wxSize(250, 200))
{
    wxColour col1, col2;
    col1.Set("#4f5049");
    col2.Set("#ededed");

    wxPanel *panel = new wxPanel(this, -1);
    panel->SetBackgroundColour(col1);

    wxBoxSizer *vbox = new wxBoxSizer(wxVERTICAL);

    wxPanel *midPanel = new wxPanel(panel, wxID_ANY);
    midPanel->SetBackgroundColour(col2);

    vbox->Add(midPanel, 1, wxEXPAND | wxALL, 20);
    panel->SetSizer(vbox);

    Centre();
}
