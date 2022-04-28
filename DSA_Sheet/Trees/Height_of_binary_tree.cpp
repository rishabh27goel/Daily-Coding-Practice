#include <iostream>
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

// Method 1 : Recursive Method 
// Time Complexity : O(n)  Space Complexity : O(h) [But for Skewed Trees -> O(n)]
// int heightOfBinaryTree(Node* root){

//     if(root == NULL) return 0;

//     int leftTree = heightOfBinaryTree(root->left);
//     int rightTree = heightOfBinaryTree(root->right);

//     return max(leftTree, rightTree) + 1;
// }

// Method 2 : Iterative Method [Level Order]
// Time Complexity : O(n)  Space Complexity : O(n)
int heightOfBinaryTree(Node* root){

    if(root == NULL) return 0;

    int height = 0;

    queue<Node*> q;
    q.push(root);

    while(!q.empty()){

        int level = q.size();

        while(level--){

            Node* front = q.front();
            q.pop();

            if(front->left != NULL){

                q.push(front->left);
            }

            if(front->right != NULL){

                q.push(front->right);
            }
        }

        height++;
    }

    return height;
}

int main()
{
    Node* root = NULL;

    // Creating the tree { 1 2 4 7 -1 -1 -1 5 -1 -1 3 -1 6 -1 -1 }
    cout << "Enter nodes data : ";
    root = createTree(root);

    // Height of binary tree
    int height = heightOfBinaryTree(root);
    
    cout << "Height of binary tree : " << height;

    cout << endl;
    return 0;
}