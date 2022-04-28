#include <iostream>
#include <stack>
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

// Method 1 : Recursive Method 
// Time Complexity : O(n)  Space Complexity : O(n)
void postorderTraversal(Node* root, vector<int> &postorder){

    if(root == NULL) return;

    // Left Node : Right Node : Root Node
    postorderTraversal(root->left, postorder);
    postorderTraversal(root->right, postorder);

    postorder.push_back(root->data);
}


int main()
{
    Node* root = NULL;

    // Creating the tree { 1 2 4 7 -1 -1 -1 5 -1 -1 3 -1 6 -1 -1 }
    cout << "Enter nodes data : "; 
    root = createTree(root);

    // Postorder Traversal
    vector<int> postorder;

    postorderTraversal(root, postorder);

    cout << "Postorder Traversal : ";
    for(int i=0; i<postorder.size(); i++){

        cout << postorder[i] << " ";
    }

    cout << endl;
    return 0;
}