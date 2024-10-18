#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

#include "student.h"
#include "node.h"
#include "list.h"
#include "app.h"

using namespace std;

int main()
{
    const string FILENAME = "studentData.txt";
    const int DECIMAL_PRECISION = 2;
    const int MIN_MENU_OPTION = 1;
    const int MAX_MENU_OPTION = 5;
    const int MENU_OPTION_1 = 1;
    const int MENU_OPTION_2 = 2;
    const int MENU_OPTION_3 = 3;
    const int MENU_OPTION_4 = 4;
    const int MENU_OPTION_5 = 5;
    const int MIN_MARK = 0;
    const int MAX_MARK = 50;
    const int CAPACITY = 100;

    bool continueRunning = true;
    int studentCount = 0;
    int menuChoice;

    List<Student> *students = new List<Student>;

    // Format output with left alignment and fixed decimal place
    cout << left << fixed << setprecision(DECIMAL_PRECISION);

    printHeader();

    readData(FILENAME, students, CAPACITY);

    while (continueRunning)
    {
        printMenu();

        cout << "Enter choice: ";
        menuChoice = validateInt(MIN_MENU_OPTION, MAX_MENU_OPTION);
        cout << endl;

        switch (menuChoice)
        {
        case MENU_OPTION_1:
            printAllStudents(students);
            break;

        case MENU_OPTION_2:
            printTopStudents(students);
            break;

        case MENU_OPTION_3:
            printGradeStats(students);
            break;

        case MENU_OPTION_4:
            updateStudentMarks(students, MIN_MARK, MAX_MARK);
            break;

        case MENU_OPTION_5:
            cout << "Exiting..." << endl;
            continueRunning = false;
            break;
        }
    }

    delete students;
    return 0;
}