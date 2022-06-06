#include <iostream>
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

Node* createTree(Node* root, int value){

    if(root == NULL){

        root = new Node(value);
        return root;
    }

    if(root->data > value){

        root->left = createTree(root->left, value);
    }
    else{

        root->right = createTree(root->right, value);
    }

    return root;
}

void printTree(Node* root){

    if(root == NULL) return;

    printTree(root->left);

    cout << root->data << " ";

    printTree(root->right);
}

Node* deleteNodeBST(Node* root, int target);
Node* deleteNodeHelper(Node* node);

// Method : Recursive Method 
// Time Complexity : O(h)  Space Complexity : O(h) 
// Node* deleteNodeHelper(Node* node){

//     // If node has 0 child
//     if(node->left == NULL && node->right == NULL){

//         delete node;
//         return NULL;
//     }
//     // If node has 1 child [Left or Right]
//     else if(node->left != NULL && node->right == NULL){

//         Node* leftChild = node->left;

//         delete node;
//         return leftChild;
//     }
//     else if(node->left == NULL && node->right != NULL){

//         Node* rightChild = node->right;

//         delete node;
//         return rightChild;
//     }
//     // If node has 2 child
//     else{

//         Node* curr = node->right;

//         while(curr->left != NULL){

//             curr = curr->left;
//         }

//         // Copy node data [Inorder Successor]
//         node->data = curr->data;

//         // Delete node from right tree
//         node->right = deleteNodeBST(node->right, node->data);
        
//         return node;
//     }
// }

// Node* deleteNodeBST(Node* root, int target){

//     if(root == NULL) return root;

//     // If node is found
//     if(root->data == target){

//         return deleteNodeHelper(root);
//     }
//     else if(root->data > target){

//         root->left = deleteNodeBST(root->left, target);
//     }
//     else{

//         root->right = deleteNodeBST(root->right, target);
//     }

//     return root;
// }


// Method 2 : Iterative Method 
// Time Complexity : O(h)  Space Complexity : O(1) 
Node* deleteNodeHelper(Node* node){

    // If node has 0 child
    if(node->left == NULL && node->right == NULL){

        delete node;
        return NULL;
    }
    // If node has 1 child
    else if(node->left != NULL && node->right == NULL){

        Node* leftChild = node->left;

        delete node;
        return leftChild;
    }
    else if(node->left == NULL && node->right != NULL){

        Node* rightChild = node->right;

        delete node;
        return rightChild;
    }
    else{

        Node* curr = node->right;
        Node* parent = node;

        while(curr->left != NULL){

            parent = curr;
            curr = curr->left;
        }

        // Copy val of Inorder Successor
        node->data = curr->data;

        if(parent == node){

            node->right = curr->right;
        }
        else{

            parent->left = deleteNodeHelper(parent->left);
        }

        return node;
    }
}

Node* deleteNodeBST(Node* root, int target){

    if(root == NULL) return root;

    // Reach the target node
    Node* parent = root;
    Node* curr = root;

    while(curr != NULL){

        if(curr->data == target){

            break;
        }
        else if(curr->data > target){

            parent = curr;
            curr = curr->left;
        }
        else{

            parent = curr;
            curr = curr->right;
        }
    }

    // If node is not found
    if(curr == NULL) return root;

    // Target is root node
    if(parent == NULL){

        return deleteNodeHelper(root);
    }

    // Store target node
    Node* targetNode = curr;

    if(parent->left == targetNode){

        parent->left = deleteNodeHelper(parent->left);
    }
    else{

        parent->right = deleteNodeHelper(parent->right);
    }
    
    return root;
}

int main()
{
    Node* root = NULL;

    // Create BST { 50 30 15 40 75 60 85 80 -1 }
    cout << "Enter nodes data : ";
    int data = 0;

    while(data != -1){

        cin >> data;
        if(data == -1) break;

        root = createTree(root, data);
    }

    int target;
    cout << "Enter target node : ";
    cin >> target;

    cout << "\nBefore Deletion : ";
    printTree(root);

    // Deletion of a node in BST
    root = deleteNodeBST(root, target);

    cout << "\nAfter Deletion : ";
    printTree(root);

    cout << endl;
    return 0;
}