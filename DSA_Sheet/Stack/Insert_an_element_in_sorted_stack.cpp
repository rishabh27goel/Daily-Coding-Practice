#include <iostream>
#include <stack>
using namespace std;

// Time Complexity : O(n)  Space Complexity : O(n)
void insertElementSorted(stack<int> &input, int val){

    if(input.empty()){

        // If val is the last element in sorted stack
        input.push(val);
        return;
    }

    int data = input.top();

    if(data < val){

        input.push(val);
    }
    else{

        input.pop();
        insertElementSorted(input, val);
        input.push(data);
    }
}

void printStack(stack<int> input){

    if(input.empty()) return;

    int data = input.top();
    input.pop();

    printStack(input);

    cout << data << " ";
}

int main()
{
    int n;
    cout << "Enter number of inputs : ";
    cin >> n;

    cout << "Enter Sorted Inputs : ";
    stack<int> st;
    int data;
    for(int i=0; i<n; i++){

        cin >> data;
        st.push(data);
    }

    int val;
    cout << "Enter the value to add : ";
    cin >> val;

    insertElementSorted(st, val);

    cout << "Modified Stack : ";
    printStack(st);

    cout << endl;
    return 0;
} 