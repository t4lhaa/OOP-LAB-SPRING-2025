#include <iostream>
using namespace std;

class Ticket
{
protected:
    int id;
    string passengerName;
    double price;
    string date;
    string destination;

public:
    Ticket(int id, string name, double price, string date, string destination) : id(id), passengerName(name), price(price), date(date), destination(destination) {}

    virtual void reserve()
    {
        cout << "Ticket reserved for " << passengerName << " on" << date << " to " << destination << endl;
    }
    virtual void cancel()
    {
        cout << "Ticket cancel for " << passengerName << endl;
    }
    virtual void displayinfo()
    {
        cout << "Ticket ID: " << id << endl;
        cout << "Passenger Name: " << passengerName << endl;
        cout << "Price: " << price << endl;
        cout << "Date: " << date << endl;
        cout << "Destination: " << destination << endl;
    }
};

class FlightTicket : public Ticket
{
protected:
    string airlineName;
    int flightNumber;
    char seatClass;

public:
    FlightTicket(int id, string name, double price, string date, string destination, string airlineName, int flightNumber, char seatClass) : Ticket(id, name, price, date, destination), airlineName(airlineName), flightNumber(flightNumber), seatClass(seatClass) {}

    void displayinfo() override
    {
        Ticket::displayinfo();
        cout << "Airline Name: " << airlineName << endl;
        cout << "Flight Number: " << flightNumber << endl;
        cout << "SeaT Class: " << seatClass << endl;
    }
};

class TrainTicket : public Ticket
{
protected:
    int trainNumber;
    string coachType;
    string departureTime;

public:
    TrainTicket(int id, string name, double price, string date, string destination, int trainNumber, string coachType, string departureTime) : Ticket(id, name, price, date, destination), trainNumber(trainNumber), coachType(coachType), departureTime(departureTime) {}

    void reserve() override
    {
        cout << "Train Ticket reserved for " << passengerName << " on" << date << " to " << destination << " at time " << departureTime << endl;
        cout << "Assigning seats: " << endl;
        int seatNumber = rand() % 100 + 1;
        cout << "Seat Number is: " << seatNumber << endl;
    }
};

class BusTicket : public Ticket
{
protected:
    string busCompany;
    int seatNumber;

public:
    BusTicket(int id, string name, double price, string date, string destination, string busCompany, int seatNumber) : Ticket(id, name, price, date, destination), busCompany(busCompany), seatNumber(seatNumber) {}

    void cancel() override
    {
        cout << "Bus Ticket cancelled for " << passengerName << endl;
        cout << "Refunding Ticket Price " << price << endl;
    }
};

class ConcertTicket : public Ticket
{
protected:
    string artistName;
    string venue;
    string seatType;

public:
    ConcertTicket(int id, string name, double price, string date, string destination, string artistName, string venue, string seatType) : Ticket(id, name, price, date, destination), artistName(artistName), venue(venue), seatType(seatType) {}

    void displayinfo() override
    {
        Ticket::displayinfo();
        cout << "Artist Name: " << artistName << endl;
        cout << "Venue: " << venue << endl;
        cout << "Seat Type: " << seatType << endl;
    }
};

int main()
{
    Ticket *ptr;

    FlightTicket flight(834, "Talha", 5000, "15/4/2025", "Lahore","PIA", 32, 'E');
    TrainTicket train(835, "Aqib", 1200, "6/5/2025", "Lahore",12, "Economy Class", "5:00 PM");
    BusTicket bus(836, "Rameel", 800, "11/5/2025", "Sahiwal","Fardeen", 34);
    ConcertTicket concert(837, "Asad", 2500, "17/4/2025", "Karachi","Young Stunners & Asim Azhar", "FAST-NUCES", "Normal");

    ptr = &flight;
    ptr->displayinfo();

    ptr = &train;
    ptr->reserve();

    ptr = &bus;
    ptr->cancel();

    ptr = &concert;
    ptr->displayinfo();

    return 0;
}
