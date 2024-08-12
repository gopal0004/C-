// WAP to create base class Student having int id and char name as data
// members and respective functionality, Take derived class as attendance
// having subject name and percentage of attendance and respective
// functionality and store the information in to the file and display in proper
// format from the file.
#include<iostream>
#include<fstream>
using namespace std;

class Student{
    
    public:
        int id;
        string name;
        
    public:
        void input()
        {
            cout<<"enter id of the student : ";
            cin>>id;
            cout<<"enter name of the student : ";
            cin>>name;
        }
        
        void display()
        {
            cout<<"id : "<<id <<"name : "<<name;
            cout<<endl;
        }
        
};
class attendence:public Student{
    public:
        float attendence;
        string *sub;
        int n;
        
    public:
        void inputdata(){
            
            input();
            cout<<"enter number of subject : ";
            cin>>n;
            sub=new string[n];
            
            for(int i=0;i<n;i++){
                cout<<"enter subject name : ";
                cin>>sub[i];
                cout<<"enter attendence respectively : ";
                cin>>attendence;
                if(attendence<75){
                    cout<<"reenter attendence : ";
                    cin>>attendence;
                }
            }
            cout<<endl;
        }
        void displaydata()
        {
            cout<<"id\t\tname\t\tsubjects\t\tattendence \n";
            cout<<id<<"\t\t"<<name<<"\t\t";
            for(int i=0;i<n;i++){
                cout<<sub[i]<<" ";
                cout<<attendence;
            }
            cout<<endl;
        }
};

int main()
{
    attendence a;
    int n;
    cout<<"enter number of student : ";
    cin>>n;
    for(int i=0;i<n;i++){
        a.inputdata();
        a.displaydata();
    }
    fstream myfile("student details.txt",ios::app);
    if(myfile.is_open())
    {
        myfile<<"id\t\tname\t\tsubjects\t\tattendence \n";
        for(int i=0;i<n;i++){
            
            myfile<<a.id<<"\t\t"<<a.name<<"\t\t";
            for(int i=0;i<n;i++){
                myfile<<a.sub[i]<<" ";
                myfile<<a.attendence;
                myfile.close();
            }
        }
    }
    else{
        cout<<"unable to open file ";
    }
}