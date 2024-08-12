// 1. Write a program to create class Time (int h, int m, int s). Read a value as
// seconds from user to display new time after adding the value to minutes in
// Time.

#include<iostream>
using namespace std;

class Time{
    int h;
    int m;
    int s;
    
    public:
    
    void inputdata();
    void addtime();
    
};

void Time :: inputdata()
{
    cout<<"enter hours : ";
    cin>>h;
    cout<<"enter minutes : ";
    cin>>m;
    cout<<"enter seconds : ";
    cin>>s;
    
    cout<<"your entered time is : "<<h<<":"<<m<<":"<<s<<" \n";
    
}
void Time::addtime()
{
    int addseconds;
    cout<<"enter seconds to add : ";
    cin>>addseconds;
    
    s += addseconds;
    while(s >= 60){
        s -= 60;
        m += 1;
        if(m >= 60){
            m -= 60;
            h += 1;
        }
        if(h >= 12){
            h-= 12;
            h;
        }   
    }
    cout<<"new time is : "<<h<<":"<<m<<":"<<s<<endl;
}
    

int main()
{
    Time t;
    t.inputdata();
    t.addtime();
}