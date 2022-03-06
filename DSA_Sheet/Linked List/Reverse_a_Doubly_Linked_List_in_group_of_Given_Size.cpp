#include <iostream>
#include <stack>
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

Node* addNode(Node* head, Node* &tail, int data){

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

// Method 1 : Simple Recursion in Groups
// Time Complexity : O(n)  Space Complexity : O(1)
// Node* reverseDLLGroups(Node* head, int k){

//     if(head == NULL || head->next == NULL || k == 0 || k == 1) return head;  

//     // For using recusion
//     head->prev = NULL;

//     cout << head->data;

//     int count = 0;
//     Node* ptr = head;
//     Node* newHead = NULL;
//     Node* track = NULL;
     
//     while(ptr != NULL && count < k){

//         track = ptr->next;
//         ptr->next = ptr->prev;
//         ptr->prev = track;

//         newHead = ptr;
//         ptr = track;
//         count++;
//     }

//     if(ptr != NULL){

//         Node* rest = reverseDLLGroups(ptr, k);
//         head->next = rest;
//         rest->prev = head;
//     }

//     return newHead;
// }

// Method 2 : Using Stack
// Time Complexity : O(n)  Space Complexity : Stack Space O(k)
Node* reverseDLLGroups(Node* head, int k){

    if(head == NULL || head->next == NULL || k == 0 || k == 1) return head;  

    stack <Node*> store;
    Node* curr = head;
    Node* newList = NULL;
    Node* tail = NULL;

    while(curr != NULL){

        int count = 0;

        // Push Nodes to Stack
        while(curr != NULL && count < k){

            store.push(curr);
            curr = curr->next;
            count++;
        }

        // Get Nodes from stack and Reverse
        while(!store.empty()){

            Node* get = store.top();
            store.pop();

            get->prev = NULL;
            get->next = NULL;

            if(newList == NULL){

                newList = get;
            }
            else{

                tail->next = get;
                get->prev = tail;
            }

            tail = get;
        }
    }

    return newList;
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
    
        listHead = addNode(listHead, listTail, data);
    }

    int k;
    cout << "Enter value of size : ";
    cin >> k;

    // Reverse DLL In Groups 
    listHead = reverseDLLGroups(listHead, k);

    cout << "\nUpdated Linked List is : ";
    Node * curr = listHead;
    while(curr != NULL){

        cout << curr->data << " ";
        curr = curr->next;
    }

    return 0;
}