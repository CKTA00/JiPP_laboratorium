#include <wx/wxprec.h>
#include <wx/filedlg.h>
#include <matrix.h>
#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif
class MyApp: public wxApp
{
public:
    virtual bool OnInit();
};
class MyFrame: public wxFrame
{
public:
    MyFrame(const wxString& title, const wxPoint& pos, const wxSize& size);
    Matrix a_mat = Matrix(5);
    Matrix b_mat = Matrix(5);
private:
    void OnHello(wxCommandEvent& event);
    void OnExit(wxCommandEvent& event);
    void OnAbout(wxCommandEvent& event);

    void OnOpenFile(wxCommandEvent& event);
    void OnSaveFile(wxCommandEvent& event);
    void OnTranspose(wxCommandEvent& event);
    wxDECLARE_EVENT_TABLE();
};
enum
{
    ID_Open = 1,
    ID_OpenA,
    ID_OpenB,
    ID_Save,
    ID_SaveA,
    ID_SaveB,
    ID_T,
    ID_TA,
    ID_TB
};
wxBEGIN_EVENT_TABLE(MyFrame, wxFrame)
    EVT_MENU(ID_OpenA,   MyFrame::OnOpenFile)
    EVT_MENU(ID_OpenB,   MyFrame::OnOpenFile)
    EVT_MENU(ID_SaveA,   MyFrame::OnSaveFile)
    EVT_MENU(ID_SaveB,   MyFrame::OnSaveFile)
    EVT_MENU(ID_TA,   MyFrame::OnTranspose)
    EVT_MENU(ID_TB,   MyFrame::OnTranspose)
    EVT_MENU(wxID_EXIT,  MyFrame::OnExit)
    EVT_MENU(wxID_ABOUT, MyFrame::OnAbout)
wxEND_EVENT_TABLE()
wxIMPLEMENT_APP(MyApp);
bool MyApp::OnInit()
{
    MyFrame *frame = new MyFrame( "Hello World", wxPoint(50, 50), wxSize(450, 340) );
    
    frame->Show( true );
    return true;
}
MyFrame::MyFrame(const wxString& title, const wxPoint& pos, const wxSize& size)
        : wxFrame(NULL, wxID_ANY, title, pos, size)
{
    wxMenu *menuFile = new wxMenu;
        wxMenu *submenuOpen = new wxMenu;
        submenuOpen->Append(ID_OpenA,"macierz &A","Otwórz plik i zapisz na miejsce macierzy A.");
        submenuOpen->Append(ID_OpenB,"macierz &B","Otwórz plik i zapisz na miejsce macierzy B.");
    menuFile->Append(ID_Open, "&Otwórz...",submenuOpen,"Otwórz plik z macierzą...");
        wxMenu *submenuSave = new wxMenu;
        submenuSave->Append(ID_SaveA,"macierz &A","Zapisz macierz A jako...");
        submenuSave->Append(ID_SaveB,"macierz &B","Zapisz macierz B jako...");
    menuFile->Append(ID_Save, "&Zapisz...",submenuSave,"Zapisz plik z macierzą...");
    menuFile->AppendSeparator();
    menuFile->Append(wxID_EXIT,"Za&kończ","Zamknij program.");

    wxMenu *menuEdit = new wxMenu;
        wxMenu *submenuTranspose = new wxMenu;
        submenuTranspose->Append(ID_TA,"macierz &A","Otwórz plik i zapisz na miejsce macierzy A.");
        submenuTranspose->Append(ID_TB,"macierz &B","Otwórz plik i zapisz na miejsce macierzy B.");
    menuEdit->Append(ID_T,"&Transponuj",submenuTranspose,"transponuj macierz...");
    wxMenu *menuHelp = new wxMenu;
    menuHelp->Append(wxID_ABOUT,"&O kalkulatorze");
    menuHelp->Append(wxID_ABOUT,"&Pomoc");

    wxMenuBar *menuBar = new wxMenuBar;
    menuBar->Append( menuFile, "&Plik" );
    menuBar->Append( menuEdit, "&Edycja" );
    menuBar->Append( menuHelp, "P&omoc" );
    SetMenuBar( menuBar );

    CreateStatusBar();
    SetStatusText("gotowość");
}

void MyFrame::OnOpenFile(wxCommandEvent& event)
{
    wxFileDialog openDialog(this, "Otwórz macierz", wxGetCwd(), "","Pliki tekstowe(*.txt)|*.txt|Pliki macierzy(*.mat)|*.mat", wxFD_OPEN|wxFD_FILE_MUST_EXIST);
    if (openDialog.ShowModal() == wxID_CANCEL) return;
    wxString path = openDialog.GetPath();
    wxString filename = openDialog.GetFilename();
    if(path.IsEmpty())
    {
        wxMessageBox("Nie wskazano pliku do otwarcia.","Niepowodzenie otwarcia",wxOK | wxICON_ASTERISK);
    }

    if(event.GetId()==ID_OpenA){
        a_mat = Matrix(path.ToStdString());
    }else{
        b_mat = Matrix(path.ToStdString());
    }
}

void MyFrame::OnSaveFile(wxCommandEvent& event)
{
    wxFileDialog saveDialog(this, "Zapisz macierz", wxGetCwd(), "","Pliki tekstowe(*.txt)|*.txt|Pliki macierzy(*.mat)|*.mat", wxFD_SAVE|wxFD_OVERWRITE_PROMPT);
    if (saveDialog.ShowModal() == wxID_CANCEL) return;
    wxString path = saveDialog.GetPath();
    wxString filename = saveDialog.GetFilename();
    if(filename.IsEmpty())
    {
        wxMessageBox("Nie nazwano pliku.","Niepowodzenie zapisu",wxOK | wxICON_ASTERISK);
    }

    if(event.GetId()==ID_SaveA){
        a_mat.save(path.ToStdString());
    }else{
        b_mat.save(path.ToStdString());
    }
}
void MyFrame::OnTranspose(wxCommandEvent& event)
{
    if(event.GetId()==ID_TA)
    {
        try {
            a_mat = a_mat.transpose();
        }
        catch(const exception& e){
            wxMessageBox(e.what(),"Błąd funkcji transpozycji - macierz A",wxOK | wxICON_ERROR);
            a_mat = Matrix(5,5);
        }
    }
    else
    {
        try{
            b_mat = b_mat.transpose();
        }
        catch(const exception& e){
            wxMessageBox(e.what(),"Błąd funkcji transpozycji - macierz B",wxOK | wxICON_ERROR);
            b_mat = Matrix(5,5);
        }
    }
}

void MyFrame::OnExit(wxCommandEvent& event)
{
    Close( true );
}
void MyFrame::OnAbout(wxCommandEvent& event)
{
    wxMessageBox( "Mini Kalkulator Macierzy v.1.0\nautor: Przemysław Kożuch\nStworzony z pomocą darmowej biblioteki wxWidgets.",
                  "O kalkulatorze", wxOK | wxICON_INFORMATION );
    a_mat = Matrix(4,3);
    a_mat.set(0,0,42);
}
void MyFrame::OnHello(wxCommandEvent& event)
{
    wxLogMessage("DEBUG EVENT!");
}