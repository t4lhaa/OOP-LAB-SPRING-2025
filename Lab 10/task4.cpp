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

            size_t pos = extraData.find(':');
            if (pos != string::npos)
            {
                string extraValueNumber = extraData.substr(pos + 1);

                if (type == "AutonomousCar")
                {
                    float softwareversion = stof(extraValueNumber);
                    cout << "Software Version is " << softwareversion << " for Vehicle ID \"" << id << "\"" << endl;
                }
                else if (type == "ElectricVehicle")
                {
                    float batterycapacity = stof(extraValueNumber);
                    cout << "Battery Capacity is " << batterycapacity << " for Vehicle ID \"" << id << " \" " << endl;
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
