#include <iostream>
using namespace std;

void rotate(int *arr, int n)
{
    if(n == 0) return;
    
    int track = arr[n-1];
    
    for(int i=0; i<n; i++){
        
        int store = arr[i];
        arr[i] = track;
        track = store;
    }
}

int main()
{
    int n;
    cout<<"Enter the size of the array : ";
    cin>> n;

    int arr[n];
    cout<<"Enter the elements of the array : ";
    for(int i=0; i<n; i++){

        cin>> arr[i];
    }

    rotate(arr, n);

    cout<<"Rotated Array : ";
    for(int i=0; i<n; i++){

        cout<<arr[i]<<" ";
    }

    cout<<endl;
    return 0;
}