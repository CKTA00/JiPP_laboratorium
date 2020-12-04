#include <matrix.h>

#define W 5

using namespace std;
Matrix::Matrix(int rows, int cols)
{
    if(rows<1||cols<1)
    {
        cout << "(!) Nieprawidlowa wartosc wierszy lub kolumn w czasie wykonywania konstruktora."<< endl;
        cout << "(!) Przerywanie pracy programu." << endl;
        exit(-1);
    }
    
    r = rows;
    c = cols;
    data = new double*[rows];
    for(int i = 0; i<rows; i++)
    {
        data[i] = new double[cols];
        for(int j = 0; j<cols; j++)
            data[i][j] = 0.0;
    }
}

Matrix::Matrix(int size) : Matrix(size, size)
{}

Matrix::~Matrix()
{
    for(int i = 0; i<r; i++)
    {
        delete data[i];
    }
    delete data;
}

void Matrix::set(int n, int m, double val)
{
    if(n<0||n>=rows()||m<0||m>=cols()) throw invalid_argument("Nie istnieje taki element!");
    data[n][m] = val;
}

double Matrix::get(int n,int m)
{
    if(n<0||n>=rows()||m<0||m>=cols()) throw invalid_argument("Nie istnieje taki element!");
    return data[n][m];
}

Matrix* Matrix::add(Matrix &m2)
{
    if(rows()!=m2.rows()||cols()!=m2.cols()) throw DiffrentSizesOfMatricesException();
    Matrix *ret = new Matrix(rows(),cols());
    double temp;
    for(int i = 0; i<r; i++)
        for(int j = 0; j<c; j++)
        {
            temp = data[i][j];
            temp += m2.get(i,j); 
            ret->set(i,j,temp);
        }
    return ret;  
}

Matrix* Matrix::subtract(Matrix &m2)
{
    if(rows()!=m2.rows()||cols()!=m2.cols()) throw DiffrentSizesOfMatricesException();
    Matrix *ret = new Matrix(rows(),cols());
    double temp;
    for(int i = 0; i<r; i++)
        for(int j = 0; j<c; j++)
        {
            temp = data[i][j];
            temp -= m2.get(i,j); 
            ret->set(i,j,temp);
        }
    return ret;  
}

Matrix* Matrix::multiply(Matrix &m2)
{
    if(cols()!=m2.rows()) throw CannotMultiplyException();
    Matrix* ret = new Matrix(rows(),m2.cols());
    double sum;
    int c2 = m2.cols();
    for(int row = 0; row<r; row++)
        for(int col = 0; col<c2; col++) //wiersze i kolumny nowej macierzy
        {
            sum = 0.0;
            for(int i = 0; i<c; i++)
            {
                sum += data[row][i]*m2.get(i,col);
            }
            ret->set(row,col,sum);
        }
    return ret;  
}

int Matrix::cols()
{
    return c;
}

int Matrix::rows()
{
    return r;
}

void Matrix::print()
{
    // zakomentowane linie dzialaly mi tylko na windowsie wiec postanowilem je zakomentowac
    //cout << (char)218 << setw(W*c+1) << setfill(' ') << (char)191 << endl;
    for(int i = 0; i<r; i++)//rows
    {
        //cout << (char)179;
        for(int j = 0; j<c; j++)//columns
        {
            cout << setw(W) << data[i][j];
        }
        //cout << (char)179;
        cout << endl;
    }
    //cout << (char)192 << setfill(' ') << setw(W*c+1) << (char)217 << endl;
}

void Matrix::store(string filename, string path)
{
    fstream file;
    path.append(filename);
    file.open(path, ios::out);
    if(!file) throw FileFailedToOpenException(path);
        //cout << "(!) Nie mozna utworzyc pliku " << path << endl;
    file << r << ' ' << c << "\n";
    for(int i = 0; i<r; i++)//rows
    {
        for(int j = 0; j<c; j++)//columns
        {
            file << data[i][j] << ' ';
        }
        file << "\n";
    }
    cout << "(i) Plik zapisano pomyslnie.\n";
    file.close();
}

Matrix::Matrix(string path)
{
    fstream file;
    file.open(path, ios::in);
    if(!file)
    {
        cout << "(!) Nie mozna otworzyc pliku " << path << endl;
        exit(-11);
    }
    file >> r >> c;
    if(r<=0 || c<=0)
    {
        cout << "(!) Plik " << path << " zawiera niepoprawne dane." << endl;
        cout << "(!) Przerywanie pracy programu." << endl;
        file.close();
        exit(-12);
    }
    data = new double*[r];
    for(int i = 0; i<r; i++)
    {
        data[i] = new double[c];
        for(int j = 0; j<c; j++)//columns
        {
            if(!file.eof())
                file >> data[i][j];
            else
            {
                cout << "(!) Plik " << path << " zawiera niepoprawne dane." << endl;
                cout << "(!) Przerywanie pracy programu." << endl;
                file.close();
                exit(-13);
            }
        }
    }
    cout << "(i) Plik odczytano pomyslnie.\n";
    file.close();
}