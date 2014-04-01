#include "main.h"
#include "Simple.h"
#include "Icon.h"
#include "Button.h"
#include "Communicate.h"
#include "Menu.h"
#include "Toolbar.h"
#include "Absolute.h"
#include "Border.h"

IMPLEMENT_APP(myApp)

bool myApp::OnInit()
{
    //Simple *simple = new Simple("Simple Title");
    //simple->Show();

    //Icon *icon = new Icon("Frame with Icon");
    //icon->Show();

    //Button *button = new Button("Button Frame");
    //button->Show();

    //Communicate *comm = new Communicate("Communicate Test");
    //comm->Show();

    //SimpleMenu *menu = new SimpleMenu("Menu Test");
    //menu->Show();

    //SubMenu *menu = new SubMenu("SubMenu Test");
    //menu->Show();

    //Toolbar *toolbar = new Toolbar("Toolbar Test");
    //toolbar->Show();

    //Absolute *absolute = new Absolute("Absolute layout");
    //absolute->Show();

    Border *border = new Border("Border BoxSizer");
    border->Show();

    return true;
}
