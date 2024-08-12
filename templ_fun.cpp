// 2. Write a template function called find(). This function searches an array for
// an object. It returns either the index of the matching object (if one is
// found) or -1 if no match is found.

#include<iostream>
using namespace std;

template<typename type>
void find(){
    
    int size;
    int i;
    
    cout<<"enter size of the array : ";
    cin>>size;
    
    type arr[size];
    
    for(i=0;i<size;i++){
        cout<<"enter element : ";
        cin>>arr[i];
        // cout<<arr[i];
    }
    
    type find;
    cout<<"enter element to find index : ";
    cin>>find;
    
    for(i=0;i<size;i++)
    {
        if(find==arr[i])
        {
            cout<<"the index of the element is : "<<i;
            return;
        }
    }
    
    
    
    cout<<"element not there ";
    
}

int main()
{
    find<int>();
}
