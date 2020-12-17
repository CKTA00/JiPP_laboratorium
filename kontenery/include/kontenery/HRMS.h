#include <vector>
#include <map>
#include <algorithm>
#include <Employee.h>
using namespace std;

class HRMS
{
    vector<Employee> employees;
    map<string,string> idToDepID;
    vector<pair<string,double>> idToSalary;

    bool static empEarnMore(pair<string, double>& emp, pair<string, double>& than);
    //bool empEarnMore(Employee& emp, Employee& than);
    // Czy 'emp' zarabia więcej niż 'than'

    public:
    HRMS();
    void add(Employee employee, std::string departmentId, double salary);
    void printDepartment(std::string departmentId);
    void changeSalary(std::string employeeId, double salary);
    void printSalaries();
    void printSalariesSorted(); //std::algorithm

};