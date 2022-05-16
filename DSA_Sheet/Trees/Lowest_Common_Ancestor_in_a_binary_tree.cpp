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

Node* createTree(Node* root){

    int data;
    cin >> data;

    if(data == -1) return NULL;

    root = new Node(data);

    root->left = createTree(root->left);
    root->right = createTree(root->right);

    return root;
}

// Method 1 : Storing the paths of n1 & n2 nodes
// Time Complexity : O(n)   Space Complexity : O(n) [Recursive Call] + O(n) [Vector Space]
// bool findPathHelper(Node* root, int num, vector<Node*> &path){

//     if(root == NULL) return false;

//     if(root->data == num){

//         path.push_back(root);
//         return true;
//     }    

//     path.push_back(root);

//     bool leftChild = findPathHelper(root->left, num, path);
//     bool rightChild = findPathHelper(root->right, num, path);

//     // Remove the node from path vector
//     if(leftChild == false && rightChild == false){

//         path.pop_back(); 
//     }

//     return (leftChild || rightChild);
// }

// Node* lca(Node* root, int n1, int n2){

//     if(root == NULL) return NULL;

//     // Get the path of n1 & n2 
//     vector<Node*> n1Path;
//     vector<Node*> n2Path;

//     // Fill the path vector
//     bool n1Bool = findPathHelper(root, n1, n1Path);
//     bool n2Bool = findPathHelper(root, n2, n2Path);

//     int i = 0;

//     while(i < n1Path.size() && i < n2Path.size()){

//         if(n1Path[i]->data != n2Path[i]->data) break;

//         i++;
//     }

//     return n1Path[i-1];
// }

// Method 2 : Sending Child Status [Bottom to Up]
// Time Complexity : O(n)   Space Complexity : O(n)
Node* lca(Node* root, int n1, int n2){

    if(root == NULL) return NULL;

    if(root->data == n1 || root->data == n2){

        return root;
    }

    Node* leftChild = lca(root->left, n1, n2);
    Node* rightChild = lca(root->right, n1, n2);

    if(leftChild != NULL && rightChild != NULL){

        return root;
    }
    else if(leftChild == NULL && rightChild != NULL){

        return rightChild;
    }
    else if(leftChild != NULL && rightChild == NULL){

        return leftChild;
    }
    else{

        return NULL;
    }
}

int main()
{
    Node* root = NULL;

    // Creating the tree { 1 2 4 7 -1 -1 -1 5 -1 -1 3 -1 6 -1 -1 }
    cout << "Enter nodes data : ";
    root = createTree(root);

    int n1;
    cout << "Enter value 1 : ";
    cin >> n1;

    int n2;
    cout << "Entre value 2 : ";
    cin >> n2;

    // Lowest Common Ancestor
    Node* ancestor = lca(root, n1, n2);

    if(ancestor){

        cout << "Ancestor Node is : " << ancestor->data;
    }
    else{

        cout << "No ancestor exits !";
    }

    cout << endl;
    return 0;
}