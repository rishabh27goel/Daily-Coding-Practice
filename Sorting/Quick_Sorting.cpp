#include <iostream>
#include <algorithm>
using namespace std;

int partition(int *arr, int start, int end){

    int pivot = end;
    int i = start;
    int j = end-1;

    while(i <= j){

        if(arr[i] < arr[pivot]){

            i++;
        }
        else{

            swap(arr[i], arr[j]);
            j--;
        }
    }

    swap(arr[i], arr[pivot]);
    
    return i;
}

void quickSort(int *arr, int start, int end){

    // Base Case
    if(start >= end) return;

    int p = partition(arr, start, end);

    // Recursive call for rest of the array
    quickSort(arr, start, p-1);
    quickSort(arr, p+1, end);
}

int main()
{
    int n;
    cout << "Enter size of the array : ";
    cin >> n;

    int arr[n];
    cout << "Enter elements of the array : ";
    for(int i=0; i<n; i++){

        cin >> arr[i];
    }

    // Quick Sort Algorithm
    quickSort(arr, 0, n-1);

    cout << "Sorted Array : ";
    for(int i=0; i<n; i++){

        cout << arr[i] << " ";
    }


    cout << endl;
    return 0;
}