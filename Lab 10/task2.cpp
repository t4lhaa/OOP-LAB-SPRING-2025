#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

class FileHandler
{
private:
    string fileName;

public:
    FileHandler(const string &file) : fileName(file) {}

    bool readVehicle()
    {
        ifstream in(fileName);

        if (!in)
        {
            cout << "ERROR: Could not open " << fileName << " file!!!!!!!!" << endl;
            return 0;
        }

        string line;
        while (getline(in, line))
        {
            if (line.empty() || line.substr(0, 2) == "//")
                continue;
            istringstream ss(line);
            string type, id, name, year, extraData, certification;

            getline(ss, type, ',');
            getline(ss, id, ',');
            getline(ss, name, ',');
            getline(ss, year, ',');
            getline(ss, extraData, ',');
            getline(ss, certification, ',');

            cout << "Type: " << type << endl;
            cout << "ID: " << id << endl;
            cout << "Name: " << name << endl;
            cout << "Year: " << year << endl;
            cout << "ExtraData: " << extraData << endl;
            cout << "Certification: " << certification << endl;
        }

        in.close();
        return 1;
    }
};

int main()
{
    FileHandler reader("vehicles.txt");
    reader.readVehicle();
    return 0;
}
