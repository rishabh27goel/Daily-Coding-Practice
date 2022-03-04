#include <iostream>
#include <vector>
using namespace std;

struct Node {

    int data;
    struct Node *next;
};

void printLinkedList(struct Node *head){

    if(head == NULL) return;

    cout<<"Linked List is : ";
    while(head != NULL){

        cout <<head->data <<" ";
        head = head -> next;
    }
}

void creatingLinkedList(vector<int> arr, int index, struct Node* &head, struct Node *prev){

    if(index == arr.size()){

        printLinkedList(head);
        return;
    }

    struct Node *curr = (struct Node *)malloc(sizeof(struct Node));
    curr -> data = arr[index];
    curr -> next = NULL;

    if(head == NULL){

        head = curr;
    }
    else{

        prev -> next = curr;
    }

    prev = curr;

    creatingLinkedList(arr, index + 1, head, prev);
}

int main()
{
    struct Node *head = NULL;

    vector<int> arr;
    int data = 0;

    cout<<"Enter Linked List: ";
    while(data != -1){

        cin>> data;

        if(data == -1)
            break;

        arr.push_back(data);
    }

    creatingLinkedList(arr, 0, head, NULL);

    cout <<endl;
    return 0;
}