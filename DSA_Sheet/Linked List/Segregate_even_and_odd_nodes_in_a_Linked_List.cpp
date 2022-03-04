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

Node* insertNode(Node* head, Node* &tail, int data){

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

// Method 1 : Create Seprate Lists for Even and Odd
// void addNodeToHead(Node* &head, Node* &tail, Node* node){

//     if(head == NULL){

//         head = node;
//     }
//     else{

//         tail->next = node;
//     }

//     tail = node;
// }

// Node* segregateOddEven(Node* head){

//     if(head == NULL || head->next == NULL) return head;

//     // Declare Even and Odd Heads & Tails
//     Node* evenHead = NULL;
//     Node* oddHead = NULL;

//     Node* evenTail = NULL;
//     Node* oddTail = NULL;

//     Node* curr = head;
//     Node* track = NULL;

//     while(curr != NULL){

//         track = curr->next;
//         curr->next = NULL;

//         if(curr->data % 2 == 0){

//             addNodeToHead(evenHead, evenTail, curr);
//         }
//         else{

//             addNodeToHead(oddHead, oddTail, curr);
//         }

//         curr = track;
//     }

//     if(evenHead == NULL) return oddHead;
//     if(oddHead == NULL) return evenHead;

//     evenTail->next = oddHead;

//     return evenHead;
// }

// Method 2 : 
Node* segregateOddEven(Node* head){

    if(head == NULL || head->next == NULL) return head;

    // Move to last node
    Node* last = head;

    while(last->next != NULL){

        last = last->next;
    }

    Node* store_last = last;
    Node* curr = head;

    while(curr->data % 2 != 0){

        if(curr == store_last) break;

        // Move Odd Nodes to last
        last->next = curr;
        curr = curr->next;
        last->next->next = NULL;
        last = last->next;
    }

    if(curr->data % 2 == 0){

        head = curr;
    }
    else{

        last->next = curr;
        curr = curr->next;
        last->next->next = NULL;
        last = last->next;

        head = curr;
        return head;
    }

    Node* prev = NULL;
    curr = head;

    cout << head->data;

    while(curr != store_last){

        if(curr->data % 2 == 1){

            last->next = curr;
            prev->next = curr->next;
            curr = curr->next;
            last->next->next = NULL;
            last = last->next;

            continue;
        }

        prev = curr;
        curr = curr->next;
    }

    if(curr->data % 2 == 1){

        last->next = curr;
        
        prev->next = curr->next;
        last->next->next = NULL;
    }

    return head;
}

int main()
{
    Node* headList = NULL;
    Node* tailList = NULL;

    int data = 0;
    cout << "Enter Linked List Data : ";
    
    while(data != -1){

        cin >> data;

        if(data == -1) break;
    
        headList = insertNode(headList, tailList, data);
    }

    // Segregate Even and Odd Nodes
    headList = segregateOddEven(headList);
    Node* curr = headList;
 
    cout << "\nSegregated List : ";

    while(curr != NULL){

        cout << curr->data << " ";
        curr = curr->next;
    }

    cout << endl;
    return 0;
}