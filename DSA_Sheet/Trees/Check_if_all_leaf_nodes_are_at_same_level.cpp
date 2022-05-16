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
// Time Complexity : O(n)  Space Complexity : O(n)
// bool checkHelper(Node* root, int level, int setLevel){

//     // Empty Node
//     if(root == NULL) return true;

//     // Leaf Node
//     if(root->left == NULL && root->right == NULL){

//         if(setLevel == 0){

//             setLevel = level;
//         }
//         else{

//             if(setLevel != level){

//                 return false;
//             }
//         }

//         return true;
//     }

//     bool leftChild = checkHelper(root->left, level + 1, setLevel);
//     bool rightChild = checkHelper(root->right, level + 1, setLevel);

//     return (leftChild && rightChild);
// }

// bool checkSameLevel(Node* root){

//     if(root == NULL) return true;

//     return checkHelper(root, 1, 0);
// }

// Method 2 : Iterative Method
// Time Complexity : O(n)  Space Complexity : O(n)
bool checkSameLevel(Node* root){

    if(root == NULL) return true;

    // For storing nodes
    queue<Node*> q;
    q.push(root);

    int countLeaf = 0;
    int store;

    while(!q.empty()){

        int size = q.size();
        store = size; 

        while(size--){

            Node* front = q.front();
            q.pop();

            // Leaf Node
            if(front->left == NULL && front->right == NULL){

                countLeaf++;
            }

            // Left Child
            if(front->left != NULL){

                q.push(front->left);
            }
        
            // Right Child
            if(front->right != NULL){

                q.push(front->right);
            }
        }

        // If it is last level [Only then check the count]
        if(q.empty() && countLeaf == store){

            return true;
        }
    }

    return false;
}

int main()
{
    Node* root = NULL;

    // Creating the tree { 1 2 4 -1 -1 5 -1 -1 3 -1 6 -1 -1 }
    cout << "Enter nodes data : ";
    root = createTree(root);

    // Check Leaf Nodes for same level
    bool check = checkSameLevel(root);

    if(check){

        cout << "Leaf Nodes are at same level !";
    }
    else{

        cout << "Leaf Nodes are not at same level !";
    }

    cout << endl;
    return 0;
}