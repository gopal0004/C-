// 2. WAP to define a class Date with properties int month; int day; int year;
// Overload the + operator [a+b] (a is of date type and b is an integer – No of
// days to add in date), use the assumption that all years have 360 days and
// // months 30 days.

#include<iostream>
using namespace std;

class date{
    public:
        int day;
        int month;
        int year;
        
    void inputdata();
    void displaydata();
};
void date::inputdata()
{
    cout<<"enter date : ";
    cin>>day;
    cin>>month;
    cin>>year;
}

void operator +(date &a,int b)
{
    a.day+=b;
    
    while(a.day>30){
        a.day-=30;
        a.month+=1;
        
        if(a.month>12){
            a.month-=12;
            a.year+=1;
        }
    }
}

void date::displaydata(){
    cout<<"updated date is : " <<day<<"/"<<month<<"/"<<year;
}

int main()
{
    date a;
    
    int b;
    
    a.inputdata();
    cout<<"enter days to add : ";
    cin>>b;
    
    a+b;
    a.displaydata();
}