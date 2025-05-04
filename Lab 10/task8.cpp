#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class ConfigEditor
{
private:
    string filename;

public:
    ConfigEditor(const string &fname) : filename(fname) {}

    void createFile(const string &content)
    {
        ofstream outFile(filename);
        if (!outFile)
        {
            cerr << "file can not be created!!!!!!!" << endl;
            return;
        }
        outFile << content << endl;
        outFile.close();
    }

    void modify(streamoff pos, const string &newText)
    {
        ifstream inFile(filename);
        if (!inFile)
        {
            cerr << "file can not read!!!" << endl;
            return;
        }

        string originalLine;
        getline(inFile, originalLine);
        inFile.close();

        string modifiedLine = originalLine;
        modifiedLine.replace(pos, newText.length(), newText);

        ofstream outFile(filename, ios::app);
        if (!outFile)
        {
            cerr << "can not open the file!!!!!!" << endl;
            return;
        }

        outFile << modifiedLine << endl;
        outFile.close();
    }

    void display() const
    {
        ifstream inFile(filename);
        if (!inFile)
        {
            cerr << "can not read file!!!!!!!!!" << endl;
            return;
        }

        string line;
        cout << "Updated file contents:\n";
        while (getline(inFile, line))
        {
            cout << line << endl;
        }

        inFile.close();
    }
};

int main()
{
    ConfigEditor editor("config.txt");

    editor.createFile("AAAAABBBBBCCCCC");
    editor.modify(5, "XXXXX");
    editor.display();

    return 0;
}
