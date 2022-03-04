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

Node* insertNode(Node* head, Node* &tail, int data){

    Node* newNode = new Node(data);

    if(head == NULL){

        head = newNode;
    }
    else{

        tail->next = newNode;
        newNode->prev = tail;
    }

    tail = newNode;

    return head;
}

int main()
{
    Node* listHead = NULL;
    Node* listTail = NULL;

    int data = 0;
    cout << "Enter Linked List Data : ";

    while(data != -1){

        cin >> data;

        if(data == -1) break;

        listHead = insertNode(listHead, listTail, data);
    }

    // Reverse Doubly Linked List

    reverseDLLInGroup(listHead);

    return 0;
}