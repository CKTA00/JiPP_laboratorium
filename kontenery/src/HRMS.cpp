#include <HRMS.h>

HRMS::HRMS()
{
    cout << "Data base of employees has been created.\n";
}

void HRMS::add(Employee employee, string departmentId, double salary)
{
    employees.push_back(employee);
    //idToSalary.insert(pair<string, double>(employee.getid(), salary));
    idToSalary.push_back(make_pair(employee.getid(),salary));
    idToDepID.insert(pair<string, string>(employee.getid(), departmentId));
}

void HRMS::changeSalary(string employeeId, double salary)
{
    for(vector<pair<string,double>>::iterator it = idToSalary.begin(); it<idToSalary.end(); it++)
    {
        if(it->first == employeeId)
        {
            it->second = salary;
            break;
        }
    }
    // Gdybym używał mapy, zapis by się skrócił
    //idToSalary[employeeId]=salary;
    // Ale wtedy miałem problemy z sortowaniem, więcej o tym nizej
}

void HRMS::printDepartment(string departmentId)
{
    cout << "\n ALL EMPLOYEES OF DEPARTMENT: " << departmentId << endl;
    cout << Employee::tabHeader << endl;
    for(vector<Employee>::iterator it = employees.begin(); it != employees.end(); it++)
    {
        //if(it->getdepid()==departmentId) //mapowanie nie jest potrzebne kiedy mamy pole deartmentID w klasie Employee
        if(idToDepID[it->getid()]==departmentId) // ale skoro jest to go użyjmy, kiedyś można będzie dodać klase departamentu
        {
            it->printRow();
            cout << endl;
        }
    }

    // to poniżej wyświetla samo id. Sby dobrać się do pól Employee, trzeba by było szukać.
    // Lepiej przejśc po każdym pracowniku raz pętlą jak wyżej
    //for(map<string,string>::iterator it = IDtoDepID.begin(); it != IDtoDepID.end(); it++) 
        //if(it->second==departmentId) 
            //cout << it->second  <<setw(13) << " " << "| " << it->first << endl;
}

void HRMS::printSalaries()
{
    cout << "\n ALL SALARIES:" << endl; 
    cout <<  "| Salary     " << Employee::tabHeader << " Department   |" << endl; // wypisz nagłówek tabelki
    int l = employees.size();
    for(int i = 0; i<l;i++)
    {
        // tu nie musimy znajdywac pracownika poniewaz idToSalary oraz Employees dzielą ten sam indeks wewnętrzny
        // gdyby doszło do rozbudowania projektu i np. sortowania na stałe to nalezalo by wyszukiwac podobnie
        // jak w printSalariesSorted()
        cout << "| " << setw(10) << idToSalary[i].second << " "; // wypisz pensje
        employees[i].printRow(); // wypisz dane z obiektu Employee
        cout << setw(12) << idToDepID[employees[i].getid()] <<  " |" << endl; // wypisz departament
    }
}

bool HRMS::empEarnMore(pair<string, double>& emp, pair<string, double>& than)
{ 
    return emp.second > than.second; 
} 

void HRMS::printSalariesSorted()
{
    cout << "\n ALL SALARIES SORTED:" << endl;
    cout << "| Salary     " << Employee::tabHeader << " Department   |" << endl; // wypisz nagłówek tabelki
    // Na początku chciałem zrobić tak:
    // sort(IDtoSalary.begin(),IDtoSalary.end(),HRMS::empEarnMore);
    // ale map nie da się sortować tą funkcją, dlatego użyłem wektora pary zamiast mapy

    // sort(employees.begin(),employees.end(),HRMS::empEarnMore_);
    // ta opcja nie działa bo metoda empEarnMore_ musi być statyczna, tymczasem używała ona niestatycznego pola idToSalary
    // normalnie bym dał pole salary w klasie Employee ale wymagania zadania mówią inaczej więc zastosowałem następujacy sposób:

    vector<pair<string,double>> temp = idToSalary;
        // kopiujemy bo nie chcemy aby naprawde sie posortoało, tylko wyświetliło sie posortowane
    
    sort(temp.begin(), temp.end(), empEarnMore);
        // sortowanie
    
    for(vector<pair<string,double>>::iterator it = temp.begin(); it != temp.end(); it++)
    {
        cout << "| " << setw(10) << it->second << " "; // wypisuje pensje
        for(vector<Employee>::iterator it2 = employees.begin(); it2<employees.end(); it2++)
        {
            if(it->first == it2->getid()) // znajduje pracownika o danym id 
            {
                it2->printRow(); // wypisuje dane z obiektu Employee
                cout << setw(12) << idToDepID[it2->getid()] << " |"; // wypisuje departament
                break;
            }
        }
        cout << endl;
    }
}