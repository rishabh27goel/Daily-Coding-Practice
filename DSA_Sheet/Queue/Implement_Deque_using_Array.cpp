#include <iostream>
using namespace std;

class Deque {

    public:
        int *arr;
        int front;
        int size;
        int rear;

    Deque(int size){

        arr = new int[size];
        this->size = size;
        this->front = -1;
        this->rear = -1;
    }

    void pushFront(int data){

        if((front == 0 && rear == size-1) || (rear < front && rear == front-1)){

            cout << "Queue is Full !" << endl;
        }
        else if(front == -1){

            front = 0;
            rear = 0;
        }
        else{

            if(front == 0){

                front = size-1;
            }
            else{

                front--;
            }
        }

        arr[front] = data; 
    }

    void pushBack(int data){

        if((front == 0 && rear == size-1) || (rear < front && rear == front-1)){

            cout << "Queue is Full !" << endl;
        }
        else if(front == -1){

            front = 0;
            rear = 0;
        }
        else{

            rear = (rear + 1) % size;
        }

        arr[rear] = data;
    }

    void popFront(){

        if(front == -1 && rear == -1){

            cout << "Queue is Empty !" << endl;
        }
        else{

            cout << "Deleted : " << arr[front] << endl;

            if(front == rear){

                front = -1;
                rear = -1;
                return;
            }
            else{

                front = (front + 1) % size;
            }
        }
    }

    void popBack(){

        if(front == -1 && rear == -1){

            cout << "Queue is Empty !" << endl;
        }
        else{
            
            cout << "Deleted : " << arr[rear] << endl;

            if(rear == front){

                front = -1;
                rear = -1;
            }
            else if(rear == 0){

                rear = size-1;
            }
            else{

                rear--;
            }
        }
    }

    void getFront(){

        if(front == -1 && rear == -1){

            cout << "Queue is Empty !" << endl;
        }
        else{

            cout << "Front element is : " << arr[front] << endl;
        }
    }

    void getRear(){

        if(front == -1 && rear == -1){

            cout << "Queue is Empty !" << endl;
        }
        else{

            cout << "Last element is : " << arr[rear] << endl;
        }
    }

    void isFull(){

        if((front == 0 && rear == size-1) || (rear < front && rear == front-1)){

            cout << "Queue is Full !" << endl;
        }
        else{

            cout << "Queue is not Full !" << endl;
        }
    }

    void isEmpty(){

        if(front == -1 && rear == -1){

            cout << "Queue is Empty !" << endl;
        }
        else{

            cout << "Queue is not Empty !" << endl;
        }
    }
};

int main()
{
    Deque dq(4);

    dq.pushBack(5);
    dq.pushFront(10);
    dq.pushFront(15);
    dq.pushBack(20);

    dq.getFront();
    dq.getRear();

    dq.isFull();
    dq.isEmpty();

    dq.popFront();
    dq.getFront();
    dq.getRear();

    dq.popBack();
    dq.getFront();
    dq.getRear();
    dq.popBack();

    dq.getFront();
    dq.getRear();
    dq.popFront();

    dq.isEmpty();

    cout << endl;
    return 0;
}