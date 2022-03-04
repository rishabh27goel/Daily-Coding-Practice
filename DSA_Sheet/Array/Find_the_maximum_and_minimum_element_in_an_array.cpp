#include <iostream>
using namespace std;

int findMax(int *arr, int n){

    int max = INT_MIN;

    for(int i=0; i<n; i++){

        if(arr[i] > max){

            max = arr[i];
        }
    }

    return max;
}

int findMin(int *arr, int n){

    int min = INT_MAX;

    for(int i=0; i<n; i++){

        if(arr[i] < min){

            min = arr[i];
        }
    }

    return min;
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

    int min = findMin(arr, n);
    cout <<"Minimum is : " <<min <<endl;

    int max = findMax(arr, n);
    cout <<"Maximum is : " <<max <<endl;

    return 0;
}