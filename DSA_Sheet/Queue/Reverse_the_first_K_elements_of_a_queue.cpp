#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;

// Method 1 : Storing in Array
// Time complexity : O(n + k)  Space Complexity : O(n)
// void reverseFirstK(queue<int> &input, int k){

//     if(input.size() <= 1 || k <= 1) return;

//     vector<int> store;

//     // Store in the Vector
//     while(!input.empty()){

//         int val = input.front();
//         input.pop();

//         store.push_back(val);
//     }

//     // Reverse First K
//     int i = 0;
//     int j = k-1;

//     while(i < j){

//         swap(store[i], store[j]);
//         i++;
//         j--;
//     }

//     // Push in the Queue again
//     for(int i=0; i<store.size(); i++){

//         input.push(store[i]);
//     }
// }

// Method 2 : Storing in Stack
// Time complexity : O(n + k)  Space Complexity : O(k)
void reverseFirstK(queue<int> &input, int k){

    if(input.size() <= 1 || k <= 1) return;

    int n = input.size();
    int t = k;
    stack<int> st;

    // Store first k in stack
    while(t--){

        int val = input.front();
        input.pop();

        st.push(val);
    }

    // Add the reversed elements back to queue
    while(!st.empty()){

        int val = st.top();
        st.pop();

        input.push(val);
    }

    // Move first n-k elements from queue start to end
    t = n - k;
    while(t--){

        int val = input.front();
        input.pop();

        input.push(val);
    }
}

void printQueue(queue<int> input){

    if(input.empty()) return;

    int val = input.front();
    input.pop();

    cout << val << " ";
    printQueue(input);
}

int main()
{
    int n;
    cout << "Enter number of elements : ";
    cin >> n;

    queue<int> input;
    int data;

    cout << "Enter elements : ";
    for(int i=0; i<n; i++){

        cin >> data;
        input.push(data);
    }

    int k;
    cout << "Enter value of K : ";
    cin >> k;

    reverseFirstK(input, k);
    
    cout << "Modified Queue : ";
    printQueue(input);


    cout << endl;
    return 0;
}