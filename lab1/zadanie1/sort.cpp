#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
    // Przepisywanie argumentow na tablice int.
    // (pierwszy argument zawiera sciezke)
    int *tab = new int[argc-1]; 
    for (int i = 0; i < argc-1; i++) tab[i] = atoi(argv[i+1]);

    // Sortowanie przez wybieranie.
    for (int i = argc-2; i > 0; i--)
    {
        int maxindex=0;
        for(int j = 1; j <= i; j++)
            if(tab[j]>tab[maxindex])
                maxindex = j;
        int temp = tab[i];
        tab[i] = tab[maxindex];
        tab[maxindex] = temp;
    }

    // Wyswietlenie wynikow.
    for (int i = 0; i < argc-1; i++)
    {
        cout << tab[i] << " ";
    }
}

