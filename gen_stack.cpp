// 2. Write an object-oriented program to implement a generic Stack.
// Incorporate all the possible operation on Stack in the program.
#include<iostream>
using namespace std;
template<typename type>
class Stack{
    
    public:
        type *arr;
        int size;
        type data;
        int top;
    
    public:
        
        Stack()
        {
            cout<<"enter number of elements you want to store in stack (size) : ";
            cin>>size;
            
            arr=new type[size];
            data =data;
            top=-1;
        }
        
        void push(){
            
            for(int i=0;i<size;i++){
                cout<<"enter data to push : ";
                cin>>data;
                arr[++top]=data;
                // top++;
            }
        }
        
        void pop()
        {
            if(top==-1){
                cout<<"stack is empty : ";
            }
            else{
                top--;
            }
        }
        
        void display()
        {
            if(top==-1){
                cout<<"list is empty : ";
            }
            else{
                cout<<"stsck elements are : ";
                for(int i=0;i<=top;i++){
                cout<<arr[i]<<" ";
                // i++;
                }
            }
            
        }
};

int main()
{
    Stack<string> s;
    s.push();
    s.pop();
    s.display();
}