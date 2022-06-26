#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Method 1 : Using Sort Function
// Time Complexity : O(n * log(n))  Space Complexity : O(1)
// int kthSmallestElement(vector<int> &arr, int k){

//     if(k == 0 || k > arr.size()) return -1;

//     // Sort the array
//     sort(arr.begin(), arr.end());

//     return arr[k-1];
// }

// Method 2 : Using Max Heap
// Time Complexity : O(k + (n-k)*log(k))  Space Complexity : O(k)
// int kthSmallestElement(vector<int> &arr, int k){

//     if(k == 0 || k > arr.size()) return -1;

//     priority_queue<int> pq;

//     // Build Max Heap from first k elements
//     for(int i=0; i<k; i++){

//         pq.push(arr[i]);
//     }

//     // Rest elements
//     for(int i=k; i<arr.size(); i++){

//         if(pq.top() > arr[i]){

//             pq.pop();
//             pq.push(arr[i]);
//         }
//     }

//     return pq.top();
// }

// Method 3 : Using Min Heap
// Time Complexity : O(n + k * log(n))  Space Complexity : O(n)
int kthSmallestElement(vector<int> &arr, int k){

    if(k == 0 || k > arr.size()) return -1;

    priority_queue<int, vector<int>, greater<int> > pq;

    // Create Min Heap for all elements
    for(int i=0; i<arr.size(); i++){

        pq.push(arr[i]);
    }

    // Remove top k-1 times for kth smallest
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

    // Kth Smallest Element
    int value = kthSmallestElement(arr, k);

    cout << "Kth Smallest Element is : " << value;

    cout << endl;
    return 0;
}