#include<iostream>
using namespace std;

class matrix{
    public:
        int arr[3][3];
    public:
        void inputdata();
        void displaydata();
};
void matrix::inputdata()
{
    cout<<"---------------entering data for matrix-----------------\n";
    for(int i=0;i<3;i++){
        cout<<"enter data for row "<<i+1<<" : \n";
        for(int j=0;j<3;j++){
            cin>>arr[i][j];
        }
        cout<<endl;
    }
    cout<<endl;
}

void operator *(matrix &m ,int num){
    matrix result;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cout<< m.arr[i][j] * num;
        }
        cout<<endl;
    }
    cout<<endl;
}

void matrix::displaydata()
{
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}
int main()
{
    matrix m;
    m.inputdata();
    
    cout<<"enter number to multiply : ";
    int n;
    cin>>n;
    
    m*n;
    m.displaydata();
}