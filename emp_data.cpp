#include<iostream>
using namespace std;

class employee {
    int id;
    string name;
    int salary;
    int HRA;
    int DA;
    int OA;

public:
    void inputdata();
    void displaydata();
};

void employee::inputdata() {
    cout << "enter id of the employee : ";
    cin >> id;
    cout << "enter name of the employee : ";
    cin >> name;
    cout << "enter salary of the employee : ";
    cin >> salary;

    HRA = salary * 0.2;
    DA = salary * 0.3;
    OA = salary * 0.1;
}

void employee::displaydata() {
    cout << id << "\t" << name << "\t\t" << salary << "\t" << HRA << "\t" << DA << "\t" << OA << "\n";
}

int main() {
    int n;
    cout << "enter number of employees you want : ";
    cin >> n;

    // Create an array of employee objects
    employee e[n];
    
    // for proper format
    
    for (int i = 0; i < n; i++) {
        e[i].inputdata();
    }

    cout << "id" << "\t" << "name" << "\t\t" << "salary" << "\t" << "HRA" << "\t" << "DA" << "\t" << "OA" << "\n";
    for (int i = 0; i < n; i++) {
        e[i].displaydata();
    }

    return 0;
}
