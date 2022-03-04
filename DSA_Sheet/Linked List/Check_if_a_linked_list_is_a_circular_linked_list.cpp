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

// Method 1 : Simple Iterative
// bool checkCircularList(Node* head){

//     if(head == NULL) return false;
//     if(head->next == head) return true;

//     Node* curr = head;

//     while(curr != NULL){

//         if(curr->next == head) return true;

//         curr = curr->next;
//     }

//     return false;
// }

// Method 2 : Using Map
bool checkCircularList(Node* head){

    if(head == NULL) return false;
    if(head->next == head) return true;

    map <Node* , bool> store;
    store[head] = true;

    Node* curr = head->next;

    while(curr != NULL){

        if(store.find(curr) != store.end()){

            return true;
        }
        else{

            store[curr] = true;
        }

        curr = curr->next;
    }

    return false;
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

    // Check for Circular Linked List
    bool get = checkCircularList(headList);

    if(get){

        cout << "Linked List is Circular !";
    }
    else{

        cout << "Linked List is not Circular !";
    }

    cout << endl;
    return 0;
}