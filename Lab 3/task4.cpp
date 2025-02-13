#include <iostream>
#include <string>

using namespace std;

class Car{
private:
    string brand;
    string model;
    double fuelCapacity;
    double currentFuel;

public:
    Car(string b, string mod, double capacity)
    {
        brand = b;
        model = mod;
        fuelCapacity = capacity;
        currentFuel = capacity;
    }

    void fuelConsumption(double distance)
    {
        double fuelNeeded = distance * 0.1;
        if (fuelNeeded > currentFuel)
        {
            cout << "Not enough fuel to drive " << distance << " km.\n";
        }
        else
        {
            currentFuel = currentFuel - fuelNeeded;
            cout << distance << " km driven. " << currentFuel << "L Fuel left. \n";
        }
        if (currentFuel < 15)
        {
            cout << "Low fuel!\n";
        }
    }

    void refuel(double amount)
    {
        if (amount + currentFuel > fuelCapacity)
        {
            currentFuel = fuelCapacity;
            cout << "Tank full!\n";
        }
        else
        {
            currentFuel = currentFuel + amount;
            cout << "Added " << amount << "L. Fuel now: " << currentFuel << "L\n";
        }
    }

    void displayCurrentStatus()
    {
        cout << brand << " " << model << " - Fuel: " << currentFuel << "-" << fuelCapacity << "L\n";
    }
};

int main()
{
    string b, m;
    double cap, dist, fuel;
    int choice;

    cout << "Enter car brand: ";
    getline(cin, b);
    cout << "Enter car model: ";
    getline(cin, m);
    cout << "Enter fuel capacity: ";
    cin >> cap;

    Car car(b, m, cap);

    do
    {
        cout << "\n1. Drive"<<endl;
        cout<<"2.Refuel"<<endl;
        cout<<"3.Check Status"<<endl;
        cout<<"4.Exit"<<endl;
        cout<<"Enter your Choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter distance to drive: ";
            cin >> dist;
            car.fuelConsumption(dist);
            break;
        case 2:
            cout << "Enter fuel amount to refuel: ";
            cin >> fuel;
            car.refuel(fuel);
            break;
        case 3:
            car.displayCurrentStatus();
            break;
        case 4:
            cout << "Goodbye!\n";
            break;
        default:
            cout << "Invalid choice!\n";
        }
    } while (choice != 4);

    return 0;
}
