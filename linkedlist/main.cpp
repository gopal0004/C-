#include<stdlib.h>
#include<iostream>
using namespace std;

struct node {
    
    int data;
    struct node *next;
};
struct node *head;


void create_list(int n){
    
    struct node *current,*temp;
    int data;
    
    head=(struct node *)malloc(sizeof(struct node));
    
    cout<<"\n enter data for node 1 : ";
    cin>>data;
    
    head->data=data;
    head->next=NULL;
    
    temp=head;
    for(int i=2;i<=n;i++){
        current=(struct node *)malloc(sizeof(struct node));
        
        cout<<"\n enter data for "<< i <<":";
        cin>>data;
        
        current->data=data;
        current->next=NULL;
        
        temp->next=current;
        temp=temp->next;
        
    }
}
void traversal()
{
    struct node *ptr;
    ptr=head;
    
    cout<<" \n list is :";
    while(ptr!=NULL){
        cout<<ptr->data;
        ptr=ptr->next;
    }
    
}

void insert_beg()
{
    struct node *new_node,*ptr;
    int data;
    
    cout<<"enter data to insert at beg : ";
    cin>>data;
    
    new_node=(struct node *)malloc(sizeof(struct node));
    
    new_node->data=data;
    new_node->next=head;
    head=new_node;
}
void insert_end()
{
    struct node *ptr,*new_node;
    int data;
    
    cout<<"\n enter data to insert at end : ";
    cin>>data;
    
    new_node=(struct node *)malloc(sizeof(struct node));
    
    new_node->data=data;
    new_node->next=NULL;
    
    ptr=head;
    while(ptr->next!=NULL){
        ptr=ptr->next;
    }
    ptr->next=new_node;
}
void insert_after(){
    
    struct node *new_node,*ptr;
    int data,pos;
    
    new_node=(struct node *)malloc(sizeof(struct node));
    
    cout<<"enter data to enter node after given node :";
    cin>>data;
    
    cout<<"enter position :";
    cin>>pos;
    
    new_node->data=data;
    new_node->next=NULL;
    
    ptr=head;
    while(ptr!=NULL&&ptr->data!=pos){
        ptr=ptr->next;
    }
    
    if(ptr!=NULL){
        new_node->next=ptr->next;
        ptr->next=new_node;
    }
    else{
        cout<<"position does not exist ";
    }
    
}

void insert_before()
{
    struct node *new_node,*ptr;
    int data,pos;
    
    new_node=(struct node *)malloc(sizeof(struct node));
    
    cout<<"enter data to insert node before given node : ";
    cin>>data;
    
    cout<<"enter position";
    cin>>pos;
    
    new_node->data=data;
    
    ptr=head;
    while(ptr!=NULL && ptr->next->data!=pos){
        ptr=ptr->next;
    }
    if(ptr!=NULL){
        new_node->next=ptr->next;
        ptr->next=new_node;
    }
    else{
        cout<<"position does not exist ";
    }
    
}

void delete_beg()
{
    struct node *ptr;
    ptr=head;
    head=head->next;
    free(ptr);
    
    cout<<"deleted at beg:";
}

void delete_end()
{
   struct node *ptr,*prev;
   if(head==NULL){
       cout<<"list is empty :";
   }
   ptr=head;
   prev=NULL;
   
   while(ptr->next!=NULL){
       prev=ptr;
       ptr=ptr->next;
   }
   if(prev!=NULL){
       prev->next=NULL;
   }
   else{
       head=NULL;
   }
   free(ptr);
   cout<<"deleted at end";
}

// void delete_after(){
//     struct node *ptr,*prev;
//     int data;
    
//     cout<<"enter node after which you want to delete node : ";
//     cin>>pos;
    
//     if(head=NULL){
//         cout<<"list is empty :";
//     }
//     ptr=head;
    
//     while(ptr!=NULL && ptr->data !=pos){
        
//         ptr=ptr->next;
//     }
//     if(ptr==NULL){
//         cout<<"node not found ";
//     }
//     if(ptr->next==NULL){
//         cout<<"there is no node after givrn node to delete";
//     }
//     prev=ptr->next;
//     ptr->next =prev->next;
//     free(prev);
    
//     cout<<"deletion complete after given node :";
    
// }

int main()
{
    int n;
    cout<<" \n enter number of node to be created : ";
    cin>>n;
    
    create_list(n);
    // insert_after();
    // insert_before();
    // delete_beg();
    // delete_end();
    delete_after();
    // insert_beg();
    // insert_end();
    traversal();
}
