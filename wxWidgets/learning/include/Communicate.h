#include <wx/wx.h>
#include "Panels.h"

class Communicate : public wxFrame
{
public:
    Communicate(const wxString& title);

    LeftPanel *m_lp;
    RightPanel *m_rp;
    wxPanel *m_parent;
};
