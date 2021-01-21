﻿#include <MainFrame.h>


wxBEGIN_EVENT_TABLE(MainFrame, wxFrame)
    EVT_MENU(ID_OpenA,          MainFrame::OnOpenFile)
    EVT_MENU(ID_OpenB,          MainFrame::OnOpenFile)
    EVT_MENU(ID_SaveA,          MainFrame::OnSaveFile)
    EVT_MENU(ID_SaveB,          MainFrame::OnSaveFile)
    EVT_MENU(ID_TA,             MainFrame::OnTranspose)
    EVT_MENU(ID_TB,             MainFrame::OnTranspose)
    EVT_MENU(ID_Add,            MainFrame::OnOperation)
    EVT_MENU(ID_Subtract,       MainFrame::OnOperation)
    EVT_MENU(ID_Subtract_alt,   MainFrame::OnOperation)
    EVT_MENU(ID_Multiply,       MainFrame::OnOperation)
    EVT_MENU(ID_Multiply_alt,   MainFrame::OnOperation)
    EVT_MENU(wxID_EXIT,         MainFrame::OnExit)
    EVT_MENU(wxID_ABOUT,        MainFrame::OnAbout)
wxEND_EVENT_TABLE()

MainFrame::MainFrame(const wxString& title, const wxPoint& pos, const wxSize& size)
        : wxFrame(NULL, wxID_ANY, title, pos, size)
{
    // =======================
    //  ogólne własności okna
    // =======================

    SetMinSize(wxSize(600, 250));
    CreateStatusBar();
    SetStatusText("gotowość");

    // =====================
    //  pasek menu na górze
    // =====================

    // menu Plik
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

    // menu Edytuj
    wxMenu *menuEdit = new wxMenu;
    menuEdit->Append(ID_Add,"&Dodaj","Dodaj macierze A i B.");
        wxMenu *submenuSubtract = new wxMenu;
        submenuSubtract->Append(ID_Subtract,"&A - B","Odejmij macierz B od A (A-B)");
        submenuSubtract->Append(ID_Subtract_alt,"&B - A","Odejmij macierz A od B (B-A)");
    menuEdit->Append(wxID_ANY,"&Odejmij",submenuSubtract,"Odejmij macierze A od B lub na odwrót.");
        wxMenu *submenuMultiply = new wxMenu;
        submenuMultiply->Append(ID_Multiply,"&A x B","Pomnóż macierz A przez macierz B");
        submenuMultiply->Append(ID_Multiply_alt,"&B x A","Pomnóż macierz B przez macierz A");
    menuEdit->Append(wxID_ANY,"Po&mnóż",submenuMultiply,"Pomnóż macierze A i B.");
    menuEdit->AppendSeparator();
    wxMenu *submenuTranspose = new wxMenu;
        submenuTranspose->Append(ID_TA,"macierz &A","Otwórz plik i zapisz na miejsce macierzy A.");
        submenuTranspose->Append(ID_TB,"macierz &B","Otwórz plik i zapisz na miejsce macierzy B.");
    menuEdit->Append(wxID_ANY,"&Transponuj",submenuTranspose,"transponuj macierz...");

    // menu Pomoc
    wxMenu *menuHelp = new wxMenu;
    menuHelp->Append(wxID_ABOUT,"&O kalkulatorze");
    menuHelp->Append(wxID_ABOUT,"&Pomoc");

    // menu główne
    wxMenuBar *menuBar = new wxMenuBar;
    menuBar->Append( menuFile, "&Plik" );
    menuBar->Append( menuEdit, "&Edycja" );
    menuBar->Append( menuHelp, "P&omoc" );
    SetMenuBar( menuBar );

    // ====================
    //  Przestrzeń robocza
    // ====================
    
    // Panel macierzy A
}

void MainFrame::OnOpenFile(wxCommandEvent& event)
{
    wxFileDialog openDialog(this, "Otwórz macierz", wxGetCwd(), "","Pliki tekstowe(*.txt)|*.txt|Pliki macierzy(*.mat)|*.mat",
     wxFD_OPEN|wxFD_FILE_MUST_EXIST);
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
    event.Skip();
}

void MainFrame::OnSaveFile(wxCommandEvent& event)
{
    wxFileDialog saveDialog(this, "Zapisz macierz", wxGetCwd(), "","Pliki tekstowe(*.txt)|*.txt|Pliki macierzy(*.mat)|*.mat",
     wxFD_SAVE|wxFD_OVERWRITE_PROMPT);
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
    event.Skip();
}

void MainFrame::OnTranspose(wxCommandEvent& event)
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
    event.Skip();
}

void MainFrame::OnOperation(wxCommandEvent& event)
{
    if(a_good && b_good)
    {
        int id = event.GetId();
        try
        {
            if(id==ID_Add)
                result = a_mat + b_mat;
            else if(id==ID_Subtract)
                result = a_mat - b_mat;
            else if(id==ID_Subtract_alt)
                result = b_mat - a_mat;
            else if(id==ID_Multiply)
                result = a_mat * b_mat;
            else if(id==ID_Multiply_alt)
                result = b_mat * a_mat;
        }
        catch(exception &e)
        {
            wxMessageBox(nd,e.what(),wxOK | wxICON_INFORMATION);
        }
        
        ResultFrame* rf = new ResultFrame(this, "Mini Kalkulator Macierzy", wxPoint(50, 50), wxSize(450, 250),result,a_mat,b_mat);
    	rf->Show();
    }
    else
    {
        if(!a_good && !b_good)
        {
            wxMessageBox(nd,"Macierze A i B są puste.",wxOK | wxICON_INFORMATION);
        }
        else if(a_good)
        {
            wxMessageBox(nd,"Macierz B jest pusta.",wxOK | wxICON_INFORMATION);
        }
        else
        {
            wxMessageBox(nd,"Macierz A jest pusta.",wxOK | wxICON_INFORMATION);
        }
    }
    event.Skip();
}

void MainFrame::OnExit(wxCommandEvent& event)
{
    Close( true );
}
void MainFrame::OnAbout(wxCommandEvent& event)
{
    wxMessageBox( "Mini Kalkulator Macierzy v.1.0\nautor: Przemysław Kożuch\nStworzony z pomocą darmowej biblioteki wxWidgets.",
                  "O kalkulatorze", wxOK | wxICON_INFORMATION );
    a_mat = Matrix(4,3);
    a_mat.set(0,0,42);
    event.Skip();
}
void MainFrame::OnHello(wxCommandEvent& event)
{
    wxLogMessage("DEBUG EVENT!");
    event.Skip();
}