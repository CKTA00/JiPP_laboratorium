#include "macierz.cpp"

#define PATH "C:\\pliki"
// katalog C:\pliki musi istniec, funkcja store nie tworzy folderow

using namespace std;

int main(int argc, char *argv[])
{
    Matrix m1(4,5);
    cout << "Macierz m1 zaraz po wykonaniu konstruktora:\n";
    m1.print();
    m1.set(1,1,3);
    m1.set(1,2,4);
    m1.set(3,3,3.14);
    m1.set(99,44,5); //proba zapisania do niestniejacej komorki, zostanie wypisany blad
    cout << "Element macierzy m1 o wspolrzednych [3,3] rowna sie " << m1.get(3,3) << endl;
    cout << "Macierz m1 ma " << m1.rows() << " wierszy i " << m1.cols() << " kolumn." << endl;
    cout << "Element macierzy m1 o wspolrzednych [50,50] rowna sie " << m1.get(50,50) << endl;
    cout << "Macierz m1 po ustawieniu paru danych:\n";
    m1.print();

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
    cout << "Tworzenie dwoch macierzy, wypelnienie danymi i wypisanie: " << endl;
    Matrix m2_a(2);
    Matrix m2_b(2,3);
    m2_a.set(0,0,1);
    m2_a.set(0,1,2);
    m2_a.set(1,0,3);
    m2_a.set(1,1,4);
    m2_a.print();
    m2_b.set(0,0,1);
    m2_b.set(0,1,1);
    m2_b.set(0,2,1);
    m2_b.set(1,0,100);
    m2_b.set(1,1,100);
    m2_b.set(1,2,100);
    m2_b.print();
    cout << "Wynik mnozenia pierwszej przez droga: " << endl;
    Matrix *wynik = m2_a.multiply(m2_b);    //obliczy m2_a x m2_b
    if(wynik != NULL) wynik->print();       //wypisze wynik
    cout << "Proba pomnozenia drugiej przez pierwsza: " << endl;
    wynik = m2_b.multiply(m2_a);            //wypisze informacje o blednych danych i zwroci NULL
    if(wynik != NULL) wynik->print();       //warunek nie zostanie spelniony
    cout << "Proba dodania macierzy o roznych wielkosciach: " << endl;
    wynik = m2_b.add(m2_a);                 //wypisze informacje o blednych danych i zwroci NULL
    if(wynik != NULL) wynik->print();       //warunek nie zostanie spelniony
    cout << "Proba odejmowania macierzy o roznych wielkosciach: " << endl;
    wynik = m2_b.subtract(m2_a);            //wypisze informacje o blednych danych i zwroci NULL
    if(wynik != NULL) wynik->print();       //warunek nie zostanie spelniony
    cout << "Otwieranie przykladowych danych..." << endl;
    Matrix m3_a("macierz_a.txt"), m3_b("macierz_b.txt");    //otwarcie przykladowych danych z folderu w ktorym jest aplikacja
    cout << "Macierz A:" << endl;
    m3_a.print();
    cout << "Macierz B:" << endl;
    m3_b.print();
    Matrix *suma, *roznica;

    cout << "Macierz A+B:" << endl;
    suma = m3_a.add(m3_b);
    suma->print();
    cout << "Macierz B-A:" << endl;
    roznica = m3_b.subtract(m3_a);
    roznica->print();
    cout << "Macierz A-B:" << endl;
    roznica = m3_a.subtract(m3_b);
    roznica->print();

    //wynik->print();

}