#include <iostream>
#include "LectureCourse.h"
#include "LabCourse.h"

int main()
{
    Course *c1;
    LectureCourse lecture1("AI4444", 4);
    LabCourse lab1("AIL44444", 2);

    
    c1 = &lecture1;
    c1->calculateGrade("B");
    c1->displayInfo();
    
    c1 = &lab1;
    c2->calculateGrade("A+");
    c2->displayInfo();
}
