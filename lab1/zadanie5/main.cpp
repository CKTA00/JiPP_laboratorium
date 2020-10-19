#include <iostream>
#include <iomanip> 
#define W 5
using namespace std;

int main(int argc, char *argv[])
{
    int a[2][3] = {{1,2,3},{4,5,6}};
    int b[2][3] = {{10,20,30},{40,50,60}};

    cout << "Wprowadz macierz A" << endl;
    cout << "1. wiersz: ";
    cin >> a[0][0] >> a[0][1] >> a[0][2];
    cout << "2. wiersz: ";
    cin >> a[1][0] >> a[1][1] >> a[1][2];

    cout << endl <<"Wprowadz macierz B" << endl;
    cout << "1. wiersz: ";
    cin >> b[0][0] >> b[0][1] >> b[0][2];
    cout << "2. wiersz: ";
    cin >> b[1][0] >> b[1][1] >> b[1][2];

    cout << endl << "Wynik A + B" << endl;
    cout << (char)218 << setw(W*3+1) << setfill(' ') << (char)191 << endl;
    for(int r = 0; r<2; r++)//rows
    {
        cout << (char)179;
        for(int c = 0; c<3; c++)//columns
        {
            cout << setw(W) << a[r][c]+b[r][c];
        }
        cout << (char)179 << endl;
    }
    cout << (char)192 << setfill(' ') << setw(W*3+1) << (char)217 << endl;
}