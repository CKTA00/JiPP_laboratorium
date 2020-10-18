#include <iostream>
#include <string>
using namespace std;

int suma_dodatnich_dzielnikow(int n)
{
    int suma = 0;
    if(n<0) n = -n;
    for(int i = 1; i<n; i++)
        if(n%i==0) suma+=i;
    return suma;
}

int main(int argc, char *argv[])
{
    string as, bs;
    int a, b;
    if(argc>=3)
    {
        // Uzytkownik podal przynajmniej 2 argumenty
        as = argv[1];
        bs = argv[2];
    }
    else if(argc==2)
    {
        // Uzytkownik podal 1 argument
        as = argv[1];
        cout << "Podaj liczbe calkowita b: ";
        cin >> bs;
    }
    else
    {
        // Uzytkownik nie podal zadnych argumentow
        cout << "Podaj liczbe calkowita a: ";
        cin >> as;
        cout << "Podaj liczbe calkowita b: ";
        cin >> bs;
    }

    a = stoi(as);
    b = stoi(bs);
    if(a==0 || b==0)
    {
        cout << "Podane liczby musza byc rozne od 0."<<endl;
        return 1;
    }

    cout << "Liczby " << a << " i " << b;
    if(suma_dodatnich_dzielnikow(a)==b+1 && suma_dodatnich_dzielnikow(b)==a+1) cout << " sa skojarzone."<<endl;
    else  cout << " nie sa skojarzone."<<endl;
}

