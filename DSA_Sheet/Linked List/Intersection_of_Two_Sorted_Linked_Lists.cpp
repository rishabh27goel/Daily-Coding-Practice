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

// Method 1 : Using Map (Hashing)
// Time Complexity : O(n + m)  Space Complexity : O(max(n, m))
void insertNodeAtTail(Node* &head, Node* &tail, int data){

    Node* newNode = new Node(data);

    if(head == NULL){

        head = newNode;
    }
    else{

        tail->next = newNode;
    }

    tail = newNode;
}

// Node* intersectionTwoSortedList(Node* first, Node* second){

//     if(first == NULL || second == NULL) return NULL;

//     Node* listHead = NULL;
//     Node* listTail = NULL;

//     map<int, int> store;
//     Node* curr1 = first;
//     Node* curr2 = second; 

//     while(curr1 != NULL){

//         store[curr1->data] = 1;

//         curr1 = curr1->next;
//     }

//     while(curr2 != NULL){

//         if(store.find(curr2->data) != store.end()){

//             insertNodeAtTail(listHead, listTail, curr2->data);
//         }

//         curr2 = curr2->next;
//     }
//     return listHead;
// }


// Method 2 :
// Time Complexity : O(n + m)  Space Complexity : O(1)
// Node* intersectionTwoSortedList(Node* first, Node* second){

//     if(first == NULL || second == NULL) return NULL;

//     Node* listHead = NULL;
//     Node* listTail = NULL;

//     Node* curr1 = first;
//     Node* curr2 = second;

//     while(curr1 != NULL && curr2 != NULL){

//         if(curr1->data < curr2->data){

//             curr1 = curr1->next;
//         }
//         else if(curr1->data > curr2->data){

//             curr2 = curr2->next;
//         }
//         else{

//             insertNodeAtTail(listHead, listTail, curr2->data);

//             curr1 = curr1->next;
//             curr2 = curr2->next;
//         }   
//     }

//     return listHead;
// }

// Method 3 : Using Recursion
// Time Complexity : O(n + m)  Space Complexity : Recursion Space
Node* intersectionTwoSortedList(Node* first, Node* second){

    if(first == NULL || second == NULL) return NULL;

    Node* newNode = NULL;

    if(first->data < second->data){

        return intersectionTwoSortedList(first->next, second);
    }
    else if(first->data > second->data){

        return intersectionTwoSortedList(first, second->next);
    }
    else{

        newNode = new Node(first->data);
        newNode->next = intersectionTwoSortedList(first->next, second->next);
    }

    return newNode;
}

int main()
{
    Node* first = NULL;
    int data = 0;

    cout << "Enter First Linked List Data : ";
    while(data != -1){

        cin >> data;

        if(data == -1) break;

        first = insertAtHead(first, data);
    }

    Node* second = NULL;
    data = 0;

    cout << "Enter Second Linked List Data : ";
    while(data != -1){

        cin >> data;

        if(data == -1) break;

        second = insertAtHead(second, data);
    }

    // Intersection of Two Sorted Linked List
    cout << "\nIntersection Linked List : ";

    Node* curr = intersectionTwoSortedList(first, second);

    if(curr != NULL){

        while(curr != NULL){

            cout << curr->data <<" ";
            curr = curr->next;
        }
    }
    else{

        cout << "List is Empty !";
    }
    

    cout << endl;
    return 0;
}