#include <iostream>
using namespace std;

class Employee
{
protected:
    string name;
    float salary;

public:
    Employee(string name, float salary) : name(name), salary(salary) {}

    void displayDetails()
    {
        cout << "Employee name: " << name << endl;
        cout << "Employee Salary: $" << salary << endl;
    }
};

class Manager : public Employee
{
protected:
    float bonus;

public:
    Manager(string name, float salary, float bonus) : Employee(name, salary), bonus(bonus) {}

    void displayDetails()
    {
        Employee::displayDetails();
        cout << "Bonus: $" << bonus << endl;
    }
};

int main()
{
    Manager m("Talha", 500000, 250000);
    m.displayDetails();

    return 0;
}
