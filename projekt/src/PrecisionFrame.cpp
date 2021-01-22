#include <PrecisionFrame.h>

wxBEGIN_EVENT_TABLE(PrecisionFrame, wxDialog)
    EVT_BUTTON(ID_OKBT, PrecisionFrame::OnOKClicked)
wxEND_EVENT_TABLE()

PrecisionFrame::PrecisionFrame(wxWindow *parent, const wxString& title, const wxPoint& pos, const wxSize& size, long style, int &precision)
    : wxDialog(parent, wxID_ANY, title, pos, size, style)
{
    //this->SetWindowStyleFlag(wx | wxRESIZE_BORDER);
    this->precision=precision;
    SetMinSize(wxSize(80,100));
    wxPanel *panel = new wxPanel(this);
    wxBoxSizer *layout = new wxBoxSizer(wxVERTICAL);

    prec = new wxTextCtrl(panel,ID_PREC,wxString::Format(wxT("%d"),precision),wxDefaultPosition,wxDefaultSize,
    0,wxIntegerValidator<int>(&precision,0));
    
    wxButton *OKBTN = new wxButton(panel,ID_OKBT,"OK",wxDefaultPosition,wxDefaultSize);

    layout->Add(prec,0,wxEXPAND|wxALL,5);
    layout->Add(OKBTN,0,wxTOP|wxALL,5);

    panel->SetSizer(layout);
    layout->Layout();
}

void PrecisionFrame::OnOKClicked(wxCommandEvent &evt)
{
    prec->GetValidator()->TransferFromWindow();
    if(precision<0||precision>9)
    {
        wxMessageBox("Precyzja musi być nieujemna i mniejsza od 10.","Nieprawidłowa precyzja",wxICON_INFORMATION|wxOK);
        precision = 0;
        prec->GetValidator()->TransferToWindow();
        evt.Skip();
    }
    else
    {
        Close(this);
    }
}
