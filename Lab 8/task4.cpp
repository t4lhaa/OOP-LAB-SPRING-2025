#include <iostream>
using namespace std;

class Car
{
private:
    string model;
    int price;

    friend class InventoryManager;

    friend void compareCars(const Car &obj1, const Car &obj2);

public:
    Car(string model, long int price) : model(model), price(price) {}
};
class InventoryManager
{

public:
    void displayDetails(Car &car)
    {
        cout << "Car Details " << endl;
        cout << "Model: " << car.model << " " << endl;
        cout << "Price: " << car.price << " " << endl;
    }

    void updateCar(Car &c)
    {

        int price;
        cout << "Enter New Price: ";
        cin >> price;
        c.price = price;
        cout << "Price Updated!!!!" << endl;
    }
};

void compareCars(const Car &obj1, const Car &obj2)
{
    if (obj1.price > obj2.price)
    {
        cout << "Car " << obj1.model << " is expensive than Car " << obj2.model << endl;
    }
    else if (obj1.price < obj2.price)
    {
        cout << "Car " << obj2.model << " is expensive than Car " << obj1.model << endl;
    }
    else
    {
        cout << "Both Car's price is equal." << endl;
    }
}

int main()
{
    InventoryManager showroom;

    Car car1("Audi E-Tron GT", 4500);
    showroom.displayDetails(car1);
    
    Car car2("Mercedes Benz", 10000);
    showroom.displayDetails(car2);
    compareCars(car1, car2);

    cout<<"\nUpdating Details of Car1"<<endl;
    showroom.updateCar(car1);
    cout<<"New Details of Car1"<<endl;
    showroom.displayDetails(car1);

    return 0;
}
