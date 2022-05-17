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

// Method 1 : Storing inorder 
// Time Complexity : O(n)  Space Complexity : O(n)
// void inorderHelper(Node* root, vector<Node*> &inorder){

//     if(root == NULL) return;

//     inorderHelper(root->left, inorder);

//     inorder.push_back(root);

//     inorderHelper(root->right, inorder);
// }

// Node* binaryToDDL(Node* root){

//     if(root == NULL) return root;

//     // Storing the nodes in inorder order manner
//     vector<Node*> inorder;

//     inorderHelper(root, inorder);

//     // Create the DDL with the help of vector
//     Node* head = NULL;
//     Node* tail = NULL;

//     for(int i=0; i<inorder.size(); i++){

//         if(head == NULL){

//             head = inorder[i];
//         }
//         else{

//             tail->right = inorder[i];
//             inorder[i]->left = tail;
//         }

//         tail = inorder[i];
//     }

//     return head;
// }

// Method 2 : Modifying tree in recursion itself 
// Time Complexity : O(n)  Space Complexity : O(n)
void inorderHelper(Node* root, Node* &head, Node* &tail){

    if(root == NULL) return;

    inorderHelper(root->left, head, tail);

    if(head == NULL){

        head = root;
    }
    else{

        tail->right = root;
        root->left = tail;
    }

    tail = root;

    inorderHelper(root->right, head, tail);
}

Node* binaryToDDL(Node* root){

    if(root == NULL) return root;

    Node* head = NULL;
    Node* tail = NULL;

    inorderHelper(root, head, tail);

    return head;
}

int main()
{   
    Node* root = NULL;

    // Creating the tree { 1 2 4 7 -1 -1 -1 5 -1 -1 3 -1 6 -1 -1 }
    cout << "Enter nodes data : ";
    root = createTree(root);

    // Binary Tree To Doubly Linked List
    Node* curr = binaryToDDL(root);

    cout << "Doubly Linked List : ";
    while(curr != NULL){

        cout << curr->data << " ";
        curr = curr->right; 
    }

    cout << endl;
    return 0;
}