#include <iostream>
#include <vector>
#include <queue>
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

// Method : 3 Step Process 
// Time Complexity : O(n)  Space Complexity : O(n)
void leftBoundary(Node* root, vector<int> &boundary){

    // Base Case [If leaf nodes occurs]
    if(root == NULL || (root->left == NULL && root->right == NULL)) return;

    // Store the root data [Before Call]
    boundary.push_back(root->data);

    if(root->left == NULL)
        leftBoundary(root->right, boundary); 
    else
        leftBoundary(root->left, boundary);
}

void leafNodes(Node* root, vector<int> &boundary){

    if(root == NULL) return;

    // Leaf Nodes
    if(root->left == NULL && root->right == NULL){

        boundary.push_back(root->data);
    }

    leafNodes(root->left, boundary);
    leafNodes(root->right, boundary);
}

void rightBoundary(Node* root, vector<int> &boundary){

    // Base Case [If leaf nodes occurs]
    if(root == NULL || (root->left == NULL && root->right == NULL)) return;

    if(root->right == NULL)
        rightBoundary(root->left, boundary); 
    else
        rightBoundary(root->right, boundary);

    // Store the root data [After Call]
    boundary.push_back(root->data);
}

void boundaryTraversal(Node* root, vector<int> &boundary){

    if(root == NULL) return;

    // Steps : 
    // 1. Root Node
    // 2. Left Tree Boundary
    // 3. Leaf Nodes [Left to Right]
    // 4. Left Tree Boundary

    // Store the root node
    boundary.push_back(root->data);

    // Left Tree Boundary [In normal Order]
    leftBoundary(root->left, boundary);

    // Leaf Nodes [Left to Right]
    leafNodes(root->left, boundary);
    leafNodes(root->right, boundary);

    // Right Tree Boundary [In reverse Order]
    rightBoundary(root->right, boundary);
}

int main()
{
    Node* root = NULL;

    // Creating the tree { 1 2 4 7 -1 -1 -1 5 -1 -1 3 -1 6 -1 -1 }
    cout << "Enter nodes data : ";
    root = createTree(root);

    // Boundary Traversal Of Binary Tree
    vector<int> boundary;
    
    boundaryTraversal(root, boundary);

    cout << "Boundary Traversal : ";
    for(int i=0; i<boundary.size(); i++){

        cout << boundary[i] << " ";
    }

    cout << endl;
    return 0;
}