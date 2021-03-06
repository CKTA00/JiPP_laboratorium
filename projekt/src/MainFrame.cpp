﻿#include <MainFrame.h>

wxBEGIN_EVENT_TABLE(MainFrame, wxFrame)
    EVT_MENU(ID_NewA,           MainFrame::OnNew)
    EVT_MENU(ID_NewB,           MainFrame::OnNew)
    EVT_MENU(ID_NewBoth,        MainFrame::OnNew)
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
    EVT_BUTTON(ID_AddBT,          MainFrame::OnOperation)
    EVT_BUTTON(ID_SubtractBT,     MainFrame::OnOperation)
    EVT_BUTTON(ID_Subtract_altBT, MainFrame::OnOperation)
    EVT_BUTTON(ID_MultiplyBT,     MainFrame::OnOperation)
    EVT_BUTTON(ID_Multiply_altBT, MainFrame::OnOperation)
    EVT_MENU(ID_Precision,      MainFrame::OnPrecision)
    EVT_MENU(wxID_EXIT,         MainFrame::OnExit)
    EVT_MENU(wxID_ABOUT,        MainFrame::OnAbout)
wxEND_EVENT_TABLE()


// UKŁAD KONTROLEK:

MainFrame::MainFrame(const wxString& title, const wxPoint& pos, const wxSize& size)
        : wxFrame(NULL, wxID_ANY, title, pos, size)
{
    // =======================
    //  Ogólne własności okna
    // =======================

    SetMinSize(wxSize(420, 400));
    CreateStatusBar();
    SetStatusText("Gotowość.");
    wxPanel *mainPanel = new wxPanel(this);
    wxBoxSizer *mainLayout = new wxBoxSizer(wxVERTICAL);

    // =====================
    //  Pasek menu na górze
    // =====================
    
    // menu Plik
    wxMenu *menuFile = new wxMenu;
    wxMenu *submenuNew = new wxMenu;
        submenuNew->Append(ID_NewA,"macierz &A","Wyczyść macierz A.");
        submenuNew->Append(ID_NewB,"macierz &B","Wyczyść macierz B.");
        submenuNew->Append(ID_NewBoth,"&obie","Wyczyść obie macierze.");
    menuFile->Append(ID_Open, "&Nowa macierz",submenuNew,"Tworzy nową macierz 5 na 5");
        wxMenu *submenuOpen = new wxMenu;
        submenuOpen->Append(ID_OpenA,"macierz &A","Otwórz plik i zapisz na miejsce macierzy A.");
        submenuOpen->Append(ID_OpenB,"macierz &B","Otwórz plik i zapisz na miejsce macierzy B.");
    menuFile->Append(ID_Open, "&Otwórz",submenuOpen,"Otwórz plik z macierzą...");
        wxMenu *submenuSave = new wxMenu;
        submenuSave->Append(ID_SaveA,"macierz &A","Zapisz macierz A jako...");
        submenuSave->Append(ID_SaveB,"macierz &B","Zapisz macierz B jako...");
    menuFile->Append(ID_Save, "&Zapisz",submenuSave,"Zapisz plik z macierzą...");
    menuFile->AppendSeparator();
    menuFile->Append(ID_Precision,"&Ustaw precyzję...","Ustaw precyzję wyświetlania liczb w macierzach.");
    menuFile->AppendSeparator();
    menuFile->Append(wxID_EXIT,"Za&kończ","Zamknij program.");

    // menu Edytuj
    wxMenu *menuEdit = new wxMenu;
    menuEdit->Append(ID_Add,"&Dodaj","Dodaj macierze A i B.");
        wxMenu *submenuSubtract = new wxMenu;
        submenuSubtract->Append(ID_Subtract,"&A - B","Odejmij macierz B od A (A-B).");
        submenuSubtract->Append(ID_Subtract_alt,"&B - A","Odejmij macierz A od B (B-A).");
    menuEdit->Append(wxID_ANY,"&Odejmij",submenuSubtract,"Odejmij macierze A od B lub na odwrót.");
        wxMenu *submenuMultiply = new wxMenu;
        submenuMultiply->Append(ID_Multiply,"&A x B","Pomnóż macierz A przez macierz B.");
        submenuMultiply->Append(ID_Multiply_alt,"&B x A","Pomnóż macierz B przez macierz A.");
    menuEdit->Append(wxID_ANY,"Po&mnóż",submenuMultiply,"Pomnóż macierze A i B.");
    menuEdit->AppendSeparator();
    wxMenu *submenuTranspose = new wxMenu;
        submenuTranspose->Append(ID_TA,"macierz &A","Transponuj macierz A.");
        submenuTranspose->Append(ID_TB,"macierz &B","Transponuj macierz B.");
    menuEdit->Append(wxID_ANY,"&Transponuj",submenuTranspose,"transponuj macierz...");

    // menu Pomoc
    wxMenu *menuHelp = new wxMenu;
    menuHelp->Append(wxID_ABOUT,"&O kalkulatorze","Informacje o programie.");
    //menuHelp->Append(wxID_ABOUT,"&Pomoc");

    // menu główne
    wxMenuBar *menuBar = new wxMenuBar;
    menuBar->Append( menuFile, "&Plik" );
    menuBar->Append( menuEdit, "&Edycja" );
    menuBar->Append( menuHelp, "P&omoc" );
    SetMenuBar( menuBar );

    // =================
    //  Panele macierzy
    // =================
    
    wxPanel *workspacePanel = new wxPanel(mainPanel);
    wxGridSizer *workspaceLayout = new wxGridSizer(1,2,0,0);
    //wxBoxSizer *workspaceLayout = new wxBoxSizer(wxHORIZONTAL);
    ui_a = new UIMatrix(workspacePanel,&mat_a,1);
    ui_a->refresh("Macierz A");
    ui_b = new UIMatrix(workspacePanel,&mat_b,2);
    ui_b->refresh("Macierz B");
    workspaceLayout->Add(ui_a->getMainPanel(),1,wxEXPAND|wxALL,5);
    workspaceLayout->Add(ui_b->getMainPanel(),1,wxEXPAND|wxALL,5);
    workspaceLayout->Layout();
    workspacePanel->SetSizer(workspaceLayout);
    
    // ==================
    //  Panel przycisków
    // ==================

    wxPanel *buttonPanel = new wxPanel(mainPanel,wxID_ANY,wxDefaultPosition);
    wxBoxSizer *buttonLayout = new wxBoxSizer(wxHORIZONTAL);
    
    wxButton *addBTN = new wxButton(buttonPanel,ID_AddBT,"A + B",wxDefaultPosition,wxSize(50,50));
    wxButton *subtractBTN = new wxButton(buttonPanel,ID_SubtractBT,"A - B",wxDefaultPosition,wxSize(50,50));
    wxButton *subtractBTN_alt = new wxButton(buttonPanel,ID_Subtract_altBT,"B - A",wxDefaultPosition,wxSize(50,50));
    wxButton *multiplyBTN = new wxButton(buttonPanel,ID_MultiplyBT,"A x B",wxDefaultPosition,wxSize(50,50));
    wxButton *multiplyBTN_alt = new wxButton(buttonPanel,ID_Multiply_altBT,"B x A",wxDefaultPosition,wxSize(50,50));
    buttonLayout->Add(addBTN,0,0);
    buttonLayout->Add(subtractBTN,0,0);
    buttonLayout->Add(subtractBTN_alt,0,0);
    buttonLayout->Add(multiplyBTN,0,0);
    buttonLayout->Add(multiplyBTN_alt,0,0);
    buttonPanel->SetSizer(buttonLayout);
    buttonLayout->Layout();

    // =================================
    //  Rozmieszczenie na głównym oknie
    // =================================
    
    mainLayout->Add(workspacePanel,1,wxEXPAND|wxALL,5);
    mainLayout->Add(buttonPanel,0,wxALL,5);
    mainPanel->SetSizer(mainLayout);
    mainLayout->Layout();
    SendSizeEvent();
    ui_a->setPrecision(precision);
    ui_b->setPrecision(precision);
}

