#include <UIMatrix.h>

UIMatrix::UIMatrix(wxWindow *parent)
{
    wxPanel *gridPanel = new wxPanel(parent,wxID_ANY,wxDefaultPosition,wxDefaultSize);
    wxGridSizer *grid = new wxGridSizer(5,5,0,0);
    textControls = new wxTextCtrl*[25];  
    for(int x = 0; x < 5; ++x)
    {
        for(int y = 0; y < 5; ++y)
        {
            textControls[5*y+x] = new wxTextCtrl(gridPanel,wxID_ANY,"0",wxDefaultPosition,wxDefaultSize,wxTE_PROCESS_TAB|wxTE_CENTRE,
                wxFloatingPointValidator<double>());
            textControls[5*y+x]->Enable(true);
            grid->Add(textControls[5*y+x], 1, wxEXPAND | wxALL);
        }
    }
    gridPanel->SetSizer(grid);
    grid->Layout();
}

void UIMatrix::clear()
{
    for(int x = 0; x < 5; ++x)
    {
        for(int y = 0; y < 5; ++y)
        {
            textControls[5*y+x]->SetLabelText("");
            textControls[5*y+x]->Enable(false);
        }
    } 
}

void UIMatrix::refresh()
{
    if(mat->displayable())
    {
        int c = mat->cols();
        int r = mat->rows();
        for(int x = 0; x < 5; ++x)
        {
            for(int y = 0; y < 5; ++y)
            {
                if(x<r && y<c)
                {
                    textControls[5*y+x]->SetLabelText(wxString::Format(wxT("%lf"),mat->get(x,y)));
                    textControls[5*y+x]->Enable(true);
                }
                else
                {
                    textControls[5*y+x]->SetLabelText("");
                    textControls[5*y+x]->Enable(false);
                }  
            }
        } 
    } 
}

