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

// Method 1 : Divide and Conquer
Node* getMid(Node* list){

    Node* slow = list;
    Node* fast = list->next;

    while(fast != NULL && fast->next != NULL){

        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

Node* mergeSortedList(Node* first, Node* second){

    if(first == NULL) return second;
    if(second == NULL) return first;

    // Create Dummy Node
    Node* newList = new Node(-1);
    Node* prev = newList;

    // Now merge the linked list
    while(first != NULL && second != NULL){

        if(first->data <= second->data){

            prev->next = first;
            first = first->next;
        }
        else{

            prev->next = second;
            second = second->next;
        }

        prev = prev->next;
    }

    while(first != NULL){

        prev->next = first;
        prev = prev->next;
        first = first->next;
    }

    while(second != NULL){

        prev->next = second;
        prev = prev->next;
        second = second->next;
    }

    // Now remove the Dummy Nodes created
    prev = newList;
    newList = newList->next;
    delete prev;

    return newList;
}

Node* mergeSortLinkedList(Node* list){

    if(list == NULL || list->next == NULL) return list;

    // Fnd the mid
    Node* mid = getMid(list);

    // Divide linked list to left and right
    Node* left = list;
    Node* right = mid->next;
    mid->next = NULL;

    left = mergeSortLinkedList(left);
    right = mergeSortLinkedList(right);

    // Merge 2 sorted linked list
    list = mergeSortedList(left, right);

    return list;
}

int main()
{
    Node* head = NULL;
    int data = 0;

    cout << "Enter Linked List Data : ";
    while(data != -1){

        cin >> data;

        if(data == -1) break;

        head = insertAtHead(head, data);
    }

    // Merge Sort Linked List
    Node* curr = mergeSortLinkedList(head);

    cout << "\nSorted Linked List : ";
    while(curr != NULL){

        cout << curr->data <<" ";
        curr = curr->next;
    }

    return 0;
}