// 1. Create class STUDENT having rollno, name and age as data members,
// also take subject with three subjects and initialize their value with
// minimum passing marks. Using member function, modify marks of
// student with specific rollno which is given by user.

#include<iostream>
using namespace std;

class Student{
    int rollno;
    string name;
    int age;
    int marks[3];
    // int n; 
    
    public:
    void inputdata();
    void modifydata();
    void displaydata();
};

void Student::inputdata()
{
  
    cout<<"enter rollno of the student : ";
    cin>>rollno;
    cout<<"enter name of the student : ";
    cin>>name;
    cout<<"enter age of the student : ";
    cin>>age;
    cout<<"enter marks of three subjects : ";
    for(int i=0;i<3;i++){
        cin>>marks[i];
    }
    cout<<endl;
}

void Student:: modifydata()
{
    int r_number;
    cout<<"enter rollno of the student to modify its data : ";
    cin>>r_number;
    
    if(r_number==rollno){
        cout<<"enter  new name : ";
        cin>>name;
        cout<<"enter new age : ";
        cin>>age;
        cout<<"enter new marks of three subjects : ";
        for(int i=0;i<3;i++){
            cin>>marks[i];
        }
    }
    else{
        cout<<"rollno does not exist ";
    }
    cout<<endl;
}

void Student::displaydata()
{
    cout<<"rollno\tname\t\tage\tmarks1\tmarks2\tmarks3\n";
    cout<<rollno<<"\t"<<name<<"\t\t"<<age<<"\t";
    for(int i=0;i<3;i++){
        cout<<marks[i]<<"\t";
    }
    cout<<endl;
}

int main()
{
    Student s;
    
    int choice;
    int n;
    
    do{
        cout<<"1.inputdata  \n";
        cout<<"2.modifydata  \n";
        cout<<"3.displaydata  \n";
        cout<<"4.exit  \n";
        
        cout<<"enter choice : ";
        cin>>choice;
        
        switch(choice){
            case 1:{
                s.inputdata();
                break;
            }
            case 2:{
                s.displaydata();
                break;
            }
            case 3:{
                s.displaydata();
                break;
            }
            case 4:{
                cout<<"exit \n";
                break;
            }
        }
    }
    while(choice != 4);
}