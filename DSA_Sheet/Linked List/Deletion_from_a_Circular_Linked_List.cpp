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

    newNode->next = head;
    tail = newNode;

    return head;
}

// Method 1 : Using Iterative Method
// Node* deleteNodeFromLinkedList(Node* head, int key){

//     // Empty List
//     if(head == NULL) return NULL;

//     // One Node
//     if(head->next == head){

//         if(head->data == key){

//             delete head;
//             return NULL;
//         }

//         return head;
//     }

//     // More than 1 Node
//     Node* curr = head;
//     Node* prev = NULL;

//     while(curr->next != head){

//         if(curr->data == key){

//             if(prev == NULL){

//                 Node* last = head;
//                 while(last->next != head){

//                     last = last->next;
//                 }

//                 Node* track = head;
//                 head = head->next;
//                 last->next = head;

//                 delete track;
//             }
//             else{

//                 Node* track = curr;
//                 prev->next = curr->next;

//                 delete track;
//             }

//             return head;
//         }

//         prev = curr;
//         curr = curr->next;
//     }

//     if(curr->data == key){

//         prev->next = head;
//         delete curr;
//     }

//     return head;
// }

// Method 2 : Using Recursive Method
Node* deleteHelper(Node* head, Node* root, int key){

    cout << root->data;
    if(head == root) return root;

    if(root->data == key){

        Node* nextTrack = root->next;
    
        delete root;
        return nextTrack;
    }

    root->next = deleteHelper(head, root->next, key);

    return root;
}
Node* deleteNodeFromLinkedList(Node* head, int key){

    // Empty List
    if(head == NULL) return NULL;

    // One Node
    if(head->next == head){

        if(head->data == key){

            delete head;
            return NULL;
        }

        return head;
    }

    if(head->data == key){

        head = head->next;
    }

    head->next = deleteHelper(head, head->next, key);

    return head;
}

int main()
{
    Node* listHead = NULL;
    Node* listTail = NULL;

    // Creating Circular Linked List
    int data = 0;
    cout << "Enter Linked List Data : ";
    
    while(data != -1){

        cin >> data;

        if(data == -1) break;

        listHead = insertNode(listHead, listTail, data);
    }

    int key;
    cout << "Enter Key value : ";
    cin >> key;

    // Deletion from a Circular Linked List
    listHead = deleteNodeFromLinkedList(listHead, key);
    
    Node* curr = listHead;

    cout << "\nUpdated List : ";
    if(curr != NULL){
        
        while(curr->next != listHead){

            cout << curr->data << " ";
            curr = curr->next;
        }

        cout << curr->data;
    }
    else{

        cout << "List Empty !!";
    }

    cout << endl;
    return 0;
}