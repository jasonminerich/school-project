/*B: roster.h*/
#pragma once
#include "degree.h"
#include "student.h"
#include <iostream>
using namespace std;
/*~~~*/
/*E_3: Define the functions*/
class Roster {
public:
    Roster(const string studentData[], int sizeofStudentData, int listLimit);
    ~Roster();
    void add(string stuID, string firstN, string lastN, string stuEmail, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram);
    void numparseID(string data);
    void printAverageDaysInCourse(string stuID);
    void printByDegreeProgram(DegreeProgram degreeProgram);
    void printInvalidEmails();
    void remove(string stuID);
    void printAll();
private:
    int listLimit;
    int stuQty;
    Student** classRosterArray;
};