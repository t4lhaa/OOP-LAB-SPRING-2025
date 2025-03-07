#include <iostream>
using namespace std;

class Device
{
protected:
    int deviceID;
    bool status;

public:
    Device(int deviceID, bool status) : deviceID(deviceID), status(status) {}
    void displayDetails()
    {
        cout << "Device ID: " << deviceID << endl;
        if (status)
        {
            cout << "Status: Active" << endl;
        }
        else
        {
            cout << "Status: Not Active" << endl;
        }
    }
};

class SmartPhone : virtual public Device
{
protected:
    float screenSize;

public:
    SmartPhone(int deviceID, bool status, float screenSize) : Device(deviceID, status), screenSize(screenSize) {}

    void displayDetails()
    {
        Device::displayDetails();
        cout << "Screen Size: " << screenSize << " inches" << endl;
    }
};

class SmartWatch : virtual public Device
{
protected:
    bool heartRateMonitor;

public:
    SmartWatch(int deviceID, bool status, bool heartRateMonitor) : Device(deviceID, status), heartRateMonitor(heartRateMonitor) {}

    void displayDetails()
    {
        Device::displayDetails();
        if (heartRateMonitor)
        {
            cout << "Heart Rate Monitor: Available" << endl;
        }
        else
        {
            cout << "Heart Rate Monitor: Not Available" << endl;
        }
    }
};

class SmartWearable : public SmartPhone, public SmartWatch
{
protected:
    int stepCounter;

public:
    SmartWearable(int deviceID, bool status, float screenSize, bool heartRateMonitor, int stepCounter) : Device(deviceID, status), SmartPhone(deviceID, status, screenSize), SmartWatch(deviceID, status, heartRateMonitor), stepCounter(stepCounter) {}
    void displayDetails()
    {
        Device::displayDetails();
        cout << "Screen Size: " << screenSize << " inches" << endl;
        if (heartRateMonitor)
        {
            cout << "Heart Rate Monitor: Available" << endl;
        }
        else
        {
            cout << "Heart Rate Monitor: Not Available" << endl;
        }
        cout << "Step Counter: " << stepCounter << " steps" << endl;
    }
};

int main()
{

    SmartWearable watch(834, true, 6.76, false, 2000);
    watch.displayDetails();

    return 0;
}
