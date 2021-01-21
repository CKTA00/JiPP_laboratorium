#include <UIMatrix.h>


UIMatrix::UIMatrix(wxWindow *parent, Matrix *mat_ptr, int id_space)
{
    mat = mat_ptr;
    this->idSpace = id_space;
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
            textControls[5*y+x] = new wxTextCtrl(gridPanel,id_space*10000+5*y+x,"0",wxDefaultPosition,wxDefaultSize,wxTE_PROCESS_TAB|wxTE_CENTRE,
                wxFloatingPointValidator<double>(6,get_ptr(mat,x,y),0));
            textControls[5*y+x]->Enable(true);
            grid->Add(textControls[5*y+x], 1, wxEXPAND | wxALL);
            //10000+5*y+x
            //textControls[5*y+x]->Bind(wxEVT_TEXT_ENTER, UIMatrix::OnTextEnter, this, 10000);
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
    //refresh();
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

void UIMatrix::OnTextEnter(wxCommandEvent& event)
{
    int x = (event.GetId()-10000*idSpace)%5;
    int y = (event.GetId()-10000*idSpace)/5;
    double val;
    if(textControls[5*y+x]->GetLabelText().ToDouble(&val))
    {
        ///
    }
    mat->set(x,y,val);
}

double* get_ptr(Matrix *mat,int n,int m)
{
    return &(mat->data[n][m]);
}

