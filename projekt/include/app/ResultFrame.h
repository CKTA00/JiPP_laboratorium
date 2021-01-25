#include <wx/wxprec.h>
#include <wx/filedlg.h>
#include <matrix.h>
#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif

#ifndef RESULT_FRAME_H
#define RESULT_FRAME_H

class ResultFrame: public wxDialog
{
    // macierz 5 na 5 elementów UI
    wxTextCtrl **ui_matrix;

    // wskaźniki na oryginalne dane:
    Matrix *result;
    Matrix *mat_a;
    Matrix *mat_b;

public:
    ResultFrame::ResultFrame(wxWindow *parent, const wxString& title, const wxPoint& pos, const wxSize& size, long style,
        Matrix &result, Matrix &a_mat, Matrix &b_mat, int precision);

    // ZDARZENIA:
    void OnBackClicked(wxCommandEvent &evt);
    void OnFileClicked(wxCommandEvent &evt);
    void OnReplaceClicked(wxCommandEvent &evt);
    
    wxDECLARE_EVENT_TABLE();
};

enum
{
    ID_Back = 1,
    ID_File,
    ID_ReplaceA,
    ID_ReplaceB,
};

#endif