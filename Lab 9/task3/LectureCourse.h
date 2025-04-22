#pragma once

#include "course.h"

class LectureCourse : public Course
{
public:
    LectureCourse(string courseCode, int credits);

    void calculateGrade(string grade) override;
    void displayInfo() override;
};
