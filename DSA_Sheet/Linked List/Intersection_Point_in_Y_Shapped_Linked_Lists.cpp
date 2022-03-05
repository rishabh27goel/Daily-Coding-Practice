#include <iostream>
#include <map>
#include <math.h>
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

// Method 1 : Two Loops
// Time Complexity : O(n * m)   Space Complexity : O(1)
// Node* intersectionPoint(Node* first, Node* second){

//     if(first == NULL || second == NULL) return NULL;

//     Node* curr1 = first;

//     while(curr1 != NULL){

//         Node* curr2 = second;

//         while(curr2 != NULL){

//             if(curr1 == curr2){

//                 return curr1;
//             }

//             curr2 = curr2->next;
//         }

//         curr1 = curr1->next;
//     } 

//     return NULL;
// }

// Method 2 : Using HashMap 
// Time Complexity : O(n + m)   Space Complexity : O(n)
// Node* intersectionPoint(Node* first, Node* second){

//     if(first == NULL || second == NULL) return NULL;

//     // Storing First Linked List Nodes in Visited Map
//     map<Node*, bool> visited;

//     Node* curr1 = first;
//     while(curr1 != NULL){

//         visited[curr1] = true;

//         curr1 = curr1->next;
//     }

//     Node* curr2 = second;
//     while(curr2 != NULL){

//         if(visited.find(curr2) != visited.end()){

//             return curr2;
//         }

//         curr2 = curr2->next;
//     }

//     return NULL;
// }   

// Method 3 : 2-Pointer Method
// Time Complexity : O(n + m)   Space Complexity : O(1)
// Node* intersectionPoint(Node* first, Node* second){

//     if(first == NULL || second == NULL) return NULL;

//     Node* curr1 = first;
//     Node* curr2 = second;

//     while(curr1 != curr2){

//         if(curr1 == NULL) curr1 = second;
//         if(curr2 == NULL) curr2 = first;

//         curr1 = curr1->next;
//         curr2 = curr2->next;
//     }

//     return curr1;
// }

// Method 4 : Count both Linked List
// Time Complexity : O(n + m)   Space Complexity : O(1)
Node* intersectionPoint(Node* first, Node* second){

    if(first == NULL || second == NULL) return NULL;

    int count1 = 0;
    int count2 = 0;

    Node* curr1 = first;
    while(curr1 != NULL){

        count1++;
        curr1 = curr1->next;
    }

    Node* curr2 = second;
    while(curr2 != NULL){

        count2++;
        curr2 = curr2->next;
    }

    int diff = count1 - count2;
    if(diff > 0){

        curr1 = first;
        curr2 = second;
    }
    else{

        curr1 = second;
        curr2 = first;
    }

    // Move Diff nodes in larger list
    diff = abs(diff);

    while(diff--){

        curr1 = curr1->next;
    }

    while(curr1 != curr2){

        curr1 = curr1->next;
        curr2 = curr2->next;
    }

    return curr1;
}

int main()
{
    // First Linked List
    Node* firstHead = NULL;
    Node* firstTail = NULL;

    int data = 0;
    cout << "Enter First Linked List Data : ";

    while(data != -1){

        cin >> data;

        if(data == -1) break;

        firstHead = addNode(firstHead, firstTail, data);
    }

    // Second Linked List
    Node* secondHead = NULL;
    Node* secondTail = NULL;

    data = 0;
    cout << "Enter Second Linked List Data : ";

    while(data != -1){

        cin >> data;

        if(data == -1) break;

        secondHead = addNode(secondHead, secondTail, data);
    }

    // Common Linked List
    Node* commonHead = NULL;
    Node* commonTail = NULL;

    data = 0;
    cout << "Enter Common Linked List Data : ";

    while(data != -1){

        cin >> data;

        if(data == -1) break;

        commonHead = addNode(commonHead, commonTail, data);
    }

    // Merge 
    firstTail->next = commonHead;
    secondTail->next = commonHead;

    Node* startCommon = intersectionPoint(firstHead, secondHead);

    if(startCommon == NULL){

        cout << "No Intersection Point !";
    }
    else{

        cout << "Intersection Node is : " << startCommon->data;
    }

    cout << endl;
    return 0;
}