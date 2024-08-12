#include <iostream>
#include <string>
using namespace std;

// Base class
class Faculty {
public:
    string name;
    string qualification;
    string subjects[3];

    // Virtual functions for reading and writing class objects
    virtual void read() = 0;
    virtual void write() = 0;
};

// Derived class: RegularFaculty
class RegularFaculty : public Faculty {
public:
    // Regular faculty is available full time and teaches at least three subjects
    void read() {
        cout << "Enter name, qualification and three subjects for regular faculty: ";
        cin >> name >> qualification;
        for(int i=0; i<3; i++)
            cin >> subjects[i];
    }

    void write() {
        cout << "Regular Faculty\n";
        cout << "Name: " << name << "\nQualification: " << qualification << "\nSubjects: ";
        for(int i=0; i<3; i++)
            cout << subjects[i] << " ";
        cout << "\n";
    }
};

// Derived class: VisitingFaculty
class VisitingFaculty : public Faculty {
public:
    string consulting_days;

    // Visiting faculty is available only on two to three days and teaches a single subject
    void read() {
        cout << "Enter name, qualification, one subject, and consulting days for visiting faculty: ";
        cin >> name >> qualification >> subjects[0] >> consulting_days;
    }

    void write() {
        cout << "Visiting Faculty\n";
        cout << "Name: " << name << "\nQualification: " << qualification;
        cout << "\nSubject: " << subjects[0] << "\nConsulting Days: " << consulting_days << "\n";
    }
};

int main() {
    RegularFaculty rf;
    VisitingFaculty vf;

    rf.read();
    vf.read();

    rf.write();
    vf.write();

    return 0;
}
