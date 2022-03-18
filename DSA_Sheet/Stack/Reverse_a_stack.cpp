#include <iostream>
#include <stack>
using namespace std;

// Method 1 : Using extra space
// Time Complexity : O(n)  Space Complexity : [O(n) + Recursion Stack O(n)]
// void reverseStack(stack<int> &input, stack<int> &output){

//     if(input.empty()) return;

//     int data = input.top();
//     input.pop();

//     output.push(data);
//     reverseStack(input, output);
//     input.push(data);
// }

// Method 2 : 
// Time Complexity : O(n^2)  Space Complexity : O(n)
void insertAtBottom(stack<int> &insert, int data){

    if(insert.empty()){

        insert.push(data);
        return;
    }

    int value = insert.top();
    insert.pop();

    insertAtBottom(insert, data);
    insert.push(value);
}

void reverseStack(stack<int> &input){

    if(input.empty()) return;

    int data = input.top();
    input.pop();

    reverseStack(input);

    insertAtBottom(input, data);
}

void printStack(stack<int> output){

    if(output.empty()) return;

    int data = output.top();
    output.pop();

    cout << data << " ";
    printStack(output); 
    output.push(data);
}

int main()
{   
    int n;
    cout << "Enter number of inputs : ";
    cin >> n;

    cout << "Enter Inputs : ";
    stack<int> input;
    stack<int> output;

    int data;
    for(int i=0; i<n; i++){

        cin >> data;
        input.push(data);
    }

    cout << "\nInput Stack : ";
    printStack(input);

    // Method 1 :
    // reverseStack(input, output);
    // cout << "\nOutput Stack : ";
    // printStack(output);

    // Method 2 : 
    reverseStack(input);
    cout << "\nModified Stack : ";
    printStack(input);

    cout << endl;
    return 0;
}