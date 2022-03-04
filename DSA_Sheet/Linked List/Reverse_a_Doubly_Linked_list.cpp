#include <iostream>
using namespace std;

class Node {

    public:
        int data;
        Node* next;
        Node* prev;

    Node(int data){

        this->data = data;
        this->prev = NULL;
        this->next = NULL;
    }
};

Node* insertNode(Node* head, Node* &prev, int data){

    Node* newNode = new Node(data);

    if(head == NULL){

        head = newNode;
    }
    else{

        prev->next = newNode;
        newNode->prev = prev;
    }

    prev = newNode;

    return head;
}

// Method 1 : Iterative Method
// Time Complexity : O(n)   Space Complexity : O(1)
// Node* reverseDoublyList(Node* head){

//     if(head == NULL || head->next == NULL) return head;

//     Node* track = NULL;

//     while(head->next != NULL){

//         track = head->next;
//         head->next = head->prev;
//         head->prev = track;
//         head = track;
//     }

//     head->next = head->prev;
//     head->prev = NULL;

//     return head;
// }

// Method 2 : Recursive Method 
// Time Complexity : O(n)   Space Complexity : O(1)
Node* reverseDoublyList(Node* head){

    if(head == NULL) return head;

    if(head->next == NULL){

        head->prev = NULL;
        return head;
    }

    // Get Reverse List from recursion
    Node* rest = reverseDoublyList(head->next);

    head->next->next = head;
    head->prev = rest;
    head->next = NULL;

    return rest;
}

int main()
{
    Node* headList = NULL;
    Node* tailList = NULL;
    int data = 0;
    cout << "Enter Doubly Linked List data : ";

    while(data != -1){

        cin >> data;

        if(data == -1) break;

        headList = insertNode(headList, tailList, data);
    }

    // Reverse Doubly Linked List
    headList = reverseDoublyList(headList);

    cout << "\nLinked List After Reversing : ";
    Node* curr = headList;
    while(curr != NULL){

        cout << curr->data <<" ";
        curr = curr->next;
    }

    cout << endl;
    return 0;
}