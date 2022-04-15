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

            cout << "Satck is Empty !" << endl;
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

            cout << "Stack is Empty !" << endl;
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

            cout << "Stack is Empty !" << endl;
        }
        else{

            cout << "Front Element is : " << front->data << endl;
        } 
    }

    void getRear(){

        if(front == NULL && rear == NULL){

            cout << "Stack is Empty !" << endl;
        }
        else{

            cout << "Last Element is : " << rear->data << endl;
        } 
    }

    void isEmpty(){

        if(front == NULL && rear == NULL){

            cout << "Stack is Empty !" << endl;
        }
        else{

            cout << "Stack is not Empty !" << endl;
        }
    }

    void getSize(){

        cout << "Size is : " << size << endl;
    }
};

class Stack : public Deque {

    public:

    void push(int data){

        pushFront(data);
    }

    void pop(){

        popFront();
    }

    void peek(){

        getFront();
    }
};

int main()
{
    Stack s;

    s.push(5);
    s.push(10);
    s.push(15);
    s.push(20);
    s.peek();

    s.getSize();
    s.pop();
    s.peek();
    s.pop();
    s.pop();

    s.getSize();
    s.peek();
    s.isEmpty();

    return 0;
}