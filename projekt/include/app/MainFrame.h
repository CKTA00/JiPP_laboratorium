#include <wx/wxprec.h>
#include <wx/filedlg.h>
#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif

#include <matrix.h>
#include <ResultFrame.h>
#include <UIMatrix.h>

#ifndef MAIN_FRAME_H
#define MAIN_FRAME_H

class MainFrame: public wxFrame
{
public:
    MainFrame(const wxString& title, const wxPoint& pos, const wxSize& size);
    bool a_good, b_good;
    Matrix a_mat = Matrix(5);
    Matrix b_mat = Matrix(5);
    Matrix result = Matrix(5);

    UIMatrix *ui_a;
    UIMatrix *ui_b;
    //wxTextCtrl **ui_a;
    //wxTextCtrl **ui_b;
private:
    const wxString nd = "Nieprawidłowe dane.";

    void OnHello(wxCommandEvent& event);
    void OnExit(wxCommandEvent& event);
    void OnAbout(wxCommandEvent& event);

    void OnOpenFile(wxCommandEvent& event);
    void OnSaveFile(wxCommandEvent& event);
    void OnTranspose(wxCommandEvent& event);
    void OnOperation(wxCommandEvent& event);
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
    ID_TA,
    ID_TB,
    ID_Add,
    ID_Subtract,
    ID_Subtract_alt,
    ID_Multiply,
    ID_Multiply_alt,
    ID_AddBT,
    ID_SubtractBT,
    ID_Subtract_altBT,
    ID_MultiplyBT,
    ID_Multiply_altBT
};

#endif