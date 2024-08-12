#include<iostream>
using namespace std;

void BubbleSort()
{
    int n;
    cout<<"enter number of elements you want to insert in array : ";
    cin>>n;
    
    int arr[n];
    cout<<"enter elements : ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    
    // BubbleSort
    
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(arr[j] > arr[j+1]){
                int temp;
                temp=arr[j+1];
                arr[j+1]=arr[j];
                arr[j]=temp;
            }
        }
    }
    cout<<"sorted array is : ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}

int main()
{
    BubbleSort();
}