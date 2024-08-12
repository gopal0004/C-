#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Employee {
public:
    string name;
    string address;
    string phoneNumber;
};

void addRecord(Employee* employees, int& employeeCount, int MAX_EMPLOYEES) {
    if (employeeCount >= MAX_EMPLOYEES) {
        cout << "Employee database is full.\n";
        return;
    }
    cout << "Enter name: ";
    cin >> employees[employeeCount].name;
    cout << "Enter address: ";
    cin >> employees[employeeCount].address;
    cout << "Enter phone number: ";
    cin >> employees[employeeCount].phoneNumber;
    employeeCount++;
}

void modifyRecord(Employee* employees, int employeeCount) {
    string name;
    cout << "Enter the name of the employee whose record you want to modify: ";
    cin >> name;
    for (int i = 0; i < employeeCount; i++) {
        if (employees[i].name == name) {
            cout << "Enter new address: ";
            cin >> employees[i].address;
            cout << "Enter new phone number: ";
            cin >> employees[i].phoneNumber;
            return;
        }
    }
    cout << "Employee not found.\n";
}

void retrieveRecord(Employee* employees, int employeeCount) {
    string name;
    cout << "Enter the name of the employee whose record you want to retrieve: ";
    cin >> name;
    for (int i = 0; i < employeeCount; i++) {
        if (employees[i].name == name) {
            cout << "Name: " << employees[i].name << ", Address: " << employees[i].address << ", Phone Number: " << employees[i].phoneNumber << "\n";
            return;
        }
    }
    cout << "Employee not found.\n";
}

void generateList(Employee* employees, int employeeCount) {
    for (int i = 0; i < employeeCount; i++) {
        cout << "Name: " << employees[i].name << ", Address: " << employees[i].address << ", Phone Number: " << employees[i].phoneNumber << "\n";
    }
}

void writeToFile(Employee* employees, int employeeCount) {
    ofstream outFile("employees.txt");
    if (!outFile) {
        cout << "Unable to open file";
        exit(1); // terminate with error
    }
    for (int i = 0; i < employeeCount; i++) {
        outFile << "Name: " << employees[i].name << ", Address: " << employees[i].address << ", Phone Number: " << employees[i].phoneNumber << "\n";
    }
    outFile.close();
}

int main() {
    int MAX_EMPLOYEES;
    cout << "Enter the maximum number of employees: ";
    cin >> MAX_EMPLOYEES;

    Employee* employees = new Employee[MAX_EMPLOYEES];
    int employeeCount = 0;

    int choice;
    do {
        cout << "Menu:\n";
        cout << "1. Add a new record\n";
        cout << "2. Modify an existing record\n";
        cout << "3. Retrieve and display an entire record for a given name\n";
        cout << "4. Generate a complete list of all names, addresses and telephone numbers\n";
        cout << "5. End of the computation\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                addRecord(employees, employeeCount, MAX_EMPLOYEES);
                break;
            case 2:
                modifyRecord(employees, employeeCount);
                break;
            case 3:
                retrieveRecord(employees, employeeCount);
                break;
            case 4:
                generateList(employees, employeeCount);
                break;
            case 5:
                cout << "Ending computation.\n";
                break;
            default:
                cout << "Invalid choice. Please enter a number between 1 and 5.\n";
        }
    } while (choice != 5);

    writeToFile(employees, employeeCount);

    delete[] employees; // Don't forget to delete the dynamically allocated array
    return 0;
}
