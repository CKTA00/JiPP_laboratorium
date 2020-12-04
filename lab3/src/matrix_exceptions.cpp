#include <matrix_exceptions.h>
using namespace std;

// class FileFailedToOpenException
FileFailedToOpenException::FileFailedToOpenException(string path){this->path = path;}
string FileFailedToOpenException::getpath(){ return path;}
const char* FileFailedToOpenException::what() const throw()
{
    return " : Błąd otwarcia pliku.";
}

// class DiffrentSizesOfMatricesException
const char* DiffrentSizesOfMatricesException::what() const throw()
{
    return "Wielkości macierzy się różnią.";
}

// class CannotMultiplyException
const char* CannotMultiplyException::what() const throw()
{
    return "Liczba kolumn pierwszej macierzy nie rowna sie liczbie wierszy w macierzy drugiej. Nie mozna wykonac mnozenia.";
}
