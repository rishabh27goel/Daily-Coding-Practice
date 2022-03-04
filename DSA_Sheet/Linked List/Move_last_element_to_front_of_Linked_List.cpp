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

Node* insertAtHead(Node* head, int data){

    Node* newNode = new Node(data);

    if(head == NULL){

        head = newNode;
    }
    else{

        newNode->next = head;
        head = newNode;
    }

    return head;
}

Node* moveLastElementToFront(Node* head){

    if(head == NULL || head->next == NULL) return head;

    Node* curr = head;
    Node* prev = NULL;

    // Move to last element
    while(curr->next != NULL){

        prev = curr;
        curr = curr->next;
    }

    // Move the last to front
    prev->next = NULL;
    curr->next = head;
    head = curr;

    return head;
}

int main()
{
    Node* head = NULL;

    int data = 0;
    cout <<"Enter Linked List Data : ";

    while(data != -1){

        cin >> data;

        if(data == -1) break;
    
        head = insertAtHead(head, data);
    }

    Node* curr = head;
    cout <<"\nLinked List is : ";
    while(curr != NULL){

        cout <<curr->data <<" ";
        curr = curr->next;
    }

    // Move Last Element
    head = moveLastElementToFront(head);
    curr = head;

    cout <<"\nUpdated List is : ";
    while(curr != NULL){

        cout <<curr->data <<" ";
        curr = curr->next;
    }

    cout <<endl;
    return 0;
}