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


// Method 1 : Time Complexity : O(n)  Space Complexity : O(n)
// bool checkPalindrome(Node* head){

//     if(head->next == NULL) return true;

//     string palindromeString = "";

//     while(head != NULL){

//         palindromeString += ('0' + head->data);
//         head = head->next;
//     }

//     // Checking For Palindrome

//     int start = 0;
//     int end = palindromeString.size()-1;

//     while(start <= end){

//         if(palindromeString[start] != palindromeString[end])
//             return false;

//         start++;
//         end--;
//     }

//     return true;
// }

// Method 2 : Time Complexity : O(n)  Space Complexity : O(1)

Node* getMid(Node* head){

    Node* slow = head;
    Node* fast = head->next;

    while(fast != NULL && fast->next != NULL){

        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

Node* reverse(Node* head){

    Node* prev = NULL;
    Node* track = NULL;

    while(head->next != NULL){

        track = head->next;
        head->next = prev;
        prev = head;
        head = track;
    }

    head->next = prev;

    return head;
}

bool checkPalindrome(Node* head){

    if(head->next == NULL) return true;

    // Finding the middle
    Node* middle = getMid(head);

    // Reverse the List after middle
    middle->next = reverse(middle->next);

    // Compare for palindrome check
    Node* start = head;
    Node* halfWay = middle->next;

    while(halfWay != NULL){

        if(start->data != halfWay->data)
            return false;

        start = start->next;
        halfWay = halfWay->next;
    }

    return true;
}

void insertAtHead(int data, Node* &head){

    Node* newNode = new Node(data);

    if(head == NULL){

        head = newNode;
    }
    else{

        newNode->next = head;
        head = newNode;
    }
}

int main()
{   
    Node* head = NULL;
    int data = 0;

    cout <<"Enter Linked List Data : ";

    while(data != -1){

        cin >> data;

        if(data == -1)
            break;

        insertAtHead(data, head);
    }

    bool palindrome = checkPalindrome(head);
    
    if(palindrome)
        cout <<"Palindrome";
    else
        cout <<"Not Palindrome";

    cout <<endl;
    return 0;
}