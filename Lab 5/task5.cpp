#include <iostream>
using namespace std;

class Doctor
{
private:
    string name;
    string specialization;
    string experience;

public:
    Doctor(string name, string specialization, string experience) : name(name), specialization(specialization), experience(experience) {}

    string getname()
    {
        return name;
    }
};

class Hospital
{
private:
    string name;
    string location;
    int doctorCount;
    Doctor **assignedDoctors;

public:
    Hospital(string name, string location) : name(name), location(location), doctorCount(0)
    {
        assignedDoctors = nullptr;
    }

    void assignDoctor(Doctor *D)
    {
        Doctor **temp = new Doctor *[doctorCount + 1];
        for (int i = 0; i < doctorCount; i++)
        {
            temp[i] = assignedDoctors[i];
        }
        delete[] assignedDoctors;
        temp[doctorCount] = D;
        doctorCount++;
        assignedDoctors = temp;
    }

    void display()
    {
        cout << "Hospital Name: " << name << endl;
        cout << "Hospital location: " << location << endl;
        if (assignedDoctors != nullptr)
        {
            cout << "Assigned Doctors: " << endl;
            for (int i = 0; i < doctorCount; i++)
            {
                cout << (i + 1) << ". " << assignedDoctors[i]->getname() << endl;
            }
        }
        else
        {
            cout << "No Doctor Found!!" << endl;
        }
    }

    ~Hospital()
    {
        delete[] assignedDoctors;
    }
};

int main()
{
    Hospital h1("Rahat Naval Hospital", "Karsaz");
    Doctor d1("Talha", "Dentist", "8 year");
    h1.assignDoctor(&d1);
    h1.display();
    Doctor d2("Rameel", "Orthopedist", "4 year");
    h1.assignDoctor(&d2);
    h1.display();

    return 0;
}
