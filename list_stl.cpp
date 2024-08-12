#include<iostream>
#include<list>
using namespace std;

template<typename type>
void display_list(list<type> &lst)
{
    list<int>::iterator i;
    
    for(i=lst.begin();i != lst.end();i++){
        cout<< *i <<" ";
    }
}

int main()
{
    
    list<int>l1;
    int n;
    int element;
    
    cout<<"enter no of elements you want to insert in list : ";
    cin>>n;
    
    for(int i=0;i<n;i++)
    {
        cout<<"enter element : ";
        cin>>element;
        l1.push_back(element);
    }
    display_list(l1);
    
    cout<<"\n reverse list is : ";
    l1.reverse();
    display_list(l1);
    
    // creating list2 and merging two lists & sorting
    list<int>l2;
    int m,ele;
    cout<<"\n enter no of elements you want to insert in list2 : " ;
    cin>>m;
    for(int j=0;j<m;j++)
    {
        cout<<"enter ele : ";
        cin>>ele;
        l2.push_back(ele);
    }
    cout<<"\n second list is : ";
    display_list(l2);
    
    cout<<"\n sorted list1 is : ";
    l1.sort();
    display_list(l1);
    
    cout<<"\n sorted list2 is : ";
    l2.sort();
    display_list(l2);
    
    // merging
    cout<<"\n merging two list's elements : ";
    l1.merge(l2);
    display_list(l1);
    
}
