#include<iostream>
using namespace std;

int Binary_search(int arr[],int beg,int end,int target)
{
    
    int mid=(beg+end)/2;
    
    if(beg>end){
        cout<<"index not found : ";
        return -1;
    }
    if(arr[mid]==target){
        return mid;
    }
    else if(arr[mid] > target)
    {
        return Binary_search(arr,beg,mid-1,target);
    }
    else if(arr[mid] < target)
    {
        return Binary_search(arr,mid+1,end,target);
    }
    return mid;
}

int main()
{
    int size,target;
    cout<<"enter size of the array : ";
    cin>>size;
    
    int arr[size];
    for(int i=0;i<size;i++){
        cout<<"enter element : ";
        cin>>arr[i];
    }
    int beg=0;
    int end=size-1;
    
    cout<<"enter target : ";
    cin>>target;
    
    cout<<"target at index : "<<Binary_search(arr,beg,end,target)<<endl;
}