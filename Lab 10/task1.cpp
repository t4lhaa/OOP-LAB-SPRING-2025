#include <iostream>
#include <fstream>
#include <string>
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
            cout << line << endl;
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
