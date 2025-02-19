#include <iostream>
#include <string>

using namespace std;

class Car {
private:
    string brand;
    string model;
    float price;
    bool available;
    float* revenue;

public:
    Car() {
        brand = "unknown";
        model = "generic";
        price = 10;
        available = true;
        revenue = new float(0.0);
    }

    Car(string brand1, string m, float rent, bool a) {
        brand = brand1;
        model = m;
        price = rent;
        available = a;
        revenue = new float(0.0);
    }
    
    Car(const Car &other) {
        brand = other.brand;
        model = other.model;
        price = other.price;
        available = other.available;
        revenue = other.revenue;
        cout << "Copy constructor called: Car copied successfully.\n";
    }

    ~Car() {
        cout << "Destructor called: " << brand << " " << model << " is being deleted.\n";
        delete revenue;
    }

    void updateDetails(string brand1, string m, float rent) {
        brand = brand1;
        model = m;
        price = rent;
    }

    void rentCar(int days) {
        float rentPrice;
        if(available) {
            cout <<brand << "-" << model <<" rented successfully for " << days << " days.\n";
            rentPrice = price * days;
            cout<<"Renting Cost: " << rentPrice << endl;
            *revenue += rentPrice;
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
    void checkRevenue() const{
        cout <<"Total revenue so far: $" << *revenue << endl;
        cout<<endl;
    }
};

int main() {
    Car Car1("Toyota", "Supraa", 15000, true);
    
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

    Car1.rentCar(18);
    Car1.checkRevenue();
    Car2.rentCar(11);
    Car2.checkRevenue();

    return 0;
}
