#include <iostream>
using namespace std;

class Node{

    public:
        int data;
        Node* next;

    Node(int data){

        this->data = data;
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
    }

    tail = newNode;
    return head;
}

// Helper Funtions
Node* addNode(Node* head, Node* &tail, Node* node){

    if(head == NULL){

        head = node;
    }
    else{

        tail->next = node;
    } 

    tail = node;
    return head;
}

Node* mergeTwoLists(Node* first, Node* second){

    if(first == NULL) return second;
    if(second == NULL) return first;

    Node* listHead = NULL;
    Node* listTail = NULL;

    Node* curr1 = first;
    Node* curr2 = second;

    while(curr1 != NULL && curr2 != NULL){

        if(curr1->data < curr2->data){

            listHead = addNode(listHead, listTail, curr1);
            curr1 = curr1->next;
        }
        else{

            listHead = addNode(listHead, listTail, curr2);
            curr2 = curr2->next;
        }
    }

    while(curr1 != NULL){

        listHead = addNode(listHead, listTail, curr1);
        curr1 = curr1->next;
    }

    while(curr2 != NULL){

        listHead = addNode(listHead, listTail, curr2);
        curr2 = curr2->next;
    }

    return listHead;
}

// Method 1 : Merging every list with first list
// Time Complexity : O(n * k * k)  Space Complexity : O(1)
// Node* mergeKSortedLL(Node* arr[], int k){

//     if(k == 1) return arr[0];

//     Node* newList = arr[0];
//     int index = 1;

//     while(index < k){

//         newList = mergeTwoLists(newList, arr[index]);
//         index++;
//     }

//     return newList;    
// }

// Method 2 : Merging every list in pair of two
// Time Complexity : O(n * k * log(k))  Space Complexity : O(1)
Node* mergeKSortedLL(Node* arr[], int k){

    if(k == 1) return arr[0];

    int start = 0;
    int last = k-1;

    while(last != 0){

        start = 0;
        
        while(start < last){

            arr[start] = mergeTwoLists(arr[start], arr[last]);
            start++;
            last--;
        }
    }

    return arr[0];    
}

int main()
{
    int k;
    cout << "Enter value of K : ";
    cin >> k;

    // Get K Sorted Linked List
    Node* arr[k];

    int i = 0;
    while(i < k){

        Node* listHead = NULL;
        Node* listTail = NULL;

        int data = 0;
        cout << "Enter Linked List Data : ";
        
        while(data != -1){

            cin >> data;

            if(data == -1) break;

            listHead = addNode(listHead, listTail, data);
        }

        arr[i] = listHead;
        i++;
    }
    
    // Merge K Sorted Linked List
    cout << "Merge Sorted List : ";
    Node* curr = mergeKSortedLL(arr, k);
    while(curr != NULL){

        cout << curr->data << " ";
        curr = curr->next;
    }
    
    cout << endl;
    return 0;
}