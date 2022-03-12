#include <iostream>
using namespace std;

// Implementing Stack Class
class Stack {

    public:
        int *arr;
        int size; 
        int top;    

    Stack(int size){

        this->size = size;
        arr = new int[size];
        top = -1;
    }

    void push(int data){

        if(size - top > 1){

            top++;
            arr[top] = data;
        }
        else{

            cout << "Stack Overflow !!" << endl;
        }
    }

    void pop(){

        if(top < 0){

            cout << "Stack Underflow !!" << endl;
        }
        else{

            top--;
        }
    }

    int peek(){

        if(top == -1){

            cout << "Stack is Empty !!" << endl;
            return -1;
        }
        else{

            return arr[top];
        }
    }

    bool isEmpty(){

        if(top == -1)
            return true;

        else
            return false;
    }
};

int main()
{
    Stack s1(5);

    // Push Operation
    s1.push(10);
    s1.push(20);

    // Overflow
    // s1.push(35);

    // Pop Operation
    s1.pop();
    // s1.pop();

    // Peek Operation
    if(s1.peek() != -1){

        cout << "Top Element is : " << s1.peek() << endl;
    }

    // s1.push(5);
    s1.pop();
    
    // Stack Empty
    if(s1.isEmpty()){

        cout << "Stack is Empty !!";
    }
    else{

        cout << "Stack is not Empty !!";
    }

    cout << endl;
    return 0;
}