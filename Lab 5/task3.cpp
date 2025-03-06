#include <iostream>
using namespace std;

class Employee
{
private:
    string name;
    string designation;

public:
    Employee(string name, string designation) : name(name), designation(designation) {}

    string getname()
    {
        return name;
    }
};

class Project
{
private:
    string title;
    string deadline;
    int employeeCount;
    Employee **assignedemployee;

public:
    Project(string title, string deadline) : title(title), deadline(deadline), employeeCount(0)
    {
        assignedemployee = nullptr;
    }

    void addEmployee(Employee *E)
    {
        Employee **temp = new Employee *[employeeCount + 1];
        for (int i = 0; i < employeeCount; i++)
        {
            temp[i] = assignedemployee[i];
        }
        delete[] assignedemployee;
        temp[employeeCount++] = E;
        assignedemployee = temp;
    }

    void display()
    {
        cout << "Project Title: " << title << endl;
        cout << "Project Dealine: " << deadline << endl;
        if (assignedemployee != nullptr)
        {
            cout << "Assigned Employees: " << endl;
            for (int i = 0; i < employeeCount; i++)
            {
                cout << (i + 1) << ". " << assignedemployee[i]->getname() << endl;
            }
        }
        else
        {
            cout << "No employee Found!!" << endl;
        }
    }

    ~Project()
    {
        delete[] assignedemployee;
    }
};

int main()
{
    Project P1("Amazon", "March 19,2025");
    Employee E1("Talha", "Head");
    P1.addEmployee(&E1);
    P1.display();
    Employee E2("Rameel", "Co-Head");
    P1.addEmployee(&E2);
    P1.display();
}
