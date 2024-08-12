// WAP to create student having data members (rollno, name, stream) as
// base class. Derive class subject with marks of 5 subjects and apply
// respective functionality. Calculate result and display details of each
// student from derived class and store the information in to the file and
// display in proper format from the file.

#include<iostream>
#include<fstream>
#include<string>
using namespace std;

class student{
    public:
        int rollno;
        string name;
        string stream;
    public:
        void input()
        {
            cout<<"enter rollno : ";
            cin>>rollno;
            cout<<"enter name : ";
            cin>>name;
            cout<<"enter stream : ";
            cin>>stream;
            
            cout<<endl;
        }
        void display()
        {
            cout<<"rollno\t\tname\t\tstream ";
            cout<<rollno<<"\t\t"<<name<<"\t\t"<<stream;
            cout<<endl;
        }
};
class subject:public student{
    public:
        int marks[5];
        int total;
        float percentage;
        
    public:
        void inputdata()
        {
            input();
            cout<<"enter marks of five subjects : ";
            for(int i=0;i<5;i++){
                cin>>marks[i];
                
                total+=marks[i];
                
            }
            percentage=total/5;
            cout<<endl;
        }
        
        void displaydata()
        {
            inputdata();
            display();
            cout<<"marks\t\t\ttotal\t\tpercentage\n";
            for(int i=0;i<5;i++){
                cout<<marks[i]<<" ";
                
            }
            cout<<total<<percentage<<"\t\t";
            cout<<endl;
        }
        
};

int main()
{
    subject s;
    int n;
    cout<<"enter number of student : ";
    cin>>n;
    
    for(int i=0;i<n;i++){
        
        s.displaydata();
    }
    fstream myfile;
    myfile.open("student details.txt",ios::app);
    if(myfile.is_open()){
        for(int i=0;i<n;i++){
            myfile<<s.rollno<<"\t";
            myfile<<s.name<<"\t\t";
            myfile<<s.stream;
            for(int j=0;j<5;j++){
                myfile<<s.marks[j];
            }
            myfile<<s.total;
            myfile<<s.percentage;
        }
        cout<<endl;
        myfile.close();
    }
    else{
        cout<<"unable to open file ";
    }
}