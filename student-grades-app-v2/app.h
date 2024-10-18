#pragma once

#include <iostream>

#include "student.h"

using namespace std;

void printHeader();

void printMenu();

void readData(string filename, List<Student> *students, int capacity);

void updateStudentMarks(List<Student> *students, int minMark, int maxMark);

void printAllStudents(List<Student> *students);

void printTopStudents(List<Student> *students);

void printGradeStats(List<Student> *students);

double getAverageMark(List<Student> *students);

double getPassRate(List<Student> *students);

int validateInt(int lowerLimit, int upperLimit);

void printTableRow(Student *student);

void printTableHeader();

string printLine(int length);