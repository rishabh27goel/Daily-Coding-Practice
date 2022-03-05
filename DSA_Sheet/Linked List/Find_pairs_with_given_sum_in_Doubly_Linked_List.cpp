#include <iostream>
#include <map>
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

// Method 1 : Two Loops
// Time Complexity : O(n ^ 2)  Space Complexity : O(1)
// void pairSumLinkedList(Node* head,int sum){

//     if(head == NULL || head->next == NULL) return; 

//     int arr[2];
//     bool found = false;

//     Node* ptr = head;

//     while(ptr->next != NULL){

//         Node* start = ptr->next;

//         while(start != NULL){

//             if(ptr->data + start->data == sum){

//                 arr[0] = ptr->data;
//                 arr[1] = start->data;

//                 cout << arr[0] << " " << arr[1] << endl;
//                 found = true;
//             }

//             start = start->next;
//         }
//         ptr = ptr->next;
//     }

//     if(found == false) cout << "No such pair exits !";    
// }

// Method 2 : Using HashMap
// Time Complexity : O(n)  Space Complexity : O(n)
// void pairSumLinkedList(Node* head,int sum){

//     if(head == NULL || head->next == NULL) return;

//     map<int, int> store;
//     bool found = false;
//     Node* ptr = head;

//     while(ptr != NULL){

//         if(store.find(sum - ptr->data) != store.end()){

//             cout << sum - ptr->data << " " << ptr->data << endl;
//             found = true;
//         }
//         else{

//             store[ptr->data] = 1;
//         }

//         ptr = ptr->next;
//     }

//     if(found == false) cout << "No such pair exits !"; 
// }

// Method 3 : Single Iteration
// Time Complexity : O(n)  Space Complexity : O(1)
void pairSumLinkedList(Node* head,int sum){

    if(head == NULL || head->next == NULL) return;

    // Move to Last Node
    Node* last = head;
    bool found = false;

    while(last->next != NULL){

        last = last->next;
    }

    // Can also use this while(itr->data < last->data){ }

    // Compare from both ends
    Node* itr = head;

    while(itr != last && last->next != itr){

        int value = itr->data + last->data;

        if(value > sum){

            last = last->prev;
        }
        else if(value < sum){

            itr = itr->next;
        }
        else{

            cout << itr->data << " " << last->data << endl; 

            found = true;
            itr = itr->next;
            last = last->prev;
        }
    }

    if(found == false) cout << "No such pair exits !"; 
}

int main()
{
    Node* listHead = NULL;
    Node* listTail = NULL;

    cout << "Enter Linked List Data : ";
    int data = 0;
    while(data != -1){

        cin >> data;

        if(data == -1) break;
    
        listHead = addNode(listHead, listTail, data);
    }

    int sum;
    cout << "Enter Value of sum : ";
    cin >> sum;

    // Pair with given sum 
    pairSumLinkedList(listHead, sum);

    cout << endl;
    return 0;
}