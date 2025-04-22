#include <iostream>
using namespace std;
class WeatherSensor
{
public:
    void virtual readData(double data) = 0;
    void virtual displayReport() = 0;
};
class Thermometer : public WeatherSensor
{
    double temp;
public:
    void readData(double data)
    {
        temp=data;
        cout << "Reading data of the Thermometer!!!" << endl;
    }
    void displayReport()
    {
        cout << "Temprature is: " << temp << "'C" << endl;
    }
};
class Barometer : public WeatherSensor
{
public:
double pressure;
    void readData(double data)
    {
        pressure = data;
        cout << "Reading data of the Barometer!!!!" << endl;
    }
    void displayReport()
    {
        cout << "Pressure is: " << pressure << " PA" << endl;
    }
};
int main()
{
    Barometer barometer1;
    Thermometer thermometer1;
    WeatherSensor *w1;

    w1 = &thermometer1;
    w1->readData(25.3);
    w1->displayReport();

    w1 = &barometer1;
    w1->readData(171.6);
    w1->displayReport();

}
