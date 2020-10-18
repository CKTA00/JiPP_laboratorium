#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
    if(argc>1)
    {
        string wyraz = argv[1];
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
    return 1;
}