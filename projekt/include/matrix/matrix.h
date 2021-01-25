//#include <iostream>
//#include <iomanip>
#include <fstream>
#include <string>
#include <list>
#include <matrix_exceptions.h>

#ifndef MATRIX_H
#define MATRIX_H

class Matrix
{
private:
    int c,r;
    double** data;
    
public:
    //KONSTRUKTORY I DETRUKTOR:
    // tworzy macierz rows na cols
    Matrix(int rows, int cols);
    //tworzy macierz kwadratową size na size
    Matrix(int size);
    //tworzy macierz na podstawie pliku
    Matrix(std::string path);
    //konstruktor kopiujący
    Matrix(const Matrix &m);
    ~Matrix();

    //operator kopiujący
    Matrix& operator=(const Matrix &m2);

    //OPERACJE NA POJEDYŃCZEJ KOMÓRCE:
    //ustaw [n,m] na wartość val
    void set(int n, int m, double val);
    //odczytaj [n,m]
    double get(int n,int m);
    //zdobądź wskaźnik do konkretnej komórki [n,m], potrzebne do ustanowienia walidacji
    friend double* get_ptr(Matrix *mat,int n,int m);

    //FUNKCJE DOTYCZĄCE ILOŚCI KOLUMN I WIERSZY:
    // liość kolumn
    int cols();
    // ilość wierszy
    int rows();
    // czy można wyświetlić macierz w ui (jest conajwyżej 5 na 5)
    bool displayable();
    // zmień rozmiar macierzy
    void resize(int n, int m);

    //DZIAŁANIA MATEMATYCZNE NA MACIERZY:
    //dodaj macierz m2
    Matrix add(Matrix &m2);
    //odejmij macierz m2
    Matrix subtract(Matrix &m2);
    //pomnóż przez macierz m2
    Matrix multiply(Matrix &m2);
    //transponuj macierz
    Matrix transpose();

    //OPERTAORY:
    //dodawaj macierze
    Matrix operator+(Matrix &m2);
    //odejmuj macierze
    Matrix operator-(Matrix &m2);
    //mnóż macierze
    Matrix operator*(Matrix &m2);

    // POZOSTAŁE
    //zapisz do pliku
    void save(std::string path);
    //operator porównania
    bool operator==(Matrix &m2);
};

#endif

