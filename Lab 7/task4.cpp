#include <iostream>
using namespace std;

class Person
{
protected:
    string name;
    int age;
    string contact;
    string address;

public:
    Person(string name, int age, string contact, string address = "-") : name(name), age(age), contact(contact), address(address) {}

    virtual void displayinfo()
    {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Contact: " << contact << endl;
        if (!address.empty())
        {
            cout << "Address: " << address << endl;
        }
    }
    virtual void updateinfo(string name1, int age1, string contact1, string address1)
    {
        name = name1;
        age = age1;
        contact = contact1;
        address = address1;
    }
};

class Patient : public Person
{
private:
    int patientID;
    string medicalHistory;
    string doctorAssigned;

public:
    Patient(string name, int age, string contact, int patientID, string medicalHistory, string doctorAssigned, string address = "-") : Person(name, age, contact, address), patientID(patientID), medicalHistory(medicalHistory), doctorAssigned(doctorAssigned) {}

    void displayinfo() override
    {
        Person::displayinfo();
        cout << "Patient ID: " << patientID << endl;
        cout << "Medical History: " << medicalHistory << endl;
        cout << "Doctor Assigned: " << doctorAssigned << endl;
    }
};

class Doctor : public Person
{
private:
    string specialization;
    double fee;
    int patientList;

public:
    Doctor(string name, int age, string contact, string specialization, double fee, int patientList, string address = "-") : Person(name, age, contact, address), specialization(specialization), fee(fee), patientList(patientList) {}

    void displayinfo() override
    {
        Person::displayinfo();
        cout << "Specialization: " << specialization << endl;
        cout << "Fee: " << fee << endl;
        cout << "Number of patients: " << patientList << endl;
    }
};

class Nurse : public Person
{
private:
    string assignedWard;
    string shiftTimings;

public:
    Nurse(string name, int age, string contact, string assignedWard, string shiftTimings, string address = "-") : Person(name, age, contact, address), assignedWard(assignedWard), shiftTimings(shiftTimings) {}

    void displayinfo() override
    {
        Person::displayinfo();
        cout << "Assigned Ward: " << assignedWard << endl;
        cout << "Shift Timings: " << shiftTimings << endl;
    }
};

class Administrator : public Person
{
private:
    string department;
    double salary;

public:
    Administrator(string name, int age, string contact, string department, double salary, string address = "") : Person(name, age, contact, address), department(department), salary(salary) {}

    void displayinfo() override
    {
        Person::displayinfo();
        cout << "Administrator Department: " << department << endl;
        cout << "Salary: $" << salary << endl;
    }
    void updateinfo(string name1, int age1, string contact1, string address1, string deptartment1, double salary1)
    {
        Person::updateinfo(name1, age1, contact1, address1);
        department = deptartment1;
        salary = salary1;
    }
};

int main()
{
    Person *ptr;

    Patient patient1("kamran", 19,"03410277451", 834, "Cancer", "Dr. Talha", "Karachi");
    Doctor doctor1("Dr. Talha", 35, "03654514528", "Cancer Tretment", 150000.0, 4, "Karachi");
    Nurse nurse1("Sidra", 25, "031245698742", "Child Ward", "Day", "Islamabad");
    Administrator administrator1("Ali", 30, "03621458968", "Health", 150000.0, "Lahore");

    ptr = &patient1;
    ptr->displayinfo();

    ptr = &doctor1;
    ptr->displayinfo();

    ptr = &nurse1;
    ptr->displayinfo();

    
    ptr = &administrator1;
    ptr->displayinfo();

    administrator1.updateinfo("Junaid", 32, "03254178953", "Lahore", "Health", 250000);
    ptr->displayinfo();

    return 0;
}
