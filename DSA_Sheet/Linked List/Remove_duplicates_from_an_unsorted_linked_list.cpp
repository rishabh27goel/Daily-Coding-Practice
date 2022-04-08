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

// Method 1 : 
// Time Complexity : O(n^2)   Space Complexity : O(1)
// Type 1 :
// Node* removeDuplicates(Node* head){

//     if(head == NULL || head->next == NULL) return head;

//     Node* curr = head;

//     while(curr != NULL){

//         Node* start = curr;

//         while(start->next != NULL){

//             if(curr->data == start->next->data){

//                 Node* track = start->next;
//                 start->next = start->next->next;

//                 delete track;
//                 continue;
//             }

//             start = start->next;
//         }

//         curr = curr->next;
//     }

//     return head;
// }

// Type 2 :
// Node* removeDuplicates(Node* head){

//     if(head == NULL || head->next == NULL) return head;

//     Node* curr = head;

//     while(curr != NULL){

//         Node* start = curr->next;
//         Node* prev = curr;

//         while(start != NULL){

//             if(start->data == curr->data){

//                 Node* track = start;
//                 prev->next = start->next;
//                 start = start->next;

//                 delete track;
//                 continue;
//             }

//             prev = start;
//             start = start->next;
//         }

//         curr = curr->next;
//     }

//     return head;
// }

// Method 2 : Using Sorting
// Time Complexity : O(n * logn)   Space Complexity : O(1)
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

    Node* newList = new Node(-1);
    Node* prev = newList;

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

    prev = newList;
    newList = newList->next;

    delete prev;

    return newList;
}

Node* mergeSort(Node* list){

    if(list == NULL || list->next == NULL) return list;
    // Getting the mid element
    Node* mid = getMid(list);

    Node* left = list;
    Node* right = mid->next;
    mid->next = NULL;

    left = mergeSort(left);
    right = mergeSort(right);

    // Merge 2 Sorted Lists
    list = mergeSortedList(left, right);

    return list;
}

Node* removeDuplicates(Node* head){

    if(head == NULL || head->next == NULL) return head;

    // Merge Sort Linked List
    head = mergeSort(head);

    // Remove the duplicated elements
    Node* curr = head;

    while(curr->next != NULL){
        
        if(curr->data == curr->next->data){

            Node* store = curr->next;
            curr->next = curr->next->next;
            
            delete store; 
            continue;
        }

        curr = curr->next;
    }

    return head;
}

// Method 3 : Using Map
// Time Complexity : O(n)   Space Complexity : O(n)
// Node* removeDuplicates(Node* head){

//     if(head == NULL || head->next == NULL) return head;

//     map<int, bool> visited;
//     Node* curr = head;
//     Node* prev = NULL;

//     while(curr != NULL){

//         if(visited.find(curr->data) != visited.end()){

//             Node* track = curr;
//             prev->next = curr->next;
//             curr = prev;

//             delete track;
//         }
//         else{

//             visited[curr->data] = true;
//         }

//         prev = curr;
//         curr = curr->next;
//     }

//     return head;
// }   

int main()
{
    Node* head = NULL;
    int data = 0;

    cout <<"Enter Linked List Data : ";
    while(data != -1){

        cin >> data;

        if(data == -1) break;

        head = insertAtHead(head, data);
    }

    cout <<"Linked List is : ";
    Node* curr = head;

    while(curr != NULL){

        cout <<curr->data <<" ";
        curr = curr->next;
    }

    // Unsorted Linked List Remove Duplicates
    cout <<"\nNew List is : ";
    head = removeDuplicates(head);
    curr = head;

    while(curr != NULL){

        cout <<curr->data <<" ";
        curr = curr->next;
    }

    cout << endl;
    return 0;
}