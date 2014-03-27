#include "Button.h"

Button::Button(const wxString& title)
    : wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, wxSize(400, 300))
{
    wxPanel *panel = new wxPanel(this, wxID_ANY);

    wxButton *button = new wxButton(panel, wxID_EXIT, "Close", wxPoint(120, 20));
    Connect(wxID_EXIT, wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(Button::OnQuit));

    button->SetFocus();

    Centre();
}

void Button::OnQuit(wxCommandEvent & event)
{
    Close(true);
}
