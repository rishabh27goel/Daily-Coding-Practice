#include <iostream>
#include <algorithm>
using namespace std;

void sortArrayOf_0_1_2(int *arr, int n){

    int start = 0;
    int mid = 0;
    int end = n-1;

    while(mid <= end){

        if(arr[mid] == 0){

            swap(arr[start], arr[mid]);
            start++;
            mid++;
        }
        else if(arr[mid] == 1){

            mid++;
        }
        else if(arr[mid] == 2){

            swap(arr[mid], arr[end]);
            end--;
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

    sortArrayOf_0_1_2(arr, n);

    cout<<"\nSorted Array : ";
    for(int i=0; i<n; i++){

        cout<<arr[i]<<" ";
    }

    cout<<endl;
    return 0;
}