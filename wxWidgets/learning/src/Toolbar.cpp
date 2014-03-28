#include "Toolbar.h"

Toolbar::Toolbar(const wxString& title)
    : wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, wxSize(280, 180))
{
    wxImage::AddHandler(new wxPNGHandler);

    wxBitmap exit("email.png", wxBITMAP_TYPE_PNG);
    wxBitmap png1("warning.png", wxBITMAP_TYPE_PNG);
    wxBitmap png2("bar.png", wxBITMAP_TYPE_PNG);
    wxBitmap png3("pie.png", wxBITMAP_TYPE_PNG);

    /** Single toolbar
    wxToolBar *toolbar = CreateToolBar();
    toolbar->AddTool(wxID_EXIT, exit, "Exit Application");
    toolbar->AddSeparator();
    toolbar->Realize();
    */

    toolbar1 = new wxToolBar(this, wxID_ANY);
    toolbar1->AddTool(wxID_ANY, "1", png1);
    toolbar1->AddTool(wxID_ANY, "2", png2);
    toolbar1->AddTool(wxID_ANY, "3", png3);
    toolbar1->Realize();

    toolbar2 = new wxToolBar(this, wxID_ANY);
    toolbar2->AddTool(wxID_ANY, "", exit);
    toolbar2->Realize();

    wxBoxSizer *vbox = new wxBoxSizer(wxVERTICAL);
    vbox->Add(toolbar1, 0, wxEXPAND);
    vbox->Add(toolbar2, 0, wxEXPAND);

    SetSizer(vbox);

    Connect(wxID_EXIT, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler(Toolbar::OnQuit));

    Centre();
}

void Toolbar::OnQuit(wxCommandEvent& event)
{
    Close(true);
}
