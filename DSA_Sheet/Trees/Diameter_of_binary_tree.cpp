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

Node* createTree(Node* root){

    int data;
    cin >> data;

    if(data == -1) return NULL;

    root = new Node(data);

    root->left = createTree(root->left);
    root->right = createTree(root->right);

    return root;
}

// Method 1 : Recursive Method 
// Time Complexity : O(n^2)  Space Complexity : O(n)
// int heightHelper(Node* root){

//     if(root == NULL) return 0;

//     int lHeight = heightHelper(root->left);
//     int rHeight = heightHelper(root->right);

//     return max(lHeight, rHeight) + 1;
// }

// int diameterOfBinaryTree(Node* root){

//     if(root == NULL) return 0;

//     int leftDiameter = diameterOfBinaryTree(root->left);
//     int rightDiameter = diameterOfBinaryTree(root->right);

//     int leftHeight = heightHelper(root->left);
//     int rightHeight = heightHelper(root->right);

//     int output = max(max(leftDiameter, rightDiameter), leftHeight + rightHeight + 1);

//     return output;
// }

// Method 2 : Recursive Method [Optimized]
// Time Complexity : O(n)  Space Complexity : O(n)
int heightHelper(Node* root, int &diameter){

    if(root == NULL) return 0;

    int leftDiameter = heightHelper(root->left, diameter);
    int rightDiameter = heightHelper(root->right, diameter);

    diameter = max(diameter, leftDiameter + rightDiameter + 1);

    return max(leftDiameter, rightDiameter) + 1;
}

int diameterOfBinaryTree(Node* root){

    if(root == NULL) return 0;

    int diameter = 0;  
    int height = heightHelper(root, diameter);

    return diameter;
}

int main()
{
    Node* root = NULL;

    // Creating the tree { 1 2 4 7 -1 -1 -1 5 -1 -1 3 -1 6 -1 -1 }
    cout << "Enter nodes data : ";
    root = createTree(root);

    // Diameter of Binary Tree
    int diameter = diameterOfBinaryTree(root);
    
    cout << "Diameter of binary tree : " << diameter; 

    cout << endl;
    return 0;
}