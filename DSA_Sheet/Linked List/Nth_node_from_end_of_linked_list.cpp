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

// Method 1 : Reverse Linked List
// Time Complexity : O(n)
// Node* reverseList(Node* list){

//     if(list == NULL || list->next == NULL) return list;

//     Node* track = NULL;
//     Node* prev = NULL;

//     while(list->next != NULL){

//         track = list->next;
//         list->next = prev;
//         prev = list;
//         list = track;
//     }

//     list->next = prev;

//     return list;
// }

// int nthNodeFromLast(Node* list, int n){

//     if(list == NULL) return -1;
//     if(n <= 0) return -1;

//     int count = 0;

//     while(list != NULL){

//         count++;

//         if(count == n) return list->data;

//         list = list->next;
//     }

//     return -1;
// }

// Method 2 : Two Pointer
// Time Complexity : O(n)
// int nthNodeFromLast(Node* list, int n){

//     if(list == NULL) return -1;
//     if(n <= 0) return -1;

//     Node* a = list;
//     Node* b = list;
//     int count = n;

//     while(count--){

//         if(a == NULL) return -1;

//         a = a->next;
//     }

//     while(a != NULL){

//         a = a->next;
//         b = b->next;
//     }

//     return b->data;
// }

// Method 3 : Get size and iterate
// Time Complexity : O(n)
int nthNodeFromLast(Node* list, int n){

    if(list == NULL) return -1;
    if(n <= 0) return -1;

    Node* curr = list;
    int count = 0;

    while(curr != NULL){

        count++;
        curr = curr->next;
    }

    if(count < n) return -1;

    int diff = count - n;
    curr = list;

    while(diff--){

        curr = curr->next;
    }
    
    return curr->data;
}


int main()
{
    Node* head = NULL;
    int data = 0;
    
    cout << "Enter Linked List Data : ";
    while(data != -1){

        cin >> data;

        if(data == -1) break;

        head = insertAtHead(head, data);
    }

    int n;
    cout << "Enter value of N : ";
    cin >> n;

    // Get the nth node from last
    int value = nthNodeFromLast(head, n);

    if(value == -1){

        cout << "N value is not valid !";
    }
    else{

        cout << "Nth Node is : " << value;
    }

    cout << endl;
    return 0;
}