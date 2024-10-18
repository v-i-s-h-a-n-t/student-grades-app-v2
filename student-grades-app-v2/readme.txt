Student Grades App
------------------

 This CLI app was made as a part of assignment 2 for CS112 (Introduction to Data Structures and Algorithms) at the University of the South Pacific. The program is built using C++ and shows the advantages of user defined data types over built in data types. The user defined data types include a Student class, a generic Node class and a generic Link class. The Link class is used to manage Node classes, which hold the Student class as its data. Wrapper functions make use of the methods from the Link class to perform various tasks like printing all students in a table format.

Final Build
-----------

This program was built using Microsoft Visual Studio. The final application (.exe file) can be found in the "x64/Debug" directory. The data file, "studentData.txt", is placed both in the "student-grades-app-v2/student-grades-app-v2" directory for development, and in the "x64/Debug" directory for the final build.

Features
--------

View all students' details - as a user, you can view all students' details in a table format
View top student's details - as a user, you can view the top students' details in a table format
View grade statistics - as a user, you can view the average mark and pass rate of all students
Update student's marks - as a user, you can update the coursework and final exam marks of a student

Edge Cases
----------

This program is built to handle a few edge cases to provide a good user experience and to prevent unwanted behavior.

Input validation - all inputs are validate, meaning users cannot enter values that are not of the correct data type or values that are outside a specific range (e.g. menu choice is set to take in values only from 1 to 5).

Multiple Toppers - since users can update the grade of any student, there there are cases when multiple highest scorers exists. This program accommodates for that and displays all the students with the highest mark.

User Manual
-----------

After running the program, you will be prompted to enter a choice that corresponds to a feature. 

Press 1 to view all students' details
Press 2 to view top students' details
Press 3 to view grade statistics
Press 4 to update student's marks. You will be prompted to enter the student ID, new coursework, and new final exam marks
Press 5 to exit the program

Extras
------

For mor information, refer to the GitHub repository for this program - https://github.com/anav5704/student-grades-app-v2

Authors
-------

- Anav Chand (S11221203)
- Vishant Kumar (S11230430)


