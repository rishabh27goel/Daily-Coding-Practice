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

Node* addNode(Node* head, Node* &tail, int data){

    Node* newNode = new Node(data);

    if(head == NULL){

        head = newNode;
    }
    else{

        tail->next = newNode;
    }

    tail = newNode;

    return head;
}

// Method 1 : Simple Two Loops
// Time Complexity : O(n ^ 2)  Space Complexity : O(1)
// Node* deleteNodesGreaterValue(Node* head){

//     if(head == NULL || head->next == NULL) return head;

//     Node* itr1 = head;
//     Node* prev = NULL;

//     while(itr1->next != NULL){

//         bool found = false;
//         Node* itr2 = itr1->next;

//         while(itr2 != NULL){

//             if(itr2->data > itr1->data){

//                 found = true;
//                 break;
//             }

//             itr2 = itr2->next;
//         }

//         if(found == true){

//             Node* track = itr1;

//             if(prev == NULL){

//                 head = head->next;
//                 itr1 = head;
//             }
//             else{

//                 prev->next = itr1->next;
//                 itr1 = itr1->next;
//             }

//             delete track;
//             continue;
//         }

//         prev = itr1;
//         itr1 = itr1->next;
//     }

//     return head;
// }

// Method 2 : Reverse the list
// Time Complexity : O(n)  Space Complexity : O(1)
Node* reverseList(Node* head){

    if(head == NULL || head->next == NULL) return head;

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

Node* deleteNodesGreaterValue(Node* head){

    if(head == NULL || head->next == NULL) return head;

    // Reverse the list
    head = reverseList(head);

    Node* itr = head;
    int max = head->data;

    while(itr->next != NULL){

        if(itr->next->data < max){

            Node* track = itr->next;
            itr->next = itr->next->next;

            delete track;
            continue;
        }
        else{

            max = itr->next->data;
        }

        itr = itr->next;
    }

    // For original order of the list
    head = reverseList(head);

    return head;
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

    // Delete Node if any greater value on the right
    listHead = deleteNodesGreaterValue(listHead);

    Node* curr = listHead;
    cout << "Updated List : ";
    while(curr != NULL){

        cout << curr->data << " ";
        curr = curr->next;
    }

    cout << endl;
    return 0;
}