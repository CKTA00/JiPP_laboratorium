#include <iostream>
#include <string>

using namespace std;

void swap(int &a, int *b)
{
    int temp = a;
    a = *b;
    *b = temp;
}

int main(int argc, char *argv[])
{
    int a=0,b=0;
    string a_s, b_s;

    // input:
    if(argc>2)
    {
        a_s = argv[1];
        b_s = argv[2];
    }
    else if(argc==2)
    {
        a_s = argv[1];
        cout << "Podaj liczbe calkowita: ";
        cin >> b_s;
    }
    else
    {
        cout << "Podaj liczbe calkowita: ";
        cin >> a_s;
        cout << "Podaj liczbe calkowita: ";
        cin >> b_s;
    }
    a = stoi(a_s);
    b = stoi(b_s);

    //cout << "(a,b) = (" << a << "," << b << ")" << endl;   
    swap(a,&b);
    //cout << "(a,b) = (" << a << "," << b << ")" << endl; 
    return 0;


}