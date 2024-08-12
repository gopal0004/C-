#include<iostream>
using namespace std;

void InsertionSort()
{
    int n;
    cout << "Enter the number of elements you want to insert in the array: ";
    cin >> n;

    int arr[n];
    cout << "Enter data: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Insertion Sort 
    for (int i = 1; i < n; i++) {
        int current = arr[i];
        int j = i - 1;

        while (j >= 0 && current < arr[j]) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = current;
    }

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << " " << arr[i];
    }
}

int main()
{
    InsertionSort();
    return 0;
}
