#include <exception>
#include <string>
using namespace std;

#ifndef MATRIX_EXCP_H
#define MATRIX_EXCP_H

class FileFailedToOpenException : public exception
{
    string path;
    public:
    FileFailedToOpenException(string path);
    string getpath();
    virtual const char *what() const throw();
};

class DiffrentSizesOfMatricesException : public exception
{
    virtual const char *what() const throw();
};

class CannotMultiplyException : public exception
{
    virtual const char *what() const throw();
};

#endif