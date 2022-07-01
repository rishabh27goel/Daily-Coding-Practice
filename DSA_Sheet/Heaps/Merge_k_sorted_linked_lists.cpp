#include <iostream>
#include <vector>
#include <queue>
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

Node* insertNode(Node* head, Node* &tail, int data){

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

// Method 1 : Divide & Conquer 
// Time Complexity : O(k * n * log(k))  Space Complexity : O(1)
// void addNode(Node* &head, Node* &tail, Node* &node){

//     if(head == NULL){

//         head = node;
//     }
//     else{

//         tail->next = node;
//     }

//     tail = node;
// }

// Node* mergeTwoSortedList(Node* first, Node* second){

//     if(first == NULL) return second;
//     if(second == NULL) return first;

//     Node* head = NULL;
//     Node* tail = NULL;

//     while(first != NULL && second != NULL){

//         if(first->data <= second->data){

//            addNode(head, tail, first);
//             first = first->next;
//         }
//         else{

//             addNode(head, tail, second);
//             second = second->next;
//         }
//     }

//     while(first != NULL){

//         addNode(head, tail, first);
//         first = first->next;
//     }

//     while(second != NULL){

//         addNode(head, tail, second);
//         second = second->next;
//     }

//     return head;
// }

// Node* mergeKSortedLL(vector <Node*> &nodes){

//     if(nodes.size() == 0) return NULL;

//     int i = 0;
//     int j = nodes.size()-1;

//     while(j != 0){

//         i = 0;

//         while(i < j){

//             nodes[i] = mergeTwoSortedList(nodes[i], nodes[j]);
//             i++;
//             j--;
//         }
//     }

//     return nodes[j];
// }

// Method 2 : Using Min Heaps
// Time Complexity : O(k * n * log(k))  Space Complexity : O(k)
class Store {

    public:
        Node* node;
        int row;

    Store(Node* node, int row){

        this->node = node;
        this->row = row;
    }
};

class CompareData {

    public:
        bool operator()(Store* s1, Store* s2){

            return s1->node->data > s2->node->data;
        }
};

Node* mergeKSortedLL(vector <Node*> &nodes){

    if(nodes.size() == 0) return NULL;

    priority_queue <Store* , vector<Store*>, CompareData> pq;

    Node* head = NULL;
    Node* tail = NULL;

    // Push first node of all k lists
    for(int i=0; i<nodes.size(); i++){

        if(nodes[i] != NULL)
            pq.push(new Store(nodes[i], i));
    }

    // Rest of nodes
    while(!pq.empty()){

        Store* top = pq.top();
        pq.pop();

        Node* nextElement = top->node->next;
        int row = top->row;

        // Inserting Elements
        if(nextElement != NULL){

            pq.push(new Store(nextElement, row));
        }

        if(head == NULL){

            head = top->node;
        }
        else{

            tail->next = top->node;
        }

        tail = top->node;
    }

    return head;
}


int main()
{
    cout << "Enter size : ";
    int k;
    cin >> k;

    vector <Node*> nodes;

    for(int i=0; i<k; i++){

        cout << "Enter data : ";
        int data = 0;

        Node* head = NULL;
        Node* tail = NULL;

        while(data != -1){

            cin >> data;
            if(data == -1) break;

            head = insertNode(head, tail, data);
        }

        nodes.push_back(head);
    }

    // Merge K Sorted LL
    Node* itr = mergeKSortedLL(nodes);

    cout << "Merged Linked List : ";
    while(itr != NULL){

        cout << itr->data << " ";
        itr = itr->next;
    }

    cout << endl;
    return 0;
}