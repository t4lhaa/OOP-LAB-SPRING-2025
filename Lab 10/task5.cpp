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
            string type, id, name, yearString, extraData, certification;
            int year;
            
            getline(ss, type, ',');
            getline(ss, id, ',');
            getline(ss, name, ',');
            getline(ss, yearString, ',');
            year = stoi(yearString);
            getline(ss, extraData, ',');
            getline(ss, certification, ',');

            if (type == "AutonomousCar")
            {
                size_t pos = extraData.find(':');
                if (pos != string::npos)
                {
                    string softwareVersionString = extraData.substr(pos + 1);
                    float softwareversion = stof(softwareVersionString);
                    cout << "Software Version is " << softwareversion << " for Vehicle ID \"" << id << "\"" << endl;
                }
            }
            else if (type == "ElectricVehicle")
            {
                size_t pos = extraData.find(':');
                if (pos != string::npos)
                {
                    string batteryCapString = extraData.substr(pos + 1);
                    float batterycapacity = stof(batteryCapString);
                    cout << "Battery Capacity is " << batterycapacity << " for Vehicle ID \"" << id << " \" " << endl;
                }
            }
            else if (type == "HybridTruck")
            {
                size_t cargoColonPos = extraData.find(':');
                size_t pos = extraData.find('|');
                size_t batteryColonPos = extraData.rfind(':');
                if (cargoColonPos != string::npos && pos != string::npos && batteryColonPos != string::npos)
                {
                    string cargoString = extraData.substr(cargoColonPos + 1, pos - cargoColonPos - 1);
                    string batteryString = extraData.substr(batteryColonPos + 1);
                    int cargo = stoi(cargoString);
                    int battery = stoi(batteryString);
                    cout << "Cargo Capacity is " << cargo << " for Vehicle ID \"" << id << " \" " << endl;
                    cout << "Battery Capacity is " << battery << " for Vehicle ID \"" << id << " \" " << endl;
                }
                else
                {
                    cout << "not found" << endl;
                }
            }
            else
            {
                cout << "Warning: Colon ':' not found in ExtraData for Vehicle ID: " << id << "!!!!!!!!!!!!!" << endl;
            }
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
