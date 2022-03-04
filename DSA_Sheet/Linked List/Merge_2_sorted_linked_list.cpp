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

// Method 1 : Simple Iterative Using Dummy Node
void simplify(Node* &newList, Node* &node){

    newList->next = node;
    newList = newList->next;
    node = node->next;
}

Node* merge_2_sorted_list(Node* first, Node* second){

    if(first == NULL) return second;
    if(second == NULL) return first;

    // Create Dummy Node
    Node* newList = new Node(-1);
    Node* start = newList;
    Node* curr1 = first;
    Node* curr2 = second;

    while(curr1 != NULL && curr2 != NULL){

        if(curr1->data <= curr2->data){

            simplify(newList, curr1);
        }
        else{

            simplify(newList, curr2);
        }
    }

    while(curr1 != NULL){

        simplify(newList, curr1);
    }

    while(curr2 != NULL){

        simplify(newList, curr2);
    }

    // Delete Dummy Nodes
    newList = start;
    newList = newList->next;
    delete start;

    return newList;
}

// Method 2 : Using Recursion
// Time Complexity : O(m+n)  Space Complexity : Stack Space + Const space
// Node* merge_2_sorted_list(Node* first, Node* second){

//     if(first == NULL) return second;
//     if(second == NULL) return first;

//     // Resultant List
//     Node* result = NULL;

//     if(first->data <= second->data){

//         result = first;
//         result->next = merge_2_sorted_list(first->next, second);
//     }
//     else{

//         result = second;
//         result->next = merge_2_sorted_list(first, second->next);
//     }

//     return result;
// }

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

    // Merge 2 Sorted Linked List
    Node* curr = merge_2_sorted_list(first, second);

    cout << "Modified List is : ";
    while(curr != NULL){

        cout << curr->data <<" ";
        curr = curr->next;
    }

    cout << endl;
    return 0;
}