#include <iostream>
#include <algorithm>
using namespace std;

void reverseHelper(int *arr, int index, int n){

    int start = index;
    int end = n-1;

    while(start <= end){

        swap(arr[start], arr[end]);
        start++;
        end--;
    }
}

void nextPermutation(int *arr, int n){

    if(n < 2) return;

    int decreasingIndex = -1;

    for(int i=n-2; i>=0; i--){

        if(arr[i] < arr[i+1]){

            decreasingIndex = i;
            break;
        }
    }

    if(decreasingIndex != -1){

        int justLarger = -1;

        for(int j=decreasingIndex+1; j<n; j++){

            if(arr[decreasingIndex] >= arr[j]){

                break;
            }

            justLarger = j;
        }

        swap(arr[justLarger], arr[decreasingIndex]);
    }


    // Decreasing Index

    reverseHelper(arr, decreasingIndex+1, n);
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

    nextPermutation(arr, n);

    cout<<"Next Permutation is : ";
    for(int i=0; i<n; i++){

        cout<<arr[i]<<" ";
    }

    cout<<endl;
    return 0;
}