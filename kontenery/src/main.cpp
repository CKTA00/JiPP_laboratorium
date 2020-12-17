#include <HRMS.h>

int main()
{
    HRMS baza;
    baza.add(Employee("0","Anna","A.","A. Manager"),"dep1",3000.0);
    baza.add(Employee("1","Bartlomiej","B.","B. Manager"),"dep1",4000.0);
    baza.add(Employee("2","Celina","C.","C. Manager"),"dep2",12000.0);
    baza.add(Employee("3","Damian","D.","D. Manager"),"dep2",10000.0);
    baza.add(Employee("4","Elenora","E.","E. Manager"),"dep1",8000.0);
    baza.add(Employee("5","Franciszek","F.","F. Manager"),"dep3",5000.0);
    baza.add(Employee("6","Genowefa","G.","G. Manager"),"dep3",5000.0);
    baza.add(Employee("7","Hubert","H.","H. Manager"),"dep3",7000.0);
    baza.add(Employee("8","Irena","I.","I. Manager"),"dep1",6000.0);
    baza.add(Employee("9","Jan","J.","J. Manager"),"dep2",18000.0);
    // przydałaby się funkcja generująca zawsze różne id, ale na potrzeby tego małego zadania pomine to
    baza.printDepartment("dep1");
    baza.printDepartment("dep2");
    baza.printDepartment("dep3");
    baza.printSalaries();

    baza.changeSalary("2",12500.0); // Podwyżka dla Celiny
    baza.printSalariesSorted();

    baza.changeSalary("9",15000.0); // Jan stracił premie
    baza.printSalaries();
}