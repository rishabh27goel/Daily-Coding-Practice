#include <iostream>
using namespace std;

class CircularQueue {

    public:
        int *arr;
        int front;
        int rear;
        int size;

    CircularQueue(int size){

        arr = new int[size];
        this->front = -1;
        this->rear = -1;
        this->size = size;
    }

    void push(int data){

        if((front == 0 && rear == size-1) || (rear < front && rear == front-1)){

            cout << "Queue is Full !!" << endl;
            return;
        }
        else if (front == -1){

            // First element to push
            front = 0;
        }

        rear = (rear + 1) % size;
        arr[rear] = data;
    }

    void pop(){

        if(front == -1){

            cout << "Queue is Empty !!" << endl;
        }
        else if(rear != -1 && front == rear){

            // One element only present
            front = -1;
            rear = -1;
            return;
        }

        front = (front + 1) % size;
    }

    void frontElement(){

        if(front == -1){

            cout << "Queue is Empty !!" << endl;
        }
        else{

            cout << "Front Element is : " << arr[front] << endl;
        }
    }
};

int main()
{
    CircularQueue cq(4);

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
    cq.push(35);

    cq.pop();
    cq.pop();
    cq.pop();
    cq.pop();
    cq.frontElement();

    cout << endl;
    return 0;
}