/*B: student.cpp*/
#pragma once
#include "degree.h"
#include "student.h"
using namespace std;
/*~~~*/
/*D_2_a: Getter(accessor) for each variable from D_1*/
string Student::GetId() {
    return stuID;
}
string Student::GetfirstN() {
    return firstN;
}
string Student::GetlastN() {
    return lastN;
}
int Student::GetAge() {
    return age;
}
string Student::GetEmail() {
    return stuEmail;
}
int* Student::GetDaystoFinish() {
    return numDaysComplete;
}
DegreeProgram Student::GetDegreeProgram() {
    return degreeProgram;
}
/*D_2_b: Setter(mutator) for each variable from D_1*/
void Student::SetId(string stuID) {
    (*this).stuID = stuID;
    return;
}
void Student::SetfirstN(string firstN) {
    (*this).firstN = firstN;
    return;
}
void Student::SetlastN(string lastN) {
    (*this).lastN = lastN;
    return;
}
void Student::SetAge(int age) {
    (*this).age = age;
    return;
}
void Student::SetEmail(string stuEmail) {
    (*this).stuEmail = stuEmail;
    return;
}
void Student::SetDaystoFinish(int numDaysComplete[]) {
    for (int i = 0; i < COURSEQTY; i++) {
        (*this).numDaysComplete[i] = numDaysComplete[i];
    }
}
void Student::SetDegreeProgram(DegreeProgram degreeProgram) {
    (*this).degreeProgram = degreeProgram;
    return;
}
/*D_2_e: Print the student data with print ()*/
void Student::print() {
    cout << " " << stuID << '\t';
    cout << "First Name: " << firstN << '\t';
    cout << "Last Name: " << lastN << '\t';
    cout << "Student Email: " << stuEmail << '\t';
    cout << "Age: " << age << '\t' ;
    cout << "Days In Course: ";
    cout << "{";
    for (int i = 0; i < COURSEQTY; i++) {
        cout << numDaysComplete[i];
        if (i != COURSEQTY - 1) {
            cout << ", ";
        }
    }
    cout << "}";
    cout << '\t';
    cout << "Degree Program: ";
    if (degreeProgram == NETWORK) {
        cout << "NETWORK" << endl;
    }
    else if(degreeProgram == SECURITY) {
        cout << "SECURITY" << endl;
    }
    else if (degreeProgram == SOFTWARE) {
        cout << "SOFTWARE" << endl;
    }
    else if(degreeProgram == INVALID) {
        cout << "INVALID" << endl;
    }
}