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

class Stack {

    public:
        int size;
        Node* top;

    Stack(){

        this->size = 0;
        this->top = NULL;
    }

    void push(int data){

        Node* newNode = new Node(data);

        if(top == NULL){

            top = newNode;
        }
        else{

            newNode->next = top;
            top = newNode;
        }

        size++;
    }

    void pop(){

        if(top == NULL){

            return;
        }
        else{

            Node* store = top;

            top = top->next;
            delete store;
            size--;
        }
    }

    int topElement(){

        if(top == NULL){

            return -1;
        }
        else{

            return top->data;
        }
    }

    bool empty(){

        if(top == NULL){

            return true;
        }
        else{

            return false;
        }
    }

    int getSize(){

        return size;
    }
};
// Enqueue is Costly

// Time Complexity : 
// Push : O(n)
// Pop : O(1)
// Front : O(1)

// Space Complexity : O(n)

class Queue {

    public:
        Stack s1;
        Stack s2;

    void enqueue(int value){

        // Try to push element at bottom of stack 1

        while(!s1.empty()){

            s2.push(s1.topElement());
            s1.pop();
        }

        // Add the value
        s1.push(value);

        // Now push all e;ements back to stack 1
        while(!s2.empty()){

            s1.push(s2.topElement());
            s2.pop();
        }
    }

    void dequeue(){

        if(s1.empty()){

            cout << "Queue is Empty !" << endl;
        }
        else{

            cout << "Deleted : " << s1.topElement() << endl;
            s1.pop();
        }
    }

    void front(){

        if(s1.empty()){

            cout << "Queue is Empty !" << endl;
        }
        else{

            cout << "Front is : " << s1.topElement() << endl;
        }
    }

    void isEmpty(){

        if(s1.empty()){

            cout << "Queue is Empty !" << endl;
        }
        else{

            cout << "Queue is not Empty !" << endl;
        }
    }
};


// Dequeue is Costly

// Time Complexity : 
// Push : O(1)
// Pop : O(n)
// Front : O(n)

// Space Complexity : O(n)
// class Queue {

//     public:
//         Stack s1;
//         Stack s2;

//     void enqueue(int value){

//         s1.push(value);
//     }

//     void dequeue(){

//         if(s1.empty()){

//             cout << "Queue is Empty !" << endl;
//         }
//         else{

//             while(!s1.empty()){

//                 s2.push(s1.topElement());
//                 s1.pop();
//             }

//             cout << "Deleted : " << s2.topElement() << endl;
//             s2.pop();

//             while(!s2.empty()){

//                 s1.push(s2.topElement());
//                 s2.pop();
//             }
//         }
//     }

//     void front(){

//         if(s1.empty()){

//             cout << "Queue is Empty !" << endl;
//         }
//         else{

//             while(!s1.empty()){

//                 s2.push(s1.topElement());
//                 s1.pop();
//             }

//             cout << "Front is : " << s2.topElement() << endl;

//             while(!s2.empty()){

//                 s1.push(s2.topElement());
//                 s2.pop();
//             }
//         }        
//     }

//     void isEmpty(){

//         if(s1.empty()){

//             cout << "Queue is Empty !" << endl;
//         }
//         else{

//             cout << "Queue is not Empty !" << endl;
//         }
//     }
// };

int main()
{
    Queue q;

    q.enqueue(5);
    q.enqueue(15);
    q.enqueue(25);
    q.enqueue(35);

    q.dequeue();
    q.dequeue();
    q.front();

    q.dequeue();
    q.front();

    q.dequeue();
    q.front();

    return 0;
}