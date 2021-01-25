#include <wx/wxprec.h>
#include <wx/filedlg.h>
#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif
#include <wx/dialog.h>

#include <matrix.h>
#include <ResultFrame.h>
#include <UIMatrix.h>
#include <PrecisionFrame.h>


#ifndef MAIN_FRAME_H
#define MAIN_FRAME_H

class MainFrame: public wxFrame
{
public:
    MainFrame(const wxString& title, const wxPoint& pos, const wxSize& size);
private:
    // dane macierzy A (lewej)
    Matrix mat_a = Matrix(5);
    // dane macierzy B (prawej)
    Matrix mat_b = Matrix(5);
    // obiekt zawierający elementy interfejsu użytkownika związane z macierzą A
    UIMatrix *ui_a;
    // obiekt zawierający elementy interfejsu użytkownika związane z macierzą B
    UIMatrix *ui_b;
    // macierz będąca wynikiem działania
    Matrix result = Matrix(5);
    // precyzja wyświetlania wyniku
    int precision = 2;
    // często używana fraza przy wyświetlaniu komunikatu o błędnych danych
    const wxString nd = "Nieprawidłowe dane.";

    // ZDARZENIA:

    void OnExit(wxCommandEvent& event);
    void OnAbout(wxCommandEvent& event);
    void OnNew(wxCommandEvent& event);
    void OnOpenFile(wxCommandEvent& event);
    void OnSaveFile(wxCommandEvent& event);
    void OnTranspose(wxCommandEvent& event);
    void OnOperation(wxCommandEvent& event);
    void OnPrecision(wxCommandEvent& event);

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
    ID_NewA,
    ID_NewB,
    ID_NewBoth,
    ID_TA,
    ID_TB,
    ID_Add,
    ID_Subtract,
    ID_Subtract_alt,
    ID_Multiply,
    ID_Multiply_alt,
    ID_Precision,
    ID_AddBT,
    ID_SubtractBT,
    ID_Subtract_altBT,
    ID_MultiplyBT,
    ID_Multiply_altBT
};

#endif