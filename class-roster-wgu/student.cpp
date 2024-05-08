#include "student.h"
#include <iostream>
using namespace std;
#include <string>
#include "degree.h"

Student::Student() {
    this->studentId = "";
    this->firstName = "";
    this->lastName = "";
    this->emailAddress = "";
    this->age = 0;
    this->daysToCompleteCourse[0] = 0;
    this->daysToCompleteCourse[1] = 0;
    this->daysToCompleteCourse[2] = 0;
    this->degreeProgram;
}

Student::Student(string studentId, string firstName, string lastName, string emailAddress, int age, int daysToCompleteCourse[], DegreeProgram degreeProgram) {
    this->studentId = studentId;
    this->firstName = firstName;
    this->lastName = lastName;
    this->emailAddress = emailAddress;
    this->age = age;
    this->daysToCompleteCourse[0] = daysToCompleteCourse[0];
    this->daysToCompleteCourse[1] = daysToCompleteCourse[1];
    this->daysToCompleteCourse[2] = daysToCompleteCourse[2];
    this->degreeProgram = degreeProgram;
}

//setters

void Student::setStudentId(string studentId) {
    this->studentId = studentId;
}

void Student::setFirstName(string firstName) {
    this->firstName = firstName;
}

void Student::setLastName(string lastName) {
    this->lastName = lastName;
}

void Student::setEmailAddress(string emailAddress) {
    this->emailAddress = emailAddress;
}

void Student::setAge(int age) {
    this->age = age;
}

void Student::setDaysToCompleteCourse(int daysInCourse1, int daysInCourse2, int daysInCourse3) {
    for (int i = 0; i < 3; i++) {
        this->daysToCompleteCourse[0] = daysInCourse1;
        this->daysToCompleteCourse[1] = daysInCourse2;
        this->daysToCompleteCourse[2] = daysInCourse3;
    }
}

void Student::setDegreeProgram(DegreeProgram degreeProgram) {
    this->degreeProgram = degreeProgram;
}

//getters

string Student::getStudentId() {
    return this->studentId;
}

string Student::getFirstName() {
    return this->firstName;
}

string Student::getLastName() {
    return this->lastName;
}

string Student::getEmailAddress() {
    return this->emailAddress;
}

int Student::getAge() {
    return this->age;
}

int* Student::getDaysToCompleteCourse() {
    return this->daysToCompleteCourse;
}

DegreeProgram Student::getDegreeProgram() {
    return this->degreeProgram;
}

// printer funcs

void Student::print() {
    string degreeProgramString;
    
    switch (getDegreeProgram()) {
        case SECURITY:
            degreeProgramString = "SECURITY";
            break;
        case NETWORK:
            degreeProgramString = "NETWORK";
            break;
        case SOFTWARE:
            degreeProgramString = "SOFTWARE";
            break;
    }
    
    cout << getStudentId() << "\tFirst Name: " << getFirstName() << "\tLast Name: " << getLastName()
        << "\tEmail Address: " << getEmailAddress() << "\tAge: " << getAge() << "\tDays To Complete Courses: {"
        << getDaysToCompleteCourse()[0] << " " << getDaysToCompleteCourse()[1] << " " << getDaysToCompleteCourse()[2]
        << "} " << "\tDegree Program: " << degreeProgramString << endl;
    
}
