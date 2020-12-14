#include <vector>
#include <map>
#include <Employee.h>
using namespace std;

class HRMS
{
    vector<Employee> employees;
    map<string,string> IDtoDepID;
    map<string,double> IDtoSalary;

    public:
    HRMS();
    void add(Employee employee, std::string departmentId, double salary);
    void printDepartment(std::string departmentId);
    void changeSalary(std::string employeeId, double salary);
    void printSalaries();
    void printSalariesSorted(); //std::algorithm
};