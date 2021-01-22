#include <wx/filedlg.h>
#include <wx/wxprec.h>
#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif
#include <wx/valnum.h>
#include <wx/listbox.h>
#include <matrix.h>

#ifndef UI_MATRIX_H
#define UI_MATRIX_H

class UIMatrix
{
    // elementy UI:
    wxPanel *mainPanel;
    //wxTextCtrl *nameTC;
    wxTextCtrl **textControls;
    wxComboBox *rowsCB, *colsCB;
    wxStaticText *infoT;
    wxArrayString sizeList;

    // wskaźnik na dane z MainFrame'a:
    Matrix *mat;
    //wxString name;

    //pozostałe informacje
    int precision;
    int idSpace;
    
public:
    UIMatrix(wxWindow *parent, Matrix *mat_ptr, int id_space);
    wxPanel* getMainPanel();
    void resize(int n, int m); // max do 5
    void refresh(); 
    void refresh(wxString inf); 
    void setPrecision(int prec);
    void OnTextChange(wxCommandEvent& event);
    void OnSizeChange(wxCommandEvent& event);


    //nazwa
    //void setName(wxString name);
    //string getName();
};

enum
{
    ID_NameTC = 500,
    ID_InfoT,
    ID_RowsCB,
    ID_ColsCB
};


#endif