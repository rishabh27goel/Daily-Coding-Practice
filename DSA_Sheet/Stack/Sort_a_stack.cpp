#include <iostream>
#include <stack>
using namespace std;

void printStack(stack<int> input){

    if(input.empty()) return;

    int data = input.top();
    input.pop();

    printStack(input);

    cout << data << " ";
}

// Time Complexity : O(n^2)  Space Complexity : O(n)
void insertInSortedOrder(stack<int> &input, int value){

    if(input.empty()){

        input.push(value);
        return;
    }

    int data = input.top();

    if(data < value){

        input.push(value);
        return;
    }
    else{

        input.pop();
        insertInSortedOrder(input, value);
        input.push(data);
    }
    
}

void sortStack(stack<int> &input){

    if(input.empty()) return;

    int data = input.top();
    input.pop();

    // Track all elements
    sortStack(input);

    insertInSortedOrder(input, data);
}

int main()
{   
    int n;
    cout << "Enter number of inputs : ";
    cin >> n;

    cout << "Enter Inputs : ";
    stack<int> st;
    int data;

    for(int i=0; i<n; i++){

        cin >> data;
        st.push(data);
    }

    sortStack(st);

    cout << "Sorted Stack : ";
    printStack(st);

    cout << endl;
    return 0;
}