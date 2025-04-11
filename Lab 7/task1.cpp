#include <iostream>
using namespace std;

class Device
{
protected:
    int ID;
    string name;
    bool status;
    string location;

public:
    Device(int ID, string name, string location) : ID(ID), name(name), status(false), location(location) {}

    virtual void turnOn()
    {
        status = true;
    }
    virtual void turnOff()
    {
        status = false;
    }
    virtual bool getstatus()
    {
        cout << "Staus is: " << (status ? "ON" : "OFF") << endl;
        return status;
    }
    virtual void displayinfo()
    {
        cout << "ID: " << ID << endl;
        cout << "Name: " << name << endl;
        cout << boolalpha << "Status: " << status << endl;
        cout << "location: " << location << endl;
    }
};

class Light : public Device
{
protected:
    int brightnessLevel;
    string colorMode;

public:
    Light(int ID, string name, string location, int brightnessLevel, string colorMode) : Device(ID, name, location), brightnessLevel(brightnessLevel), colorMode(colorMode) {}

    void displayinfo()
    {
        Device::displayinfo();
        cout << "Brightness Level: " << brightnessLevel << endl;
        cout << "Color Mode: " << colorMode << endl;
    }
};

class Thermostat : public Device
{
protected:
    float temperature;
    string mode;
    float targetTemperature;

public:
    Thermostat(int ID, string name, string location, float temperature, string mode, float targetTemperature)
        : Device(ID, name, location), temperature(temperature), mode(mode), targetTemperature(targetTemperature) {}

    bool getstatus()
    {
        cout << name << " is set to " << mode << " mode with current temperature " << temperature << "*C and target temperature " << targetTemperature << "*C" << endl;
    }
};

class SecurityCamera : public Device
{
protected:
    double resolution;
    bool recordingsStatus;
    bool nightVision;

public:
    SecurityCamera(int ID, string name, string location, double resolution, bool nightVision) : Device(ID, name, location), resolution(resolution), recordingsStatus(false), nightVision(nightVision) {}

    void turnOn()
    {
        status = true;
        recordingsStatus = true;
        cout << name << " Starts Recording!!!" << endl;
    }
};

class SmartPlug : public Device
{
protected:
    float powerConsumption;
    int timerSetting;

public:
    SmartPlug(int ID, string name, string location, float powerConsumption, int timerSetting) : Device(ID, name, location), powerConsumption(powerConsumption), timerSetting(timerSetting) {}

    void turnOff()
    {
        status = false;
        cout << name << "Power Usage of " << powerConsumption << " km/h";
    }
};

int main()
{
    Device *ptr1;

    Light Light1(834, "Osaka", "Room", 100, "Cyan");
    Thermostat Thermostat1(835, "Ecobee", "Ceiling", 32.8, "Cooling", 26.0);
    SecurityCamera SecurityCamera1(836, "Huawei", "Parking", 1080, true);
    SmartPlug SmartPlug1(837, "Finti", "ABC", 30, 1);

    ptr1 = &Light1;
    ptr1->displayinfo();

    ptr1 = &Thermostat1;
    ptr1->getstatus();

    ptr1 = &SecurityCamera1;
    ptr1->turnOn();

    ptr1 = &SmartPlug1;
    ptr1->turnOff();

    return 0;
}
