#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

class student {
public:
    int rollno;
    string name;
    string stream;
public:
    void input() {
        cout << "Enter rollno: ";
        cin >> rollno;
        cout << "Enter name: ";
        cin >> name;
        cout << "Enter stream: ";
        cin >> stream;
        cout << endl;
    }

    void display() {
        cout << setw(10) << "Rollno" << setw(15) << "Name" << setw(15) << "Stream\n";
        cout << setw(10) << rollno << setw(15) << name << setw(15) << stream << endl;
    }
};

class subject : public student {
public:
    int marks[5];
    int total;
    float percentage;

public:
    void inputdata() {
        input();
        cout << "Enter marks of five subjects: ";
        total = 0;
        for (int i = 0; i < 5; i++) {
            cin >> marks[i];
            total += marks[i];
        }
        percentage = static_cast<float>(total) / 5.0;
        cout << endl;
    }

    void displaydata() {
        inputdata();
        display();
        cout <<"Marks" << setw(20) << "Total" << setw(15) << "Percentage\n";
        for (int i = 0; i < 5; i++) {
            cout <<" "<< marks[i];
        }
        cout << setw(15) << total << setw(25) << setprecision(3) << fixed << percentage << endl;
    }
};

int main() {
    int n;
    cout << "Enter number of students: ";
    cin >> n;

    fstream myfile;
    myfile.open("student_details.txt", ios::app);

    if (myfile.is_open()) {
        for (int i = 0; i < n; i++) {
            subject s;
            s.displaydata();

            myfile << setw(10) << s.rollno << setw(15) << s.name << setw(15) << s.stream << "\t";
            for (int j = 0; j < 5; j++) {
                myfile << setw(10) << s.marks[j];
            }
            myfile << setw(10) << s.total << setw(15) << setprecision(2) << fixed << s.percentage << "\n";
        }

        myfile.close();
        cout << "Data written to file successfully.\n";
    } else {
        cout << "Unable to open file.\n";
    }

    return 0;
}
