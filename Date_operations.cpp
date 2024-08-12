// Write a program to create class Date (int day, int month, int year). Read
// a value as day from user to display new date after adding the value to
// day in Date.

#include<iostream>
using namespace std;

class Date{
    int day;
    int month;
    int year;
    
    public:
        void inputdata();
        void addDays();
        // void displaydata();
};

void Date::inputdata()
{
    cout<<"enter day : ";
    cin>>day;
    cout<<"enter month : ";
    cin>>month;
    cout<<"enter year : ";
    cin>>year;
    
    cout<<"entered date is : "<<day<<"/"<<month<<"/"<<year;
    cout<<endl;
}

void Date::addDays()
{
    int addDays;
    cout<<"enter days you want to add in date : ";
    cin>>addDays;
    
    day+=addDays;
    while(day > 30){
        day -= 30;
        month+=1;
        if(month > 12){
            month -= 12;
            year += 1;
        }
    }
    cout<<"new date is : "<<day<<"/"<<month<<"/"<<year<<"\n";
    cout<<endl;
}

int main()
{
    Date d;
    d.inputdata();
    d.addDays();
}