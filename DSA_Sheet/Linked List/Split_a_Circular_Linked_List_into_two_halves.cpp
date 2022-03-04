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

// Method 1 : With Extra Space
void splitCircularList(Node* head, Node* &first, Node* &second){

    if(head == NULL) return;
    if(head->next == head){

        first = head;
        second = NULL;
        return;
    }

    vector<Node *> store;

    Node* curr = head;
    while(curr->next != head){

        store.push_back(curr);
        curr = curr->next;
    }

    store.push_back(curr);

    Node* mid = store[((store.size()-1) / 2)];
    Node* last = store[store.size()-1];

    first = head;
    second = mid->next;
    last->next = mid->next;
    mid->next = first;
}

// Method 2 : Without Extra Space
// void splitCircularList(Node* head, Node* &first, Node* &second){

//     if(head == NULL) return;
//     if(head->next == head){

//         first = head;
//         second = NULL;
//         return;
//     }

//     Node* slow = head;
//     Node* fast = head->next;
//     Node* prev = NULL;

//     while(fast != head && fast->next != head){

//         prev = fast;
//         slow = slow->next;
//         fast = fast->next->next;
//     }

//     first = head;
//     second = slow->next;

//     if(fast->next == head){

//         fast->next = second;
//     }
//     else{

//         prev->next->next = second;
//     }

//     slow->next = first;
// }

void printList(Node* list){

    if(list == NULL) return;

    Node* curr = list;

    while(curr->next != list){

        cout << curr->data <<" ";
        curr = curr->next;
    }

    cout << curr->data;
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

    // Circular Linked List Spit In Two Halves
    Node* first = NULL;
    Node* second = NULL;

    splitCircularList(headList, first, second); 
    
    cout << "\nFirst Split : ";
    printList(first);

    cout << "\nSecond Split : ";
    printList(second);

    cout << endl;
    return 0;
}
