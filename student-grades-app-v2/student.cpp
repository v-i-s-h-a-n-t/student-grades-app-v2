#include <iostream>
#include <string> 

#include "student.h"

using  namespace std;

Student::Student() 
{
    id = "0";
    coursework = 0.0;
    finalExam = 0.0;
}

Student::Student(string id, double coursework, double finalExam) {
	this->id = id;
	this->coursework = coursework;
	this->finalExam = finalExam;
}

Student::~Student(){}

void Student::setId(string id)
{
	this->id = id;
}

string Student::getId()
{
	return id;
}

void Student::setCoursework(double coursework)
{
	this->coursework = coursework;
}

double Student::getCoursework()
{
	return coursework;
}

void Student::setFinalExam(double finalExam)
{
	this->finalExam = finalExam;
}

double Student::getFinalExam()
{
	return finalExam;
}

double Student::getTotalMark() {
	return coursework + finalExam;
}

// Calaulalte student grade based on total mark
string Student::getGrade()
{
    const int GRADE_A_PLUS_MIN = 85;
    const int GRADE_A_MIN = 78;
    const int GRADE_B_PLUS_MIN = 71;
    const int GRADE_B_MIN = 64;
    const int GRADE_C_PLUS_MIN = 57;
    const int GRADE_C_MIN = 50;
    const int GRADE_D_MIN = 40;

    double totalMark = this->getTotalMark();

    if (totalMark >= GRADE_A_PLUS_MIN)
    {
        return "A+";
    }
    else if (totalMark >= GRADE_A_MIN)
    {
        return "A";
    }
    else if (totalMark >= GRADE_B_PLUS_MIN)
    {
        return "B+";
    }
    else if (totalMark >= GRADE_B_MIN)
    {
        return "B";
    }
    else if (totalMark >= GRADE_C_PLUS_MIN)
    {
        return "C+";
    }
    else if (totalMark >= GRADE_C_MIN)
    {
        return "C";
    }
    else if (totalMark >= GRADE_D_MIN)
    {
        return "D";
    }
    else
    {
        return "E";
    }
}


