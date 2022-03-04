#include <iostream>
#include <map>
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

// Method 1 : Iterative Method
// Time Complexity : O(n)   Space Complexity : O(1)
// Node* removeDuplicateElement(Node* head){

//     if(head == NULL || head->next == NULL) return head;

//     Node* curr = head;
//     Node* track = NULL;

//     while(curr->next != NULL){

//         if(curr->data == curr->next->data){

//             track = curr->next;
//             curr->next = curr->next->next;

//             delete track;
//             continue;
//         }

//         curr = curr->next;
//     }

//     return head;
// }

// Method 2 : Recursive Method
// Time Complexity : O(n)   Space Complexity : O(1)
// void removeDuplicateElement(Node* head){

//     if(head == NULL || head->next == NULL) return;

//     if(head->data == head->next->data){

//         Node* remove = head->next;
//         head->next = head->next->next;

//         delete remove;
//         removeDuplicateElement(head);
//     }
//     else{

//         removeDuplicateElement(head->next);
//     }
// }

// Method 3 : Using Map
// Time Complexity : O(n)   Space Complexity : O(n)
void removeDuplicateElement(Node* head){

    if(head == NULL || head->next == NULL) return;

    Node* curr = head;
    map <int, bool> visited;

    cout<<"\nNew List : ";
    while(curr != NULL){

        if(visited.find(curr->data) == visited.end()){

            visited[curr->data] = true;
            cout <<curr->data <<" ";
        }

        curr = curr->next;
    }
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

    cout<<"Linked List : ";
    while(curr != NULL){

        cout <<curr->data <<" ";
        curr = curr->next;
    }

    // Remove Duplicate Element
    
    // head = removeDuplicateElement(head);
    removeDuplicateElement(head);
    // curr = head;

    // cout<<"\nNew Linked List : ";
    // while(curr != NULL){

    //     cout <<curr->data <<" ";
    //     curr = curr->next;
    // }
    
    cout <<endl;
    return 0;
}