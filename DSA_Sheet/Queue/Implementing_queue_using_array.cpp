#include <iostream>
using namespace std;

// Insert is Enqueue
// Removing is Dequeue

class Queue {

    public:
        int* arr;
        int size;
        int front;
        int rear;  // Points to empty index in Queue

    Queue(int size){

        arr = new int[size];
        this->size = size;
        front = 0;
        rear = 0;
    }

    void push(int data){

        if(rear == size){

            cout << "Queue is Full !!" << endl;
        }
        else{

            arr[rear] = data;
            rear++;
        }
    }

    void pop(){

        if(rear == front){

            cout << "Queue is Empty !!" << endl;
        }
        else{

            arr[front] = -1;
            front++;

            // If we reach empty list [ Other condition than front = 0 & rear = 0 ]
            if(front == rear){

                front = 0;
                rear = 0;
            }
        }
    }

    bool isEmpty(){

        if(front == rear){

            cout << "Queue is Empty !!" << endl;
            return true;
        }
        else{

            cout << "Queue is not Empty !!" << endl;
            return false;
        }
    }

    int frontElement(){

        if(front == rear){

            return -1;
        }
        else{

            return arr[front];
        }
    }
};

int main()
{
    Queue q(4);

    // Pushing Elements
    q.push(5);
    q.push(10);
    q.push(15);
    // q.push(20);
    // q.push(25);
    cout << "Front Element is : " << q.frontElement() << endl;
    
    // Popping Elements
    q.pop();
    q.pop();
    q.pop();
    cout << "Front Element is : " << q.frontElement() << endl;
    q.isEmpty();

    q.push(5);
    q.push(10);
    q.push(15);
    q.push(5);
    q.push(10);
    cout << "Front Element is : " << q.frontElement() << endl;

    q.pop();
    q.pop();
    cout << "Front Element is : " << q.frontElement() << endl;

    return 0;
}