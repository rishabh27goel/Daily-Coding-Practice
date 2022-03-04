#include <iostream>
using namespace std;


// Time Complexity : O(n^2)
// void largestSumContiguousSubarray(int arr[], int n){

//     int largestSum = INT_MIN;

//     for(int i=0; i<n; i++){

//         int currentSum = 0;
//         for(int j=i; j<n; j++){

//             currentSum += arr[j];
            
//             if(largestSum < currentSum){

//                 largestSum = currentSum;
//             }
//         }
//     }

//     cout <<"Largest Sum is : " <<largestSum;
// }

// Time Complexity : O(n) [Kadane's Algorithm]
void largestSumContiguousSubarray(int arr[], int n){

    int largestSum = INT_MIN;
    int currentSum = 0;

    for(int i=0; i<n; i++){

        currentSum += arr[i];

        if(largestSum < currentSum){

            largestSum = currentSum;
        }

        if(currentSum < 0){

            currentSum = 0;
        }
    }

    cout <<"Largest Sum is : " <<largestSum;
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

    largestSumContiguousSubarray(arr, n);

    cout<<endl;
    return 0;
}