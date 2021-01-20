/*B: roster.cpp*/
#pragma once
#include "roster.h"
#include "student.h"
#include <sstream>
#include <string>
#include <vector>
using namespace std;
/*~~~*/
/*E_1: Create an array of points to hold studentData Table data*/
Roster::Roster(const string studentData[], int sizeofStudentData, int listLimit) {
    (*this).classRosterArray = new Student * [listLimit];
    (*this).listLimit = listLimit;
    (*this).stuQty = sizeofStudentData;
    int stuData = 0;
    while (stuData < sizeofStudentData) {
        /*E_2_a: Using tokens to Parse data in the studentData Table, Vectors to Save the tokens, String stream to relate string object and string*/
        vector <string> token;
        string cycleTokens;
        stringstream inputS(studentData[stuData]);
        DegreeProgram degreeProgram = INVALID;
        while (getline(inputS, cycleTokens, ',')) {
            token.push_back(cycleTokens);
        }
        /*E_2_* The conversion of strings to enum and int respectively */
        if (token[8].compare("NETWORK") == 0) {
            degreeProgram = NETWORK; }
        else if (token[8].compare("SECURITY") == 0) {
            degreeProgram = SECURITY; }
        else if (token[8].compare("SOFTWARE") == 0) {
            degreeProgram = SOFTWARE; }
        int age = std::stoi(token[4]);
        int numDaysComplete[4] = { std::stoi(token[5]), std::stoi(token[6]), std::stoi(token[7]) };
        /*E_2_b: Create, add, and populate each student object with regards to classRosterArray*/
        classRosterArray[stuData] = new Student(token[0], token[1], token[2], token[3], age, numDaysComplete, degreeProgram);
        stuData++;
    }
}
/*E_3: Define the functions*/
/*E_3_a*/
void Roster::add(string stuID, string firstN, string lastN, string stuEmail, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram) {
    int numDaysComplete[3] = { daysInCourse1, daysInCourse2, daysInCourse3 };
    classRosterArray[stuQty] = new Student(stuID, firstN, lastN, stuEmail, age, numDaysComplete, degreeProgram);
}
/*E_3_b: Removes students from the Roster*/
void Roster::remove(string stuID) {
    bool findID = false;
    for (int i = 0; (i < stuQty) and !findID; ++i) {
        if ((*classRosterArray[i]).GetId() == stuID) {
            classRosterArray[i] = classRosterArray[stuQty - 1];
            findID = true;
        }
    }
    if (findID) {
        cout << "Student ID " << stuID << " was found and is now removed." << endl;
    }
    else {
        cout << '\n';
        cout << "Student with this ID not found." << endl;
    }
}
/*E_3_c: Prints Student data*/
void Roster::printAll() {
    for (int i = 0; i < stuQty; ++i) {
        (*classRosterArray[i]).print();
    }
}
/*E_3_d: Prints average Days in courses*/
void Roster::printAverageDaysInCourse(string stuID) {
    for (int i = 0; i < stuQty; ++i) {
        if ((*classRosterArray[i]).GetId() == stuID) {
            cout << " Student ID " << (*classRosterArray[i]).GetId() << ": ";
            int* days = (*classRosterArray[i]).GetDaystoFinish();
            cout << "Average days in courses: " << (days[0] + days[1] + days[2]) / 3 << endl;
            return;
        }
    }
}
/*E_3_e: Prints invalid emails*/
void Roster::printInvalidEmails() {
    for (int i = 0; i < stuQty; ++i) {
        string email = (*classRosterArray[i]).GetEmail();
        long arroba = email.find('@');
        long period = email.find('.', arroba);
        if (arroba == string::npos) {
            cout << " The following is invalid. The email is missing an @ symbol:" << email << endl;
        }
        else if (period == string::npos) {
            cout << " The following is invalid. The email is missing a '.' : " << email << endl;
        }
        else if (email.find(' ') != string::npos) {
            cout << " The following is invalid. The email contains a space character:" << email << endl;
        }
    }
}
/*E_3_f: Prints student info*/
void Roster::printByDegreeProgram(DegreeProgram degreeProgram) {
    for (int i = 0; i < stuQty; ++i) {
        if ((*classRosterArray[i]).GetDegreeProgram() == degreeProgram) {
            (*classRosterArray[i]).print();
        }
    }
}
/*F_5: Destructor to release memory allocated dynamically in Roster*/
Roster::~Roster() {
    delete[] classRosterArray;
}
void Roster::numparseID(string data) {
}