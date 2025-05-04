#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Record
{
private:
    ifstream inFile;
    string filename;

public:
    Record(const string &filename) : filename(filename) {}

    bool open()
    {
        inFile.open(filename);
        if (!inFile)
        {
            cerr << "File can not be opened: " << filename << endl;
            return false;
        }
        return true;
    }

    void read(streamoff pos)
    {
        if (!inFile.is_open())
        {
            cerr << "File is not open!!!!!!!!" << endl;
            return;
        }

        inFile.seekg(pos, ios::beg);

        string record;
        getline(inFile, record);
        cout << record << endl;
    }

    ~Record()
    {
        if (inFile.is_open())
        {
            inFile.close();
        }
    }
};

int main()
{
    Record reader("data_records.txt");

    if (!reader.open())
    {
        return 1;
    }
    cout << "Third Record: ";
    reader.read(18);

    return 0;
}
