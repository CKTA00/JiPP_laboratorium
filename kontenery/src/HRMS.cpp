#include <HRMS.h>

HRMS::HRMS()
{
    cout << "Utworzono nową bazę pracowników\n";
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
    cout << "Department ID | Employee ID" << endl;
    

    for(map<string,string>::iterator it = IDtoDepID.begin(); it != IDtoDepID.end(); it++)
    {
        if(it->second==departmentId)
            cout << it->second  <<setw(13) << " " << "| " << it->first << endl;
    }
}

void HRMS::printSalaries()
{
    cout << Employee::tabHeader << "Salary   |" << endl;
    for(vector<Employee>::iterator it = employees.begin(); it != employees.end(); it++)
    {
        //int w = 45;
        //w -= it->printData();
        // cout << string(w, ' ') << "| " << IDtoSalary[it->getid()] << endl;
        it->printTab();
        cout << setw(8) << IDtoSalary[it->getid()] << " |" << endl;
    }
}

void HRMS::printSalariesSorted()
{

}