#include "Align.h"

Align::Align(const wxString& title)
    : wxFrame(NULL, -1, title, wxDefaultPosition, wxSize(300, 200))
{
     wxPanel *panel = new wxPanel(this, -1);

     wxBoxSizer *vbox = new wxBoxSizer(wxVERTICAL);
     wxBoxSizer *hbox1 = new wxBoxSizer(wxHORIZONTAL);
     wxBoxSizer *hbox2 = new wxBoxSizer(wxHORIZONTAL);

     wxButton *ok = new wxButton(panel, -1, "OK");
     wxButton *cancel = new wxButton(panel, -1, "Cancel");

     hbox1->Add(new wxPanel(panel, -1));
     vbox->Add(hbox1, 1, wxEXPAND);

     hbox2->Add(ok);
     hbox2->Add(cancel);

     vbox->Add(hbox2, 0, wxALIGN_RIGHT | wxRIGHT | wxBOTTOM, 10);
     panel->SetSizer(vbox);

     Centre();
}

