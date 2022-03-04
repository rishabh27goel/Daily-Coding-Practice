#include <iostream>
#include <algorithm>
using namespace std;

void sortArrayOf_0_1(int *arr, int n){

    int i = 0;
    int j = n-1;

    while(i <= j){

        if(arr[i] == 1){

            swap(arr[i], arr[j]);
            j--;
        }
        else if(arr[i] == 0){

            i++;
        }
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

    sortArrayOf_0_1(arr, n);

    cout<<"\nSorted Array : ";
    for(int i=0; i<n; i++){

        cout<<arr[i]<<" ";
    }

    return 0;
}