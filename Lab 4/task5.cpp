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
    int carId;

public:
    Car() {
        brand = "unknown";
        model = "generic";
        price = 10;
        available = true;
        revenue = new float(0.0);
    }

    Car(string brand1, string m, float rent, bool a, int id) {
        brand = brand1;
        model = m;
        price = rent;
        available = a;
        revenue = new float(0.0);
        carId = id;
    }
    
    Car(const Car &other) {
        brand = other.brand;
        model = other.model;
        price = other.price;
        available = other.available;
        revenue = other.revenue;
        carId = other.carId;
        cout << "Copy constructor called: Car copied successfully.\n";
    }

    ~Car() {
        cout << "Destructor called: " << brand << " " << model << " is being deleted.\n";
        delete revenue;
    }

    void updateDetails(string brand1, string m, float rent, int id) {
        brand = brand1;
        model = m;
        price = rent;
        carId = id;
    }

    bool checkavailable() {
        return available;
    }

    void rentCar(int days) {
        float rentPrice;
        if(available) {
            cout<<"Car ID: "<< carId << endl;
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
        cout<<"Car ID: "<< carId << endl;
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
    Car car1("Toyota", "Supraa", 15000, true, 100);
    Car car2("Suzuki", "Mehran", 600, true, 101);
    
    car1.displayDetails();
    
    car1.updateDetails("Toyota", "Supraa", 15500, 100);
    car1.checkavailable();
    car1.rentCar(8);
    car1.checkRevenue();
    
    car2.displayDetails();
    car2.checkavailable();
    car2.rentCar(12);
    car2.checkRevenue();




    return 0;
}
