#include <iostream>
#include <vector>
#include <map>
#include <utility>
using namespace std;

class Node {

    public:
        int data;
        Node* next;
        Node* random;
    
    Node(int data){

        this->data = data;
        this->next = NULL;
        this->random = NULL;
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

// Method 1 : Checking for random node using additional loop
// Time Complexity : O(n ^ 2)  Space Complexity : O(1)
Node* createNode(Node* head, Node* &tail, int data){

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

Node* cloneLLWithNextRandom(Node* head){

    if(head == NULL) return head;

    // First create copy for next pointer 
    Node* listHead = NULL;
    Node* listTail = NULL;
    Node* curr1 = head;

    while(curr1 != NULL){

        listHead = createNode(listHead, listTail, curr1->data);
        curr1 = curr1->next;
    }

    // Handling Random Pointer
    Node* curr2 = listHead;
    curr1 = head;

    while(curr1 != NULL){

        if(curr1->random != NULL){

            // Reach the random node
            Node* store = curr1->random;
            Node* itr1 = head;
            Node* itr2 = listHead;

            while(itr1 != store){

                itr2 = itr2->next;
                itr1 = itr1->next;
            }

            curr2->random = itr2;
        }
        else{

            curr2->random = NULL;
        }

        curr1 = curr1->next;
        curr2 = curr2->next;
    }

    return listHead;
}

// Method 2 : Using Map for storing old and new nodes
// Time Complexity : O(n)  Space Complexity : O(n)
// Node* cloneLLWithNextRandom(Node* head){

//     if(head == NULL) return head;

//     // First create copy for next pointer 
//     map<Node *, Node *> mapping;   // {mapping oldNode to newNode}
//     Node* listHead = NULL;
//     Node* listTail = NULL;

//     Node* curr = head;
//     while(curr != NULL){

//         listHead = createNode(listHead, listTail, curr->data);
        
//         mapping[curr] = listTail;
//         curr = curr->next;
//     }

//     // Handling random pointers
//     curr = head;
//     while(curr != NULL){

//         if(curr->random != NULL){

//             mapping[curr]->random = mapping[curr->random];
//         }
//         else{

//             mapping[curr]->random = NULL;
//         }

//         curr = curr->next;
//     }

//     return listHead;
// }

// Method 3 : Modifying original list without using extra space
// Time Complexity : O(n)  Space Complexity : O(1)
// Node* cloneLLWithNextRandom(Node* head){

//     if(head == NULL) return head;

//     // First create copy for next pointer and 
//     // connect new list with original list
//     Node* track = NULL;
//     Node* curr = head;

//     while(curr != NULL){

//         track = curr->next;

//         Node* newNode = new Node(curr->data);
//         curr->next = newNode;
//         newNode->next = track;

//         curr = track;
//     }

//     // Handle random pointer
//     curr = head;
//     while(curr != NULL){

//         if(curr->random != NULL){

//             curr->next->random = curr->random->next;
//         }
//         else{

//             curr->next->random = NULL;
//         }

//         curr = curr->next->next;
//     }

//     // Remove extra links 
//     Node* newList = head->next;
//     curr = head;
//     track = NULL;

//     while(curr != NULL){

//         track = curr->next->next;

//         if(track != NULL){

//             curr->next->next = track->next;
//         }
//         else{

//             curr->next->next = NULL;
//         }

//         curr->next = track;
//         curr = track;
//     }

//     return newList;
// }

int main()
{
    vector<Node *> nodes;
    Node* listHead = NULL;
    Node* listTail = NULL;

    int data = 0;
    cout << "Enter Linked List Data : ";

    while(data != -1){

        cin >> data;
        
        if(data == -1) break;

        listHead = addNode(listHead, listTail, data);
        nodes.push_back(listTail);
    }

    // Adding Random Pointers
    int n;
    cout << "Enter number of pairs : ";
    cin >> n;

    int a, b;
    cout << "Enter value of pairs : ";
    for(int i=0; i<n; i++){

        cin >> a;
        cin >> b;

        nodes[a-1]->random = nodes[b-1];
    }

    // Original List : 
    Node* curr = listHead;    
    cout << "Original List : \n";
    while(curr != NULL){

        cout << curr->data << " ";
        curr = curr->next;
    }
    
    cout << endl;
    curr = listHead;    
    while(curr != NULL){

        if(curr->random != NULL){

            cout << curr->random->data << " ";
        }
        else{

            cout << "-1 ";
        }
        
        curr = curr->next;
    }

    // Clone LL with next and random pointers
    Node* newList = cloneLLWithNextRandom(listHead); 

    curr = newList;   
    cout << "\nNew List : \n";
    while(curr != NULL){

        cout << curr->data << " ";
        curr = curr->next;
    }
    
    cout << endl;
    curr = listHead;    
    while(curr != NULL){

        if(curr->random != NULL){

            cout << curr->random->data << " ";
        }
        else{

            cout << "-1 ";
        }
        
        curr = curr->next;
    }

    cout << endl;
    return 0;
}