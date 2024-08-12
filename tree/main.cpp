#include<iostream>
#include<stdlib.h>
#include<queue>
using namespace std;

class node{
    public:
    
    int data;
    node *left;
    node *right;
    
    node(int d){
        data=d;
        left=NULL;
        right=NULL;
    }
};

node* buildtree(node *root)
{
    int data;
    cout<<"enter data : ";
    cin>>data;
    
    if(data==-1){
        return NULL;
    }
    
    root=new node(data);
    
    cout<<"enter data for inserting node in left "<< data <<" : \n ";
    root->left=buildtree(root->left);
    cout<<"enter data for inserting node in right "<<data<<" : \n ";
    root->right=buildtree(root->right);
    return root;
}
void levelordertraversal(node *root)
{
    queue<node*>q;
    q.push(root);
    q.push(NULL);
    
    while(!q.empty()){
        node *temp=q.front();
        q.pop();    
        
        if(temp==NULL){
            cout<<endl;
            
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout<<temp->data<<" "; // Add a space after each node value
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
    }
}

void preorder(node *root)
{
    if(root==NULL){
        return;
    }
    cout<<root->data <<" ";
    preorder(root->left);
    preorder(root->right);
}
void inorder(node *root)
{
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data <<" ";
    inorder(root->right);
}

void postorder(node *root)
{
    if(root==NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data <<" ";
}

int main()
{
    node *root=NULL;
    root=buildtree(root);
    cout<<"levelordertraversal : ";
    levelordertraversal(root);
    
    cout<<"preorder : ";
    preorder(root);
    cout<<" inorder : ";
    inorder(root);
    cout<<"postorder : ";
    postorder(root);
    return 0;
}

