#include <HRMS.h>

HRMS::HRMS()
{
    cout << "Data base of employees has been created.\n";
}

void HRMS::add(Employee employee, string departmentId, double salary)
{
    employees.push_back(employee);
    IDtoSalary.insert(pair<string, double>(employee.getid(), salary));
    IDtoDepID.insert(pair<string, string>(employee.getid(), departmentId));
}

void HRMS::changeSalary(string employeeId, double salary)
{
    //IDtoSalary.find(employeeId);
    IDtoSalary[employeeId]=salary;
}

void HRMS::printDepartment(string departmentId)
{
    cout << " ALL EMPLOYEES OF DEPARTMENT: " << departmentId << endl;
    cout << Employee::tabHeader << endl;
    for(vector<Employee>::iterator it = employees.begin(); it != employees.end(); it++)
    {
        //if(it->getdepid()==departmentId) //mapowanie nie jest potrzebne kiedy mamy pole deartmentID w klasie Employee
        if(IDtoDepID[it->getid()]==departmentId) // ale skoro jest to go użyjmy
        {
            it->printRow();
            cout << endl;
        }
    }

    //for(map<string,string>::iterator it = IDtoDepID.begin(); it != IDtoDepID.end(); it++) 
        //if(it->second==departmentId) 
            //cout << it->second  <<setw(13) << " " << "| " << it->first << endl;
}

void HRMS::printSalaries()
{
    cout << " ALL SALARIES:" << endl;
    cout << Employee::tabHeader << "Salary   |" << endl;
    for(vector<Employee>::iterator it = employees.begin(); it != employees.end(); it++)
    {
        //int w = 45;
        //w -= it->printData();
        // cout << string(w, ' ') << "| " << IDtoSalary[it->getid()] << endl;
        it->printRow();
        cout << setw(8) << IDtoSalary[it->getid()] << " |" << endl;
    }
}

bool HRMS::empEarnMore(pair<string, double>& emp, pair<string, double>& than)
{ 
    return emp.second > than.second; 
} 

// bool HRMS::empEarnMore(Employee& emp, Employee& than)
// { 
//     return IDtoSalary[emp.getid()] > IDtoSalary[than.getid()];
// } 

void HRMS::printSalariesSorted()
{
    cout << " ALL SALARIES SORTED:" << endl;
    cout << Employee::tabHeader << "| Salary   " << endl;
    //sort(employees.begin(),employees.end(),HRMS::empEarnMore); // nie da się tym sposobem

    //sort(IDtoSalary.begin(),IDtoSalary.end());
    //sort(IDtoSalary.begin(),IDtoSalary.end(),empEarnMore);
    //reverse(IDtoSalary.begin(),IDtoSalary.end());
    
    for(map<string,double>::iterator it = IDtoSalary.begin(); it != IDtoSalary.end(); it++)
    {
        cout << "|" << setw(10) << it->second;
    }
}