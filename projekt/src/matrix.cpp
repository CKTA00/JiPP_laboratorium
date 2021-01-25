#include <matrix.h>

#define W 5

using namespace std;

Matrix::Matrix(const Matrix &m)
{
    r = m.r;
    c = m.c;
    data = new double*[r];
    for(int i = 0; i<r; i++)
    {
        data[i] = new double[c];
        for(int j = 0; j<c; j++)
            data[i][j] = m.data[i][j];
    }
}

Matrix::Matrix(int rows, int cols)
{
    if(rows<1||cols<1)
    {
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

Matrix& Matrix::operator=(const Matrix &m2)
{
    if(this == &m2) return *this; // czy nie doszło do samoprzypisania
    r = m2.r;
    c = m2.c;
    data = new double*[r];
    for(int i = 0; i<r; i++)
    {
        data[i] = new double[c];
        for(int j = 0; j<c; j++)
            data[i][j] = m2.data[i][j];
    }
    return *this;
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

Matrix Matrix::add(Matrix &m2)
{
    if(rows()!=m2.rows()||cols()!=m2.cols()) throw DiffrentSizesOfMatricesException();
    Matrix ret = Matrix(rows(),cols());
    double temp;
    for(int i = 0; i<r; i++)
        for(int j = 0; j<c; j++)
        {
            temp = data[i][j];
            temp += m2.get(i,j); 
            ret.set(i,j,temp);
        }
    return ret;  
}

Matrix Matrix::operator+(Matrix &m2)
{
    return add(m2);
}

Matrix Matrix::subtract(Matrix &m2)
{
    if(rows()!=m2.rows()||cols()!=m2.cols()) throw DiffrentSizesOfMatricesException();
    Matrix ret = Matrix(rows(),cols());
    double temp;
    for(int i = 0; i<r; i++)
        for(int j = 0; j<c; j++)
        {
            temp = data[i][j];
            temp -= m2.get(i,j); 
            ret.set(i,j,temp);
        }
    return ret;  
}

Matrix Matrix::operator-(Matrix &m2)
{
    return subtract(m2);
}

Matrix Matrix::multiply(Matrix &m2)
{
    if(cols()!=m2.rows()) throw CannotMultiplyException();
    Matrix ret = Matrix(rows(),m2.cols());
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
            ret.set(row,col,sum);
        }
    return ret;  
}

Matrix Matrix::operator*(Matrix &m2)
{
    return multiply(m2);
}

Matrix Matrix::transpose()
{
    Matrix ret = Matrix(cols(),rows());
    for(int i = 0; i<r; i++)
        for(int j = 0; j<c; j++)
        {
            try
            {
                ret.set(j,i,data[i][j]);
            }
            catch(const exception& e)
            {
                throw e;
            }
        }
    
    return ret;
}

bool Matrix::operator==(Matrix &m2)
{
    if(r==m2.rows()&&c==m2.cols())
    {
        for(int i = 0; i<r; ++i)
        {
            for(int j = 0; j<c; ++j) if(data[i][j]!=m2.data[i][j]) return false;
            return true;
        }
    }
    return false;
}

int Matrix::cols()
{
    return c;
}

int Matrix::rows()
{
    return r;
}

bool Matrix::displayable()
{
    return (c<=5 && r<=5);
}

void Matrix::resize(int n, int m)
{
    // r,c - w starej macierzy
    // n,m - w nowej macierzy
    double** newdata = new double*[n];
    for(int i = 0; i<n; i++)
    {
        newdata[i] = new double[m];
        for(int j = 0; j<m; j++)
        {
            if(i<r && j<c)
                newdata[i][j] = data[i][j];
            else
                newdata[i][j] = 0.0;
        }
    }

    for(int i = 0; i<r; i++)
    {
        delete data[i];
    }
    delete data;
    data = newdata;
    r=n;
    c=m;
}


void Matrix::save(string path)
{
    fstream file;
    file.open(path, ios::out);
    if(!file) throw FileFailedToOpenException(path);
    file << r << ' ' << c << "\n";
    for(int i = 0; i<r; i++)//rows
    {
        for(int j = 0; j<c; j++)//columns
        {
            file << data[i][j] << ' ';
        }
        file << "\n";
    }
    file.close();
}

Matrix::Matrix(string path)
{
    fstream file;
    file.open(path, ios::in);
    if(!file)
    {
        //cout << "(!) Nie mozna otworzyc pliku " << path << endl;
        exit(-11);
    }
    file >> r >> c;
    if(r<=0 || c<=0)
    {
        //cout << "(!) Plik " << path << " zawiera niepoprawne dane." << endl;
        //cout << "(!) Przerywanie pracy programu." << endl;
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
                //cout << "(!) Plik " << path << " zawiera niepoprawne dane." << endl;
                //cout << "(!) Przerywanie pracy programu." << endl;
                file.close();
                exit(-13);
            }
        }
    }
    //cout << "(i) Plik odczytano pomyslnie.\n";
    file.close();
}

