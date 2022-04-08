#include <iostream>
#include <vector>
#include <deque>
using namespace std;

// Method 1 : Brute Force 
// Time Complexity : O(n * k)   Space Complexity : O(1)
// vector<int> firstNegativeInteger(vector<int> arr, int k){

//     if(arr.size() == 0 || k == 0) return arr;

//     vector<int> output;

//     // Sliding Window
//     for(int i=0; i<arr.size()-k+1; i++){

//         int val = 0;

//         for(int j=i; j<i+k; j++){

//             if(val == 0 && val > arr[j]){

//                 val = arr[j];
//             }
//         }

//         output.push_back(val);
//     }

//     return output;
// }

// Method 2 : Using Deque
// Time Complexity : O(n)   Space Complexity : O(k)
// vector<int> firstNegativeInteger(vector<int> arr, int k){

//     if(arr.size() == 0 || k == 0) return arr;

//     vector<int> output;
//     deque<int> dq;

//     // First Window Push
//     for(int i=0; i<k; i++){

//         if(arr[i] < 0){

//             dq.push_back(i);
//         }
//     }

//     if(dq.size() != 0){

//         output.push_back(arr[dq.front()]);
//     }
//     else{

//         output.push_back(0);
//     }
    

//     // Iterate Rest of the Windows add and remove one element
//     for(int i=k; i<arr.size(); i++){

//         // Add Element
//         if(arr[i] < 0){

//             dq.push_back(i);
//         }

//         // Remove Element
//         if(!dq.empty() && dq.front() <= i-k){

//             dq.pop_front();
//         }

//         if(dq.size() != 0){

//             output.push_back(arr[dq.front()]);
//         }
//         else{

//             output.push_back(0);
//         }
//     }

//     return output;
// }

// Method 3 : Single Iteration
// Time Complexity : O(n)   Space Complexity : O(1)
vector<int> firstNegativeInteger(vector<int> arr, int k){

    if(arr.size() == 0 || k == 0) return arr;

    vector<int> output;

    int firstIndex = 0;

    for(int i=k-1; i<arr.size(); i++){

        while(firstIndex < i && (firstIndex <= i-k || arr[firstIndex] > 0)){

            firstIndex++;
        }

        if(arr[firstIndex] < 0){

            output.push_back(arr[firstIndex]);
        }
        else{

            output.push_back(0);
        }
    }

    return output;
}

int main()
{
    int n;
    cout << "Enter number of elements : ";
    cin >> n;

    vector<int> arr;
    cout << "Enter elements : ";
    int data;

    for(int i=0; i<n; i++){

        cin >> data;
        arr.push_back(data);
    }

    int k;
    cout << "Enter value of K : ";
    cin >> k;

    vector<int> output = firstNegativeInteger(arr, k);

    cout << "Output Array : ";
    for(int i=0; i<output.size(); i++){

        cout << output[i] << " ";
    }

    cout << endl;
    return 0;
}