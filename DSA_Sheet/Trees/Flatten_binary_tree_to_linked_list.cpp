#include <iostream>
#include <vector>
using namespace std;

class Node {

    public:
        int data;
        Node* left;
        Node* right;

    Node(int data){

        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

Node* createTree(Node* root){

    int data;
    cin >> data;

    if(data == -1) return NULL;

    root = new Node(data);

    root->left = createTree(root->left);
    root->right = createTree(root->right);

    return root;
}

// Method 1 : Storing the nodes the vector
// Time Complexity : O(n)  Space Complexity : O(n)
// void preorderTraversal(Node* root, vector<Node*> &treeNodes){

//     if(root == NULL) return;

//     treeNodes.push_back(root);

//     preorderTraversal(root->left, treeNodes);
//     preorderTraversal(root->right, treeNodes);
// }

// Node* flattenBinaryTreeToList(Node* root){

//     if(root == NULL) return root;

//     vector<Node*> treeNodes;
//     preorderTraversal(root, treeNodes);

//     // Create the Linked List
//     Node* head = NULL;
//     Node* tail = NULL;

//     for(int i=0; i<treeNodes.size(); i++){

//         if(head == NULL){

//             head = treeNodes[i];
//         }
//         else{

//             tail->right = treeNodes[i];
//             treeNodes[i]->left = tail;
//         }

//         tail = treeNodes[i];
//     }

//     // Ending nodes
//     head->left = NULL;
//     tail->right = NULL;

//     return head;
// }

// Method 2 : Passing head and tail as parameters
// Time Complexity : O(n)  Space Complexity : O(n)
void flattenHelper(Node* root, Node* &head, Node* &tail){

    if(root == NULL) return;

    Node* leftChild = root->left;
    Node* rightChild = root->right;

    root->left = NULL;

    if(head == NULL){

        head = root;
    }
    else{

        tail->right = root;
    }

    tail = root;

    flattenHelper(leftChild, head, tail);
    flattenHelper(rightChild, head, tail);
}

Node* flattenBinaryTreeToList(Node* root){

    if(root == NULL) return root;

    Node* head = NULL;
    Node* tail = NULL;

    flattenHelper(root, head, tail);

    // Ending nodes
    tail->right = NULL;

    return head;
}

int main()
{
    Node* root = NULL;

    // Creating the tree { 1 2 4 7 -1 -1 -1 5 -1 -1 3 -1 6 -1 -1 }
    cout << "Enter nodes data : ";
    root = createTree(root);

    // Flatten Binary Tree To Linked List
    Node* head = flattenBinaryTreeToList(root);

    Node* curr = head;
    cout << "Printing Linked List : ";

    while(curr != NULL){

        cout << curr->data << " ";
        curr = curr->right;
    }

    cout << endl;
    return 0;
}