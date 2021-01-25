#include <ResultFrame.h>

wxBEGIN_EVENT_TABLE(ResultFrame, wxDialog)
    EVT_BUTTON(ID_Back,      ResultFrame::OnBackClicked)
    EVT_BUTTON(ID_File,      ResultFrame::OnFileClicked)
    EVT_BUTTON(ID_ReplaceA,      ResultFrame::OnReplaceClicked)
    EVT_BUTTON(ID_ReplaceB,      ResultFrame::OnReplaceClicked)
wxEND_EVENT_TABLE()

ResultFrame::ResultFrame(wxWindow *parent, const wxString& title, const wxPoint& pos, const wxSize& size, long style,
            Matrix &result, Matrix &mat_a, Matrix &mat_b, int precision)
: wxDialog(parent, wxID_ANY, title, pos, size, style)
{
    // OGÓLNE:
    this->result = &result;
    this->mat_a = &mat_a;
    this->mat_b = &mat_b;
    SetMinSize(wxSize(450, 200));
    wxPanel *mainPanel = new wxPanel(this);
    wxBoxSizer *mainLayout = new wxBoxSizer(wxVERTICAL);
    
    // MACIERZ (utworzenie elementów gui):
    wxPanel *gridPanel = new wxPanel(mainPanel,wxID_ANY,wxDefaultPosition,wxSize(200,160));
    wxGridSizer *grid = new wxGridSizer(5,5,0,0);
    ui_matrix = new wxTextCtrl*[25];  
    for(int x = 0; x < 5; ++x)
    {
        for(int y = 0; y < 5; ++y)
        {
            ui_matrix[5*y+x] = new wxTextCtrl(gridPanel,1000 + (5*y+x),"",wxDefaultPosition,wxDefaultSize,wxTE_PROCESS_TAB|wxTE_READONLY|wxTE_CENTRE);
            ui_matrix[5*y+x]->Enable(false);
            grid->Add(ui_matrix[5*y+x], 1, wxEXPAND | wxALL);
        }
    }
    gridPanel->SetSizer(grid);
    grid->Layout();

    wxStaticText *infoT = new wxStaticText(mainPanel,wxID_ANY,"Macierz");
    if(result.displayable()) infoT->SetLabelText("Macierz Wynikowa");
    else infoT->SetLabelText("Macierz Wynikowa - zbyt duża by wyświetlić");

    // PRZYCISKI:
    wxPanel *buttonPanel = new wxPanel(mainPanel,wxID_ANY,wxDefaultPosition);//, wxPoint(200,50),wxSize(100,30)
    wxBoxSizer *buttonLayout = new wxBoxSizer(wxHORIZONTAL);
    wxButton *backBTN = new wxButton(buttonPanel,ID_Back,"Powrót");
    wxButton *fileBTN = new wxButton(buttonPanel,ID_File,"Zapisz do pliku");
    wxButton *replaceA_BTN = new wxButton(buttonPanel,ID_ReplaceA,"Zastąp macierz A");
    wxButton *replaceB_BTN = new wxButton(buttonPanel,ID_ReplaceB,"Zastąp macierz B");
    buttonLayout->Add(backBTN,4,wxEXPAND|wxALL);
    buttonLayout->Add(fileBTN,4,wxEXPAND|wxALL);
    buttonLayout->Add(replaceA_BTN,5,wxEXPAND|wxALL);
    buttonLayout->Add(replaceB_BTN,5,wxEXPAND|wxALL);
    buttonPanel->SetSizer(buttonLayout);
    buttonLayout->Layout();

    // OKNO GŁÓWNE
    mainLayout->Add(gridPanel,1,wxEXPAND|wxALL,5);
    mainLayout->Add(infoT,0,wxEXPAND|wxLEFT|wxRIGHT,5);
    mainLayout->Add(buttonPanel,0,wxEXPAND|wxALL,5);
    mainPanel->SetSizer(mainLayout);
    mainLayout->Layout();
    
    // MACIERZ (wpisanie danych):
    if(result.displayable())
    {
        for(int x = result.rows()-1; x >= 0; --x)
        {
            for(int y = result.cols()-1; y >= 0; --y)
            {
                ui_matrix[5*y+x]->Enable(true);
                ui_matrix[5*y+x]->SetLabelText(wxString::FromDouble	(result.get(x,y) , precision));
            }
        }
    }
}

// ZDARZENIA:

void ResultFrame::OnBackClicked(wxCommandEvent &event)
{
    Close( true );
}

void ResultFrame::OnFileClicked(wxCommandEvent &event)
{
    wxFileDialog saveDialog(this, "Zapisz rezulata", wxGetCwd(), "","Pliki tekstowe(*.txt)|*.txt|Pliki macierzy(*.mat)|*.mat",
     wxFD_SAVE|wxFD_OVERWRITE_PROMPT);
    if (saveDialog.ShowModal() == wxID_CANCEL) return;
    wxString path = saveDialog.GetPath();
    wxString filename = saveDialog.GetFilename();
    if(filename.IsEmpty())
    {
        wxMessageBox("Nie nazwano pliku.","Niepowodzenie zapisu",wxOK | wxICON_ASTERISK);
        event.Skip();
        return;
    }
    else
    {
        result->save(path.ToStdString());
        Close( true );
    }
}

void ResultFrame::OnReplaceClicked(wxCommandEvent &event)
{
    if(event.GetId()==ID_ReplaceA)
    {
        *(this->mat_a) = *(this->result);
    }
    else
    {
        *(this->mat_b) = *(this->result);
    }
    Close( true );
}