#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <matrix_exceptions.h>

class Matrix
{
private:
    double** data;
    int c,r;
public:
    Matrix(int rows, int cols);
    Matrix(int size);
    Matrix(std::string path);
    ~Matrix();
    void set(int n, int m, double val);
    double get(int n,int m);
    Matrix* add(Matrix &m2);
    Matrix* subtract(Matrix &m2);
    Matrix* multiply(Matrix &m2);
    int cols();
    int rows();
    void print();
    void store(std::string filename, std::string path);
};

