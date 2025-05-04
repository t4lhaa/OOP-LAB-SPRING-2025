#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class LogReader
{
private:
    ifstream inFile;
    string filename;

public:
    LogReader(const string &filename) : filename(filename) {}

    bool open()
    {
        inFile.open(filename);
        if (!inFile)
        {
            cerr << "Can not open file: " << filename << endl;
            return false;
        }
        return true;
    }

    void read(int count)
    {
        if (!inFile.is_open())
        {
            cerr << "File can not be open!!!!!!!!!." << endl;
            return;
        }

        string line;
        for (int i = 1; i <= count && getline(inFile, line); ++i)
        {
            cout << "Line " << i << ": " << line << endl;
            cout << "Position after line " << i << ": " << inFile.tellg() << endl;
        }
    }

    ~LogReader()
    {
        if (inFile.is_open())
            inFile.close();
    }
};

int main()
{
    LogReader reader("large_log.txt");

    if (!reader.open())
        return 1;

    reader.read(3);
    return 0;
}
