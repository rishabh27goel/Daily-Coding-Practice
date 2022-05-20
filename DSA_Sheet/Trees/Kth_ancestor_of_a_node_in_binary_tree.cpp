#include <iostream>
#include <vector>
#include <utility>
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

// Method 1 : Storing the path
// Time Complexity : O(n)   Space Complexity : O(n)
// bool getPathHelper(Node* root, int value, vector<Node*> &path){

//     // Empty Node
//     if(root == NULL) return false;

//     // If we find the value
//     if(root->data == value){

//         path.push_back(root);

//         return true;
//     }

//     path.push_back(root);

//     bool leftChild = getPathHelper(root->left, value, path);
//     bool rightChild = getPathHelper(root->right, value, path);

//     if(leftChild == false && rightChild == false){

//         path.pop_back();
//     }

//     return (leftChild || rightChild);
// }

// Node* kthAncestor(Node* root, int value, int k){

//     if(root == NULL || k == 0) return NULL;

//     // Storing the path
//     vector<Node*> path;

//     bool check = getPathHelper(root, value, path);

//     int index = path.size()-1; 

//     if(index >= 0 && path[index]->data == value){

//         while(k--){

//             index--;

//             if(index < 0) return NULL;
//         }

//         return path[index];
//     }

//     return NULL;
// }


// Method 2 : Single Recursive Call
// Time Complexity : O(n)   Space Complexity : O(n)
pair < Node *, int> helperAncestor(Node* root, int value, int k){

    // Empty Node
    if(root == NULL) 
        return make_pair((Node *) NULL, -1);

    // Leaf Node
    if(root->data == value){

        return make_pair(root, 0);
    }

    pair < Node *, int> leftChild = helperAncestor(root->left, value, k);
    pair < Node *, int> rightChild = helperAncestor(root->right, value, k);

    if(leftChild.first != NULL && rightChild.first == NULL){

        if(leftChild.second < k){

            return make_pair(root, leftChild.second + 1);
        }
        else{

            return leftChild;
        }
        
    }
    else if(leftChild.first == NULL && rightChild.first != NULL){

        if(rightChild.second < k){

            return make_pair(root, rightChild.second + 1);
        }
        else{

            return rightChild;
        }
        
    }

    return make_pair((Node *) NULL, -1);
}

Node* kthAncestor(Node* root, int value, int k){

    if(root == NULL || k == 0) return NULL;

    pair < Node *, int> pr = helperAncestor(root, value, k);

    if(pr.second < k) return NULL;

    return pr.first;
}

int main()
{
    Node* root = NULL;

    // Creating the tree { 1 2 4 7 -1 -1 -1 5 -1 -1 3 -1 6 -1 -1 }
    cout << "Enter nodes data : ";
    root = createTree(root);

    int value;
    cout << "Enter value of node : ";
    cin >> value;

    int k;
    cout << "Enter k : ";
    cin >> k;

    // Kth Ancestor of a node
    Node* ancestor = kthAncestor(root, value, k);

    if(ancestor == NULL){

        cout << "No Ancestor Exist !";
    }
    else{

        cout << "Ancestor is : " << ancestor->data;
    }   

    cout << endl;
    return 0;
}