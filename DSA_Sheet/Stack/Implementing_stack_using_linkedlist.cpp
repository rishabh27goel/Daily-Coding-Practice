#include <iostream>
using namespace std;

class Node {

    public:
        int data;
        Node* next;

    Node(int data){

        this->data = data;
        this->next = NULL;
    }
};

// Implementing Stack Class
class Stack {

    public:
        int count;
        Node* top;

    Stack(){

        this->count = 0;
        this->top = NULL;
    }

    void push(int data){

        Node* newNode = new Node(data);

        if(top == NULL){

            top = newNode;
        }
        else{

            newNode->next = top;
        }

        top = newNode;
        count++;
    }

    void pop(){

        if(top == NULL){

            cout << "Stack Underflow !!" << endl;
        }
        else{

            Node* store = top;
            top = top->next;

            count--;
            delete store;
        }
    }

    int peek(){

        if(top == NULL){

            cout << "Stack is Empty !!" << endl;
            return -1;
        }
        else{

            return top->data;
        }
    }

    bool isEmpty(){

        if(top == NULL){

            return true;
        }
        else{

            return false;
        }   
    }

    int size(){

        return count;
    }
};

int main()
{
    Stack s1;

    // Push Operation
    s1.push(10);
    // s1.push(20);
    // s1.push(30);

    // Pop Operation
    s1.pop();
    s1.pop();

    // Peek Operation
    if(s1.peek() != -1){

        cout << "Top Element is : " << s1.peek() << endl;
    }

    s1.push(10);
    s1.push(20);
    s1.push(30);
    
    // Stack Empty
    if(s1.isEmpty()){

        cout << "Stack is Empty !!" << endl;
    }
    else{

        cout << "Stack is not Empty !!" << endl;
    }

    // Stack Size
    cout << "Size of Stack is : " << s1.size() << endl;

    cout << endl;
    return 0;
}