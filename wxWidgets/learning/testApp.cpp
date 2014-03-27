/***************************************************************
 * Name:      testApp.cpp
 * Purpose:   Code for Application Class
 * Author:     ()
 * Created:   2014-03-26
 * Copyright:  ()
 * License:
 **************************************************************/

#include "testApp.h"

//(*AppHeaders
#include "Simple.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(testApp);

bool testApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	Simple* Frame = new Simple(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}
