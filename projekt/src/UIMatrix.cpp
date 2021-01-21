#include <UIMatrix.h>

UIMatrix::UIMatrix(wxWindow *parent, Matrix *mat_ptr)
{
    mat = mat_ptr;
    mainPanel = new wxPanel(parent,wxID_ANY,wxDefaultPosition,wxDefaultSize);
    //mainPanel->SetMinSize(wxSize(150,150));
    wxBoxSizer *mainLayout = new wxBoxSizer(wxVERTICAL);

    nameTC = new wxTextCtrl(mainPanel,ID_NameTC,"debug",wxDefaultPosition,wxSize(30,30));

    wxPanel *gridPanel = new wxPanel(mainPanel,wxID_ANY);
    wxGridSizer *grid = new wxGridSizer(5,5,0,0);
    textControls = new wxTextCtrl*[25];  
    for(int x = 0; x < 5; ++x)
    {
        for(int y = 0; y < 5; ++y)
        {
            textControls[5*y+x] = new wxTextCtrl(gridPanel,wxID_ANY,"0",wxDefaultPosition,wxDefaultSize,wxTE_PROCESS_TAB|wxTE_CENTRE,
                wxFloatingPointValidator<double>(6,get_ptr(mat,x,y),0));
            textControls[5*y+x]->Enable(true);
            grid->Add(textControls[5*y+x], 1, wxEXPAND | wxALL);
        }
    }
    //wxMessageBox(wxString::Format(wxT("%lf"),test));
    gridPanel->SetSizer(grid);
    grid->Layout();

    mainLayout->Add(nameTC,0,wxEXPAND);
    mainLayout->Add(gridPanel,1,wxEXPAND);
    mainPanel->SetSizer(mainLayout);
    mainLayout->Layout();
}

wxPanel* UIMatrix::getMainPanel()
{
    return mainPanel;
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
                    //textControls[5*y+x]->SetLabelText(wxString::Format(wxT("%lf"),mat->get(x,y)));
                    textControls[5*y+x]->SetValidator(wxFloatingPointValidator<double>(6,get_ptr(mat,x,y),0));
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


double* get_ptr(Matrix *mat,int n,int m)
{
    return &(mat->data[n][m]);
}

