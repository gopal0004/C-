#include<iostream>
#include<fstream>
using namespace std;

class student
{
    public:
    int roll_no;
    string name; // Changed from 'char' to 'string' to store the full name
    
    public:
    
    void input(int n)
    {
        cout<<"enter roll_no : ";
        cin>>roll_no;
        cout<<"enter name of student : ";
        cin>>name;
        // cin.ignore(); // To ignore the newline character in the input buffer
        // getline(cin, name); // Changed from 'cin' to 'getline' to read the full line
    }
    void display()
    {
        cout<<roll_no << " " << name <<" "; // Added a space for better formatting
    }
    
};

class marksheet:public student {
    public:
    
    int *marks;
    int total=0;
    int n;
    float percentage;
    public:
    
    void inputdata()
    {
        student::input(n); // Call the input function of the student class
        cout<<"enter number of subject : ";
        cin>>n;
        
        marks= new int[n];
        
        cout<<"enter marks : ";
        for(int i=0;i<n;i++){
            cin>>marks[i];
            total += marks[i];
        }
    
        
        percentage= total/3; // Cast total to float for accurate division
    }
    
    void displaydata()
    {
        ofstream file("ms.txt");
        if (file.is_open()) {
            file << "Roll No: " << roll_no << "\n";
            file << "Name: " << name << "\n";
            file << "Total: " << total << "\n";
            file << "Percentage: " << percentage << "\n";
            file.close();
        } 
        else
        {
            cout << "Unable to open file";
        }
    }

};

int main()
{
    int n;
    cout<<"enter number of student : ";
    cin>>n;
    
    
    marksheet m1;
    m1.inputdata();
    m1.displaydata();
    student s1;
}
