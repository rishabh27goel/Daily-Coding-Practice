#include <iostream>
#include <vector>
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

// Method 1 : Getting the middle using extra space
// Time Complexity : O(n)  Space Complexity : O(n)
// Node* getMiddle(Node* head){

//     if(head == NULL || head->next == NULL) return head; 

//     Node* curr = head;

//     // Storing the nodes of the List
//     vector <Node*> store;

//     while(curr != NULL){

//         store.push_back(curr);
//         curr = curr->next;
//     }
    
//     // Get the middle
//     int mid = (int)(store.size() / 2);

//     return store[mid];
// }

// Method 2 : Slow Pointer and Fast Pointer Method
// Time Complexity : O(n)  Space Complexity : O(1)
Node* getMiddle(Node* head){

    if(head == NULL || head->next == NULL) return head;

    // Slow and Fast Pointer
    Node* slow = head;
    Node* fast = head;

    while(fast != NULL && fast->next != NULL){

        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

int main()
{
    Node* head = NULL;

    cout<<"Enter Linked List Data : ";
    int data = 0;

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

    // Getting the middle
    Node* middle = getMiddle(head);
    cout <<"\nMiddle Node : " <<middle->data;

    cout <<endl;
    return 0;
}