#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
    string wyraz;
    if(argc>1)
    {
        wyraz = argv[1];
    }
    else
    {
        cout << "Podaj wyraz: ";
        cin >> wyraz;
    }
    
    int d = wyraz.size();
    for(int i = 0; i<d/2; i++)
    {
        if(wyraz[i]!=wyraz[d-i-1])
        {
            cout << "Wyraz " << wyraz << " nie jest palindromem."<<endl;
            return 0;
        }
    }
    cout << "Wyraz " << wyraz << " jest palindromem." << endl;
    return 0;
}