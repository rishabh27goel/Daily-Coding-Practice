#include <iostream>
#include <stack>
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


// Method 1 : Using Recursion
// Time Complexity : O(n)  Space Complexity : Stack Space O(n/k)
// Node* reverseLinkedListInGroups(Node* head, int k){

//     if(k == 1) return head;

//     Node* curr = head;
//     int count = 0;

//     Node* track = NULL;
//     Node* prev = NULL;

//     while(curr != NULL && count < k){

//         track = curr->next;
//         curr->next = prev;

//         prev = curr;
//         curr = track;

//         count++;
//     }

//     if(curr != NULL){

//         head->next = reverseLinkedListInGroups(curr, k);
//     }

//     return prev;
// }

// Method 2 : Using Stack
// Time Complexity : O(n)  Space Complexity : Stack Space O(k)
Node* reverseLinkedListInGroups(Node* head, int k){

    if(k == 1) return head;

    Node* curr = head;
    stack <Node *> store;

    Node* prev = NULL;

    while(curr != NULL){

        int count = 0;

        // Store size elements in the Stack
        while(curr != NULL && count < k){

            store.push(curr);

            curr = curr->next;
            count++;
        }

        // Get elements from stack
        while(!store.empty()){

            Node* get = store.top();
            store.pop();
            get->next = NULL;

            if(prev == NULL){
                
                prev = get;
                head = get;
            }
            else{

                prev->next = get;
                prev = get;
            }
        }
    }   

    return head;
}


int main()
{
    Node* head = NULL;

    int data;

    cout<<"Enter Linked List Data : ";
    while(data != -1){

        cin >> data;

        if(data == -1) break;

        head = insertAtHead(head, data);
    }

    int k;
    cout <<"Enter size : ";
    cin >> k;

    Node* curr = head;

    cout <<"Linked List : ";
    while(curr != NULL){

        cout <<curr->data <<" ";
        curr = curr->next;
    }

    curr = reverseLinkedListInGroups(head, k);

    cout<<"\nNew Linked List : ";

    while(curr != NULL){

        cout <<curr->data <<" ";
        curr = curr->next;
    }

    cout <<endl;
    return 0;
}