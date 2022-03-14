#include <iostream>
using namespace std;

class Node {

    public:
        int data;
        Node* prev;
        Node* next;

    Node(int data){

        this->data = data;
        this->prev = NULL;
        this->next = NULL;
    }
};

Node* addNode(Node* head, Node* &tail, int data){

    Node* newNode = new Node(data);

    if(head == NULL){

        head = newNode;
    }
    else{

        tail->next = newNode;
        newNode->prev = tail;
    }

    tail = newNode;
    return head;
}

// Method 1 : Using Insertion Sort
// Time Complexity : O(n * k) - As inner loop with run for max k swaps   
// Space Complexity : O(1)
Node* sortKSortedDLL(Node* head, int k){

    if(head == NULL || head->next == NULL) return head;

    // Starting from second node
    Node* start = head->next;

    while(start != NULL){

        Node* curr = start;

        while(curr->prev != NULL && curr->data < curr->prev->data){

            Node* ptr1 = curr->prev->prev; // Can be NULL
            Node* ptr2 = curr->prev;  // Can not be NULL (As we are stating from second node)
            Node* ptr3 = curr->next;  // Can be NULL

            ptr2->next = ptr3;
            ptr2->prev = curr;

            curr->prev = ptr1;
            curr->next = ptr2;

            if(ptr1 != NULL)  
                ptr1->next = curr;
            
            if(ptr3 != NULL)
                ptr3->prev = ptr2;
        }

        // Update Head
        if(curr->prev == NULL){

            head = curr;
        }   

        start = start->next;
    }

    return head;
}

int main()
{
    Node* listHead = NULL;
    Node* listTail = NULL;

    int data = 0;
    cout << "Enter Linked List Data : ";

    while(data != -1){

        cin >> data;

        if(data == -1) break;
    
        listHead = addNode(listHead, listTail, data);
    }

    int k;
    cout << "Enter value of k : ";
    cin >> k;

    // Sort K Sorted DLL
    listHead = sortKSortedDLL(listHead, k);

    cout << "Updated List : ";
    Node* curr = listHead;
    while(curr != NULL){

        cout << curr->data << " ";
        curr = curr->next;
    }

    cout << endl;
    return 0;
}