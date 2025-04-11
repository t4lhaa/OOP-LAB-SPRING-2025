#include <iostream>
using namespace std;

class Product
{
protected:
    int ID;
    string name;
    double price;
    int quantity;

public:
    Product(int ID, string name, double price, int quantity = 0) : ID(ID), name(name), price(price), quantity(quantity) {}

    virtual void applyDiscount(double amount)
    {
        price -= amount;
    }

    virtual void calculateTotalPrice(int quantity)
    {
        price *= quantity;
    }

    virtual void displayInfo()
    {
        cout << "Product ID: " << ID << endl;
        cout << "Name: " << name << endl;
        cout << "Price: " << price << endl;
        cout << "Stock quantity: " << quantity << endl;
    }
    Product operator+(const Product &o)
    {
        double total;
        total = price + o.price;
        cout << "Total price is: " << total << endl;
    }
};

class Electronics : public Product
{
protected:
    int warranty;
    string brand;

public:
    Electronics(int ID, string name, double price, int warranty, string brand, int quantity = 0) : Product(ID, name, price, quantity), warranty(warranty), brand(brand) {}

    void displayInfo() override
    {
        Product::displayInfo();
        cout << "Warranty Period: " << warranty << " years" << endl;
        cout << "Brand: " << brand << endl;
    }
};

class Clothing : public Product
{
protected:
    int size;
    string color;
    string fabric;

public:
    Clothing(int ID, string name, double price, int size, string color, string fabric, int quantity = 0) : Product(ID, name, price, quantity), size(size), color(color), fabric(fabric) {}

    void applyDiscount(double amount)
    {
        Product::applyDiscount(amount);
        cout << "Discounted Price of cloth is: " << price << endl;
    }
};

class FoodItem : public Product
{
protected:
    int calories;
    string expiryDate;

public:
    FoodItem(int ID, string name, double price, int calories, string expiryDate, int quantity = 0) : Product(ID, name, price, quantity), calories(calories), expiryDate(expiryDate) {}

    void calculateTotalPrice(int quantity)
    {
        Product::calculateTotalPrice(quantity);
        cout << "Total Price of food is: " << price << endl;
    }
};

class Book : public Product
{
protected:
    string author;
    string genre;

public:
    Book(int ID, string name, double price, string author, string genre, int quantity = 0) : Product(ID, name, price, quantity), author(author), genre(genre) {}

    void displayInfo() override
    {
        Product::displayInfo();
        cout << "Author: " << author << endl;
        cout << "Genre: " << genre << endl;
    }
};

int main()
{
    Product *ptr;

    Electronics electronic(101, "Watch", 2000, 3, "Apple", 4);
    Clothing cloth(102, "Hoodie", 750.5, 'M', "Black", "Cotton", 7);
    FoodItem food(103, "Nutella", 500.6, 2500, "24-12-2027", 10);
    Book book1(104, "The Alchemist", 200, "Paulo Coelho", "Fiction", 8);

    ptr = &electronic;
    ptr->displayInfo();
    ptr = &cloth;
    ptr->applyDiscount(5);
    ptr = &food;
    ptr->calculateTotalPrice(10);
    ptr = &book1;
    ptr->displayInfo();

    cloth.calculateTotalPrice(5);
    cout << "Bulk purchase calculation of cloth and food!! " << endl;
    cloth + food;
    return 0;
}
