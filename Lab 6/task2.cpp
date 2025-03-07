#include <iostream>
using namespace std;

class Vehicle
{
protected:
    string brand;
    int speed;

public:
    Vehicle(string brand, int speed) : brand(brand), speed(speed) {}
    void displayDetails()
    {
        cout << "Car Information:" << endl;
        cout << "Brand: " << brand << endl;
        cout << "Speed: " << speed << "kmph" << endl;
    }
};

class Car : public Vehicle
{
protected:
    int seats;

public:
    Car(string brand, int speed, int seats) : Vehicle(brand, speed), seats(seats) {}

    void displayDetails()
    {
        Vehicle::displayDetails();
        cout << "Seats: " << seats << endl;
    }
};

class ElectricCar : public Car
{
protected:
    int batteryLife;

public:
    ElectricCar(string brand, int speed, int seats, int batteryLife) : Car(brand, speed, seats), batteryLife(batteryLife) {}

    void displayDetails()
    {
        Car::displayDetails();
        cout << "Battery Life: " << batteryLife << " Days" << endl;
    }
};

int main()
{

    ElectricCar car("Audi E-Tron GT", 290, 4, 21);
    car.displayDetails();

    return 0;
}
