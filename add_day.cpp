// 2. WAP to define a class Date with properties int month; int day; int year;
// Overload the + operator [+a] (a is of date type). Add 1 day to the date each
// time +a is called, use the assumption that all years have 360 days and
// months 30 days.

#include<iostream>
using namespace std;

class date{
    public:
        int day;
        int month;
        int year;
        
    public:
        void input();
        void display();
        // void operator +(date &a,int b);
};

void date::input()
{
    cout<<"enter data";
    cin>>day;
    cin>>month;
    cin>>year;
}
void  operator +(date &a,int b)
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

void date::display()
{
    cout<<day<<"/"<<month<<"/"<<year;
}

int main()
{
    // int b;
    date d;
    
    d.input();
    // cout<<"enter number of days to add : ";
    // cin>>b;
    
    d+1;
    d+1;
    d.display();
}