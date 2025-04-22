#pragma once

#include "course.h"

class LectureCourse : public Course
{
public:
    LectureCourse(string courseCode, int credits);

    void calculateGrade() override;
    void displayInfo() override;
};
