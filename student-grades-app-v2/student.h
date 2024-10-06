#pragma once

#include <iostream>

class Student
{
private:
	string id;
	double coursework;
	double finalExam;

public:
	Student();
	~Student();

	void setId(string id);
	string getId();

	void setCoursework(double coursework);
	double getCoursework();

	void setFinalExam(double finalExam);
	double getFinalExam();
};

