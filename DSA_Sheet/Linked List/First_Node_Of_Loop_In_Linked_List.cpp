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
// Node* firstNodeOfLoop(Node* head){

//     Node* curr = head;
//     map <Node *, bool> visited;

//     while(curr != NULL){

//         if(visited.find(curr) != visited.end()){

//             return curr;
//         }
//         else{

//             visited[curr] = true;
//         }

//         curr = curr->next;
//     }

//     return NULL;
// }

// Method 2 : Using Floyd's Detection Algorithm
// Time Complexity : O(n)   Space Complexity : O(n)

Node* findPointOfIntersection(Node* start, Node* fast){

    while(start != fast){

        start = start->next;
        fast = fast->next;
    }

    return start;
}

Node* firstNodeOfLoop(Node* head){

    Node* slow = head;
    Node* fast = head;

    // Getting the Point Of Fast and Slow Pointer Intersection

    while(fast != NULL && fast->next != NULL){

        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast){

            // Loop Exits
            return findPointOfIntersection(head, fast);
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

    while(curr->next->next != NULL){

        curr = curr->next;
    }

    curr->next = head;

    // Find the first node of the loop 
    Node* firstNode = firstNodeOfLoop(head);

    if(firstNode == NULL){

        cout <<"No Loop Present !" << endl;
    }
    else{

        cout <<"Loop Start Node : " << firstNode->data << endl;
    }

    return 0;
}