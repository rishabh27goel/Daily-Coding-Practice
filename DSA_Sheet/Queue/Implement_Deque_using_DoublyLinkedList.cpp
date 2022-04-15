#include <iostream>
using namespace std;

class Node {

    public:
        int data;
        Node* prev;
        Node* next;

    Node(int data){

        this->data = data;
        this->prev = NULL;
        this->next = NULL;
    }
};

class Deque {

    public:
        int size;
        Node* front;
        Node* rear;

    Deque(){

        this->size = 0;
        this->front = NULL;
        this->rear = NULL;
    }

    void pushFront(int data){

        Node* newNode = new Node(data);

        if(front == NULL && rear == NULL){

            front = newNode;
            rear = newNode;
        }
        else{

            newNode->next = front;
            front->prev = newNode;
            front = newNode;
        }

        size++;
    }

    void pushBack(int data){

        Node* newNode = new Node(data);

        if(front == NULL && rear == NULL){

            front = newNode;
            rear = newNode;
        }
        else{

            rear->next = newNode;
            newNode->prev = rear;
            rear = newNode;
        }

        size++;
    }

    void popFront(){

        if(front == NULL && rear == NULL){

            cout << "Queue is Empty !" << endl;
        }
        else{

            cout << "Deleted : " << front->data << endl;

            Node* store = front;
            front = front->next;

            if(front == NULL){

                rear = NULL;
            }
            else{

                front->prev = NULL;
            }            

            delete store;
            size--;
        }
    }

    void popBack(){

        if(front == NULL && rear == NULL){

            cout << "Queue is Empty !" << endl;
        }
        else{

            cout << "Deleted : " << rear->data << endl;
                     
            Node* store = rear;
            rear = rear->prev;

            if(rear == NULL){

                front = NULL;
            }
            else{

                rear->next = NULL;
            }

            delete store;
            size--;
        }
    }

    void getFront(){

        if(front == NULL && rear == NULL){

            cout << "Queue is Empty !" << endl;
        }
        else{

            cout << "Front Element is : " << front->data << endl;
        } 
    }

    void getRear(){

        if(front == NULL && rear == NULL){

            cout << "Queue is Empty !" << endl;
        }
        else{

            cout << "Last Element is : " << rear->data << endl;
        } 
    }

    void isEmpty(){

        if(front == NULL && rear == NULL){

            cout << "Queue is Empty !" << endl;
        }
        else{

            cout << "Queue is not Empty !" << endl;
        }
    }

    void getSize(){

        cout << "Size is : " << size << endl;
    }
};

int main()
{
    Deque dq;

    dq.pushBack(5);
    dq.pushFront(10);
    dq.pushFront(15);
    dq.pushBack(20);
    dq.getSize();

    dq.getFront();
    dq.getRear();
    dq.isEmpty();

    dq.popFront();
    dq.getFront();
    dq.getRear();
    dq.getSize();

    dq.popBack();
    dq.getFront();
    dq.getRear();
    dq.popBack();
    dq.getSize();

    dq.getFront();
    dq.getRear();
    dq.popFront();

    dq.getSize();
    dq.isEmpty();

    return 0;
}