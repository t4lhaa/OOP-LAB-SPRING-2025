#include <iostream>
using namespace std;

class AlarmSystem
{
private:
    string securityLevel;

public:
    AlarmSystem(string securityLevel) : securityLevel(securityLevel)
    {
        cout << "AlarmSystem Class Constructed." << endl;
    }

    string getSecurityLevel()
    {
        return securityLevel;
    }
    ~AlarmSystem()
    {
        cout
            << "AlarmSystem Class destroyed." << endl;
    }
};

class Smarthome
{
private:
    int ID;
    string owner;
    AlarmSystem Alarm;

public:
    Smarthome(int ID, string owner, string securityLevel) : ID(ID), owner(owner), Alarm(securityLevel)
    {
        cout << "SmartHomeClass Constructed." << endl;
    }

    void display()
    {
        cout << "ID: " << ID << endl;
        cout << "Owner Name: " << owner << endl;
        cout << "Alarm system level: " << Alarm.getSecurityLevel() << endl;
    }

    ~Smarthome()
    {
        cout
            << "SmartHome Class destroyed." << endl;
    }
};

int main()
{
    Smarthome s1(834, "Talha", "Medium");
    s1.display();
}
