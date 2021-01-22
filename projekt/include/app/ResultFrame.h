#include <wx/wxprec.h>
#include <wx/filedlg.h>
#include <matrix.h>
#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif

#ifndef RESULT_FRAME_H
#define RESULT_FRAME_H

class ResultFrame: public wxFrame
{
    wxTextCtrl **ui_matrix;
    Matrix *result;
    Matrix *a_mat;
    Matrix *b_mat;
    public:
        ResultFrame::ResultFrame(wxWindow *parent, const wxString& title, const wxPoint& pos, const wxSize& size,
            Matrix &result, Matrix &a_mat, Matrix &b_mat, int precision);
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