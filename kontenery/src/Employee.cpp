#include <Employee.h>


Employee::Employee(string id, string name, string surname, string position)
{
    this->id = id;
    this->name = name;
    this->surname = surname;
    this->position = position;
}

string Employee::getid()
{
    return id;
}

string Employee::getdepid()
{
    return departmentId;
}

void Employee::setData(string name, string surname, string position)
{
    this->name = name;
    this->surname = surname;
    this->position = position;
}

void Employee::printRow()
{
    cout << "|"<<setw(12) << name << " | " << setw(12) << surname << " | " << setw(12) << position << " | ";
}
////
const string Employee::tabHeader = "| Name        | Surname      | Position     |";
// stała używana jako część nagłówka pasująca do wypisania przez printRow()
