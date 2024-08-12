#include<iostream>
#include<fstream>
using namespace std;

class student {
public:
    int roll_no;
    string name;
    int marks[5];

public:
    void input() {
        cout << "Enter roll_no of the student: ";
        cin >> roll_no;
        cout << "Enter name of the student: ";
        cin >> name;
        for (int i = 0; i < 5; i++) {
            cout << "Enter marks: ";
            cin >> marks[i];
        }
    }

    void display() {
        cout << "Roll no: " << roll_no << " Name: " << name << " Marks: ";
        for (int i = 0; i < 5; i++) {
            cout << marks[i] << " ";
        }
        cout << endl;
    }
};

class marksheet : public student {
public:
void display_file() {
    ofstream myfile("marksheet.txt", ios::app);  // Open file in append mode
    if (myfile.is_open()) {
        // Add headers to the file
        myfile << "Roll No\tName\tMarks1\tMarks2\tMarks3\tMarks4\tMarks5" << endl;
        // Write data in tabular format
        myfile << roll_no << "\t" << name << "\t";
        for (int j = 0; j < 5; j++) {
            myfile << marks[j] << "\t";
        }
        myfile << endl;  // Add newline to separate entries
        myfile.close();  // Close the file after writing
    } else {
        cout << "Unable to open file";
    }
    
}

void proper_format()
{
    cout << "Roll No\tName\tMarks1\tMarks2\tMarks3\tMarks4\tMarks5" << endl;
        // Write data in tabular format
    cout << roll_no << "\t" << name << "\t";
    for (int j = 0; j < 5; j++) {
        cout << marks[j] << "\t";
    }
}

};

int main() {
    int n;
    cout << "Enter number of students: ";
    cin >> n;

    marksheet m;
    for (int i = 0; i < n; i++) {
        m.input();        // Use marksheet's input method
        m.display();      // Use marksheet's display method
        m.display_file();  // Write data to the file inside the loop
        m.proper_format();
    }
    
}
