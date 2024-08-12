// Write a program to generate templates function for swapping values of
// variables and show its use with integer, float and character type of data as
// input.
#include<iostream>
#include<string>
using namespace std;

template<typename type>
void swapping(type &a,type &b)
{
    type temp;
    temp=a;
    a=b;
    b=temp;
}

int main()
{
    int a,b;
    float c,d;
    char e,f;
    
    cout<<"enter two integer to swap : \n";
    cin>>a>>b;
    cout<<"enter two floats : \n";
    cin>>c>>d;
    cout<<"enter two character : \n";
    cin>>e>>f;
    
    cout<<"entered value is : \n";
    cout<<"a : "<<a<<"b : "<<b<<"c : "<<c<<"d : "<<d<<"e : "<<e<<"f : "<<f<<endl;
    
    cout<<"after swapping : ";
    
    swapping<int>(a,b);
    swapping<float>(c,d);
    swapping<char>(e,f);
    cout<<"a : "<<a<<"\nb : "<<b<<"\nc : "<<c<<"\nd : "<<d<<"\ne : "<<e<<"\nf : "<<f<<endl;
    cout<<"\n";
}