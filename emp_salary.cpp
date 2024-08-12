// 1. Write a program to create class employee with employee’s id, name and
// basic salary. Calculate gross salary for each employee(HRA 20%, DA 30%,
// OA 10%).

#include<iostream>
using namespace std;

class employee{
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

void employee::inputdata()
{
    cout<<"enter id of the employee : ";
    cin>>id;
    cout<<"enter name of the employee : ";
    cin>>name;
    cout<<"enter salary of the employee : ";
    cin>>salary;
    
    HRA=salary * 0.2;
    DA=salary * 0.3;
    OA=salary * 0.1;
    
    
    
}

void employee:: displaydata()
{
    cout<<id<<"\t"<<name<<"\t\t\t"<<salary<<"\t\t"<<HRA<<"\t"<<DA<<"\t"<<OA<<"\n";
    cout<<endl;
}

int main()
{
    // employee e;
    
    int n;
    cout<<"enter number of employee you want : ";
    cin>>n;
    
    employee e[n];
    
    for(int i=0;i<n;i++){
        e[i].inputdata();
    }
    
    cout<<"id"<<"\t"<<"name"<<"\t\t\t"<<"salary"<<"\t\t"<<"HRA"<<"\t"<<"DA"<<"\t"<<"OA"<<"\n";
    for(int i=0;i<n;i++){
        e[i].displaydata();
    }
}