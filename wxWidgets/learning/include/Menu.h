#include <wx/wx.h>

class SimpleMenu : public wxFrame
{
public:
    SimpleMenu(const wxString& title);

    void OnQuit(wxCommandEvent& event);

    wxMenuBar *menubar;
    wxMenu *menu_file;
};

class SubMenu : public wxFrame
{
public:
    SubMenu(const wxString& title);

    void OnQuit(wxCommandEvent& event);

    wxMenuBar *menubar;
    wxMenu *menu_file;
    wxMenu *menu_imp;
    wxMenuItem *mi_quit;

};
