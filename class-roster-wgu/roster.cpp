#include "roster.h"
#include <iostream>
#include <string>
#include "student.h"
#include "degree.h"
#include <array>
#include <regex>
using namespace std;

//constructor
Roster::Roster() {
    for (int i = 0; i < 5; i++) {
        classRosterArray[i] = nullptr;
    }
}

void Roster::parse(string studentData) {
    int stringIdx = studentData.find(",");
    string studentId = studentData.substr(0, stringIdx);
    
    int nextStringIdx = stringIdx + 1;
    stringIdx = studentData.find(",", nextStringIdx);
    string firstName = studentData.substr(nextStringIdx, stringIdx - nextStringIdx);
    
    nextStringIdx = stringIdx + 1;
    stringIdx = studentData.find(",", nextStringIdx);
    string lastName = studentData.substr(nextStringIdx, stringIdx - nextStringIdx);
    
    nextStringIdx = stringIdx + 1;
    stringIdx = studentData.find(",", nextStringIdx);
    string emailAddress = studentData.substr(nextStringIdx, stringIdx - nextStringIdx);
    
    nextStringIdx = stringIdx + 1;
    stringIdx = studentData.find(",", nextStringIdx);
    int age = stoi(studentData.substr(nextStringIdx, stringIdx - nextStringIdx));
    
    nextStringIdx = stringIdx + 1;
    stringIdx = studentData.find(",", nextStringIdx);
    int daysInCourse1 = stoi(studentData.substr(nextStringIdx, stringIdx - nextStringIdx));
    
    nextStringIdx = stringIdx + 1;
    stringIdx = studentData.find(",", nextStringIdx);
    int daysInCourse2 = stoi(studentData.substr(nextStringIdx, stringIdx - nextStringIdx));
    
    nextStringIdx = stringIdx + 1;
    stringIdx = studentData.find(",", nextStringIdx);
    int daysInCourse3 = stoi(studentData.substr(nextStringIdx, stringIdx - nextStringIdx));
    
    nextStringIdx = stringIdx + 1;
    string degreeProgramName = studentData.substr(nextStringIdx, stringIdx - nextStringIdx);
    DegreeProgram degreeProgram;
    
    if(degreeProgramName == "SECURITY") {
        degreeProgram = SECURITY;
    }
    else if (degreeProgramName == "NETWORK") {
        degreeProgram = NETWORK;
    }
    else if (degreeProgramName == "SOFTWARE") {
        degreeProgram = SOFTWARE;
    }
    
    add(studentId, firstName, lastName, emailAddress, age, daysInCourse1, daysInCourse2, daysInCourse3, degreeProgram);
}


void Roster::add(string studentId, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram) {
    int daysToCompleteCourse[3] = { daysInCourse1, daysInCourse2, daysInCourse3 };
    
    int i = 0;
    bool studentAdded = false;
    
    do {
        if (classRosterArray[i] == nullptr) {
            classRosterArray[i] = new Student(studentId, firstName, lastName, emailAddress, age, daysToCompleteCourse, degreeProgram);
            studentAdded = true;
        }

        i++;

    } while (studentAdded == false && i < 5 );
}

void Roster::remove(string studentId) {
    bool studentFound = false;
    
    for (int i = 0; i < 5; i++) {
        if (this->classRosterArray[i] != nullptr && this->classRosterArray[i]->getStudentId() == studentId) {
            studentFound = true;
            delete this->classRosterArray[i];
            this->classRosterArray[i] = nullptr;
            break;
        }
    }
    if (studentFound) {
        cout << "Student " << studentId << " was removed." << endl;
    }
    else {
        cout << "Student" << studentId << " was not found." << endl;
    }
    return;
}

void Roster::printAll() {
    for (int i = 0; i < 5; i++) {
        if (classRosterArray[i] != nullptr) {
            classRosterArray[i]->print();
        }
    }
}

void Roster::printAverageDaysInCourse(string studentId) {
    bool studentIdExists = false;
    
    for (int i = 0; i < 5; i++) {
        if (classRosterArray[i] != nullptr && classRosterArray[i]->getStudentId() == studentId) {
            studentIdExists = true;
            double averageDaysInClass = (classRosterArray[1]->getDaysToCompleteCourse()[0] +
                classRosterArray[i]->getDaysToCompleteCourse()[1] +
                                         classRosterArray[i]->getDaysToCompleteCourse()[2])/3.0;
            
            cout << "Student " << studentId << " has an average number of days " << averageDaysInClass << " in class." << endl;
        }
    }
    return;
}

void Roster::printInvalidEmails() {
    regex validEmailCharacters("(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");
    bool invalidEmailFound = false;
    
    for (int i = 0; i < 5; i++) {
        if (classRosterArray[i] != nullptr && !regex_match(classRosterArray[i]->getEmailAddress(), validEmailCharacters)) {
            invalidEmailFound = true;
            cout << "Invalid email found: " << classRosterArray[i]->getEmailAddress() << endl;
        }
    }
    if (!invalidEmailFound) {
        cout << "All emails are valid" << endl;
    }
}

void Roster::printByDegreeProgram(DegreeProgram degreeProgram) {
    for (int i = 0; i < 5; i++) {
        if (classRosterArray[i] != nullptr && classRosterArray[i]->getDegreeProgram() == degreeProgram) {
            classRosterArray[i]->print();
        }
    }
}

//destructor
Roster::~Roster() {
    for (int i = 0; i < 5; i++) {
        delete this->classRosterArray[i];
        this->classRosterArray[i] = nullptr;
    }
}
