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

class Stack {

    public:
        Node* top;
        Node* middle;
        int size;

    Stack(){

        this->top = NULL;
        this->middle = NULL;
        this->size = 0;
    }

    void push(int data){

        Node* newNode = new Node(data);

        if(top == NULL){

            top = newNode;
        }
        else{

            newNode->next = top;
            top->prev = newNode;
            top = newNode;
        }

        size++;

        if(size % 2 == 1){

            if(middle == NULL)
                middle = top;
            else    
                middle = middle->prev;
        }
    }

    void pop(){

        if(top == NULL){

            cout << "Stack Underflow !!" << endl;
        }
        else{

            Node* track = top;
            top = top->next;
            
            if(top != NULL){

                top->prev = NULL;
            }

            delete track;
            size--;

            if(size % 2 == 0){

                middle = middle->next;
            }
        }
    }

    int peek(){

        if(top == NULL){

            return -1;
        }
        else{

            return top->data;
        }
    }

    int findMiddle(){

        if(middle == NULL){

            return -1;
        }
        else{

            return middle->data;
        }
    }

    void deleteMiddle(){

        if(size == 0){

            cout << "Stack Empty !! " << endl;
            return;
        }

        Node* track = middle;
        cout << "Deleting middle element !!" << endl;

        if(size == 1){
            
            middle = NULL;
            top = NULL;
        }
        else if(size == 2){

            middle = middle->prev;
            middle->next = NULL;
        }
        else{

            Node* itr1 = middle->prev;
            Node* itr2 = middle->next;

            itr1->next = itr2;
            itr2->prev = itr1;

            if(size % 2 == 0){

                middle = middle->prev;
            }
            else{

                middle = middle->next;
            }
        }

        size--;
        delete track;
    }
};

int main()
{
    Stack s;

    // Pushing elements
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    // s.push(50);
    // s.push(60);

    if(s.findMiddle() == -1){

        cout << "Stack is Empty !! " << endl;
    }    
    else{
        
        cout << "Middle Element : " << s.findMiddle() << endl;
    }

    // Popping the elements
    // s.pop();
    // s.pop();
    // s.pop();

    // if(s.findMiddle() == -1){

    //     cout << "Stack is Empty !! " << endl;
    // }    
    // else{
        
    //     cout << "Middle Element : " << s.findMiddle() << endl;
    // }

    // Deleting middle
    s.deleteMiddle();
    cout << s.findMiddle() << endl;

    s.deleteMiddle();
    cout << s.findMiddle() << endl;

    s.deleteMiddle();
    cout << s.findMiddle() << endl;

    s.deleteMiddle();

    cout << endl;
    return 0;
}