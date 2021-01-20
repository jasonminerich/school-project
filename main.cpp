/*B: main.cpp*/
#pragma once
#include "roster.h"
#include "student.h"
using namespace std;
/*~~~*/
int main()
{
    /*F_1: My student info/heading*/
    cout << '\n' << endl;
    cout << "  Scripting and Programming - Applications: C867" << endl;
    cout << "  Programming Language: C++" << endl;
    cout << "  Student ID: ######" << endl;
    cout << "  Student Name: Jason Minerich" << '\n' <<endl;
    /*A: studentData Table*/
    const string studentData[] = {
        "A1,John,Smith,John1989@gmail.com,20,30,35,40,SECURITY",
        "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
        "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
        "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
        "A5,Jason,Minerich,######@##.###.edu,34,60,40,25,SOFTWARE"
    };
    /*F_2-F_4: classRoster main functions*/
    Roster* classRoster = new Roster(studentData, 5, 5);
    cout << "Printing student list:" << endl;
    (*classRoster).printAll();
    cout << endl;
    cout << "Invalid emails:" << endl;
    (*classRoster).printInvalidEmails();
    cout << endl;
    cout << "Course averages by Days: " << endl;
    (*classRoster).printAverageDaysInCourse("A1");
    (*classRoster).printAverageDaysInCourse("A2");
    (*classRoster).printAverageDaysInCourse("A3");
    (*classRoster).printAverageDaysInCourse("A4");
    (*classRoster).printAverageDaysInCourse("A5");
    cout << endl;
    cout << "Displaying roster by NETWORK program:" << endl;
    (*classRoster).printByDegreeProgram(NETWORK);
    cout << endl << "Displaying roster by SECURITY program:" << endl;
    (*classRoster).printByDegreeProgram(SECURITY);
    cout << endl << "Displaying roster by SOFTWARE program:" << endl;
    (*classRoster).printByDegreeProgram(SOFTWARE);
    cout << endl << endl;
    (*classRoster).remove("A3");
    (*classRoster).printAll();
    (*classRoster).remove("A3");
    cout << endl;
}
