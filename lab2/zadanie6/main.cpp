#include <iostream>
#include <string>

using namespace std;

template<typename T> void swaper(T *a, T *b)
{
    size_t s = sizeof(T);
    T temp;
    memcpy(&temp, a, s);
    memcpy(a, b, s);
    memcpy(b, &temp, s);
}

int main(int argc, char *argv[])
{
    int a=0,b=0;
    float af,bf;
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
    af = (float)a;
    bf = (float)b;
    cout << "Before swaping: (a,b) = (" << a << "," << b << ")" << endl;   
    swaper(&a,&b);
    cout << "After swaping: (a,b) = (" << a << "," << b << ")" << endl;
    cout << "Before swaping: (af,bf) = (" << af << "," << bf << ")" << endl;   
    swaper(&af,&bf);
    cout << "After swaping: (af,bf) = (" << af << "," << bf << ")" << endl;
    return 0;
}