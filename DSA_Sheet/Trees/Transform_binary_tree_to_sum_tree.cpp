#include <iostream>
#include <utility>
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

void printTree(Node* root){

    queue<Node*> q;
    q.push(root);

    cout << "Printing the tree : ";
    while(!q.empty()){

        // Get the node & Print it
        Node* front = q.front();
        q.pop();

        cout << front->data << " ";

        // Push its child in the queue
        if(front->left != NULL){

            q.push(front->left);
        }

        if(front->right != NULL){

            q.push(front->right);
        }
    }
}

// Method : Recursive Method 
// Time Complexity : O(n)  Space Complexity : O(n)
pair<int, Node*> helperSumConvert(Node* root){

    // Empty Node
    if(root == NULL) return make_pair(0, root);

    // Leaf Node
    if(root->left == NULL && root->right == NULL){

        int val = root->data;
        root->data = 0;

        return make_pair(val, root);
    }

    pair<int, Node*> leftSum = helperSumConvert(root->left);
    pair<int, Node*> rightSum = helperSumConvert(root->right);

    // Change root node data
    int val = root->data;

    root->data = leftSum.first + rightSum.first;

    return make_pair(val + leftSum.first + rightSum.first, root);
}

Node* binaryToSum(Node* root){

    if(root == NULL) return root;

    return helperSumConvert(root).second;
}

int main()
{
    Node* root = NULL;

    // Creating the tree { 1 2 4 7 -1 -1 -1 5 -1 -1 3 -1 6 -1 -1 }
    cout << "Enter nodes data : ";
    root = createTree(root);

    // Binary Tree To Sum Tree
    cout << "\nPrinting Binary Tree : ";
    printTree(root);

    
    root = binaryToSum(root);

    cout << "\nPrinting Sum Tree : ";
    printTree(root);

    cout << endl;
    return 0;
}