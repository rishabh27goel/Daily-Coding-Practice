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

// Method : Storing the nodes of tree
// Time Complexity : O(n)  Space Complexity : O(n)
void fillInorder(Node* root, vector <Node*> &inorder){

    if(root == NULL) return;

    fillInorder(root->left, inorder);

    inorder.push_back(root);

    fillInorder(root->right, inorder);
}

Node* createTreeInorderHelper(vector <Node*> &inorder, int start, int end){

    if(start > end) return NULL;

    int middle = (start + end)/2;

    Node* root = inorder[middle];

    root->left = createTreeInorderHelper(inorder, start, middle-1);
    root->right = createTreeInorderHelper(inorder, middle+1, end);

    return root;
}

Node* convertToBalanceBST(Node* root){

    if(root == NULL) return NULL;

    // Storing the node in inorder
    vector <Node*> inorder;
    fillInorder(root, inorder);

    // Creating Tree using Inorder 
    root = createTreeInorderHelper(inorder, 0, inorder.size()-1);

    return root;
}

int main()
{
    Node* root = NULL;

    // Create BST { 50 30 15 10 75 85 90 -1 }
    cout << "Enter nodes data : ";
    int data = 0;

    while(data != -1){

        cin >> data;
        if(data == -1) break;

        root = createTree(root, data);
    }

    // BST to Balanced BST
    root = convertToBalanceBST(root);

    cout << "\nBalanced Binary Tree : ";
    printTree(root);

    cout << endl;
    return 0;
}