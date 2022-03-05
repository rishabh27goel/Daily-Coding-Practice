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

// Method 1 : Triple Loops
// Time Complexity : O(n ^ 3)  Space Complexity : O(1)
// int countTripletInDDL(Node* head, int sum){

//     // If list is less than 3 nodes
//     if(head == NULL || head->next == NULL || head->next->next == NULL) return -1;

//     int count = 0;
//     Node* itr1 = head;

//     while(itr1->next->next != NULL){

//         Node* itr2 = itr1->next;
        
//         while(itr2->next != NULL){

//             Node* itr3 = itr2->next;

//             while(itr3 != NULL){

//                 if(itr1->data + itr2->data + itr3->data == sum){

//                     cout << itr1->data << " " << itr2->data << " " <<itr3->data << endl;
//                     count++;
//                 }

//                 itr3 = itr3->next;
//             }

//             itr2 = itr2->next;
//         }

//         itr1 = itr1->next;
//     }

//     if(count == 0) return -1;

//     return count;
// }

// Method 2 : Using HashMap
// Time Complexity : O(n ^ 2)  Space Complexity : O(n)
// int countTripletInDDL(Node* head, int sum){

//     if(head == NULL || head->next == NULL || head->next->next == NULL) return -1;
    
//     // Store all the elements
//     int count = 0;
//     Node* itr = head;
//     map<int, Node*> store;

//     while(itr != NULL){

//         store[itr->data] = itr;
//         itr = itr->next;
//     }

//     // Check for remaining sum
//     Node* first = head;

//     while(first->next != NULL){

//         Node* second = first->next;

//         while(second != NULL){

//             int val = sum - (first->data + second->data);

//             if(store.find(val) != store.end() && second->data < val && store[val] != first && store[val] != second){

//                 cout << first->data << " " << second->data << " " << val << endl;
//                 count++;
//             }

//             second = second->next;
//         }

//         first = first->next;
//     }

//     if(count == 0) return -1;

//     return count;
// }

// Method 3 : Using TwoPointer
// Time Complexity : O(n ^ 2)  Space Complexity : O(1)
int countTripletInDDL(Node* head, int sum){

    if(head == NULL || head->next == NULL || head->next->next == NULL) return -1;

    int count = 0;
    Node* lastStore = head;

    while(lastStore->next != NULL){

        lastStore = lastStore->next;
    }

    Node* itr1 = head;
    while(itr1->next != NULL){

        Node* itr2 = itr1->next;
        Node* last = lastStore;
        int target = sum - itr1->data;

        while(itr2 != last && last->next != itr2){

            int val = itr2->data + last->data;

            if(val  > target){

                last = last->prev;
            }
            else if(val < target){

                itr2 = itr2->next;
            }
            else{

                count++;
                cout << itr1->data << " " << itr2->data << " " << last->data << endl;
                
                itr2 = itr2->next;
                last = last->prev;
            }
        }

        itr1 = itr1->next;
    }

    if(count == 0) return -1;

    return count;
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
    cout << "Enter sum value : ";
    cin >> sum;

    // Count triplets
    int count = countTripletInDDL(listHead, sum);

    if(count == -1){

        cout << "No triplets exits !";
    }
    else{

        cout << "Count is : " << count;
    }

    cout << endl;
    return 0;
}