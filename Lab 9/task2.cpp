#include <iostream>
using namespace std;
class MenuItem
{
protected:
    string dishName;
    double price;

public:
    MenuItem(string name, double price) : dishName(name), price(price)
    {
    }
    virtual void showDetails() = 0;
    virtual void prepare() = 0;
};
class Appetizer : public MenuItem
{
public:
    Appetizer(string name, double price) : MenuItem(name, price)
    {
    }
    void showDetails()
    {
        cout << "Appetizer Dish Name: " << dishName << endl;
        cout << "Price: " << price << endl;
    }
    void prepare()
    {
        cout << dishName << " is preparing!!!" << endl;
    }
};
class Maincourse : public MenuItem
{
public:
    Maincourse(string name, double price) : MenuItem(name, price)
    {
    }
    void showDetails()
    {
        cout << "Main Dish Name: " << dishName << endl;
        cout << "Price: " << price << endl;
    }
    void prepare()
    {
        cout << dishName << " is preparing!!!" << endl;
    }
};
int main()
{
    Appetizer appetizer1("Burger", 849);
    Maincourse maincourse1("Pizza", 1949);

    MenuItem *d1;
    d1 = &appetizer1;
    d1->showDetails();
    d1->prepare();

    d1 = &maincourse1;
    d1->showDetails();
    d1->prepare();
}
