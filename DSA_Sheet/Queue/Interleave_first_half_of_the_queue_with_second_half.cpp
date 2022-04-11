#include <iostream>
#include <stack>
#include <queue>
using namespace std;

// Method 1 : Using Queue
// Time Complexity : O(n)    Space Complexity : O(n)
// void interleaveFirstWithSecond(queue<int> &q){

//     queue<int> store;
//     int n = q.size() / 2;

//     // Store first n/2 elements in New Queue
//     while(n--){

//         int val = q.front();
//         q.pop();

//         store.push(val);
//     }

//     // Now take one element from each queue
//     while(!store.empty()){

//         int val1 = store.front();
//         store.pop();

//         int val2 = q.front();
//         q.pop();

//         q.push(val1);
//         q.push(val2);
//     }
// }

// Method 2 : Using Stack
// Time Complexity : O(n)    Space Complexity : O(n)
void interleaveFirstWithSecond(queue<int> &q){

    stack<int> st;
    int n = q.size() / 2;

    // Store first n/2 elements into Stack
    while(n--){

        int val = q.front();
        q.pop();

        st.push(val);
    }

    // Push them in Queue again
    while(!st.empty()){

        int val = st.top();
        st.pop();

        q.push(val);
    }

    // Move first n/2 to back of Queue
    n = q.size() / 2;

    while(n--){

        int val = q.front();
        q.pop();

        q.push(val);
    }

    // Store first n/2 again in Stack
    n = q.size() / 2;

    while(n--){

        int val = q.front();
        q.pop();

        st.push(val);
    }

    // Now take one element each from queue & stack
    while(!st.empty()){

        int val1 = st.top();
        st.pop();

        int val2 = q.front();
        q.pop();

        q.push(val1);
        q.push(val2);
    } 
}

void printQueue(queue<int> q){

    if(q.empty()) return;

    int data = q.front();
    q.pop();

    cout << data << " ";

    printQueue(q);
}

int main()
{
    int n;
    cout << "Enter number of elements [Even]: ";
    cin >> n;

    queue<int> input;
    int data;
    
    cout << "Enter elements : ";
    for(int i=0; i<n; i++){

        cin >> data;
        input.push(data);
    }

    interleaveFirstWithSecond(input);

    cout << "Modified Queue : ";
    printQueue(input);

    cout << endl;
    return 0;
}