#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class SensorLogger
{
private:
    ofstream out;

public:
    SensorLogger(const string &filename)
    {
        out.open(filename);
        if (!out)
        {
            cerr << "Error opening file for writing." << endl;
        }
    }

    ~SensorLogger()
    {
        if (out.is_open())
        {
            out.close();
        }
    }

    void logSensor(const string &sensorName, float value)
    {
        if (!out)
            return;

        out << sensorName << ": " << value << "C\n";
        streampos pos = out.tellp();
        cout << "After " << sensorName << ", Current position is: " << pos << endl;
    }

    bool isOpen() const
    {
        return out.is_open();
    }
};

int main()
{
    SensorLogger logger("sensor_log.txt");

    if (!logger.isOpen())
        return 1;

    logger.logSensor("Sensor1", 23.5f);
    logger.logSensor("Sensor2", 98.1f);

    return 0;
}
