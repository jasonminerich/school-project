/*B: student.h*/
#pragma once
#include "degree.h"
#include <string>
#include <iostream>
using namespace std;
/*~~~*/
/*D_1: Create the class Student with variables*/
constexpr auto COURSEQTY = 3;
class Student {
public:
    /*D_2_d: Constructor that uses all input parameters in table*/
    Student(string stuID, string firstN, string lastN, string stuEmail, int age, int numDaysComplete[], DegreeProgram degreeProgram) {
        (*this).stuID = stuID;
        (*this).firstN = firstN;
        (*this).lastN = lastN;
        (*this).age = age;
        (*this).stuEmail = stuEmail;
        (*this).numDaysComplete = new int[COURSEQTY];
        for (int i = 0; i < COURSEQTY; i++) {
            (*this).numDaysComplete[i] = numDaysComplete[i];
        }
        (*this).degreeProgram = degreeProgram;
    }
    /*D_2_a: Getter(accessor) for each variable from D_1*/
    string GetEmail();
    string GetfirstN();
    string GetId();
    string GetlastN();      
    int GetAge();
    int* GetDaystoFinish();
    DegreeProgram GetDegreeProgram();
    /*D_2_b: Setter(mutator) for each variable from D_1*/
    void SetId(string stuID);
    void SetfirstN(string firstN);
    void SetlastN(string lastN);
    void SetAge(int age);
    void SetEmail(string stuEmail);
    void SetDaystoFinish(int numDaysComplete[]);
    void SetDegreeProgram(DegreeProgram degreeProgram);
    void print();
/*D_2_c: Instance variables of the Student class*/
private:
    string stuID;
    string firstN;
    string lastN;
    int age;
    string stuEmail;
    int* numDaysComplete;
    DegreeProgram degreeProgram;
};