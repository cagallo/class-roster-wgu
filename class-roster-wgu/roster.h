#pragma once
#ifndef roster_h
#define roster_h
#include "degree.h"
#include "student.h"
#include <iostream>
#include <string>
#include <array>
using namespace std;

class Roster {
public:
    Student*classRosterArray[5];
    Roster();
    void parse(string studentData);
    void add(string studentId, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram);
    void remove(string studentId);
    void printAll();
    void printAverageDaysInCourse(string studentId);
    void printInvalidEmails();
    void printByDegreeProgram(DegreeProgram degreeProgram);
    ~Roster();
};

#endif /* roster_h */

