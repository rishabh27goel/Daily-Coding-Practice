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

// Method 1 : Move to last nodes
// Time Complexity : O(n)   Space Complexity : O(1)
// Node* moveHeadToLast(Node* start, Node* &last){

//     last->next = start;
//     start = start->next;
//     start->prev = NULL;

//     last->next->next = NULL;
//     last->next->prev = last;
//     last = last->next;

//     return start;
// }

// Node* rotateDoublyLinkedList(Node* start, int p){

//     if(p == 0 || start == NULL || start->next == NULL) return start;

//     // Move to last node
//     Node* last = start;

//     while(last->next != NULL){

//         last = last->next;
//     }

//     // Move head to last and update head
//     int count = p;

//     while(count--){

//         start = moveHeadToLast(start, last);
//     }

//     return start;
// }

// Method 2 : Using Circular Method
// Time Complexity : O(n)   Space Complexity : O(1)
Node* rotateDoublyLinkedList(Node* start, int p){

    if(p == 0 || start == NULL || start->next == NULL) return start;

    // Move to last node
    Node* last = start;
    while(last->next != NULL){

        last = last->next;
    }

    // Make it a circular list
    last->next = start;

    // Now move head to P Nodes
    int count = p;

    while(count--){

        start = start->next;
    }

    // Move to last node
    last = start;
    while(last->next != start){

        last = last->next;
    }

    last->next = NULL;

    return start;
}

int main()
{
    Node* listStart = NULL;
    Node* listTail = NULL;

    int data = 0;
    cout << "Enter Linked List Data : ";

    while(data != -1){

        cin >> data;

        if(data == -1) break;

        listStart = insertNode(listStart, listTail, data);
    }

    int p;
    cout << "Enter value of P : ";
    cin >> p;

    // Rotate Doubly Linked List
    listStart = rotateDoublyLinkedList(listStart, p);

    Node* curr = listStart;

    cout << "\nUpdated List is : ";
    while(curr != NULL){

        cout << curr->data << " ";
        curr = curr->next;
    }

    cout << endl;
    return 0;
}