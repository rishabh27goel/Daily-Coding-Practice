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

// Method 1 : 
// Time Comlexity : O(n + m)  Space Complexity : O(1)
const long long mod = 1000000007;

long long multiplyTwoLinkedList(Node* first, Node* second){

    Node* curr1 = first;
    Node* curr2 = second;

    long long n1 = 0;
    long long n2 = 0;

    while(curr1 != NULL || curr2 != NULL){

        if(curr1 != NULL){

            n1 = ((n1 * 10) % mod) + curr1->data;
            curr1 = curr1->next;
        }

        if(curr2 != NULL){

            n2 = ((n2 * 10) % mod) + curr2->data;
            curr2 = curr2->next;
        }
    }

    return ((n1 % mod) * (n2 % mod)) % mod;
}

int main()
{
    Node* first = NULL;
    int data = 0;
    cout << "Enter First Linked List Data : ";

    while(data != -1){

        cin >> data;

        if(data == -1) break;

        first = insertAtHead(first, data);
    }

    Node* second = NULL;
    data = 0;
    cout << "Enter Second Linked List Data : ";

    while(data != -1){

        cin >> data;

        if(data == -1) break;

        second = insertAtHead(second, data);
    }

    // Multiply Two Linked List
    long long output = multiplyTwoLinkedList(first, second);

    cout << "\nMultiplied Number is : " << output;

    cout << endl;
    return 0;
}
