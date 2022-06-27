#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Method 1 : Using Bubble Sort
// Time Complexity : O(n * k)  Space Complexity : O(1)
// vector<int> kLargestElements(vector<int> &arr, int k){

//     vector<int> output;
//     if(arr.size() == 0 || k > arr.size()) return output;

//     int index = arr.size()-1;

//     for(int i=0; i<k; i++){

//         for(int j=0; j<arr.size()-1; j++){

//             if(arr[j] > arr[j+1]){

//                 swap(arr[j], arr[j+1]);
//             }
//         }

//         output.push_back(arr[index]);
//         index--;
//     }

//     return output;
// }

// Method 2 : Using Sort Function
// Time Complexity : O(n * log(n))  Space Complexity : O(1)
// vector<int> kLargestElements(vector<int> &arr, int k){

//     vector<int> output;
//     if(arr.size() == 0 || k > arr.size()) return output;

//     // Sort the Vector
//     sort(arr.begin(), arr.end(), greater<int>());

//     for(int i=0; i<k; i++){

//         output.push_back(arr[k]);
//     }

//     return output;
// }

// Method 3 : Using Min Heaps
// Time Complexity : O(k + ((n-k) * log(k)))  Space Complexity : O(k)
// vector<int> kLargestElements(vector<int> &arr, int k){

//     vector<int> output;
//     if(arr.size() == 0 || k > arr.size()) return output;

//     // Create Min Heap for first k elements
//     priority_queue<int, vector<int>, greater<int> > pq;

//     for(int i=0; i<k; i++){

//         pq.push(arr[i]);
//     }

//     // Rest n-k elements
//     for(int i=k; i<arr.size(); i++){

//         if(pq.top() < arr[i]){

//             pq.pop();
//             pq.push(arr[i]);
//         }
//     }

//     // Now largest k elements are present in the heap
//     // If not sorting is needed 
//     while(!pq.empty()){

//         output.push_back(pq.top());
//         pq.pop();
//     }


//     return output;
// }

// Method 4 : Using Max Heaps
// Time Complexity : O(n + (k * log(n)))  Space Complexity : O(n)
vector<int> kLargestElements(vector<int> &arr, int k){

    vector<int> output;
    if(arr.size() == 0 || k > arr.size()) return output;

    // Create Max Heap
    priority_queue<int> pq;

    for(int i=0; i<arr.size(); i++){

        pq.push(arr[i]);
    }

    // Remove top element k times
    for(int i=0; i<k; i++){

        output.push_back(pq.top());
        pq.pop();
    }

    return output;
}

int main()
{
    cout << "Enter size of the array : ";
    int n;
    cin >> n;


    cout << "Enter data : ";
    vector<int> arr;
    int data;

    for(int i=0; i<n; i++){

        cin >> data;
        arr.push_back(data);
    }

    cout << "Enter value of k : ";
    int k;
    cin >> k;

    vector<int> output = kLargestElements(arr, k);

    cout << "Max Elements : ";
    for(int i=0; i<output.size(); i++){

        cout << output[i] << " ";
    }

    cout << endl;
    return 0;
}