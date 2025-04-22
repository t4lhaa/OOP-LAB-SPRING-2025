#include <iostream>
using namespace std;

class Shipment
{
protected:
    string trackingNumber;
    double weight;

public:
    Shipment(string number, double weight) : trackingNumber(number), weight(weight)
    {
    }
    void virtual estimateDeliveryTime() = 0;
    void virtual showDetails() = 0;
};
class AirFreight : public Shipment
{
public:
    AirFreight(string number, double weight) : Shipment(number, weight)
    {
    }
    void estimateDeliveryTime()
    {
        cout << "estimating air deliverly time.........." << endl;
        cout << "For AirFreight it will take atleast 10 days to deliver!!!" << endl;
    }
    void showDetails()
    {
        cout << "Shipment Tracking number : " << trackingNumber << endl;
        cout << "Weight: " << weight << endl;
    }
};
class GroundShipment : public Shipment
{
public:
    GroundShipment(string number, double weight) : Shipment(number, weight)
    {
    }
    void estimateDeliveryTime()
    {
        cout << "estimating air deliverly time.........." << endl;
        cout << "For GroudndShipment it will take maximum 4 to 5 days to deliver!!!" << endl;
    }
    void showDetails()
    {
        cout << "Shipment Tracking number : " << trackingNumber << endl;
        cout << "Weight: " << weight << endl;
    }
};
int main()
{
    Shipment *s1;
    GroundShipment groundShipment1("1234", 59.4);
    AirFreight airFreight1("4321", 122);

    s1 = &groundShipment1;
    s1->showDetails();
    s1->estimateDeliveryTime();

    s1 = &airFreight1;
    s1->showDetails();
    s1->estimateDeliveryTime();
}
