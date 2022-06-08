#include <iostream>
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

Node* createTree(Node* root, int value){

    if(root == NULL){

        root = new Node(value);
        return root;
    }

    if(root->data > value){

        root->left = createTree(root->left, value);
    }
    else{

        root->right = createTree(root->right, value);
    }

    return root;
}

// Method 1 : Storing path in vectors
// Time Complexity : O(h)  Space Complexity : O(h)
// void getPath(Node* root, int value, vector<Node*> &path){

//     if(root == NULL) return;

//     path.push_back(root);

//     if(root->data == value){

//         return;
//     }
//     else if(root->data > value){

//         getPath(root->left, value, path);
//     }
//     else{

//         getPath(root->right, value, path);
//     }
// }

// Node* lcaOfTwoNodeBST(Node* root, int n1, int n2){

//     if(root == NULL) return root;

//     // Vectors for storing nodes path
//     vector<Node*> n1Path;
//     vector<Node*> n2Path;

//     getPath(root, n1, n1Path);
//     getPath(root, n2, n2Path);

//     // Find the lca index
//     int index = 0;

//     while(index < n1Path.size() && index < n2Path.size()){

//         if(n1Path[index] != n2Path[index])
//             break;

//         index++;
//     }

//     return n1Path[index-1];
// }

// Method 2 : Change root based on nodes data
// Time Complexity : O(h)  Space Complexity : O(h)
Node* lcaOfTwoNodeBST(Node* root, int n1, int n2){

    if(root == NULL) return root;

    // If both nodes are smaller than root
    if(root->data > n1 && root->data > n2){

        return lcaOfTwoNodeBST(root->left, n1, n2);
    }

    // If both nodes are larger than root
    else if(root->data < n1 && root->data < n2){

        return lcaOfTwoNodeBST(root->right, n1, n2);
    }

    return root;
}

int main()
{
    Node* root = NULL;

    // Create BST { 50 30 15 40 75 60 85 80 -1 }
    cout << "Enter nodes data : ";
    int data = 0;

    while(data != -1){

        cin >> data;
        if(data == -1) break;

        root = createTree(root, data);
    }

    int n1;
    cout << "Enter first node : ";
    cin >> n1;

    int n2;
    cout << "Enter second node : ";
    cin >> n2;

    // Find LCA Of Nodes
    Node* lca = lcaOfTwoNodeBST(root, n1, n2);

    cout << "Lowest Common Ancestor : " << lca->data;

    cout << endl;
    return 0;
}