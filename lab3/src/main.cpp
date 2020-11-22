#include "matrix.h"

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

    // test obslugi bledow:
    cout << "Macierz mat ma " << mat1.rows() << " wierszy i " << mat1.cols() << " kolumn." << endl << endl;
    cout << "Proba zapisania do niestniejacej komorki, zostanie wypisany blad:"<<endl;
    mat1.set(99,44,5); 
    cout << "Proba odczytania niestniejacej komorki, zostanie wypisany blad:"<<endl;
    cout << "Element macierzy mat o wspolrzednych [50,50] rowna sie " << mat1.get(50,50) << endl << endl;
    
    // test obsulgi plikow:
    cout << endl << "TEST OBSLUGI PLIKOW:" << endl << endl;
    string filename, fullpath;
    cout << "Plik zostanie zapisany w folderze " << PATH << " o ile istnieje." << endl;
    cout << "Podaj nazwe pliku: ";
    cin >> filename;
    mat1.store(filename,PATH);
    cout << "Plik ten zostanie teraz otwarty i wypisany..." << endl;
    fullpath = PATH;
    fullpath.append(filename);
    Matrix mat2(fullpath);
    mat2.print();
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
    Matrix mat_b("macierz_b.txt"), mat_c("macierz_c.txt"), mat_d("macierz_d.txt"); //niepowodzenie konczy dzialanie programu
    cout << "Macierz A:" << endl;
    mat_a.print();
    cout << "Macierz B:" << endl;
    mat_b.print();     
    cout << "Macierz C:" << endl;
    mat_c.print();
    cout << "Macierz D:" << endl;
    mat_d.print();


    // test mnozenia:
    cout << "Wynik mnozenia A x B: " << endl;
    Matrix * iloczyn = mat_a.multiply(mat_b);                 
    iloczyn->print();                                     
    delete iloczyn;
    iloczyn = nullptr;

    

    // test dodawania i odejmowania:
    cout << endl << "TEST FUNKCJI DODAWANIA, ODEJMOWANIA I MNOZENIA:" << endl << endl;
    Matrix *suma, *roznica_a, *roznica_b;
    cout << "Macierz C+D:" << endl;
    suma = mat_c.add(mat_d);
    suma->print();
    delete suma;
    suma = nullptr;

    cout << "Macierz D-C:" << endl;
    roznica_a = mat_d.subtract(mat_c);
    roznica_a->print();
    delete roznica_a;
    roznica_a = nullptr;

    cout << "Macierz C-D:" << endl;
    roznica_b = mat_c.subtract(mat_d);
    roznica_b->print();
    delete roznica_b;
    roznica_b = nullptr;

    // Test obslugi bledow:
    cout << endl << "TEST ZACHOWANIA FUNKCJI DODAWANIA, ODEJMOWANIA I MNOZENIA PO PODANIU BLEDNYCH DANYCH:" << endl << endl;

    cout << "Proba dodania macierzy o roznych wielkosciach (A+B): " << endl;
    Matrix * bad1 = mat_a.add(mat_b);                            //wypisze informacje o blednych danych i zwroci macierz domyślną
    bad1->print();                                             //wypisze macierz domyślną [0]
    delete bad1;
    bad1 = nullptr;

    cout << "Proba odejmowania macierzy o roznych wielkosciach (A-B): " << endl;
    Matrix * bad2 = mat_a.subtract(mat_b);                      //wypisze informacje o blednych danych i zwroci macierz domyślną
    bad2->print();                                           //wypisze macierz domyślną [0]
    delete bad2;
    bad2 = nullptr;

    cout << "Proba pomnozenia B x A (zamiast A x B): " << endl;
    Matrix * bad3 = mat_b.multiply(mat_a);                      //wypisze informacje o blednych danych i zwroci macierz domyślną
    bad3->print();                                            //warunek macierz domyślną [0]
    delete bad3;
    bad3 = nullptr;
    


}