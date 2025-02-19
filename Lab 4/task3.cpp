#include <iostream>
#include <string>

using namespace std;

class Car {
private:
    string brand;
    string model;
    float price;
    bool available;

public:
    Car() {
        brand = "unknown";
        model = "generic";
        price = 10;
        available = true;
    }

    Car(string brand1, string m, float rent, bool a) {
        brand = brand1;
        model = m;
        price = rent;
        available = a;
    }

    Car(const Car &other) {
        brand = other.brand;
        model = other.model;
        price = other.price;
        available = other.available;
        cout << "Copy constructor called: Car copied successfully.\n";
    }

    ~Car() {
        cout << "Destructor called: " << brand << " " << model << " is being deleted.\n";
    }

    void updateDetails(string brand1, string m, float rent) {
        brand = brand1;
        model = m;
        price = rent;
    }

    void rentCar() {
        if (available) {
            cout << "Car rented successfully!\n";
            available = false;
        } else {
            cout << "Car already rented out.\n";
        }
    }

    void displayDetails() const {
        cout << "Car Brand: " << brand << endl;
        cout << "Car Model: " << model << endl;
        cout << "Price: $" << price << endl;
        if(available){
            cout<<"Car Available for rent.\n";
        }
        else{
            cout<<"Car already rented out\n";
        }
    }
};

int main() {
    Car Car1("Toyota", "Supra", 15000, true);
    
    cout << "Original Car Details:\n";
    Car1.displayDetails();

    Car Car2(Car1);
    
    cout << "\nCopied Car Details(Before):\n";
    Car2.displayDetails();

    cout << "\nUpdating Original Car Details...\n";
    Car1.updateDetails("Suzuki", "Mehran", 600);

    cout << "\nOriginal Car Details(After):\n";
    Car1.displayDetails();

    cout << "\nCopied Car Details: \n";
    Car2.displayDetails();

    return 0;
}
