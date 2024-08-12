#include<iostream>
#include<stdlib.h>
using namespace std;

struct node
{
    int data;
    struct node *next;
};

struct node *front=NULL;
struct node *rear=NULL;

void enque(int data)
{
    struct node * new_node;
    new_node=(struct node *)malloc(sizeof(struct node));
    
    new_node->data=data;
    new_node->next=NULL;
    
    if(front ==NULL && rear ==NULL){
        front=rear=new_node;
        return;
    }
    rear->next=new_node;
    rear=new_node;
}

void deque()
{
    struct node *ptr;
    ptr=front;
    
    if(front==NULL){
        cout<<"queue is empty : \n";
    }
    else if(front==rear){
        front=rear=NULL;
    }
    else{
        front=front->next;
    }
    free(ptr);
}

void display()
{
    struct node *ptr;
    ptr=front;
    while(ptr!=NULL){
        cout<<ptr->data<<" ";
        ptr=ptr->next;
    }
    
    cout<<"\n";
}

int main()
{
    int data;
    int choice;
    
    cout<<"1.enque in que : \n";
    cout<<"2.deque in queue :\n";
    cout<<"3.display queue :\n";
    cout<<"4.exit \n";
    
    do{
        cout<<"enter choice : ";
        cin>>choice;
        
        switch(choice){
            
            case 1:{
                cout<<"enter data to be enqued :";
                cin>>data;
                enque(data);
                break;
            }
            case 2:{
                deque();
                break;
            }
            case 3:{
                display();
                break;
            }
            case 4:{
                cout<<"exit \n";
                break;
                
            }
            default:{
                cout<<"invalid choice :\n";
            }
        }
    }
    while(choice!=4);
}
