#include <iostream>

#include "student.h"

using  namespace std;

Student::Student() 
{
	cout << "Student" << endl;
}
Student::~Student()
{
}

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

void Student::setFinalExam(double coursework)
{
	this->finalExam = finalExam;
}
double Student::getFinalExam()
{
	return finalExam;
}

