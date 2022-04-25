#include <iostream>
#include <vector>
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

// Method 1 : Using extra space 
// Time Complexity : O(n)  Space Complexity : O(n)
// Node* reverseSublist(Node* head, int m, int n){

//     if(m > n || m == n || head == NULL || head->next == NULL) return head;

//     // Store linked list into vector
//     vector<Node*> vt;
//     Node* curr = head;

//     while(curr != NULL){

//         vt.push_back(curr);
//         curr = curr->next;
//     }

//     // Check for valid n value 
//     if(m > vt.size()) 
//         return head;
//     if(n > vt.size()) 
//         n = vt.size();

//     // Reverse Sublist from m to n
//     int i = m-1;
//     int j = n-1;

//     while(i < j){

//         swap(vt[i], vt[j]);
//         i++;
//         j--;
//     }

//     // Create list again
//     curr = NULL;

//     for(int i=0; i<vt.size(); i++){

//         if(curr == NULL){

//             curr = vt[i];
//         }
//         else{

//             curr->next = vt[i];
//             curr = vt[i];
//         }
//     }

//     // Last Element as NULL
//     curr->next = NULL;

//     // Set head
//     head = vt[0];

//     return head;
// }

// Method 2 : Without extra space
// Time Complexity : O(n)  Space Complexity : O(1)
Node* reverseList(Node* head){

    Node* track = head;
    Node* prev = NULL;

    while(head->next != NULL){

        track = head->next;
        head->next = prev;
        prev = head;
        head = track;
    }

    head->next = prev;
    return head;
}

Node* reverseSublist(Node* head, int m, int n){

    if(m > n || m == n || head == NULL || head->next == NULL) return head;

    int i = 1;
    Node* curr = head;

    Node* prevEnd = NULL;
    Node *revStart = NULL, *revEnd = NULL;
    Node *prevStart = NULL, *nextEnd = NULL; 

    while(curr != NULL && i <= n){

        if(i < m){

            prevStart = curr;
        }
        else if(i == m){

            revStart = curr;
        }
        else if(i == n){

            revEnd = curr;
        }

        i++;
        prevEnd = curr;
        curr = curr->next;
    }

    // // If M is greater than Linked List Size
    // if(curr == NULL && revStart == NULL){

    //     return head;
    // }

    // // If N is greater than Linked List Size
    // if(curr == NULL && revEnd == NULL){

    //     revEnd = prevEnd;
    // }

    // Set nextEnd
    nextEnd = revEnd->next;

    // Break revEnd with main list
    revEnd->next = NULL;

    Node* updatedStart = reverseList(revStart);
    revEnd = revStart;
    revStart = updatedStart;

    // Link to main list
    if(prevStart == NULL){

        head = revStart;
    }
    else{

        prevStart->next = revStart;
    }

    revEnd->next = nextEnd;
    return head;
}

int main()
{
    Node* listHead = NULL;
    Node* listTail = NULL;

    cout << "Enter Linked List : ";
    int data = 0;

    while(data != -1){

        cin >> data;

        if(data == -1)
            break;

        listHead = addNode(listHead, listTail, data);
    }
    

    int m, n;
    cout << "Enter Start & End of Sublist : ";
    cin >> m >> n;

    listHead = reverseSublist(listHead, m, n);
    
    cout << "Modified Linked List : ";
    Node* curr = listHead;
    while(curr != NULL){

        cout << curr->data << " ";
        curr = curr->next;
    }

    cout << endl;
    return 0;
}