#pragma once
#ifndef student_h
#define student_h
#include <iostream>
using namespace std;
#include <string>
#include "degree.h"

class Student {
public:
    //constructor
    Student();
    Student(string studentId, string firstName, string lastName, string emailAddress, int age, int daysToCompleteCourse[3], DegreeProgram degreeProgram);
    
    //setters
    void setStudentId(string studentId);
    void setFirstName(string firstName);
    void setLastName(string lastName);
    void setEmailAddress(string emailAddress);
    void setAge(int age);
    void setDaysToCompleteCourse(int daysInCourse1, int daysInCourse2, int daysInCourse3);
    void setDegreeProgram(DegreeProgram degreeProgram);
    
    //getters
    string getStudentId();
    string getFirstName();
    string getLastName();
    string getEmailAddress();
    int getAge();
    int* getDaysToCompleteCourse();
    DegreeProgram getDegreeProgram();
    
    //printer funcs
    void print();
    void printStudentId();
    void printFirstName();
    void printLastName();
    void printEmailAddress();
    void printAge();
    void printDaysToCompleteCourse();
    void printDegreeProgram();
    
    
private:
    string studentId;
    string firstName;
    string lastName;
    string emailAddress;
    int age;
    int daysToCompleteCourse[3];
    DegreeProgram degreeProgram;
};

#endif /* student_h */
