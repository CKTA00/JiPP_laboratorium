#include <matrix.h>


// PROGRAM ZOSTAL NAPISANY POD LINUX (PISALEM UZYWAJAC WSL)
#define PATH "../tests/" // zakladajac ze plik wykonywalny znajduje sie w folderze build (lub jakimkolwiek jednym folderze w katalogu lab4)

using namespace std;


int main(int argc, char *argv[])
{
    // test konstruktora Matrix(int,int) oraz funkcji set(), get(), rows(), cols() i print():
    cout << endl << "TEST PODSTAWOWYCH FUNKCJI MACIERZY:" << endl << endl;
    Matrix mat1(5,6);
    cout << "Macierz mat zaraz po wykonaniu konstruktora:" << endl;
    mat1.print();
    mat1.set(1,1,3);
    mat1.set(1,2,4);
    mat1.set(3,3,3.14);
    cout << "Macierz mat po ustawieniu paru danych:\n";
    mat1.print();
    cout << "Element macierzy mat o wspolrzednych [3,3] rowna sie " << mat1.get(3,3) << endl;
    cout << "Macierz mat ma " << mat1.rows() << " wierszy i " << mat1.cols() << " kolumn." << endl << endl;

    // test obslugi bledow:
    cout << "Proba zapisania do niestniejacej komorki:"<<endl;
    try
    {
        mat1.set(99,44,5);
    }
    catch(const exception& e)
    {
        cerr << e.what() << '\n';
    }
    
    cout << "Proba odczytania niestniejacej komorki, zostanie wypisany blad:"<<endl;
    try
    {
        cout << "Element macierzy mat o wspolrzednych [50,50] rowna sie " << mat1.get(50,50) << endl << endl;
    }
    catch(const exception &e)
    {
        cerr << e.what() << '\n';
    }
    
    
    // test obsulgi plikow:
    cout << endl << "TEST OBSLUGI PLIKOW:" << endl << endl;
    string filename, fullpath;
    cout << "Plik zostanie zapisany w folderze " << PATH << " o ile istnieje." << endl;
    cout << "Podaj nazwe pliku: ";
    cin >> filename;
    try
    {
        mat1.store(filename,PATH);
    }
    catch(FileFailedToOpenException &fe)
    {
        cerr << fe.getpath() << fe.what() << "\n";
        exit(1);
    }

    cout << "Plik ten zostanie teraz otwarty i wypisany..." << endl;
    fullpath = PATH;
    fullpath.append(filename);
    Matrix mat2(fullpath);
    mat2.print();
    if(mat1==mat2) cout << "Zapisana macierz i odczytana macierz są identyczne." << endl;      
    cout << endl;

    cout << "Tworzenie dwoch macierzy A i B oraz wypelnienie danymi: " << endl;
    // test konstruktora Matrix(int)
    Matrix mat_a(4);
    mat_a.set(0,0,1);
    mat_a.set(0,1,2);
    mat_a.set(0,2,1);
    mat_a.set(0,3,2);
    mat_a.set(1,0,3);
    mat_a.set(1,1,4);
    Matrix mat_b("../tests/macierz_b.txt"), mat_c("../tests/macierz_c.txt"), mat_d("../tests/macierz_d.txt"); //niepowodzenie konczy dzialanie programu
    cout << "Macierz A:" << endl;
    mat_a.print();
    cout << "Macierz B:" << endl;
    mat_b.print();     
    cout << "Macierz C:" << endl;
    mat_c.print();
    cout << "Macierz D:" << endl;
    mat_d.print();

                           
    // test dodawania, odejmowania i mnozenia:
    cout << endl << "TEST FUNKCJI DODAWANIA, ODEJMOWANIA I MNOZENIA:" << endl << endl;

    cout << "Macierz C+D:" << endl;
    //Matrix suma = mat_c.add(mat_d);
    Matrix suma = mat_c + mat_d;
    suma.print();

    cout << "Macierz D-C:" << endl;
    //Matrix roznica = mat_d.subtract(mat_c);
    Matrix roznica = mat_d - mat_c;
    roznica.print();

    cout << "Macierz C-D:" << endl;
    //Matrix roznica2 = mat_c.subtract(mat_d);
    Matrix roznica2 = mat_c - mat_d;
    roznica2.print();

    cout << "Wynik mnozenia A*B:" << endl;
    //Matrix iloczyn = mat_a.multiply(mat_b);
    Matrix iloczyn = mat_a * mat_b;                    
    iloczyn.print();

    cout << endl << "Wynik mnozenia zostanie teraz zapisany do pilku " << PATH << "iloczyn.txt" << endl;
    string path = PATH;
    path.append("iloczyn.txt");

    fstream zapis;
    zapis.open(path, ios::out);
    zapis << iloczyn;
    zapis.close();

    cout << "Zapis udany!" << endl << "Wynik mnozenia zostanie teraz odczytany z tego piku:" << endl;

    Matrix odczytana(path);
    cout << odczytana << endl;

    if(odczytana==iloczyn) cout << "Macierze A*B oraz odczytana są identyczne" << endl;
    else cout << "Cos poszło nie tak! Macierze A*B oraz odczytana są różne" << endl; 

    cout << "Teraz zostanie utworzona lista z drugiego wiersza macierzy odczytanej:" << endl;
    list<double> lista = odczytana[1];
    for(list<double>::iterator it = lista.begin();it!=lista.end();it++)
    {
        cout << setw(5) <<*it;
    }


    // Test obslugi bledow:
    cout << endl << "TEST ZACHOWANIA FUNKCJI DODAWANIA, ODEJMOWANIA I MNOZENIA PO PODANIU BLEDNYCH DANYCH:" << endl << endl;

    cout << "Proba dodania macierzy o roznych wielkosciach (A+B): " << endl;
    try
    {
        Matrix bad = mat_a.add(mat_b);
        bad.print();
    }
    catch(const exception& e)
    {
        cerr << e.what() << '\n';
    }

    cout << "Proba odejmowania macierzy o roznych wielkosciach (A-B): " << endl;
    try
    {
        Matrix bad2 = mat_a.subtract(mat_b);
        bad2.print();
    }
    catch(const exception& e)
    {
        cerr << e.what() << '\n';
    }
    
    cout << "Proba pomnozenia B x A (zamiast A x B): " << endl;
    try
    {
        Matrix bad3 = mat_b.multiply(mat_a);
        bad3.print();
    }
    catch(const exception& e)
    {
        cerr << e.what() << '\n';
    }
}