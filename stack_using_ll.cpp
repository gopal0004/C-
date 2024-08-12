#include<iostream>
#include<stdlib.h>
using namespace std;

struct node{
	
	int data;
	struct node *next;
};

struct node *top;

void push(int data)
{
	struct node *new_node;
	
	new_node=(struct node *)malloc(sizeof(struct node));
	
	new_node->data=data;
	new_node->next=top;
	top=new_node;
}
void pop()
{
	struct node *ptr;
	ptr=top;
	if(top==NULL){
		cout<<"\n List is Empty ";
	}
	else{
		cout<<"\n the popped elements is : "<<top->data;
		top=top->next;
	}
}
void display()
{
	struct node *ptr;
	if(top==NULL)
	{
		cout<<"\n List is empty ";
	}
	cout<<"your stack elements are : ";
	ptr=top;
	while(ptr->next!=NULL)
	{
		ptr=ptr->next;
	}
}
int main()
{
	int data;
	int choice;
	
	cout<<"1.push in stack \n";
    cout<<"2.pop in stack \n ";
    cout<<"3.display stack \n ";
    cout<<"4. exit \n ";
	
	do{
		cout<<"enter choice : ";
		cin>>choice;
		
		switch(choice){
			case 1:{
				
				cout<<"enter element : ";
				cin>>data;
				push(data);
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
				cout<<"EXIT";
				break;
			}
			default:{
				cout<<"invalid choice : ";
				break;
			}
		}
	}while(choice!=4);
}