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

    // Leaf Nodes
    if(data == -1) return NULL;

    root = new Node(data);

    root->left = createTree(root->left);
    root->right = createTree(root->right);

    return root;
}

void printTree(Node* root){

    if(root == NULL) return;

    queue<Node*> q;
    q.push(root);

    while(!q.empty()){

        int lvl = q.size();
        
        while(lvl--){

            Node* front = q.front();
            q.pop();

            cout << front->data << " ";

            if(front->left != NULL){

                q.push(front->left);
            }

            if(front->right != NULL){

                q.push(front->right);
            }
        }

        cout << endl;
    }
}

// Method 1 : Modifying the tree to mirror
// Time Complexity : O(n)  Space Complexity : O(n)
// Node* convertMirror(Node* root){

//     if(root == NULL) return root;

//     // Recursive Call
//     root->left = convertMirror(root->left);
//     root->right = convertMirror(root->right);

//     // Store the child of root node
//     Node* leftChild = root->left;
//     Node* rightChild = root->right;

//     // Reverse them
//     root->left = rightChild;
//     root->right = leftChild;

//     return root;
// }

// Method 2 : Create a New Mirror Tree 
// Time Complexity : O(n)  Space Complexity : O(n)
Node* convertMirror(Node* root){

    if(root == NULL) return NULL;

    // Create New Node
    Node* newTree = new Node(root->data);
    
    // Recursive Call for Left and Right Child
    newTree->left = convertMirror(root->right);
    newTree->right = convertMirror(root->left);

    return newTree;
}

int main()
{
    Node* root = NULL;

    // Creating the tree { 1 2 4 7 -1 -1 -1 5 -1 -1 3 -1 6 -1 -1 }
    cout << "Enter nodes data : ";
    root = createTree(root);

    cout << "Original Tree : " << endl;
    printTree(root);

    root = convertMirror(root);

    cout << "Mirror Tree : " << endl;
    printTree(root);

    cout << endl;
    return 0;
}