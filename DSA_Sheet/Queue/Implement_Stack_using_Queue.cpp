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

class Queue {

    public:
        int size;
        Node* rear;
        Node* front;

    Queue(){

        this->size = 0;
        this->front = NULL;
        this->rear = NULL;
    }

    void enqueue(int data){

        Node* newNode = new Node(data);

        if(front == NULL && rear == NULL){

            front = newNode;
            rear = newNode;
        }
        else{

            rear->next = newNode;
            rear = newNode;
        }

        size++;
    }

    void dequeue(){

        if(front == NULL && rear == NULL){

            return;
        }
        else{

            front = front->next;

            if(front == NULL){

                rear = NULL;
            }

            size--;
        }

    }

    int frontElement(){

        if(front == NULL && rear == NULL){

            return -1;
        }
        else{

            return front->data;
        }
    }

    bool empty(){

        if(front == NULL && rear == NULL){

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


// Pushing is Costly

// Time Complexity : 
// Push : O(n)
// Pop : O(1)
// Top : O(1)

// Space Complexity : O(n)

class Stack {

    public:
        Queue q1;
        Queue q2;

    void push(int value){

        // Try to push new value at the bottom
        while(!q1.empty()){

            q2.enqueue(q1.frontElement());
            q1.dequeue();
        }

        // Push new value
        q1.enqueue(value);

        // Push back to Queue 1
        while(!q2.empty()){

            q1.enqueue(q2.frontElement());
            q2.dequeue();
        }
    }

    void pop(){

        if(q1.empty()){

            cout << "Stack is Empty !" << endl;
        }
        else{

            cout << "Deleted : " << q1.frontElement() << endl;
            q1.dequeue();
        }
    }

    void top(){

        if(q1.empty()){

            cout << "Stack is Empty !" << endl;
        }
        else{

            cout << "Top Element is : " << q1.frontElement() << endl;
        }
    }

    void isEmpty(){

        if(q1.empty()){

            cout << "Stack is Empty !";
        }
        else{

            cout << "Stack is not Empty !";
        }
    }

    int size(){

        return q1.getSize();
    }
};


// Popping is Costly

// Time Complexity : 
// Push : O(1)
// Pop : O(n)
// Top : O(n)

// Space Complexity : O(n)

// class Stack {

//     public:
//         Queue q1;
//         Queue q2;

//     void push(int value){

//         q1.enqueue(value);
//     }

//     void pop(){

//         if(q1.empty()){

//             cout << "Stack is Empty !" << endl;
//         }
//         else{

//             while(q1.getSize() != 1){

//                 q2.enqueue(q1.frontElement());
//                 q1.dequeue();
//             }

//             cout << "Deleted : " << q1.frontElement() << endl;
//             q1.dequeue();

//             while(!q2.empty()){

//                 q1.enqueue(q2.frontElement());
//                 q2.dequeue();
//             }
//         }
//     }

//     void top(){

//         if(q1.empty()){

//             cout << "Stack is Empty !" << endl;
//         }
//         else{

//             while(q1.getSize() != 1){

//                 q2.enqueue(q1.frontElement());
//                 q1.dequeue();
//             }

//             cout << "Top Element is : " << q1.frontElement() << endl;
//             q2.enqueue(q1.frontElement());
//             q1.dequeue();

//             while(!q2.empty()){

//                 q1.enqueue(q2.frontElement());
//                 q2.dequeue();
//             }
//         }
//     }

//     void isEmpty(){

//         if(q1.empty()){

//             cout << "Stack is Empty !";
//         }
//         else{

//             cout << "Stack is not Empty !";
//         }
//     }

//     int size(){

//         return q1.getSize();
//     }
// };


int main()
{
    Stack s;

    s.push(5);
    s.push(10);
    s.push(15);
    s.push(20);

    s.top();
    s.pop();

    s.top();
    s.pop();

    s.top();
    s.pop();
    
    s.top();
    s.pop();
    s.pop();

    return 0;
}