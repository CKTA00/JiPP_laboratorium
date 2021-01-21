#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <list>
#include <matrix_exceptions.h>

class Matrix
{
private:
    double** data;
    int c,r;

public:

    //konstruktory i detruktor
    Matrix(int rows, int cols);
    Matrix(int size);
    Matrix(std::string path);
    Matrix(const Matrix &m);
    ~Matrix();

    Matrix& operator=(const Matrix &m2); //operator kopiujący

    //operacje na pojedyńczej komórce
    void set(int n, int m, double val);
    double get(int n,int m);

    //ilości kolumn i wierszy
    int cols();
    int rows();
    bool displayable();

    //działania matematyczne na macierzy
    Matrix add(Matrix &m2);
    Matrix subtract(Matrix &m2);
    Matrix multiply(Matrix &m2);
    Matrix transpose();

    //działania matematyczne na macierzy (opertaory)
    Matrix operator+(Matrix &m2);
    Matrix operator-(Matrix &m2);
    Matrix operator*(Matrix &m2);

    // wypisywanie, zapisywanie
    void print();
    void save(std::string path);
    friend ostream& operator<<(ostream& ostr, const Matrix& mat);

    //pozostałe operatory
    bool operator==(Matrix &m2);
    std::list<double> operator[](int row);
};

