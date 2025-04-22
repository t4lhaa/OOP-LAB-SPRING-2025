#pragma once

#include "course.h"

class LabCourse : public Course
{

public:
    LabCourse(string courseCode, int credits);
    void calculateGrade(string grade) override;
    void displayInfo() override;
};
