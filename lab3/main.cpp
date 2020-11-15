#include "matrix.cpp"

#define PATH "C:\\pliki\\"
// Katalog C:\pliki musi istniec, funkcja Matrix::store nie tworzy folderow
// Funkcja Matrix::store nie dodaje do sciezki '\' ani '/'. Prosze uwzglednic ten znak w tym makrze.

using namespace std;

int main(int argc, char *argv[])
{
    Matrix m1(4,5);
    cout << "Macierz m1 zaraz po wykonaniu konstruktora:" << endl;
    m1.print();
    m1.set(1,1,3);
    m1.set(1,2,4);
    m1.set(3,3,3.14);
    
    
    cout << "Macierz m1 po ustawieniu paru danych:\n";
    m1.print();
    cout << "Element macierzy m1 o wspolrzednych [3,3] rowna sie " << m1.get(3,3) << endl;
    cout << "Macierz m1 ma " << m1.rows() << " wierszy i " << m1.cols() << " kolumn." << endl;
    cout << "Proba zapisania do niestniejacej komorki, zostanie wypisany blad:"<<endl;
    m1.set(99,44,5); 
    cout << "Proba odczytania niestniejacej komorki, zostanie wypisany blad:"<<endl;
    cout << "Element macierzy m1 o wspolrzednych [50,50] rowna sie " << m1.get(50,50) << endl << endl;
    

    string filename, fullpath;
    cout << "Plik zostanie zapisany w folderze " << PATH << " o ile istnieje." << endl;
    cout << "Podaj nazwe pliku: ";
    cin >> filename;
    m1.store(filename,PATH);
    cout << "Plik ten zostanie teraz otwarty i wypisany..." << endl;
    fullpath = PATH;
    fullpath.append("\\");
    fullpath.append(filename);
    Matrix m1_b(fullpath);
    m1_b.print();
    cout << endl;


    cout << "Tworzenie dwoch macierzy A i B oraz wypelnienie danymi: " << endl;
    Matrix m2_a(4);
    Matrix m2_b(4,6);

    m2_a.set(0,0,1);
    m2_a.set(0,1,2);
    m2_a.set(0,2,1);
    m2_a.set(0,3,2);
    m2_a.set(1,0,3);
    m2_a.set(1,1,4);
    cout << "A:" << endl;
    m2_a.print();

    m2_b.set(0,0,1);
    m2_b.set(0,1,1);
    m2_b.set(0,2,1);
    m2_b.set(0,3,1);
    m2_b.set(0,4,1);
    m2_b.set(0,5,1);
    m2_b.set(1,0,2);
    m2_b.set(1,1,2);
    m2_b.set(1,2,2);
    m2_b.set(1,3,2);
    m2_b.set(2,0,-2);
    m2_b.set(3,1,3);
    cout << "B:" << endl;
    m2_b.print();

    cout << "Proba dodania macierzy o roznych wielkosciach: " << endl;
    Matrix * wynik = m2_b.add(m2_a);                                //wypisze informacje o blednych danych i zwroci macierz domyślną
    wynik->print();                                                 //wypisze macierz domyślną [0]
    delete wynik;
    wynik = NULL;
    cout << "Wynik mnozenia A x B: " << endl;
    wynik = m2_a.multiply(m2_b);                        
    wynik->print();                                     
    delete wynik;
    wynik = NULL;
    
    cout << "Proba pomnozenia B x A: " << endl;
    wynik = m2_b.multiply(m2_a);                    //wypisze informacje o blednych danych i zwroci macierz domyślną
    wynik->print();                                 //warunek macierz domyślną [0]
    delete wynik;
    wynik = NULL;
    
    cout << "Proba odejmowania macierzy o roznych wielkosciach: " << endl;
    wynik = m2_b.subtract(m2_a);                    //wypisze informacje o blednych danych i zwroci macierz domyślną
    wynik->print();                                 //wypisze macierz domyślną [0]
    delete wynik;
    wynik = NULL;



    cout << "Otwieranie przykladowych danych..." << endl;
    Matrix m3_c("macierz_c.txt"), m3_d("macierz_d.txt");    //niepowodzenie konczy dzialanie programu
    cout << "Macierz C:" << endl;
    m3_c.print();
    cout << "Macierz D:" << endl;
    m3_d.print();
    Matrix *suma, *roznica;
    cout << "Macierz C+D:" << endl;
    suma = m3_c.add(m3_d);
    suma->print();
    delete suma;
    suma = NULL;
    cout << "Macierz D-C:" << endl;
    roznica = m3_d.subtract(m3_c);
    roznica->print();
    delete roznica;
    suma = NULL;
    cout << "Macierz C-D:" << endl;
    roznica = m3_c.subtract(m3_d);
    roznica->print();
    delete roznica;
    roznica = NULL;
}