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
// Time Complexity : O(n)   Space Complexity : O(n)
// int getCount(Node* root){

//     if(root == NULL) 
//         return 0;

//     return 1 + getCount(root->left) + getCount(root->right);
// }

// bool isComplete(Node* root, int index, int count){

//     if(root == NULL)
//         return true;

//     // If node is not null and index exceeds count
//     if(index >= count)
//         return false;

//     return isComplete(root->left, 2*index + 1, count) && isComplete(root->right, 2*index + 2, count);
// }

// bool isMaxHeap(Node* root){

//     // Positive Base Case
//     if(root->left == NULL && root->right == NULL) return true;

//     if(root->right == NULL) return root->data > root->left->data;

//     // Negative Base Case
//     bool rootCheck = (root->data > root->left->data) && (root->data > root->right->data);

//     return rootCheck && isMaxHeap(root->left) && isMaxHeap(root->right);
// }

// bool isHeap(Node* root){

//     if(root == NULL) return true;

//     // Count of Nodes 
//     int count = getCount(root);

//     return isComplete(root, 0, count) && isMaxHeap(root);
// }

// Method 2 : Iterative Method
// Time Complexity : O(n)   Space Complexity : O(n)
bool isHeap(Node* root){

    if(root == NULL) return true;

    // Queue for storing nodes
    queue <Node*> q;
    q.push(root);
    
    bool nullish = false;

    while(!q.empty()){

        Node* front = q.front();
        q.pop();

        if(front->left != NULL){

            if(nullish || front->left->data > front->data)
                return false;

            q.push(front->left);
        }
        else{
            
            // Null is found
            nullish = true;
        }

        if(front->right != NULL){

            if(nullish || front->right->data > front->data)
                return false;

            q.push(front->right);
        }
        else{
            
            // Null is found
            nullish = true;
        }
    }

    return true;
}

int main()
{
    Node* root = NULL;

    // Create Tree { 8 4 2 -1 -1 -1 6 -1 -1 }  { 8 4 -1 2 -1 -1 6 -1 -1 }
    cout << "Enter data : ";
    root = createTree(root);

    // Is Binary Tree a Heap
    bool heap = isHeap(root);

    if(heap){

        cout << "Binary Tree is a Heap !";
    }
    else{

        cout << "Binary Tree is not a Heap !";
    }

    cout << endl;
    return 0;
}