#include <iostream>
#include <vector>
using namespace std;

class Node {

    public:
        int data;
        Node* left;
        Node* right;
        Node* next;

    Node(int data){

        this->data = data;
        this->left = NULL;
        this->right = NULL;
        this->next = NULL;
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

void printTree(Node* root){

    if(root == NULL) return;

    printTree(root->left);

    if(root->next != NULL){

        cout << root->data << " -> " << root->next->data << endl;
    }
    else{

        cout << root->data << " -> " << -1 << endl;
    } 

    printTree(root->right);
}

// Method 1 : Storing inorder as extra space
// Time Complexity : O(n)  Space Complexity : o(n)
// void inorderHelper(Node* root, vector<Node*> &inorder){

//     if(root == NULL) return;

//     inorderHelper(root->left, inorder);

//     inorder.push_back(root);

//     inorderHelper(root->right, inorder);
// }

// Node* inorderSuccessorAllNodes(Node* root){

//     if(root == NULL) return root;

//     // Store the inorder
//     vector <Node*> inorder;

//     inorderHelper(root, inorder);


//     // Create the connection to inorder successor
//     for(int i=1; i<inorder.size(); i++){

//         inorder[i-1]->next = inorder[i];
//     }

//     return root;
// }

// Method 2 : Tracking previous inorder node
// Time Complexity : O(n)  Space Complexity : O(n)
Node* connectInorderHelper(Node* root, Node* &prev){

    if(root == NULL) return root;

    root->left = connectInorderHelper(root->left, prev);

    if(prev == NULL){

        prev = root;
    }
    else{

        prev->next = root;
        prev = root;
    }

    root->right = connectInorderHelper(root->right, prev);

    return root;
}

Node* inorderSuccessorAllNodes(Node* root){

    if(root == NULL) return root;

    Node* prev = NULL;

    return connectInorderHelper(root, prev);
}

int main()
{
    Node* root = NULL;

    // Creating the tree { 1 2 4 7 -1 -1 -1 5 -1 -1 3 -1 6 -1 -1 }
    cout << "Enter nodes data : ";
    root = createTree(root);

    // Inorder Successor for all nodes
    root = inorderSuccessorAllNodes(root);

    cout << "Printing Inorder Successor : " << endl;
    printTree(root);

    return 0;
}
