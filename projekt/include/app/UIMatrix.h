#include <wx/wxprec.h>
#include <wx/filedlg.h>
#include <wx/valnum.h>
#include <matrix.h>

class UIMatrix
{
    wxTextCtrl **textControls;
    Matrix *mat;
    wxTextCtrl *name;
    wxStaticText *info;

    
public:
    UIMatrix(wxWindow *parent);
    void clear();
    void resize(int n, int m); // max do 5
    void refresh(); // wywołuj po zmiane wskaznika w funkcjach MainFrame'a
    //void setMatrix(Matrix &mat); // tu sprawdzaj czy displayable
};