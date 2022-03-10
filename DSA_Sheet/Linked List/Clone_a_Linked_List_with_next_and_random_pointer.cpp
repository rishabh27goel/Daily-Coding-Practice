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

// Method 1 : Using Map for storing old and new nodes
// Time Complexity : O(n)  Space Complexity : O(n)
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
    map<Node *, Node *> mapping;   // {mapping oldNode to newNode}
    Node* listHead = NULL;
    Node* listTail = NULL;

    Node* curr = head;
    while(curr != NULL){

        listHead = createNode(listHead, listTail, curr->data);
        
        mapping[curr] = listTail;
        curr = curr->next;
    }

    // Handling random pointers
    curr = head;
    while(curr != NULL){

        if(curr->random != NULL){

            mapping[curr]->random = mapping[curr->random];
        }
        else{

            mapping[curr]->random = NULL;
        }

        curr = curr->next;
    }

    return listHead;
}

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
    cout << "New List : \n";
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