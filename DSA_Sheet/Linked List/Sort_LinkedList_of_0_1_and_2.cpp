#include <iostream>
using namespace std;

class Node {

    public:
        int data;
        Node *next;

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

// Method 1 : With replacing data
// Node* sortLinkedListOf012(Node* head){

//     if(head == NULL || head->next == NULL) return head;

//     int zeroCount = 0;
//     int oneCount = 0;
//     int twoCount = 0;

//     // Counting the 0s, 1s and 2s
//     Node* curr = head;

//     while(curr != NULL){

//         int val = curr->data;
        
//         if(val == 0){

//             zeroCount++;
//         }
//         else if(val == 1){

//             oneCount++;
//         }
//         else{

//             twoCount++;
//         }

//         curr = curr->next;
//     }

//     // Second Iteration and replace data
//     curr = head;

//     while(curr != NULL){

//         if(zeroCount != 0){

//             curr->data = 0;
//             zeroCount--;
//         }
//         else if(oneCount != 0){

//             curr->data = 1;
//             oneCount--;
//         }
//         else if(twoCount != 0){

//             curr->data = 2;
//             twoCount--;
//         }

//         curr = curr->next;
//     }

//     return head;
// }

// Method 2 : Without Data Replacement
void insertingAtTail(Node* &tail, Node* curr){

    tail->next = curr;
    tail = curr;
}

Node* sortLinkedListOf012(Node* head){

    if(head == NULL || head->next == NULL) return head;

    // Creating the Heads and Tails and Dummy Nodes
    Node* zeroHead = new Node(-1);
    Node* zeroTail = zeroHead;

    Node* oneHead = new Node(-1);
    Node* oneTail = oneHead;

    Node* twoHead = new Node(-1);
    Node* twoTail = twoHead;

    // Creating the Sub-Lists

    Node* curr = head;
    Node* track = NULL;

    while(curr != NULL){

        int val = curr->data;
        
        track = curr->next;
        curr->next = NULL;

        if(val == 0){

            insertingAtTail(zeroTail, curr);
        }
        else if(val == 1){

            insertingAtTail(oneTail, curr);
        }
        else if(val == 2){

            insertingAtTail(twoTail, curr);
        }

        curr = track;
    }

    // Merge the sub-Lists of 0, 1, 2

    if(oneHead->next != NULL){

        zeroTail->next = oneHead->next;
    }
    else{

        zeroTail->next = twoHead->next;
    }

    // It will cover both above case
    oneTail->next = twoHead->next;
    twoTail->next = NULL;

    head = zeroHead->next;

    // Remove the Dummy Nodes
    delete zeroHead;
    delete oneHead;
    delete twoHead;

    return head;
}


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

    head = sortLinkedListOf012(head);

    cout <<"\nSorted Linked List : ";
    Node* curr = head;

    while(curr != NULL){

        cout <<curr->data <<" ";
        curr = curr->next;
    }

    cout <<endl;
    return 0;
}

