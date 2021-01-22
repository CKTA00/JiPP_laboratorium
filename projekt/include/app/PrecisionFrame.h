#include <wx/wxprec.h>
#include <wx/filedlg.h>
#include <matrix.h>
#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif
#include <wx/valnum.h>
//#include <MainFrame.h>

#ifndef PRECISION_FRAME_H
#define PRECISION_FRAME_H

class PrecisionFrame: public wxDialog
{
    int precision;
    wxTextCtrl *prec;
    public:
        PrecisionFrame(wxWindow *parent, const wxString& title, const wxPoint& pos, const wxSize& size, long style, int &precision);
        void OnOKClicked(wxCommandEvent &evt);
    wxDECLARE_EVENT_TABLE();
};

enum
{
    ID_PREC = 600,
    ID_OKBT
};

#endif