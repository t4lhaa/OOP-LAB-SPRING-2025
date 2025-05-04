#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

class InventoryItem
{
private:
    int itemID;
    char itemName[50];

public:
    InventoryItem() : itemID(0)
    {
        itemName[0] = '\0';
    }
    InventoryItem(int id, const char *name)
    {
        itemID = id;
        strncpy(itemName, name, sizeof(itemName) - 1);
        itemName[sizeof(itemName) - 1] = '\0';
    }

    void displayItem() const
    {

        cout << "Loaded item from file:\n";
        cout << "Item ID: " << itemID << endl;
        cout << "Item Name: " << itemName << endl;
    }

    void saveToFile(const string &filename) const
    {
        ofstream out(filename, ios::binary);
        if (!out)
        {
            cerr << "Error: Could not open file for writing!!!!!!!!\n";
            return;
        }
        out.write(reinterpret_cast<const char *>(this), sizeof(*this));
        out.close();
    }

    void loadFromFile(const string &filename)
    {
        ifstream in(filename, ios::binary);
        if (!in)
        {
            cerr << "Error: Could not open file for reading!!!!!!!!!!\n";
            return;
        }
        in.read(reinterpret_cast<char *>(this), sizeof(*this));
        in.close();
    }
};

int main()
{
    InventoryItem item1(834, "Paani");
    item1.saveToFile("inventory.dat");

    InventoryItem item2;
    item2.loadFromFile("inventory.dat");

    item2.displayItem();

    return 0;
}
