#include <UIMatrix.h>


UIMatrix::UIMatrix(wxWindow *parent, Matrix *mat_ptr, int id_space)
{
    // OGÓLNE:
    mat = mat_ptr;
    precision = 2;
    this->idSpace = id_space;
    mainPanel = new wxPanel(parent,wxID_ANY,wxDefaultPosition,wxDefaultSize);
    //mainPanel->SetMinSize(wxSize(150,150));
    wxBoxSizer *mainLayout = new wxBoxSizer(wxVERTICAL);
    sizeList.Add("1");
    sizeList.Add("2");
    sizeList.Add("3");
    sizeList.Add("4");
    sizeList.Add("5");

    // PANEL Z USTAWIANIEM WIELKOŚCI MACIERZY:
    wxPanel *topPanel = new wxPanel(mainPanel,wxID_ANY,wxDefaultPosition,wxDefaultSize);
    wxGridSizer *topLayout = new wxGridSizer(1,4,0,0);
    rowsCB = new wxComboBox(topPanel,ID_RowsCB,"5",wxDefaultPosition,wxDefaultSize,sizeList,wxCB_READONLY);
    rowsCB->Bind(wxEVT_COMBOBOX, &UIMatrix::OnSizeChange, this, ID_RowsCB);
    colsCB = new wxComboBox(topPanel,ID_ColsCB,"5",wxDefaultPosition,wxDefaultSize,sizeList,wxCB_READONLY);
    colsCB->Bind(wxEVT_COMBOBOX, &UIMatrix::OnSizeChange, this, ID_ColsCB);
    wxStaticText *rowsT = new wxStaticText(topPanel,wxID_ANY,"Wierszy:",wxDefaultPosition,wxDefaultSize,wxALIGN_RIGHT);
    wxStaticText *colsT = new wxStaticText(topPanel,wxID_ANY,"Kolumn:",wxDefaultPosition,wxDefaultSize,wxALIGN_RIGHT);
    topLayout->Add(rowsT,0,wxEXPAND|wxRIGHT,2);
    topLayout->Add(rowsCB,1,wxEXPAND|wxRIGHT,5);
    topLayout->Add(colsT,0,wxEXPAND|wxRIGHT,2);
    topLayout->Add(colsCB,1,wxEXPAND);
    topPanel->SetSizer(topLayout);
    topLayout->Layout();

    // PANEL MACIERZY:
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

    // PASEK INFORMACJI POD MACIERZĄ:
    infoT = new wxStaticText(mainPanel,ID_InfoT,"Macierz ?");

    // OKNO GŁÓWNE:
    mainLayout->Add(topPanel,0,wxEXPAND);
    mainLayout->Add(gridPanel,1,wxEXPAND);
    mainLayout->Add(infoT,0,wxEXPAND);
    mainPanel->SetSizer(mainLayout);
    mainLayout->Layout();
}

wxPanel* UIMatrix::getMainPanel()
{
    return mainPanel;
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
        rowsCB->Enable(true);
        colsCB->Enable(true);
        rowsCB->SetValue(wxString::Format("%d",mat->rows()));
        colsCB->SetValue(wxString::Format("%d",mat->cols()));
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
        infoT->SetLabelText(inf + " - za duża aby wyświetlić");
        rowsCB->SetValue(wxString::Format("%d",mat->rows()));
        colsCB->SetValue(wxString::Format("%d",mat->cols()));
        rowsCB->Enable(false);
        colsCB->Enable(false);
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
    textControls[5*y+x]->GetValidator()->TransferFromWindow();
    event.Skip();
}

void UIMatrix::OnSizeChange(wxCommandEvent& event)
{
    long new_size;

    if(event.GetId()==ID_RowsCB)
    {
        rowsCB->GetValue().ToLong(&new_size,10);
        mat->resize((int)new_size,mat->cols());
    }
    else
    {
        colsCB->GetValue().ToLong(&new_size,10);
        mat->resize(mat->rows(),(int)new_size);
    }
    refresh();
    event.Skip();
}

void UIMatrix::setPrecision(int prec)
{
    precision = prec;
    refresh();
}


double* get_ptr(Matrix *mat,int n,int m)
{
    return &(mat->data[n][m]);
}

