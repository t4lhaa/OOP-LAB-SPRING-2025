#include <iostream>
using namespace std;

class Person
{
protected:
    string name;
    int age;

public:
    Person(string name, int age) : name(name), age(age) {}
    void displayDetails()
    {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
    }
};

class Teacher : virtual public Person
{
protected:
    string subjects;

public:
    Teacher(string name, int age, string subjects) : Person(name, age), subjects(subjects) {}

    void displayDetails()
    {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Subject: " << subjects << endl;
    }
};

class Researcher : virtual public Person
{
protected:
    string researchArea;

public:
    Researcher(string name, int age, string researchArea) : Person(name, age), researchArea(researchArea) {}

    void displayDetails()
    {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Research Area: " << researchArea << endl;
    }
};

class Professor : public Researcher, public Teacher
{
protected:
    int publications;

public:
    Professor(string name, int age, string subjects, string researchArea, int publications) : Person(name, age), Researcher(name, age, subjects), Teacher(name, age, researchArea), publications(publications) {}
    void displayDetails()
    {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Subject: " << subjects << endl;
        cout << "Research Area: " << researchArea << endl;
        cout << "Publications: " << publications << endl;
    }
};

int main()
{
    Professor professor("Talha", 19, "Object-Oriented Programming", "AI", 3);
    professor.displayDetails();

    return 0;
}
