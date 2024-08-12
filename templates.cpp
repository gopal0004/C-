#include<iostream>
#include<vector> 
using namespace std;

template<typename type>
void display(vector<type> &v)//parameter because of it points the same vector we create in main
{
    cout<<"\n pushed elements are : ";
    for(int i=0;i<v.size();++i){
        cout<<v[i]<<" ";
    }
}



int main()
{
    // vector<int>vec1;
    
    // int n;
    // cout<<"\nenter number of elements you want to push on vector : ";
    // cin>>n;
    
    // for(int i=0;i<=n;i++)
    // {
    //     cout<<" enter element : ";
    //     cin>>i;
    //     vec1.push_back(i);
    // }
    // cout<<"\n the size of the vector is : "<<vec1.size();// for size 
    
    // display(vec1);
    // // for iterator by this we can insert element at any position by using begin() & end() function
    // vector<int>::iterator i =vec1.end();
    // vec1.insert(i-1,100);
    // display(vec1);
    
    vector<int>v1(5,10);
    cout<<"\n v1 : ";
    display(v1);
    
    vector<int>v2(10,5);
    cout<<"\n v2 : ";
    display(v2);
    // v2.push_back(10,5);
    
    v1.swap(v2);
    cout<<"\n after swapping v1 ";
    display(v1);
    cout<<"\n after swapping v2 ";
    display(v2);
    
    
}
