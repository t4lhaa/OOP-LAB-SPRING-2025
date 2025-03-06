#include <iostream>
using namespace std;

class Product
{
private:
    int ID;
    string name;
    int stock;

public:
    Product(int ID, string name, int stock) : ID(ID), name(name), stock(stock) {}

    string getname()
    {
        return name;
    }
    int getID()
    {
        return ID;
    }
};

class Inventory
{
private:
    string name;
    int productCount;
    Product **product;

public:
    Inventory(string name):name(name),productCount(0)
    {
        product = nullptr;
    }

    void addProduct(Product *P)
    {
        Product **temp = new Product *[productCount + 1];
        for (int i = 0; i < productCount; i++)
        {
            temp[i] = product[i];
        }
        delete[] product;
        temp[productCount++] = P;
        product = temp;
    }

    void sortByName()
    {
        for (int i = 0; i < productCount - 1; i++)
        {
            for (int j = i + 1; j < productCount; j++)
            {
                if (product[i]->getname() > product[j]->getname())
                {
                    swap(product[i], product[j]);
                }
            }
        }
    }

    void display()
    {
        cout << "Inventory Name: " << name << endl;
        if (product != nullptr)
        {
            cout << "Products: " << endl;
            for (int i = 0; i < productCount; i++)
            {
                cout << i + 1 << ". " << product[i]->getname() << endl;
            }
        }
        else
        {
            cout << "No Products available!!!" << endl;
        }
    }

    void searchByID(int ID)
    {
        for (int i = 0; i < productCount; i++)
        {
            if (product[i]->getID() == ID)
            {
                cout << "Product Name is : " << product[i]->getname() << endl;
                return;
            }
        }
        cout << "Product not found!" << endl;
    }

    ~Inventory()
    {
        delete[] product;
    }
};

int main()
{
    Inventory warehouse("BCS-2J STORE");

    Product p1(612, "Abdullah", 6);
    warehouse.addProduct(&p1);
    
    Product p2(758, "Rameel", 7);
    warehouse.addProduct(&p2);
    
    Product p3(740, "Irfan", 5);
    warehouse.addProduct(&p3);

    cout << "Before Sorting:"<<endl;
    warehouse.display();
    
    cout << "\nAfter Sorting:\n";
    warehouse.sortByName();
    warehouse.display();

    cout << "\nSearching for Product: "<<endl;
    warehouse.searchByID(758);

    return 0;
}
