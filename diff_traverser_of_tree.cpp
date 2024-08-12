#include<iostream>
#include<stdlib.h>
#include<queue>
using namespace std;

struct node{
    int data;
    struct node *left;
    struct node *right;
    
    node(int value){
        data=value;
        left=NULL;
        right=NULL;
    }
};

node *insertdata(node *root,int data)
{
    if(root==NULL)
    {
        root=new node(data);
        return root;
    }
    if(data > root->data){
        root->right=insertdata(root->right,data);
    }
    else{
        root->left=insertdata(root->left,data);
    }
    return root;
}

void inputdata(node* &root)
{
    int data;
    cout<<"enter data : ";
    cin>>data;
    while(data != -1){
        root=insertdata(root,data);
        cin>>data;
    }
}

void inorder(node *root)
{
    if(root==NULL){
        return ;
    }
    inorder(root->left);
    cout<<" "<<root->data;
    inorder(root->right);
}

void preorder(node *root){
    if(root==NULL)
    {
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(node *root)
{
    if(root==NULL)
    {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}

void levelOrder(node* root){
    queue<node*> q;
    q.push(root);
    q.push(NULL);
        while(!q.empty()){
            node* temp=q.front();
            q.pop();
            if(temp==NULL){
                cout<<endl;
                if(!q.empty()){
                    q.push(NULL);
                }
            }
            else{
                cout<<temp->data<<" ";
                if(temp->left){
                    q.push(temp->left);
                }if(temp->right){
                    q.push(temp->right);
                }
            }
        }
}

int main()
{
    node *root=NULL;
    // cout<<"enter data : ";
    inputdata(root);
    cout<<"\n inorder : ";
    inorder(root);
    cout<<"\n preorder : ";
    preorder(root);
    cout<<"\n postorder : ";
    postorder(root);
    cout<<"\n level order : ";
    levelOrder(root);
    
}
