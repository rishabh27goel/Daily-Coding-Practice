#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// Method 1 : Checking rest window
// Time Complexity : O(n^2)  Space Complexity : O(1)
// void nextGreaterElement(vector<int> arr){

//     if(arr.size() == 0) return;

//     for(int i=0; i<arr.size(); i++){

//         int val = -1;

//         for(int j=i+1; j<arr.size(); j++){

//             if(arr[i] < arr[j]){

//                 val = arr[j];
//                 break;
//             }
//         }

//         cout << val << " ";
//     }
// }

// Method 2 : Using Stack and Iterating from right
// Time Complexity : O(n)  Space Complexity : O(n)
void nextGreaterElement(vector<int> arr){

    if(arr.size() == 0) return;

    stack<int> st;
    int data;

    for(int i=arr.size()-1; i>=0; i--){

        while(!st.empty() && st.top() <= arr[i]){

            st.pop();
        }

        if(st.empty()){

            st.push(arr[i]);
            arr[i] = -1;
        }
        else if(arr[i] < st.top()){

            data = st.top();
            st.push(arr[i]);
            arr[i] = data;
        }
    }  

    for(int i=0; i<arr.size(); i++){

        cout << arr[i] << " ";
    }
}

int main()
{
    int n;
    cout << "Enter size of array : ";
    cin >> n;

    vector<int> arr;
    int data;

    cout << "Enter elements : ";
    for(int i=0; i<n; i++){

        cin >> data;
        arr.push_back(data);
    }

    cout << "Next Greater Element : ";
    nextGreaterElement(arr);

    cout << endl;
    return 0;
}