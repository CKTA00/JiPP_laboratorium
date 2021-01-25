#include <exception>
#include <string>
using namespace std;

#ifndef MATRIX_EXCP_H
#define MATRIX_EXCP_H

// wyjątek: nie udało się otworzyć pliku
class FileFailedToOpenException : public exception
{
    string path;
    public:
    FileFailedToOpenException(string path);
    string getpath();
    virtual const char *what() const throw();
};

// wyjątek: operacja wymaga macierzy o tych samych rozmiarach
class DiffrentSizesOfMatricesException : public exception
{
    virtual const char *what() const throw();
};

// wyjątek: nie można pomnożyć macierzy o tych rozmiarach
class CannotMultiplyException : public exception
{
    virtual const char *what() const throw();
};

#endif