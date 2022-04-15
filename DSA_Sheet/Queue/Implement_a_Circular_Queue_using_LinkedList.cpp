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

class CircularQueue {

    public:
        int size;
        Node* front;
        Node* rear;

    CircularQueue(){

        size = 0;
        front = NULL;
        rear = NULL;
    }

    void push(int data){

        Node* newNode = new Node(data);

        // Empty Queue
        if(front == NULL && rear == NULL){

            // Circular List
            front = newNode;
            newNode->next = front;
            rear = newNode;
        }
        else{

            rear->next = newNode;
            newNode->next = front;
            rear = rear->next;
        }

        size++;
    }

    void pop(){

        // If Queue is Empty
        if(front == NULL && rear == NULL){

            cout << "Queue is Empty !! " << endl;
        }
        else{

            Node* store = front;
            cout << "Deleted Node : " << front->data << endl;

            // Handle the circular part
            // Only one node
            if(front->next == front){

                front = NULL;
                rear = NULL;
            }
            else{

                front = front->next;
                rear->next = front;
            }

            delete store;
            size--;
        }
    }

    void frontElement(){

        if(front == NULL && rear == NULL){

            cout << "Queue is Empty !!" << endl;
        }
        else{

            cout << "Front Element is : " << front->data << endl;
        }
    }
};

int main()
{
    CircularQueue cq;

    // Pushing Elements
    cq.push(5);
    cq.push(10);
    cq.push(15);
    cq.push(20);
    cq.push(25);

    cq.frontElement();

    // Popping Elements
    cq.pop();
    cq.pop();
    cq.frontElement();
    
    cq.push(30);
    cq.pop();
    cq.pop();
    cq.pop();
    cq.pop();
    cq.frontElement();

    cq.push(30);
    cq.frontElement();

    cout << endl;
    return 0;
}