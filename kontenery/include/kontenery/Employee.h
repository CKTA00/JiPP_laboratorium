#include <iostream>
#include <iomanip>
using namespace std;

class Employee
{
    //static int new_id;
    string id;
    string name;
    string surname;
    string departmentId;
    string position;
    public:
    Employee(string id, string name, string surname, string position);
    string getid();
    string getdepid();
    void setData(string name, string surname, string position);
    //int printData();
    const static string tabHeader;
    void printTab();
    //Employee(string name, string surname, string position);
};