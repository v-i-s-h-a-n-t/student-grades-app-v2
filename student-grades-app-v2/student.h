#pragma once

#include <string> 

using namespace std;

class Student {
private:
	string id;
	double coursework;
	double finalExam;

public:
	Student();
	Student(string id, double coursework, double finalExma);
	~Student();

	void setId(string id);
	string getId();

	void setCoursework(double coursework);
	double getCoursework();

	void setFinalExam(double finalExam);
	double getFinalExam();
	
	double getTotalMark();
	string getGrade();
};



