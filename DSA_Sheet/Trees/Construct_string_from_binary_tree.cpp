#include <iostream>
using namespace std;
#include <string.h>

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

// Method : Recursive Method
// Time Complexity : O(n)  Space Complexity : O(n)
string binaryTreeToString(Node* root){

    // Empty Tree
    if(root == NULL) return "";

    // Leaf Node
    if(root->left == NULL && root->right == NULL) return to_string(root->data);

    string output = "";
    output += to_string(root->data);

    // Left Child
    output += '(';

    if(root->left != NULL){

        output += binaryTreeToString(root->left);
    }

    output += ')';

    // Right Child
    if(root->right != NULL){

        output += '(';
        output += binaryTreeToString(root->right);
        output += ')';
    }

    return output;
}

int main()
{
    Node* root = NULL;

    // Creating the tree { 1 2 4 7 -1 -1 -1 5 -1 -1 3 -1 6 -1 -1 }
    cout << "Enter nodes data : ";
    root = createTree(root);

    // Construct String From Binary Tree
    string output = binaryTreeToString(root);

    cout << "Tree String : " << output;

    cout << endl;
    return 0;
}