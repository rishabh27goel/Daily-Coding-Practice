#include <iostream>
using namespace std;

class Node {

    public:
        int data;
        int height;
        Node* left;
        Node* right;

    Node(int data){

        this->data = data;
        this->height = 1;
        this->left = NULL;
        this->right = NULL;
    }
};

void printTree(Node* root){

    if(root == NULL) return;

    cout << root->data << " ";

    printTree(root->left);
    printTree(root->right);
}

int getHeight(Node* node){

    if(node == NULL) return 0;

    return node->height;
}

int getBalance(Node* node){

    if(node == NULL) return 0;

    return getHeight(node->left) - getHeight(node->right);
}

Node* leftRotation(Node* node){

    Node* child = node->right;
    Node* leftTree = child->left;

    // Make child new root
    child->left = node;

    // Shift the tree 
    node->right = leftTree;


    // Update Heights
    node->height = 1 + max(getHeight(node->left), getHeight(node->right));
    child->height = 1 + max(getHeight(child->left), getHeight(child->right));

    return child;
}

Node* rightRotation(Node* node){

    Node* child = node->left;
    Node* rightTree = child->right;

    // Make child new root
    child->right = node;

    // Shift the tree 
    node->left = rightTree;


    // Update Heights
    node->height = 1 + max(getHeight(node->left), getHeight(node->right));
    child->height = 1 + max(getHeight(child->left), getHeight(child->right));

    return child;
}

Node* insertionOfNode(Node* root, int value){

    if(root == NULL){

        root = new Node(value);
        return root;
    }
    

    if(root->data == value){

        return root;
    }
    else if(root->data > value){

        root->left = insertionOfNode(root->left, value);
    }
    else{

        root->right = insertionOfNode(root->right, value);
    }

    // Set the height of Ancestors
    root->height = 1 + max(getHeight(root->left), getHeight(root->right));


    // Get the balance factor using height
    int balance = getBalance(root);


    // Rotations in AVL Trees :
    // Left Left Case
    if(balance > 1 && root->left->data > value){

        return rightRotation(root);
    }

    // Right Right Case
    if(balance < -1 && root->right->data < value){

        return leftRotation(root);
    }

    // Left Right Case
    if(balance > 1 && root->left->data < value){

        root->left = leftRotation(root->left);

        return rightRotation(root);
    }

    // Right Left Case
    if(balance < -1 && root->right->data > value){

        root->right = rightRotation(root->right);

        return leftRotation(root);
    }

    return root;
}

int main()
{
    Node* root = NULL;

    // Create AVL { 10 20 30 40 50 -1 }
    cout << "Enter nodes data : ";
    int data = 0;

    while(data != -1){

        cin >> data;
        if(data == -1) break;

        root = insertionOfNode(root, data);

        cout << "\nPrinting Tree : ";
        printTree(root);
    }

    cout << endl;
    return 0;
}