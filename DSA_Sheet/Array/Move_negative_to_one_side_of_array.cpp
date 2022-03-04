#include <iostream>
#include <algorithm>
using namespace std;

void moveNegativeToLeft(int *arr, int n){

    int i = 0;
    int j = n-1;

    while(i <= j){

        if(arr[i] < 0){

            i++;
        }
        else{

            swap(arr[i], arr[j]);
            j--;
        }
    }
}

void moveNegativeToRight(int *arr, int n){

    int i = 0;
    int j = n-1;

    while(i <= j){

        if(arr[i] >= 0){

            i++;
        }
        else{

            swap(arr[i], arr[j]);
            j--;
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

    moveNegativeToLeft(arr, n);
    cout<<"\nNegative To Left : ";
    for(int i=0; i<n; i++){

        cout<<arr[i]<<" ";
    }

    moveNegativeToRight(arr, n);
    cout<<"\nNegative To Right : ";
    for(int i=0; i<n; i++){

        cout<<arr[i]<<" ";
    }

    cout<<endl;
    return 0;
}