#include <iostream>
#include <stack>
using namespace std;

void deleteMiddle(stack<int> &input, int count, int size){

    if(count == size/2){

        input.pop();
        return;
    }

    int data = input.top();
    input.pop();

    deleteMiddle(input, count + 1, size);
    input.push(data);
}

void printStack(stack<int> &input, int index){

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

    deleteMiddle(input, 0, n);

    cout << "Modified Stack is : ";
    printStack(input, 0);


    cout << endl;
    return 0;
}