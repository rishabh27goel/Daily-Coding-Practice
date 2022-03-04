// Given an unsorted array arr[] of size N having both 
// negative and positive integers. The task is place all 
// negative element at the end of array without changing 
// the order of positive element and negative element.

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void segregateElements(int *arr,int n){
    
    int i = 0;
    int j = 0;
    
    vector<int> trackElements;
    
    while(j < n){
        
        if(arr[j] >= 0){
            
            swap(arr[j], arr[i]);
            i++;
        }
        else{
            
            trackElements.push_back(arr[j]);
            
        }
        
        j++;
    }
    
    if(i < n){
        
        for(int x=i; x<n; x++){

            arr[x] = trackElements[x-i];
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

    segregateElements(arr, n);
    cout<<"\nModified Array : ";
    for(int i=0; i<n; i++){

        cout<<arr[i]<<" ";
    }


    cout<<endl;
    return 0;
}