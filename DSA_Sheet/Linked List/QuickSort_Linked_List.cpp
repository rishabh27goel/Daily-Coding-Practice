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

Node* insertNode(Node* head, Node* &tail, int data){

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

// Quick Sort
// Time Complexity : O(n^2)   Space Complexity : O(n * log(n))

Node* getTail(Node* head){

    Node* tail = head;

    while(tail != NULL && tail->next != NULL){

        tail = tail->next;
    }

    return tail;
}

Node* partition(Node* head, Node* tail, Node* &newHead, Node* &newTail){

    Node* pivot = tail;
    Node* curr = head;
    Node* prev = NULL;
    Node* last = pivot;

    while(curr != pivot){

        if(curr->data >= pivot->data){

            last->next = curr;

            if(prev == NULL){

                curr = curr->next;
            }
            else{

                prev->next = curr->next;
                curr = prev->next;
            }

            last->next->next = NULL;
            last = last->next;
        
            continue;
        }

        // First smaller element than Pivot 
        if(prev == NULL) newHead = curr;

        prev = curr;
        curr = curr->next;
    }

    // If newHead is NULL then Pivot is the smallest element
    if(newHead == NULL) newHead = pivot;

    newTail = last;

    return pivot;
}

Node* quickSortLinkedList(Node* head, Node* tail){

    if(head == NULL || head == tail) return head;

    Node* newHead = NULL;
    Node* newTail = NULL;

    Node* pivot = partition(head, tail, newHead, newTail);

    // If Pivot is the smallest element then no need for left call 
    if(newHead != pivot){

        Node* tmp = newHead;

        while(tmp->next != pivot){

            tmp = tmp->next;
        }

        tmp->next = NULL;

        newHead = quickSortLinkedList(newHead, tmp);

        // Get Updated Tail
        Node* updatedTail = getTail(newHead);

        updatedTail->next = pivot;
    }

    // Right recursive sort
    pivot->next = quickSortLinkedList(pivot->next, newTail);

    return newHead;
}


int main()
{
    Node* listHead = NULL;
    Node* listTail = NULL;

    int data;
    cout << "Enter Linked List Data : ";

    while(data != -1){

        cin >> data;

        if(data == -1) break;
    
        listHead = insertNode(listHead, listTail, data);
    }

    // Quick Sort Linked List
    Node* last = getTail(listHead);
    listHead = quickSortLinkedList(listHead, last);

    Node* curr = listHead;
    cout << "\nSorted Linked List : ";
    while(curr != NULL){

        cout << curr->data << " ";
        curr = curr->next;
    }

    cout << endl;
    return 0;
}