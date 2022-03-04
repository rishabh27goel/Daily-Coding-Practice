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

// Method 1 : Simple Iteration
Node* reverseList(Node* head){

    if(head->next == NULL) return head;

    Node* track = NULL;
    Node* prev = NULL;

    while(head->next != NULL){

        track = head->next;
        head->next = prev;
        prev = head;
        head = track;
    }

    head->next = prev;

    return head;
}

Node* add_1_To_List(Node* head){

    if(head == NULL) return head;

    // Reverse the Linked List
    head = reverseList(head);
     
    int carry = 1;
    Node* curr = head;

    while(curr != NULL && carry != 0){

        int val = (curr->data + carry) % 10;
        carry = (curr->data + carry) / 10;

        curr->data = val;
        curr = curr->next;
    }

    head = reverseList(head);

    if(carry != 0){

        Node* newNode = new Node(carry);
        newNode->next = head;
        head = newNode;
    }

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

    // Add 1 to Number represented Linked List 
    head = add_1_To_List(head);
    Node* curr = head;

    cout <<"New List : ";
    while(curr != NULL){

        cout <<curr->data <<" ";
        curr = curr->next;
    }


    return 0;
}