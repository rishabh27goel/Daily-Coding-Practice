#include <iostream>
using namespace std;

class Node {

    public : 
        int data;   
        Node *next;

    Node(int data){

        this -> data = data;
        this -> next = NULL;
    }
};

void insertingNodeAtHead(Node* &head, int data){

    Node *newNode = new Node(data);

    if(head == NULL){

        head = newNode;
    }   
    else{

        newNode->next = head;
        head = newNode;
    }
        
}

int main()
{
    Node *head = NULL;
    int data = 0;

    cout<<"Enter linked list data: ";
    while(data != -1){

        cin >> data;

        if(data == -1)
            break;

        insertingNodeAtHead(head, data);
    }

    cout<<"Linked List is : ";
    while(head != NULL){

        cout <<head->data <<" ";
        head = head->next;
    }

    cout <<endl;
    return 0;
}