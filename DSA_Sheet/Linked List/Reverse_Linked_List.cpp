#include <iostream>
using namespace std;

class Node {

    public:
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

// Method 1 : Using Iterative Method
// Time Complexity : O(n)  Space Complexity : Stack Space O(1)
Node* iterativeReverseLinkedList(Node* head){

    Node *prev = NULL;
    Node *track = NULL;

    while(head->next != NULL){

        track = head->next;
        head->next = prev;
        prev = head;
        head = track;
    }

    head->next = prev;

    return head;
}

// Method 2 : Using Recursion Method
// Time Complexity : O(n)  Space Complexity : Stack Space O(n)
Node* recursiveReverseLinkedList(Node* head){

    if(head == NULL || head->next == NULL)
        return head;

    Node* rest = recursiveReverseLinkedList(head->next);
    head->next->next = head;

    // End Element
    head->next = NULL;
    return rest;
}

int main()
{
    Node *head = NULL;

    cout <<"Enter Linked List Data : ";
    int data = 0;
    while(data != -1){

        cin >> data;

        if(data == -1)
            break;

        insertingNodeAtHead(head, data);
    }

    Node *curr = head;

    cout <<"Linked List is : ";
    while(curr != NULL){

        cout <<curr->data <<" ";
        curr = curr -> next;
    }

    // curr = head;

    // cout<<"\nIterative Reverse Linked List : ";
    // curr = iterativeReverseLinkedList(curr);

    // while(curr != NULL){

    //     cout <<curr->data <<" ";
    //     curr = curr -> next;
    // }

    curr = head;

    cout<<"\nRecursive Reverse Linked List : ";
    curr = recursiveReverseLinkedList(curr);

    while(curr != NULL){

        cout <<curr->data <<" ";
        curr = curr->next;
    }

    cout <<endl;
    return 0;
}