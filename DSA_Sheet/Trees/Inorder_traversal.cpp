#include <iostream>
#include <vector>
#include <stack>
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
// void inorderTraversal(Node* root, vector<int> &inorder){

//     if(root == NULL) return;

//     // Left Node : Root Node : Right Node
//     inorderTraversal(root->left, inorder);

//     inorder.push_back(root->data);

//     inorderTraversal(root->right, inorder);
// }

// Method 2 : Iterative Method 
// Time Complexity : O(n)  Space Complexity : O(n)
// void inorderTraversal(Node* root, vector<int> &inorder){

//     if(root == NULL) return;

//     // Storing the tree nodes
//     stack<Node*> st;
//     Node* itr = root;

//     while(!st.empty() || itr != NULL){

//         while(itr != NULL){

//             // Store the nodes
//             st.push(itr);

//             itr = itr->left;
//         }

//         // Itr will be NULL after the loop
//         itr = st.top();
//         st.pop();

//         inorder.push_back(itr->data);

//         // We node we will iterate is right
//         itr = itr->right;
//     }
// }

// Method 3 : Using Morris Traversal 
// Time Complexity : O(n)  Space Complexity : O(n)
void inorderTraversal(Node* root, vector<int> &inorder){

    
}

int main()
{
    Node* root = NULL;

    // Creating the tree { 1 2 4 7 -1 -1 -1 5 -1 -1 3 -1 6 -1 -1 }
    cout << "Enter nodes data : ";
    root = createTree(root);

    // Inorder Traversal
    vector<int> inorder;

    inorderTraversal(root, inorder);

    cout << "Inorder Traversal : ";
    for(int i=0; i<inorder.size(); i++){

        cout << inorder[i] << " ";
    }

    cout << endl;
    return 0;
}