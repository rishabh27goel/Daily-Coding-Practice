#include <iostream>
#include <queue>
using namespace std;

class Node {

    public:
        char data;
        Node* next;

    Node(int data){

        this->data = data;
        this->next = NULL;
    }
};

// Method 1 : Using Count Map
// Time complexity : O(26 * n)   Space Complexity : O(26)
// string firstNonRepeating(string input){

//     if(input.size() <= 1) return input;

//     string output = "";
//     int arr[26] = {0};

//     for(int i=0; i<input.size(); i++){

//         if(arr[input[i]-'a'] == 0){

//             arr[input[i]-'a'] = i+1;
//         }
//         else{

//             arr[input[i]-'a'] = -1;
//         }

//         int min = INT_MAX;

//         for(int i=0; i<26; i++){

//             if(arr[i] > 0 && arr[i] < min){

//                 min = arr[i];
//             }
//         }

//         if(min == INT_MAX){

//             output += '#';
//         }
//         else{

//             output += input[min-1];
//         }
//     }

//     return output;
// }

// Method 2 : Using Queue
// Time complexity : O(n)   Space Complexity : O(n)
// string firstNonRepeating(string input){

//     if(input.size() <= 1) return input;

//     string output = "";
//     queue<char> store;
//     int count[26] = {0};

//     for(int i=0; i<input.size(); i++){

//         count[input[i]-'a']++;
//         store.push(input[i]);
        
//         while(!store.empty()){

//             if(count[store.front()-'a'] > 1){

//                 store.pop();
//             }
//             else{

//                 output += store.front();
//                 break;
//             }

//         }
        
//         if(store.empty()) output += '#';
//     }

//     return output;
// }

// Method 3 : Using Linked List
// Time complexity : O(n)   Space Complexity : O(n)
Node* createNode(Node* head, Node* &tail, char data){

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

void deleteNode(Node* &head, Node* &tail){

    if(head->next == NULL){

        head = NULL;
        tail = NULL;
        return;
    }

    Node* track = head;
    head = head->next;

    delete track;
}

string firstNonRepeating(string input){

    if(input.size() <= 1) return input;

    string output = "";
    int count[26] = {0};
    Node* listHead = NULL;
    Node* listTail = NULL;

    for(int i=0; i<input.size(); i++){

        listHead = createNode(listHead, listTail, input[i]);        
        count[input[i]-'a']++;
        
        while(listHead != NULL){

            if(count[listHead->data - 'a'] > 1){

                deleteNode(listHead, listTail);
            }
            else{

                output += listHead->data;
                break;
            }
        }

        if(listHead == NULL) output += '#';
    }

    return output;
}

int main()
{
    cout << "Enter Input String : ";
    string input;
    cin >> input;

    // First Non-Repeating Character in Stream
    string output = firstNonRepeating(input);

    if(output != ""){

        cout << "Output String is : " << output;
    }

    cout << endl;
    return 0;
}