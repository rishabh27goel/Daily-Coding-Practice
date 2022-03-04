#include <iostream>
#include <map>
using namespace std;

class Node
{
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

// Method 1 : Using Map 
// Time Complexity : O(n)  Space Complexity : O(n)
bool detectLoopLinkedList(Node* head){

    Node* curr = head;
    map <Node* , bool> visited;

    while(curr != NULL){

        if(visited.find(curr) != visited.end()){

            return true;
        }
        else{

            visited[curr] = true;
        }

        curr = curr->next;
    }
    
    return false;
}

// Method 2 : Using Floyd's Cycle Detection Algorithm 
// Time Complexity : O(n)  Space Complexity : O(1)
// bool detectLoopLinkedList(Node* head){

//     if(head->next == NULL) return false;

//     Node* slow = head;
//     Node* fast = head;

//     while(fast != NULL && fast->next != NULL){

//         slow = slow->next;
//         fast = fast->next->next;

//         if(slow == fast) return true;
//     } 

//     return false;
// }


int main()
{
    Node* head = NULL;
    int data = 0;

    cout<<"Enter Linked List Data : ";
    while(data != -1){

        cin >> data;

        if(data == -1)
            break;

        head = insertAtHead(head, data);
    }

    // Adding the loop 
    Node* curr = head;

    while(curr->next != NULL){

        curr = curr->next;
    }

    curr->next = head;

    // Calling Loop Check
    bool loop = detectLoopLinkedList(head);    

    if(loop){

        cout <<"Loop Present" << endl;;
    }
    else{

        cout <<"No Loop Present" << endl;;
    }

    return 0;
}