#include<iostream>
#include<stdlib.h>
using namespace std;

struct node{
	
	int data;
	struct node *next;
	struct node *prev;
};

struct node *head;

void create_doubly()
{
	struct node *new_node,*current=NULL;
	int data;
	int n;
	
	cout<<"enter number of node you want to insert : ";
	cin>>n;
	
	new_node=(struct node *)malloc(sizeof(struct node));
	
	cout<<"enter data for node 1 : ";
	cin>>data;
	
	head=new_node;
	new_node->data=data;
	new_node->next=NULL;
	new_node->prev=NULL;
	
	for(int i=2;i<=n;i++)
	{
		cout<<"enter data for node "<<i<<" : \n";
		cin>>data;
		
		current=(struct node *)malloc(sizeof(struct node));
		
		current->data=data;
		current->next=NULL;
		current->prev=new_node;
		new_node->next=current;
		new_node=current;
	}
}

void traversal()
{
    struct node *ptr;
    
    cout<<"list is : ";
    ptr=head;
    while(ptr != NULL)
    {
        cout<<ptr->data<<" ";
        ptr=ptr->next;
    }
}

void insert_beg()
{
    struct node *new_node;
    int data;
    
    new_node=(struct node *)malloc(sizeof(struct node));
    
    cout<<"\n enter data you want to insert at begining : ";
    cin>>data;
    
    
    new_node->data=data;
    new_node->next=head;
    new_node->prev=NULL;
    head->prev=new_node;
    head=new_node;
}

void insert_end()
{
    struct node *new_node,*ptr;
    int data;
    
    cout<<"\n enter data you want to insert at end : ";
    cin>>data;
    
    new_node=(struct node *)malloc(sizeof(struct node));
    
    new_node->data=data;
    new_node->next=NULL;
    
    ptr=head;
    while(ptr -> next != NULL)
    {
        ptr=ptr->next;
    }
    ptr->next=new_node;
    new_node->prev=ptr;
}

void insert_after()
{
    struct node *new_node,*ptr;
    int data,pos;
    
    new_node=(struct node *)malloc(sizeof(struct node));
    
    cout<<"\n enter position : ";
    cin>>pos;
    cout<<"\n enter data you want to insert after given node : ";
    cin>>data;
    
    new_node->data=data;
    
    ptr=head;
    while(ptr!=NULL&&ptr->data!=pos)
    {
        ptr=ptr->next;
    }
    
    if(ptr==NULL){
        cout<<"\n given element is not present in the list ";
    }
    
    new_node->next=ptr->next;
    new_node->prev=ptr;
    
    if(ptr->next != NULL)
    {
        ptr->next->prev=new_node;
    }
    ptr->next=new_node;
}

void insert_before()
{
    struct node *new_node,*ptr;
    int data,pos;
    
    new_node=(struct node *)malloc(sizeof(struct node));
    
    cout<<"\n enter position before : ";
    cin>>pos;
    cout<<"\n enter data to insert before given node : ";
    cin>>data;
    
    new_node->data=data;
    
    ptr=head;
    while(ptr != NULL && ptr->data!=pos)
    {
        ptr=ptr->next;
    }
    
    if(ptr==NULL){
        cout<<"\n given element is not present in list";
    }
    else
    {
        ptr->prev->next=new_node;
        new_node->prev=ptr->prev;
        new_node->next=ptr;
        ptr->prev=new_node;
    }
    
}

void delete_beg()
{
    struct node *ptr;
    ptr=head;
    head=head->next;
    head->prev=ptr;
    free (ptr);
    cout<<"\n Deletion at begining has been completed \n";
}

void delete_end()
{
    struct node *ptr;
    
    ptr=head;
    while(ptr->next!=NULL){
        ptr=ptr->next;
    }
    
    if(head==NULL)
    {
        cout<<"\n list is empty  ";
    }
    
    else{
        ptr->prev->next=NULL;
        free (ptr);
    }
    cout<<"\n deletion at end has been completed \n ";
}

void delete_at_given()
{
    struct node *ptr;
    int data;
    
    cout<<"\n enter data you want to delete : ";
    cin>>data;
    
    ptr=head;
    while(ptr!=NULL && ptr->data!=data)
    {
        ptr=ptr->next;
    }
    if(ptr==NULL){
        cout<<"\n data is not present in the list";
    }
//    else if(ptr==head){
//        head=ptr->next;
//        head->prev=NULL;
//        free(ptr);
//    }
    else{
        ptr->prev->next=ptr->next;
        ptr->next->prev=ptr->prev;
        free(ptr);
    }
    cout<<"\n deletion at given position has been completed \n ";
}


int main()
{
    create_doubly(); 
    traversal();
//    insert_beg();
//    traversal();
//    insert_end();
//    traversal();
//    insert_after();
//	  traversal();
//    insert_before();
//    traversal();
//    delete_beg();
//    traversal();
//    delete_end();
	delete_at_given();
    traversal();
}
