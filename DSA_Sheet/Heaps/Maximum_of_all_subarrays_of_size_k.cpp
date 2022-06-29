#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// Method 1 : Brute Force
// Time Complexity : O(n * k)  Space Complexity : O(1)
// vector<int> maximumOfWindow(vector<int> &arr, int k){

//     vector<int> output;
//     if(arr.size() < k) return output;

//     for(int i=0; i<arr.size()-k+1; i++){

//         int maxElement = INT_MIN;

//         for(int j=i; j<i+k; j++){

//             if(arr[j] > maxElement){

//                 maxElement = arr[j];
//             }
//         }

//         output.push_back(maxElement);
//     }

//     return output;
// }

// Method 2 : Using Deque
// Time Complexity : O(n)  Space Complexity : O(k)
// vector<int> maximumOfWindow(vector<int> &arr, int k){

//     vector<int> output;
//     if(arr.size() < k) return output;

//     deque <int> dq;

//     // Add first k elements in Deque
//     for(int i=0; i<k; i++){

//         // Remove element
//         // If greater element comes then remove rest [Equal Included]
//         while(!dq.empty() && arr[dq.back()] <= arr[i]){

//             dq.pop_back();
//         }

//         // Insert Element
//         dq.push_back(i);
//     }

//     output.push_back(arr[dq.front()]);

//     // Rest k-n elements
//     for(int i=k; i<arr.size(); i++){

//         // Remove with index with more than k distance
//         while(!dq.empty() && dq.front() <= i-k){

//             dq.pop_front();
//         }

//         // Remove element
//         // If greater element comes then remove rest [Equal Included]
//         while(!dq.empty() && arr[dq.back()] <= arr[i]){

//             dq.pop_back();
//         }

//         // Insert Element
//         dq.push_back(i);

//         output.push_back(arr[dq.front()]);
//     }

//     return output;
// }

// Method 3 : Using Max Heaps
// Time Complexity : O(n * log(n))  Space Complexity : O(n)
vector<int> maximumOfWindow(vector<int> &arr, int k){

    vector<int> output;
    if(arr.size() < k) return output;

    priority_queue< pair<int, int> > pq;

    // Put first k elements
    for(int i=0; i<k; i++){

        pq.push(make_pair(arr[i], i));
    }

    output.push_back(pq.top().first);

    // Rest k elements
    for(int i=k; i<arr.size(); i++){

        // Remove element
        while(!pq.empty() && pq.top().second <= i-k){

            pq.pop();
        }

        // Insert Element
        pq.push(make_pair(arr[i], i));

        output.push_back(pq.top().first);
    }

    return output;
}

int main()
{
    cout << "Enter size : ";
    int n;
    cin >> n;

    cout << "Enter data : ";
    int data;
    vector<int> arr;

    for(int i=0; i<n; i++){

        cin >> data;
        arr.push_back(data);
    }

    cout << "Enter value of k : ";
    int k;
    cin >> k;

    // Maximum of Subarray [Size k]
    vector<int> output = maximumOfWindow(arr, k);

    cout << "Window Maximum : ";
    for(int i=0; i<output.size(); i++){

        cout << output[i] << " ";
    }

    cout << endl;
    return 0;
}