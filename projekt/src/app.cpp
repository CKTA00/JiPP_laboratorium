#include <App.h>

wxIMPLEMENT_APP(App);

bool App::OnInit()
{
    MainFrame *frame = new MainFrame( "Mini Kalkulator Macierzy", wxPoint(50, 50), wxSize(450, 340));
    frame->Show( true );
    frame->Layout();
    //frame->SendSizeEvent();
    return true;
}
