#include <vector>
#include <map>
#include <algorithm>
#include <Employee.h>
using namespace std;

class HRMS
{
    vector<Employee> employees;
    map<string,string> idToDepID; // pierwszy string to id pracownika, a drugi to id departamentu
    vector<pair<string,double>> idToSalary; // pierwszy string to id pracownika, a drugi to pensja
    //  (czemu użyłem wektora par zamiast mapy? - std::map nie działa z funkcją std::sort)

    bool static empEarnMore(pair<string, double>& emp, pair<string, double>& than);
    // Czy 'emp' zarabia więcej niż 'than', musi być statyczna żeby zostać użyta w metodzie std::sort()

    public:
    HRMS();
    void add(Employee employee, std::string departmentId, double salary); //dodaj pracownika
    void printDepartment(std::string departmentId); // wypisz pracowników danego departamentu
    void changeSalary(std::string employeeId, double salary); // zmień pensję pracownika
    void printSalaries(); // wypisz wszystkie pensje
    void printSalariesSorted(); // wypisz wszystkie pensje malejąco

};