#include <iostream>
#include <stack>
using namespace std;

// Time Complexity : O(n)  Space Complexity : O(n)
void insertAtBottom(stack<int> &input, int val){

    if(input.empty()){

        input.push(val);
        return;
    }

    int data = input.top();
    input.pop();

    insertAtBottom(input, val);
    input.push(data);
}

void printStack(stack<int> input, int index){

    if(input.empty()) 
        return;

    int data = input.top();
    input.pop();

    printStack(input, index + 1);

    cout << data << " ";
    input.push(data);
}

int main()
{
    int n;  
    cout << "Enter number of inputs : ";
    cin >> n;

    cout << "Enter Input : ";
    stack<int> input;
    int data;
    for(int i=0; i<n; i++){

        cin >> data;
        input.push(data);
    }   

    int val;
    cout << "Enter value to insert : ";
    cin >> val;

    insertAtBottom(input, val);
    
    cout << "Modified Stack : ";
    printStack(input, 0);

    cout << endl;
    return 0;
}