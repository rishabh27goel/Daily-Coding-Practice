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
        Node* front;
        Node* rear;
        int size;

    Queue(){

        this->front = NULL;
        this->rear = NULL;
        this->size = 0;
    }

    void push(int data){

        Node* newNode = new Node(data);

        if(front == NULL && rear == NULL){

            front = newNode;
            rear = newNode;
        }
        else{

            rear->next = newNode;
            rear = rear->next;
        }

        size++;
    }

    void pop(){

        if(rear == NULL && front == NULL){

            cout << "Queue is Empty !!";
        }
        else{

            Node* store = front;
            front = front->next;
            
            if(size == 1){

                rear = NULL;
            }
            
            delete store;
            size--;
        }
    }

    bool isEmpty(){

        if(front == NULL && rear == NULL){

            cout << "Queue is Empty !!" << endl;
            return true;
        }
        else{

            cout << "Queue is not Empty !!" << endl;
            return false;
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
};

int main()
{
    Queue q;

    // Pushing Elements
    q.push(5);
    // q.push(10);
    // q.push(15);
    cout << "Front Element is : " << q.frontElement() << endl;
    
    // Popping Elements
    q.pop();
    // q.pop();
    // q.pop();
    cout << "Front Element is : " << q.frontElement() << endl;
    q.isEmpty();

    return 0;
}