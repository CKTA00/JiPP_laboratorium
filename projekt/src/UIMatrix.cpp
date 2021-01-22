#include <UIMatrix.h>


UIMatrix::UIMatrix(wxWindow *parent, Matrix *mat_ptr, int id_space)
{
    mat = mat_ptr;
    precision = 2;
    this->idSpace = id_space;
    mainPanel = new wxPanel(parent,wxID_ANY,wxDefaultPosition,wxDefaultSize);
    //mainPanel->SetMinSize(wxSize(150,150));
    wxBoxSizer *mainLayout = new wxBoxSizer(wxVERTICAL);

    //nameTC = new wxTextCtrl(mainPanel,ID_NameTC,"debug",wxDefaultPosition,wxDefaultSize,0,wxTextValidator(wxFILTER_ALPHA,&name));

    wxPanel *gridPanel = new wxPanel(mainPanel,wxID_ANY);
    wxGridSizer *grid = new wxGridSizer(5,5,0,0);
    textControls = new wxTextCtrl*[25]; 
    int new_id; 
    for(int x = 0; x < 5; ++x)
    {
        for(int y = 0; y < 5; ++y)
        {
            new_id = id_space*10000+5*y+x;
            textControls[5*y+x] = new wxTextCtrl(gridPanel,new_id,"-",wxDefaultPosition,wxDefaultSize,wxTE_CENTRE,
                wxFloatingPointValidator<double>(precision,get_ptr(mat,x,y),0));
            textControls[5*y+x]->Enable(true);
            textControls[5*y+x]->Bind(wxEVT_TEXT, &UIMatrix::OnTextChange, this, new_id);
            grid->Add(textControls[5*y+x], 1, wxEXPAND | wxALL);
        }
    }
    gridPanel->SetSizer(grid);
    grid->Layout();

    infoT = new wxStaticText(mainPanel,ID_InfoT,"Macierz ?");

    //mainLayout->Add(nameTC,0,wxEXPAND);
    mainLayout->Add(gridPanel,1,wxEXPAND);
    mainLayout->Add(infoT,0,wxEXPAND);
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

void UIMatrix::refresh(wxString inf)
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
                    //textControls[5*y+x]->SetLabelText( wxString::Format(wxT("%lf"), mat->get(x,y)) );
                    textControls[5*y+x]->SetValidator(wxFloatingPointValidator<double>(precision,get_ptr(mat,x,y),0));
                    textControls[5*y+x]->Enable(true);
                    textControls[5*y+x]->GetValidator()->TransferToWindow();
                }
                else
                {
                    textControls[5*y+x]->SetLabelText("");
                    textControls[5*y+x]->Enable(false);
                }  
            }
        } 
        infoT->SetLabelText(inf);
    }
    else
    {
        for(int x = 0; x < 5; ++x)
        {
            for(int y = 0; y < 5; ++y)
            {
                textControls[5*y+x]->SetLabelText("");
                textControls[5*y+x]->Enable(false);
            }
        } 
        infoT->SetLabelText(inf + " - za duży aby wyświetlić");
    }
    
    
}

void UIMatrix::refresh()
{
    UIMatrix::refresh(infoT->GetLabelText());
}

void UIMatrix::OnTextChange(wxCommandEvent& event)
{
    int x = (event.GetId()-10000*idSpace)%5;
    int y = (event.GetId()-10000*idSpace)/5;
    double val;
    textControls[5*y+x]->GetValidator()->TransferFromWindow();
    //if(textControls[5*y+x]->GetLabelText().ToDouble(&val))
   // {
        //wxMessageBox("Debug");
    //}
    
    //mat->set(x,y,val);
}

void UIMatrix::setPrecision(int prec)
{
    precision = prec;
    refresh();
}

/*
void UIMatrix::setName(wxString name)
{
    this->name = name;
}

string UIMatrix::getName()
{
    return name;
}
*/

double* get_ptr(Matrix *mat,int n,int m)
{
    return &(mat->data[n][m]);
}

