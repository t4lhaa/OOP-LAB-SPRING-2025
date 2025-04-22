#include "LectureCourse.h"
#include <iostream>
using namespace std;

LectureCourse::LectureCourse(string courseCode, int credits) : Course(courseCode, credits) {}

void LectureCourse::displayInfo()
{
    cout << "Lecture Course: " << courseCode << " | Credits: " << credits << endl;
}

void LectureCourse::calculateGrade()
{
    cout << "Final Grade of Lecture: 90" << endl;
}
