#include <iostream>
#include <fstream>
#include <iomanip>

#include "list.h"
#include "app.h"

using namespace std;

const int COL_WIDTH = 15;
const int ROW_WIDTH = 55;

// ---------------------------- Functions ---------------------------- //

void readData(string filename, List<Student>* students, int capacity)
{
    bool isFull = students->getSize() == capacity;
    ifstream readFile(filename.c_str());

    if (readFile.fail())
    {
        cout << "Oops, could not open file: " << filename << endl;
    }

    string headerOmit;
    getline(readFile, headerOmit);

    string id;
    double coursework;
    double finalExam;

    // Fill array until capacity is not reached and data exists
    while (!isFull && readFile >> id >> coursework >> finalExam)
    {
        // TODO: move node logic inside List (should not use Node<Student> outside List)
        students->appendNode(new Node<Student>(new Student(id, coursework, finalExam)));
    }

    readFile.close();
}

// Helper function to print the table header
void printTableHeader()
{
    cout << setw(COL_WIDTH) << "Student ID"
        << setw(COL_WIDTH) << "CW"
        << setw(COL_WIDTH) << "Final"
        << setw(COL_WIDTH) << "Grade" << endl
        << printLine(ROW_WIDTH) << endl;
}

// Helper function to print a table row (student details)
void printTableRow(Student* student)
{
    cout << setw(COL_WIDTH) << student->getId()
        << setw(COL_WIDTH) << student->getCoursework()
        << setw(COL_WIDTH) << student->getFinalExam()
        << setw(COL_WIDTH) << student->getGrade() << endl
        << printLine(ROW_WIDTH) << endl;
}

void printAllStudents(List<Student>* students)
{
    printTableHeader();

    for (int i = 0; i < students->getSize(); i++)
    {
        printTableRow(students->getNode(i)->getData());
    }
}

void printTopStudents(List<Student>* students)
{
    double highestMark = students->getNode(0)->getData()->getTotalMark();

    //  Loop through all students and get highest mark
    for (int i = 0; i < students->getSize(); i++)
    {
        double totalMark = students->getNode(i)->getData()->getTotalMark();

        if (totalMark >= highestMark)
        {
            highestMark = totalMark;
        }
    }

    printTableHeader();

    // Loop through all students and print those with the highest mark
    for (int i = 0; i < students->getSize(); i++)
    {
        Student* student = students->getNode(i)->getData();

        if (student->getTotalMark() == highestMark)
        {
            printTableRow(student);
        }
    }
}

void printGradeStats(List<Student>* students)
{
    cout << "Average Mark: " << getAverageMark(students) << endl;
    cout << "Pass Rate: " << getPassRate(students) << "%" << endl;
}

double getAverageMark(List<Student>* students)
{
    double totalMarks = 0.0;

    for (int i = 0; i < students->getSize(); i++)
    {
        totalMarks += students->getNode(i)->getData()->getTotalMark();
    }

    return totalMarks / students->getSize();
}

double getPassRate(List<Student>* students)
{
    const int ONE_HUNDRED = 100;

    double passCount = 0.0;

    for (int i = 0; i < students->getSize(); i++)
    {
        string grade = students->getNode(i)->getData()->getGrade();

        if (grade != "D" && grade != "E")
        {
            passCount++;
        }
    }

    return (passCount / students->getSize()) * ONE_HUNDRED;
}

void updateStudentMarks(List<Student>* students, int minMark, int maxMark)
{
    bool studentExists = false;
    int studentIndex;
    string studentId;
    double coursework;
    double finalExam;

    cout << "Enter student Id: ";
    cin >> studentId;

    //  Check if student exists and get their index
    for (int i = 0; i < students->getSize(); i++)
    {
        Student* student = students->getNode(i)->getData();

        if (student->getId() == studentId)
        {
            studentExists = true;
            studentIndex = i;
        }
    }

    if (studentExists)
    {
        cout << "Enter new coursework: ";
        coursework = validateInt(minMark, maxMark);

        cout << "Enter new final exam: ";
        finalExam = validateInt(minMark, maxMark);

        Student* student = students->getNode(studentIndex)->getData();

        student->setCoursework(coursework);
        student->setFinalExam(finalExam);

        cout << "\nStudent details updated successfully!\n\n";

        printTableHeader();
        printTableRow(student);
    }
    else
    {
        cout << "\nOops, student Id: " << studentId << " was not found" << endl;
    }
}

int validateInt(int lowerLimit, int upperLimit)
{
    int input;
    cin >> input;

    while (cin.fail() || (input < lowerLimit || input > upperLimit))
    {
        cin.clear();
        string dummy;
        getline(cin, dummy);

        cout << "\nOops! Something went wrong." << endl;

        // Input is not a number
        if (cin.fail())
        {
            cout << "Please enter a number: ";
        }

        // Input is out of range
        else if (input < lowerLimit || input > upperLimit)
        {
            cout << "Try entering something between " << lowerLimit << " and " << upperLimit << ": ";
        }

        cin >> input;
    }

    return input;
}

// Helper function to print a horizontal line
string printLine(int length)
{
    string line = "";

    for (int i = 0; i < length; i++)
    {
        line += "-";
    }

    return line;
}