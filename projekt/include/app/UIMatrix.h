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
    // ELEMENTY UI:
    wxPanel *mainPanel;
    wxTextCtrl **textControls;
    wxComboBox *rowsCB, *colsCB;
    wxStaticText *infoT;
    wxArrayString sizeList;

    // wskaźnik na dane z MainFrame'a:
    Matrix *mat;

    //pozostałe informacje
    int precision;
    int idSpace;
    
public:
    UIMatrix(wxWindow *parent, Matrix *mat_ptr, int id_space);

    //zwraca wskaźnik do panelu głównego (przydatne podczas przyłańczania do głównego okna)
    wxPanel* getMainPanel();
    
    //zmienia rozmiar macierzy (maks do 5 na 5)
    void resize(int n, int m);
    //odśwież widok po zmianie danych
    void refresh();
    //odśwież widok po zmianie danych i zmień informacje pod macierzą na inf
    void refresh(wxString inf); 
    //ustaw precyzje walidatorów
    void setPrecision(int prec);
    
    // ZDARZENIA:

    void OnTextChange(wxCommandEvent& event);
    void OnSizeChange(wxCommandEvent& event);
};

enum
{
    ID_NameTC = 500,
    ID_InfoT,
    ID_RowsCB,
    ID_ColsCB
};


#endif