#include <iostream>
using namespace std;

class Patient
{
protected:
    string name;
    string ID;

public:
    Patient(string name, string ID) : name(name), ID(ID)
    {
    }
    virtual void displayTreatment() = 0;
    virtual void calculateCost() = 0;
};
class inPatient : public Patient
{
public:
    inPatient(string name, string ID) : Patient(name, ID)
    {
    }
    void displayTreatment()
    {
        cout << "InPatient Name: " << name << endl;
    }
    void calculateCost()
    {
        cout << "Cost: RS 10000" << endl;
    }
};
class outPatient : public Patient
{
public:
    outPatient(string name, string ID) : Patient(name, ID)
    {
    }
    void displayTreatment()
    {
        cout << "OutPatient Name: " << name << endl;
    }
    void calculateCost()
    {
        cout << "Cost: RS 15000" << endl;
    }
};
int main()
{
    inPatient inpatient1("Talha", "834");
    outPatient outpatient1("Rameel", "758");
    Patient *p1;
    p1 = &inpatient1;
    p1->displayTreatment();
    p1->calculateCost();

    p1 = &outpatient1;
    p1->displayTreatment();
    p1->calculateCost();
}
