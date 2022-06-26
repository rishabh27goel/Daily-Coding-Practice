#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Method 1 : Using Sort Function
// Time Complexity : O(n * log(n))  Space Complexity : O(1)
// int kthLargestElement(vector<int> &arr, int k){

//     if(k == 0 || k > arr.size()) return -1;

//     // Sort the array
//     sort(arr.begin(), arr.end(), greater<int>());

//     return arr[k-1];
// }

// Method 2 : Using Min Heap
// Time Complexity : O(k + (n-k)*log(k))  Space Complexity : O(k)
// int kthLargestElement(vector<int> &arr, int k){

//     if(k == 0 || k > arr.size()) return -1;

//     priority_queue<int, vector<int>, greater<int> > pq;

//     // Create Min Heap for first k elements 
//     for(int i=0; i<k; i++){

//         pq.push(arr[i]);
//     }

//     // Rest n-k elements check with top node
//     for(int i=k; i<arr.size(); i++){

//         if(pq.top() < arr[i]){

//             pq.pop();
//             pq.push(arr[i]);
//         }
//     }

//     return pq.top();
// }

// Method 3 : Using Max Heap
// Time Complexity : O(n + k * log(n))  Space Complexity : O(n)
int kthLargestElement(vector<int> &arr, int k){

    if(k == 0 || k > arr.size()) return -1;

    priority_queue<int> pq;   

    // Create Max Haep for all elements
    for(int i=0; i<arr.size(); i++){

        pq.push(arr[i]);
    }

    // Remove k-1 times top element of heap
    for(int i=0; i<k-1; i++){

        pq.pop();
    }

    return pq.top();
}

int main()
{
    cout << "Enter size of array : ";
    int n;
    cin >> n;

    cout << "Enter elements : ";
    vector<int> arr;
    int data;

    for(int i=0; i<n; i++){

        cin >> data;
        arr.push_back(data);
    }

    cout << "Enter value of k : ";
    int k;
    cin >> k;

    // Kth Largest Element
    int value = kthLargestElement(arr, k);

    cout << "Kth Largest Element is : " << value;

    cout << endl;
    return 0;
}