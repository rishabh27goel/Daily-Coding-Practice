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
// Time Complexity : O(n)   Space Complexity : O(n)
// Node* removeLoopLinkedList(Node* head){

//     Node* curr = head;
//     Node* prevTrack;

//     map <Node *, bool> visited;

//     while(curr != NULL){

//         if(visited.find(curr) != visited.end()){

//             return prevTrack;
//         }
//         else{

//             visited[curr] = true;
//             prevTrack = curr;
//         }
//     }

//     return NULL;
// }

// Method 2 :

Node* findFirstNode(Node* slow, Node* fast){

    while(slow != fast){

        slow = slow->next;
        fast = fast->next;
    }

    return slow;
}

Node* removeLoopLinkedList(Node* head){

    Node* slow = head;
    Node* fast = head;

    while(fast != NULL && fast->next != NULL){

        slow = slow->next;
        fast = fast->next->next;

        // Loop Exits
        if(fast == slow){

            // Find the first node of loop 
            Node* firstNode = findFirstNode(head, fast);

            cout <<"Loop Starts At : " << firstNode->data << endl;
            Node* curr = firstNode;

            while(curr->next != firstNode){

                curr = curr->next;
            }

            curr->next = NULL;
            return head;
        }
    }



    return NULL;
}


int main()
{
    Node* head = NULL;

    int data = 0;

    cout <<"Enter Linked List Data : ";

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

    curr->next = head->next->next;

    // Removing the Loop From Linked List
    head = removeLoopLinkedList(head);

    if(head == NULL){

        cout <<"No Loop Present !" << endl;
    }
    else{

        curr = head;

        cout <<"Loop Exits & Removed : " ;

        while(curr != NULL){

            cout << curr->data <<" ";
            curr = curr->next;
        }
    }

    cout<<endl;
    return 0;
}