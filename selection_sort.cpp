#include<iostream>
using namespace std;

void SelectionSort()
{
    int n;
    cout<<"enter number of element you want to insert in array : ";
    cin>>n;
    
    int arr[n];
    cout <<"enter elements : ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i] > arr[j]){
                int temp;
                temp=arr[i];
                arr[i]=arr[j];
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
    SelectionSort();
}