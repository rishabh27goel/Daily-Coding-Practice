#include <iostream>
#include <stack>
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

// Method 1 : Simple Iterative
// Time Complexity : O(n + m)  Space Complexity(Return List) : O(max(m, n)) 
// Node* reverseList(Node* head){

//     if(head->next == NULL) return head;

//     Node* track = NULL;
//     Node* prev = NULL;

//     while(head->next != NULL){

//         track = head->next;
//         head->next = prev;
//         prev = head;
//         head = track;
//     }

//     head->next = prev;

//     return head;
// }

// Type 2 : More Optimised
// Node* addTwoNumber(Node* first, Node* second){

//     if(first == NULL) return second;
//     if(second == NULL) return first;

//     // Reverse First and Second
//     first = reverseList(first);
//     second = reverseList(second);

//     Node* sumList = NULL;
//     int carry = 0;

//     while(first != NULL || second != NULL || carry != 0){

//         int val1 = 0;
//         if(first != NULL){

//             val1 = first->data;
//         }

//         int val2 = 0;
//         if(second != NULL){

//             val2 = second->data;
//         }

//         int data = (val1 + val2 + carry) % 10;
//         carry = (val1 + val2 + carry) / 10;

//         sumList = insertAtHead(sumList, data);

//         if(first != NULL) 
//             first = first->next;

//         if(second != NULL)
//             second = second->next;
//     }

//     return sumList;
// }

// Type 1 : Less Optimised
// Node* addTwoNumber(Node* first, Node* second){

//     if(first == NULL) return second;
//     if(second == NULL) return first;

//     // Reverse the First and Second List to add
//     first = reverseList(first);
//     second = reverseList(second);

//     Node* sumList = NULL;
//     int carry = 0;

//     while(first != NULL && second != NULL){

//         int val = (first->data + second->data + carry) % 10;
//         carry = (first->data + second->data + carry) / 10;

//         sumList = insertAtHead(sumList, val);

//         first = first->next;
//         second = second->next;
//     }

//     // Now iterate rest list
//     while(first != NULL){

//         int val = (first->data + carry) % 10;
//         carry = (first->data + carry) / 10;

//         sumList = insertAtHead(sumList, val);
//         first = first->next;
//     }

//     while(second != NULL){

//         int val = (second->data + carry) % 10;
//         carry = (second->data + carry) / 10;

//         sumList = insertAtHead(sumList, val);
//         second = second->next;
//     }

//     if(carry != 0){

//         sumList = insertAtHead(sumList, carry);
//     }

//     return sumList;
// }

// Method 2 : Using Stack
// Time Complexity : O(n + m)  Space Complexity(Return List) : O(max(m, n) + m + n) 
Node* addTwoNumber(Node* first, Node* second){

    if(first == NULL) return second;
    if(second == NULL) return first;

    stack<int> firstStack;
    stack<int> secondStack;
    
    // Store Lists in Stack
    Node* curr1 = first;
    while(curr1 != NULL){

        firstStack.push(curr1->data);
        curr1 = curr1->next;
    }

    Node* curr2 = second;
    while(curr2 != NULL){

        secondStack.push(curr2->data);
        curr2 = curr2->next;
    }

    // Creating Sum Linked List
    Node* sumList = NULL;
    int carry = 0;

    while(!firstStack.empty() || !secondStack.empty() || carry != 0){

        int val1 = 0;
        if(!firstStack.empty()){

            val1 = firstStack.top();
            firstStack.pop();
        }

        int val2 = 0;
        if(!secondStack.empty()){

            val2 = secondStack.top();
            secondStack.pop();
        }

        int data = (val1 + val2 + carry) % 10;
    
        sumList = insertAtHead(sumList, data);
        carry = (val1 + val2 + carry) / 10;
    }

    return sumList;
}

int main()
{
    Node* first = NULL;
    int data1 = 0;
    cout <<"Enter First Linked List Data : ";

    while(data1 != -1){

        cin >> data1;

        if(data1 == -1) break;

        first = insertAtHead(first, data1);
    }

    Node* second = NULL;
    int data2 = 0;
    cout <<"Enter Second Linked List Data : ";

    while(data2 != -1){

        cin >> data2;

        if(data2 == -1) break;

        second = insertAtHead(second, data2);
    }

    // Add Two Numbers
    Node* sumList = addTwoNumber(first, second);

    cout <<"Sum List : ";
    while(sumList != NULL){

        cout << sumList->data <<" ";
        sumList = sumList->next;
    }

    cout <<endl;
    return 0;
}