// ZDARZENIA:

void MainFrame::OnNew(wxCommandEvent& event)
{
    if(event.GetId()==ID_NewA)
    {
        mat_a = Matrix(5,5);
        ui_a->refresh("Macierz A");
    }
    else if(event.GetId()==ID_NewB)
    {
        mat_b = Matrix(5,5);
        ui_b->refresh("Macierz B");
    }
    else
    {
        mat_a = Matrix(5,5);
        mat_b = Matrix(5,5);
        ui_a->refresh("Macierz A");
        ui_b->refresh("Macierz B");
    }
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
        event.Skip();
        return;
    }

    if(event.GetId()==ID_OpenA){
        mat_a = Matrix(path.ToStdString());
        ui_a->refresh(filename);
    }else{
        mat_b = Matrix(path.ToStdString());
        ui_b->refresh(filename);
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
        event.Skip();
        return;
    }

    if(event.GetId()==ID_SaveA){
        mat_a.save(path.ToStdString());
    }else{
        mat_b.save(path.ToStdString());
    }
    event.Skip();
}

void MainFrame::OnTranspose(wxCommandEvent& event)
{
    if(event.GetId()==ID_TA)
    {
        try {
            mat_a = mat_a.transpose();
        }
        catch(const exception& e){
            wxMessageBox(e.what(),"Błąd funkcji transpozycji - macierz A",wxOK | wxICON_ERROR);
            mat_a = Matrix(5,5);
        }
        ui_a->refresh("T(A)");
    }
    else
    {
        try{
            mat_b = mat_b.transpose();
        }
        catch(const exception& e){
            wxMessageBox(e.what(),"Błąd funkcji transpozycji - macierz B",wxOK | wxICON_ERROR);
            mat_b = Matrix(5,5);
        }
        ui_b->refresh("T(B)");
    }
    event.Skip();
}

