#include "Menu.h"

SimpleMenu::SimpleMenu(const wxString& title)
    : wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, wxSize(280, 180))
{
    menubar = new wxMenuBar;
    menu_file = new wxMenu;
    menu_file->Append(wxID_EXIT, "&Quit");
    menubar->Append(menu_file, "нд╪Ч(&F)");
    SetMenuBar(menubar);

    Connect(wxID_EXIT, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(SimpleMenu::OnQuit));

    this->Centre();
}

void SimpleMenu::OnQuit(wxCommandEvent& event)
{
    Close(true);
}


SubMenu::SubMenu(const wxString& title)
    : wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, wxSize(280, 180))
{
    menubar = new wxMenuBar;
    menu_file = new wxMenu;

    menu_file->Append(wxID_ANY, "&New");
    menu_file->Append(wxID_ANY, "&Open");
    menu_file->Append(wxID_ANY, "&Save");
    menu_file->AppendSeparator();

    menu_imp = new wxMenu;
    menu_imp->Append(wxID_ANY, "Import 1");
    menu_imp->Append(wxID_ANY, "Import 2");

    menu_file->AppendSubMenu(menu_imp, "&Import");

    mi_quit = new wxMenuItem(menu_file, wxID_EXIT, "&Quit\tCtrl+W");
    menu_file->Append(mi_quit);

    menubar->Append(menu_file, "&File");

    Connect(wxID_EXIT, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(SubMenu::OnQuit));

    SetMenuBar(menubar);
    Centre();
}

void SubMenu::OnQuit(wxCommandEvent& event)
{
    Close(true);
}
