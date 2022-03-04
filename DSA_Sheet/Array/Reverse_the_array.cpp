#include <iostream>
#include <algorithm>
using namespace std;

void reverseArray(int *arr, int n){

    int i = 0;
    int j = n-1;

    while(i <= j){

        swap(arr[i], arr[j]);
        i++;
        j--;
    }
}

int main()
{
    int n;
    cout<<"Enter the size of the array : ";
    cin>> n;

    int arr[n];
    cout<<"Enter the elements : ";
    
    for(int i=0; i<n; i++){

        cin>> arr[i];
    }

    reverseArray(arr, n);

    cout<<"\nReversed Array : ";
    for(int i=0; i<n; i++){

        cout<<arr[i]<<" ";
    }

    cout<<endl;
    return 0;    
}