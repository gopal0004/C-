#include<iostream>
#include<stdlib.h>
using namespace std;

struct node{
    struct node *next;
    int data;
};
struct node *top=NULL;

void push()
{
    struct node *new_node;
    int data;
    
    new_node=(struct node *)malloc(sizeof(struct node));
    
    cout<<"enter data : ";
    cin>>data;  
    
    new_node->data=data;
    new_node->next=top;
    top=new_node;
    cout<<endl;
}
void pop()
{
    if(top==NULL){
        cout<<"stack underflow : ";
    }
    else{
        cout<<"popped element is : "<<top->data;
        top=top->next;
    }
    cout<<endl;
}
void display()
{
    if(top==NULL){
        cout<<"stack is empty \n";
        return;
    }
    struct node *ptr;
    ptr=top;
    while(top!=NULL){
        cout<<top->data;
        top=top->next;
    }
    cout<<endl;
}

int main(){
    int choice;
    
    do{
        cout<<"1.push \n";
        cout<<"2.pop \n";
        cout<<"3.display \n";
        cout<<"4.exit \n";
        
        cout<<"enter choice : ";
        cin>>choice;
        
        switch(choice){
            case 1:{
                push();
                break;
            }
            case 2:{
                pop();
                break;
            }
            case 3:{
                display();
                break;
            }
            case 4:{
                cout<<"exit : ";
            }
        }
    }
    while(choice !=4);
}