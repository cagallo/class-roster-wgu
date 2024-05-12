#include <iostream>
using namespace std;
#include "degree.h"
#include "roster.h"
#include "student.h"


int main() {
    
    const string studentData[] = {
        "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY", "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK", "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE", "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY", "A5,Chez, Gallo,cgal226@wgu.edu,30, 10, 20, 21,SOFTWARE"
    };
    
    const static int classRosterSize = 5;
    
    Roster classRoster;
    
    for (int i = 0; i < classRosterSize; i++) {
        classRoster.parse(studentData[i]);
    };

    cout << "C867: Scripting and Programming Applications" << endl;
    cout << "Cesare Gallo" << endl;
    cout << "Student ID: 011021267" << endl;
    cout << endl;
    cout << endl;
    
    // print all student data
    classRoster.printAll();
    cout << endl;
    cout << endl;
    
    // print invalid emails
    classRoster.printInvalidEmails();
    cout << endl;
    cout << endl;
    
    //print each student's avg days in course
    for (int i = 0; i < classRosterSize; i++) {
        classRoster.printAverageDaysInCourse(classRoster.classRosterArray[i]->getStudentId());
    }
    cout << endl;
    cout << endl;
    
    // print by degree program - software
    cout << "These students are in the Software Program: " << endl;
    classRoster.printByDegreeProgram(SOFTWARE);
    cout << endl;
    cout << endl;

    //remove student successfully
    classRoster.remove("A3");
    cout << endl;
    cout << endl;
    
    // print all current students post removal
    classRoster.printAll();
    cout << endl;
    cout << endl;
    
    //try and remove student again- get error
    classRoster.remove("A3");
    cout << endl;
    
    return 0;
}
