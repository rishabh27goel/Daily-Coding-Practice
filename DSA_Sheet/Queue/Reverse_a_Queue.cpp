#include <iostream>
#include <queue>
#include <stack>
using namespace std;

// Method 1 : Using Recursion 
// Time Complexity : O(n)  Space Complexity : O(n)
// void reverseQueue(queue<int> &q){

//     if(q.empty())
//         return;

//     int data = q.front();
//     q.pop();

//     reverseQueue(q);
//     q.push(data);
// }

// Method 2 : Using Stack 
// Time Complexity : O(n)  Space Complexity : O(n)
void reverseQueue(queue<int> &q){

    stack<int> st;

    while(!q.empty()){

        st.push(q.front());
        q.pop();
    }

    while(!st.empty()){

        q.push(st.top());
        st.pop();
    }
}

void printQueue(queue<int> q){

    if(q.empty())
        return;

    int front = q.front();
    cout << front << " ";

    q.pop();
    printQueue(q);
}

int main()
{
    int n;
    cout << "Enter number of elements : ";
    cin >> n;
    
    cout << "Enter Queue Elements : ";
    queue<int> q;
    int data;
    for(int i=0; i<n; i++){

        cin >> data;
        q.push(data);
    }

    // Reverse a Queue
    reverseQueue(q);

    cout << "Reversed Queue : ";
    printQueue(q);

    cout << endl;
    return 0;
}