#include <iostream>
#include <string>
using namespace std;

int main(int argc, char *argv[])
{
    string ms, ws;
    float masa, wzrost, bmi;
    if(argc>=3)
    {
        // Uzytkownik podal przynajmniej 2 argumenty (czyli podal wzrost i mase)
        ws = argv[2];
        ms = argv[1];
    }
    else if(argc==2)
    {
        // Uzytkownik podal 1 argument (sama mase)
        ms = argv[1];
        cout << "Podaj wzrost [m]: ";
        cin >> ws;
    }
    else
    {
        // Uzytkownik nie podal zadnych argumentow
        cout << "Podaj mase [kg]: ";
        cin >> ms;
        cout << "Podaj wzrost [m]: ";
        cin >> ws;
    }

    masa = stof(ms);
    wzrost = stof(ws);
    bmi = masa/(wzrost*wzrost);

    cout << "BMI wynioslo " << bmi << endl << "Kategoria: ";
    if(bmi<16) cout << "wyglodzenie";
    else if (bmi <17) cout << "wychudzenie";
    else if (bmi <18.5f) cout << "niedowaga";
    else if (bmi <25) cout << "wartosc prawidlowa";
    else if (bmi <30) cout << "nadwaga";
    else if (bmi <35) cout << "I stopnien otylosci";
    else if (bmi <40) cout << "II stopnien otylosci";
    else cout << "otylosc skrajna";
}