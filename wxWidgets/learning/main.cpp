#include "main.h"
#include "Simple.h"
#include "Icon.h"
#include "Button.h"
#include "Communicate.h"
#include "Menu.h"
#include "Toolbar.h"
#include "Absolute.h"
#include "Border.h"
#include "Align.h"
#include "GotoClass.h"
#include "NewFrame.h"
#include "GridSizer.h"
#include "Flexgridsizer.h"

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

    //Border *border = new Border("Border BoxSizer");
    //border->Show();

    //Align *align = new Align("BoxSizer align");
    //align->Show();

    //GotoClass *go = new GotoClass("Go to class");
    //go->Show();

    //NewFrame *nf = new NewFrame(NULL);
    //nf->Show();

    //GridSizer *gs = new GridSizer("Grid sizer");
    //gs->Show();

    FlexGridSizer *fgs = new FlexGridSizer("Flex Grid sizer");
    fgs->Show();

    return true;
}
