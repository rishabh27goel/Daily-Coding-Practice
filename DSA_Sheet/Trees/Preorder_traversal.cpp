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

    // Left and Right Child
    root->left = createTree(root->left);
    root->right = createTree(root->right);

    return root;
}

// Method 1 : Recursive Method 
// Time Complexity : O(n)  Space Complexity : O(n)
// void preorderTraversal(Node* root, vector<int> &preorder){

//     if(root == NULL) return;

//     // Root Node : Left Node : Right Node
//     preorder.push_back(root->data);

//     preorderTraversal(root->left, preorder);
//     preorderTraversal(root->right, preorder);
// }

// Method 2 : Iterative Method 
// Time Complexity : O(n)  Space Complexity : O(n)
// void preorderTraversal(Node* root, vector<int> &preorder){

//     if(root == NULL) return;

//     // For iterating the tree
//     stack<Node*> st;
//     st.push(root);

//     while(!st.empty()){

//         Node* top = st.top();
//         st.pop();

//         // Storing the root first
//         preorder.push_back(top->data);

//         if(top->right != NULL){

//             st.push(top->right);
//         }

//         if(top->left != NULL){

//             st.push(top->left);
//         }
//     }
// }

// Method 3 : Iterative Method [Space Optimized]
// Time Complexity : O(n)  Space Complexity : O(h) 
// We are not storing more than { height of the tree nodes } in the stack
void preorderTraversal(Node* root, vector<int> &preorder){

    if(root == NULL) return;

    // Print left nodes & store right nodes
    stack<Node*> st;
    Node* itr = root;

    while(!st.empty() || itr != NULL){

        while(itr != NULL){

            // Store the data [left nodes]
            preorder.push_back(itr->data);

            // Push right nodes in the stack
            if(itr->right != NULL){

                st.push(itr->right);
            }

            itr = itr->left;
        }

        // Taking one every time from stack
        if(!st.empty()){

            itr = st.top();
            st.pop();
        }
    }
}

int main()
{
    Node* root = NULL;

    // Creating the tree { 1 2 4 7 -1 -1 -1 5 -1 -1 3 -1 6 -1 -1 }
    cout << "Enter nodes data : ";
    root = createTree(root);

    // Preorder Traversal
    vector<int> preorder;
    
    preorderTraversal(root, preorder);

    cout << "Preorder Traversal : ";
    for(int i=0; i<preorder.size(); i++){

        cout << preorder[i] << " ";
    }

    cout << endl;
    return 0;
}