void MainFrame::OnOperation(wxCommandEvent& event)
{
    int id = event.GetId();
    try
    {
        if(id==ID_Add||id==ID_AddBT)
            result = mat_a + mat_b;
        else if(id==ID_Subtract||id==ID_SubtractBT)
            result = mat_a - mat_b;
        else if(id==ID_Subtract_alt||id==ID_Subtract_altBT)
            result = mat_b - mat_a;
        else if(id==ID_Multiply||id==ID_MultiplyBT)
            result = mat_a * mat_b;
        else if(id==ID_Multiply_alt||ID_Multiply_altBT)
            result = mat_b * mat_a;
    }
    catch(exception &e)
    {
        wxMessageBox(e.what(),nd,wxOK | wxICON_INFORMATION);
        event.Skip();
        return;
    }
    ResultFrame* rf = new ResultFrame(this, "Wynik działania", wxPoint(300, 300), wxSize(450, 250),wxDEFAULT_DIALOG_STYLE|wxRESIZE_BORDER,result,mat_a,mat_b,precision);
    rf->ShowModal();
    ui_a->refresh("Macierz A");
    ui_b->refresh("Macierz B");
    event.Skip();
}

void MainFrame::OnPrecision(wxCommandEvent& event)
{
    PrecisionFrame* pf = new PrecisionFrame(this,"Ustaw precyzje", wxPoint(300, 300), wxSize(160,120),wxDEFAULT_DIALOG_STYLE|wxRESIZE_BORDER, precision);
    //pf->ShowModal();
    pf->ShowWindowModal();
    ui_a->setPrecision(precision);
    ui_b->setPrecision(precision);
}

void MainFrame::OnExit(wxCommandEvent& event)
{
    Close( true );
}
void MainFrame::OnAbout(wxCommandEvent& event)
{
    wxMessageBox( "Mini Kalkulator Macierzy v.1.0\nautor: Przemysław Kożuch\nStworzony z pomocą darmowej biblioteki wxWidgets.",
                  "O kalkulatorze", wxOK | wxICON_INFORMATION );
    event.Skip();
}
