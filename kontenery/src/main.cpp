#include <HRMS.h>

int main()
{
    cout << "Hello world" << endl;
    HRMS baza;
    baza.add(Employee("0","Anna","A.","A. Manager"),"dep1",15000.0);
    baza.add(Employee("1","Bartlomiej","B.","B. Manager"),"dep1",27000.0);
    baza.add(Employee("2","Maciej","M.","M. Manager"),"dep2",5000.0);
    baza.add(Employee("2","Radoslaw","R.","R. Manager"),"dep2",10000.0);
    baza.printDepartment("dep1");
    baza.printSalaries();
    baza.changeSalary("2",6400.0);
    baza.printSalaries();
    baza.printSalariesSorted();
    baza.printSalaries();
}