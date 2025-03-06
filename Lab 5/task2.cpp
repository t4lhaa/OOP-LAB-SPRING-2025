#include <iostream>
using namespace std;

class Student
{
private:
    int ID;
    string name;
    int count;
    int *scores;

public:
    Student(int ID, string name, int scores[], int count) : ID(ID), name(name), count(count)
    {
        this->scores = new int[count];
        for (int i = 0; i < count; i++)
        {
            this->scores[i] = scores[i];
        }
    }
    Student(const Student &s)
    {
        ID = s.ID;
        name = s.name;
        count = s.count;
        this->scores = new int[s.count];
        for (int i = 0; i < s.count; i++)
        {
            this->scores[i] = s.scores[i];
        }
    }

    ~Student()
    {
        delete[] scores;
    }

    void display()
    {
        cout << "Student ID: " << ID << endl;
        cout << "Student Name: " << name << endl;
        cout << "Exam Scores: ";
        for (int i = 0; i < count; i++)
        {
            if(!i<count-1 && !i==0){
                cout << ", " ;
            }
            cout<< scores[i];
        }
    }
};

int main()
{
    int scores[] = {61, 56, 73};
    Student s1(834, "Talha", scores, 3);
    s1.display();

    cout << endl;
    Student s2 = s1;
    s2.display();

    return 0;
}
