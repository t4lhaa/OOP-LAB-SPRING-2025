#include "LabCourse.h"
#include <iostream>
using namespace std;

LabCourse::LabCourse(string courseCode, int credits) : Course(courseCode, credits) {}

void LabCourse::displayInfo()
{
    cout << "Lab Course: " << courseCode << " | Credits: " << credits << endl;
}

void LabCourse::calculateGrade(string grade)
{
    cout << "Grade : " << grade << endl;
}
